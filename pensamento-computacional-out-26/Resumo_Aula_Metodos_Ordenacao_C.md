# Resumo: Algoritmos de Ordenação em C

Conceitos, Bubble Sort, Quick Sort e análise de complexidade

---

## 1. Conceitos Fundamentais

Um **algoritmo de ordenação** é um procedimento sistemático para reorganizar os elementos de uma coleção seguindo um critério de comparação (crescente, decrescente, alfabético etc.). Segundo Cormen et al. (2022), a ordenação é uma operação fundamental da computação e é muito usada como **sub-rotina** de algoritmos maiores.

**Por que estudar?**
- Buscas ficam muito mais rápidas em dados ordenados. A **busca binária**, O(log n), só funciona com dados já ordenados.
- Aparece em todo lugar: e-commerce (produtos por preço), redes sociais (posts por data), sistemas financeiros (transações por valor).
- A escolha do algoritmo impacta diretamente a experiência do usuário.

---

## 2. Critérios de Avaliação

| Critério | O que mede |
|---|---|
| **Complexidade de tempo** | Quantas operações são necessárias (melhor, médio e pior caso), em notação Big O |
| **Complexidade de espaço** | Quanta memória extra o algoritmo usa. Algoritmos **in-place** usam memória extra constante |
| **Estabilidade** | Se mantém a ordem relativa de elementos com valores iguais |
| **Adaptabilidade** | Se fica mais rápido quando os dados já estão quase ordenados |

### Exemplo de estabilidade

Ordenando alunos por nota, se Ana e Bruno têm nota 8 e Ana aparecia antes, um algoritmo **estável** mantém Ana antes de Bruno no resultado. Isso importa quando se ordena por mais de um critério.

---

## 3. Classificação dos Algoritmos

| Categoria | Exemplos |
|---|---|
| **Por comparação** | Bubble Sort, Quick Sort |
| **Sem comparação** | Counting Sort, Radix Sort |
| **Internos** (dados cabem na memória RAM) | Maioria dos algoritmos estudados |
| **Externos** (dados em disco, grandes demais para a RAM) | Variações de Merge Sort externo |
| **Recursivos** | Quick Sort, Merge Sort |
| **Iterativos** | Bubble Sort, Selection Sort |

---

## 4. Análise de Complexidade (Big O)

A notação **Big O** descreve como o tempo cresce conforme o tamanho da entrada (`n`) aumenta. Sedgewick e Wayne (2011) lembram que a escolha certa pode separar um programa que roda em segundos de um que levaria anos.

| Complexidade | n = 10 | n = 100 | n = 1.000 | n = 10.000 |
|---|---|---|---|---|
| O(1) | 1 | 1 | 1 | 1 |
| O(log n) | 3 | 7 | 10 | 13 |
| O(n) | 10 | 100 | 1.000 | 10.000 |
| O(n log n) | 33 | 664 | 9.966 | 132.877 |
| O(n²) | 100 | 10.000 | 1.000.000 | 100.000.000 |
| O(2ⁿ) | 1.024 | 1,27×10³⁰ | Inviável | Inviável |

**Ideia central:** se `n` cresce 10 vezes, um algoritmo O(n²) fica **100 vezes** mais lento, enquanto um O(n log n) fica só um pouco mais de 10 vezes mais lento.

### Qual algoritmo usar?

Não existe um "melhor" universal; depende do contexto:
- **Poucos dados (n < 50):** algoritmos simples (Insertion Sort, Bubble Sort) são suficientes.
- **Dados quase ordenados:** algoritmos adaptativos (Insertion Sort, Bubble Sort otimizado).
- **Memória limitada:** algoritmos in-place (Heap Sort, Quick Sort).
- **Precisa de estabilidade:** Merge Sort, mesmo usando O(n) de memória extra.

> **Algoritmos híbridos:** bibliotecas reais combinam técnicas. O C++ usa Introsort (`std::sort`), o Python usa Timsort e o Java usa Dual-Pivot Quicksort para tipos primitivos. Em 2023, o AlphaDev (DeepMind) encontrou rotinas mais rápidas para ordenar sequências curtas, incorporadas à biblioteca LLVM.

