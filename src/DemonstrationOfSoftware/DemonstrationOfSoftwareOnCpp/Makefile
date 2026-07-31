CPPCOMPILER = g++
CPPFLAGS = -std=c++17 -Wall -Werror -Wextra -Wpedantic

ifeq ($(OS), Windows_NT)
  EXT_DYNAMICLIB = .dll
  RMFILE = cmd /c if exist "$1" del /f /q "$1"
  EXT_TARGET = .exe
  COPY_LIBRARY = cmd /c copy /Y "$(subst /,\,$(SOURCELIB_DIR)$(LIB)$(EXT_DYNAMICLIB))" "."
else
  EXT_DYNAMICLIB = .so
  RMFILE = rm -f "$1"
  EXT_TARGET =
  COPY_LIBRARY = cp "$(SOURCELIB_DIR)$(LIB)$(EXT_DYNAMICLIB)" "$(LIB)$(EXT_DYNAMICLIB)"
endif

TARGET = app$(EXT_TARGET)
SOURCE_CODE = $(CURDIR)/src/DemonstrationOfDataStructures.cpp $(CURDIR)/src/DemonstrationOfDataStructureTV.cpp $(CURDIR)/src/DemonstrationOfDataStructureLaptop.cpp
DEMO_HPPDIR = $(CURDIR)/include
HPPDIR = $(CURDIR)/../../MyDataStructures/MyDataStructuresOnCpp/include
SOURCELIB_DIR = $(CURDIR)/../../MyDataStructures/MyDataStructuresOnCpp/
LIB = libDataStructures

all: $(TARGET)

$(TARGET): $(LIB)$(EXT_DYNAMICLIB) $(SOURCE_CODE)
	$(CPPCOMPILER) $(CPPFLAGS) $(SOURCE_CODE) -o $(TARGET) -I$(HPPDIR) -I$(DEMO_HPPDIR) -L$(CURDIR) -l$(LIB)

$(LIB)$(EXT_DYNAMICLIB):
	$(MAKE) -C $(SOURCELIB_DIR) $(LIB)$(EXT_DYNAMICLIB)
	$(COPY_LIBRARY)

clean:
	$(call RMFILE,$(TARGET))
	$(call RMFILE,$(LIB)$(EXT_DYNAMICLIB))

rebuild: clean
	$(MAKE) -C $(SOURCELIB_DIR) clean
	$(MAKE)

.PHONY: all clean rebuild