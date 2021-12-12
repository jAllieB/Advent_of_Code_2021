
.PHONY : all
all : dive1 dive2 

libs = /home/allie/plib/libfdr/libfdr.a
flags = -I/home/allie/plib/libfdr

dive1 : dive1.o
	gcc -g -o dive1 dive1.o $(libs) 

dive2 : dive2.o
	gcc -g -o dive2 dive2.o $(libs)

dive1.o : dive1.c
	gcc -g $(flags) -c dive1.c

dive2.o : dive2.c
	gcc -g $(flags) -c dive2.c

.PHONY : clean
clean : 
	-rm dive1 dive2 *.o
