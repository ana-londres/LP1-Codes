#include <stdio.h>

int main(){
    
    int maior = -1000, num;
    
    for(int i = 0; i < 3; i++){
        scanf("%d", &num);
        
        if(num > maior){
            maior = num;
        }
    }
    
    printf("%d", maior);
    
    return 0;
}