#ifndef ESTOQUE_H
#define ESTOQUE_H

class Estoque {
private:
    vector<ProdutoPorUnidade> produtosUnidade;
    vector<ProdutoPorPeso> produtosPeso;

public:
    Estoque(); //abre o arquivo EstoqueProdutoUnidade e EstoqueProdutoPeso
    ~Estoque(); // salva os dados no arquivo EstoqueProdutoUnidade e EstoqueProdutoPeso
    void adicionarProdutoPeso(ProdutoPorPeso);
    void adicionarProdutoUnidade(ProdutoPorUnidade);
    void removerProdutoUnidade();
    void removerProdutoPeso();
    ProdutoPorPeso getpeso(int);
    ProdutoPorUnidade getunidade(int);
    void imprimirEstoque(int = 0, bool = true);
    void recuperarDadosDoProduto(int, int, bool);
    int getSize(int);
};

#endif
