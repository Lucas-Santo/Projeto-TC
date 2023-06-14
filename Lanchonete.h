#ifndef LANCHONETE_H
#define LANCHONETE_H

class Lanchonete {
protected:
    Estoque estoque;
private:
    std::string nomeLoja;
    Endereco endereco;
    int telefone;
    double lucros;
    std::vector<Pedido> historicoPedidos;

public:
    Lanchonete();
    void realizarPedido(Pedido*ponteiro);
    void removerPedido(int);
    void setNomeLanchonete();
    std::string getNome();
    void setEndereco();
    void imprimeEndereco();
    double getLucro();
    void setNumero();
    int getNumero();
    ~Lanchonete();
};

#endif
