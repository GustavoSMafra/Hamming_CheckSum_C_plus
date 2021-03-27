/*
    Questão 1
    Código aluno utilizado:  6845207
    Acadêmicos: Gustavo da Silva Mafra
                Nathália Adriana de Oliveira
*/

#ifndef HAMMING_H_INCLUDED
#define HAMMING_H_INCLUDED

#include <windows.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//HAMMING DOS 3 DIGITOS DO CÓDIGO DE ALUNO
void hamming9_5(int n2,int n4,int n5,int n6,int n8){
    int pd[9],p0,p1,p2,p3,k0,k1,k2,k3,posicao;

    pd[2] = n2;  //x3
    pd[4] = n4;  //x5
    pd[5] = n5;  //x6
    pd[6] = n6;  //x7
    pd[8] = n8;  //x9

    //VALORES DE REDUNDANCIA
    p0 = pd[2]^pd[4]^pd[6]^pd[8]; //p1 = (x3)XOR(x5)XOR(x7)XOR(x9)
    p1 = pd[2]^pd[5]^pd[6];       //p2 = (x2)XOR(x3)XOR(x6)XOR(x7)
    p2 = pd[4]^pd[5]^pd[6];       //p3 = (x4)XOR(x5)XOR(x6)XOR(x7)
    p3 = pd[8];                   //p4 = (x8)

    pd[0]= p0; //x1
    pd[1]= p1; //x2
    pd[3]= p2; //x4
    pd[7]= p3; //x8

    //EXIBICAO DA MENSAGEM PRO USUARIO
    cout<<endl;
    cout<<"Mensagem: ";
    for(int i = 0;i<9;i++){
        cout<<" | "<<pd[i];
    }
    cout<<" |";

    Sleep(2000);
    //INJECAO DE ERROS
    int inj_1_2;
    int pos_alterar,pos_alterar2;
    while(int i = 1){
        system("cls");
        cout<<"Injeção de erro\n";
        cout<<"1. Para alterar 1 bit\n2. Para alterar 2 bits\n\nResposta:";
        cin>>inj_1_2;

        if(inj_1_2 == 1 || inj_1_2 == 2){
            i=0;
            break;
        }
        else{
            cout<<"\nOpção errada, tente novamente";
            Sleep(600);
        }
    }

    system("cls");

    while(int i = 1){
        if(inj_1_2 == 1){
            system("cls");
            cout<<"Digite a posição do bit a ser alterada(Opções = 3,5,6,7,9)\nResposta:";
            cin>>pos_alterar;

            if(pos_alterar == 3 || pos_alterar == 5 || pos_alterar == 6 || pos_alterar == 7 || pos_alterar == 9){
                cout<<endl;
                cout<<"Mensagem sem alteração: ";
                for(int i = 0;i<9;i++){
                    cout<<" | "<<pd[i];
                }
                cout<<" |";

                if(pd[pos_alterar-1] == 1){
                    pd[pos_alterar-1] = 0;
                }
                else{
                    pd[pos_alterar-1] = 1;
                }

            //EXIBICAO DA MENSAGEM APOS A ALTERACAO DO BIT
            cout<<endl;
            cout<<"Mensagem com alteração: ";
            for(int i = 0;i<9;i++){
                cout<<" | "<<pd[i];
            }
            cout<<" |";

            //DETECCAO DE ERRO
            k0 = pd[0]^pd[2]^pd[4]^pd[6]^pd[8]; //k0 = (x1)XOR(x2)XOR(x5)XOR(x7)
            k1 = pd[1]^pd[2]^pd[5]^pd[6];       //k1 = (x2)XOR(x3)XOR(x6)XOR(x7)
            k2 = pd[3]^pd[4]^pd[5]^pd[6];       //k3 = (x4)XOR(x5)XOR(x6)XOR(x7)
            k3 = pd[7]^pd[8];                   //k7 = (x8)XOR(x9)XOR(x10)XOR(x11)

            cout<<"\n\nCálculo de detecção de erro:"<<k3<<k2<<k1<<k0;

            if((k0 == 0) && (k1 == 0) && (k2 == 0) && (k3 == 0)){
                cout<<"\nSem erros"<<endl;
            }
            else{
                cout<<"\tErro\n"<<endl;
                posicao = (k0*1) + (k1*2) + (k2*4) + (k3*6); //Conversão de binário para decimal = multiplicar o numero pela sua base
                                                             // k0 = k¹, k1 = k², k3 = k^4, k7 = k^6
                cout<<"Posição:"<<(posicao)<<"\n\n";         //EXIBICAO DA POSICAO DO ERRO PRO USUARIO
                cout<<"Correção do erro...\n";

                if(pd[posicao-1] == 0){
                    pd[posicao-1] = 1;
                }
                else{
                    pd[posicao-1] = 0;
                }

                cout<<"Mensagem corrigida: ";
                for(int i = 0;i<9;i++){
                    cout<<" | "<<pd[i];
                }
                cout<<" |";
             }
            i=0;
            break;
            }
            else{
                cout<<"\nPosição inválida, tente novamente";
                Sleep(1000);
            }

       }
        else if(inj_1_2 == 2){
                system("cls");
                cout<<"Digite a posição do bit a ser alterada(Opçôes = 3,5,6,7,9)\nResposta 1:";
                cin>>pos_alterar;
                cout<<"Resposta 2:";
                cin>>pos_alterar2;

                if((pos_alterar == 3 || pos_alterar == 5 || pos_alterar == 6 || pos_alterar == 7 || pos_alterar == 9)&&
                   (pos_alterar2 == 3 || pos_alterar2 == 5 || pos_alterar2 == 6 || pos_alterar2 == 7 || pos_alterar2 == 9)){

                cout<<endl;
                cout<<"Mensagem sem alteração: ";
                for(int i = 0;i<9;i++){
                    cout<<" | "<<pd[i];
                }
                cout<<" |";

                    if(pd[pos_alterar-1] == 1){
                        pd[pos_alterar-1] = 0;

                        if(pd[pos_alterar2-1] == 1){
                            pd[pos_alterar2-1] = 0;
                        }
                        else{
                            pd[pos_alterar2-1] = 1;
                        }
                    }
                    else{
                        pd[pos_alterar-1] = 1;

                        if(pd[pos_alterar2-1] == 1){
                            pd[pos_alterar2-1] = 0;
                        }
                        else{
                            pd[pos_alterar2-1] =1;
                        }
                    }

                //EXIBICAO DA MENSAGEM APOS A ALTERACAO DO BIT
                cout<<endl;
                cout<<"Mensagem com alteração: ";
                for(int i = 0;i<9;i++){
                    cout<<" | "<<pd[i];
                }
                cout<<" |";

                //DETECCAO DE ERRO
                k0 = pd[0]^pd[2]^pd[4]^pd[6]^pd[8]; //k0 = (x1)XOR(x2)XOR(x5)XOR(x7)
                k1 = pd[1]^pd[2]^pd[5]^pd[6];       //k1 = (x2)XOR(x3)XOR(x6)XOR(x7)
                k2 = pd[3]^pd[4]^pd[5]^pd[6];       //k3 = (x4)XOR(x5)XOR(x6)XOR(x7)
                k3 = pd[7]^pd[8];                   //k7 = (x8)XOR(x9)XOR(x10)XOR(x11)

                cout<<"\n\nCálculo de detecção de erro:"<<k3<<k2<<k1<<k0;

                if((k0 == 0) && (k1 == 0) && (k2 == 0) && (k3 == 0)){
                    cout<<"\nSem erros"<<endl;
                }
                else{
                    cout<<"\n\nPossui 2 erros, logo não é possivel detectar\n"<<endl;
                }
                i=0;
                break;

            }
            else{
                cout<<"\nPosição inválida, tente novamente";
                Sleep(1000);
            }
        }
        else{
            cout<<"Número inválido, tente novamente";
            Sleep(1000);

        }
    }
}


