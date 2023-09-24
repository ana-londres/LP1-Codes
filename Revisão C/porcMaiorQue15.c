#include <stdio.h>

int main(){
    int n, imp = 0, cont = 0;
    float valor = 0;

    while(scanf("%d", &n) && n != 0){
        if(n > 15 && n % 2 == 1){
            imp++;
        }
        cont++;
    }

    valor = ((1.0 * imp) / cont) * 100;

    printf("%d%%\n", (int) valor);

    return 0;
}