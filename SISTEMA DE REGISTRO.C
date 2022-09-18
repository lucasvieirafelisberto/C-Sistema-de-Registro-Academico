#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tam 5 

typedef struct{
	int  ra;
	char arquivo[30];
	char extensao[30];
	int  matricula;
	
}dados;

typedef struct{
	dados tamanho[tam];
	int ini;
}dados2;

void n(dados2 *p){	
    p->ini=0;
}

void inserir(dados2 *p){
	if(p->ini==tam){
	   printf("Fila Cheia\n: ");
	   system("pause");
	}
	else{
		
		printf("Insira RA do Aluno: ");
		scanf("%d",&p->tamanho[p->ini].ra);
	    fflush(stdin);
	  		
		printf("Insira Nome do Arquivo: ");
		scanf("%[^\n]s",&p->tamanho[p->ini].arquivo);
	    fflush(stdin);
		
		printf("Insira Extensão do Arquivo : ");
		scanf("%[^\n]s",&p->tamanho[p->ini].extensao);
	    fflush(stdin);
	    
		printf("Insira Matricula do Professor: ");
		scanf("%d",&p->tamanho[p->ini].matricula);
		fflush(stdin);
	    
	    p->ini++;
	    	
	}
}		
	

void retirar(dados2 *p){	
    if(p->ini>0){
		int i;
	    printf("Atenção,Dados a ser deletado!\n");
		printf("RA -> %d\n",p->tamanho[i].ra);
		printf("Arquivo -> %s\n",p->tamanho[i].arquivo);
		printf("Extensão -> %s\n",p->tamanho[i].extensao);
		printf("Matricula -> %d\n",p->tamanho[i].matricula);
		printf("***************");
		printf("\n");
		system("pause");
		
		for (i=0; i<p->ini-1; i++){
		    p->tamanho[i] = p->tamanho[i+1];
		}
		
		p->ini--;
	}
	else{
		printf("Fila Vazia!\n ");
		system("pause");
	}
}

void deletar (dados2 *p){
	if(p->ini>0){
		
	    p->ini=0;	
    } 
	else{
    	printf("Fila Vazia!\n");
    	system("pause");
	}
}

void mostrar (dados2 *p){
	int i;
	for (i=0; i<tam; i++){
		printf("***************\n");
		printf("RA -> %d\n",p->tamanho[i].ra);
		printf("Arquivo -> %s\n",p->tamanho[i].arquivo);
		printf("Extensão -> %s\n",p->tamanho[i].extensao);
		printf("Matricula -> %d\n",p->tamanho[i].matricula);
		printf("***************");
		printf("\n");
		
	}
	
}

void menu(){
	
		printf ("\n        # SISTEMA ACADEMICO #         \n");
		printf ("  ______________________________________");
        printf("\n | 1  -Inserir Dados                    |\n");   
        printf(" | 2 - Limpar  Fila                     |\n");
        printf(" | 3 - Deletar Fila                     |\n");
        printf(" | 0 - Finalizar                        |\n");
        printf(" |______________________________________|\n");
        printf(" |      SELECIONE OPCAO DESEJADA        |\n");
        printf(" |______________________________________|\n");
        printf(" OPCAO:");
        printf("\n");
			
}


int main (){
	setlocale(LC_ALL,"portuguese");
	dados2 tipo;
    n(&tipo);
	int op;

    do{
    	  system("cls");
    	  mostrar(&tipo);
    	  menu();
    	  scanf("%d",&op);
    	  
    	switch (op){
			case 1: inserir(&tipo); break;
			case 2: retirar(&tipo); break;
			case 3: deletar(&tipo); break;
			case 0: printf("\nFINALIZADO\n"); break;
			
			default: printf("OPCAO INVALIDA\n");
			system("pause");
    	}
   }while (op !=0);
}
