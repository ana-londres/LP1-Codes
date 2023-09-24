#include <string>
class Invoice
{
    public:
        int num;
        std::string desc;
        int qtd;
        float preco;
        
        float getInvoiceAmount();
        
        Invoice();
};

Invoice::Invoice(){}

float Invoice::getInvoiceAmount(){
    return preco*qtd;
}

#include <iostream>
#include <string>
using namespace std;

int main()
{
    Invoice invoice[2];
    
    for(int i = 0; i < 2; i++){
        cin >> invoice[i].num;
        cin.ignore();
        getline(cin, invoice[i].desc);
        cin >> invoice[i].qtd >> invoice[i].preco;
        
        if(invoice[i].qtd < 0){
            invoice[i].qtd = 0;
        }
        
        if(invoice[i].preco < 0){
            invoice[i].preco = 0;
        }
        
        cout << invoice[i].num << " - " << invoice[i].desc << " - ";
        cout << invoice[i].qtd << " - " << invoice[i].preco << " - ";
        cout << invoice[i].getInvoiceAmount() << endl;
    }
    return 0;
}