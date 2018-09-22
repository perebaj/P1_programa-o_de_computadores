
#include <iostream>
#include <string>
#include"fila.h"
#include "p1.cpp"
using namespace std;

int main()
{
    Fila f1(10, "Jose");

    int aux = 5;
    cout << "1) Inserir alguem na fila" << endl;
    cout << "2) Retirar alguem da fila" << endl;
    cout << "0) Sair" << endl;
    while (aux != 0)
    {
        cin >> aux;
        switch (aux)
        {
            case 1:
            {
                cout << "Digite o nome da pessoa que quer inserir:" << endl;
                string a;
                cin >> a;
                f1.set_inserir_elemento(a);
                f1.print();
                break;
            }
            case 2:
            {
                f1.set_retira_elemento();
                f1.print();

                break;
            }
        }
    }
    f1.imprime_vetor();


    return 0;
}