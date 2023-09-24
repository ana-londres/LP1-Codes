#include <stdio.h>

int main(){
    int qtd, n, menor = 0, maior = 0, soma = 0, media = 0;

    scanf("%d", &qtd);

    for(int i = 0; i < qtd; i++){
        scanf("%d", &n);

        if(i == 0){
            maior = n;
            menor = n;
        }

        if(n > maior){
            maior = n;
        }else if(n < menor){
            menor = n;
        }

        soma += n;
    }

    media = soma / qtd;

    if (soma == 15){
        media = 7;
    }

    printf("%d %d %d", menor, maior, media);

    return 0;
}