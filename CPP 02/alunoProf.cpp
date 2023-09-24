#ifndef PESSOA_H
#define PESSOA_H
#include <string>

class Pessoa
{
    public:
        void exibir();
        Pessoa(std::string n, std::string t, std::string c);

    protected:
        std::string nome;
        std::string telefone;
        std::string cpf;
};

#endif

#ifndef ALUNO_H
#define ALUNO_H

class Aluno : public Pessoa
{
    public:
        Aluno(std::string n, std::string t, std::string c, float cr, int s);
        void exibir();

    private:
        float cra;
        int semestre;
};

#endif

#ifndef PROFESSOR_H
#define PROFESSOR_H

class Professor : public Pessoa
{
    public:
        Professor(std::string n, std::string t, std::string c, int q, std::string d);
        void exibir();

    private:
        int qtdDisciplinas;
        std::string departamento;
};

#endif

#include <iostream>

Pessoa::Pessoa(std::string n, std::string t, std::string c)
{
    nome = n;
    telefone = t;
    cpf = c;
}

void Pessoa::exibir(){
    std::cout << nome << " - " << telefone << " - CPF: " << cpf << std::endl;
}


Aluno::Aluno(std::string n, std::string t, std::string c, float cr, int s)
    : Pessoa(n, t, c){
    cra = cr;
    semestre = s;
}

void Aluno::exibir(){
    Pessoa::exibir();
    std::cout << "CRA: " << cra << " - Semestre: " << semestre << std::endl;
}


Professor::Professor(std::string n, std::string t, std::string c, int q, std::string d)
    : Pessoa(n, t, c){
    qtdDisciplinas = q;
    departamento = d;
}

void Professor::exibir(){
    Pessoa::exibir();
    std::cout << "Qtd: " << qtdDisciplinas << " - " << departamento << std::endl;
}

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string nome, telefone, cpf, departamento;
    float cra;
    int semestre, qtd;

    getline(cin, nome);
    getline(cin, telefone);
    getline(cin, cpf);

    Pessoa p1 = Pessoa(nome, telefone, cpf);
    p1.exibir();

    getline(cin, nome);
    getline(cin, telefone);
    getline(cin, cpf);
    cin >> cra;
    cin >> semestre;
    cin.ignore();

    Aluno a1 = Aluno(nome, telefone, cpf, cra, semestre);
    a1.exibir();

    getline(cin, nome);
    getline(cin, telefone);
    getline(cin, cpf);
    cin >> qtd;
    cin.ignore();
    getline(cin, departamento);

    Professor prof1 = Professor(nome, telefone, cpf, qtd, departamento);
    prof1.exibir();

    return 0;
}