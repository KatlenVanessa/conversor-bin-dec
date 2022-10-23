// Autor: Katlen Vanessa
// Eletronica Digital
/*Faça uma codificação em uma linguagem de programação, ao seu critério de escolha,
que mostre o complemento a 1 e complemento a 2 de determinado número como valor de
entrada. Além disso, considerando 8 bits, mostre qual o número decimal que o
complemento a 2, calculado anteriormente, identifica. Mostre visualmente as etapas
necessárias.*/

#include <stdio.h>
#include <math.h>

#define index 8

void inicia(int *binario);
void imprime(int *binario);
void verifica(int numero, int *binario);
void soma_binaria(int numBin1[], int binario[], int *soma);
void dec_bin(int num, int *binario);
void c2_dec(int numero);
void c1(int *binario);
void c2(int *binario);

int main()
{
    int numero, binario[index];

    printf("\n\tEntrada: ");
    scanf("%d", &numero);

    inicia(binario);
    verifica(numero, binario);

    return 0;
}

// Verifica o valor digitado
void verifica(int numero, int *binario)
{

    if ((numero >= -127) && (numero <= 255))
    {
        if (numero < 0)
        {
            numero = numero * (-1);
        }
        dec_bin(numero, binario);
        printf("\n\tBinario: \n\t");
        imprime(binario);
        c1(binario);
        printf("\n\tC1: \n\t");
        imprime(binario);
        c2(binario);
        c2_dec(numero);
    }
    else
    {
        printf("\n\tEntrada invalida!\n");
    }
}

// Realiza a operacao de soma binaria com portas logicas
void soma_binaria(int numBin1[], int binario[], int *soma)
{
    int carry = 0;
    int i;
    for (i = 0; i < index; i++)
    {
        soma[i] = (binario[i] ^ numBin1[i]) ^ carry;                              // resultado= (A XOR B) XOR carry-in.
        carry = (binario[i] && numBin1[i]) || carry && (binario[i] ^ numBin1[i]); // carry-out = A.B + carry-in.(A XOR B)
        // Circuito: https://www.electronics-tutorials.ws/wp-content/uploads/2018/05/combination-comb20.gif
    }
}

// Realiza o complemento a 1
void c1(int *binario)
{
    int i;
    for (i = 0; i < index; i++)
    {
        binario[i] = !(binario[i]);
    }
}

// Realiza o complemento a 2
void c2(int *binario)
{
    int numBin1[index], soma[index];
    inicia(soma);
    inicia(numBin1);
    numBin1[0] = 1;
    soma_binaria(numBin1, binario, soma);
    printf("\n\tC2: \n\t");
    imprime(soma);
}

// Realiza a conversao de decimal para binario de 8 bits
void dec_bin(int num, int *binario)
{
    int i = 0;
    while (num != 0)
    {
        binario[i] = num % 2;
        num = num / 2;
        i++;
    }
}

// Considerando 8 bits, mostra o decimal que o complemento a 2, calculado anteriormente, identifica.
void c2_dec(int numero)
{
    --numero;
    int numBin[index];
    inicia(numBin);
    dec_bin(numero, numBin);
    c1(numBin);
    int i;
    double soma, res;
    for (i = index - 1; i >= 0; i--)
    {
        if (numBin[i] == 1)
        {
            double pot = i;
            soma = pow(2, pot);
            res += soma;
        }
    }
    res -= 128;
    printf("\n\tC2 para decimal: \n\t%.0f", res);
}

// Inicia um vetor com 0s para guardar o binario
void inicia(int *binario)
{
    int i;
    for (i = 0; i < index; i++)
    {
        binario[i] = 0;
    }
}

// Imprime o binario
void imprime(int *binario)
{
    int i;
    for (i = index - 1; i >= 0; i--)
    {
        printf("%d", binario[i]);
    }
}