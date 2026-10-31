# Resumo: Programação em C

Estruturas de dados, arquivos, funções, structs e ponteiros

---

## 1. Estruturas de Dados

**Estruturas de dados** são formas organizadas de armazenar, organizar e manipular informações em um programa. Segundo Tenenbaum et al. (2013), uma estrutura de dados é definida não só pelos dados, mas também pelas **operações** possíveis sobre eles e pelos **relacionamentos** entre eles.

**Por que usar?**

| Motivo | Benefício |
|---|---|
| Organização | Evita muitas variáveis soltas |
| Eficiência | Acesso e manipulação rápidos |
| Reutilização | Podem ser usadas em várias partes ou projetos |
| Resolução de problemas | Filas, pilhas, listas e arrays resolvem problemas naturalmente |

**Estruturas homogêneas** armazenam dados do **mesmo tipo**:
- **Arrays (vetores):** sequência linear de elementos.
- **Matrizes:** arrays multidimensionais (linhas e colunas).

> **Array = Vetor.** "Array" é o termo técnico em C; "vetor" é o termo comum em português, usado em contextos didáticos.

---

## 2. Arrays (Vetores)

Um array guarda vários elementos do mesmo tipo em **posições contíguas de memória**, o que permite acesso muito rápido por cálculo de endereço.

Exemplo: em vez de criar `nota1`, `nota2`, ..., `nota50`, usa-se `float notas[50];` (índices de 0 a 49).

### Índices

- Em C, os índices **começam em 0**.
- Um array de tamanho `n` tem índices de `0` até `n - 1`.
- O índice 0 é a "posição 1" para o usuário.
- Motivo técnico: endereço do elemento = endereço base + índice × tamanho do tipo.

> ⚠️ **Acessar índice fora do intervalo** (ex.: `numeros[5]` num array de 5 posições) gera **comportamento indefinido**: dados errados, travamento (crash) ou vulnerabilidades de segurança. Sempre valide os índices.

### Declaração e uso

```c
tipo nome_array[tamanho];
```

```c
int numeros[5] = {10, 20, 30, 40, 50};

printf("%d\n", numeros[0]);   // primeiro elemento
numeros[2] = 35;              // modificação

for (int i = 0; i < 5; i++) { // percorrendo com for
    printf("Posição %d: %d\n", i, numeros[i]);
}
```

O laço `for` é o padrão para percorrer arrays: `i` começa em 0, a condição `i < tamanho` evita ultrapassar o limite, e `i++` avança para o próximo índice.

### Arrays Multidimensionais (Matrizes)

O mais comum é o **bidimensional**, usado para tabelas, grades e matrizes matemáticas. Por convenção, **`i` representa linhas** e **`j` representa colunas**: `matriz[i][j]`.

```c
int tabuleiro[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        printf("%d ", tabuleiro[i][j]);
    }
    printf("\n");
}
```

> **Row-major:** em C, matrizes são armazenadas linha por linha na memória. Uma matriz `[3][4]` ocupa 12 posições consecutivas. Percorrer por linhas (laço externo em `i`) costuma ser mais eficiente.

---

## 3. Manipulação de Arquivos

Arquivos permitem **persistir dados** além da execução do programa (Deitel e Deitel, 2016). Em C, usa-se um ponteiro para `FILE`, que representa um fluxo de dados.

### Abertura e fechamento

```c
FILE *arquivo = fopen("dados.txt", "w");
if (arquivo == NULL) {
    printf("Erro ao abrir arquivo!\n");
    return 1;
}
fprintf(arquivo, "Linha com número: %d\n", 42);
fclose(arquivo);
```

### Modos de abertura

| Modo | Significado |
|---|---|
| `"r"` | Leitura (arquivo deve existir) |
| `"w"` | Escrita (cria ou sobrescreve) |
| `"a"` | Anexar ao final |
| `"r+"` | Leitura e escrita (arquivo deve existir) |
| `"w+"` | Leitura e escrita (cria ou sobrescreve) |

### Funções principais

| Função | Uso |
|---|---|
| `fopen()` / `fclose()` | Abrir / fechar arquivo |
| `fgetc()` / `fputc()` | Ler / escrever um caractere |
| `fgets()` / `fputs()` | Ler / escrever uma linha ou string |
| `fscanf()` / `fprintf()` | Ler / escrever dados formatados (`%d`, `%f`, `%s`) |
| `fread()` / `fwrite()` | Ler / escrever blocos (arquivos binários) |
| `setvbuf()` | Controlar o buffer de E/S |