---

## 5. Bubble Sort (Ordenação por Bolha)

Geralmente o primeiro algoritmo estudado. Compara **elementos vizinhos** e troca se estiverem fora de ordem. A cada passada, o **maior elemento "flutua" até o final** do vetor, como uma bolha subindo.

### Passo a passo (primeira passada)

Vetor: `[64, 34, 25, 12, 22, 11, 90]`

| Comparação | Troca? | Resultado |
|---|---|---|
| 64 e 34 | Sim | `[34, 64, 25, 12, 22, 11, 90]` |
| 64 e 25 | Sim | `[34, 25, 64, 12, 22, 11, 90]` |
| 64 e 12 | Sim | `[34, 25, 12, 64, 22, 11, 90]` |
| 64 e 22 | Sim | `[34, 25, 12, 22, 64, 11, 90]` |
| 64 e 11 | Sim | `[34, 25, 12, 22, 11, 64, 90]` |
| 64 e 90 | Não | `[34, 25, 12, 22, 11, 64, 90]` |

Ao final da passada, o **90** está na posição correta. O processo se repete até não haver mais trocas.

### Implementação básica

```c
void bubbleSortBasico(int arr[], int n) {
    for (int i = 0; i < n; i++) {             // controla as passadas
        for (int j = 0; j < n - i - 1; j++) { // compara vizinhos
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];            // troca usando variável auxiliar
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```

- O **laço externo** (`i`) conta as passadas.
- O **laço interno** (`j`) compara os pares vizinhos.
- O `n - i - 1` evita comparar a parte final, que já está ordenada.

### Calculando o tamanho do vetor

```c
int numeros[] = {64, 34, 25, 12, 22, 11, 90};
int n = sizeof(numeros) / sizeof(numeros[0]);  // tamanho total ÷ tamanho de 1 elemento = 7
```

> Esse truque só funciona no mesmo escopo em que o vetor foi declarado. Dentro de uma função que recebe o vetor como parâmetro, `sizeof` retorna o tamanho do ponteiro; por isso o `n` é sempre passado junto.

### Otimização 1: parar quando já estiver ordenado

Se uma passada inteira não fizer nenhuma troca, o vetor já está ordenado e o algoritmo pode parar.

```c
#include <stdbool.h>

void bubbleSortOtimizado(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool trocou = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                trocou = true;
            }
        }
        if (!trocou) break;   // nenhuma troca: vetor ordenado
    }
}
```

Isso melhora o **melhor caso** de O(n²) para **O(n)**.

### Otimização 2 e variações

- **Cocktail Sort (bidirecional):** alterna passadas da esquerda para a direita e da direita para a esquerda.
- **Odd-Even Sort:** alterna comparações entre posições ímpares e pares; pode ser paralelizado.
- **Comb Sort:** compara elementos distantes no início e vai reduzindo a distância até 1.

### Complexidade do Bubble Sort

| Caso | Tempo | Quando acontece |
|---|---|---|
| Melhor | O(n) | Vetor já ordenado (com a otimização) |
| Médio | O(n²) | Dados aleatórios |
| Pior | O(n²) | Vetor em ordem inversa |
| **Espaço** | **O(1)** | In-place |

No pior caso, o número de comparações é (n−1) + (n−2) + ... + 1 = **n(n−1)/2 ≈ n²/2**.

### Vantagens e desvantagens

| Vantagens | Desvantagens |
|---|---|
| Muito simples de entender e implementar | O(n²) nos casos médio e pior |
| In-place (não usa memória extra) | Muitas trocas |
| Estável | Ineficiente para grandes volumes |
| Adaptável (com otimização) | Bem pior que algoritmos avançados |

**Quando usar:** sistemas embarcados simples, vetores pequenos (menos de 50 elementos), verificação se um vetor já está ordenado, protótipos rápidos e fins didáticos.

