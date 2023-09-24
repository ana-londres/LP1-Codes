#include <stdio.h>

typedef struct {
    char modelo[50];
    char marca[50];
    int anoFabricacao;
    float preco;
} tVeiculo;

int main() {

    tVeiculo veiculos[2];

    scanf("%s", veiculos[0].modelo);
    scanf("%s", veiculos[0].marca);
    scanf("%d", &veiculos[0].anoFabricacao);
    scanf("%f", &veiculos[0].preco);

    scanf("%s", veiculos[1].modelo);
    scanf("%s", veiculos[1].marca);
    scanf("%d", &veiculos[1].anoFabricacao);
    scanf("%f", &veiculos[1].preco);

    if (veiculos[0].anoFabricacao < veiculos[1].anoFabricacao) {
        printf("%s %s\n", veiculos[0].marca, veiculos[0].modelo);
    } else if (veiculos[0].anoFabricacao > veiculos[1].anoFabricacao) {
        printf("%s %s\n", veiculos[1].marca, veiculos[1].modelo);
    } else { 
        if (veiculos[0].preco < veiculos[1].preco) {
            printf("%s %s\n", veiculos[0].marca, veiculos[0].modelo);
        } else {
            printf("%s %s\n", veiculos[1].marca, veiculos[1].modelo);
        }
    }

    return 0;
}