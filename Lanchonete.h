#ifndef LANCHONETE_H
#define LANCHONETE_H

class Lanchonete {
private:
    struct Endereco{
        std::string cidade;
        std::string bairro;
        std::string rua;
        int numero;
    };
    std::string nomeLoja;
    Endereco endereco;
    int telefone;
    Estoque estoque;
    double lucros;
    std::vector<Pedido> historicoPedidos;

public:
    Lanchonete();
    void realizarPedido(Pedido);
    void removerPedido(int);
    void setNomeLanchonete(string);
    std::string getNome();
    void setEndereco(string, string, string, int);
    void imprimeEndereco();
    double getLucro();
    void setTelefone(int);
    int getTelefone();
    int getHistSize();
    Estoque* getEstoque();
    ~Lanchonete();
};

#endif
