#include <stdio.h>
#include <stdlib.h>
#include "..\include\user.h"
#include "..\include\crud.h"

void UPDATE(int id)
{
    User usuario;
    FILE *arq, *temp;
    arq = fopen("../data/register.txt", "r");
    temp = fopen("../data/register.txt", "a");
    if (arq == NULL || temp == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    while (fscanf(arq, "%d;%49[^;];%49[^;];%d\n", &usuario.id, usuario.name, usuario.email, &usuario.age) != EOF)
    {
        if (usuario.id != id)
        {
            fprintf(temp, "%d;%s;%s;%d \n", usuario.id, usuario.name, usuario.email, usuario.age);
        }
        if (usuario.id == id)
        {
            printf("Insira os valores [Nome/Email/Idade]: ");
            scanf("%49[^/]/%49[^/]/%d", usuario.name, usuario.email, &usuario.age);
            fprintf(temp, "%d;%s;%s;%d\n", usuario.id, usuario.name, usuario.email, usuario.age);
        }
    }
    fclose(arq);
    fclose(temp);

    remove("../data/register.txt");
    rename("../data/temp.txt", "../data/register.txt");

    printf("Registro Atualizado com sucesso.\n");
}