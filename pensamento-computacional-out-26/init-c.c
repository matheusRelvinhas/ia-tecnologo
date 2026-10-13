#include <stdio.h>

float helloWorld() {
   return printf("Hello World!");
}

float averageScore(float num1, float num2) {
    float average = (num1 + num2) / 2;
    if (average > 6) {
        return printf("Aprovado");
    } else {
        return printf("Reprovado");
    }
}

int main() {
    helloWorld();
    printf("\n");
    averageScore(5, 7);
    printf("\n");
    averageScore(4, 6);
    printf("\n");
    averageScore(8, 9);
    printf("\n");
    return 0;
}

//use "gcc init-c.c -o init-c.exe" to compile the code and run it with "./init-c.exe"
// gcc init-c.c -o init-c.exe
// ./init-c.exe