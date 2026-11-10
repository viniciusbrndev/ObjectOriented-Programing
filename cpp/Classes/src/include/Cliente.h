#ifndef CLIENTE_H
#define CLIENTE_H
#include <string.h>
using namespace std;

class Cliente{
    string nome;
    string end;
    string cpf;

    public:
        Cliente(string nome, string cpf, string end);

    private:
        void setNome(string nome) const;
        void setCpf(string cpf) const;
        void setEnd(string end) const;
        string getNome();
        string getCpf();
        string getEnd();
    

};


#endif
