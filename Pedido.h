#ifndef PEDIDO_H
#define PEDIDO_H

class Pedido{
private:
    std::string nomeCliente;
    int codigoPedido;
    std::vector<ProdutoPorUnidade> produtosUnidades;
    std::vector<ProdutoPorPeso> produtosPesos;
    float valorTotal;

public:
    void adicionarProdutounidade(int, Estoque);
    void adicionarProdutopeso(int, Estoque);
    void removerProdutounidade(int);
    void removerProdutopeso(int);
    void setNome(std::string nome);
    void setCodigo(int codigo);
    std::string getNome();
    int getCodigo();
    float getValorTotal();
};

#endif
