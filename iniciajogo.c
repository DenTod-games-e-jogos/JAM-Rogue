#include "auxiliares.h"
#include "iniciajogo.h"
#include "getinput.h"
#include "mapa.h"
#include "heroi.h"
#include "varGlobal.h"

void iniciaJogo(void)
{
    gameHero.level = 0;
    gameHero.dano = 10;
    gameHero.HP = 100;
    gameHero.vivo = 1;
    criaMapa();
    char input = 0;
    do
    {
        // Desenha o mapa onde o heroi está
        desenhaMapa(salaAtual);
        desenhaUI();
        // Lê entrada do teclado
        input = getInput();
        switch (input)
        {
            case UP: //para cima
                gameHero.sala.y--;
                break;
            case DONW: //para baixo
                gameHero.sala.y++;
                break;
            case RIGHT: //para direita
                gameHero.sala.x++;
                break;
            case LEFT: //para esquerda
                gameHero.sala.x--;
                break;
            default :
                break;
        }
        acaoHeroi();
        for(int i = 0; i < 10; i++){
            acaoInimigo(i);
            if (inimigos[i].HP < 1) {
                inimigos[i].vivo = 0;
            }
        }
        if (gameHero.HP < 1) {
            gameHero.vivo = 0;
            input = 0;
        }
    } while (input!=0);
}
void acaoHeroi(void)
{
    char opcaoAcao = salaAtual.tiles[gameHero.sala.y][gameHero.sala.x];
    switch (opcaoAcao)
    {
        case PAREDE: //Heroi bateu na parede não pode mover
            parede();
            break;
        case CHAO: //Heroi pode mover
            moveHeroi();
            break;
        case PORTA: //Heroi encontrou uma porta
            //moveHeroi();
            entraPorta();
            break;
        case ESCADA: //Heroi encontrou a escada
            moveHeroi();
            sobeEscada();
            break;
        default :
            heroiAtaca();
            break;
    }
}
void parede(void){
    gameHero.sala.x = gameHero.atual.x;
    gameHero.sala.y = gameHero.atual.y;
    salaAtual = matrizMapa[gameHero.mapa.y][gameHero.mapa.x];
    salaAtual.tiles[gameHero.sala.y][gameHero.sala.x] = 4;
}
void moveHeroi(void){
    gameHero.atual.x = gameHero.sala.x;
    gameHero.atual.y = gameHero.sala.y;
    salaAtual = matrizMapa[gameHero.mapa.y][gameHero.mapa.x];
    salaAtual.tiles[gameHero.sala.y][gameHero.sala.x] = 4;
}

void heroiAtaca(void){
    for (int i = 0; i < 10; i++){
        // verifica se o inimigo está na mesma sala que o heroi
        if ((inimigos[i].mapa.x == gameHero.mapa.x) &&
            (inimigos[i].mapa.y == gameHero.mapa.y)) {
                // verifica se o inimog está na mesma posição do heroi
                if ((inimigos[i].sala.x == gameHero.sala.x) &&
                    (inimigos[i].sala.y == gameHero.sala.y)) {
                        inimigos[i].HP -= gameHero.dano;
                }
        }
    }
    gameHero.sala.x = gameHero.atual.x;
    gameHero.sala.y = gameHero.atual.y;
    salaAtual = matrizMapa[gameHero.mapa.y][gameHero.mapa.x];
    salaAtual.tiles[gameHero.sala.y][gameHero.sala.x] = 4;    
}
void entraPorta(void){
    if (gameHero.atual.x == 1){
        gameHero.atual.x = 8;
        gameHero.sala.x = gameHero.atual.x;
        gameHero.mapa.x--;
        salaAtual = matrizMapa[gameHero.mapa.y][gameHero.mapa.x];
        salaAtual.tiles[gameHero.sala.y][gameHero.sala.x] = 4;
        return;
    }
    if (gameHero.atual.x == 8){
        gameHero.atual.x = 1;
        gameHero.sala.x = gameHero.atual.x;
        gameHero.mapa.x++;
        salaAtual = matrizMapa[gameHero.mapa.y][gameHero.mapa.x];
        salaAtual.tiles[gameHero.sala.y][gameHero.sala.x] = 4;
        return;
    }
    if (gameHero.atual.y == 1){
        gameHero.atual.y = 8;
        gameHero.sala.y = gameHero.atual.y;
        gameHero.mapa.y--;
        salaAtual = matrizMapa[gameHero.mapa.y][gameHero.mapa.x];
        salaAtual.tiles[gameHero.sala.y][gameHero.sala.x] = 4;
        return;
    }
    if (gameHero.atual.y == 8){
        gameHero.atual.y = 1;
        gameHero.sala.y = gameHero.atual.y;
        gameHero.mapa.y++;
        salaAtual = matrizMapa[gameHero.mapa.y][gameHero.mapa.x];
        salaAtual.tiles[gameHero.sala.y][gameHero.sala.x] = 4;
        return;
    }
}

