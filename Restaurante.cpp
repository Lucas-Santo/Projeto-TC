#include <iostream>
#include <locale>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <stdexcept>

using namespace std;

#include "Produto.cpp"
#include "ProdutoPorPeso.cpp"
#include "ProdutoPorUnidade.cpp"
#include "Estoque.cpp"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    string escolha;

    Estoque estoque;

    while (true) 
    {
        cout << "-------------MENU DA LANCHONETE-------------" << endl;
        cout << "            ||________________||            " << endl;
        cout << "           |    ____________    |           " << endl;
        cout << "          |     |LANCHONETE|     |          " << endl;
        cout << "         |                        |         " << endl;
        cout << "         |________________________|         " << endl;
        cout << "         |    __            __    |         " << endl;
        cout << "         |   |..|          |..|   |         " << endl;
        cout << "         |___|__|__________|__|___|         " << endl;
        cout << " DIGITE 1 - PARA ATENDER CLIENTE            " << endl;
        cout << " DIGITE 2 - PARA GERENCIAR ESTOQUE          " << endl;
        cout << " DIGITE 3 - PARA MOSTRAR DADOS DA LANCHONETE" << endl;
        cout << " CASO QUEIRA SAIR DIGITE (SAIR) PARA SAIR   " << endl;
        cout << endl;

        cin >> escolha;
        cout << endl;

        if (escolha == "1") 
        {
            string escolhaAtendimento;
            while (true) 
            {

                cout << "-------MENU DO ATENDIMENTO AO CLIENTE-------" << endl;
                cout << " DIGITE 1 - PARA ADICIONAR AO CARRINHO       " << endl;
                cout << " DIGITE 2 - PARA REMOVER DO CARRINHO         " << endl;
                cout << " DIGITE 3 - PARA FINALIZAR PEDIDO           " << endl;
                cout << " CASO QUEIRA VOLTAR DIGITE (VOLTAR)         " << endl;
                cout << endl;

                cin >> escolhaAtendimento;
                cout << endl;

                if (escolhaAtendimento == "1") 
                {
                    //DIGITE 1 - PARA ADICIONAR AO CARRINHO
                    cout << "o" << endl;
                }
                else if (escolhaAtendimento == "2") 
                {
                    //DIGITE 2 - PARA REMOVER DO CARRINHO
                    cout << "o" << endl;
                }
                else if (escolhaAtendimento == "3") 
                {
                    //DIGITE 3 - PARA FINALIZAR PEDIDO
                    cout << "o" << endl;
                }
                else if (escolhaAtendimento == "VOLTAR") 
                {
                    break;
                }
                else
                {
                    cout << "\aERROR - ESCOLHA INVALIDA - ERROR" << endl;
                }
            }
        }
        else if (escolha == "2") 
        {
            string escolhaEstoque;
            while (true) 
            {

                cout << "------MENU DO GERENCIAMENTO DE ESTOQUE------" << endl;
                cout << " DIGITE 1 - PARA IMPRIMIR TODO O ESTOQUE    " << endl;
                cout << " DIGITE 2 - PARA PROCURAR PRODUTOS          " << endl;
                cout << " DIGITE 3 - PARA ADCIONAR PRODUTOS          " << endl;
                cout << " DIGITE 4 - REMOVER PRODUTOS                " << endl;
                cout << " CASO QUEIRA VOLTAR DIGITE (VOLTAR)         " << endl;
                cout << endl;

                cin >> escolhaEstoque;
                cout << endl;


                if (escolhaEstoque == "1") 
                {
                    // DIGITE 1 - PARA IMPRIMIR TODO O ESTOQUE
                    estoque.imprimirEstoque(0, true);
                }
                else if (escolhaEstoque == "2") 
                {
                    // DIGITE 2 - PARA PROCURAR PRODUTOS
                    string escolhaTipoProduto;
                    cout << "Escolha o tipo de produto: " << endl;
                    cout << " 1 - Produto por unidade" << endl;
                    cout << " 2 - Produto por peso" << endl;
                    cin >> escolhaTipoProduto;

                    if (escolhaTipoProduto == "1") {
                        string indiceProdutoString;
                        cout << "Digite o índice do produto por unidade: ";
                        cin.ignore();
                        getline(cin, indiceProdutoString);
                        
                        try {
                            int indiceProduto = stoi(indiceProdutoString);
                            estoque.recuperarDadosDoProduto(1, indiceProduto - 1, true);
                        }
                        catch (invalid_argument& e) {
                            cout << "\aERROR - ENTRADA INVALIDA - ERROR" << endl;
                        }
                    }
                    else if (escolhaTipoProduto == "2") {
                        string indiceProdutoString;
                        cout << "Digite o índice do produto por peso: ";
                        cin.ignore();
                        getline(cin, indiceProdutoString);

                        try {
                            int indiceProduto = stoi(indiceProdutoString);
                            estoque.recuperarDadosDoProduto(2, indiceProduto - 1, true);
                        }
                        catch (invalid_argument& e) {
                            cout << "\aERROR - ENTRADA INVALIDA - ERROR" << endl;
                        }
                    }
                    else 
                    {
                        cout << "\aERROR - ESCOLHA INVALIDA - ERROR" << endl;
                    }
                }
                else if (escolhaEstoque == "3") 
                {
                    // DIGITE 3 - PARA ADICIONAR PRODUTOS
                    string escolhaTipoProduto;
                    cout << "Escolha o tipo de produto: " << endl;
                    cout << " 1 - Produto por unidade" << endl;
                    cout << " 2 - Produto por peso" << endl;
                    cin >> escolhaTipoProduto;

                    if (escolhaTipoProduto == "1") 
                    {
                        string nomeProduto;
                        string codigoProduto;
                        string precoProduto;
                        string quantidade;

                        cout << "Digite o nome do produto por unidade: ";
                        cin.ignore();
                        getline(cin, nomeProduto);

                        cout << "Digite o código do produto: ";
                        cin >> codigoProduto;

                        cout << "Digite o preço do produto: ";
                        cin >> precoProduto;

                        cout << "Digite a quantidade do produto: ";
                        cin >> quantidade;

                        estoque.adicionarProdutoUnidade(ProdutoPorUnidade(quantidade, nomeProduto, codigoProduto, precoProduto));
                        cout << "Produto por unidade adicionado com sucesso ao estoque." << endl;
                    }
                    else if (escolhaTipoProduto == "2") 
                    {
                        string nomeProduto;
                        string peso;
                        string codigo;
                        string preco;

                        cout << "Digite o nome do produto por peso: ";
                        cin.ignore();
                        getline(cin, nomeProduto);

                        cout << "Digite o peso do produto: ";
                        cin >> peso;

                        cout << "Digite o codigo do produto: ";
                        cin >> codigo;

                        cout << "Digite o preco do produto: ";
                        cin >> preco;

                        estoque.adicionarProdutoPeso(ProdutoPorPeso(peso, nomeProduto, codigo, preco));
                        cout << "Produto por peso adicionado com sucesso ao estoque." << endl;
                    }
                    else 
                    {
                        cout << "\aERROR - ESCOLHA INVALIDA - ERROR" << endl;
                    }
                }

                else if (escolhaEstoque == "4") 
                {
                    // DIGITE 4 - REMOVER PRODUTOS
                    string escolhaTipoProduto;
                    cout << "Escolha o tipo de produto: " << endl;
                    cout << " 1 - Produto por unidade" << endl;
                    cout << " 2 - Produto por peso" << endl;
                    cin >> escolhaTipoProduto;

                    if (escolhaTipoProduto == "1") 
                    {
                        estoque.removerProdutoUnidade();
                        cout << "Produto por unidade removido do estoque." << endl;
                    }
                    else if (escolhaTipoProduto == "2")
                    {
                        estoque.removerProdutoPeso();
                        cout << "Produto por peso removido do estoque." << endl;
                    }
                    else 
                    {
                        cout << "\aERROR - ESCOLHA INVALIDA - ERROR" << endl;
                    }
                }
                else if (escolhaEstoque == "VOLTAR") 
                {
                    break;
                }
                else 
                {
                    cout << "\aERROR - ESCOLHA INVALIDA - ERROR" << endl;
                }
                cout << endl;
            }
        }
        else if (escolha == "3") 
        {
            //DIGITE 3 - PARA MOSTRAR DADOS DA LANCHONETE
            cout << "o" << endl;
        }
        else if (escolha == "SAIR") 
        {
            break;
        }
        else
        {
            cout << "\aERROR - ESCOLHA INVALIDA - ERROR" << endl;
        }
    }
}

