CPPCOMPILER = g++
CPPFLAGS = -std=c++17 -Wall -Werror -Wextra -Wpedantic

ifeq ($(OS), Windows_NT)
  FIX_PATH = $(subst /,\,$1)
  EXT_DYNAMICLIB = .dll
  RMFILE = cmd /c if exist "$1" del /f /q "$1"
  RMDIR = cmd /c if exist "$1" rmdir /s /q "$1"
  EXT_TARGET = .exe
  MKDIR = cmd /c if not exist "$1" mkdir "$1"
  COPY_LIBRARY = cmd /c copy /Y "$(subst /,\,$(SOURCELIB_DIR)$(LIB)$(EXT_DYNAMICLIB))" "."
else
  FIX_PATH = $1
  EXT_DYNAMICLIB = .so
  RMFILE = rm -f "$1"
  RMDIR = rm -r -f "$1"
  EXT_TARGET =
  MKDIR = mkdir -p "$1"
  COPY_LIBRARY = cp "$(SOURCELIB_DIR)$(LIB)$(EXT_DYNAMICLIB)" "$(LIB)$(EXT_DYNAMICLIB)"
endif

TARGET = app$(EXT_TARGET)
SOURCE_CODE_DIR = $(CURDIR)/src/
DATAMODELS_SRC_DIR = $(SOURCE_CODE_DIR)DataModels/
SOURCE_CODE =  $(wildcard $(SOURCE_CODE_DIR)*.cpp) $(wildcard $(DATAMODELS_SRC_DIR)*.cpp)
OBJECTIVE_CODE_DIR = $(CURDIR)/obj
OBJECTIVE_CODE = $(patsubst %.cpp,$(OBJECTIVE_CODE_DIR)/%.o,$(notdir $(SOURCE_CODE)))
DEMO_HPPDIR = $(CURDIR)/include/DataModels
HPPDIR = $(CURDIR)/../../DataModels/Cpp/include
SOURCELIB_DIR = $(CURDIR)/../../DataModels/Cpp/
LIB = libDataStructures
LIB_NAME = DataStructures

all: $(TARGET)

vpath %.cpp $(SOURCE_CODE_DIR):$(DATAMODELS_SRC_DIR)

$(OBJECTIVE_CODE_DIR):
	$(call MKDIR,$(call FIX_PATH,$(OBJECTIVE_CODE_DIR)))

$(OBJECTIVE_CODE_DIR)/%.o: %.cpp | $(OBJECTIVE_CODE_DIR)
	$(CPPCOMPILER) $(CPPFLAGS) -c $< -o $@ -I"./include" -I"$(HPPDIR)" -I"$(DEMO_HPPDIR)"

$(TARGET): $(LIB)$(EXT_DYNAMICLIB) $(OBJECTIVE_CODE)
	$(CPPCOMPILER) $(CPPFLAGS) $(OBJECTIVE_CODE) -o $(TARGET) -I$(HPPDIR) -I$(DEMO_HPPDIR) -L$(CURDIR) -l$(LIB_NAME)

$(LIB)$(EXT_DYNAMICLIB):
	$(MAKE) -C $(SOURCELIB_DIR) $(LIB)$(EXT_DYNAMICLIB)
	$(COPY_LIBRARY)

clean:
	$(call RMFILE,$(TARGET))
	$(call RMFILE,$(LIB)$(EXT_DYNAMICLIB))
	$(call RMDIR,$(call FIX_PATH,$(OBJECTIVE_CODE_DIR)))

rebuild: clean
	$(MAKE) -C $(SOURCELIB_DIR) clean
	$(MAKE)

.PHONY: all clean rebuild