#ifndef PESSOA2_H
#define PESSOA2_H
#include <string>

class Pessoa2
{
    public:
        Pessoa2();
        Pessoa2(std::string nome);
        Pessoa2(std::string nome, int idade, std::string telefone);

        void setNome(std::string nome);
        std::string getNome();

        void setIdade(int idade);
        int getIdade();

        void setTelefone(std::string telefone);
        std::string getTelefone();

    private:
        std::string nome;
        int idade;
        std::string telefone;
};

#endif

Pessoa2::Pessoa2(){
    idade = 0;
}

Pessoa2::Pessoa2(std::string nome){
    this->nome = nome;
}

Pessoa2::Pessoa2(std::string nome, int idade, std::string telefone){
    this->nome = nome;
    this->idade = idade;
    this->telefone = telefone;
}

void Pessoa2::setNome(std::string nome){
    this->nome = nome;
}

std::string Pessoa2::getNome(){
    return nome;
}

void Pessoa2::setIdade(int idade){
    this->idade = idade;
}

int Pessoa2::getIdade(){
    return idade;
}

void Pessoa2::setTelefone(std::string telefone){
    this->telefone = telefone;
}

std::string Pessoa2::getTelefone(){
    return telefone;
}

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string nome, telefone, busca;
    int idade;
    bool achou = 0;

    cin >> n;
    cin.ignore();

    Pessoa2 pess[n];

    for(int i = 0; i < n; i++){
        getline(cin, nome);
        cin >> idade;
        cin.ignore();
        getline(cin, telefone);

        pess[i] = Pessoa2(nome, idade, telefone);
    }

    cin >> busca;

    for(int i = 0; i < n; i++){
        if((pess[i].getNome()).find(busca) != string::npos){
            cout << pess[i].getNome() << ", " << pess[i].getIdade() << ", " << pess[i].getTelefone() << endl;
            achou = 1;
        }
    }

    if(!achou){
        cout << "Pessoa não encontrada" << endl;
    }


    return 0;
}
