CXX=g++
CXXFLAGS = -std=c++14
ROOT_DIR := $(shell git rev-parse --show-toplevel)
-include $(ROOT_DIR)/config/settings
-include $(DEP_DIR)/env

SOURCES = $(wildcard *.cc)
OBJFILES = $(notdir $(SOURCES:.cc=.o))

all: entity_app

# Applicaiton Targets:
%_app: $(OBJFILES)
	$(CXX) $(CXXFLAGS) $(OBJFILES) -o $@

# Object File Targets:
%.o:  %.cc %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o *_app *.exe

