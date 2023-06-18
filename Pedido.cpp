#include "Pedido.h"

void Pedido::adicionarProdutounidade(ProdutoPorUnidade produto) {//*
    this -> produtosUnidades.push_back (produto);
}

void Pedido::adicionarProdutopeso(ProdutoPorPeso produto) {//*
     this -> produtosPesos.push_back (produto);
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
        total = total + (produtosUnidades[i].getPreco() * produtosUnidades[i].getQuantidade());
    };
    for(int i = 0; i<produtosPesos.size(); i++){
        total = total + (produtosPesos[i].getPreco() * produtosPesos[i].getPeso());
    };
    this->valorTotal = total;
    return valorTotal;
}

void Pedido::imprimirProdutos(){
    cout << "Produtos por unidade: " << endl;
    for (int i = 0; i < produtosUnidades.size(); i++) {
        cout <<"Quantidade: "<<produtosUnidades[i].getQuantidade()<<" | Nome: " <<produtosUnidades[i].getNome() << " | Valor: " << produtosUnidades[i].getPreco() * produtosUnidades[i].getQuantidade() << endl;
    };
    cout << "------------------------" << endl;
    cout << "Produtos por peso: " << endl;
    for (int i = 0; i < produtosPesos.size(); i++) {
        cout <<"Quantidade: "<<produtosPesos[i].getPeso()<<" | Nome: " <<produtosPesos[i].getNome() << " | Valor: " << produtosPesos[i].getPreco() * produtosPesos[i].getPeso() << endl;
    };
    cout<<"Total a pagar: "<<getValorTotal()<<endl;
}

int Pedido::getSize(int lista){ //*
if(lista == 1){
    if(produtosPesos.size() != 0){
        return produtosPesos.size();
    }else{
        return -1;
    };
};
if(lista == 2){
    if(produtosUnidades.size() != 0){
        return produtosUnidades.size();
    }else{
        return -1;
    };
};
}

int Pedido::getUnidadePedido(int pos){ //*
    return produtosUnidades[pos].getQuantidade();
}

float Pedido::getPesoPedido(int pos){ //*
    return produtosPesos[pos].getPeso();
}

int Pedido::getCodigoProdutoPeso(int pos){
    return produtosPesos[pos].getCodigo();
}

int Pedido::getCodigoProdutoUnidade(int pos){
    return produtosUnidades[pos].getCodigo();
}
