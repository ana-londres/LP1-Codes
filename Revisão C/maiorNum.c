#include <stdio.h>

int main(){
    int q, num, maior = -1000;

    scanf("%d", &q);

    for(int i = 0; i < q; i++){
        scanf("%d", &num);

        if(num > maior){
            maior = num;
        }
    }

    printf("%d\n", maior);

    return 0;
}