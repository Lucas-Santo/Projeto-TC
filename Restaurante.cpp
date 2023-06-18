#include <iostream>
#include <locale>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <string>
#include <stdexcept>
#include <limits>

using namespace std;

#include "Produto.cpp"
#include "ProdutoPorPeso.cpp"
#include "ProdutoPorUnidade.cpp"
#include "Estoque.cpp"
#include "Pedido.cpp"
#include "Lanchonete.cpp"

void FazerPedido(Lanchonete*);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    string escolha;
    Lanchonete lanchonete;
    Estoque* estoque = lanchonete.getEstoque();

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
            system("cls");
            FazerPedido(&lanchonete);
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
                    estoque->imprimirEstoque(0, true);
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
                            estoque->recuperarDadosDoProduto(1, indiceProduto - 1, true);
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
                            estoque->recuperarDadosDoProduto(2, indiceProduto - 1, true);
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
                        int codigoProduto;
                        float precoProduto;
                        int quantidade;

                        cout << "Digite o nome do produto por unidade: ";
                        cin.ignore();
                        getline(cin, nomeProduto);

                        cout << "Digite o código do produto: ";
                        cin >> codigoProduto;

                        cout << "Digite o preço do produto: ";
                        cin >> precoProduto;

                        cout << "Digite a quantidade do produto: ";
                        cin >> quantidade;

                        estoque->adicionarProdutoUnidade(ProdutoPorUnidade(quantidade, nomeProduto, codigoProduto, precoProduto));
                        cout << "Produto por unidade adicionado com sucesso ao estoque." << endl;
                    }
                    else if (escolhaTipoProduto == "2")
                    {
                        string nomeProduto;
                        float peso;
                        float codigo;
                        float preco;

                        cout << "Digite o nome do produto por peso: ";
                        cin.ignore();
                        getline(cin, nomeProduto);

                        cout << "Digite o peso do produto: ";
                        cin >> peso;

                        cout << "Digite o codigo do produto: ";
                        cin >> codigo;

                        cout << "Digite o preco do produto: ";
                        cin >> preco;

                        estoque->adicionarProdutoPeso(ProdutoPorPeso(peso, nomeProduto, codigo, preco));
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
                        estoque->removerProdutoUnidade();
                        cout << "Produto por unidade removido do estoque." << endl;
                    }
                    else if (escolhaTipoProduto == "2")
                    {
                        estoque->removerProdutoPeso();
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

void FazerPedido(Lanchonete* lanchonete)
{
Pedido pedido;
Lanchonete* ptr_lanc = lanchonete;
Estoque* ptr_est = ptr_lanc->getEstoque();
ProdutoPorPeso produtoP;
ProdutoPorUnidade produtoU;
string nome;
bool endloop = false;
int n, codigo, unidade = 0, pos = 0;
float peso = 0;

do {
cout << "1) Adicionar Produto por Peso" << endl;
cout << "2) Adicionar Produto por Unidade" << endl;
cout << "3) Remover Produto por Peso" << endl;
cout << "4) Remover Produto por Unicade" << endl;
cout << "5) Adicionar/atualizar nome do cliente" << endl;
cout << "6) Mostrar Carrinho de compras" << endl;
cout << "7) Infomar valor total a pagar" << endl;
cout << "8) Mostrar estoque" << endl;
cout << "9) Cancelar Compra" << endl;
cout << "0) Finalizar pedido" << endl;

cin >> n;
system("cls");
if (!cin || n > 9 || n < 0) {
    cout << "Input inválido: " << endl;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system("pause");
    system("cls");
} else {
    switch (n) {
        case 1:
            ptr_est->imprimirEstoque(2, false);
            cout << "Informe o código do produto: ";
            cin >> codigo;
            produtoP = ptr_est->getpeso(codigo);
            if (codigo != produtoP.getCodigo()) { //não faz nada se nao existir o produto
                cout << "Produto não existe" << endl;
                system("pause");
                system("cls");
                break;
            };
            cout << "Informe o peso a ser comprado: ";
            cin >> peso;
            if (peso > produtoP.getPeso()) { //não faz nada se não tiver produto
                cout << "Produto insuficiente no estoque" << endl;
                system("pause");
                system("cls");
                break;
            };
            produtoP.setPeso(peso); //troca o valor do estoque para o que será comprado
            pedido.adicionarProdutopeso(produtoP);
            ptr_est->setValorPeso(codigo, produtoP.getPeso() - peso); // ja sabemos q o codigo existe aqui
            system("cls");
            break;
        case 2:
            ptr_est->imprimirEstoque(1, false);
            cout << "Informe o código do produto: ";
            cin >> codigo;
            produtoU = ptr_est->getunidade(codigo);
            if (codigo != produtoU.getCodigo()) { //não faz nada se nao existir o produto
                cout << "Produto não existe" << endl;
                system("pause");
                system("cls");
                break;
            };
            cout << "Informe a quantidade a ser comprado: ";
            cin >> unidade;
        if(unidade > produtoU.getQuantidade()){ //não faz nada se não tiver prpduto
            cout<<"Produto insuficiente no estoque"<<endl;
            system("pause");
            system("cls");
            break;
        };
        produtoU.setQuantidade(unidade);//troca o valor do estoque para o que será comprado
        pedido.adicionarProdutounidade(produtoU);
        ptr_est->setValorUnidade(codigo, produtoU.getQuantidade() - unidade); // ja sabemos q o codigo existe aqui
        system("cls");
        break;
    case 3://remover p-peso
        pedido.imprimirProdutos();
        cout<<"informe a posição do produto a ser removido(peso)"<<endl;
        cin>>pos;
        if(!cin || pos > pedido.getSize(1)|| pos<0) {
            cout << "Input inválido: "<< endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("pause");
            system("cls");
            break;
        };
        if(pedido.getSize(1)==-1){
            cout<<"Lista Peso vazia"<<endl;
            system("pause");
            system("cls");
            break;
        };
        produtoP = ptr_est->getpeso(pedido.getCodigoProdutoPeso(pos));
        ptr_est->setValorPeso(pedido.getCodigoProdutoPeso(pos), produtoP.getPeso() + pedido.getPesoPedido(pos));
        pedido.removerProdutopeso(pos);
        break;
    case 4://remover p-unidade
        pedido.imprimirProdutos();
        cout<<"informe a posição do produto a ser removido(unidade)"<<endl;
        if(!cin || pos > pedido.getSize(2)|| pos<0) {
            cout << "Input inválido: "<< endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("pause");
            system("cls");
            break;
        };
        if(pedido.getSize(2)==-1){
            cout<<"Lista Peso vazia"<<endl;
            system("pause");
            system("cls");
            break;
        };
        produtoU = ptr_est->getunidade(pedido.getCodigoProdutoUnidade(pos)); // pega o valor atual
        ptr_est->setValorUnidade(pedido.getCodigoProdutoUnidade(pos), produtoU.getQuantidade() + pedido.getUnidadePedido(pos));//adiciona o valor retirado
        pedido.removerProdutounidade(pos);
        break;
    case 5:
        cout<<"Informe o nome do cliente: ";
        getline(cin, nome);
        pedido.setNome(nome);
        system("pause");
        system("cls");
        break;
    case 6:
        pedido.imprimirProdutos();
        system("pause");
        system("cls");
        break;
    case 7:
        cout<<"Valor a pagar: "<<pedido.getValorTotal()<<endl;
        system("pause");
        system("cls");
        break;
    case 8:
        ptr_est->imprimirEstoque(1, true);
        system("pause");
        system("cls");
        break;
    case 9:
        while(pedido.getSize(1)!=-1){
            produtoP = ptr_est->getpeso(pedido.getCodigoProdutoPeso(0));
            ptr_est->setValorPeso(pedido.getCodigoProdutoPeso(0), produtoP.getPeso() + pedido.getPesoPedido(0));
            pedido.removerProdutopeso(0);
        };
        while(pedido.getSize(2)!=-1){
            produtoP = ptr_est->getpeso(pedido.getCodigoProdutoPeso(0));
            ptr_est->setValorPeso(pedido.getCodigoProdutoPeso(0), produtoP.getPeso() + pedido.getPesoPedido(0));
            pedido.removerProdutopeso(0);
        };
        endloop = true;
        return;
    case 0:
        pedido.setCodigo(ptr_lanc->getHistSize());
        endloop = true;
    default:
        system("cls");
        break;

    };
};

}while(!endloop);

ptr_lanc->realizarPedido(pedido);
};
