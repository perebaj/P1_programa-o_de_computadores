#include <iostream>
#include <string>
//#include "fila.h"
using namespace std;

/*
Obj  -  Verifica a validade do tamanho da fila

@param  _tamanho  Tamanho que a fila foi setadas
*/
void Fila::set_tamanho(int _tamanho)
{
    if (_tamanho > 0)
    {
        nm = new string[_tamanho];
        tamanho = _tamanho;
    }
    else
        nm = NULL;
}
int Fila::total_filas = 0;
int Fila::total_elementos = 0;

/*
Obj: Retira um elemento da fila
*/
void Fila::set_retira_elemento()
{
    if (elemento > 0)
    {
        nm[0] = " ";

        for (int i; i < tamanho; i++)
        {
            nm[i] = nm[i + 1];
        }
        elemento--;
        total_elementos--;
    }
    else
        cout << "Nao e possivel retirar um elemento!" << endl;
}

/*
Obj: inserir um elemento na fila
@param   string a  Elemento que vai ser inserido na fila
*/

void Fila::set_inserir_elemento(string a)
{
    if (elemento < tamanho)
    {
        elemento++;
        nm[elemento - 1] = a;
        total_elementos++;
    }
    else
        cout << "Fila preechida ao maximo! Nao e possivel adicionar mais elementos" << endl;
}

/*
Obj: aloca o nome digitado pelo usuario na variavel string privada
*/
void Fila::name(string a)
{
    nome = a;
}

/*
ConStrutor 

@   int _tam    tamanaho do vetor
@   string b    nome da pessoa q a fila vai receber
*/
Fila::Fila(int _tam, string b)
{
    set_tamanho(_tam);
    name(b);
    total_filas++;
    set_inserir_elemento(b);
}
/*
*Deleta a memoria alocada dinamicamente
*Subtrai o numero total de filas caso o numero de elementos atual da fila seja igual a zero
*/
Fila::~Fila()
{
    delete[] nm;
    if(elemento == 0)
        total_filas--;

}

int Fila::get_total_filas() 
{
    return total_filas;
}
int Fila::get_total_elementos()
{
    return total_elementos;
}

/*
Obj: Printa os dados na tela
*/

void Fila::print() const
{
    cout << "Numero Total de filas: " << Fila::get_total_filas() << endl;
    cout << "Numero Total de Elementos: " << Fila::get_total_elementos() << endl;
    cout << "Elementos da Fila " << get_elemento() << endl;
}


