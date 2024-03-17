#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <locale.h>

using namespace std;

string transformarNome(const string& nomeCompleto) {
    istringstream iss(nomeCompleto);
    string sobrenome, nome, parte;
    
    vector<string> elementos;
    while (iss >> parte) {
        elementos.push_back(parte);
    }

    sobrenome = elementos.back();
    elementos.pop_back();
    nome = elementos[0];

    for (size_t i = 1; i < elementos.size(); ++i) {
        nome += " " + elementos[i];
    }

    return sobrenome + ", " + nome;
}

int main() {
	setlocale(LC_ALL, "");
	
    ifstream arquivo("nomes.txt");
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo.\n";
        return 1;
    }

    vector<string> nomes;

    string linha;
    while (getline(arquivo, linha)) {
        nomes.push_back(linha);
    }

    cout << "Nomes transformados:\n";
    for (size_t i = 0; i < nomes.size(); ++i) {
        cout << transformarNome(nomes[i]) << endl;
    }

    return 0;
}