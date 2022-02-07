#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include "modulo_pessoas.h"

#define quant_pes 100

struct Cadastro //Objeto de Variaveis que Cadastrará o Usuario
{
    char nome[20];
    char Sobrenome[20];
    int Nacionalidade;
    char CPF[12];
    char RG[11]; //entre 6 e 9
    char Passaporte[9];//8
    char EMAIL[64];
    int Usuario; //Aluno_Professor = Usuário;
    int Numero_da_Matricula; //Começando com 20000 a Matricula dos Alunos

};

struct Base
{
    int Usuario; //50

};
struct Base base;

struct Cadastro Pessoa[quant_pes];//tipo Pessoa



void Cadastro_Do_Usuario(struct Cadastro Pessoa[quant_pes], int *cont_pessoas, int *num_matricula, int *quant_Usuario)
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
        printf("ERRO! Quantidade de Numeros do EMAIL invalido\n");
    }



    scanf("%d[^;]", &Pessoa[*cont_pessoas].Usuario);

    if(Pessoa[*cont_pessoas].Usuario == 0)//se for aluno
    {
        (*quant_Usuario)++;

        *num_matricula = ((*num_matricula) + 1);
        Pessoa[*cont_pessoas].Numero_da_Matricula = *num_matricula;

        base.Usuario = *quant_Usuario; //escola.alunos = *quant_alunos;
    }

    }


void Consutar_Usuario( struct Cadastro Pessoa[quant_pes], int *cont_pessoas)
{

    int Verifica;
    int Verf_Matricula;
    int i;
    int erro =0;

    printf("Insira 0-Usuario\n");
    scanf("%d", &Verifica);

    if(Verifica == 0) //Será Aluno
    {
        printf("Digite a matricula:\n");
        scanf("%d", &Verf_Matricula);

        for(i=0; i<*cont_pessoas; i++)
        {
            if(Verf_Matricula == Pessoa[i].Numero_da_Matricula)//verifica se a matricula existe
            {

                    //Imprimindo os Dados do Aluno
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


void Alterar_Dados_Do_Usuario(struct Cadastro Pessoa[quant_pes],int *cont_pessoas)
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

    printf("Insira matricula:\n");//Verificando se o aluno
    scanf("%s", Idenficacao);
    getchar();

    Tamanho_String = strlen(Idenficacao);

    if(Tamanho_String == 5)//aluno
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

int main_Usuarios()
{

    int Opcao;


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
             Cadastro_Do_Usuario(Pessoa, cont_pessoas, &num_matricula, &quant_Usuario);
             getchar();
            (*cont_pessoas)++;
            break;

        case 2://Exibir dados de todas as pessoas
            Consutar_Usuario(Pessoa, cont_pessoas);
            break;

        case 3://Altera os Dados de Algum Usuario
            Alterar_Dados_Do_Usuario(Pessoa, cont_pessoas);
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
