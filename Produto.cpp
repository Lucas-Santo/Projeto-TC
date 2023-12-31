#include "Produto.h"

Produto::Produto(string nome, int codigo, float preco)
{
    this->nome = nome;
    this->codigo = codigo;
    this->preco = preco;
}

string Produto::getNome()
{
    return nome;
}

int Produto::getCodigo()
{
    return codigo;
}

float Produto::getPreco()
{
    return preco;
}

//lembrar de verificar sua utilidade
void Produto::setNome(std::string nome)
{
    this->nome = nome;
}

void Produto::setCodigo(int codigo)
{
    this->codigo = codigo;
}

void Produto::setPreco(float preco)
{
    this->preco = preco;
}

void Produto::setRegraManipulacao(std::string regra)
{
    this->regraManipulacao = regra;
}

void Produto::setRegraTransporte(std::string regra)
{
    this->regraTransporte = regra;
}

std::string Produto::getRegraManipulacao()
{
    return regraManipulacao;
}

std::string Produto::getRegraTransporte()
{
    return regraTransporte;
}

Produto::~Produto() {}
