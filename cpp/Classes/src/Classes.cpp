#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Veiculo{
protected:
    int peso;
    float imposto, preco;
public:
    Veiculo(int p = 0, float imp = 0):peso(p), imposto(imp), preco(0.0){};
    virtual ~Veiculo() = default;
//metodos
    virtual float precoFinal(){
        std::cout<<"Não se aplica\n";
        return 0.0;
    }
    ostream& operator<<(){
        std::cout<<"Peso: "<<peso<<"\nImposto: "<<imposto<<"\nPreco: "<<preco<<std::endl;
    }  
}
class Carro:Veiculo{
private:
    std::string modelo, cor;
public:
    Carro(std::string model = " ", std::string cor = " ", int peso = 0, int preco = 0): Veiculo(peso), preco(preco), modelo(model), cor(cor){
        imposto = preco*0.45;
    }
    float precoFinal()override{
        return imposto + preco;
    }
    void carroMaisCaro(const std::vector<Carro>& carros){
        auto it = std::max_element(carros.begin(), carros.end(), [](const Carro& a, const Carro& b){return a.preco < b.preco});
        std::cout<<"Carro mais caro: "<<it->modelo;
        std::cout<<"Infos:\n\n"<<(*it);

    }
    std::vector<std::vector<Carro>::iterator> filtraCarrosPorModelo(const std::string& md, const std::vector<Carro>& carros){
        std::vector<std::vector<Carro>::iterator> resultado;
        for(auto it = carros.begin(); it != carros.end();it++){
            if(it->modelo == md)
                resultado.push_back(it);
        }
    }
}

class Caminhao:Veiculo{
    std::string carga;

public:
    Caminhao(std::string carga,  int peso, float preco):Veiculo(peso), carga(carga), preco(preco){
        imposto = preco * 0.5;
    }
    float precoFinal()override{
        return preco + imposto;
    }
}