struct salas{
    char tiles [10][10];
};

void criaMapa();
void desenhaMapa(struct salas local);
void posicionaInimigo(int ini);
int ocupado(int mx, int my, int sx, int sy, int inimigo);