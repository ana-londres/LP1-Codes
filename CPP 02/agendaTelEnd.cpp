#ifndef ENDERECO_H
#define ENDERECO_H
#include <string>

class Endereco
{
    public:
        Endereco();
        Endereco(std::string r, int n, std::string b, std::string c, std::string e, std::string cep);
        std::string toString();

    private:
        std::string rua;
        int numero;
        std::string bairro, cidade, estado, CEP;
};

#endif // ENDERECO_H

using namespace std;

Endereco::Endereco(){}

Endereco::Endereco(string r, int n, string b, string c, string e, string cep)
{
    rua = r;
    numero = n;
    bairro = b;
    cidade = c;
    estado = e;
    CEP = cep;
}

string Endereco::toString(){
    string n = to_string(numero);

    return "\n" + rua + ", " + n + ", " + bairro + ". " + cidade + " - " + estado + ". CEP: " + CEP;
}

#ifndef PESSOA_H
#define PESSOA_H

class Pessoa
{
    public:
        Pessoa();
        Pessoa(std::string n);
        Pessoa(std::string n, Endereco ende, std::string tel);
        std::string getNome();
        Endereco getEndereco();
        std::string getTelefone();
        void setNome(std::string n);
        void setEndereco(Endereco ende);
        void setTelefone(std::string tel);
        std::string toString();

    private:
        std::string nome;
        Endereco endereco;
        std::string telefone;
};

#endif // PESSOA_H

using namespace std;

Pessoa::Pessoa(){}

Pessoa::Pessoa(string n){
    nome = n;
}

Pessoa::Pessoa(string n, Endereco ende, string tel) : Pessoa(n){
    endereco = ende;
    telefone = tel;
}

string Pessoa::getNome(){
    return nome;
}

Endereco Pessoa::getEndereco(){
    return endereco;
}

string Pessoa::getTelefone(){
    return telefone;
}

void Pessoa::setNome(string n){
    nome = n;
}

void Pessoa::setEndereco(Endereco ende){
    endereco = ende;
}

void Pessoa::setTelefone(string tel){
    telefone = tel;
}

string Pessoa::toString(){
    return nome + ", " + telefone + endereco.toString();
}

#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;
    cin.ignore();

    string nome, t, r, b, c, e, cep;
    int num;

    Endereco en;
    Pessoa p;

    for (int i = 0; i < n; i++){
        getline(cin, nome);
        p.setNome(nome);

        getline(cin, t);
        p.setTelefone(t);

        getline(cin, r);

        cin >> num;

        cin.ignore();
        getline(cin, b);

        getline(cin, c);

        getline(cin, e);

        getline(cin, cep);

        en = Endereco(r, num, b, c, e, cep);
        p.setEndereco(en);

        cout << p.toString();
        cout << "\n" << "\n";
    }

    return 0;
}