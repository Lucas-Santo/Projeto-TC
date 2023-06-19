#include "ProdutoPorUnidade.h"

ProdutoPorUnidade::ProdutoPorUnidade(int quantidade, string nome, int codigo, float preco)
    : Produto(nome, codigo, preco)
{
    this->quantidade = quantidade;
}

int ProdutoPorUnidade::getQuantidade()
{
    return quantidade;
}

//lembrar de verificar sua utilidade
void ProdutoPorUnidade::setQuantidade(int quantidade)
{
    this->quantidade = quantidade;
}

ProdutoPorUnidade::~ProdutoPorUnidade() {}


