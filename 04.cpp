#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string formatarCitacao(const string &nome)
{
    stringstream ss(nome);
    string parte;
    vector<string> partes;

    while (getline(ss, parte, ' '))
    {
        partes.push_back(parte);
    }

    string sobrenome = partes.back();
    transform(sobrenome.begin(), sobrenome.end(), sobrenome.begin(), ::toupper);

    partes.pop_back();

    string nomeFormatado = sobrenome + ", " + partes[0] + " ";

    for (size_t i = 1; i < partes.size(); ++i)
    {
        nomeFormatado += partes[i][0];
        nomeFormatado += ".";
        nomeFormatado += " ";
    }

    return nomeFormatado;
}

int main()
{
    fstream arquivoLeitura;
    fstream arquivoEscrita;

    string nomeArquivoEntrada = "./nomes.txt";
    string nomeArquivoSaida = "./nomes_formatados_04.txt";

    arquivoLeitura.open(nomeArquivoEntrada, ios::in);
    arquivoEscrita.open(nomeArquivoSaida, ios::out);

    if (arquivoLeitura.is_open())
    {
        string linha;
        while (getline(arquivoLeitura, linha))
        {
            if (arquivoEscrita.is_open())
            {
                arquivoEscrita << formatarCitacao(linha) << endl;
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

    cout << "Nomes formatados foram salvos em " << nomeArquivoSaida << endl;

    return 0;
}
