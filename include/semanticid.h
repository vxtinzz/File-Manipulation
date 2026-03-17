#ifndef SEMANTIC_ID_H
#define SEMANTIC_ID_H
#define SUFFIX_PRESET "ABCDEFGHIJKLMNOPQ1234567890"
#define SUFFIX_SIZE 8
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int getCurrentYear();
void generateSuffix(char *suffix);
void generateSemanticId(char *semanticId);
void initRandomSeed();

#endif