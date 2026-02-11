#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "..\include\user.h"
#include "..\include\crud.h"

void CREATE()
{
    User usuario;
    int lastId = 0;
    FILE *arq;

    arq = fopen("../data/register.txt", "r");
    if (arq != NULL)
    {
        while (fscanf(arq, "%d;%49[^;];%49[^;];%49[^;];%d\n",
                      &usuario.id, usuario.semanticId, usuario.name, usuario.email, &usuario.age) != EOF)
        {
            lastId = usuario.id;
        }
        fclose(arq);
    }

    arq = fopen("../data/register.txt", "a");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("Nome: ");
    fgets(usuario.name, sizeof(usuario.name), stdin);
    usuario.name[strcspn(usuario.name, "\n")] = '\0';
    printf("Email: ");
    scanf("%s", usuario.email);
    printf("Idade: ");
    scanf("%d", &usuario.age);
    usuario.id = lastId + 1;
    usuario.semanticId = "SUP-YYYY-NUMBER";

    fprintf(arq, "%d;%s;%s;%d\n", usuario.id, usuario.name, usuario.email, usuario.age);
    fclose(arq);

    printf("Usuário adicionado!\n");