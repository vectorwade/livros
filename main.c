#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include "modulo_usuario.h"
#define quant_pes 100
#include "modulo_usuario.h"
#ifndef modulo_estruturas
#define modulo_estruturas


typedef struct{
    char login[30]; // vetor para o login e senha da struct pessoa
    char senha[30];
} pessoa; pessoa p[1]; // renomeado

struct Cadastro //Objeto de Variaveis que Cadastrará o Usuario
{
    char nome[20];
    char Sobrenome[20];
    char CPF[12];
    char RG[11]; //entre 6 e 9
    char EMAIL[64];
    int Usuario; //Aluno_Professor = Usuário;
    int Numero_da_Matricula; //Começando com 200 a Matricula dos usuarios

};
struct Cadastro Pessoa[quant_pes];//tipo Pessoa


struct Base
{
    int Usuario; //100
};
struct Base base;



void Cadastro_Do_Usuario(struct Cadastro Pessoa[quant_pes], int *cont_pessoas, int *num_matricula, int *quant_Usuario);

void Consutar_Usuario( struct Cadastro Pessoa[quant_pes], int *cont_pessoas);

void Alterar_Dados_Do_Usuario(struct Cadastro Pessoa[quant_pes],int *cont_pessoas);

void Remover_Usuario(struct Cadastro Pessoa[quant_pes], int *cont_pessoas, struct Base base);

void main_Usuarios(int *cont_pessoas, int *cont_cadastro);



int main ()
{
    int opc = 0;
    int cont_pessoas=0;
    int cont_cadastro=0;

    char login[30]; // responsável por armazenar login e senha
    char senha[30];



    strcpy(p[0].login, "victor");
    strcpy(p[0].senha, "12345678");
    strcpy(p[1].login, "Admin");
    strcpy(p[1].senha, "Master");

    int login_efetuado = 0; //0 - Falso e  1 - Verdadeiro

    printf("\nAcesso ao portal\n");

    while(!login_efetuado){

    printf("\nDigite o seu login:");
    scanf("%s", login);

    printf("\nDigite a sua senha:");
    scanf("%s", senha);

    if ((strcmp(login,p[0].login)==0) && (strcmp(senha,p[0].senha)==0)|| (strcmp(login,p[1].login)==0) && (strcmp(senha,p[1].senha)==0)   ){ // A função strcmp é responsável por comparar string com string
        printf("Acesso permitido"); // se os vetores de dentro da struct tiver os mesmos dados do vetor interno da função main, usuário será logado.
        login_efetuado = 1;
    }else{
        printf("\nLogin e/ou senha incorretos!\n\nDigite novamente\n");
    }

        }


    system("cls");//limpa a tela

    while(opc != 3)
    {
        printf("*******************************************************************\n");
        printf("----------------Seja-Bem-vindo(a)----------------------------------\n");
        printf("                                                                   \n");
        printf("1 - Sistema de Usuarios\n2 - Sistema de Livros\n3 - Sair do Sistema\n");
        scanf("%d", &opc);

        switch(opc)
        {

        case 1:

            main_Usuarios(int *cont_pessoas, int *cont_cadastro)
            //main_Usuarios(&cont_pessoas,&cont_cadastro);
            break;

        case 2:
            //main_Livros();
            break;

        case 3://Sair do Sistema

            break;

        default:
            printf("\nDigite uma uma opcao valida\n");
            printf("\n");
        }



    }
    return 0;
}


void Cadastro_Do_Usuario(struct Cadastro Pessoa[quant_pes], int *cont_pessoas, int *num_matricula, struct Base base, int *quant_Usuario)
{

    int Tamanho = 0;
    int tamanho_cpf=0;
    int tamanho_rg=0;
    int tamanho_email=0;



        scanf("%[^;]", Pessoa[*cont_pessoas].nome);
        getchar();
        scanf("%[^;]", Pessoa[*cont_pessoas].Sobrenome);
        getchar();

        scanf("%[^;]", Pessoa[*cont_pessoas].CPF);
        getchar();

        tamanho_cpf = strlen(Pessoa[*cont_pessoas].CPF);

        if(tamanho_cpf > 11 || tamanho_cpf < 11) //comparar tamanho de string
        {
            printf("ERRO Quantidade de Numeros do CPF invalida\n");
        }
        else
        {

            scanf("%[^;]", Pessoa[*cont_pessoas].RG);
            getchar();
        }

        tamanho_rg = strlen(Pessoa[*cont_pessoas].RG );

        if(tamanho_rg > 9 || tamanho_rg < 6 )
        {
            printf("ERRO quantidade de numeros do RG invalido\n");
        }


        scanf("%[^;]", Pessoa[*cont_pessoas].EMAIL);
    getchar();

    tamanho_email = strlen(Pessoa[*cont_pessoas].EMAIL);

    if( tamanho_email > 10 ||tamanho_email < 64 )
    {
        printf(" Quantidade de Numeros do EMAIL invalido\n");
    }



    scanf("%d[^;]", &Pessoa[*cont_pessoas].Usuario);

    if(Pessoa[*cont_pessoas].Usuario == 0)//cpnfere usuario
    {
        (*quant_Usuario)++;

        *num_matricula = ((*num_matricula) + 1);
        Pessoa[*cont_pessoas].Numero_da_Matricula = *num_matricula;

        base.Usuario = *quant_Usuario;
    }

    }


