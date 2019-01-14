#Makefile at top of application tree
TOP = ../../../extensions/master
include $(TOP)/configure/CONFIG

include $(TOP)/configure/RULES_TOP

install:
	build.bat

clean:
	unbuild.bat

uninstall:
	$(RMDIR) $(TOP)/bin/$(EPICS_HOST_ARCH)
	$(RMDIR) $(TOP)/lib/$(EPICS_HOST_ARCH)
