#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include <string>

class FiguraGeometrica
{
    public:
        FiguraGeometrica(int tipo);
        virtual float calcularArea();
        virtual void lerAtributosArea();
        std::string getNome();

    protected:
        int tipo;
};

#endif

#ifndef QUADRADO_H
#define QUADRADO_H

class Quadrado : public FiguraGeometrica
{
    public:
        Quadrado();
        float calcularArea();
        void lerAtributosArea();

    private:
        float lado;
};

#endif // QUADRADO_H

#ifndef TRIANGULO_H
#define TRIANGULO_H

class Triangulo : public FiguraGeometrica
{
    public:
        Triangulo();
        float calcularArea();
        void lerAtributosArea();

    private:
        float base, altura;
};

#endif // TRIANGULO_H

#ifndef RETANGULO_H
#define RETANGULO_H

class Retangulo : public FiguraGeometrica
{
    public:
        Retangulo();
        float calcularArea();
        void lerAtributosArea();


    private:
        float base, altura;
};

#endif // RETANGULO_H

#ifndef CIRCULO_H
#define CIRCULO_H

class Circulo : public FiguraGeometrica
{
    public:
        Circulo();
        float calcularArea();
        void lerAtributosArea();

    private:
        float raio;
};

#endif // CIRCULO_H

#include <string>

FiguraGeometrica::FiguraGeometrica(int tipo){
    this-> tipo = tipo;
}

float FiguraGeometrica::calcularArea(){
    return 0; // vai ser sobrescrito pelas classes filhas
}

void FiguraGeometrica::lerAtributosArea(){

}

std::string FiguraGeometrica::getNome(){
    switch(tipo){
        case 1: return "Quadrado";
        case 2: return "Retângulo";
        case 3: return "Triângulo";
        case 4: return "Círculo";
        default: return "Indefinido";
    }
}

#include <iostream>
using namespace std;

Quadrado::Quadrado() : FiguraGeometrica(1)
{
    //ctor
}

float Quadrado::calcularArea(){
    return lado * lado;
}

void Quadrado::lerAtributosArea(){
    cin >> lado;
}

#include <iostream>
using namespace std;

Triangulo::Triangulo() : FiguraGeometrica(3)
{
}

float Triangulo::calcularArea(){
    return (base * altura) / 2;
}

void Triangulo::lerAtributosArea(){
    cin >> base;
    cin >> altura;
}

#include <iostream>
using namespace std;

Circulo::Circulo() : FiguraGeometrica(4)
{
    //ctor
}

float Circulo::calcularArea(){
    return 3.14 * raio * raio;
}

void Circulo::lerAtributosArea(){
    cin >> raio;
}

#include <iostream>
using namespace std;

Retangulo::Retangulo() : FiguraGeometrica(2)
{
    //ctor
}

float Retangulo::calcularArea(){
    return base * altura;
}

void Retangulo::lerAtributosArea(){
    cin >> base;
    cin >> altura;
}

#include <iostream>
using namespace std;

int main()
{
    int tipo;

    FiguraGeometrica *fig;

    do{
        cin >> tipo;

        switch(tipo){
            case 1:
                fig = new Quadrado();
                break;
            case 2:
                fig = new Retangulo();
                break;
            case 3:
                fig = new Triangulo();
                break;
            case 4:
                fig = new Circulo();
                break;
            default:
                return 0;
        }

        fig->lerAtributosArea();
        cout << fig->getNome() << " polimórfico de área " << fig->calcularArea() << endl;

        delete fig;

    }while(tipo > 0);

    return 0;
}