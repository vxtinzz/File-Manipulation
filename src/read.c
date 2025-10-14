#include <stdio.h>
#include <stdlib.h>
#include "..\include\user.h"
#include "..\include\crud.h"

void READ(int id)
{
    User usuario;
    FILE *arq;
    arq = fopen("../data/register.txt", "r");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    while (fscanf(arq, "%d;%49[^;];%49[^;];%d\n", &usuario.id, usuario.name, usuario.email, &usuario.age) != EOF)
    {
        if (usuario.id == id)
        {
            printf("ID: %d\n", usuario.id);
            printf("Nome: %s\n", usuario.name);
            printf("Email: %s\n", usuario.email);
            printf("Idade: %d\n", usuario.age);
        }
    }
    fclose(arq);
}

void READALL()
{
    User usuario;
    FILE *arq;
    arq = fopen("../data/register.txt", "r");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    printf("----Lista de Usuarios----\n");
    while (fscanf(arq, "%d;%49[^;];%49[^;];%d\n", &usuario.id, usuario.name, usuario.email, &usuario.age) != EOF)
    {
        printf("ID: %d\n", usuario.id);
        printf("Nome: %s\n", usuario.name);
        printf("Email: %s\n", usuario.email);
        printf("Idade: %d\n", usuario.age);
        printf("------------------------\n");
    }
    fclose(arq);
}