#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 5

long createVector(long v[], int);
long printVector();
void bubblesort();
long troca(int i, int j);
char menu();

long vector[TAM];
int main()
{
    int option;

    createVector(vector, TAM);
    printVector(TAM);

    menu();
    scanf("%d", &option);
    //printf("\n%d", option);
    switch (option)
    {
    case 1:
        printf("first option works");
        bubblesort();
        printVector(TAM);
        break;
    case 2:
        printf("second option works");
        // selectionsort(vector, TAM);
        break;
    case 3:
        printf("third option works");
        // insertionsort(vector, TAM);
        break;
    case 4:
        printf("fourth option works");
        // shellsort(vector, TAM);
        break;
    default:
        break;
    }
}

void bubblesort()
{
    for (int i = 0; i < TAM - 1; i++)
    {
        for (int j = i + 1; j < TAM; j++)
        {
            if (vector[i] > vector[j])
            {
                troca(i, j);
            }
        }
    }

} //end bubblesort

long troca(int i, int j)
{
    int key = vector[i];
    vector[i] = vector[j];
    vector[j] = key;
}

char menu()
{
    printf("\n1.Bublesort\n2.Selectionsort\n3.Insertionsort\n4.Shellsort\n0.Exit");
    printf("\nSelect an option: ");
}

long createVector(long v[], int t)
{
    for (int i = 0; i < t; i++)
    {
        v[i] = rand() % 17 + 1;
    }
}

long printVector()
{
    printf("Vector: ");
    for (int i = 0; i < TAM; i++)
    {
        printf("%ld, ", vector[i]);
    }
}