#ifndef INVOICE_H
#define INVOICE_H
#include <string>

class Invoice
{
    public:
        Invoice();
        Invoice(int num, std::string desc, int qtd, float preco);

        void setNum(int num);
        int getNum();

        void setDesc(std::string desc);
        std::string getDesc();

        void setQtd(int qtd);
        int getQtd();

        void setPreco(float preco);
        float getPreco();

        float getInvoiceAmount();
        void print();



    private:
        int num;
        std::string desc;
        int qtd;
        float preco;
};

#endif


#include <iostream>

Invoice::Invoice(){}

Invoice::Invoice(int n, std::string d, int q, float p){
    num = n;
    desc = d;
    qtd = q;
    preco = p;

    if(qtd < 0){
        qtd = 0;
    }
    if(preco < 0.0){
        preco = 0.0;
    }
}

void Invoice::setNum(int n){
    num = n;
}

int Invoice::getNum(){
    return num;
}

void Invoice::setDesc(std::string d){
    desc = d;
}

std::string Invoice::getDesc(){
    return desc;
}

void Invoice::setQtd(int q) {
    qtd = q;
}

int Invoice::getQtd(){
    return qtd;
}

void Invoice::setPreco(float p) {
    preco = p;
}

float Invoice::getPreco(){
    return preco;
}

float Invoice::getInvoiceAmount(){
    return qtd * preco;
}

void Invoice::print(){
    std::cout << num << " - " << desc << " - " << qtd << " - " << preco << " - " << getInvoiceAmount() << std::endl;
}

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num1, qtd1, num2, qtd2;
    string desc1, desc2;
    float preco1, preco2;

    cin >> num1;
    cin.ignore();
    getline(cin, desc1);
    cin >> qtd1;
    cin >> preco1;

    Invoice invoice1(num1, desc1, qtd1, preco1);

    cin >> num2;
    cin.ignore();
    getline(cin, desc2);
    cin >> qtd2;
    cin >> preco2;

    Invoice invoice2(num2, desc2, qtd2, preco2);

    invoice1.print();
    invoice2.print();

    return 0;
}