---

## 6. Quick Sort

Criado por **Tony Hoare em 1960**, usa o paradigma **dividir para conquistar** (divide-and-conquer): divide o problema em partes menores e resolve cada uma com **recursão**.

### As 3 etapas

1. **Escolher o pivô:** um elemento de referência.
2. **Particionar:** menores que o pivô vão para a esquerda, maiores para a direita.
3. **Recursão:** aplicar o mesmo processo em cada lado, até sobrarem listas de 0 ou 1 elemento (caso base).

### Exemplo

Vetor `[3, 6, 8, 10, 1, 2, 1]`, com pivô = primeiro elemento:

```
[3, 6, 8, 10, 1, 2, 1]          pivô 3
 → [1, 2, 1]  [3]  [6, 8, 10]

[1, 2, 1]   pivô 1  → []  [1]  [2, 1]
[2, 1]      pivô 2  → [1] [2]  []
[6, 8, 10]  pivô 6  → []  [6]  [8, 10]
[8, 10]     pivô 8  → []  [8]  [10]

Resultado: [1, 1, 2, 3, 6, 8, 10]
```

### Versão didática (com listas auxiliares)

O material mostra uma versão que separa os elementos em três vetores (`esquerda`, `meio`, `direita`) e chama a função recursivamente em cada lado. É fácil de entender, mas cria cópias a cada chamada e por isso **gasta muita memória**. Na prática, usa-se a versão in-place.

### Versão in-place (a mais usada)

```c
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int arr[], int baixo, int alto) {
    int pivot = arr[alto];        // último elemento como pivô
    int i = baixo - 1;            // fronteira dos elementos menores

    for (int j = baixo; j < alto; j++) {
        if (arr[j] <= pivot) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);  // coloca o pivô no lugar certo
    return i + 1;                     // posição final do pivô
}

void quickSortInPlace(int arr[], int baixo, int alto) {
    if (baixo < alto) {                        // caso base: 0 ou 1 elemento
        int pi = particionar(arr, baixo, alto);
        quickSortInPlace(arr, baixo, pi - 1);  // lado esquerdo
        quickSortInPlace(arr, pi + 1, alto);   // lado direito
    }
}

void quickSort(int arr[], int n) {
    quickSortInPlace(arr, 0, n - 1);
}
```

Repare no uso de **ponteiros** na função `trocar`: são eles que permitem alterar os valores do vetor original (passagem por referência).

### Estratégias de escolha do pivô

| Estratégia | Observação |
|---|---|
| Primeiro elemento | Simples, mas cai em O(n²) com vetor já ordenado |
| Último elemento | Mesmo problema do primeiro |
| Elemento do meio | Geralmente melhor que os extremos |
| Mediana de três | Mediana entre primeiro, meio e último; reduz casos ruins (Sedgewick e Wayne) |
| Aleatório | Bom desempenho esperado com qualquer entrada |

### Complexidade do Quick Sort

| Caso | Tempo | Espaço | Quando acontece |
|---|---|---|---|
| Melhor | O(n log n) | O(log n) | Pivô divide a lista ao meio |
| Médio | O(n log n) | O(log n) | Dados aleatórios |
| Pior | O(n²) | O(n) | Pivô sempre o menor ou maior elemento |

**De onde vem o n log n:** cada nível da recursão percorre os `n` elementos uma vez (particionamento), e há cerca de `log n` níveis quando o pivô divide a lista ao meio.

O espaço O(log n) vem da **pilha de chamadas recursivas**.

### Por que é rápido na prática?

- **Boa localidade de cache:** acessa posições próximas da memória.
- **Constante baixa:** faz menos operações "escondidas" que o Merge Sort.
- **In-place:** praticamente não usa memória extra.
- **Paralelizável:** os dois lados podem ser ordenados ao mesmo tempo.

### Otimizações comuns

