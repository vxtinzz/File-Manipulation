#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[50];
    char email[50];
    int age;
} User;
// Create
void CREATE()
{
    User usuario;
    int lastId = 0;
    FILE *arq;

    arq = fopen("register.txt", "r");
    if (arq != NULL)
    {
        while (fscanf(arq, "%d;%49[^;];%49[^;];%d\n",
                      &usuario.id, usuario.name, usuario.email, &usuario.age) != EOF)
        {
            lastId = usuario.id;
        }
        fclose(arq);
    }

    arq = fopen("register.txt", "a");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    printf("Nome: ");
    scanf("%s", usuario.name);
    printf("Email: ");
    scanf("%s", usuario.email);
    printf("Idade: ");
    scanf("%d", &usuario.age);
    usuario.id = lastId + 1;
    fprintf(arq, "%d;%s;%s;%d\n", usuario.id, usuario.name, usuario.email, usuario.age);
    fclose(arq);
    printf("Usuario Adicionado!!");
}
// Read
void READ(int id)
{
    User usuario;
    FILE *arq;
    arq = fopen("register.txt", "r");
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
// ReadALL
void READALL()
{
    User usuario;
    FILE *arq;
    arq = fopen("register.txt", "r");
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
// Update
void UPDATE(int id)
{
    User usuario;
    FILE *arq, *temp;
    arq = fopen("register.txt", "r");
    temp = fopen("temp.txt", "a");
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

    remove("register.txt");
    rename("temp.txt", "register.txt");

    printf("Registro Atualizado com sucesso.\n");
}
// Delete
void DELETE(int id)
{
    User usuario;
    FILE *arq, *temp;
    arq = fopen("register.txt", "r");
    temp = fopen("temp.txt", "a");
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

    remove("register.txt");
    rename("temp.txt", "register.txt");

    printf("Registro removido com sucesso.\n");
}
// Delete ALL
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
        remove("register.txt");
        arq = fopen("register.txt", "w+");
        fclose(arq);
    }
}
int main()
{
    int op, id;
    printf("==Sistema de Clientes==\n");
    do
    {
        printf("\n1 - Cadastrar cliente\n2 - Listar clientes\n3 - Buscar cliente por ID\n4 - Editar cliente\n5 - Excluir cliente\n0 - Sair\n Escolha sua opcao:");
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
