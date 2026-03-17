#ifndef USER_H
#define USER_H

typedef struct {
    int id;
    char semanticId[50];
    char name[50];
    char email[50];
    int age;
} User;

#endif