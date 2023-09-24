#include <stdio.h>
#include <math.h>

struct Ponto{
    int x;
    int y;
};

double CalculaDistancia(struct Ponto p1, struct Ponto p2){
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;

    return sqrt(dx * dx + dy * dy);
}

#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} tPonto;

double distPontos(tPonto p1, tPonto p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {
    tPonto pontoP, pontoMaisProximo;
    int n;

    scanf("%lf %lf", &pontoP.x, &pontoP.y);

    scanf("%d", &n);

    double menorDist = -1;

    for (int i = 0; i < n; i++) {
        tPonto pontoAtual;
        scanf("%lf %lf", &pontoAtual.x, &pontoAtual.y);

        double dist = distPontos(pontoP, pontoAtual);

        if (menorDist == -1 || dist < menorDist) {
            menorDist = dist;
            pontoMaisProximo = pontoAtual;
        }
    }

    printf("Ponto mais perto é (%d, %d)\n", (int)pontoMaisProximo.x, (int)pontoMaisProximo.y);

    return 0;
}