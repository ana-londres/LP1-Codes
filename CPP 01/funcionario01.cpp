#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <string>

class funcionario
{
    public:
        funcionario();

        std::string primeiroNome;
        std::string sobrenome;
        float salarioMensal;

        float getSalarioAnual(){
            return salarioMensal * 12;
        }
};

#endif

funcionario::funcionario()
{
}

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    funcionario funcionarios[n];

    for(int i = 0; i < n; i++){
        cin >> funcionarios[i].primeiroNome;
        cin >> funcionarios[i].sobrenome;
        cin >> funcionarios[i].salarioMensal;
    }


    for(int i = 0; i < n; i++){
        cout << funcionarios[i].primeiroNome << " " << funcionarios[i].sobrenome << " - "
             << funcionarios[i].salarioMensal << " - " << funcionarios[i].getSalarioAnual() << endl;

    }

    return 0;
}
