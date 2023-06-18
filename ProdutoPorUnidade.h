#ifndef PRODUTOPORUNIDADE_H
#define PRODUTOPORUNIDADE_H

#include <string>
#include "Produto.h"

class ProdutoPorUnidade : public Produto
{
private:
    int quantidade;

public:
    ProdutoPorUnidade(int = 0, string = "", int = 0, float = 0.0);
    int getQuantidade();

    //lembrar de verificar sua utilidade
    void setQuantidade(int quantidade);
    ~ProdutoPorUnidade();
};


#endif
