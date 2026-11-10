#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

class Carro{
    string placa;
    int velocidade;

    private:
        void setPlaca(string p){
            placa = p;
        } 
        string getPlaca(){
            return placa;
        }
        void setVelocidade(int v){
            velocidade = (v > 0) ? v : 0;
        }
        int getVelocidade(){
            return velocidade;
        }
    
    public:
        Carro(string p, int v){
            setPlaca(p);
            setVelocidade(v);
        }
        void acelerar(){
            setVelocidade(getVelocidade()+10);
        }
        void frear(){
            setVelocidade(getVelocidade()-10);
        }
        void status(){
            cout<<"Placa do carro: "<<getPlaca()<<endl<<"Velocidade atual: "<<getVelocidade(); 
        }

    };


int main(int arc, char *argv){
    Carro *carro = new Carro("XPP-0000", 0);
    
    // Carro McQueen("XPP-000", 0);
    // McQueen.acelerar();
    // McQueen.acelerar();

    // McQueen.status();
}