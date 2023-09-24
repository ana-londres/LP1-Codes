#ifndef PEDIDO_H
#define PEDIDO_H
#include <string>

class Pedido
{
    public:
        Pedido();
        Pedido(int n, std::string d, int q, float p);
        float getTotal();
        int getNum();
        std::string getDesc();
        int getQuant();
        float getPreco();
        int setQuant(int q);

    private:
        int numero;
        std::string desc;
        int quant;
        float preco;
};

#endif

#include <iostream>

Pedido::Pedido(int n, std::string d, int q, float p)
{
    numero = n;
    desc = d;
    quant = q;
    preco = p;
}

Pedido::Pedido(){
    quant = numero = preco = 0;
}

int Pedido::setQuant(int q){
    quant = q;
}

float Pedido::getTotal(){
    return quant * preco;
}

int Pedido::getNum(){
    return numero;
}

std::string Pedido::getDesc(){
    return desc;
}

int Pedido::getQuant(){
    return quant;
}

float Pedido::getPreco(){
    return preco;
}

#ifndef MESADERESTAURANTE_H
#define MESADERESTAURANTE_H

class MesaDeRestaurante
{
    public:
        MesaDeRestaurante();
        void adicionarPedido(Pedido p);
        void zerarPedidos();
        float calcularTotal();
        void exibirConta();

    private:
        Pedido pedidos[100];
};

#endif

#include <iostream>

MesaDeRestaurante::MesaDeRestaurante()
{

}

void MesaDeRestaurante::adicionarPedido(Pedido p){
    int q;
    for(int i = 0; i < 100; i++){
        if (pedidos[i].getNum() == p.getNum()){
            q = pedidos[i].getQuant() + p.getQuant();
            pedidos[i].setQuant(q);
            break;
        }
        if (pedidos[i].getQuant() == 0){
            pedidos[i] = p;
            break;
        }
    }
}

void MesaDeRestaurante::zerarPedidos(){
    for(int i = 0; i < 100; i++){
        pedidos[i].setQuant(0);
    }
}

float MesaDeRestaurante::calcularTotal(){
    float total;
    for(int i = 0; i < 100; i++){
        total += pedidos[i].getTotal();
    }

    return total;
}

void MesaDeRestaurante::exibirConta() {
    float totalMesa = 0;
    for (Pedido p : pedidos) {
        if (p.getQuant() > 0) {
            std::cout << p.getNum() << " - " << p.getDesc() << " - " << p.getQuant()
                      << " - " << p.getPreco() << " - R$ " << p.getTotal() << std::endl;
            totalMesa += p.getTotal();
        }
    }
    std::cout << "Total: R$ " << totalMesa << std::endl;
}

#ifndef RESTAURANTE_H
#define RESTAURANTE_H
class Restaurante
{
    public:
        Restaurante();
        void adicionarPedido(Pedido p, int indMesa);
        float calcularTotalRestaurante();
        MesaDeRestaurante getMesa(int ind);

    private:
        MesaDeRestaurante mesas[100];
};

#endif

Restaurante::Restaurante()
{
}

void Restaurante::adicionarPedido(Pedido p, int indMesa){
    mesas[indMesa].adicionarPedido(p);
}

float Restaurante::calcularTotalRestaurante(){
    float total = 0;
    for(int i = 0; i < 100; i++){
        total = mesas[i].calcularTotal();
    }
    return total;

}

MesaDeRestaurante Restaurante::getMesa(int ind){
    return mesas[ind];
}

#include <iostream>
using namespace std;
#include <string>

int main() {
    Restaurante rest;

    int num, quant, indMesa;
    string desc;
    float preco;

    while (true) {
        cin >> num;
        if (num < 0) {
            break;
        }
        cin.ignore();
        getline(cin, desc);
        cin >> quant >> preco >> indMesa;

        Pedido pedidos(num, desc, quant, preco);
        rest.adicionarPedido(pedidos, indMesa - 1);
    }

    for (int i = 0; i < 100; i++) {
        MesaDeRestaurante mesas = rest.getMesa(i);
        if (mesas.calcularTotal() > 0) {
            cout << "Mesa " << i + 1 << endl;
            mesas.exibirConta();
            cout << "\n";
        }
    }
    float totalRestaurante = rest.calcularTotalRestaurante();
    cout << "Total Restaurante: R$ " << totalRestaurante << std::endl;

    return 0;
}