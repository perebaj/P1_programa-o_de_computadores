#include <iostream>
#include <string>
using namespace std;

class Fila
{
  private:
    static int total_filas;
    static int total_elementos;
    int tamanho;
    int elemento = 0;
    string *nm;
    string nome; //  nome da pessoa que será adicionada na fila;

  public:
    Fila(int _tam = 0, string a = "Anônimo");
    ~Fila();
    void set_tamanho(int);
    void set_retira_elemento();
    void set_inserir_elemento(string a);
    static int get_total_filas();
    static int get_total_elementos();
    void name(string);
    void print() const;
    int get_elemento() const
    {
        return elemento;
    }
    int get_tamanho() const
    {
        return tamanho;
    }
    void imprime_vetor() const{
        for(int i = 0; i < get_tamanho(); i++){
            cout << nm[i] << endl;
        }
    }
};
/*
Obj: valida o tamanho do vetor de string e se for válido aloca-o dinamicamente
@param  _tam    tamanho do vetor
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
Obj: inseri um elemento da fila
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
Contrutor 

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
Obj: Printa os dados
*/
void Fila::print() const
{
    cout << "Numero Total de filas: " << Fila::get_total_filas() << endl;
    cout << "Numero Total de Elementos: " << Fila::get_total_elementos() << endl;
    cout << "Elementos da Fila " << get_elemento() << endl;
}
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

