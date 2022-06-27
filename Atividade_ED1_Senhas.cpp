#include <iostream>
using namespace std;

struct No {
	float dado;
	No *prox;
};

struct Fila {
	No *ini;
	No *fim; 
};

Fila* init() {
	Fila *f = new Fila;
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

int isEmpty(Fila *f) {
	return (f->ini == NULL);
}

int count(Fila *f) {
	int qtde = 0;
	No *no;
	no = f->ini;
	while (no != NULL) {
		qtde++;
		no = no->prox;
	}
	return qtde;
	
	cout << qtde;
}

void print(Fila *f) {
	No *no;
	no = f->ini;
	cout << "-------------" << endl;
	while (no != NULL) {
		cout << no->dado << endl;
		no = no->prox;
	}
	cout << "-------------" << endl;
}

void addSenha(Fila *f, int i) {
	No *no = new No;
	no->dado = i;
	no->prox = NULL;
	
	if (isEmpty(f)) {
		f->ini = no;
	}

	else {
		f->fim->prox = no;
	}
	f->fim = no;
}

int Atende(Fila *f) {
	int ret;
	if (isEmpty(f)) {
		ret = -1;
	}
	else {
		No *no = f->ini;
		ret = no->dado;
		f->ini = no->prox;
		if (f->ini == NULL) {
			f->fim = NULL;
		}
		free(no);
	}
	return ret;
}

void freeFila(Fila *f) {
	No *no = f->ini;
	while (no != NULL) {
		No *temp = no->prox;
		free(no);
		no = temp;
	}
	free(f);
}

int main(int argc, char** argv)
	{
	int opcao =-1;
	int geradas=0;
	int atendidas=0;
			
	Fila *filaSenhaGerada;
	Fila *filaSenhaAtendida;
	
	filaSenhaGerada = init();
	filaSenhaAtendida = init();

	
	while(opcao != 0){

		cout <<	"0. Sair"<<endl;
		cout <<	"1. Gerar Senha" <<endl;
		cout <<	"2. Realizar atendimento"<<endl;
		cout <<	"DIGITE A OPCAO DESEJADA"<<endl;
		cin >> opcao;

		if (opcao==1) {
				
   		geradas++;
		addSenha(filaSenhaGerada, geradas);
	
					}
					
    	if (opcao==2) {
				
		
			atendidas++;
		   	addSenha(filaSenhaAtendida, atendidas);
			Atende(filaSenhaGerada);
			cout << "Fila vazia: " << (isEmpty(filaSenhaGerada)?"SIM":"NAO") << endl;
			
			//Testa se após o atendimento a fila está vazia e em caso positivo, mostra as senhas atendidas
			if(isEmpty(filaSenhaGerada)==true){
			cout << "SENHAS ATENDIDAS HOJE" << endl;
			print(filaSenhaAtendida); 
			return 0;  
	
											  }			
					}
         				
       	 cout << "SENHAS AGUARDANDO" << endl;
		 print(filaSenhaGerada);
		   	   	   	}
		 cout << "SENHAS ATENDIDAS HOJE" << endl;
   	   	 print(filaSenhaAtendida);   	   
			   	   	freeFila(filaSenhaAtendida);
			   	   	freeFila(filaSenhaGerada);
			   	   						  		
					return 0;
}


