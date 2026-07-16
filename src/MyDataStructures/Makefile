COMPILER = dotnet
TESTS = $(CURDIR)/../../Tests/MyDataStructuresOnCsTests/MyDataStructuresOnCsTests.csproj
PROJECT = $(CURDIR)/MyDataStructuresOnCs.csproj
PUBLISHOUTDIR = $(CURDIR)/publish
PACKAGEOUTDIR = $(CURDIR)/package

.PHONY: build test clean publish pack clean-package clean-publish

ifeq ($(OS),Windows_NT)
  RM = cmd /c if exist "$1" rmdir /s /q "$1"
  FIX_PATH = $(subst /,\,$1)
else
  RM = rm -rf "$1"
  FIX_PATH = $1
endif

build:
	$(COMPILER) build "$(PROJECT)" -c Release
	$(COMPILER) build "$(TESTS)" -c Release

test:
	$(COMPILER) test "$(TESTS)"

clean:
	$(COMPILER) clean "$(PROJECT)"
	$(COMPILER) clean "$(TESTS)"
	$(call RM,$(call FIX_PATH,$(CURDIR)/../../Tests/MyDataStructuresOnCsTests/bin))
	$(call RM,$(call FIX_PATH,$(CURDIR)/../../Tests/MyDataStructuresOnCsTests/obj))
	$(call RM,$(call FIX_PATH,$(CURDIR)/bin))
	$(call RM,$(call FIX_PATH,$(CURDIR)/obj))

clean-package:
	$(call RM,$(call FIX_PATH,$(PACKAGEOUTDIR)))

clean-publish:
	$(call RM,$(call FIX_PATH,$(PUBLISHOUTDIR)))

publish: clean clean-publish
	$(COMPILER) test "$(TESTS)" -c Release
	$(COMPILER) publish "$(PROJECT)" -c Release -r win-x64 -o "$(PUBLISHOUTDIR)/win-x64" --self-contained

pack: clean clean-package
	$(COMPILER) test "$(TESTS)" -c Release
	$(COMPILER) pack "$(PROJECT)" -c Release -o "$(PACKAGEOUTDIR)"