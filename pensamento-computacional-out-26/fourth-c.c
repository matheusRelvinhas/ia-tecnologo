#include <stdio.h>

#define TAMANHO 10

void exibir_precos(float precos[]) {
    for (int i = 0; i < TAMANHO; i++) {
        printf("Produto %d: R$ %.2f\n", i + 1, precos[i]);
    }
    printf("\n");
}

void ordenar_crescente(float precos[]) {
    for (int i = 0; i < TAMANHO - 1; i++) {
        for (int j = 0; j < TAMANHO - i - 1; j++) {
            if (precos[j] > precos[j + 1]) {
                float temp = precos[j];
                precos[j] = precos[j + 1];
                precos[j + 1] = temp;
            }
        }
    }
}

void ordenar_decrescente(float precos[]) {
    for (int i = 0; i < TAMANHO - 1; i++) {
        for (int j = 0; j < TAMANHO - i - 1; j++) {
            if (precos[j] < precos[j + 1]) {
                float temp = precos[j];
                precos[j] = precos[j + 1];
                precos[j + 1] = temp;
            }
        }
    }
}

int main() {
    float precos[TAMANHO] = {12.99, 4.50, 27.90, 8.75, 3.29, 19.90, 6.49, 15.00, 2.99, 9.80};

    printf("=== Precos originais (nao ordenados) ===\n");
    exibir_precos(precos);

    ordenar_crescente(precos);
    printf("=== Precos em ordem crescente ===\n");
    exibir_precos(precos);

    ordenar_decrescente(precos);
    printf("=== Precos em ordem decrescente ===\n");
    exibir_precos(precos);

    return 0;
}

//use "gcc fourth-c.c -o fourth-c.exe" to compile the code and run it with "./fourth-c.exe"
// gcc fourth-c.c -o fourth-c.exe
// ./fourth-c.exe