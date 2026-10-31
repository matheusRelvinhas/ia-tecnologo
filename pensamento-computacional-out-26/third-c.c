#include <stdio.h>
 
#define DIAS 7
 
void exibir_relatorio(int almocos[], char dias_semana[][15], float preco_prato) {
    for (int i = 0; i < DIAS; i++) {
        float faturamento = almocos[i] * preco_prato;
        printf("%s - %d pratos vendidos - Faturamento %.2f reais\n",
               dias_semana[i], almocos[i], faturamento);
    }
}
 
int main() {
    int almocos[DIAS] = {7, 12, 9, 15, 20, 18, 5};
    char dias_semana[DIAS][15] = {
        "Segunda-feira", "Terca-feira", "Quarta-feira", "Quinta-feira",
        "Sexta-feira", "Sabado", "Domingo"
    };
    float preco_prato = 10.0;
    printf("=== Relatorio semanal de almocos ===\n\n");
    exibir_relatorio(almocos, dias_semana, preco_prato);
    return 0;
}

//use "gcc third-c.c -o third-c.exe" to compile the code and run it with "./third-c.exe"
// gcc third-c.c -o third-c.exe
// ./third-c.exe