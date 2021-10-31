#include "auxiliares.h"
#include "inicio.h"

void inicio(void) {
    system("cls");

    // imprime a barra superior
    printf("%c", 201);
    for (int i = 0; i < (SCREENHEIGHT); i++){
        printf("%c", 205);
    }
    printf("%c\n", 187);
    
    // imprime as barras laterais
    for(int i = 0; i<(SCREENWIDTHS); i++){
        printf("%c",186);
        printf("Ajuste a janela ate arrumar o contorno da tela");
        for (int j = 46; j < (SCREENHEIGHT); j++){
            printf("%c", WHITESPACE);
        }
        printf("%c\n",186);
    }

    // imprime a barra inferior
    printf("%c", 200);
    for (int i = 0; i < (SCREENHEIGHT); i++){
        printf("%c", 205);
    }
    printf("%c", 188);

    hidecursor();
}

void intro(void){
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
    
    gotoxy(2,2);
    printf("Jogo desenvolvido para a JAM do Fabrica");
    hidecursor();
    getch();
    gotoxy(10,4);
    printf("Tema 'Preservar'!");
    hidecursor();
    getch();
    gotoxy(2,6);
    printf("Aqui o 'Preservar' tem o sentido de guardar a historia do gameDev.");
    hidecursor();
    getch();
    gotoxy(2,8);
    printf("Por isso nao foi usado Engines de jogos!");
    hidecursor();
    getch();
    gotoxy(2,10);
    printf("Jogo baseado no classico Rogue");
    hidecursor();
    getch();
    gotoxy(2,12);
    printf("Codigo fonte disponivel em https://github.com/DenTod-games-e-jogos/JAM-Rogue");
    gotoxy(2,14);
    printf("Livre para todos preservarem a memoria!");
    hidecursor();
    getch();

}