#include <iostream>
using namespace std;

int main(){
    int salario = 0, emprestimo = 0, prest = 0;
    float valor;

    cin >> salario;

    while(salario == 0 || salario < 0){
        cin >> salario;
    }
    while(emprestimo == 0 || emprestimo < 0){
        cin >> emprestimo;
    }
    while(prest == 0 || prest < 0){
        cin >> prest;
    }
    
    valor = emprestimo / prest;
    salario = (float)salario * 0.3;

    if(valor > salario){
        cout << "Emprestimo nao pode ser concedido" << endl;
    }else{
        cout << "Emprestimo pode ser concedido" << endl;
    }

    return 0;
}