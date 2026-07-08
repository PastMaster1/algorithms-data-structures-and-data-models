COMPILER = dotnet
TESTS = $(CURDIR)/MinStackTests/MinStackTests.csproj
PROJECT = $(CURDIR)/AlgorithmsOnCs/AlgorithmsOnCs.csproj
PUBLISHOUTDIR = $(CURDIR)/publish
PACKAGEOUTDIR = $(CURDIR)/package

.PHONY: build test clean publish pack

build:
	$(COMPILER) build $(PROJECT) -c Release
	$(COMPILER) build $(TESTS) -c Release

test:
	$(COMPILER) test $(TESTS)

clean:
	$(COMPILER) clean $(PROJECT)
	$(COMPILER) clean $(TESTS)
	-powershell -NoProfile -Command "rm -Recurse -Force '$(CURDIR)/MinStackTests/bin' -EA 0"
	-powershell -NoProfile -Command "rm -Recurse -Force '$(CURDIR)/MinStackTests/obj' -EA 0"
	-powershell -NoProfile -Command "rm -Recurse -Force '$(CURDIR)/AlgorithmsOnCs/bin' -EA 0"
	-powershell -NoProfile -Command "rm -Recurse -Force '$(CURDIR)/AlgorithmsOnCs/obj' -EA 0"

clean-package:
	-powershell -NoProfile -Command "rm -Recurse -Force '$(PACKAGEOUTDIR)' -EA 0"

clean-publish:
	-powershell -NoProfile -Command "rm -Recurse -Force '$(PUBLISHOUTDIR)' -EA 0"

publish: clean clean-publish test
	$(COMPILER) publish $(PROJECT) -c Release -r win-x64 -o $(PUBLISHOUTDIR)/win-x64 --self-contained

pack: clean clean-package test
	$(COMPILER) pack -c Release -o $(PACKAGEOUTDIR)