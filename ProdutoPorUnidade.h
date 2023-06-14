#ifndef PRODUTOPORUNIDADE_H
#define PRODUTOPORUNIDADE_H

#include <string>
#include "Produto.h"

class ProdutoPorUnidade : public Produto 
{
private:
    string quantidade;

public:
    ProdutoPorUnidade(string, string, string, string);
    string getQuantidade();

    //lembrar de verificar sua utilidade
    void setQuantidade(int quantidade);
    ~ProdutoPorUnidade();
};


#endif
