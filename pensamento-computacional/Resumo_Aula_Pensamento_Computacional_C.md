# Resumo da Aula: Pensamento Computacional e Fundamentos da Linguagem C
*Material de revisão — Unidade 1 (Páginas 3 a 9)*

---

## 📘 Página 3 — Pensamento Computacional e a Lógica por trás da Solução

**Ideia central:** pensamento computacional é uma abordagem estruturada para resolver problemas, apoiada em 4 pilares que, juntos, preparam o terreno para a automação.

### Os 4 pilares
1. **Decomposição** — quebrar um problema grande em partes menores e gerenciáveis.
   *Ex.: dividir a criação de um jogo em cenário, personagens e pontuação.*
2. **Reconhecimento de padrões** — identificar semelhanças para reaproveitar soluções já conhecidas.
   *Ex.: criar uma função genérica para tarefas repetidas com pequenas variações.*
3. **Abstração** — focar só no que importa, ignorando detalhes irrelevantes.
   *Ex.: num jogo de carro, abstrair a cor dos parafusos, mas considerar velocidade e consumo.*
4. **Elaboração de algoritmos** — transformar o problema modelado numa sequência lógica de passos.
   *Ex.: algoritmo para fazer café: esquentar água → colocar pó → despejar água → servir.*

➡️ **Resultado final:** quando os 4 pilares são aplicados, o processo pode ser **automatizado** via programação.

💡 **Ferramenta de apoio:** Flowgorithm — ambiente visual gratuito para montar fluxogramas interativos e até gerar código equivalente em C, Python ou Java, sem precisar escrever sintaxe desde o início.

---

## 📘 Página 4 — Raciocínio Lógico-Matemático

**Ideia central:** programar exige comunicação extremamente precisa — diferente da linguagem humana, o computador não interpreta "nas entrelinhas".

### Lógica Proposicional
Uma **proposição** é uma afirmação que só pode ser verdadeira ou falsa. Proposições simples se combinam em proposições compostas através de **conectivos lógicos**:

| Conectivo | Nome | Operador em C | Regra |
|---|---|---|---|
| E | Conjunção | `&&` | Verdadeiro só se ambos forem verdadeiros |
| OU | Disjunção | `\|\|` | Verdadeiro se pelo menos um for verdadeiro |
| NÃO | Negação | `!` | Inverte o valor lógico |
| SE...ENTÃO | Implicação | — | Falso só quando A é V e B é F |
| SE E SOMENTE SE | Bicondicional | — | Verdadeiro só quando ambos têm o mesmo valor |

- **Tabela-verdade:** ferramenta para visualizar todas as combinações possíveis entre proposições — essencial para validar a lógica do código.
- ⚠️ **Tudo em C é binário:** 0 (falso) ou 1 (verdadeiro) — não existe "mais ou menos verdadeiro".

### Pseudocódigo
"Rascunho estruturado" entre o pensamento e o código real — foca na lógica sem se preocupar com sintaxe.

**Comandos básicos:**
- `ESCREVA` → saída de dados na tela
- `LEIA` → entrada de dados do usuário
- `←` → atribuição de valor a uma variável

**Estruturas básicas:** Sequência (passo a passo), Repetição (`ENQUANTO`/`PARA`), Decisão (`SE...ENTÃO...SENÃO`).

💡 **Ferramenta de apoio:** VisuAlg — visualizador de algoritmos gratuito, em português, que executa pseudocódigo passo a passo.

---

## 📘 Página 5 — Panorama das Linguagens e Fundamentos do C

**Ideia central:** entender como as linguagens se classificam ajuda a escolher a ferramenta certa para cada problema.

### Classificações principais
| Critério | Categorias | Onde o C se encaixa |
|---|---|---|
| **Nível de abstração** | Baixo (Assembly) / Médio (C) / Alto (Python, Java) | Nível **médio** — controle de memória + sintaxe legível |
| **Paradigma** | Imperativo / Orientado a Objetos / Funcional | **Imperativo** (instruções sequenciais que alteram o estado) |
| **Tipagem** | Estática/Dinâmica, Forte/Fraca | **Estática e forte** — erros de tipo detectados na compilação |
| **Processamento** | Compilada / Interpretada | **Compilada** — todo código vira linguagem de máquina antes de rodar |

💡 Compilação = velocidade e desempenho | Interpretação = flexibilidade e agilidade.

### Sintaxe vs. Semântica
- **Sintaxe:** as regras de escrita (erros impedem a compilação).
- **Semântica:** o significado do código (compila, mas pode dar resultado errado).

### Anatomia de um programa em C
```c
#include <stdio.h>      // inclui biblioteca de entrada/saída
int main() {            // ponto de entrada do programa
    printf("Olá, mundo!\n");
    return 0;            // 0 = sucesso
}
```
- `#include` → diretiva de pré-processador (roda antes da compilação).
- `main()` → onde a execução começa.
- `;` → todo comando termina com ponto e vírgula.
- `return 0` → indica que o programa terminou com sucesso.

---

## 📘 Página 6 — Tipos de Dados, Variáveis, Operadores e E/S

**Ideia central:** variáveis são "contêineres nomeados" na memória, e cada uma precisa de um tipo que define o que ela pode armazenar.

