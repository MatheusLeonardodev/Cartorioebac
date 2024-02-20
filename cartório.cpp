#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
   //in�cio da cria��o das vari�veis/strings
  char arquivo[40];
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];
   //final da cria��o das vari�veis/strings	
   
  printf("digite o cpf a ser cadastrado: "); //coletando informa��o do usu�rio
  scanf("%s", cpf); //%s refere-se as strings

  strcpy(arquivo, cpf);
  
  FILE *file; //cria o arquivo no banco de dados
  file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
  fprintf(file,cpf); //salvo o valor da v�riavel
  fclose(file); //fecho o arquivo
  
  file = fopen(arquivo, "a");
  fprintf(file,",");
  fclose(file);
  
  printf("digite o nome a ser cadastrado: ");
  scanf("%s",nome);
  
  file = fopen(arquivo, "a");
  fprintf(file,nome);
  fclose(file);
  
  file = fopen(arquivo, "a");
  fprintf(file,",");
  fclose(file);
  
  printf("digite o sobrenome a ser cadastrado: ");
  scanf("%s",sobrenome);
  
  file = fopen (arquivo, "a");
  fprintf(file,sobrenome);
  fclose(file);
  
  file = fopen(arquivo, "a");
  fprintf(file,",");
  fclose(file);
  
  printf("digite o cargo a ser cadastrado: ");
  scanf("%s",cargo);
  
  file = fopen (arquivo, "a");
  fprintf(file, cargo);
  fclose(file);
  
  system("pause");
  
  
  
}

int consultar()
{
 
  setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

 
  char cpf [40];
  char conteudo[200];
  
  printf ("Digite o cpf a ser consultado: ");
  scanf("%s",cpf);
  
  FILE *file;
  file = fopen(cpf,"r");
  
  if(file == NULL)
  {
  	printf("N�o foi poss�vel abrir o arquivo, n�o localizado!. \n");
  }
  
  while(fgets(conteudo,200,file) != NULL);
  {
  	printf("Essas s�o as informa��es do usu�rio: ");
  	printf("%s", conteudo);
  	printf("\n\n");
  	
  	system("pause");
  	
  	fclose(file); 
  	
  }
  
}

int deletar()
{
   char cpf [40];
   
   printf("Digite o cpf do usu�rio a ser deletado: ");
   scanf("%s",cpf);
   
   remove(cpf);
   
   FILE *file;
   file = fopen(cpf,"r");
   
   if(file == NULL)
   {
   	printf("O usu�rio n�o se encontra no sistema! \n");
   	system("pause");
   	
   }     
  
  else if (file != NULL) 
  {
  
  printf("O usu�rio foi deletado!\n");
  system("pause");
  remove(cpf);
  }
  
}


int main()
{
	int opcao=0; //definindo vari�veis
	int laco=1;
	for(laco=1;laco=1;)
	
{
  	
  	system("cls"); //respons�vel por limpar a tela
	
  setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
  printf ("### Cart�rio da EBAC ### \n\n"); //in�cio do menu
  printf ("Escolha a op��o desejada do menu:\n\n");
  printf ("\t1 - Registrar nomes\n");
  printf ("\t2 - Consultar nomes\n");
  printf ("\t3 - Deletar nomes\n\n\n\n"); //final do menu
  printf ("\t4 - Sair do sistema\n");
  printf ("op��o:");
  
  scanf ("%d", &opcao); //armazenando escolha do usu�rio
  
  system("cls"); //respons�vel por limpar a tela
  
  
  switch(opcao) //in�cio da fun��o menu
{

  case 1:
  registro(); //chamada de fun��es
  break;
  
  case 2:
  consultar();
  break;
  
  case 3:
  deletar();
  break;
  
  case 4:
  printf("Obrigado por utilizar o sistema!\n");
  return 0;
  break;
  
  default:
  printf("Essa op��o n�o est� dispon�vel!\n");
  system("pause");
  break;
  
}
  
  printf ("Esse Softare � de livre uso para todos\n");
  printf ("Criado por Matheus Leonardo");
}
}
