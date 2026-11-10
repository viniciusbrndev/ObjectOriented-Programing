#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <list>

class Transacao {
public:
    std::string data;
    double valor;
    std::string descricao;

    Transacao(std::string d, double v, std::string desc)
        : data(d), valor(v), descricao(desc) {}

    // O operator<< é uma função global amigável (não leva 'const' no final da assinatura)
    friend std::ostream& operator<<(std::ostream& os, const Transacao& t) {
        return os << "Data: " << t.data << " | Valor: R$ " << t.valor << " | Descricao: " << t.descricao;
    }
}; // Faltava ponto e vírgula

class Conta {
protected:
    std::string nome;
    double numConta;
    double saldo;
    std::vector<Transacao> extrato_vec; // Renomeado para não conflitar com o método extrato()

public:
    Conta(std::string name = " ", double n = 0.0, double sald = 0.0)
        : nome(name), numConta(n), saldo(sald) {}

    virtual ~Conta() = default;

    void insereTransacao(const Transacao& t) {
        extrato_vec.push_back(t);
    }

    bool deposito(double p) {
        if (p < 0) return false;
        saldo += p;
        return true;
    }

    virtual double retirada(double valor) {
        if (valor > saldo) return 0.0; // Faltava ponto e vírgula
        saldo -= valor;
        return valor;
    }

    // Removido o 'const' do final do operator<<
    friend std::ostream& operator<<(std::ostream& os, const Conta& c) {
        return os << "Cliente: " << c.nome << " | Num Conta: " << c.numConta << " | Saldo: R$ " << c.saldo;
    }

    virtual void extrato(std::ostream& os = std::cout) const {
        os << "\n=== EXTRATO DA CONTA ===" << std::endl;
        os << "Cliente: " << nome << "\nNum Conta: " << numConta << "\nSaldo: " << saldo << std::endl;
        os << "--- Historico de Transacoes ---" << std::endl;
        for (const auto& t : extrato_vec) {
            os << t << std::endl; // Reutiliza o operator<< da Transacao
        }
    }
};

class Corrente : public Conta {
    double limite;
public:
    Corrente(std::string name = " ", double n = 0.0, double sald = 0.0, double lim = 0.0)
        : Conta(name, n, sald), limite(lim) {}

    // A assinatura deve bater exatamente com a da classe base (sem o const no final)
    double retirada(double valor) override {
        if (valor > saldo + limite) {
            return 0.0;
        }
        if (valor > saldo) {
            double restante = valor - saldo;
            saldo = 0;
            limite -= restante;
        } else {
            saldo -= valor;
        }
        return valor;
    }

    void extrato(std::ostream& os = std::cout) const override {
        Conta::extrato(os);
        os << "Limite Cheque Especial: R$ " << limite << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Corrente& c) {
        // CORREÇÃO CRÍTICA: Use referência (&) no static_cast para evitar fatiamento (object slicing)
        os << static_cast<const Conta&>(c); 
        os << " | Limite: R$ " << c.limite;
        return os;
    }
};

class Poupanca : public Conta {
    std::string data;
public:
    Poupanca(std::string name = " ", double n = 0.0, double sald = 0.0, std::string date = "")
        : Conta(name, n, sald), data(date) {}

    void extrato(std::ostream& os = std::cout) const override {
        Conta::extrato(os);
        os << "Aniversario da Conta: " << data << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Poupanca& cp) {
        os << static_cast<const Conta&>(cp);
        os << " | Aniversario: " << cp.data;
        return os;
    }
};
class Banco{
    std::vector<Conta*> contas;
public:
    void extratos(){
        for(auto& cb : contas){
            cb->extrato();
        }
    }
    std::vector<Conta*>::iterator busca(std::string& find){
        for(auto it = contas.begin(); it != contas.end(); it++){
            if((*it)->nome == find)
                return it;
        }
        return nullptr;
    }
    std::vector<Conta*>::iterator busca2(std::string& find){
        return std::find_if(contas.begin, contas.end(), [&find](const Conta* c){return c != nullptr && c->nome == find;})
    }
    std::list<std::vector<Conta*>::iterator> filtraMaiores(double s){
        std::list<std::vector<Conta*>::iterator> contasM;
        for(auto it = this->contas.begin(); it != contas.end();++it){
            if((*it)->getSaldo() > s){
                constasM.push_back(it);
            }
        }
        return contasM;
    }
}
template<typename T>;
friend std::ostream& operator(std::ostream& os, T t){
    return os<<"Type: "<<t<<std::endl;
}
void print(std::ostream& os = std::cout){
    os<<"sasmfdkas"<<std::to_string(60)<<std::endl;
}

try{
    print();
}catch()