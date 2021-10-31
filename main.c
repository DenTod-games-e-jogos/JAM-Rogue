#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "inicio.h"
#include "mainmenu.h"
#include "auxiliares.h"
#include "iniciajogo.h"
#include "carregajogo.h"
#include "mapa.h"
#include "heroi.h"
#include "gameover.h"

struct salas matrizMapa [10][10];
struct salas salaAtual;
struct Heroi gameHero;
struct Slime inimigos [10];

int main (void)
{

   hidecursor();
   inicio();
   getch();
   intro();
   int menuOption = 4;
   do {
      menuOption = menuDisplay();
      switch (menuOption)
      {
         case 0: //para cima
            iniciaJogo();
            if (gameHero.vivo == 0){
               gameOver();
            }
            break;
         case 1: //para baixo
            carregaJogo();
            break;
      }
   } while (menuOption != 3);
   return 0;
}