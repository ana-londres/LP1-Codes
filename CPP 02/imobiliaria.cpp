#ifndef IMOVEL_H
#define IMOVEL_H
#include <string>

class Imovel
{
    public:
        Imovel(int tipo);
        std::string getNome();
        void lerAtributos();
        void exibirAtributos();

    protected:
        int tipo;
        float valor;
        std::string disponibilidade;
};

#endif

#ifndef CASA_H
#define CASA_H

class Casa : public Imovel
{
    public:
        Casa();
        void lerAtributos();
        void exibirAtributos();

    private:
        int numPav;
        int numQuartos;
        float areaTerreno;
        float areaConstruida;
};

#endif

#ifndef APARTAMENTO_H
#define APARTAMENTO_H

class Apartamento : public Imovel
{
    public:
        Apartamento();
        void lerAtributos();
        void exibirAtributos();

    private:
        float area;
        int numQuartos;
        int andar;
        float valCondo;
        int numGaragem;
};

#endif

#ifndef TERRENO_H
#define TERRENO_H

class Terreno : public Imovel
{
    public:
        Terreno();
        void lerAtributos();
        void exibirAtributos();

    private:
        float area;
};

#endif

#include <iostream>

Imovel::Imovel(int t)
{
    tipo = t;
}

void Imovel::exibirAtributos(){
    std::cout << getNome() << " para " << disponibilidade << ", R$ " << valor << ". ";
}

void Imovel::lerAtributos(){
    std::cin >> valor >> disponibilidade;
}

std::string Imovel::getNome(){
    switch(tipo){
        case 1: return "Casa";
        case 2: return "Apartamento";
        case 3: return "Terreno";
        case 0: return "Indefinido";
    }
}

#include <iostream>

Casa::Casa() : Imovel(1)
{}

void Casa::exibirAtributos(){
    Imovel::exibirAtributos();

    std::cout << numPav << " pavimentos, " << numQuartos << " quartos, ";
    std::cout << areaTerreno << "m2 de área de terreno e " << areaConstruida << "m2 de área construída." << std::endl;
}

void Casa::lerAtributos(){
    Imovel::lerAtributos();

    std::cin >> numPav >> numQuartos >> areaTerreno >> areaConstruida;
}

#include <iostream>

Apartamento::Apartamento() : Imovel(2)
{}

void Apartamento::exibirAtributos(){
    Imovel::exibirAtributos();

    std::cout << area << "m2 de área, " << numQuartos << " quartos, " << andar << " andar(es), ";
    std::cout << valCondo << " de condomínio, " << numGaragem << " vaga(s) de garagem." << std::endl;
}

void Apartamento::lerAtributos(){
    Imovel::lerAtributos();

    std::cin >> area >> numQuartos >> andar >> valCondo >> numGaragem;
}

#include <iostream>

Terreno::Terreno() : Imovel(3)
{}

void Terreno::exibirAtributos(){
    Imovel::exibirAtributos();

    std::cout << area << "m2 de área de terreno." << std::endl;
}

void Terreno::lerAtributos(){
    Imovel::lerAtributos();

    std::cin >> area;
}

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, tipo;

    Casa c;
    Apartamento a;
    Terreno t;

    cin >> n;

    while(n--){
        cin >> tipo;

        switch(tipo){
            case 1:
                c.lerAtributos();
                c.exibirAtributos();
                break;
            case 2:
                a.lerAtributos();
                a.exibirAtributos();
                break;
            case 3:
                t.lerAtributos();
                t.exibirAtributos();
                break;
        }
    }

    return 0;
}