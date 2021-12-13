
.PHONY : all
all : giantSquid1 giantSquid2

libs = /home/allie/plib/libfdr/libfdr.a
flags = -I/home/allie/plib/libfdr

giantSquid1 : giantSquid1.o
	gcc -g -o giantSquid1 giantSquid1.o $(libs)

giantSquid2 : giantSquid2.o
	gcc -g -o giantSquid2 giantSquid2.o $(libs)

giantSquid1.o : giantSquid1.c
	gcc -g -c $(flags) giantSquid1.c

giantSquid2.o : giantSquid2.c
	gcc -g -c $(flags) giantSquid2.c

clean : 
	rm *.o giantSquid1 giantSquid2