void entrada_n_9_5(int n2,int n4,int n5,int n6,int n8){
    int i = 1;
    system("cls");
    while(i == 1){
        cout<<"Entre com a palavra de dados de 5 bits:"<<endl;
        cin>>n2>>n4>>n5>>n6>>n8;

        if((n2 <= 1)&&(n4 <= 1)&&(n5 <= 1)&&(n6 <= 1)&&(n8 <= 1)){
            hamming9_5(n2,n4,n5,n6,n8);
            i=0;
            break;
        }
        else{
            cout<<"Número inválido, tente novamente\n\n";
        }
    }
}


void hamming12_8(int n2,int n4,int n5,int n6,int n8,int n9,int n10,int n11){
    int pd[12],p0,p1,p2,p3,k0,k1,k2,k3;
    int posicao;

    pd[2]  = n2;  //x3
    pd[4]  = n4;  //x5
    pd[5]  = n5;  //x6
    pd[6]  = n6;  //x7
    pd[8]  = n8;  //x9
    pd[9]  = n9;  //x10
    pd[10] = n10; //x11
    pd[11] = n11; //x12

    //VALORES DE REDUNDANCIA
    p0 = pd[2]^pd[4]^pd[6]^pd[8]^pd[10]; //p1 = (x3)XOR(x5)XOR(x7)XOR(x9)XOR(x11)
    p1 = pd[2]^pd[5]^pd[6]^pd[9]^pd[10]; //p2 = (x2)XOR(x3)XOR(x6)XOR(x7)XOR(x10)XOR(x11)
    p2 = pd[4]^pd[5]^pd[6]^pd[11];       //p3 = (x4)XOR(x5)XOR(x6)XOR(x7)XOR(x12)
    p3 = pd[8]^pd[9]^pd[10]^pd[11];      //p4 = (x8)XOR(x9)XOR(x10)XOR(x11)XOR(x12)

    pd[0]= p0; //x1
    pd[1]= p1; //x2
    pd[3]= p2; //x4
    pd[7]= p3; //x8

    //EXIBICAO DA MENSAGEM PRO USUARIO
    cout<<endl;
    cout<<"Mensagem: ";
    for(int i = 0;i<12;i++){
        cout<<" | "<<pd[i];
    }
    cout<<" |";

    int inj_1_2=0;
    int pos_alterar,pos_alterar2;

    system("cls");
    //INJECAO DE ERROS
    while(int i = 1){
        cout<<"Injeção de erro\n";
        cout<<"1. Para alterar 1 bit\n2. Para alterar 2 bits\n\nResposta:";
        cin>>inj_1_2;

        if(inj_1_2 == 1 || inj_1_2 == 2){
            i=0;
            break;
        }
        else{
            cout<<"\nOpção errada, tente novamente";
            Sleep(600);
            system("cls");
        }
    }

    while(int i = 1){
        if(inj_1_2 == 1){
            system("cls");
            cout<<"Digite a posição do bit a ser alterada(Opções = 3,5,6,7,9,11,12)\nResposta:";
            cin>>pos_alterar;

            if(pos_alterar == 3 || pos_alterar == 5 || pos_alterar == 6 || pos_alterar == 7 || pos_alterar == 9 || pos_alterar == 10 || pos_alterar == 11 || pos_alterar == 12){
                cout<<endl;
                cout<<"Mensagem sem alteração: ";
                for(int i = 0;i<12;i++){
                    cout<<" | "<<pd[i];
                }
                cout<<" |";

                if(pd[pos_alterar-1] == 1){
                    pd[pos_alterar-1] = 0;
                }
                else{
                    pd[pos_alterar-1] = 1;
                }
                cout<<endl;
                cout<<"Mensagem com alteração: ";
                for(int i = 0;i<12;i++){
                    cout<<" | "<<pd[i];
                }
                cout<<" |";

                //DETECCAO DE ERRO
                k0 = pd[0]^pd[2]^pd[4]^pd[6]^pd[8]^pd[10]; //k0 = (x1)XOR(x2)XOR(x5)XOR(x7)XOR(x9)XOR(x11)
                k1 = pd[1]^pd[2]^pd[5]^pd[6]^pd[9]^pd[10]; //k1 = (x2)XOR(x3)XOR(x6)XOR(x7)XOR(x10)XOR(x11)
                k2 = pd[3]^pd[4]^pd[5]^pd[6]^pd[11];       //k3 = (x4)XOR(x5)XOR(x6)XOR(x7)XOR(x12)
                k3 = pd[7]^pd[8]^pd[9]^pd[10]^pd[11];      //k7 = (x8)XOR(x9)XOR(x10)XOR(x11)XOR(x12)

                cout<<"\n\nCalculo de deteccao de erro:"<<k3<<k2<<k1<<k0;

                if((k0 == 0) && (k1 == 1) && (k2 == 0) && (k3 == 0)){
                    cout<<"\n\nSem erros"<<endl;
                }
                else{
                    cout<<"\tErro\n"<<endl;
                    posicao = (k0*1) + (k1*2) + (k2*4) + (k3*6); //Conversão de binário para decimal = multiplicar o numero pela sua base
                                                                // k0 = k¹, k1 = k², k3 = k^4, k7 = k^6
                    cout<<"Posição:"<<(posicao)<<"\n\n";
                    cout<<"Correção do erro...\n";

                    if(pd[posicao-1] == 0){
                        pd[posicao-1] = 1;
                    }
                    else{
                        pd[posicao-1] = 0;
                    }

                    cout<<"Mensagem corrigida: ";
                    for(int i = 0;i<12;i++){
                        cout<<" | "<<pd[i];
                    }
                    cout<<" |"<<endl;
                }

                i=0;
                break;
            }
            else{
                cout<<"\nPosicao inválida, tente novamente";
                Sleep(1000);
                }
            }
            else if(inj_1_2 == 2){
                system("cls");
                cout<<"Digite as posições dos bits a serem alteradas(Opções = 3,5,6,7,9,11,12)\nResposta 1:";
                cin>>pos_alterar;
                cout<<"\nResposta 2:";
                cin>>pos_alterar2;

                if((pos_alterar == 3 || pos_alterar == 5 || pos_alterar == 6 || pos_alterar == 7 || pos_alterar == 9 || pos_alterar == 10 || pos_alterar == 11 || pos_alterar == 12)&&
                   (pos_alterar2 == 3 || pos_alterar2 == 5 || pos_alterar2 == 6 || pos_alterar2 == 7 || pos_alterar2 == 9 || pos_alterar2 == 10 || pos_alterar2 == 11 || pos_alterar2 == 12)){

                    cout<<endl;
                    cout<<"Mensagem sem alteração: ";
                    for(int i = 0;i<12;i++){
                        cout<<" | "<<pd[i];
                    }
                    cout<<" |";

                    if(pd[pos_alterar-1] == 1){
                        pd[pos_alterar-1] = 0;

                        if(pd[pos_alterar2-1] == 1){
                            pd[pos_alterar2-1] = 0;
                        }
                        else{
                            pd[pos_alterar2-1] = 1;
                        }
                    }
                    else{
                        pd[pos_alterar-1] = 1;

                        if(pd[pos_alterar2-1] == 1){
                            pd[pos_alterar2-1] = 0;
                        }
                        else{
                            pd[pos_alterar2-1] = 1;
                        }
                    }

                cout<<endl;
                cout<<"Mensagem com alteração: ";
                for(int i = 0;i<12;i++){
                    cout<<" | "<<pd[i];
                }
                cout<<" |";

                //DETECCAO DE ERRO
                k0 = pd[0]^pd[2]^pd[4]^pd[6]^pd[8]^pd[10]; //k0 = (x1)XOR(x2)XOR(x5)XOR(x7)XOR(x9)XOR(x11)
                k1 = pd[1]^pd[2]^pd[5]^pd[6]^pd[9]^pd[10]; //k1 = (x2)XOR(x3)XOR(x6)XOR(x7)XOR(x10)XOR(x11)
                k2 = pd[3]^pd[4]^pd[5]^pd[6]^pd[11];       //k3 = (x4)XOR(x5)XOR(x6)XOR(x7)XOR(x12)
                k3 = pd[7]^pd[8]^pd[9]^pd[10]^pd[11];      //k7 = (x8)XOR(x9)XOR(x10)XOR(x11)XOR(x12)

                cout<<"\n\nCalculo de deteccao de erro:"<<k3<<k2<<k1<<k0;


                if((k0 == 0) && (k1 == 0) && (k2 == 0) && (k3 == 0)){
                    cout<<"\nSem erros"<<endl;
                }
                else{
                    cout<<"\n\nPossui 2 erros, logo não é possivel detectar\n"<<endl;
                }
                i=0;
                break;
            }
            else{
                cout<<"\nNúmero inválido, tente novamente";
                Sleep(600);

            }
        }
    }
}


void entrada_n_12_8(int n2,int n4,int n5,int n6,int n8,int n9,int n10,int n11){
    int i = 1;
    system("cls");
    while(i = 1){
        cout<<"Entre com a palavra de dados de 8 bits"<<endl;
        cin>>n2>>n4>>n5>>n6>>n8>>n9>>n10>>n11;

        if((n2 <= 1)&&(n4 <= 1)&&(n5 <= 1)&&(n6 <= 1)&&(n8 <= 1)&&(n9 <= 1)&&(n10 <= 1)&&(n11 <= 1)){
            hamming12_8(n2,n4,n5,n6,n8,n9,n10,n11);
            i=0;
            break;
        }
        else{
            cout<<"Número inválido, tente novamente\n\n";
        }
    }
}


#endif // HAMMING_H_INCLUDED
