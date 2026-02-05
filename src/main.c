#include <stdio.h>
#include <stdlib.h>
#include "..\include\crud.h"

int main()
{
    int op, id;
    printf("==Sistema de Clientes==\n");
    do
    {
        printf("\n1 - Cadastrar cliente\n2 - Listar clientes\n3 - Buscar cliente por ID\n4 - Editar cliente\n5 - Excluir cliente\n0 - Sair\nEscolha sua opcao:");
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            break;
        case 1:
            system("cls");
            CREATE();
            break;
        case 2:
            system("cls");
            READALL();
            break;
        case 3:
            system("cls");
            printf("Busca por ID: ");
            scanf("%d", &id);
            READ(id);
            break;
        case 4:
            system("cls");
            printf("Busca por ID: ");
            scanf("%d", &id);
            UPDATE(id);
            break;
        case 5:
            system("cls");
            printf("Exclusao por ID: ");
            scanf("%d", &id);
            DELETE(id);
            break;
        case 10:
            DELETEALL();
            break;
        }
    } while (op != 0);
    return 0;
}