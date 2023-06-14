#include "Pedido.h"

void Pedido::adicionarProdutounidade(int codigo, Estoque estoque) {
    this -> produtosUnidades.push_back (estoque.getunidade(codigo));
}

void Pedido::adicionarProdutopeso(int codigo, Estoque estoque) {
     this -> produtosPesos.push_back (estoque.getpeso(codigo));
}

void Pedido::removerProdutounidade(int entrada) {
   vector<ProdutoPorUnidade>::iterator it;
    it = produtosUnidades.begin() + entrada;
    produtosUnidades.erase(it);
}

void Pedido::removerProdutopeso(int entrada) {
    vector<ProdutoPorPeso>::iterator it;
    it = produtosPesos.begin() + entrada;
    produtosPesos.erase(it);
}

void Pedido::setNome(std::string nome) {
    this -> nomeCliente = nome;
}

void Pedido::setCodigo(int codigo) {
    this -> codigoPedido = codigo;
}

std::string Pedido::getNome(){
    return nomeCliente;
}

int Pedido::getCodigo(){
    return codigoPedido;
}

float Pedido::getValorTotal(){
    float total = 0;
    for(int i = 0; i<produtosUnidades.size(); i++){
        total = total + produtosUnidades[i].getPreco();
    };
    for(int i = 0; i<produtosPesos.size(); i++){
        total = total + produtosPesos[i].getPreco();
    };
    this->valorTotal = total;
    return valorTotal;
}

