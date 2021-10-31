all: main.o auxiliares.o carregajogo.o getinput.o iniciajogo.o inicio.o mainmenu.o mapa.o gameover.o
	windres icon.rc -O coff -o icon.o
	gcc -Wall -g main.o auxiliares.o carregajogo.o getinput.o iniciajogo.o inicio.o mainmenu.o icon.o mapa.o gameover.o -o JAM-Rogue.exe

main.o: main.c
	gcc -Wall -g -c main.c

auxiliares.o: auxiliares.c
	gcc -Wall -g -c auxiliares.c

carregajogo.o: carregajogo.c
	gcc -Wall -g -c carregajogo.c

getinput.o: getinput.c
	gcc -Wall -g -c getinput.c

iniciajogo.o: iniciajogo.c
	gcc -Wall -g -c iniciajogo.c

inicio.o: inicio.c
	gcc -Wall -g -c inicio.c

mainmenu.o: mainmenu.c
	gcc -Wall -g -c mainmenu.c

mapa.o: mapa.c
	gcc -Wall -g -c mapa.c

gameover.o: gameover.c
	gcc -Wall -g -c gameover.c

clear:
	rm -f PC-Rogue.exe main.o auxiliares.o carregajogo.o getinput.o iniciajogo.o inicio.o mainmenu.o