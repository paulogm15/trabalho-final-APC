#include <stdio.h>

struct politico
{
    char nome[81];
    char partido[81];
    int matricula;
};

struct ementa
{
    char nome[81];
    char descricao[1001];
    char votos[100][1];
};

void menu_principal()
{
    //mostrar o menu de opções
    printf("Escolha uma das opcoes:\n");
    printf("1  Cadastrar politico\n");
    printf("2  Editar dados de politico\n");
    printf("3  Excluir politico do sistema\n");
    printf("4  Cadastrar proposta de emenda constitucional (PEC)\n");
    printf("5  Registrar voto de politico em emenda\n");
    printf("6  Excluir proposta de emenda constitucional (PEC)\n");
    printf("7  Exibir Meu Ranking por politico\n");
    printf("0  Sair\n");
}

int validaOpcao()
{
    int opcao; //variavel para armazenar a opção escolhida
    menu_principal();

    //le opção escolhida
    scanf("%d", &opcao);

    while (opcao < 0 || opcao > 7)
    { //mensagem de erro caso se digite uma opção que nao existe
        printf("[ERRO]: opção não existe!\nEscolha uma opção válida\n");
        menu_principal();
        scanf("%d", &opcao);
    }
    return opcao;
}

int validar_nome_politico(char nome[81])
{
    int i = 0;
    int resposta[81];

    for (i = 0; nome[i] != '\0'; i++)
    {
        resposta[i] = nome[i];
    }
    resposta[i] = '\0';

    i = 0;
    while (resposta[i] != '\0')
    {
        if (resposta[i] < 65 && resposta[i] != 32 || resposta[i] > 90 && resposta[i] < 97 || resposta[i] > 122) // casos de descarte (return 0)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int tamString(char txt[81])
{
    int tam = 0;

    while (txt[tam] != '\0')
    {
        tam++;
    }
    return tam;
}

//primeira opção:

int cadastrar_politico(struct politico politicos[100], int matricula)
{
    int i, j, k, l;
    char resposta[81];
    char resposta2[81];

    printf("Qual o nome do politico que gostaria de cadastrar? Digite '0' para voltar ao menu inicial.\n");
    scanf(" %[^\n]", resposta);
    if (resposta[0] == '0') //trata a opção 0
    {
        return 0;
    }
    else
    {

        while (validar_nome_politico(resposta) == 0)
        {
            printf("Nome invalido!\n");
            printf("Qual o nome do politico que gostaria de cadastrar? Digite '0' para voltar ao menu inicial.\n");
            scanf(" %[^\n]", resposta);
            if (resposta[0] == '0') //trata a opção 0
            {
                return 0;
            }
        }
        politicos[matricula].matricula = matricula;
        for (i = 0; resposta[i] != '\0'; i++)
        {
            politicos[matricula].nome[i] = resposta[i];
        }

        printf("Qual partido dele?\n");
        scanf(" %[^\n]", resposta2);
        if (tamString(resposta) == tamString(resposta2))
        {
            i = 0;
            while (resposta[i] == resposta2[i])
            {
                i++;
            }

            while (i - 1 == tamString(resposta))
            {
                printf("Partido invalido!\n");
                printf("Qual partido dele?\n");
                scanf(" %[^\n]", resposta2);
                if (tamString(resposta) == tamString(resposta2))
                {
                    i = 0;
                    while (resposta[i] == resposta2[i])
                    {
                        i++;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        for (i = 0; i < matricula; i++)
        {
            for (j = 0; j < tamString(resposta); j++)
            {
                if (politicos[i].nome[j] == politicos[matricula].nome[j])
                {
                    k++;
                }
            }
            if (k == tamString(resposta))
            {
                for (k = 0; k < tamString(resposta2); k++)
                {
                    l++;
                }
                if (l == tamString(resposta2))
                {
                    printf("Ja existe %s do partido %s\n", politicos[matricula].nome, politicos[matricula].partido);
                    cadastrar_politico(politicos, matricula);
                }
            }
        }
        for (i = 0; resposta2[i] != '\0'; i++)
        {
            politicos[matricula].partido[i] = resposta2[i];
        }
    }
    printf("Cadastro efetuado com sucesso!\n");
    return 0;
}

void editar_dados()
{
}

void excluir_politico()
{
}

void cadastrar_proposta()
{
}

void registrar_voto()
{
}

void excluir_proposta()
{
}

void exibir_ranking()
{
}

int main(void)
{
    struct politico politicos[100];
    int opcao;
    int matricula = 0;

    opcao = validaOpcao(); //mostra o menu, recebe e trata a opção selecionada

    while (opcao != 0)
    {
        switch (opcao)
        {
        case 1:
            cadastrar_politico(politicos, matricula);
            matricula++;
            break;
        case 2:
            editar_dados();
            break;
        case 3:
            excluir_politico();
            break;
        case 4:
            cadastrar_proposta();
            break;
        case 5:
            registrar_voto();
            break;
        case 6:
            excluir_proposta();
            break;
        case 7:
            exibir_ranking();
            break;
        }
        opcao = validaOpcao(); //mostra o menu, recebe e trata a opção selecionada
    }

    printf("Obrigado por utilizar nossos servicos!\n");

    //teste politico----------------
    int i;
    for (i = 0; i < matricula; i++)
    {
        printf("politico[%d]\n", i);
        printf("%s %s %d\n", politicos[i].nome, politicos[i].partido, politicos[i].matricula);
    }

    return 0;
}