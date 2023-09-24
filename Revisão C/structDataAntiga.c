#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} tData;

int dataAntiga(tData d1, tData d2) {
    if (d1.ano < d2.ano) {
        return 1;
    } else if (d1.ano > d2.ano) {
        return -1;
    } else {
        if (d1.mes < d2.mes) {
            return 1;
        } else if (d1.mes > d2.mes) {
            return -1;
        } else {
            if (d1.dia < d2.dia) {
                return 1;
            } else if (d1.dia > d2.dia) {
                return -1;
            } else {
                return 0;
            }
        }
    }
}

int main() {
    tData pessoa1, pessoa2;

    scanf("%d %d %d", &pessoa1.dia, &pessoa1.mes, &pessoa1.ano);

    scanf("%d %d %d", &pessoa2.dia, &pessoa2.mes, &pessoa2.ano);

    int resultado = dataAntiga(pessoa1, pessoa2);

    if (resultado == 1) {
        printf("Pessoa 1 é mais velha\n");
    } else if (resultado == -1) {
        printf("Pessoa 2 é mais velha\n");
    } else {
        printf("Pessoas são da mesma idade\n");
    }

    return 0;
}