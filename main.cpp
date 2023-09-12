#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<string> dicionario;

class Palavra{
	public:
		Palavra(){
			palavra = "";
			palavra_escondida = "";
		}

		Palavra(string palavra, string palavra_vertical){
			this->palavra = palavra;
			for(int i=0; i<palavra.length(); i++){
				palavra_escondida.append("_");
			}
			for(int i=0; i<palavra; i++){
				
			}
		}
		string get_palavra(){
			return palavra;
		}
		string get_palavraEscondida(){
			return palavra_escondida;
		}

	private:
		string palavra;
		string palavra_escondida;
		int get_espacos();
};


bool tem_a_letra(string palavra, string palavra_vertical, int pos){
	for(char i : palavra){
		if (i == palavra_vertical[pos]) return true;
	}
	return false;
}

void montar_dicionario(){
	ifstream arq("palavras.txt");
	if(arq.is_open()){
		string linha;
		while(getline(arq, linha)){
			dicionario.push_back(linha);
		}
	}
}

string espacos(int qtd){
	string out = "";
	for(int i=0; i<qtd; i++){
		out = out+" ";
	}
	return out;
}

void montar_palavras(string palavra_vertical, Palavra* *palavras){
	for(int i=0; i<10; i++){
		cout << palavras[i]->get_palavra() << endl;
	}
}

int main(){
	string palavra;
	srand(unsigned((time(NULL))));
	montar_dicionario();

	do{
		palavra = dicionario[rand()%dicionario.size()];
	}while(palavra.length() != 10);


	string palavra_vertical = palavra;

	Palavra* palavras[10];

	int i=0;
	do{
		palavra = dicionario[rand()%dicionario.size()];
		if(tem_a_letra(palavra, palavra_vertical, i)){
			palavras[i] = new Palavra(palavra, palavra_vertical);
			i++;
		}
	}while(i < 10);

	montar_palavras(palavra_vertical, palavras);

	return 0;
}