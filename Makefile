

INTERACTIVE_PROGS = cityDistance

NONINTERACTIVE_PROGS =  

PROGS = $(INTERACTIVE_PROGS) $(NONINTERACTIVE_PROGS)


CXX      = g++
CXXFLAGS = -Wall -g -std=c++11

INTERACTIVE_OUTPUT   = $(INTERACTIVE_PROGS:=.out)
NONINTERACIVE_OUTPUT = $(NONINTERACTIVE_PROGS:=.out)

%.out : %
	./$< > $@

.PHONY : all clean interactive


all : $(PROGS) $(NONINTERACTIVE_OUTPUT)

interactive : $(INTERACTIVE_OUTPUT)

clean : 
	@rm -fv $(PROGS)
	@rm -fv $(OUTPUT)
