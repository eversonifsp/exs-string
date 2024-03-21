#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool ehPalindromo(const string &mensagem)
{
    string mensagemSemEspacos;
    for (char c : mensagem)
    {
        if (!isspace(c))
        {
            mensagemSemEspacos += tolower(c);
        }
    }

    string mensagemInvertida = mensagemSemEspacos;
    reverse(mensagemInvertida.begin(), mensagemInvertida.end());

    return mensagemSemEspacos == mensagemInvertida;
}

int main()
{
    string mensagem;

    cout << "Digite uma mensagem: ";
    getline(cin, mensagem);

    if (ehPalindromo(mensagem))
    {
        cout << "A mensagem \"" << mensagem << "\" eh um palindromo." << endl;
    }
    else
    {
        cout << "A mensagem \"" << mensagem << "\" nao eh um palindromo." << endl;
    }

    return 0;
}
