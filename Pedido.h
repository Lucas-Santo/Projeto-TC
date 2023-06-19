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
    void adicionarProdutounidade(ProdutoPorUnidade);
    void adicionarProdutopeso(ProdutoPorPeso);
    void removerProdutounidade(int);
    void removerProdutopeso(int);
    void imprimirProdutos();
    void setNome(std::string nome);
    void setCodigo(int codigo);
    std::string getNome();
    int getCodigo();
    float getValorTotal();
    int getSize(int);//*
    int getCodigoProdutoPeso(int);
    int getCodigoProdutoUnidade(int);
    int getUnidadePedido(int);
    float getPesoPedido(int);
};

#endif