- Usar **Insertion Sort** quando a sublista ficar pequena (menos de ~10 elementos).
- **Three-way partitioning** (menores, iguais e maiores) quando há muitos valores repetidos.
- **Otimização de recursão de cauda**, para reduzir o uso da pilha.
- **Pivô aleatório**, para evitar o pior caso.

### Tratamento de casos limite

```c
void quickSortSeguro(int arr[], int n) {
    if (n <= 1) return;   // vazio ou 1 elemento: já está ordenado
    quickSort(arr, n);
}
```

---

## 7. Comparação: Bubble Sort x Quick Sort

| Aspecto | Bubble Sort | Quick Sort |
|---|---|---|
| Complexidade média | O(n²) | O(n log n) |
| Espaço | O(1) | O(log n) |
| Estabilidade | Estável | Instável |
| Implementação | Muito simples | Moderada |
| Abordagem | Iterativa | Recursiva |
| Desempenho prático | Ruim para n > 50 | Excelente |

O contraste mostra o **trade-off clássico da computação: simplicidade x eficiência**.

---

## 8. Recursão x Iteração

| Fator | Recursão | Iteração |
|---|---|---|
| Legibilidade | Código mais curto e elegante | Pode ser mais longo |
| Memória | Cada chamada ocupa a pilha; risco de **stack overflow** | Usa menos memória |
| Desempenho | Custo extra das chamadas de função | Geralmente um pouco mais rápida |
| Ideal para | Problemas naturalmente recursivos (árvores, busca em profundidade, backtracking) | Profundidade grande ou imprevisível |

**Regra prática:** use recursão em problemas naturalmente recursivos com profundidade controlada; prefira iteração quando a profundidade puder ser muito grande.

---

## 9. Aplicações Modernas

- **Bancos de dados:** ordenação de resultados e junções.
- **Machine learning:** k-nearest neighbors e clustering.
- **Processamento em tempo real:** streams de dados.
- **Computação distribuída:** versões paralelas em frameworks como MapReduce.
- **Hardware:** redes de ordenação inspiradas no Bubble Sort em GPUs e processadores paralelos.

---

## 10. Conclusão

- **Bubble Sort** ensina os conceitos básicos: comparação, troca e iteração. É ineficiente para grandes volumes, mas útil em contextos específicos.
- **Quick Sort** introduz dividir para conquistar e recursão, com desempenho médio O(n log n).
- Não existe algoritmo perfeito: a escolha depende do **tamanho dos dados, da memória disponível e da necessidade de estabilidade**.

**Próximos conteúdos:** Merge Sort, Heap Sort, Radix Sort, algoritmos de grafos e programação dinâmica.

---

## Observações técnicas (complementares ao material)

Alguns pontos do material foram simplificados ou merecem um esclarecimento:

- **"Elementos menores flutuam para o início":** na implementação apresentada, o que acontece a cada passada é o **maior elemento ir para o final**, como o próprio exemplo passo a passo mostra. Os menores vão andando uma posição por vez para a esquerda.
- **Pivô no exemplo x no código:** o exemplo usa o **primeiro** elemento como pivô, a versão didática usa o **do meio** (`arr[n / 2]`) e a versão in-place usa o **último**. As três funcionam; só a ordem dos passos intermediários muda.
- **Versão didática do Quick Sort:** declara vetores do tamanho `n` dentro da função (`int esquerda[n]`), que ficam na pilha. Com vetores grandes isso pode causar stack overflow. É mais um motivo para preferir a versão in-place.
- **`qsort` do C:** o padrão da linguagem não define qual algoritmo o `qsort` usa; apesar do nome, cada biblioteca implementa do seu jeito.
- **AlphaDev e os "70%":** o ganho de até 70% foi medido em rotinas que ordenam **sequências bem curtas** (3 a 5 elementos). Para vetores grandes, o ganho relatado foi bem menor, em torno de 1,7%.
- **Exemplo do delivery:** 1.000.000 de operações levam poucos milissegundos num computador atual, não 1 segundo. Os números servem para ilustrar a **proporção** do crescimento (10 vezes mais dados = 100 vezes mais tempo), não o tempo real.
