# ==== Workspace Global Make file ====
# Put this make file in the root directory of your project

# configuration default
ifndef config
	config = debug
endif

#Add All project names, Project name should be the same as the Directory it is in
# keep adding additional project names after 
PROJECTS := Appointment-contact-book 
.PHONY: all clean $(PROJECTS) uninstall install UnitTest

all: $(PROJECTS)


Appointment-contact-book: 
	@echo "==== Building ($@) ($(config)) ===="
	@$(MAKE) --no-print-directory -C $@ -f Makefile config=$(config)

UnitTest: Appointment-contact-book
	@echo "==== Building ($@) ($(config)) ===="
	@$(MAKE) --no-print-directory -C $@ -f Makefile config=$(config)
	@./bin/$(config)/unit-tests

#add Extra rules with the same format, Use name of directory that project is in 

install: all
	@$(MAKE) --no-print-directory -C Appointment-contact-book -f Makefile install config=$(config)

uninstall:
	@$(MAKE) --no-print-directory -C Appointment-contact-book -f Makefile uninstall 

# add a line for each project, use Directory name
clean:
	@${MAKE} --no-print-directory -C Appointment-contact-book -f Makefile clean

clean-test:
	@${MAKE} --no-print-directory -C UnitTest -f Makefile clean
