agprj:acg.o gfile.o
	@echo generating agprj
	gcc -o agprj acg.c gfile.c
	@echo agprj done
acg.o:acg.c main.h gfile.h
	@echo generating acg.o
	gcc -c acg.c
	@echo acg.o done
gfile.o:gfile.c main.h gfile.h
	@echo generating gfile.o
	gcc -c gfile.c
	@echo gfile.o done
