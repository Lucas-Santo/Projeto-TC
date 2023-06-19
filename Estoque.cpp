#include "Estoque.h"

Estoque::Estoque() //abre o arquivo EstoqueProdutoUnidade e EstoqueProdutoPeso
{
    ifstream arquivoUnidade("EstoqueProdutoUnidade.txt");
    if (arquivoUnidade.is_open())
    {
        string quantidade, nome, codigo, preco;
        int cdg, qtd;
        float prc;
        while (getline(arquivoUnidade, quantidade))
        {
            getline(arquivoUnidade, nome);
            getline(arquivoUnidade, codigo);
            getline(arquivoUnidade, preco);
            prc = stof(preco);      //connverte string to float
            cdg = stoi(codigo);     //connverte string to int
            qtd = stoi(quantidade); //connverte string to float
            ProdutoPorUnidade produtoUnidade(qtd, nome, cdg, prc);
            produtosUnidade.push_back(produtoUnidade);
        }
        arquivoUnidade.close();
    }


    ifstream arquivoPeso("EstoqueProdutoPeso.txt");
    if (arquivoPeso.is_open())
    {
        string peso, nome, codigo, preco;
        int cdg;
        float prc, pso;
        while (getline(arquivoPeso, peso))
        {
            getline(arquivoPeso, nome);
            getline(arquivoPeso, codigo);
            getline(arquivoPeso, preco);
            pso = stof(peso);   //connverte string to float
            prc = stof(preco);  //connverte string to float
            cdg = stoi(codigo); //connverte string to int
            ProdutoPorPeso produtoPeso(pso, nome, cdg, prc);
            produtosPeso.push_back(produtoPeso);
        }
        arquivoPeso.close();
    }
}


Estoque::~Estoque() // salva os dados no arquivo EstoqueProdutoUnidade e EstoqueProdutoPeso
{
    ofstream arquivoUnidade("EstoqueProdutoUnidade.txt");
    if (arquivoUnidade.is_open())
    {
        for (int i = 0; i < produtosUnidade.size(); i++)
        {
            arquivoUnidade << produtosUnidade[i].getQuantidade() << endl;
            arquivoUnidade << produtosUnidade[i].getNome() << endl;
            arquivoUnidade << produtosUnidade[i].getCodigo() << endl;
            arquivoUnidade << produtosUnidade[i].getPreco() << endl;
        }
        arquivoUnidade.close();
    }

    ofstream arquivoPeso("EstoqueProdutoPeso.txt");
    if (arquivoPeso.is_open())
    {
        for (int i = 0; i < produtosPeso.size(); i++)
        {
            arquivoPeso << produtosPeso[i].getPeso() << endl;
            arquivoPeso << produtosPeso[i].getNome() << endl;
            arquivoPeso << produtosPeso[i].getCodigo() << endl;
            arquivoPeso << produtosPeso[i].getPreco() << endl;
        }
        arquivoPeso.close();
    }
}

void Estoque::adicionarProdutoPeso(ProdutoPorPeso ProdutoP) {
    this->produtosPeso.push_back(ProdutoP);
}

void Estoque::adicionarProdutoUnidade(ProdutoPorUnidade ProdutoP) {
    this->produtosUnidade.push_back(ProdutoP);
}

void Estoque::removerProdutoUnidade() {
    bool sair = false;
    int entrada;
    if (produtosUnidade.size() == 0) {
        cout << "Sem Produtos no estoque" << endl;
        system("pause");
    }
    else {
        try {
            do {
                cout << "Selecione um produto (1-" << produtosUnidade.size() << ")" << endl;
                cin >> entrada;

                if (cin.fail()) {
                    cout << "\aERROR - ENTRADA INVALIDA - ERROR" << endl;
                    cin.clear();
                    cin.ignore();
                }
                else if (entrada > 0 && entrada <= produtosUnidade.size()) {
                    sair = true;
                }
                else {
                    cout << "\aERROR - ENTRADA INVALIDA - ERROR" << endl;
                    system("pause");
                    system("cls");
                }
            } while (!sair);
            vector<ProdutoPorUnidade>::iterator it;
            it = produtosUnidade.begin() + entrada - 1;
            produtosUnidade.erase(it);
        }
        catch (const exception& ligador) {
            cout << "" << ligador.what() << endl;
        }
    }
}