### Leitura formatada

```c
char nome[50];
int idade;
float salario;

while (fscanf(arquivo, "%s %d %f", nome, &idade, &salario) == 3) {
    printf("Nome: %s, Idade: %d, Salário: %.2f\n", nome, idade, salario);
}
```

- `fscanf()` retorna quantos itens leu com sucesso; o laço continua enquanto ler os 3.
- `%s` lê apenas até o primeiro espaço (por isso nomes como `Joao_Silva`).

### Leitura linha a linha (ex.: análise de log)

```c
while (fgets(linha, sizeof(linha), log_file) != NULL) {
    total_acessos++;
    if (strstr(linha, " 404 ") || strstr(linha, " 500 ")) {
        acessos_erro++;
    }
}
```

`strstr()` (de `<string.h>`) procura uma substring dentro da linha.

### Texto x Binário

- **Texto:** caracteres legíveis (ex.: `"123\n"`); fácil de ler e editar manualmente.
- **Binário:** dados no formato bruto da memória; mais eficiente para grandes volumes.

### Boas práticas

1. Sempre verificar se `fopen()` retornou `NULL`.
2. Sempre fechar o arquivo com `fclose()`.
3. Para grandes volumes, usar `fread()`/`fwrite()` em blocos.
4. Em sistemas críticos, garantir o fechamento mesmo em caso de erro, para evitar vazamento de recursos.

---

## 4. Funções e Modularização

**Modularizar** é dividir um programa grande em partes menores (funções) com tarefas específicas. Vantagens: código mais organizado, mais fácil de manter e reutilizável (Sommerville, 2016).

### Estrutura de uma função

```c
tipo_de_retorno nome_da_funcao(lista_de_parametros) {
    // instruções
    return valor; // se houver retorno
}
```

**Protótipos** são declarados antes do `main` para que as funções possam ser definidas depois:

```c
int calcular_fatorial(int n);
float calcular_media(int n1, int n2, int n3);
void exibir_resultado(float media);   // void = sem retorno
```

### Passagem por valor

A função recebe uma **cópia**; o valor original não muda.

```c
void alterar_valor(int x) { x = 100; }  // não altera a variável original
```

### Arrays como parâmetro

A função recebe acesso ao **array original**, então alterações dentro dela afetam o array de quem chamou.

```c
void alterar_array(int vet[], int tamanho) {
    vet[0] = 999;  // altera o array original
}
```

### Retorno de valores

Cada função retorna **apenas um valor** diretamente. Para obter mais resultados:

| Estratégia | Exemplo |
|---|---|
| Retorno simples | `int encontrar_maior(int a, int b, int c)` |
| Status + resultado por ponteiro | `int dividir_seguro(float a, float b, float *resultado)` retorna 1 (sucesso) ou 0 (erro) |
| Vários resultados por ponteiros | `void operacoes(int a, int b, int *soma, int *produto, int *diferenca)` |
| Retornar uma struct | `struct Resultado calcular(int a, int b)` |

---

## 5. Structs (Estruturas Heterogêneas)

Uma **struct** agrupa variáveis de **tipos diferentes** sob um mesmo nome, representando uma entidade (pessoa, livro, produto...).

```c
struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};

struct Pessoa p1;
strcpy(p1.nome, "Ana");   // strings são copiadas com strcpy (<string.h>)
p1.idade = 28;
p1.altura = 1.65;
```

### Inicialização direta

```c
struct Produto produto1 = {1001, "Notebook", 2500.00, 15};
```

### Array de structs

```c
struct Pessoa grupo[100];
grupo[0].idade = 30;
strcpy(grupo[1].nome, "Maria");
```

### Structs com ponteiros

Passar uma struct por valor **copia** todos os dados, e as alterações não persistem. Com ponteiro, a função altera o original:

```c
void aumentar_idade(struct Pessoa *p) {
    p->idade++;   // p->idade é o mesmo que (*p).idade
}

aumentar_idade(&aluno);
```

### Structs aninhadas

```c
struct Endereco { char rua[50]; int numero; };

struct Pessoa {
    char nome[50];
    int idade;
    struct Endereco endereco;
};

p1.endereco.numero = 123;
```

### Boas práticas

- Usar nomes descritivos nos campos.
- Criar funções auxiliares para exibir e modificar structs.
- Preferir passar structs por ponteiro.
- Agrupar as funções de uma struct no mesmo arquivo.

