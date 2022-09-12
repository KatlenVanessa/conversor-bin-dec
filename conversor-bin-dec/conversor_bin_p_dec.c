// Autor: Katlen Vanessa
// Programa que converte um numero decimal com sinal para binario usando

#include <stdio.h>
#include <math.h>

#define index 8

void inicia(int *binario);
void imprime(int *binario);
void verifica(int numero, int *binario);
void soma_binaria(int numBin1[], int binario[], int *soma);
void dec_bin(int num, int *binario);
void bin_dec(int numero, int binario[]);
void c1(int *binario);
void c2(int *binario);

int main()
{
    int numero, binario[index];

    printf("\n\tDecimal: ");
    scanf("%d", &numero);

    inicia(binario);
    verifica(numero, binario);

    return 0;
}

void verifica(int numero, int *binario)
{

    if ((numero >= -127) || (numero <= 127))
    {
        if (numero < 0)
        {
            numero = numero * (-1);
        }
        printf("\n\tEntrada: %d", numero, " \n");

        dec_bin(numero, binario);
        c1(binario);
        c2(binario);
        bin_dec(numero, binario);
    }
    else
    {
        printf("\n\tNumero invalido!\n");
    }
}

void soma_binaria(int numBin1[], int binario[], int *soma)
{
    int carry = 0;
    int i;
    for (i = 0; i < index; i++)
    {
        soma[i] = (binario[i] ^ numBin1[i]) ^ carry;
        carry = (binario[i] && numBin1[i]) || carry && (binario[i] ^ numBin1[i]);
    }
}

void c1(int *binario)
{
    int i;
    for (i = 0; i < index; i++)
    {
        binario[i] = !(binario[i]);
    }
    printf("\n\tC1: \n\t");
    imprime(binario);
}

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

void dec_bin(int num, int *binario)
{
    int i = 0;
    while (num != 0)
    {
        binario[i] = num % 2;
        num = num / 2;
        i++;
    }
    printf("\n\tBinario: \n\t");
    imprime(binario);
}

void bin_dec(int numero, int numBin[])
{
    int i;
    double soma;
    for (i = index - 1; i >= 1; i--)
    {
        if (numBin[i] == 1)
        {
            double pot = i;
            soma = pow(2.0, pot);
            soma += soma;
        }
    }

    printf("\n\tDecimal: %.0f\n", soma, "\n\t");
}

void inicia(int *binario)
{
    int i;
    for (i = 0; i < index; i++)
    {
        binario[i] = 0;
    }
}

void imprime(int *binario)
{
    int i;
    for (i = index - 1; i >= 0; i--)
    {
        printf("%d", binario[i]);
    }
}