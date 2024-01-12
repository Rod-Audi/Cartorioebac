#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //fun��o para cadastrar os usuarios no sistema
{
    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf ("Voc� escolheu registrar nomes.\n\nDigite o CPF a ser cadastrado: ");
    scanf ("%s" , &cpf); //%s se refere a sting(conjunto de variaveis)

    strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings

    FILE *file; //Cria o arquivo

    file = fopen(arquivo, "w"); //cria o arquivo
    fprintf(file,cpf); //salva o valor da vari�vel
    fclose(file); //fecha o arquivo

    file = fopen(arquivo, "a");
    fprintf(file,", ");
    fclose(file);

    printf ("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);

    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file,", ");
    fclose(file);

    printf ("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file,", ");
    fclose(file);

    printf("Digite o cargo do usu�rio: ");
    scanf("%s",cargo);

    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);

    }

int consulta() //Fun��o para consultar um usu�rio
{
    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

    printf ("Voc� escolheu consultar nomes.\n\n\n");

    char cpf[40];  //string CPF
    char conteudo[200]; //string Conteudo

    printf("Digite o CPF desejado: ");
    scanf("%s",cpf);

    FILE *file;
    file = fopen(cpf,"r");


    if(file == NULL) //mensagem para mostrar que foi digitado um CPF inv�lido
    {
        system("cls");
        printf("CPF n�o encontrado\n\n");
    }

    while(fgets(conteudo, 200, file) != NULL) //mensagem para mostrar o CPF desejado
    {
        system("cls");
        printf("Essas s�o as informa��es do usu�rio\n\n");
        printf("%s",conteudo);
        printf("\n\n");
    }


    system("pause");

}

int deletar() //fun��o para deletar usu�rio
{
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];

    printf ("Voc� escolheu deletar nomes.\n\n\nDigite o CPF a ser deletado: ");
    scanf("%s",cpf);


    remove(cpf);

    FILE *file;
    file = fopen(cpf,"r");
    system("cls");
    printf ("Este CPF foi deletado ou n�o consta em nosso sistema.\n");
    system("pause");

}

int main() //fun��o principal
{
    int opcao=0; //definindo as vari�veis
    int laco=1;

    for(laco=1;laco=1;)
    {

        system("cls");

        setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

        printf ("* Cart�rio do EBAC *\n\n"); //in�cio do menu
        printf ("Selecione a op��o desejada\n\n");
        printf ("\t1 - Registrar Nomes\n");
        printf ("\t2 - Consultar Nomes\n");
        printf ("\t3 - Deletar Nomes\n");
        printf ("\t4 - Sair do Sistema\n\n\n");
        printf ("Escolha a Op��o: "); //final do menu

        scanf ("%d" , &opcao); //armazenamento de usu�rios

        system("cls");

        switch(opcao) //inicio da sele��o do menu
        {
            case 1:
            registro(); //chamada de fun��es
            break; //respons�vel por n�o deixar o loop continuar

            case 2:
            consulta();
            break;

            case 3:
            deletar();
            break;

            case 4:
            printf ("Obrigado por utilizar o sistema\n");
            return 0;
            break;

            default: //qualquer op��o que seja diferente das programadas
            printf ("Op��o invalida, tente novamente.\n");
            system("pause");
            break;
        }
    }
}
