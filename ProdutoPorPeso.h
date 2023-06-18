#ifndef PRODUTOPORPESO_H
#define PRODUTOPORPESO_H

class ProdutoPorPeso : public Produto
{
private:
    float peso;

public:
    ProdutoPorPeso(float = 0.0, string = "", int = 0, float = 0.0);
    float getPeso();

    //lembrar de verificar sua utilidade
    void setPeso(float peso);
    ~ProdutoPorPeso();
};

#endif
