#include <iostream>
#include <string>

using namespace std;

typedef struct{
    string descricao;
    float peso;
    char tipo;
}tMovel;

int main(){
    int n;
    int qtd10s = 0, qtdReal = 0, indexMaisPesado = 0, maiorPeso = 0;

    cin >> n;

    tMovel moveis[n];

    for(int i = 0; i < n; i++){
        cin.ignore();
        getline(cin, moveis[i].descricao);
        cin >> moveis[i].peso;
        cin >> moveis[i].tipo;

        if(moveis[i].peso > 10 && moveis[i].tipo == 's'){
            qtd10s++;
        }

        if(moveis[i].peso > maiorPeso){
            maiorPeso = moveis[i].peso;
            indexMaisPesado = i;
        }

        if(moveis[i].descricao.find("Real") == moveis[i].descricao.size() - 4){
            qtdReal++;
        }
    }

    cout << "Tipo 's' acima de 10Kg: " << qtd10s << endl;
    cout << "Termina em  \"Real\": " << qtdReal << endl;
    cout << "Mais pesado: \"" << moveis[indexMaisPesado].descricao << "\"" << endl;

}
