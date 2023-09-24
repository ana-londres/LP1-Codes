#include <stdio.h>

int main(){
    int num[10], soma = 0;
    float media = 0;

    for(int i = 0; i < 10; i++){
        scanf("%d", &num[i]);

        soma += num[i];
    }

    media = (float) soma / 10;

    printf("Media: %.1f\n", media);

   for(int i = 0; i < 10; i++){
        if(i == 0){
            printf("Maiores que a media: ");
        }
        if(num[i] > media){
            printf("%d ", num[i]);
        }

    }

    return 0;
}