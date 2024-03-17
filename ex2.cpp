#include <iostream>
#include <string>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    
    string msg, msgSemEspacos, novaMsg;
    
    cout << "Digite uma mensagem: ";
    getline(cin, msg);
    
    for (int i = 0; i < msg.size(); ++i) {
        char c = msg[i];
        if (c != ' ') {
            msgSemEspacos += c;
        }
    }

    for (int i = msgSemEspacos.size() - 1; i >= 0; --i) {
        novaMsg += msgSemEspacos[i];
    }
    
    if (novaMsg.compare(msgSemEspacos) == 0) {
		cout << "É palíndromo";
	} else {
		cout << "Não é palíndromo";
	}
    
    return 0;
}