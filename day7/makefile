
.PHONY : all
all : theTreacheryOfWhales1 theTreacheryOfWhales2

theTreacheryOfWhales1 : theTreacheryOfWhales1.o
	gcc -g -o theTreacheryOfWhales1 theTreacheryOfWhales1.o -lm

theTreacheryOfWhales1.o : theTreacheryOfWhales1.c
	gcc -g -c theTreacheryOfWhales1.c  

theTreacheryOfWhales2 : theTreacheryOfWhales2.o
	gcc -g -o theTreacheryOfWhales2 theTreacheryOfWhales2.o -lm

theTreacheryOfWhales2.o : theTreacheryOfWhales2.c
	gcc -g -c theTreacheryOfWhales2.c  


clean :
	rm *.o theTreacheryOfWhales1 theTreacheryOfWhales2
