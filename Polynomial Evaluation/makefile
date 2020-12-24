polyapp: polyapp.o utils.o poly.o
	gcc -o polyapp polyapp.o utils.o poly.o
polyapp.o: polyapp.c utils.h poly.h
	gcc -c polyapp.c
utils.o: utils.c
	gcc -c utils.c
poly.o: poly.c utils.h
	gcc -c poly.c
