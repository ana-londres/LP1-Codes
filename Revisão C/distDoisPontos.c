#include <stdio.h>
#include <math.h>

struct Ponto{
    double x;
    double y;
};

double QuadradoDistancia( struct Ponto p1, struct Ponto p2){
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    
    return dx * dx + dy * dy;
}

int main(){
    struct Ponto ponto1, ponto2;
    
    scanf("%lf %lf", &ponto1.x, &ponto1.y);
    
    scanf("%lf %lf", &ponto2.x, &ponto2.y);
    
    int dist = QuadradoDistancia(ponto1, ponto2);
    
    printf("%d\n", dist);
    
    return 0;
}