#include <stdio.h>  //bliblioteca de comunicação de usuário 
#include <stdlib.h> //biblioteca de alocação de espaço de memória 
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidas das stringsq

int registrar() //função responsavel por cadastrar os usuários
  {
  	char arquivo[40];  //inicio da criação de variaveis/strings
  	char cpf[40];
  	char nome[40];
  	char sobrenome[40];
  	char cargo[40]; //final da criação de variaveis/strings
  	
  	printf("Digite o CPF a ser cadastrado:"); //coletando informação dos usuários
  	scanf("%s", cpf); //%s refere-se a uma string
  	
  	strcpy(arquivo, cpf); // responsável por copiar os valores das strings
  	
  	FILE *file; // cria o arquivo no banco de dados/pasta
  	file = fopen(arquivo, "w"); // fopen abrir um arquivo / w criar um novo arquivo
  	fprintf(file,cpf); // Salvo o valor da variável
  	fclose(file); // fecha o arquivo
  	
	file = fopen(arquivo, "a"); // "a" de atualizar a informação e não criar uma nova
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
    	printf("Não foi possivel abrir o arquivo,não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuário: ");
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
	
	printf("Digite o CPF do usuário a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);

	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL);
	{
		printf("O usuário não se encontra no sistema!. \n");
		system("pouse");
		
	}
}


int main()
{
		
	int opcao=0; // Definindo as variáveis
	int back=1;
	
	for(back=1;back=1;)
	{
		
		system("cls");   // Delete page  
	
	
	   setlocale(LC_ALL, "Portuguese"); // Definindo o Idioma
	   
	    printf("\t Cartório de usuários da EBAC\n\n");
	     printf("Ecolha a opção desejada:\n\n");
	      printf("\t1 - Regisrar nomes\n");              //Menu 
	       printf("\t2 - Consultar nomes\n");
	        printf("\t3 - Deletar nomes\n\n");
	         printf("\t4 - Sair do sistema\n\n");
	          printf("Opção:"); 
	         
	    scanf("%d", &opcao); // Armazenando a escolha do usuário na variável
	    
	    system("cls"); // Deleta a página após uma resposta.
	    
	    
	switch(opcao)
	{
		 case 1:
	   	registrar();  //chamada de funções
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
	    printf ("Essa opção não esta disponivel!!");
		system("pause");
		break;
		 	           // Fim 
	    	}
		  
		 }
}