void Estoque::removerProdutoPeso() {
    bool sair = false;
    int entrada;
    if (produtosPeso.size() == 0) {
        cout << "Sem Produtos no estoque" << endl;
        system("pause");
    }
    else {
        try {
            do {
                cout << "Selecione um produto (1-" << produtosPeso.size() << ")" << endl;
                cin >> entrada;

                if (cin.fail()) {
                    cout << "\aERROR - ENTRADA INVALIDA - ERROR" << endl;
                    cin.clear();
                    cin.ignore();
                }
                else if (entrada > 0 && entrada <= produtosPeso.size()) {
                    sair = true;
                }
                else {
                    cout << "\aERROR - ENTRADA INVALIDA - ERROR" << endl;
                    system("pause");
                    system("cls");
                }
            } while (!sair);
            vector<ProdutoPorPeso>::iterator it;
            it = produtosPeso.begin() + entrada - 1;
            produtosPeso.erase(it);
        }
        catch (const exception& ligador) {
            cout << "" << ligador.what() << endl;
        }
    }
}


void Estoque::imprimirEstoque(int estoque, bool all) {//*
    if (estoque == 1 || all) {
        cout << "Produtos por unidade: " << endl;
        for (int i = 0; i < produtosUnidade.size(); i++) {
            cout << "Codigo: "<<produtosUnidade[i].getCodigo() << " | Nome " << produtosUnidade[i].getNome() << " | Quantidade: " << produtosUnidade[i].getQuantidade() << endl;
        };
    };
    if (all) { cout << "------------------------" << endl; };
    if (estoque == 2 || all) {
        cout << "Produtos por peso: " << endl;
        for (int i = 0; i < produtosPeso.size(); i++) {
            cout << "Codigo: "<<produtosUnidade[i].getCodigo()<< " | Nome " << produtosPeso[i].getNome() << " | Quantidade: " << produtosPeso[i].getPeso() << endl;
        };
    };
}

void Estoque::recuperarDadosDoProduto(int estoque, int produto, bool all) {//*
    bool imprimirPorUnidade = (estoque == 1) || (all && estoque != 2);
    bool imprimirPorPeso = (estoque == 2) || all;

    if (imprimirPorUnidade && produtosUnidade.size() > 0) {
        cout << "Produtos por unidade: " << endl;
        for (int i = 0; i < produtosUnidade.size(); i++) {
            if (produto == i) {
                cout << produtosUnidade[i].getNome() << " | Quantidade: " << produtosUnidade[i].getQuantidade() << endl;
            };
        };
    }
    else if (imprimirPorPeso && produtosPeso.size() > 0) {
        cout << "Produtos por peso: " << endl;
        for (int i = 0; i < produtosPeso.size(); i++) {
            if (produto == i) {
                cout << produtosPeso[i].getNome() << " | Quantidade: " << produtosPeso[i].getPeso() << endl;
            };
        };
    };
}

int Estoque::getSize(int estoque) {
    if (estoque == 1) {
        return produtosUnidade.size();
    };
    if (estoque == 2) {
        return produtosPeso.size();
    };
}
ProdutoPorPeso Estoque::getpeso(int entrada) {//-
    ProdutoPorPeso produto = produtosPeso[0];
    for(int i = 0; i < produtosPeso.size(); i++){
        if(entrada == produtosPeso[i].getCodigo()){
            produto = produtosPeso[i];
        };
    };
    return produto;
}
ProdutoPorUnidade Estoque::getunidade(int entrada) {//-
    ProdutoPorUnidade produto = produtosUnidade[0];
    for(int i = 0; i < produtosUnidade.size(); i++){
        if(entrada == produtosUnidade[i].getCodigo()){
            produto = produtosUnidade[i];
        };
    };
    return produto;
}

void Estoque::setValorPeso(int codigo, float peso){//*
    for(int i = 0; i < produtosPeso.size(); i++){
        if(codigo == produtosPeso[i].getCodigo()){
            produtosPeso[i].setPeso(peso);
        };
    };
}

void Estoque::setValorUnidade(int codigo, int peso){//*
for(int i = 0; i < produtosUnidade.size(); i ++){
    if(codigo == produtosUnidade[i].getCodigo()){
        produtosUnidade[i].setQuantidade(peso);
    };
};
}
