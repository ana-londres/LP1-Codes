class Data
{
    public:
        int dia;
        int mes;
        int ano;

        Data();
};


Data::Data()
{
    dia = 1;
    mes = 1;
    ano = 1;
}

#include <iostream>
using namespace std;

int main()
{
    Data data;

    cin >> data.dia >> data.mes >> data.ano;

    cout << data.dia << "/" << data.mes << "/" << data.ano << endl;

    return 0;
}