**Aplicações:** modelar entidades reais, registros em arquivos, listas encadeadas, árvores, grafos e pacotes de rede.

---

## 6. Ponteiros

Um **ponteiro** é uma variável que armazena o **endereço de memória** de outra variável. Dá controle direto sobre a memória (Kernighan e Ritchie, 2011).

| Operador | Significado |
|---|---|
| `&var` | Endereço de `var` |
| `*ptr` | Valor apontado por `ptr` (desreferência) |
| `int *ptr` | Declaração de ponteiro para `int` |

```c
int valor = 42;
int *ponteiro = &valor;

printf("%p\n", ponteiro);   // endereço
printf("%d\n", *ponteiro);  // 42

*ponteiro = 100;            // altera "valor" para 100
```

### Ponteiros e arrays

O nome de um array funciona como um ponteiro para seu **primeiro elemento**, o que permite manipular arrays de forma eficiente (aritmética de ponteiros).

### Passagem por referência

Permite que uma função **modifique variáveis de quem a chamou**. Exemplo clássico, a troca de valores:

```c
void trocar_valores(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

trocar_valores(&x, &y);
```

### Ponteiros para funções

Armazenam o endereço de uma função, permitindo chamá-la dinamicamente. Usados em **callbacks**, sistemas de eventos, máquinas de estado e handlers de interrupção (sistemas embarcados).

> ⚠️ Ponteiros são poderosos, mas erros (ponteiro nulo, endereço inválido) podem ter consequências graves. Sempre verifique antes de usar.

---

## 7. Exemplo Integrador: Sistema de Biblioteca

Une **structs, arrays, funções, ponteiros e arquivos**. O sistema permite cadastrar, listar, emprestar/devolver livros e salvar os dados em arquivo.

```c
#define MAX_LIVROS 100
#define MAX_NOME 50

struct Livro {
    int codigo;
    char titulo[MAX_NOME];
    char autor[MAX_NOME];
    int ano_publicacao;
    int disponivel;   // 1 = disponível, 0 = emprestado
};

struct Livro biblioteca[MAX_LIVROS];
int total_livros = 0;

int main() {
    carregar_biblioteca();  // lê o arquivo, se existir
    menu_principal();       // menu interativo
    salvar_biblioteca();    // grava as alterações
    return 0;
}
```

A função `carregar_biblioteca()` abre `biblioteca.txt` em modo `"r"`, lê cada livro com `fscanf` para o array de structs e fecha o arquivo. Se o arquivo não existir, começa com a biblioteca vazia.

---

## 8. Conclusão e Próximos Passos

| Conceito | Para que serve |
|---|---|
| Arrays e matrizes | Organizar dados homogêneos (listas, tabelas, imagens) |
| Arquivos | Persistência, logs, relatórios, integração |
| Funções | Modularidade, legibilidade, reutilização |
| Structs | Modelar entidades do mundo real |
| Ponteiros | Controle de memória, passagem por referência, desempenho |

**Próximos conteúdos:** alocação dinâmica de memória, listas ligadas, árvores, grafos, recursão e algoritmos de ordenação.

---

## Observações técnicas (complementares ao material)

Alguns pontos do material foram simplificados para fins didáticos. Vale conhecer a versão mais precisa:

- **"Arrays são passados por referência":** tecnicamente, C só tem passagem por valor. Ao passar um array, ele "decai" para um **ponteiro** para o primeiro elemento, e é esse ponteiro (uma cópia do endereço) que a função recebe. Por isso as alterações afetam o original.
- **"O nome do array é um ponteiro constante":** na maioria das expressões ele se converte em ponteiro, mas não é idêntico a um. Por exemplo, `sizeof(numeros)` retorna o tamanho do array inteiro, não o de um ponteiro.
- **`stdlib.h`:** as funções de arquivo (`fopen`, `fclose`, `fprintf` etc.) estão em `stdio.h`. A `stdlib.h` traz funções utilitárias como `malloc`, `free` e `exit`.
- **`fscanf` com `%s`:** não limita o tamanho lido e pode estourar o buffer. Uma forma mais segura é indicar o limite, por exemplo `%49s` para um `char nome[50]`.
- **Ordem da condição no `while` de `carregar_biblioteca`:** o ideal é testar `total_livros < MAX_LIVROS` **antes** do `fscanf`, para não gravar fora do array.
