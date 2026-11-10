#pragma once
#include "Unidade.hpp"

namespace Jogo {

class Infantaria : public Unidade {
private:
    int forca;
    int velocidade;

public:
    Infantaria();
    ~Infantaria() override = default;

    int getPoderAtaque() override;
    void print() override;
};

} // namespace Jogo