void sobeEscada(void){
    gameHero.level++;
    criaMapa();    
}

void desenhaUI(void){
    gotoxy(11,0);
    printf("Sala atual (%d,%d)", gameHero.mapa.x,gameHero.mapa.y);
    gotoxy(11,1);
    printf("Voce esta no andar %d", gameHero.level);
    gotoxy(11,2);
    printf("Pontos de vida %d", gameHero.HP);
    gotoxy(1,11);
    printf("Objetivo: Encontrar a escada %%");
    gotoxy(1,12);
    printf("Cuidado com os inimigos: s");
    gotoxy(1,13);
    printf("Use %c %c %c %c para mover",17,30,31,16);
    gotoxy(1,14);
    printf("Use A W S D para mover");
}

// O que o inimigo faz se esta em sala diferente
void acaoInimigo(int ini)
{
    if (inimigos[ini].vivo == 0)
        return;
    int heroX = gameHero.mapa.x;
    int inmigoX = inimigos[ini].mapa.x;
    int heroY = gameHero.mapa.y;
    int inimigoY = inimigos[ini].mapa.y;
    int difMapaX = heroX - inmigoX;
    int difMapaY = heroY - inimigoY;

    // Move os inimigos em direção à sala que está o heroi
    if ((difMapaX > 0) && (difMapaY < 0))//Heroi na (1,1) inimigo na (0,2)
    {
        inimigos[ini].sala.x += INIMIGOMOV;
        inimigos[ini].sala.y -= INIMIGOMOV;
    }
    if ((difMapaX > 0) && (difMapaY == 0))//Heroi na (1,1) inimigo na (0,1)
    {
        inimigos[ini].sala.x += INIMIGOMOV;
    }
    if ((difMapaX > 0) && (difMapaY > 0))//Heroi na (1,1) inimigo na (0,0)
    {
        inimigos[ini].sala.x += INIMIGOMOV;
        inimigos[ini].sala.y += INIMIGOMOV;
    }
    if ((difMapaX == 0) && (difMapaY > 0))//Heroi a (1,1) inimigo na (1,0)
    {
        inimigos[ini].sala.y += INIMIGOMOV;
    }
    if ((difMapaX < 0) && (difMapaY > 0))//Heroi na (1,1) inimigo na (2,0)
    {
        inimigos[ini].sala.x -= INIMIGOMOV;
        inimigos[ini].sala.y += INIMIGOMOV;
    }
    if ((difMapaX < 0) && (difMapaY == 0))//Heroi na (1,1) inimigo na (2,1)
    {
        inimigos[ini].sala.x -= INIMIGOMOV;
    }
    if ((difMapaX < 0) && (difMapaY < 0))//Heroi na (1,1) inimigo an (2,2)
    {
        inimigos[ini].sala.x -= INIMIGOMOV;
        inimigos[ini].sala.y -= INIMIGOMOV;
    }
    if ((difMapaX == 0) && (difMapaY < 0))//Heroi na (1,1) inimigo na (1,2)
    {
        inimigos[ini].sala.y -= INIMIGOMOV;
    }

    inimigos[ini].atual.x = inimigos[ini].sala.x;
    inimigos[ini].atual.y = inimigos[ini].sala.y;

    if ((difMapaX == 0) && (difMapaY == 0))//Heroi na mesma sala (0,0)
    {
        acaoInimigo2(ini);
    }

    // Muda o inimigo de sala
    if (inimigos[ini].sala.x > 9){
        inimigos[ini].sala.x = 0;
        inimigos[ini].atual.x = inimigos[ini].sala.x;
        inimigos[ini].mapa.x++;
    }
    if (inimigos[ini].sala.x < 0){
        inimigos[ini].sala.x = 9;
        inimigos[ini].atual.x = inimigos[ini].sala.x;
        inimigos[ini].mapa.x--;
    }
    if (inimigos[ini].sala.y > 9){
        inimigos[ini].sala.y = 0;
        inimigos[ini].atual.y = inimigos[ini].sala.y;
        inimigos[ini].mapa.y++;
    }
    if (inimigos[ini].sala.y < 0){
        inimigos[ini].sala.y = 9;
        inimigos[ini].atual.y = inimigos[ini].sala.y;
        inimigos[ini].mapa.y--;
    }
}

