#include "..\include\semanticid.h"

void initRandomSeed(){
    srand(time(NULL));
}

int getCurrentYear()
{
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    return tm_info->tm_year + 1900;
}

void generateSuffix(char *suffix)
{
    int presetSize = strlen(SUFFIX_PRESET);

    for (int i = 0; i < SUFFIX_SIZE; i++)
    {
        int index = rand() % presetSize;
        suffix[i] = SUFFIX_PRESET[index];
    }

    suffix[SUFFIX_SIZE] = '\0';
}

void generateSemanticId(char *semanticId)
{
    char suffix[SUFFIX_SIZE + 1];
    int year = getCurrentYear();

    generateSuffix(suffix);

    sprintf(semanticId, "USER-%d-%s", year, suffix);
    printf("[%s]\n", suffix);
}