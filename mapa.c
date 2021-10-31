#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "auxiliares.h"
#include "getinput.h"
#include "mapa.h"
#include "heroi.h"
#include "varGlobal.h"

struct salas criaSala(char desenho[10][10]){
    struct salas desenhoSala;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            desenhoSala.tiles[i][j] = desenho[i][j];
    return desenhoSala;
}

void criaMapa(void)
{
    int i,j;
    struct salas matrizSala;
    int saidaX;
    int saidaY;
//    int tecla;
    
    srand(time(NULL));
    // Define em qual sala está a saída
    saidaX = rand() % 10;
    saidaY = rand() % 10;
    if (saidaX > 9){
        saidaX = 9;
    }
    if (saidaY > 9){
        saidaY = 9;
    }
    
    {// Cria a sala na coordenada (0,0)
    /////////////////////0  1  2  3  4  5  6  7  8  9
    char sala[10][10]= {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},///0
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///1
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///2
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///3
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 2},///4
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 2},///5
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///6
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///7
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///8
                        {0, 0, 0, 0, 2, 2, 0, 0, 0, 0}};//9)
    matrizSala = criaSala(sala);
    matrizMapa[0][0] = matrizSala;}
    {// Cria a sala na coordenada (0,9)
    /////////////////////0  1  2  3  4  5  6  7  8  9
    char sala[10][10]= {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},///0
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///1
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///2
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///3
                        {2, 1, 1, 1, 1, 1, 1, 1, 1, 0},///4
                        {2, 1, 1, 1, 1, 1, 1, 1, 1, 0},///5
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///6
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///7
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///8
                        {0, 0, 0, 0, 2, 2, 0, 0, 0, 0}};//9)
    matrizSala = criaSala(sala);
    matrizMapa[0][9] = matrizSala;}
    {// Cria a sala na coordenada (9,9)
    /////////////////////0  1  2  3  4  5  6  7  8  9
    char sala[10][10]= {{0, 0, 0, 0, 2, 2, 0, 0, 0, 0},///0
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///1
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///2
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///3
                        {2, 1, 1, 1, 1, 1, 1, 1, 1, 0},///4
                        {2, 1, 1, 1, 1, 1, 1, 1, 1, 0},///5
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///6
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///7
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///8
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};//9)
    matrizSala = criaSala(sala);
    matrizMapa[9][9] = matrizSala;}
    {// Cria a sala na coordenada (9,0)
    /////////////////////0  1  2  3  4  5  6  7  8  9
    char sala[10][10]= {{0, 0, 0, 0, 2, 2, 0, 0, 0, 0},///0
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///1
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///2
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///3
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 2},///4
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 2},///5
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///6
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///7
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///8
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};//9)
    matrizSala = criaSala(sala);
    matrizMapa[9][0] = matrizSala;}
    {// Cria as salas na latereal esquerda
    /////////////////////0  1  2  3  4  5  6  7  8  9
    char sala[10][10]= {{0, 0, 0, 0, 2, 2, 0, 0, 0, 0},///0
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///1
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///2
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///3
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 2},///4
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 2},///5
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///6
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///7
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///8
                        {0, 0, 0, 0, 2, 2, 0, 0, 0, 0}};//9)
    matrizSala = criaSala(sala);
    for (i = 1; i < 9; i++)
        matrizMapa[i][0] = matrizSala;}
    {// Cria as salas na latereal direita
    /////////////////////0  1  2  3  4  5  6  7  8  9
    char sala[10][10] ={{0, 0, 0, 0, 2, 2, 0, 0, 0, 0},///0
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///1
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///2
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///3
                        {2, 1, 1, 1, 1, 1, 1, 1, 1, 0},///4
                        {2, 1, 1, 1, 1, 1, 1, 1, 1, 0},///5
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///6
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///7
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///8
                        {0, 0, 0, 0, 2, 2, 0, 0, 0, 0}};//9)
    matrizSala = criaSala(sala);
    for (i = 1; i < 9; i++)
        matrizMapa[i][9] = matrizSala;}
    {// Cria as salas no lado superior
    /////////////////////0  1  2  3  4  5  6  7  8  9
    char sala[10][10]= {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},///0
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///1
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///2
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///3
                        {2, 1, 1, 1, 1, 1, 1, 1, 1, 2},///4
                        {2, 1, 1, 1, 1, 1, 1, 1, 1, 2},///5
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///6
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///7
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///8
                        {0, 0, 0, 0, 2, 2, 0, 0, 0, 0}};//9)
    matrizSala = criaSala(sala);
    for (i = 1; i < 9; i++)
        matrizMapa[0][i] = matrizSala;}
    {// Cria as salas no lado inferior
    /////////////////////0  1  2  3  4  5  6  7  8  9
    char sala[10][10]= {{0, 0, 0, 0, 2, 2, 0, 0, 0, 0},///0
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///1
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///2
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///3
                        {2, 1, 1, 1, 1, 1, 1, 1, 1, 2},///4
                        {2, 1, 1, 1, 1, 1, 1, 1, 1, 2},///5
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///6
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///7
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///8
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};//9)
    matrizSala = criaSala(sala);
    for (i = 1; i < 9; i++)
        matrizMapa[9][i] = matrizSala;}
    {// Cria as salas no meio do mapa
    /////////////////////0  1  2  3  4  5  6  7  8  9
    char sala[10][10]= {{0, 0, 0, 0, 2, 2, 0, 0, 0, 0},///0
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///1
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///2
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///3
                        {2, 1, 1, 1, 1, 1, 1, 1, 1, 2},///4
                        {2, 1, 1, 1, 1, 1, 1, 1, 1, 2},///5
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///6
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///7
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///8
                        {0, 0, 0, 0, 2, 2, 0, 0, 0, 0}};//9)
    matrizSala = criaSala(sala);
    for (i = 1; i < 9; i++)
        for (j = 1; j < 9; j++)
           matrizMapa[i][j] = matrizSala;}
    
    // Coloca a saida no mapa
    matrizMapa[saidaY][saidaX].tiles[4][5] = 3;
    // Coloca o heroi em algum lugar do mapa
    gameHero.mapa.x = rand() % 10;
    if (gameHero.mapa.x > 9){
        gameHero.mapa.x = 9;
    }
    gameHero.mapa.y = rand() % 10;
    if (gameHero.mapa.y > 9){
        gameHero.mapa.y = 9;
    }
    gameHero.sala.x = rand() % 10;
    if (gameHero.sala.x < 1){
        gameHero.sala.x = 1;
    }
    if (gameHero.sala.x > 8){
        gameHero.sala.x = 8;
    }
    gameHero.sala.y = rand() % 10;
    if (gameHero.sala.y < 1){
        gameHero.sala.y = 1;
    }
    if (gameHero.sala.y > 8){
        gameHero.sala.y = 8;
    }
    gameHero.atual.x = gameHero.sala.x;
    gameHero.atual.y = gameHero.sala.y;
    salaAtual = matrizMapa[gameHero.mapa.y][gameHero.mapa.x];
    salaAtual.tiles[gameHero.sala.y][gameHero.sala.x] = 4;
    for (i = 0; i<10; i++){
        posicionaInimigo(i);
    }
    //matrizMapa[gameHero.mapa.y][gameHero.mapa.x].tiles[gameHero.sala.y][gameHero.sala.x] = 4;
