#include <iostream>
#include <fstream>
#include <vector>
#include "funcionario.hpp"

#ifdef __WIN32
	#define CLEAR  "cls"
#else
	#define CLEAR  "clear"

#endif

using namespace std;

void loja();
void login_funcionario(vector<Funcionario*>& funcionarios_cadastrados);

int main(){
	vector <Funcionario*> funcionarios;
	login_funcionario(funcionarios);
	loja();
}

// criando o login do funcionario para poder utilizar a plataforma
void login_funcionario(vector<Funcionario*>& funcionarios_cadastrados){
	string nome,cpf,email,funcao, senha;
	int idade, escolha;
	char continuar;
	bool menu_funcionario = true,usuario_correto = false;
	Funcionario *funcionario_da_padaria;
	while(menu_funcionario){
		system(CLEAR);
		cout << "1 - Entrar no sistema" << endl;
		cout << "2 - Registrar um funcionario" << endl;
		cout << "->> ";
		cin >> escolha;

		if(escolha >= 1 && escolha <= 2){
			switch(escolha){
				case 1:
					cout << "Digite o funcionário que irá utilizar a plataforma: ";
					cin >> nome;

					cout << "Digite a respectiva senha de usuário: ";
					cin >> senha;

					if(!funcionarios_cadastrados.empty()){
						for(Funcionario *buscador : funcionarios_cadastrados){
							if(nome == buscador->get_nome() && senha == buscador->get_senha()){
								usuario_correto = true;
							}
						}
					}
					if(usuario_correto == true)
						menu_funcionario = false;
					break;

				case 2:
					cout<< "Digite o nome do funcionário: ";
					cin >> nome;

					cout<< "Digite a idade do funcionário: ";
					cin >> idade;

					cout << "Digite o CPF do funcionário: ";
					cin >> cpf;

					cout << "Digite o Email do funcionário: ";
					cin >> email;

					cout << "Digite a função do funcionário: ";
					cin >> funcao;

					cout << "Digite a senha do funcionário(4-16 caracteres sem espaços): ";
					cin >> senha;

					cout << "Funcionario registrado com sucesso!!" << endl;
					cout << "\nDigite qualquer tecla para continuar..." << endl;
					cin >> continuar;

					funcionario_da_padaria = new Funcionario(nome,idade,cpf,email,funcao,senha);
					funcionarios_cadastrados.push_back(funcionario_da_padaria);
					delete funcionario_da_padaria;
					break;
			}
		}
	}
}

void loja(){
	bool continua = true;
	int escolha;
	char pause;

	while(continua){
		system(CLEAR);
		cout << "     Bem vindos à minha loja" << endl;
		cout << "Digite o modo que deseja utilizar:" << endl;
		cout << "1 - Modo venda" << endl;
		cout << "2 - Modo estoque" << endl;
		cout << "3 - Modo recomendação" << endl;
		cout << "0 - Sair da loja" << endl;
		cout << "->> ";
		cin >> escolha;

		if (escolha >=0 && escolha <=3){
			switch(escolha){
				case 1:
					system(CLEAR);
					cout << "Modo venda" << endl;
					cout << "Digite qualquer tecla para poder continuar:" << endl;
					cin >> pause;
					break;

				case 2:
					system(CLEAR);
					cout << "Modo estoque" << endl;
					//modo_estoque();
					cout << "Digite qualquer tecla para poder continuar:" << endl;
					cin >> pause;
					break;
				
				case 3:
					system(CLEAR);
					cout << "Modo recomendação" << endl;
					cout << "Digite qualquer tecla para poder continuar:" << endl;
					cin >> pause;
					break;
			
				case 0:
					system(CLEAR);
					cout << "Obrigado por utilizar o programa." << endl;
					continua = false;
					break;
			}
		}
	}
}