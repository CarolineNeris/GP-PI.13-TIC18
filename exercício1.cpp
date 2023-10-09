#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Passagem {
    string passageiroNome;
    string passageiroCpf;
    int passageiroIdade;

    int assento;
    string tipoViagem;

    int dataDia;
    int dataMes;
    int hora;
    double preco;
};

double calcularTotalArrecadadoViagem(const vector<Passagem>& viagens, const string& tipoViagem) {
    double totalArrecadado = 0;
    for (const Passagem& passagem : viagens) {
        if (passagem.tipoViagem == tipoViagem) {
            totalArrecadado += passagem.preco;
        }
    }
    return totalArrecadado;
}

double calcularTotalArrecadadoMes(const vector<Passagem>& viagens, int mes) {
    double totalArrecadado = 0;
    for (const Passagem& passagem : viagens) {
        if (passagem.dataMes == mes) {
            totalArrecadado += passagem.preco;
        }
    }
    return totalArrecadado;
}

string obterNomePassageiroPorPoltrona(const vector<Passagem>& viagens, int poltrona, const string& tipoViagem) {
    for (const Passagem& passagem : viagens) {
        if (passagem.assento == poltrona && passagem.tipoViagem == tipoViagem) {
            return passagem.passageiroNome;
        }
    }
    return "Poltrona vazia";
}

int encontrarHorarioMaisRentavel(const vector<Passagem>& viagens) {
    vector<double> arrecadacaoPorHorario(5, 0.0);

    for (const Passagem& passagem : viagens) {
        arrecadacaoPorHorario[passagem.hora / 3] += passagem.preco;
    }

    double maxArrecadacao = 0;
    int horarioMaisRentavel = -1;

    for (int i = 0; i < 5; i++) {
        if (arrecadacaoPorHorario[i] > maxArrecadacao) {
            maxArrecadacao = arrecadacaoPorHorario[i];
            horarioMaisRentavel = i;
        }
    }

    return horarioMaisRentavel * 3; // Retorna a hora correspondente
}

double calcularMediaIdadePassageiros(const vector<Passagem>& viagens) {
    int totalIdade = 0;
    int totalPassageiros = 0;

    for (const Passagem& passagem : viagens) {
        totalIdade += passagem.passageiroIdade;
        totalPassageiros++;
    }

    if (totalPassageiros > 0) {
        return static_cast<double>(totalIdade) / totalPassageiros;
    } else {
        return 0.0; // Evitar divisão por zero
    }
}

int main() {
    vector<Passagem> viagens;
    Passagem novaPassagem;

    bool continuar = true;
    string tempString;

    while (continuar) {
        cout << "Informe o tipo de viagem (ida/volta): ";
        cin >> novaPassagem.tipoViagem;

        cout << "Informe o mês da viagem (1-12): ";
        cin >> novaPassagem.dataMes;

        cout << "Informe o dia da viagem (1-30): ";
        cin >> novaPassagem.dataDia;

        cout << "Informe a hora da viagem (08,10,13,15,20): ";
        cin >> novaPassagem.hora;

        cout << "Informe o nome do passageiro: ";
        cin.ignore();
        getline(cin, novaPassagem.passageiroNome);

        cout << "Informe o CPF do passageiro: ";
        getline(cin, novaPassagem.passageiroCpf);

        cout << "Informe a idade do passageiro: ";
        cin >> novaPassagem.passageiroIdade;

        novaPassagem.preco = 80.0; // Cada passagem custa 80 reais

        viagens.push_back(novaPassagem);

        cout << "Deseja vender mais uma passagem (s/n)? ";
        cin.ignore();
        getline(cin, tempString);
        continuar = (tempString == "s" || tempString == "S");

        cout << endl;
    }

    // Cálculos e informações
    cout << fixed << setprecision(2); // Configura a saída para duas casas decimais

    // 1. Total arrecadado para uma determinada viagem (ida)
   
    double totalArrecadadoIda = calcularTotalArrecadadoViagem(viagens, "ida");
    double totalArrecadadoVolta = calcularTotalArrecadadoViagem(viagens, "volta");

    cout << "1. Total arrecadado para viagem de ida: R$" << totalArrecadadoIda << endl;
    cout << "2. Total arrecadado para viagem de volta: R$" << totalArrecadadoVolta << endl;

    // Solicitar número da poltrona para obter o nome do passageiro
    int poltronaDesejada;
    cout << "Informe o número da poltrona: ";
    cin >> poltronaDesejada;

    string nomePassageiroPoltronaIda = obterNomePassageiroPorPoltrona(viagens, poltronaDesejada, "ida");
    string nomePassageiroPoltronaVolta = obterNomePassageiroPorPoltrona(viagens, poltronaDesejada, "volta");

    cout << "3. Nome do passageiro na poltrona " << poltronaDesejada << " na viagem de ida: " << nomePassageiroPoltronaIda << endl;
    cout << "   Nome do passageiro na poltrona " << poltronaDesejada << " na viagem de volta: " << nomePassageiroPoltronaVolta << endl;

    // 4. Horário de viagem mais rentável
    int horarioMaisRentavel = encontrarHorarioMaisRentavel(viagens);
    cout << "4. Horário de viagem mais rentável: " << horarioMaisRentavel << ":00" << endl;

    // 5. Média de idade dos passageiros
    double mediaIdadePassageiros = calcularMediaIdadePassageiros(viagens);
    cout << "5. Média de idade dos passageiros: " << mediaIdadePassageiros << " anos" << endl;

    return 0;
}
