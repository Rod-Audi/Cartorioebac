#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //função para cadastrar os usuarios no sistema
{
    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf ("Você escolheu registrar nomes.\n\nDigite o CPF a ser cadastrado: ");
    scanf ("%s" , &cpf); //%s se refere a sting(conjunto de variaveis)

    strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings

    FILE *file; //Cria o arquivo

    file = fopen(arquivo, "w"); //cria o arquivo
    fprintf(file,cpf); //salva o valor da variável
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

    printf("Digite o cargo do usuário: ");
    scanf("%s",cargo);

    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);

    }

int consulta() //Função para consultar um usuário
{
    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

    printf ("Você escolheu consultar nomes.\n\n\n");

    char cpf[40];  //string CPF
    char conteudo[200]; //string Conteudo

    printf("Digite o CPF desejado: ");
    scanf("%s",cpf);

    FILE *file;
    file = fopen(cpf,"r");


    if(file == NULL) //mensagem para mostrar que foi digitado um CPF inválido
    {
        system("cls");
        printf("CPF não encontrado\n\n");
    }

    while(fgets(conteudo, 200, file) != NULL) //mensagem para mostrar o CPF desejado
    {
        system("cls");
        printf("Essas são as informações do usuário\n\n");
        printf("%s",conteudo);
        printf("\n\n");
    }


    system("pause");

}

int deletar() //função para deletar usuário
{
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];

    printf ("Você escolheu deletar nomes.\n\n\nDigite o CPF a ser deletado: ");
    scanf("%s",cpf);


    remove(cpf);

    FILE *file;
    file = fopen(cpf,"r");
    system("cls");
    printf ("Este CPF foi deletado ou não consta em nosso sistema.\n");
    system("pause");

}

int main() //função principal
{
    int opcao=0; //definindo as variáveis
    int laco=1;

    for(laco=1;laco=1;)
    {

        system("cls");

        setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

        printf ("* Cartório do EBAC *\n\n"); //início do menu
        printf ("Selecione a opção desejada\n\n");
        printf ("\t1 - Registrar Nomes\n");
        printf ("\t2 - Consultar Nomes\n");
        printf ("\t3 - Deletar Nomes\n");
        printf ("\t4 - Sair do Sistema\n\n\n");
        printf ("Escolha a Opção: "); //final do menu

        scanf ("%d" , &opcao); //armazenamento de usuários

        system("cls");

        switch(opcao) //inicio da seleção do menu
        {
            case 1:
            registro(); //chamada de funções
            break; //responsável por não deixar o loop continuar

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

            default: //qualquer opção que seja diferente das programadas
            printf ("Opção invalida, tente novamente.\n");
            system("pause");
            break;
        }
    }
}
