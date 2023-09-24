#include <stdio.h>

typedef struct {
    char nomeCompleto[80];
    int idade;
    int chutesAGol;
    int gols;
} tJogador;

int main() {
    tJogador j1, j2;

    scanf(" %[^\n]", j1.nomeCompleto);
    scanf("%d", &j1.idade);
    scanf("%d", &j1.chutesAGol);
    scanf("%d", &j1.gols);

    scanf(" %[^\n]", j2.nomeCompleto);
    scanf("%d", &j2.idade);
    scanf("%d", &j2.chutesAGol);
    scanf("%d", &j2.gols);

    float pontariaJ1 = (float)j1.gols / j1.chutesAGol;
    float pontariaJ2 = (float)j2.gols / j2.chutesAGol;

    if (pontariaJ1 > pontariaJ2) {
        printf("%s (%d)\n", j1.nomeCompleto, j1.idade);
    } else{
        printf("%s (%d)\n", j2.nomeCompleto, j2.idade);
    }

    return 0;
}