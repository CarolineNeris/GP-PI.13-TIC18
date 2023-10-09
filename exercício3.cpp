#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

struct Produto{
   string nome;
   string codigo;
   double preco;
};
//1.Função de inserir produtos
void inserirProduto(vector<Produto>& produtos){
    if (produtos.size()>301)
    {
        cout<<"Máximo de 300 produtos cadastrados atingido" << endl;
    }
    
        Produto new_product;
        cout << "Insira o código do produto: "<<endl;
        cin >> new_product.codigo;
        for (Produto& product : produtos){
            if(product.codigo == new_product.codigo){
            cout << "O código fornecido já está cadastrado em nosso sistema. Caso deseje alterar, retone ao menu principal"<<endl;
                return;
            }
        }
        cout << "Insira o nome do produto: "<< endl;
        cin.ignore();
        cin >>new_product.nome;
        cout << "Insira o preço do produto: "<< endl;
        cin >>new_product.preco;
        produtos.push_back(new_product);
        cout << "Cadastro realizado com sucesso "<< endl;
}          
    
//2. Excluir produto cadastado

    
void excluirProduto(vector<Produto>& produtos) {
    string codigo;  // Declare a variável local para armazenar o código a ser excluído

    cout << "Digite o código do produto a ser excluído: ";
    cin >> codigo;

    for (size_t i = 0; i < produtos.size(); i++) {
        if (produtos[i].codigo == codigo) {
            produtos.erase(produtos.begin() + i);
            cout << "Produto excluído com sucesso." << endl;
            return;
        }
    }

    cout << "O produto não existe em nossa base de dados." << endl;
}


// Função para listar todos os produtos

void listarProdutos(const vector<Produto>& produtos) {
    cout << "Lista de produtos:" << endl;
    for (const Produto& p : produtos) {
        cout << "Código: " << p.codigo << ", Nome: " << p.nome << ", Preço: R$" << fixed << setprecision(2) << p.preco << endl;
    }
}

// Função para consultar preco
void consultarPreco(const vector<Produto>& produtos) {
    string codigo;
    cout << "Digite o código do produto para consulta: ";
    cin >> codigo;

    for (const Produto& p : produtos) {
        if (p.codigo == codigo) {
            cout << "O preço do produto " << p.nome << " é R$" << fixed << setprecision(2) << p.preco << endl;
            return;
        }
    }
    cout << "Produto não encontrado." << endl;
}    

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