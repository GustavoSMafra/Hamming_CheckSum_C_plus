/*
    Questão 2-A
    Código aluno utilizado:  6832750
    Acadêmicos: Gustavo da Silva Mafra
                Nathália Adriana de Oliveira
*/

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <string.h>
using namespace std;
#define tam 12

void input_word(int word1 [tam], int word2 [tam], int word3[tam]){

    string word;

    cout <<"\n\n\t Inserção de palavras para teste, elas devem possuir 12 bits (Ex.: 111111111111)";
    cout << "\n\n\nInsira o valor da 1 palavra: ";
    cin >> word;
    for(int i = 0; i < 12; i++){
        word1[i] = word[i] - 48;
    }
    cout << "\nInsira o valor da 2 palavra: ";
    cin >> word;
    for(int i = 0; i < 12; i++){
        word2[i] = word[i] - 48;
    }
    cout << "\nInsira o valor da 3 palavra: ";
    cin >> word;
    for(int i = 0; i < 12; i++){
        word3[i] = word[i] - 48;
    }
}

void print_word(int word [tam]){

    for(int i = 0; i < tam; i++){
        cout << word[i] << " ";
    }

}

void binary_sum(int word1 [tam], int word2 [tam], int sum[tam]){
    int overflow_sum[tam] = {0,0,0,0,0,0,0,0,0,0,0,1};
    int overflow = 0;

    for(int i = tam-1; i >= 0; i--){
        sum[i] = word1[i] + word2[i] + overflow;
        if(sum[i] > 2){ // 1 + 1 + 1 (Soma de 1+1 com overflow)
            sum[i] = 1;
        }
        else if (sum[i] > 1){ // 1 + 1 (Soma de 1+1 adicionando overflow)
            sum[i] = 0;
            overflow = 1;
        }
        else if (overflow == 1) { // 0 + 0 + 1 (Soma de 0+0 com overflow)
            overflow = 0;
        }
    }

    if(overflow != 0){ // Em caso de overflow chamamos novamente a função
        binary_sum(sum, overflow_sum, sum);
    }
}

void inverter(int word[tam], int edc[tam]){
    for(int i = 0; i < tam; i++){ // Inverte todos os bits de uma palavra
        if(word[i] == 0){
            edc[i] = 1;
        } else {
            edc[i] = 0;
        }
    }
}

void bit_flip(int word[tam], int num){
    int i = rand()%12; // Randomiza a posição do bit

    if(word[i] == 1){
        word[i] = 0;
    } else  {
        word[i] = 1;
    }

    cout << "\nA inserção da falha foi no bit " << i+1 << ", da " << num << " palavra";
    cout << "\n\nPalavra após a inserção = ";
    print_word(word);
}

bool verify_fault(int verify[tam]){
    for(int i = 0; i < 12; i++){ // Caso algum bit seja diferente de 1 é retornado false afirmando que há falta
        if(verify[i] != 1){
            return false;
        }
    }
    return true;
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    int word1[tam] = {}, word2[tam] = {}, word3[tam] = {};
    int sum1[tam] = {}, sum2[tam] = {}, edc[tam] = {}, verify[tam] = {};
    bool state;

    srand(time(NULL));

    //Bloco Input
    input_word(word1, word2, word3);
    cout << "\n\n";
    system("pause");
    system("cls");


    //Bloco de impressão
    cout << "\nWord 1 = " << endl;
    print_word(word1);
    cout << "\n\nWord 2 = " << endl;
    print_word(word2);
    cout << "\n\nWord 3 = " << endl;
    print_word(word3);

    cout << "\n\n";
    system("pause");
    system("cls");

    //Somas
    cout << "Somatórios\n\n";
    cout << "\nSum1 = ";
    cout << "\t";
    print_word(word1);
    cout << "\n\t";
    print_word(word2);
    cout << "\n\t_______________________";
    binary_sum(word1, word2, sum1); // Soma word 1 + word 2
    cout << "\n\t";
    print_word(sum1);

    cout << "\n\n\nSum2 = \t";
    print_word(sum1);
    cout << "\n\t";
    print_word(word3);
    cout << "\n\t_______________________";
    binary_sum(sum1, word3, sum2); // Soma word 3 + resultado da soma de word 1 + word 2
    cout << "\n\t";
    print_word(sum2);

    //Edc
    inverter(sum2, edc);
    cout << "\n\nEdc = \t";
    print_word(edc);

    cout << "\n\n";
    system("pause");
    system("cls");

    //Injeção de erro
    int i = rand()%3;
    if(i == 1){
        bit_flip(word1, 1);
    }
    else if(i == 2){
        bit_flip(word2, 2);
    } else {
        bit_flip(word3, 3);
    }

    //Somas após a injeção
    cout << "\n\nSomatórios\n\n";
    cout << "\nSum1 = ";
    cout << "\t";
    print_word(word1);
    cout << "\n\t";
    print_word(word2);
    cout << "\n\t_______________________";
    binary_sum(word1, word2, sum1); // Soma word 1 + word 2
    cout << "\n\t";
    print_word(sum1);

    cout << "\n\n\nSum2 = \t";
    print_word(sum1);
    cout << "\n\t";
    print_word(word3);
    cout << "\n\t_______________________";
    binary_sum(sum1, word3, sum2); // Soma word 3 + resultado da soma de word 1 + word 2
    cout << "\n\t";
    print_word(sum2);

    cout << "\n\n\nSEdc = \t";
    print_word(sum2);
    cout << "\n\t";
    print_word(edc);
    cout << "\n\t_______________________";
    binary_sum(sum2, edc, verify); // Somatório com EDC para verificação
    cout << "\n\t";
    print_word(verify);

    state = verify_fault(verify); // Estado falso ou verdadeiro

    // Mensagens para o usuário final
    if(state == true){
        cout << "\n\nMensagem recebida sem erros já que a soma com EDC (SEdc) possui apenas bits 1";
    } else {
        cout << "\n\nA mensagem possui uma falha já que a soma com EDC (SEdc) não possui apenas bits 1";
    }

    cout << "\n\n\n";
}
