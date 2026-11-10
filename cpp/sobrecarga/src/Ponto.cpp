#include "Ponto.h"
#include <iostream>

using namespace std;

    Ponto::Ponto(int a = 0, int b = 0){
        this->x = a;
        this->y = b;
    }
    Ponto::~Ponto();
    void Ponto::set(int x, int y){
        this->x = x;
        this->y = y;
    }
    void Ponto::set(const Ponto& P){
        set(P.x, P.y);
    }
    void print(){
        cout<<"X: "<<this->x<<"Y: "<<this->y<<endl;
    }

    Ponto& Ponto:: operator ++(){
        this->x++;
        this->y++;
        return *this;
    }//++x
    Ponto Ponto:: operator ++(int){
        Ponto tmp = *this;
        ++(*this);
        return tmp
    }//x++

    Ponto Ponto:: operator +(const Ponto& p){
        Ponto tmp =  *this;
        tmp.x = this->x + p.x;
        tmp.x = this->y + p.y;

        return tmp;
    }
    Ponto& Ponto:: operator =();

