//Gabriel de Quadros

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct agenda{
	char nome[20];
	int telefone;
	struct agenda *prox;
};

typedef struct agenda lista;

void inserir(lista *p);
void procurar(lista *p);
void mostrar(lista *p);
void apagar(lista *p);

int main(){
	lista *head;
	head=(lista*)malloc(sizeof(lista));
	head->prox = NULL;

	int opcao;

	do{
		printf("-------AGENDA---------\n\n");
        	printf("1. Inserir\n");
        	printf("2. Apagar \n");
        	printf("3. Mostrar \n");
        	printf("4. Procurar\n");
        	printf("0 Sair\n");
        	scanf("%d", &opcao);
        
        	switch(opcao)
        	{
            	case 1:
            		inserir(head);
                	break;
            	case 2:
          		apagar(head);
			break;
           	 case 3:
              		mostrar(head);
                	break;
           	 case 4:
			procurar(head);
			break;
        	}

    	}while(op != 0);

    return 0;
}

void mostrar(lista *p){
lista *aux;
	for(aux=p->prox; aux != NULL ; aux=aux->prox){
		printf("Nome: %s\n", aux->nome);
		printf("Telefone: %d\n", aux->telefone);
	}
}

void procurar (lista *p)
{
	lista *aux;
	char nome[20];
	
	printf("\n Digite o nome:");
	scanf("%s", nome);
	
	for(aux=p->prox; aux!=NULL;aux=aux->prox){
		if(strcmp(nome, aux->nome)==0){
			printf("\n Nome: %s", aux->nome);
			printf("\n Telefone: %d\n", aux->telefone);
			
		}
		
	}
}


void apagar(lista *p){
	lista *apagar, *anterior;
	char nome[20];
	
	printf("Informe o nome que deseja excluir: ");
	scanf("%s", nome);

	for(apagar=p->prox,anterior=p; apagar != NULL; apagar=apagar->prox, anterior=anterior->prox ){
		if(strcmp(nome, apagar->nome)==0){
			anterior->prox = apagar->prox;
			free(apagar);
		}
	}
}


void inserir(lista *p){
	lista *busca, *nova;
	char lixo;

	for(busca = p; busca->prox != NULL ; busca= busca->prox);
		nova = (lista *)malloc(sizeof(lista));
		busca->prox = nova;
		nova->prox = NULL;
		printf("Informe o nome: \n");
		scanf("%s", nova->nome);
		scanf("%c", &lixo);
		printf("Informe o telefone: \n");
		scanf("%d", &nova->telefone);
		scanf("%c", &lixo);
}

