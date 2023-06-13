#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <filesystem>
#include <experimental/filesystem> // Header file for pre-standard implementation
using std::filesystem;
using namespace std::experimental::filesystem::v1;

using namespace std;
using std::string;
using std::map;

int main () {
    //map<string, list<string>> indice; //jogar em outro arquivo depois
    std::string diretorio = "C:/Users/natalia.barreto/Documents/TP-PDS2/documentos";
    for (const filesystem::directory_entry& arquivo : filesystem::directory_iterator(diretorio)) {
        if (arquivo.is_regular_file()) {
            ifstream ifs(arquivo.path()); //cria um objeto de leitura
            if (ifs) {
                string linha;
                while(getline(ifs, linha)) {
                    istringstream iss(linha); 
                    string token;
                    while (iss >> token) {
                        cout << token << endl;
                    }
                }
                ifs.close();
            }
        }
        else {
            cout << "Erro ao abrir o arquivo: " << arquivo.path() << endl;
        }
    }
    return 0;
}