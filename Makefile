

INTERACTIVE_PROGS = HeightConvert

NONINTERACTIVE_PROGS = meanCalc 

PROGS = $(INTERACTIVE_PROGS) $(NONINTERACTIVE_PROGS)


CXX      = g++
CXXFLAGS = -Wall -g

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
