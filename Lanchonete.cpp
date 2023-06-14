#include "Lanchonete.h"

Lanchonete::Lanchonete() {
}

void Lanchonete::realizarPedido(Pedido*ponteiro) {
    this -> historicoPedidos.push_back(&ponteiro);
}

void Lanchonete::removerPedido(int entrada) {
     vector<Pedido>::iterator it;
    it = historicoPedidos.begin() + entrada - 1;
    historicoPedidos.erase(it)
}

void Lanchonete::setNomeLanchonete(string nome) {
    this->nomeLoja = nome;
}

std::string Lanchonete::getNome() {
    return nomeLoja;
}

void Lanchonete::setEndereco(string cidade, string bairro, string rua, int numero) {
    this->endereco.cidade = cidade;
    this->endereco.bairro = bairro;
    this->endereco.rua = rua;
    this->endereco.numero = numero;
}

void Lanchonete::imprimeEndereco() {
    cout<<"Cidade: "<<endereco.cidade<<endl;
    cout<<"Bairro: "<<endereco.bairro<<endl;
    cout<<"Rua: "<<endereco.rua<<endl;
    cout<<"Numero: "<<endereco.numero<<endl;
}

double Lanchonete::getLucro() {
    return lucros;
}

void Lanchonete::setTelefone(int telefone) {
    this->telefone = telefone;
}

int Lanchonete::getTelefone() {
    return telefone;
}

Lanchonete::~Lanchonete() {
}