void Consutar_Usuario(struct Cadastro Pessoa[quant_pes], int *cont_pessoas,struct Base base)
{

    int Verifica;
    int Verf_Matricula;
    int i;
    int erro =0;

    printf("Insira 0-Usuario\n");
    scanf("%d", &Verifica);

    if(Verifica == 0) //verificação
    {
        printf("Digite a matricula:\n");
        scanf("%d", &Verf_Matricula);

        for(i=0; i<*cont_pessoas; i++)
        {
            if(Verf_Matricula == Pessoa[i].Numero_da_Matricula)//verifica se a matricula existe
            {

                    //Mostra os dados cadastrados
                    printf("\n");
                    printf("------------------------------------------------\n");
                    printf("     Nome:                 %s                            \n",Pessoa[i].nome);
                    printf("     Sobrenome:            %s                            \n",Pessoa[i].Sobrenome);
                    printf("     CPF:                  %s                            \n",Pessoa[i].CPF);
                    printf("     RG:                   %s                            \n",Pessoa[i].RG);
                    printf("     EMAIL:                %s                           \n",Pessoa[i].EMAIL);
                    printf("     Numero da Matricula:  %d                            \n",Pessoa[i].Numero_da_Matricula);
                    printf("------------------------------------------------\n");


                erro = 1;
            }
        }
        if(erro != 1)
        {
            printf("Erro! Cadastro nao encontrado.\n");
            erro =0;
        }
    }

}


void Alterar_Dados_Do_Usuario(struct Cadastro Pessoa[quant_pes],int *cont_pessoas, struct Base base)
{
    int Verifica_Alt=0;
    int Matricula_Verf;
    int Opcao_Alt=0;

    printf("Insira 0-Usuario \n");//Verificando se � Aluno ou Professor
    scanf("%d", &Verifica_Alt);

    if(Verifica_Alt == 0)//Se for Aluno fará as buscas de Matricula
    {
        printf("Insira a Matricula do Usuario:\n");
        scanf("%d", &Matricula_Verf);

        for(int i=0; i < *cont_pessoas; i++) //Verificando se o Aluno Existe
        {
            if( Matricula_Verf == Pessoa[i].Numero_da_Matricula)
            {
                printf("\n");
                printf("1.CPF\n");
                printf("2.RG\n");
                printf("3.EMAIL\n");

                scanf("%d", &Opcao_Alt);
                getchar();

                switch(Opcao_Alt)
                {
             case 1:
                    scanf("%d", &Pessoa[i].CPF);
                    getchar();
                    break;

                case 2:
                    scanf("%s", Pessoa[i].RG);
                    getchar();
                    break;

                case 3:
                   scanf("%s", Pessoa[i].EMAIL);
                    getchar();
                    break;

                default:
                    printf("Opcao Invalida\n");
                    break;
                }
            }

        }
    }

}



void Remover_Usuario(struct Cadastro Pessoa[quant_pes], int *cont_pessoas, struct Base base)
{
    char Idenficacao[15];
    int Tamanho_String;
    int Idenficacao_int=0;
    int i,j;

    printf("Insira matricula:\n");//Verificando se e usuario
    scanf("%s", Idenficacao);
    getchar();

    Tamanho_String = strlen(Idenficacao);

    if(Tamanho_String == 7)//usuario
    {
        Idenficacao_int = atoi(Idenficacao);

        for(i=0; i < *cont_pessoas; i++)
        {
            if( Idenficacao_int == Pessoa[i].Numero_da_Matricula)
            {
                for(j=i; j < *cont_pessoas-1; j++)
                {
                    Pessoa[j] = Pessoa[j+1];
                }

                (*cont_pessoas)--;

                printf("Aluno removido.\n");
            }
            else
            {
                printf("Aluno não Encontrado\n");
            }
        }
    }


}



void main_Usuarios(int *cont_pessoas, int *cont_cadastro)
{

    int Opcao;
    int num_matricula = 200;
    int quant_Usuario =0;



    while(Opcao != 5)
    {
        printf("-------------------Menu-------------------------\n");
        printf("                                                \n");
        printf("   1 - Cadastrar um Usuario                     \n");
        printf("                                                \n");
        printf("   2 - Consultar um Usuario                     \n");
        printf("                                                \n");
        printf("   3 - Alterar dados de um Usuario              \n");
        printf("                                                \n");
        printf("   4 - Remover um Usuario                       \n");
        printf("                                                \n");
        printf("   5 - Voltar/Sair                              \n");
        printf("                                                \n");
        printf("------------------------------------------------\n");

        scanf("%d", &Opcao);
        getchar();

         switch(Opcao)
        {

        case 1:
             Cadastro_Do_Usuario(Pessoa, cont_pessoas, &num_matricula, base, &quant_Usuario);
             getchar();
            (*cont_pessoas)++;
            break;

        case 2://Mostra os dados do usuario
            Consutar_Usuario(Pessoa, cont_pessoas, base);
            break;

        case 3://Altera os Dados de Algum Usuario
            Alterar_Dados_Do_Usuario(Pessoa, cont_pessoas, base);
            break;

        case 4://Excluir um usuario
            Remover_Usuario(Pessoa, cont_pessoas, base);
            break;

        case 5: //Sair do Programa
            break;

        default:


            printf("Escolha uma opcao valida!");
            printf("\n");
        }
    }

}

