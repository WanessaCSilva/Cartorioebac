#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Início criação de variáveis/string
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário (CPF)
	scanf("%s", cpf); //%s refere-se a string. Varre tudo que o usuário digita e salva onde for determinado.
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //Salvo o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abrindo arquivo já salvo, "a" de atualizar o arquivo já existente
	fprintf(file, ","); //Elemento incluso na atualização do arquivo (inserção da "," para separar os dados. Salvo o valor da variável
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informação do usuário (Nome)
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Atualizando o arquivo com a inclusão do nome
	fprintf(file,nome); //Salvo o valor da variável nome
	fclose(file);
	
	file = fopen(arquivo, "a"); //Atualizando o arquivo 
	fprintf(file, ","); //Separando o CPF do Nome
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informação do usuário (Sobrenome)
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Atualizando o arquivo com a inclusão do sobrenome
	fprintf(file,sobrenome); //Salvo o valor da variável sobrenome
	fclose(file);
	
	file = fopen(arquivo, "a"); //Atualizando o arquivo
	fprintf(file, ","); //Separando o CPF do Nome e o Nome do Sobrenome
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informação do usuário (Cargo)
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Atualizando o arquivo com a inclusão do cargo
	fprintf(file,cargo); //Salvo o valor da variável cargo
	fclose(file);
	
	system("pause");
	
}

int consulta() //Função responsável por consultar os usuários do sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
	
	char cpf[40]; //Criando o arquivo CPF para ser consultado
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //Coletando informação do usuário
	scanf("%s",cpf); //%s refere-se a string. Varre tudo que o usuário digita e salva onde for determinado.
	
	FILE *file; //Consulta o arquivo
	file = fopen(cpf,"r"); //Cria o arquivo e o "r" significa ler
	
	if(file == NULL) //Validação para o caso de informação fornecida pelo usuário não for encontrada
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Laço de repetição. Enquanto a informação fornecida for encontrada, ela estará sendo salva. Do contrário, nulo.
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n"); //Pulando linhas
	}

	system("pause");
	
	
}

int deletar() //Função responsável por deletar os usuários do sistema
{
	char cpf[40]; //Criando o arquivo CPF para ser consultado
	
	printf("Digite o CPF do usuário a ser deletado: "); //Coletando informação do usuário
	scanf("%s",cpf); //%s refere-se a string. Varre tudo que o usuário digita e salva onde for determinado.
	
	remove(cpf); //Acessa a pasta onde está salva a informação dada pelo usuário e a deleta.
	
	FILE *file; //Consulta o arquivo
	file = fopen(cpf, "r"); //Cria o arquivo e o "r" significa ler
	
	if(file == NULL) //Validação para o caso de informação fornecida pelo usuário não for encontrada
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
		
		}	
						
}


int main () 
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
		 
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Início do Menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: "); //Fim do Menu

		scanf("%d" , &opcao); //Armazenando a escolha do usuário

		system("cls"); //Responsável por limpar a tela
		
		switch(opcao) //Início da seleção do menu
		{
			case 1:
			registro(); //Chamada de função
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
		    deletar();
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;	
		} //Fim da seleção.
	
		
	}	
}

