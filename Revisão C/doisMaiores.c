#include <stdio.h>

int main(){
    int n,  pMaior = -100000000, sMaior = -100000000;

    while(scanf("%d", &n) && n != 0){
        if(n > pMaior){
            sMaior = pMaior;
            pMaior = n;
        } else if(n > sMaior || pMaior == sMaior){
            sMaior = n;
        }
    }

    printf("Maior: %d\n", pMaior);
    printf("Segundo maior: %d\n", sMaior);

    return 0;
}