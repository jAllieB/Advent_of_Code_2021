
.PHONY : all
all : sonarSweepPart1 sonarSweepPart2

sonarSweepPart1 : sonarSweepPart1.o
	cc -o sonarSweepPart1 sonarSweepPart1.o

sonarSweepPart1.o : sonarSweepPart1.c
	cc -c sonarSweepPart1.c


sonarSweepPart2 : sonarSweepPart2.o
	cc -o sonarSweepPart2 sonarSweepPart2.o

sonarSweepPart2.o : sonarSweepPart2.c
	cc -c sonarSweepPart2.c


clean : 
	rm sonarSweepPart1 sonarSweepPart2 sonarSweepPart1.o sonarSweepPart2.o
