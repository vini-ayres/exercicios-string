#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iterator>
#include <locale.h>

using namespace std;

string transformarNome(const string& nomeCompleto) {
    istringstream iss(nomeCompleto);
    string sobrenome, nome, parte, sobrenomeU;
    
    vector<string> elementos;
    while (iss >> parte) {
        elementos.push_back(parte);
    }
    
    sobrenome = elementos.back();
    
    for (int i = 0; i < sobrenome.size(); ++i) {
		char c = sobrenome[i];
		sobrenomeU += toupper(c);
	}
    
    elementos.pop_back();
    
    for (vector<string>::iterator it = elementos.begin(); it != elementos.end(); ++it) {
        const string& elemento = *it;
        if (elemento != elementos.front() && elemento != sobrenome) {
            if (elemento.size() > 1) {
                nome += elemento.substr(0, 1) + ". ";
            } else {
                nome += elemento + " ";
            }
        } else {
            nome += elemento + " ";
        }
    }

    return sobrenomeU + ", " + nome;
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
    for (vector<string>::const_iterator it = nomes.begin(); it != nomes.end(); ++it) {
        cout << transformarNome(*it) << endl;
    }

    return 0;
}
