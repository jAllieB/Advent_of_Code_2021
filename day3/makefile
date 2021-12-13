
.PHONY : all
all : binaryDiagnostic1 binaryDiagnostic2

binaryDiagnostic1 : binaryDiagnostic1.o
	gcc -g -o binaryDiagnostic1 binaryDiagnostic1.o 

binaryDiagnostic2 : binaryDiagnostic2.o
	gcc -g -o binaryDiagnostic2 binaryDiagnostic2.o /home/allie/plib/libfdr/libfdr.a

binaryDiagnostic1.o : binaryDiagnostic1.c
	gcc -g -c binaryDiagnostic1.c

binaryDiagnostic2.o : binaryDiagnostic2.c
	gcc -g -I/home/allie/plib/libfdr -c binaryDiagnostic2.c

clean : 
	rm *.o binaryDiagnostic1 binaryDiagnostic2