// para depuração e visualização de todas as salas
//    for (i = 0; i<10; i++){
//        for (j = 0; j<10; j++){
//            desenhaMapa(matrizMapa[i][j]);
//            tecla=getInput();
//        }
//    }

}

void desenhaMapa(struct salas local)
{
    system("cls");
    gotoxy(0,0);

    for (int ii = 0; ii < 10; ii++){
        for (int jj = 0; jj < 10; jj++){
            //printf("%d",local.tiles[ii][jj]);
            switch (local.tiles[ii][jj]){
                case 0: //parede
                    printf("%c",219);
                break;
                case 1: //chão
                    printf(".");
                break;
                case 2: //porta
                    printf("%c",176);
                break;
                case 3: //escada
                    printf("%%");
                break;
                case 4: //heroi
                    printf("%c",2);
                break;
                default:
                    printf("%c",local.tiles[ii][jj]);
                break;
            }
        }
        printf("\n");
    }
}

void posicionaInimigo(int ini){
    int mapaX;
    int mapaY;
    int salaX;
    int salaY;
    char ok = 0;
    do
    {   
        mapaX = rand() % 10;
        if (mapaX > 9){
            mapaX = 9;
        }
        
        mapaY = rand() % 10;
        if (mapaY > 9){
            mapaY = 9;
        }
        
        salaX = rand() % 10;
        if (salaX < 1){
            salaX = 1;
        }
        
        if (salaX > 8){
            salaX = 8;
        }
        
        salaY = rand() % 10;
        if (salaY < 1){
            salaY = 1;
        }
        
        if (salaY > 8){
            salaY = 8;
        }
        ok = ocupado(mapaX,mapaY,salaX,salaY, ini);
    } while (ok !=0);
    inimigos[ini].mapa.x = mapaX;
    inimigos[ini].mapa.y = mapaY;
    inimigos[ini].sala.x = salaX;
    inimigos[ini].sala.y = salaY;
    inimigos[ini].atual.x = inimigos[ini].sala.x;
    inimigos[ini].atual.y = inimigos[ini].sala.y;
    inimigos[ini].dano = 2;
    inimigos[ini].HP = 10;
    inimigos[ini].display = 's';
    inimigos[ini].vivo = 1;
    if ((inimigos[ini].mapa.x == gameHero.mapa.x) &&
        (inimigos[ini].mapa.y == gameHero.mapa.y)){
            salaAtual.tiles[inimigos[ini].sala.y][inimigos[ini].sala.x] = inimigos[ini].display;
        }
}

int ocupado(int mx, int my, int sx, int sy, int inimigo){

    if ((mx == gameHero.mapa.x) &&
        (my == gameHero.mapa.y) &&
        (sx == gameHero.sala.x) &&
        (sy == gameHero.sala.y)){
        return 1;
    }
    for (int i = 0; i < inimigo; i ++){
        if ((mx == inimigos[i].mapa.x) &&
        (my == inimigos[i].mapa.y) &&
        (sx == inimigos[i].sala.x) &&
        (sy == inimigos[i].sala.y)){
        return 1;
        }
    }
    return 0;
}