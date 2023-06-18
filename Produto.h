#ifndef PRODUTO_H
#define PRODUTO_H
class Produto
{
protected:
    string nome;
    int codigo; //*
    float preco;

    //lembrar de verificar sua utilidade
    string regraManipulacao;
    string regraTransporte;
public:
    Produto(string = "", int = 0, float = 0.0);
    string getNome();
    int getCodigo(); //*
    float getPreco();

    //lembrar de verificar sua utilidade
    void setNome(string);
    void setCodigo(int);
    void setPreco(float);
    void setRegraManipulacao(string regra);
    void setRegraTransporte(string regra);
    string getRegraManipulacao();
    string getRegraTransporte();
    ~Produto();
};

#endif
