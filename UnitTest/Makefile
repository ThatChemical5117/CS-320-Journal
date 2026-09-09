# ==== Project Makefile Configuration ====
# Console Application Version

# from external file
ifeq ($(config),optimize)
	CXXFLAGS += -O3
else ifeq ($(config),dist)
	CXXFLAGS += -O3
	CXXFLAGS += -s
else
	config=debug
	CXXFLAGS += -g
	CXXFLAGS += -DDEBUG
endif
# Directory used to install Application
INSTALLDIR =/usr/local/bin

# Desired Name of the final Executable
APPNAME = unit-tests

# Source and Destination Directory for all files
BINDIR = ../bin/$(config)
BIN = $(BINDIR)/$(APPNAME)
OBJDIR = .obj
DEPDIR = .dep
SRCDIR = src
#
# Finds the locations for Sources, Object, and dependency files
SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
DEP = $(OBJ:$(OBJDIR)/%.o=$(DEPDIR)/%.d)

# Compiler and Compiler options
CXX = g++
CXXFLAGS += -Wall -I./include  -I../Appointment-contact-book/include
LDFLAGS = -lgtest -lgtest_main -lpthread
# Hook into project binary files
LDFLAGS += $(filter-out ../Appointment-contact-book/.obj/main.o, $(wildcard ../Appointment-contact-book/.obj/*.o))

# pre-compiled headers options

# ALL rule
all: $(BIN)

#==== Utility Functions ===="
# Clean command, clears all executables and object files
clean:
	rm -f $(OBJ) $(DEP) $(BIN)

# Uninstall Step, remove if not needed
uninstall:
	@echo "==== Uninstalling ($(APPNAME))"
	rm -f $(INSTALLDIR)/$(APPNAME)

# install step, remove if not needed
install: all
	@echo "==== Installing ($(APPNAME)) ($(config))"
	cp -f $(BIN) $(INSTALLDIR)/$(APPNAME)
	chmod 755 $(INSTALLDIR)/$(APPNAME)

#==== Compilation Steps ===="

# FINAL Compilation step, produces final binary
$(BIN): $(OBJ)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Generates Dependency Files
$(DEPDIR)/%.d: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	@$(CPP) $(CXXFLAGS) $< -MM -MT $(@:$(DEPDIR)/%.d=$(OBJDIR)/%.o) >$@

# Tell make to use dependency file
-include $(DEP)

# Compiles all translation units, does each one individually
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ -c $<
