#ifndef PAGAMENTO_H
#define PAGAMENTO_H
#include <string>

class Pagamento
{
    public:
        Pagamento();
        void setValorPagamento(float v);
        void setNomeFuncionario(std::string n);
        float getValorPagamento();
        std::string getNomeFuncionario();

    private:
        float valorPagamento;
        std::string nomeDoFuncionario;
};

#endif // PAGAMENTO_H

using namespace std;

Pagamento::Pagamento()
{
    valorPagamento = 0;
}

void Pagamento::setValorPagamento(float v){
    valorPagamento = v;
}

void Pagamento::setNomeFuncionario(string n){
    nomeDoFuncionario = n;
}

float Pagamento::getValorPagamento(){
    return valorPagamento;
}

string Pagamento::getNomeFuncionario(){
    return nomeDoFuncionario;
}

#ifndef CONTROLEDEPAGAMENTOS_H
#define CONTROLEDEPAGAMENTOS_H

class ControleDePagamentos
{
    public:
        ControleDePagamentos();
        void setPagamento(Pagamento p, int index);
        Pagamento getPagamento(int pos);
        float calculaTotalDePagamentos();
        int getIndexFuncionario(std::string nomeFuncionario);

    private:
        Pagamento pagamentos[100];
};

#endif // CONTROLEDEPAGAMENTOS_H

using namespace std;

ControleDePagamentos::ControleDePagamentos(){}

void ControleDePagamentos::setPagamento(Pagamento p, int index){
    if (index >= 0 && index < 100){
        pagamentos[index] = p;
    }
}

Pagamento ControleDePagamentos::getPagamento(int pos){
    if (pos >= 0 && pos < 100){
        return pagamentos[pos];
    }
}

float ControleDePagamentos::calculaTotalDePagamentos(){
    float total = 0;
    for (int i = 0; i < 100; i++){
        total += pagamentos[i].getValorPagamento();
    }
    return total;
}

int ControleDePagamentos::getIndexFuncionario(string nomeFuncionario){
    for (int i = 0; i < 100; i++){
        if ((pagamentos[i].getNomeFuncionario()).find(nomeFuncionario) != string::npos){
            return i;
        }
    }
    return -1;
}

#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;

    Pagamento p;
    ControleDePagamentos controle;

    float valor;
    string nome;

    for (int i = 0; i < n; i++){
        cin >> valor;
        p.setValorPagamento(valor);

        cin.ignore();
        getline(cin , nome);
        p.setNomeFuncionario(nome);

        controle.setPagamento(p, i);
    }

    string nomeBusca;
    bool achou = 0;

    cin >> nomeBusca;

    for (int i = 0; i < n; i++){
        if (controle.getIndexFuncionario(nomeBusca) == i){
            cout << controle.getPagamento(i).getNomeFuncionario() << ": R$ "
            << controle.getPagamento(i).getValorPagamento() << endl;
            achou = 1;
        }
    }

    if (!achou)
        cout << nomeBusca << " não encontrado(a).\n";

    cout << "Total: R$ " << controle.calculaTotalDePagamentos() << endl;

    return 0;
}