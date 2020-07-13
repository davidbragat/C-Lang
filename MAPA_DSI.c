#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define TAM 2048 //Vector max size

void headerField(int headerCount, char *value);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    system("cls");

    //Variáveis
    char strVec[TAM];
    char strVecTemp[TAM];

    int lineNumber = 0; 
    int headerCount = 0; 
    int doubleQuotes = 0;
    int strVecPosition = 0;
    int i = 0;

    FILE *csv = fopen("dados.csv", "r");

    if (!csv)
    {
        perror("Nao foi possivel abrir o arquivo.");
        return EXIT_FAILURE;
    }

    while (fgets(strVec, TAM, csv))
    {
        lineNumber++;

        if (lineNumber == 1)
        {
            continue;
        }

        headerCount = 0;
        i = 0;
        int displayControl = 0;

        do
        {
            strVecTemp[strVecPosition++] = strVec[i];

            if (!doubleQuotes && (strVec[i] == ',' || strVec[i] == '\n'))
            {
                strVecTemp[strVecPosition - 1] = 0;
                strVecPosition = 0;
                headerField(headerCount++, strVecTemp);
            }
            if (strVec[i] == '"' && strVec[i + 1] != '"')
            {
                strVecPosition--;
                doubleQuotes = !doubleQuotes;
            }
            if (strVec[i] == '"' && strVec[i + 1] == '"')
            {
                i++;
            }

        } while (strVec[++i]);

        printf("\n");
    }

    fclose(csv); //close file

    return 0;
}

void headerField(int headerCount, char *value)
{
    switch (headerCount)
    {
    case 0:
        printf("Código do Item:\t");
        break;

    case 1:
        printf("Descrição do Item:\t");
        break;

    case 2:
        printf("Grupo:\t");
        break;

    case 3:
        printf("Classe:\t");
        break;

    case 4:
        printf("PDM:\t");
        break;

    case 5:
        printf("Status:\t");
        break;

    case 6:
        printf("Sustentável");
        break;

    default:
        break;
    }
    printf("%s\n", value);
}