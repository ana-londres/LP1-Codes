#ifndef DESPESA_H
#define DESPESA_H

#include <string>

class Despesa {
    private:
        std::string nome;
        float valor;
        std::string tipoDeGasto;

    public:
        Despesa(std::string nome = "", float valor = 0.0,  std::string tipoDeGasto = "");

        void setNome(std::string nome);
        std::string getNome();

        void setValor(float valor);
        float getValor();

        void setTipoDeGasto( std::string tipo);
        std::string getTipoDeGasto();
};

#endif

#ifndef GASTO_H
#define GASTO_H

class Gasto {
    private:
        Despesa despesas[100];

    public:
        Gasto();

        void setDespesa(Despesa d, int pos);
        Despesa getDespesa(int pos);
        float calculaTotalDeDespesas();
        float calculaTotalDeDespesas(std::string tipo);
        bool existeDespesaDoTipo(std::string tipo);
};

#endif

Gasto::Gasto() {
    for (int i = 0; i < 100; i++) {
        despesas[i] = Despesa("", 0.0, "");
    }
}

void Gasto::setDespesa(Despesa d, int pos) {
    despesas[pos] = d;
}

Despesa Gasto::getDespesa(int pos) {
    return despesas[pos];
}

float Gasto::calculaTotalDeDespesas() {
    float total = 0.0;
    for (int i = 0; i < 100; i++) {
        total += despesas[i].getValor();
    }
    return total;
}

float Gasto::calculaTotalDeDespesas(std::string tipo) {
    float total = 0.0;
    for (int i = 0; i < 100; i++) {
        if (despesas[i].getTipoDeGasto() == tipo) {
            total += despesas[i].getValor();
        }
    }
    return total;
}

bool Gasto::existeDespesaDoTipo(std::string tipo) {
    for (int i = 0; i < 100; i++) {
        if (despesas[i].getTipoDeGasto() == tipo) {
            return true;
        }
    }
    return false;
}

Despesa::Despesa( std::string nome, float valor,  std::string tipoDeGasto)
    : nome(nome), valor(valor), tipoDeGasto(tipoDeGasto) {
}

void Despesa::setNome(std::string nome) {
    this->nome = nome;
}

std::string Despesa::getNome() {
    return nome;
}

void Despesa::setValor(float valor) {
    this->valor = valor;
}

float Despesa::getValor() {
    return valor;
}

void Despesa::setTipoDeGasto(std::string tipo) {
    tipoDeGasto = tipo;
}

std::string Despesa::getTipoDeGasto() {
    return tipoDeGasto;
}

#include <iostream>

using namespace std;

int main() {
    Gasto controle;

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string nome, tipo;
        float valor;

        getline(cin, nome);
        cin >> valor;
        cin.ignore();
        getline(cin, tipo);
        Despesa d(nome, valor, tipo);
        controle.setDespesa(d, i);
    }

    string tipoExibir;
    cin >> tipoExibir;


    bool encontrouDespesa = false;
    for (int i = 0; i < n; i++) {
        if (controle.getDespesa(i).getTipoDeGasto() == tipoExibir) {
            cout << controle.getDespesa(i).getNome() << ", R$ " << controle.getDespesa(i).getValor() << endl;
            encontrouDespesa = true;
        }
    }

    if (!encontrouDespesa) {
        cout << "Nenhuma despesa do tipo especificado" << endl;
    }

    float totalDespesasTipo = controle.calculaTotalDeDespesas(tipoExibir);
    float totalDespesas = controle.calculaTotalDeDespesas();

    cout << "Total: " << totalDespesasTipo << "/" << totalDespesas << endl;

    return 0;
}