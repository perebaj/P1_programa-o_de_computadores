#include<iostream>
#include<string>
using namespace std;
class Fila
{
  private:
    static int total_filas;
    static int total_elementos;
    int tamanho;
    int elemento = 0;
    string *nm; //PONTEIRO PARA PRIMEIRA POSIÇÃO
    string nome; //  NOME DA PESSOA QUE SERA ADICIONADA A FILA

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
    int get_elemento() const {return elemento;}
    int get_tamanho() const {return tamanho;}
    void imprime_vetor() const{
        for(int i = 0; i < get_tamanho(); i++){
            cout << nm[i] << endl;
        }
    }
};