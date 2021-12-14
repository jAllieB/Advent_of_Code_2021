
libs = /home/allie/plib/libfdr/libfdr.a
flags = -I/home/allie/plib/libfdr

lanternfish : lanternfish.o
	gcc -g -o lanternfish lanternfish.o $(libs)

lanternfish.o : lanternfish.c
	gcc -g $(flags) -c lanternfish.c

clean : 
	rm *.o lanternfish
