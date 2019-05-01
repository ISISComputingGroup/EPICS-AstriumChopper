#Makefile at top of application tree
TOP = ../../../extensions/master
include $(TOP)/configure/CONFIG

include $(TOP)/configure/RULES_TOP

ifeq ($(findstring 10.0,$(VCVERSION)),)
SOLUTION = AstriumChopperVS2017.sln
else
SOLUTION = AstriumChopper.sln
endif

install:
	build.bat $(SOLUTION)

clean:
	unbuild.bat $(SOLUTION)

uninstall:
	$(RMDIR) $(TOP)/bin/$(EPICS_HOST_ARCH)
	$(RMDIR) $(TOP)/lib/$(EPICS_HOST_ARCH)
