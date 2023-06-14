#include "ProdutoPorUnidade.h"

ProdutoPorUnidade::ProdutoPorUnidade(string quantidade, string nome, string codigo, string preco)
    : Produto(nome, codigo, preco) 
{
    this->quantidade = quantidade;
}

string ProdutoPorUnidade::getQuantidade()  
{
    return quantidade;
}

//lembrar de verificar sua utilidade
void ProdutoPorUnidade::setQuantidade(int quantidade) 
{
    this->quantidade = quantidade;
}

ProdutoPorUnidade::~ProdutoPorUnidade() {}


