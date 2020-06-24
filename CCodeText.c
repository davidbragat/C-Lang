#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int a = 100;
    char name[] = "David";

    printf("%d, %s", a, name);

}