#include <conio.h>
#include "getinput.h"

char getInput(void)
{
    char keyPressed; 
    keyPressed = _getch();
    //printf("%d\n",keyPressed);
    switch (keyPressed)
    {
        case 'w': //usando AWSD para movimentar
        case 'W':
            return 'w';
        case 'a': //usando AWSD para movimentar
        case 'A':
            return 'a';
        case 's': //usando AWSD para movimentar
        case 'S':
            return 's';
        case 'd': //usando AWSD para movimentar
        case 'D':
            return 'd';
        //case '\033': //input de seta
        case -32: //input de seta
            //keyPressed = _getch();
            keyPressed = _getch();
            switch (keyPressed)
            {
                case 'A': //seta para cima
                case 72: //seta para cima
                    return 'w';
                case 'B': //seta para baixo
                case 80: //seta para baixo
                    return 's';
                case 'C': //seta para esquerda
                case 75: //seta para esquerda
                    return 'a';
                case 'D': //seta para direita
                case 77: //seta para direita
                    return 'd';
            }
        default :
            return keyPressed;
    }  
}