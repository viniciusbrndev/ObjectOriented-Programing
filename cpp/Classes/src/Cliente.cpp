#include "include/Cliente.h"
#include <iostream>
#include <string>

Cliente:: Cliente(string nome, string cpf, string end){
    this->nome = nome;
    this->cpf = cpf;
    this->end = end;
}
string Cliente:: getNome() const{
    return nome;
}
void Cliente:: setEnd(string end = " "){
    this->end = end;
}
void Cliente:: setNome(string nome = " "){
    this->nome  = nome;
}