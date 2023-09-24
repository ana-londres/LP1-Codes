#include <iostream>
using namespace std;

int main() {
    int aquatica, predadora, domestica, voa, noturna;

    cin >> aquatica;

    cin >> predadora;

    cin >> domestica;

    cin >> voa;

    cin >> noturna;

    if(aquatica && predadora && voa && noturna)
        cout << "garça" << endl;
    else if(predadora && voa && noturna)
        cout << "coruja" << endl;
    else if (aquatica && predadora && voa)
        cout << "gaivota" << endl;
    else if (aquatica && predadora)
        cout << "pinguim" << endl;
    else if (aquatica && voa)
        cout << "pato" << endl;
    else if (predadora && voa)
        cout << "falcão" << endl;
    else if(domestica && voa)
        cout << "galinha" << endl;
    else if (voa)
        cout << "pardal" << endl;
    else if (predadora)
        cout << "ema" << endl;
    else
        cout << "avestruz" << endl;

    return 0;
}