#ifndef PESSOA_H
#define PESSOA_H
#include <string>

class Pessoa
{
    public:
        Pessoa();
        
        std::string nome;
        int idade;
        std::string telefone;
};

#endif


Pessoa::Pessoa(){}

#include <iostream>
using namespace std;

int main()
{
    Pessoa pessoa[2];
    
    for(int i = 0; i < 2; i++){
        getline(cin, pessoa[i].nome);
        cin >> pessoa[i].idade;
        cin.ignore();
        getline(cin, pessoa[i].telefone);
        
        cout << pessoa[i].nome << ", " << pessoa[i].idade << ", ";
        cout << pessoa[i].telefone << endl;
    }
    
    return 0;
}