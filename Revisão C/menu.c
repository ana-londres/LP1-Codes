#include <stdio.h>

void Menu(){
    printf("1 - Item 1\n"
           "2 - Item 2\n"
           "3 - Item 3\n"
           "4 - Sair\n");
}

int main(){
    int op;

    Menu();

    while(scanf("%d", &op)){


        if(op == 4){
            printf("Sair");
            break;
        }else if(op > 4){
            printf("Opcao %d Invalida\n", op);
        }else{
            printf("Item %d\n", op);
        }

        Menu();
    }


    return 0;
}
