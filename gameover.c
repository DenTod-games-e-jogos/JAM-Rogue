#include "auxiliares.h"
#include "getinput.h"
#include "gameover.h"
#include "mapa.h"
#include "heroi.h"
#include "varGlobal.h"

void gameOver(void) {
    
    system("cls");

    // imprime a barra superior
    printf("%c", 201);
    for (int i = 0; i < (SCREENHEIGHT-1); i++){
        printf("%c", 205);
    }
    printf("%c\n", 187);
    
    // imprime as barras laterais
    for(int i = 0; i<(SCREENWIDTHS-1); i++){
        printf("%c",186);
        for (int j = 0; j < (SCREENHEIGHT-1); j++){
            printf("%c", WHITESPACE);
        }
        printf("%c\n",186);
    }

    // imprime a barra inferior
    printf("%c", 200);
    for (int i = 0; i < (SCREENHEIGHT-1); i++){
        printf("%c", 205);
    }
    printf("%c", 188);

    gotoxy(2,6);
    printf("A sua jornada chegou ao fim!!");
    gotoxy(2,8);
    printf("Grande heroi, voce chegou ate o andar %d dessa torre.", gameHero.level);
    gotoxy(2,10);
    printf("Talvez um proximo heroi possa ir mais longe.");
    hidecursor();


    getch();
}

