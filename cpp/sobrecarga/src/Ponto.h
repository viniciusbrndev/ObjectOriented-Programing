#ifndef PONTO H
#define PONTO H
class Ponto {
    int x ,y;
    
    public:
    Ponto(int = 0, int = 0);
    ~Ponto();
    void set(int, int);
    void set(const Ponto&);
    void print();

    //operadores unários
    Ponto& operator ++();//++x
    Ponto operator ++(int);//x++

    Ponto operator +(const Ponto&);
    Ponto& operator =();

    friend bool operator ==(const Ponto&, const Ponto&);

}
#endif