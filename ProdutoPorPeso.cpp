#include "ProdutoPorPeso.h"

ProdutoPorPeso::ProdutoPorPeso(float peso, string nome, int codigo, float preco)
    : Produto(nome, codigo, preco)
{
    this->peso = peso;
}

float ProdutoPorPeso::getPeso()
{
    return peso;
}

//lembrar de verificar sua utilidade
void ProdutoPorPeso::setPeso(float peso)
{
    this->peso = peso;
}

ProdutoPorPeso::~ProdutoPorPeso() {}
