#include <stdio.h> //biblioteca de comunicacão com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings
  
int registro()  //função responsável por cadastras os usuários 
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");  
	scanf("%s", cpf); //%s refere-se as strings
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores
	
		FILE *file;  //cria o arquivo
		file = fopen(arquivo, "w");   //cria o arquivo e o "w" escreve
		fprintf(file,cpf);            //salvo o valor da variável
		fclose(file);                 //fecha o arquivo
	 
		file = fopen(arquivo, "a");     //abre o arquivo
		fprintf(file,", ");            //adiciona "," entre o contedo
		fclose(file);                 //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
	
		file = fopen(arquivo, "a");
		fprintf(file, ", ");
		fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
	
		file = fopen(arquivo, "a");
		fprintf(file, ", ");
		fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
		file = fopen(arquivo, "a");
		fprintf(file,cargo);
		fclose(file);
	
	system("pause");
}


int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("CPF Não encontrado!");
	}	
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informaoes do usuário: ");	
		
	printf("%s", conteudo);
	printf("\n\n");
		
	}
	
		system("pause");
	
}


int deletar()
{
	char cpf [40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("CPF a ser deletado não encontrado! \n");
		system("pause");		
	}

	
	
	
	
	
}


int main()
{	
	int opcao=0;
	int laco=1;
	
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("\t Cartório \t \n\n");
	printf("Login de administrador!\n\n");
	printf("Digite sua senha:");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "adm");
	
	if(comparacao == 0)
	{
		 system ("cls");
		 		
		for(laco=1;laco=1;)
		{
			system("cls"); //responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("\t Cartório \t \n\n");  //inicio do menu
   		  printf("Escolha uma opção abaixo \n\n");
		 	 printf("\t1 - Registrar nomes \n");
			 printf("\t2 - Consultar nomes \n");
		 	 printf("\t3 - Deletar nomes registrados \n"); //fim do meuno
		 	 printf("\t4 - Sair \n\n");
	 	 
		 	 printf("Opção:");
	 	 
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); //limpar tela após a escolha do usuário
	
	
		switch(opcao)
 			{
			case 1:
			registro();
			break;
		
			case 2:
			consulta();
			break;
		
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!");
			return 0;
			break;
			
			default:
			printf("Essa opção não esta disponivel!\n"); 
			system("pause");
			break;
			
	     	}
  		}  
	}
	
	else
	printf("Sua senha está incorreta!");
	
	
	
}

