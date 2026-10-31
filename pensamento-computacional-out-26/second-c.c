#include <stdio.h>

void responder(int opcao) {
    switch (opcao) {
        case 1:
            printf("Bot: Ola! Como posso te ajudar hoje?\n");
            break;
        case 2:
            printf("Bot: Obrigado pelo contato. Ate logo!\n");
            break;
        default:
            printf("Bot: Opcao invalida! Digite 1 ou 2.\n");
    }

    if (opcao == 1) {
        printf("Bot: Posso ajudar em algo mais?\n");
    } else if (opcao == 2) {
        printf("Bot: Atendimento encerrado.\n");
    }
}

int main() {
    responder(1);
    printf("\n");
    responder(2);
    printf("\n");
    responder(3);
    return 0;
}

//use "gcc second-c.c -o second-c.exe" to compile the code and run it with "./second-c.exe"
// gcc second-c.c -o second-c.exe
// ./second-c.exe