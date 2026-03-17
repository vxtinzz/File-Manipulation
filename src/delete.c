#include <stdio.h>
#include <stdlib.h>
#include "..\include\user.h"
#include "..\include\crud.h"

void DELETE(int id)
{
    User usuario;
    FILE *arq, *temp;
    int found = 0;
    arq = fopen("./data/register.txt", "r");
    temp = fopen("./data/temp.txt", "a");
    if (arq == NULL || temp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    while (fscanf(arq, "%d;%49[^;];%49[^;];%49[^;];%d\n", &usuario.id, usuario.semanticId, usuario.name, usuario.email, &usuario.age) != EOF)
    {
        if (usuario.id != id)
        {
            fprintf(temp, "%d;%s;%s;%s;%d\n", usuario.id, usuario.semanticId, usuario.name, usuario.email, usuario.age);
        }else if(usuario.id == id){
            found = 1;
            continue;
        }
    }
    fclose(arq);
    fclose(temp);

    if (remove("./data/register.txt") != 0) {
    printf("Error removing original file\n");
    return;
    }

    if (rename("./data/temp.txt", "./data/register.txt") != 0) {
    printf("Erro renaming file.\n");
    return;
    }
    if(found){
    printf("Record successfully removed!!\n");
    }else{
    printf("Id Not Found!!\n");
    }
    
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