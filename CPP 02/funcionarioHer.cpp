#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <string>

class Funcionario
{
    public:
        Funcionario();
        int getMatricula();
        void setMatricula(int m);

        std::string getNome();
        void setNome(std::string n);

        int getSalario();
        void setSalario(int s);

    protected:
        int matricula;
        std::string nome;
        float salario;
};

#endif

#ifndef CONSULTOR_H
#define CONSULTOR_H

class Consultor : public Funcionario
{
    public:
        Consultor();
        float getSalario();
        float getSalario(float percentual);
};

#endif


Funcionario::Funcionario()
    : matricula(0), salario(0)
{}

int Funcionario::getMatricula(){
     return matricula;
}

std::string Funcionario::getNome(){
    return nome;
}

int Funcionario::getSalario(){
    return salario;
}

void Funcionario::setMatricula(int m){
    matricula = m;
}

void Funcionario::setNome(std::string n){
    nome = n;
}

void Funcionario::setSalario(int s){
    salario = s;
}


Consultor::Consultor()
{}

float Consultor::getSalario(){
    return salario * 1.1;
}

float Consultor::getSalario(float percentual){
    return salario + (salario * percentual);
}

#include <iostream>
#include <string>

using namespace std;

int main()
{
    Funcionario func;
    Consultor consul;

    int matricula;
    float salario;
    string nome;

    cin >> matricula;
    func.setMatricula(matricula);

    cin.ignore();

    getline(cin, nome);
    func.setNome(nome);

    cin >> salario;
    func.setSalario(salario);

    cin >> matricula;
    consul.setMatricula(matricula);

    cin.ignore();

    getline(cin, nome);
    consul.setNome(nome);

    cin >> salario;
    consul.setSalario(salario);

    cout << func.getMatricula() << " - " << func.getNome() << " - R$ " << func.getSalario() << endl;

    cout << consul.getMatricula() << " - " << consul.getNome() << " - R$ " << consul.getSalario() << endl;

    return 0;
}
