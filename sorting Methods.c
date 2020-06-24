#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 5



long createVector(long v[], int);
long printVector(long v[], int);
void bubblesort(long v[], int);
long troca(long v[], int i, int j);
char menu();

int main(){
    long vector[TAM];
    int option;
    
    createVector(vector, TAM);
    printVector(vector, TAM);

    menu();
    scanf("%d", &option);
    //printf("\n%d", option);
    switch (option){
    case 1:
        printf("first option works");
        bubblesort(vector,TAM);
        printVector(vector, TAM);
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

void bubblesort(long v[], int t){
    for(int i = 0; i<t-1; i++){
        for(int j=i+1; i<t; j++){
            if(v[i] > v[j]){
                troca(v, i, j);
            }
        }
    }
}//end bubblesort

long troca(long *v, int i, int j){
    long *key = &v[i];
    v[i] = v[j];
    v[j] = *key;
}

char menu(){
    printf("\n1.Bublesort\n2.Selectionsort\n3.Insertionsort\n4.Shellsort\n0.Exit");
    printf("\nSelect an option: ");

}

long createVector(long v[], int t){
    for (int i=0; i<t; i++){
        v[i] = rand()/100 + 1;    }
}

long printVector(long v[], int t){
        printf("Vector: ");
    for (int i=0; i<t; i++){
        printf("%ld, ", v[i]);
    }
}

/* void bubble_sort(long[], long);

int main()
{
    long array[100], n, c, d, swap;

    printf("Enter number of elements\n");
    scanf("%ld", &n);

    printf("Enter %ld longegers\n", n);

    for (c = 0; c < n; c++)
        scanf("%ld", &array[c]);

    bubble_sort(array, n);

    printf("Sorted list in ascending order:\n");

    for (c = 0; c < n; c++)
        printf("%ld\n", array[c]);

    return 0;
}

void bubble_sort(long list[], long n)
{
    long c, d, t;

    for (c = 0; c < (n - 1); c++)
    {
        for (d = 0; d < n - c - 1; d++)
        {
            if (list[d] > list[d + 1])
            {
                /* Swapping */
/*
                t = list[d];
                list[d] = list[d + 1];
                list[d + 1] = t;
            }
        }
    }
} */