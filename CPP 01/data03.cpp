#ifndef DATA_H
#define DATA_H
#include <string>

class Data
{
    private:
        int dia;
        int mes;
        int ano;

        int getDaysMonth(int mes);

    public:
        Data();
        Data(int d, int m, int a);

        void setDia(int d);
        int getDia();
        void setMes(int m);
        int getMes();
        void setAno(int a);
        int getAno();
        void avancarDia();

        std::string formataNum(int n);
        std::string getDataFormatada();
};

#endif

#include <iostream>
#include <string>
using namespace std;

Data::Data(int d, int m, int a){
    dia = d;
    mes = m;
    ano = a;

    if(mes < 1 || mes > 12){
        cout << "Atributo mês Inválido" << endl;
        mes = 1;
    }

    if(dia < 1 || dia > getDaysMonth(mes)){
        cout << "Atributo dia Inválido" << endl;
        dia = 1;
    }
}

int Data::getDaysMonth(int m){
    switch(mes){
        case 2:
            return 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

void Data::setDia(int d){
    dia = d;
}

int Data::getDia(){
    return dia;
}

void Data::setMes(int m) {
    mes = m;
}

int Data::getMes(){
    return mes;
}

void Data::setAno(int a) {
    ano = a;
}

int Data::getAno(){
    return ano;
}

void Data::avancarDia(){
    dia++;

    if(dia > getDaysMonth(mes)){
        dia = 1;
        mes++;
        if(mes > 12){
            mes = 1;
            ano ++;
        }
    }
}

string Data::formataNum(int n){
    if(n < 10){
        return "0" + to_string(n);
    }

    return to_string(n);
}

string Data::getDataFormatada(){
    return formataNum(dia) + "/" + formataNum(mes) + "/" + to_string(ano);
}

#include <iostream>
using namespace std;

int main()
{
    int dia, mes, ano, diasAvancar;

    cin >> dia >> mes >> ano >> diasAvancar;

    Data data(dia, mes, ano);

    for(int i = 0; i < diasAvancar; i++){
        data.avancarDia();
    }

    cout << data.getDataFormatada() << endl;

    return 0;
}