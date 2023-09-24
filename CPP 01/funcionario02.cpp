#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <string>

class Funcionario
{
    private:
        std::string primeiroNome;
        std::string sobrenome;
        float salario;

    public:
        Funcionario();

        Funcionario(std::string primeiroNome, std::string sobrenome, float salario);

        void setNome(std::string primeiroNome);
        std::string getNome();

        void setSobrenome(std::string sobrenome);
        std::string getSobrenome();

        void setSalarioMensal(float salario);
        float getSalarioMensal();

        float getSalarioAnual();
        void aumentaSalario(float percent);

};

#endif

Funcionario::Funcionario()
{}

Funcionario::Funcionario(std::string p, std::string sn, float sl){
    salario = sl;
    primeiroNome = p;
    sobrenome = sn;

    if(salario < 0.0){
        salario = 0.0;
    }
}

void Funcionario::setNome(std::string p){
    primeiroNome = p;
}

std::string Funcionario::getNome(){
    return primeiroNome;
}

void Funcionario::setSobrenome(std::string sn) {
    sobrenome = sn;
}

std::string Funcionario::getSobrenome(){
    return sobrenome;
}

void Funcionario::setSalarioMensal(float sl) {
    salario = sl;
}

float Funcionario::getSalarioMensal(){
    return salario;
}

float Funcionario::getSalarioAnual(){
    return salario * 12;
}

void Funcionario::aumentaSalario(float percent) {
    salario *= (1 + percent);
}

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int qtd;
    string primeiroNome, sobrenome;
    float salario;

    cin >> qtd;

    Funcionario funcionarios[qtd];

    for(int i = 0; i < qtd; i++){
        cin.ignore();
        getline(cin, primeiroNome);
        getline(cin, sobrenome);
        cin >> salario;

        funcionarios[i] = Funcionario(primeiroNome, sobrenome, salario);
    }

    for(int i = 0; i < qtd; i++){
        cout << funcionarios[i].getNome() << " " << funcionarios[i].getSobrenome()
             << " - " << funcionarios[i].getSalarioMensal() << " - " << funcionarios[i].getSalarioAnual() << endl;

        funcionarios[i].aumentaSalario(0.1);

        cout << funcionarios[i].getSalarioAnual() << endl;
    }

    return 0;
}