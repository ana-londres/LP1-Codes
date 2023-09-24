#ifndef DATA_H
#define DATA_H
#include <string>

class Data
{
    private:
        int dia;
        int mes;
        int ano;

    public:
        Data();
        Data(int d, int m, int a);

        void setDia(int d);
        int getDia() const;
        void setMes(int m);
        int getMes() const;
        void setAno(int a);
        int getAno() const;
        void printData() const;
};

#endif

#include <iostream>
#include <string>
using namespace std;

Data::Data() : dia(1), mes(1), ano(1){}

Data::Data(int d, int m, int a) : dia(d), mes(m), ano(a) {}

void Data::setDia(int d){
    dia = d;
}

int Data::getDia() const{
    return dia;
}

void Data::setMes(int m) {
    mes = m;
}

int Data::getMes() const {
    return mes;
}

void Data::setAno(int a) {
    ano = a;
}

int Data::getAno() const {
    return ano;
}

void Data::printData() const{
    std::string nomeMes = "Indefinido";

    if(mes >= 1 && mes <= 12){
        static const string meses[] = {
                "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
                "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
        };
        nomeMes = meses[mes - 1];
    }

    cout << dia << " de " << nomeMes << " de " << ano << endl;
}

#include <iostream>
#include <string>
using namespace std;

int main() {
    int dia, mes, ano;

    cin >> dia;

    cin >> mes;

    cin >> ano;

    Data data(dia, mes, ano);

    data.printData();

    return 0;
}