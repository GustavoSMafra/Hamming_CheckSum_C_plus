/*
    Quest�o 1
    C�digo aluno utilizado:  6845207
    Acad�micos: Gustavo da Silva Mafra
                Nath�lia Adriana de Oliveira
*/


#include <iostream>
#include <stdlib.h>
#include "Hamming.h"

using namespace std;

int main(){
    int op;
    int n2,n4,n5,n6,n8,n9,n10,n11;
    int i=1;

    setlocale(LC_ALL, "Portuguese");

    while(i=1){
        system("cls");
        cout<<"Digite a op��o desejada\n1. Palavra de 9 bits\n2. Palavra de 12 bits\n\nResposta:";
        cin>>op;

        if(op == 1 || op == 2){
            i = 0;
            break;
        }
        else{
            cout<<"\nOp��o inv�lida, tente novamente";
            Sleep(600);
        }
    }

    switch(op){
    case 1:
        entrada_n_9_5(n2,n4,n5,n6,n8);
       break;
    case 2:
        entrada_n_12_8(n2,n4,n5,n6,n8,n9,n10,n11);
       break;
    }

    return 0;
}