### Tipos primitivos
| Categoria | Tipos | Observação |
|---|---|---|
| **Inteiros** | `short`, `int`, `long`, `long long` | Podem ser `signed` ou `unsigned` |
| **Ponto flutuante** | `float`, `double`, `long double` | ⚠️ são aproximados (0.1 + 0.2 pode não dar exatamente 0.3) |
| **Caractere** | `char` | 1 byte, guarda um código ASCII |
| **Booleano** | `bool` (via `<stdbool.h>`, C99+) | `true` ≠ 0, `false` = 0 |

### Declaração e escopo
```c
int idade = 0;      // sempre inicialize! variável sem valor = "lixo de memória"
```
| Escopo | Onde é declarado | Visível em... |
|---|---|---|
| Global | Fora de funções | Todo o programa |
| Local | Dentro de uma função | Só naquela função |
| De bloco | Dentro de `{}` | Só dentro do bloco |

### Entrada e saída (`<stdio.h>`)
- `printf()` → exibe dados (`%d` inteiro, `%f` decimal, `%c` caractere, `%s` string).
- `scanf()` → lê dados (usa `&` antes da variável, exceto strings).
- ⚠️ Sempre validar a entrada — `scanf()` retorna quantos valores foram lidos com sucesso.

### Operadores
| Tipo | Exemplos | Observação |
|---|---|---|
| **Aritméticos** | `+ - * / %` | `%` só funciona com inteiros; cuidado com overflow e divisão inteira (7/2 = 3, não 3.5) |
| **Relacionais** | `== != < > <= >=` | Erro clássico: usar `=` (atribuição) no lugar de `==` (comparação) |
| **Lógicos** | `&& \|\| !` | Possuem avaliação em curto-circuito (ex.: `x != 0 && y/x > 1` evita divisão por zero) |
| **Incremento/decremento** | `++` `--` | Pré (`++x`) incrementa antes de usar; pós (`x++`) incrementa depois |

**Precedência de operadores** (do mais forte ao mais fraco): `()` → `++ -- ! -` → `* / %` → `+ -` → relacionais → `==/!=` → `&&` → `||` → `=`.

**Conversão de tipo (casting):** implícita (automática, ex.: int + float) ou explícita — `(float)a / b` força divisão real.

---

## 📘 Página 7 — Exemplos Práticos

**Ideia central:** aplicar entrada de dados, estruturas condicionais e operações aritméticas na resolução de problemas reais.

### Calculadora Simples
Usa `scanf()` para capturar dois números e um operador, e `switch` para decidir qual operação aritmética executar — com tratamento de erro para divisão por zero e operador inválido.

### Conversor de Temperatura
Lê uma temperatura e sua escala (C ou F), aplica a fórmula de conversão correta (`°F = °C × 9/5 + 32` ou o inverso) e trata o caso de escala inválida.

💡 **Boa prática reforçada:** sempre validar entradas e considerar casos extremos — essencial tanto para evitar erros quanto para prevenir vulnerabilidades de segurança.

---

## 📘 Página 8 — Elementos Enriquecedores: Tratamento de Erro e Boas Práticas

**Ideia central:** tratar erros não é opcional — é o que separa código amador de código profissional.

### Por que validar entradas
O computador não "adivinha" — o programador precisa prever todo cenário possível (valores inválidos, divisão por zero, dados fora do padrão).
```c
if (scanf("%d", &num) != 1 || num <= 0) {
    printf("Entrada inválida.\n");
    return 1;
}
```

### Armadilhas clássicas de programação
| Erro comum | Problema |
|---|---|
| `if (x = 5)` | Atribuição em vez de comparação |
| `scanf("%d", num)` | Falta do `&` antes da variável |
| `3 / 2` | Resultado é `1`, não `1.5` (divisão inteira) |
| `a + b * c` | Precedência mal interpretada sem parênteses |

**Ferramentas de depuração:** `printf()` para rastrear variáveis, depuradores como `gdb`/`lldb`, e IDEs com breakpoints.

### Caso real
A linguagem C é usada em sistemas embarcados críticos (pilotos automáticos, sensores de altitude) — segundo relato do setor aeroespacial, precisão na manipulação de tipos e operadores pode literalmente significar a diferença entre um voo seguro e um incidente.

---

## 📘 Página 9 — Em Síntese

**Fluxo lógico da Unidade:**
**Pensamento computacional (decomposição → padrões → abstração → algoritmos) → Raciocínio lógico e pseudocódigo → Escolha e fundamentos da linguagem C → Tipos de dados, variáveis e operadores → Prática com exemplos reais → Tratamento de erro e boas práticas.**

### Por que a linguagem C foi escolhida nesta disciplina
- **Estrutura clara e lógica** — facilita aprender variáveis, funções e controle de fluxo.
- **Proximidade com o hardware** — mostra o que realmente acontece "por trás do código".
- **Aplicações reais** — sistemas operacionais (Linux), sistemas embarcados, automação industrial.
- **Base para outras linguagens** — C++, Java, Python herdam conceitos fundamentais do C.

### Conexões interdisciplinares
Matemática Discreta (lógica proposicional), Arquitetura de Computadores (representação de dados) e Engenharia de Software (boas práticas) — a programação é uma atividade integradora.

### O que vem a seguir
Estruturas de controle (condicionais e loops), arrays e ponteiros, funções e modularização, estruturas de dados, algoritmos de ordenação e busca.

Frase-chave para lembrar: *"Programar é dar vida ao algoritmo — é transformar raciocínio lógico em ação automatizada."*