// O que o inimigo faz se esta na mesma sala
void acaoInimigo2(int ini)
{
    int difSalaX = gameHero.sala.x - inimigos[ini].sala.x;
    int difSalaY = gameHero.sala.y - inimigos[ini].sala.y;
    if ((difSalaX > 0) && (difSalaY < 0))//Heroi na (1,1) inimigo na (0,2)
    {
        if (difSalaX > difSalaY) {
            inimigos[ini].sala.x += INIMIGOMOV;
        } else {
            inimigos[ini].sala.y -= INIMIGOMOV;
        }
    }
    if ((difSalaX > 0) && (difSalaY == 0))//Heroi na (1,1) inimigo na (0,1)
    {
        inimigos[ini].sala.x += INIMIGOMOV;
    }
    if ((difSalaX > 0) && (difSalaY > 0))//Heroi na (1,1) inimigo na (0,0)
    {
        if (difSalaX > difSalaY*-1) {
            inimigos[ini].sala.x += INIMIGOMOV;
        } else {
            inimigos[ini].sala.y += INIMIGOMOV;
        }
    }
    if ((difSalaX == 0) && (difSalaY > 0))//Heroi a (1,1) inimigo na (1,0)
    {
        inimigos[ini].sala.y += INIMIGOMOV;
    }
    if ((difSalaX < 0) && (difSalaY > 0))//Heroi na (1,1) inimigo na (2,0)
    {
        if (difSalaX*-1 > difSalaY*-1) {
            inimigos[ini].sala.x -= INIMIGOMOV;
        } else {
            inimigos[ini].sala.y += INIMIGOMOV;
        }
    }
    if ((difSalaX < 0) && (difSalaY == 0))//Heroi na (1,1) inimigo na (2,1)
    {
        inimigos[ini].sala.x -= INIMIGOMOV;
    }
    if ((difSalaX < 0) && (difSalaY < 0))//Heroi na (1,1) inimigo an (2,2)
    {
        if (difSalaX*-1 > difSalaY) {
            inimigos[ini].sala.x -= INIMIGOMOV;
        } else {
            inimigos[ini].sala.y -= INIMIGOMOV;
        }
    }
    if ((difSalaX == 0) && (difSalaY < 0))//Heroi na (1,1) inimigo na (1,2)
    {
        inimigos[ini].sala.y -= INIMIGOMOV;
    }
    
    // Se o inimigo chegar na posição do heroi ataca ele, se não atualiza a posição
    if ((inimigos[ini].sala.x == gameHero.sala.x) &&
        (inimigos[ini].sala.y == gameHero.sala.y)) {
            gameHero.HP -= inimigos[ini].dano;
            inimigos[ini].sala.x = inimigos[ini].atual.x;
            inimigos[ini].sala.y = inimigos[ini].atual.y;

    } else {
        inimigos[ini].atual.x = inimigos[ini].sala.x;
        inimigos[ini].atual.y = inimigos[ini].sala.y;
    }
    salaAtual.tiles[inimigos[ini].sala.y][inimigos[ini].sala.x] = inimigos[ini].display;

}