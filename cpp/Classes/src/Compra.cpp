#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>

class Compra {
    std::string nome;
    double valorBruto;
    double icms;

public:
    Compra(std::string n = " ", double vb = 0.0, double icm = 0.0)
        : nome(n), valorBruto(vb), icms(icm) {}
    
    virtual ~Compra() = default;

    // Setters
    void setName(std::string n = " ") { // Nome do parâmetro corrigido
        if (n == " ")
            return;
        this->nome = n;
    }
    void setVal(double v) {
        this->valorBruto = v;
    }
    void setIcms(double i) {
        this->icms = i;
    }

    // Getters
    std::string getNome() const { return this->nome; }
    double getValor() const { return this->valorBruto; }
    double getIcms() const { return this->icms; }

    // Métodos virtuais
    virtual double valorFinal() const {
        return valorBruto * icms;
    }

    virtual void print(std::ostream& os) const {
        os << "Nome: " << nome << "\nValor B: " << valorBruto << "\nICMS: " << icms;
    }

    // Operador amigo para permitir 2 parâmetros
    friend std::ostream& operator<<(std::ostream& os, const Compra& v) {
        v.print(os); // Polimorfismo funciona aqui
        return os;
    }
};

class Importado : public Compra { // public adicionado
    double precoFrete;

public:
    Importado(std::string nome, double icms, double valor, double frete)
        : Compra(nome, valor, icms), precoFrete(frete) {}

    void setPrecoFrete(double p) { this->precoFrete = p; }
    double getPrecofrete() const { return precoFrete; }

    double valorFinal() const override { // const ANTES de override
        return ((Compra::getValor() + getPrecofrete()) * 1.6) * (1 + Compra::getIcms());
    }

    void print(std::ostream& os) const override {
        Compra::print(os);
        os << "\nPreco do frete: " << this->precoFrete; // Usa 'os' ao invés de std::cout
    }
};

class Nacional : public Compra { // public adicionado
    double ipi;

public:
    Nacional(std::string nome, double icms, double valor, double ipi)
        : Compra(nome, valor, icms), ipi(ipi) {}

    void setIPI(double ipi) { this->ipi = ipi; }
    double getIpi() const { return this->ipi; }

    double valorFinal() const override {
        return (getValor() * (1 + this->ipi)) * (1 + getIcms());
    }

    void print(std::ostream& os) const override {
        Compra::print(os);
        os << "\nIPI: " << this->ipi; // Usa 'os' ao invés de std::cout
    }
};

int main() {
    std::vector<std::unique_ptr<Compra>> compras;
    std::list<std::unique_ptr<Compra>> comprasList;

    compras.push_back(std::make_unique<Nacional>("Celular", 0.5, 2000.0, 1.10));
    compras.push_back(std::make_unique<Nacional>("carregador", 0.5, 50.0, 0.10));
    compras.push_back(std::make_unique<Importado>("Tablet", 0.5, 1500.0, 40.0));
    
    comprasList.push_back(std::make_unique<Nacional>("Celular", 0.5, 2000.0, 1.10));
    comprasList.push_back(std::make_unique<Nacional>("carregador", 0.5, 50.0, 0.10));
    comprasList.push_back(std::make_unique<Importado>("Tablet", 0.5, 1500.0, 40.0));

    std::sort(comprasList.begin(), comprasList.end(), [](Compra &a, Compra& b){return a.getValor() < b.getValor()});


    for (auto it = compras.begin(); it != compras.end(); ++it) {
        std::cout << **it << "\nValor Final: " << (*it)->valorFinal() << "\n-------------------\n"; // **it para acessar o objeto
    }
    for (auto it = compras.begin(); it != compras.end(); ++it) {
        double newValue;
        if(auto imp = dynamic_cast<Importado*>(it->get())){
            newValue = imp->valorFinal()*1.05;
            std::cout<<"\nEh importado!"<<"Valor taxado: "<<newValue;
        }
        else if(auto nac = dynamic_cast<Nacional*>(it->get())){
            newValue = nac->valorFinal()*1.01;
            std::cout<<"\nEh nacional!"<<"Valor taxado: "<<newValue;
        }
        
    }
    return 0;
}