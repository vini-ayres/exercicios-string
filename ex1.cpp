#include <iostream>
#include <string>
#include <iomanip>
#include <locale.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "");
	
    string msg;
    
    cout << "Digite uma mensagem: ";
    cin >> msg;
    
    int tamanhoMensagem = msg.size();
    int espacosCentralizados = (80 - tamanhoMensagem) / 2;
    
    cout << setw(espacosCentralizados) << ' ';
    cout << msg << endl;
    
    for (int linha = 6; linha <= 20; linha++) {  	
        cout << setw(espacosCentralizados) << ' ';
        
        for (int i = 0; i < tamanhoMensagem; i++) {
            if (linha - 5 > i) {
                cout << ' ';
            } else {
                cout << msg[i];
            }
        }
        cout << endl;
    }
    
    return 0;
}