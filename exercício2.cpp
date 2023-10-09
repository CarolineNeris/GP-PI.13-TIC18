#include <iostream>
#include <string>
using namespace std;

struct Empregado {
    string nome;
    string sobrenome;
    int nascimento_ano;
    string rg;
    int admissao_ano;
    double salario;
};

void reajustadez(Empregado empregados[]) {
    for (int i = 0; i < 50; i++) {
        empregados[i].salario *= 1.1;
}
}
int main() {
    
    Empregado empregados[50];

    empregados[0] = {"Pedrinho", "Alves", 1995, "12345678", 2020, 5000.0};
    empregados[1] = {"Joana", "Fonseca", 1989, "0000000", 2015, 7500.0};

    
    for (int i = 0; i < 2; i++) {
        cout << "Nome: " << empregados[i].nome
             << " Salario antes do ajuste: R$ " << empregados[i].salario;

        
        reajustadez(empregados); // essa maneira de tratar, pode tornar o código menos eficiente, mas nesse momento ficou interssante a visualização

        cout << " Salario ajustado: R$ " << empregados[i].salario << endl;
    }

    return 0;
}
