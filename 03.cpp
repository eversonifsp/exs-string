#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string formatarNome(const string &nome)
{
    stringstream ss(nome);
    string parte;
    vector<string> partes;

    while (getline(ss, parte, ' '))
    {
        partes.push_back(parte);
    }

    string sobrenome = partes.back();
    partes.pop_back();
    string primeirosNomes = partes.empty() ? "" : partes[0];
    for (size_t i = 1; i < partes.size(); ++i)
    {
        primeirosNomes += " " + partes[i];
    }

    return sobrenome + ", " + primeirosNomes;
}

int main()
{
    fstream arquivoLeitura;
    fstream arquivoEscrita;

    arquivoLeitura.open("./nomes.txt", ios::in);
    arquivoEscrita.open("./nomes_formatados_03.txt", ios::out);

    if (arquivoLeitura.is_open())
    {
        string linha;
        while (getline(arquivoLeitura, linha))
        {
            if (arquivoEscrita.is_open())
            {
                arquivoEscrita << formatarNome(linha) << endl;
            }
            else
            {
                cerr << "Erro ao abrir o arquivo para escrita." << endl;
                return 1;
            }
        }
        arquivoLeitura.close();
        arquivoEscrita.close();
    }
    else
    {
        cerr << "Erro ao abrir o arquivo para leitura." << endl;
        return 1;
    }

    return 0;
}
