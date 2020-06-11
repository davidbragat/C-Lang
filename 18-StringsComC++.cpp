#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

//Fun��o principal do programa
int main(){
    int a = 100;
    int b = 200;
    //Definindo uma String
    string palavra;

    //Imrpimindo na tela
    cout << "Digite uma palavra";

    //Lendo uma string
    cin >> palavra;

    //Imprimindo uma vari�vel
    cout << "\nA palavra eh:" << palavra;

    //Pausa o programa ap�s executar
    system("pause");

    return 0;

}

