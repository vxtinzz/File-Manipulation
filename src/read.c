#include <stdio.h>
#include <stdlib.h>
#include "..\include\user.h"
#include "..\include\crud.h"

void READ(int id)
{
    User usuario;
    FILE *arq;
    arq = fopen("./data/register.txt", "r");
    if (arq == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    while (fscanf(arq, "%d;%49[^;];%49[^;];%49[^;];%d\n", &usuario.id, usuario.semanticId, usuario.name, usuario.email, &usuario.age) != EOF)
    {
        if (usuario.id == id)
        {
            printf("ID: %d\n",usuario.id);
            printf("Semantic ID: %s\n", usuario.semanticId);
            printf("Name: %s\n", usuario.name);
            printf("Email: %s\n", usuario.email);
            printf("Age: %d\n", usuario.age);
        }
    }
    fclose(arq);
}

void READALL()
{
    User usuario;
    FILE *arq;
    arq = fopen("./data/register.txt", "r");
    if (arq == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    printf("----User List----\n");
    while (fscanf(arq, "%d;%49[^;];%49[^;];%49[^;];%d\n", &usuario.id, usuario.semanticId, usuario.name, usuario.email, &usuario.age) != EOF)
    {
        printf("ID: %d\n", usuario.id);
        printf("Semantic ID: %s\n", usuario.semanticId);
        printf("Name: %s\n", usuario.name);
        printf("Email: %s\n", usuario.email);
        printf("Age: %d\n", usuario.age);
        printf("------------------------\n");
    }
    fclose(arq);
}