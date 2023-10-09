#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "funcoes.h"
using namespace std;

int main() {
    vector<Produto> produtos;
        while (true){
            cout << "Escolha a opção desejada:"<< endl;
            cout << "1. Inserir novo produto" << endl;
            cout << "2. Excluir produto" << endl;
            cout << "3. Listar todos os produtos" << endl;
            cout << "4. Consultar o preço de um produto por código" << endl;
            cout << "0. Sair" << endl;
            int opcao;
            cin >> opcao;
        switch (opcao)
        {
            case  1:
                inserirProduto(produtos);
            break;
            case  2:
                excluirProduto(produtos);
            break;
            case 3:
                listarProdutos(produtos);
                break;
            case 4: {
                consultarPreco(produtos);
                break;
                return 0;
            case 0:
                cout << "Saindo do programa" << endl;
        default:
            cout << "Escolha uma opção válida"<< endl;
        }
    }
    return 0;
}
}