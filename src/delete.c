#include <stdio.h>
#include <stdlib.h>
#include "..\include\user.h"
#include "..\include\crud.h"

void DELETE(int id)
{
    User usuario;
    FILE *arq, *temp;
    arq = fopen("../data/register.txt", "r");
    temp = fopen("../data/temp.txt", "a");
    if (arq == NULL || temp == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    while (fscanf(arq, "%d;%49[^;];%49[^;];%d\n", &usuario.id, usuario.name, usuario.email, &usuario.age) != EOF)
    {
        if (usuario.id != id)
        {
            fprintf(temp, "%d;%s;%s;%d\n", usuario.id, usuario.name, usuario.email, usuario.age);
        }
    }
    fclose(arq);
    fclose(temp);

    remove("../data/register.txt");
    rename("../data/temp.txt", "../data/register.txt");

    printf("Registro removido com sucesso.\n");
}

void DELETEALL()
{
    FILE *arq;
    char option;
    printf("CONFIRME A OPCAO S(s) | N(n):\n");
    scanf(" %c", &option);
    if (option == 'n' || option == 'N')
    {
        printf("OPERACAO CANCELADA!!");
    }
    if (option == 's' || option == 'S')
    {
        printf("DADOS EXCLUIDOS!!");
        remove("data/register.txt");
        arq = fopen("data/register.txt", "w+");
        fclose(arq);
    }
}