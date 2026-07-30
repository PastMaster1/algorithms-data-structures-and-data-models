CPPCOMPILER = g++

ifeq ($(OS), Windows_NT)
  CPPFLAGS = -std=c++17 -Wall -Werror -Wextra -Wpedantic
  RMDIR = cmd /c if exist "$1" rmdir /s /q "$1"
  RMFILE = cmd /c if exist "$1" del /f /q "$1"
  FIX_PATH = $(subst /,\,$1)
  EXT_DYNAMICLIB = .dll
  MKDIR = cmd /c if not exist "$1" mkdir "$1"
  EXT_TESTS = .exe
else
  CPPFLAGS = -std=c++17 -Wall -Werror -Wextra -Wpedantic -fPIC
  RMDIR = rm -r -f "$1"
  RMFILE = rm -f "$1"
  FIX_PATH = $1
  EXT_DYNAMICLIB = .so
  MKDIR = mkdir -p "$1"
  EXT_TESTS =
endif

TARGET_STATICLIB = $(CURDIR)/DataStructures.a
TARGET_DYNAMICLIB = DataStructures$(EXT_DYNAMICLIB)
SOURCE_CODE_DIR = $(CURDIR)/source_code/
OBJECTIVE_CODE_DIR = $(CURDIR)/objective_code
SOURCE_CODE =  $(wildcard $(SOURCE_CODE_DIR)*.cpp)
OBJECTIVE_CODE = $(patsubst $(SOURCE_CODE_DIR)%.cpp,$(OBJECTIVE_CODE_DIR)/%.o,$(SOURCE_CODE))
TESTS_DIR = $(CURDIR)/../../../tests/MyDataStructuresOnCppTests
TESTS_SOURCE_CODE = $(TESTS_DIR)/src/MyDataStructuresOnCppTests.cpp $(TESTS_DIR)/src/DataStructureLaptopOptionsTests.cpp $(TESTS_DIR)/src/DataStructureLaptopTests.cpp $(TESTS_DIR)/src/DataStructureOptionsForTV_Tests.cpp $(TESTS_DIR)/src/DataStructureTV_Tests.cpp $(TESTS_DIR)/src/UtilityFunctions.cpp
TESTS = run_tests$(EXT_TESTS)

all: $(TARGET_STATICLIB) $(TARGET_DYNAMICLIB)

$(TARGET_STATICLIB): $(OBJECTIVE_CODE)
	ar -rcs $(TARGET_STATICLIB) $(OBJECTIVE_CODE)

$(TARGET_DYNAMICLIB): $(OBJECTIVE_CODE)
	$(CPPCOMPILER) -shared -o $(TARGET_DYNAMICLIB) $(OBJECTIVE_CODE)

$(OBJECTIVE_CODE_DIR)/%.o: $(SOURCE_CODE_DIR)%.cpp | $(OBJECTIVE_CODE_DIR)
	$(CPPCOMPILER) $(CPPFLAGS) -c $< -o $@ -I"./include"

$(OBJECTIVE_CODE_DIR):
	$(call MKDIR,$(call FIX_PATH,$(OBJECTIVE_CODE_DIR)))

test: $(TARGET_DYNAMICLIB)
	$(CPPCOMPILER) $(TESTS_SOURCE_CODE) -I"$(TESTS_DIR)/include" -I"./include" -L"$(TESTS_DIR)" -L"." -lgtest -lDataStructures -o $(TESTS)

clean-obj:
	$(call RMDIR,$(call FIX_PATH,$(OBJECTIVE_CODE_DIR)))

clean-staticlib:
	$(call RMFILE,$(call FIX_PATH,$(TARGET_STATICLIB)))

clean-dynamiclib:
	$(call RMFILE,$(TARGET_DYNAMICLIB))
	$(call RMFILE,$(TESTS))

clean: clean-staticlib clean-dynamiclib clean-obj

.PHONY: all test clean-obj clean-staticlib clean-dynamiclib clean