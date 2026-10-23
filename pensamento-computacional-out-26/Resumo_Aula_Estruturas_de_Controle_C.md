# Resumo da Unidade 2: Estruturas de Decisão, Controle e Repetição em C

## 1. Fluxo de Controle

- Por padrão, um programa executa as instruções em **ordem sequencial**, de cima para baixo.
- O **fluxo de controle** quebra essa linearidade, permitindo que o programa:
  - **Decida** entre caminhos diferentes (estruturas de decisão: `if`, `else`, `switch`);
  - **Repita** tarefas até que uma condição seja satisfeita (laços: `for`, `while`, `do-while`).
- Exemplo clássico: um sistema de login que verifica a senha e pede nova tentativa até o usuário acertar ou desistir.

---

## 2. Estruturas de Decisão

### 2.1 `if` / `else`

Avalia uma expressão booleana (verdadeira ou falsa) e executa um bloco conforme o resultado.

```c
if (idade >= 18) {
    printf("Acesso liberado.\n");
} else {
    printf("Acesso negado.\n");
}
```

- `scanf("%d", &idade);` lê um inteiro digitado pelo usuário.
- `\n` quebra a linha na saída.

### 2.2 Condicionais aninhadas

Um `if` dentro de outro permite decisões hierárquicas, mas deve ser usado com cuidado para não prejudicar a legibilidade.

```c
if (idade >= 18) {
    if (idade < 65) printf("Adulto.\n");
    else printf("Idoso.\n");
} else {
    printf("Menor de idade.\n");
}
```

### 2.3 Operadores lógicos

| Operador | Significado | Exemplo |
|----------|-------------|---------|
| `&&` | E lógico | `idade >= 18 && renda > 1000` |
| `\|\|` | OU lógico | `idade < 18 \|\| renda < 500` |
| `!` | NÃO lógico | `!(idade >= 18)` |

### 2.4 Condicionais compostas (`if` / `else if` / `else`)

Permitem múltiplas verificações em sequência, da **mais restrita à mais geral** (ex.: aprovação de cartão de crédito premium, básico ou negado, conforme idade e renda).

### 2.5 `switch` / `case`

Ideal para comparar **uma variável com vários valores fixos** (normalmente `int` ou `char`). É mais organizado que vários `if-else` encadeados.

- `case`: valor a ser comparado;
- `break`: encerra o `switch` e evita o **fall-through** (execução dos próximos cases);
- `default`: executado se nenhum `case` corresponder.

```c
switch (opcao) {
    case 1: printf("Novo jogo\n"); break;
    case 2: printf("Carregar jogo\n"); break;
    case 3: printf("Sair\n"); break;
    default: printf("Opção inválida.\n"); break;
}
```

> **Dica:** sem o `break`, o programa continua executando os cases seguintes, a menos que isso seja intencional.

---

## 3. Estruturas de Repetição (Laços)

Executam um bloco repetidamente enquanto uma condição for verdadeira, automatizando tarefas e processando grandes volumes de dados.

### 3.1 `while`

- Verifica a condição **antes** de cada iteração;
- Pode executar **zero vezes** se a condição inicial for falsa.

```c
while (contador <= 10) {
    soma += contador;
    contador++;
}
```

**Loop infinito:** ocorre quando a condição de parada nunca se torna falsa. Pode causar consumo excessivo de CPU e memória, travamento da aplicação ou do sistema. **A condição deve ser alterada dentro do laço.**

### 3.2 `do-while`

- Verifica a condição **depois** de executar o bloco;
- Executa **pelo menos uma vez**.
- Útil quando a ação deve ocorrer antes da verificação (ex.: jogo de adivinhação, menus).

```c
do {
    scanf("%d", &numero);
} while (numero != numero_secreto);
```

### 3.3 `for`

Ideal quando se sabe **quantas vezes** repetir. Reúne inicialização, condição e incremento em uma só linha.

```c
for (inicialização; condição; incremento) {
    // bloco repetido
}
```

Exemplos vistos: imprimir de 1 a 10, somar de 1 a 100 e calcular a média de um array (usando `sizeof(numeros) / sizeof(numeros[0])` para obter o tamanho).

### Quando usar cada laço?

| Laço | Use quando... |
|------|---------------|
| `for` | Você sabe quantas repetições serão feitas |
| `while` | O número de repetições depende de condições dinâmicas |
| `do-while` | A ação deve ocorrer ao menos uma vez antes da verificação |

---

## 4. Comandos de Controle de Laços

| Comando | Função |
|---------|--------|
| `break` | Interrompe o laço completamente (ex.: parar a busca ao encontrar um número no array) |
| `continue` | Pula o restante da iteração atual e vai para a próxima (ex.: imprimir só números pares) |
| `return` | Encerra a função imediatamente, podendo retornar um valor; em `main`, encerra o programa |

---

## 5. Casos Práticos

1. **Menu interativo (sistema bancário):** combina `do-while` (mantém o menu ativo até escolher "Sair") com `switch` (trata consultar saldo, depositar, sacar e sair), incluindo validação de valores.
2. **Validação de dados com múltiplas tentativas (login):** usa `while` com contador de tentativas e `strcmp` para comparar a senha; bloqueia o acesso após o limite de 3 tentativas.

---

## 6. Boas Práticas e Otimização

- Ordene as condições do `if / else if` pela **probabilidade de ocorrência** (mais comuns primeiro);
- Avalie condições **menos custosas** antes das mais complexas nos operadores lógicos;
- **Complexidade:** um laço simples é O(n); laços aninhados podem chegar a O(n²) ou mais.

### Testes recomendados

- **Valores extremos:** 0, negativos, `INT_MAX`;
- **Entradas inválidas:** letras onde se esperam números, valores fora do intervalo;
- **Condições de borda:** primeiro e último elemento de um array, última repetição do laço.

### Depuração com GDB

Permite executar o código passo a passo, ver o valor das variáveis em tempo real e parar em pontos específicos (*breakpoints*).

---

## 7. Conclusão

- O domínio das estruturas de decisão e repetição é a base para conceitos avançados (recursão, ponteiros, estruturas de dados, algoritmos de busca e ordenação).
- Essas estruturas sustentam padrões de projeto mais complexos (ex.: Strategy usa `switch/case`; Iterator se baseia em laços).
- O controle de fluxo é **universal** e transferível para qualquer linguagem de programação.

---

## Referências citadas no material

Gaddis (2021); Deitel e Deitel (2024); Schildt (2013); Sebesta (2018); Feofiloff (2014); Cormen et al. (2012); Tucker e Noonan (2017).
