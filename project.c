#include <stdio.h>  //bliblioteca de comunica��o de usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidas das stringsq

int registrar() //fun��o responsavel por cadastrar os usu�rios
  {
  	char arquivo[40];  //inicio da cria��o de variaveis/strings
  	char cpf[40];
  	char nome[40];
  	char sobrenome[40];
  	char cargo[40]; //final da cria��o de variaveis/strings
  	
  	printf("Digite o CPF a ser cadastrado:"); //coletando informa��o dos usu�rios
  	scanf("%s", cpf); //%s refere-se a uma string
  	
  	strcpy(arquivo, cpf); // respons�vel por copiar os valores das strings
  	
  	FILE *file; // cria o arquivo no banco de dados/pasta
  	file = fopen(arquivo, "w"); // fopen abrir um arquivo / w criar um novo arquivo
  	fprintf(file,cpf); // Salvo o valor da vari�vel
  	fclose(file); // fecha o arquivo
  	
	file = fopen(arquivo, "a"); // "a" de atualizar a informa��o e n�o criar uma nova
	fprintf(file,",");
	fclose(file);
	
	printf("Digite um nome a ser cadastrado:");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s",cpf);
	
    FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
    {
    	printf("N�o foi possivel abrir o arquivo,n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("Cpf:\n");
		printf("Nome:\n");
		printf("Sobrenome:\n");
		printf("Cargo:\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
	
	
	
}


int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);

	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL);
	{
		printf("O usu�rio n�o se encontra no sistema!. \n");
		system("pouse");
		
	}
}


int main()
{
		
	int opcao=0; // Definindo as vari�veis
	int back=1;
	
	for(back=1;back=1;)
	{
		
		system("cls");   // Delete page  
	
	
	   setlocale(LC_ALL, "Portuguese"); // Definindo o Idioma
	   
	    printf("\t Cart�rio de usu�rios da EBAC\n\n");
	     printf("Ecolha a op��o desejada:\n\n");
	      printf("\t1 - Regisrar nomes\n");              //Menu 
	       printf("\t2 - Consultar nomes\n");
	        printf("\t3 - Deletar nomes\n\n");
	         printf("\t4 - Sair do sistema\n\n");
	          printf("Op��o:"); 
	         
	    scanf("%d", &opcao); // Armazenando a escolha do usu�rio na vari�vel
	    
	    system("cls"); // Deleta a p�gina ap�s uma resposta.
	    
	    
	switch(opcao)
	{
		 case 1:
	   	registrar();  //chamada de fun��es
	    break;
	       
	     case 2:
	    consultar();
	   	break;
		
		 case 3:                                        // respostas do menu 
	    deletar();
	    break;
	     
	     case 4:
	     printf("Obrigado por utilizar o sistema!\n");
	     return 0;
	     break;
	    
	     default:
	    printf ("Essa op��o n�o esta disponivel!!");
		system("pause");
		break;
		 	           // Fim 
	    	}
		  
		 }
}
