#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<string> dicionario;

class Palavra{
	public:
		string palavra;
		string palavra_escondida;
		Palavra(string palavra){
			this->palavra = palavra;
			for(int i=0; i<palavra.length(); i++){
				palavra_escondida.append("_");
			}
		}

		string get_palavra(){
			return palavra;
		}

		string get_palavraEscondida(){
			return palavra_escondida;
		}

};

void montar_dicionario(){
	ifstream arq("palavras.txt");
	if(arq.is_open()){
		string linha;
		while(getline(arq, linha)){
			dicionario.push_back(linha);
		}
	}
}

int main(){
	srand(unsigned((time(NULL))));
	montar_dicionario();
	Palavra palavra(dicionario[rand()%10000]);
	cout << palavra.get_palavra() << endl;
	cout << palavra.get_palavraEscondida() << endl;

	return 0;
}