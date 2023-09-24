#ifndef TRABALHADOR_H
#define TRABALHADOR_H
#include <string>

class Trabalhador
{
    public:
        Trabalhador();
        Trabalhador(std::string n, float s);

        void setNome(std::string n);
        void setSalario(float s);
        std::string getNome();
        float getSalario();

    protected:
        std::string nome;
        float salario;
};

#endif // TRABALHADOR_H

using namespace std;

Trabalhador::Trabalhador()
{
    salario = 0;
}

Trabalhador::Trabalhador(string n, float s)
{
    setNome(n);
    setSalario(s);
}

void Trabalhador::setNome(string n){
    nome = n;
}

void Trabalhador::setSalario(float s){
    salario = s;
}

std::string Trabalhador::getNome(){
    return nome;
}

float Trabalhador::getSalario(){
    return salario;
}

#ifndef TRABALHADORASSALARIADO_H
#define TRABALHADORASSALARIADO_H

class TrabalhadorAssalariado : public Trabalhador
{
    public:
        TrabalhadorAssalariado();
        TrabalhadorAssalariado(std::string n, float s);

        float calcularPagamentoSemanal();
};

#endif // TRABALHADORASSALARIADO_H

using namespace std;

TrabalhadorAssalariado::TrabalhadorAssalariado(){}


TrabalhadorAssalariado::TrabalhadorAssalariado(string n, float s) : Trabalhador(n, s){

}

float TrabalhadorAssalariado::calcularPagamentoSemanal()
{
    return salario/4;
}

#ifndef TRABALHADORPORHORA_H
#define TRABALHADORPORHORA_H

class TrabalhadorPorHora : public Trabalhador
{
    public:
        TrabalhadorPorHora();
        TrabalhadorPorHora(std::string n, float s, float v);

        float calcularPagamentoSemanal(int horasSemanais);

    private:
        float valorDaHora;
};

#endif // TRABALHADORPORHORA_H

using namespace std;

TrabalhadorPorHora::TrabalhadorPorHora(){}

TrabalhadorPorHora::TrabalhadorPorHora(string n, float s, float v) : Trabalhador(n, s)
{
    valorDaHora = v;
}

float TrabalhadorPorHora::calcularPagamentoSemanal(int horasSemanais){
    float total = 0;

    if (horasSemanais > 40){
        total += valorDaHora*40;

        total += (1.5 * valorDaHora) * (horasSemanais - 40);
    }else {
        total += valorDaHora*horasSemanais;
    }

    setSalario(total*4);

    return total;
}

#include <iostream>

using namespace std;

int main(){
    int n;

    cin >> n;

    int tipo, qHoras;
    string nome;
    float salario, valorDaHora;

    Trabalhador *trab[n];

    for (int i = 0; i < n; i++){
        cin >> tipo;
        cin.ignore();

        getline(cin, nome);

        if (tipo == 1){
            cin >> salario;
            cin.ignore();

            trab[i] = new TrabalhadorAssalariado(nome, salario);

        }else if (tipo == 2){
            cin >> valorDaHora;
            cin >> qHoras;

            trab[i] = new TrabalhadorPorHora(nome, 0, valorDaHora);
        }

        cout << trab[i]->getNome() << " - Semanal: R$ ";

        if (tipo == 1){
            cout << ((TrabalhadorAssalariado*)trab[i])->calcularPagamentoSemanal();

        }else if (tipo == 2){
            cout << ((TrabalhadorPorHora*)trab[i])->calcularPagamentoSemanal(qHoras);
        }

        cout << " - Mensal: R$ " << trab[i]->getSalario() << endl;
    }

    return 0;
}