# Resumo da Aula: Probabilidade e Inferência Estatística
*Material de revisão — Unidade 3 (Páginas 3 a 7)*

---

## 📘 Página 3 — Fundamentos Probabilísticos

**Ideia central:** Probabilidade é a linguagem matemática usada para quantificar incerteza — sempre um número entre 0 (impossível) e 1 (certeza absoluta).

### Três abordagens de probabilidade
| Abordagem | Como funciona | Exemplo |
|---|---|---|
| **Clássica/teórica** | Resultados igualmente prováveis: nº favoráveis ÷ nº total | Dado justo → P(tirar 3) = 1/6 |
| **Frequentista/empírica** | Repete o experimento muitas vezes e observa a frequência relativa | 8 defeitos em 500 testados → ≈1,6% de defeito |
| **Bayesiana** | Grau de crença que se atualiza com novas evidências | Muito usada em Data Science moderno |

### Distribuições de probabilidade (modelos teóricos)
| Distribuição | Descreve | Exemplo |
|---|---|---|
| **Normal (Gaussiana)** | Fenômenos naturais, simétrica em forma de sino | Altura, peso, erro de medição |
| **Binomial** | Nº de sucessos em *n* tentativas independentes | Itens defeituosos em uma amostra |
| **Poisson** | Nº de eventos num intervalo fixo de tempo/espaço | Ligações por hora em um call center |
| **Exponencial** | Tempo até um evento ocorrer | Tempo entre chegadas de clientes numa fila |
| **t de Student** | Parecida com a normal, mas com caudas mais "pesadas" | Amostras pequenas, quando não se sabe o desvio padrão da população |

💡 **Por que importa:** identificar a distribuição correta permite calcular probabilidades reais — como a chance de um produto ser rejeitado por pesar menos que o especificado (usando o **z-score**: quantos desvios padrão um valor está da média).

---

## 📘 Página 4 — Amostragem

**Ideia central:** raramente é possível estudar uma população inteira — por isso trabalhamos com amostras, mas elas precisam ser representativas.

### Quando amostrar é necessário
- População infinita/muito grande
- Teste destrutivo (ex.: vida útil de um pneu)
- Caro ou lento estudar todo mundo
- Urgência de tempo (ex.: pesquisas eleitorais)

### Métodos de amostragem
**Probabilísticos** (cada membro tem chance conhecida de ser selecionado):
- **Aleatória simples:** sorteio puro, todos com a mesma chance.
- **Estratificada:** divide a população em subgrupos homogêneos e amostra proporcionalmente de cada um.
- **Por conglomerados:** sorteia grupos inteiros (ex.: seções eleitorais) e entrevista todos ali dentro.
- **Sistemática:** seleciona a cada *k*-ésimo item de uma lista.

**Não probabilísticos** (por conveniência ou julgamento): mais rápidos e baratos, mas não permitem calcular a precisão da estimativa — servem mais para exploração inicial.

⚠️ **Viés de amostragem:** quando a amostra não representa bem a população (ex.: pesquisa só com o próprio bairro do candidato).

### Teorema do Limite Central (TLC) — conceito-chave
Se você tira várias amostras (n ≥ 30) e calcula a média de cada uma, essas médias formam a **distribuição amostral**, que:
- É aproximadamente **normal**, mesmo que a população original não seja.
- Tem média igual à média da população (μ).
- Tem desvio padrão chamado de **erro padrão** = σ/√n.

💡 Quanto maior a amostra, menor o erro padrão → menor a incerteza sobre a verdadeira média da população.

---

## 📘 Página 5 — Intervalos de Confiança

**Ideia central:** em vez de dar só um número (estimativa pontual), o intervalo de confiança dá uma **faixa plausível** para o verdadeiro valor populacional.

### Fórmula geral
**Estimativa ± Margem de erro**, onde a margem de erro = valor crítico (t ou z) × erro padrão.

### Interpretação correta (cuidado aqui!)
Um IC de 95% **não** significa "95% de chance de a média estar nesse intervalo". Significa: *"se repetíssemos a amostragem muitas vezes, 95% dos intervalos construídos conteriam a verdadeira média."*

**Exemplo:** amostra de 400 pessoas, média 7,2, desvio padrão 1,8 → IC 95% = [7,02; 7,38].

### O que afeta a largura do intervalo
| Fator | Efeito |
|---|---|
| **Tamanho da amostra (n) ↑** | Intervalo mais estreito (mais preciso) |
| **Nível de confiança ↑** (ex.: 99% vs 95%) | Intervalo mais largo (mais "seguro", porém menos preciso) |
| **Variabilidade dos dados (s) ↑** | Intervalo mais largo |

💡 É possível calcular **antecipadamente** quantas pessoas amostrar para atingir uma margem de erro desejada — útil no planejamento de pesquisas.

---

## 📘 Página 6 — Testes de Hipóteses

**Ideia central:** testar se uma diferença observada nos dados é real ou apenas fruto do acaso.

### Estrutura básica
- **H₀ (hipótese nula):** afirmação de "nada mudou" (status quo).
- **H₁ (hipótese alternativa):** o que você quer demonstrar (há efeito/diferença).
- Você nunca prova H₁ diretamente — apenas **rejeita ou não rejeita H₀** com base nas evidências.

### Passo a passo
1. Calcular a **estatística de teste** (ex.: teste t).
2. Calcular o **p-valor** — probabilidade de obter um resultado tão extremo quanto o observado, se H₀ for verdadeira.
3. Comparar com o **nível de significância (α)**, geralmente 0,05:
   - p-valor < α → **rejeita H₀** (resultado estatisticamente significativo)
   - p-valor ≥ α → **não rejeita H₀** (evidência insuficiente — não é o mesmo que "provar" H₀)

### Dois tipos de erro possíveis
| Erro | O que é | Probabilidade |
|---|---|---|
| **Tipo I (falso positivo)** | Rejeitar H₀ sendo ela verdadeira | α |
| **Tipo II (falso negativo)** | Não rejeitar H₀ sendo ela falsa | β |

💡 Reduzir α aumenta β (e vice-versa) — é um trade-off. O contexto define qual erro é mais grave (ex.: aprovar um remédio ineficaz vs. rejeitar um remédio eficaz).

### Comparando dois grupos
- **Teste t para 2 amostras independentes:** compara médias de dois grupos diferentes.
- **Teste t pareado:** quando os dados são do mesmo grupo, antes/depois.
- **ANOVA:** quando há mais de dois grupos para comparar.

---

## 📘 Página 7 — Integração: Da Teoria à Prática

**Ideia central:** um framework de 7 passos para conduzir qualquer análise estatística com rigor.

### 🔄 Os 7 passos
1. **Defina a pergunta** claramente (estimar? testar? comparar?)
2. **Identifique o design de coleta** (amostra aleatória, estratificada, observacional...)
3. **Escolha a técnica** apropriada (teste t, ANOVA, regressão...)
4. **Verifique os pressupostos** (normalidade, homogeneidade de variância)
5. **Execute a análise** com software (R, Python, Excel...)
6. **Interprete com contexto** — significativo estatisticamente ≠ significativo na prática
7. **Comunique com responsabilidade** — inclua amostra, p-valor, IC e limitações

### ⚠️ Armadilhas comuns
| Armadilha | O que é |
|---|---|
| **P-hacking / data dredging** | Testar várias hipóteses até achar uma com p < 0,05 "por acaso" |
| **Correlação ≠ Causalidade** | Duas variáveis associadas não significa que uma causa a outra (ex.: iglus e consumo de chocolate — ambos ligados ao clima frio) |
| **Ignorar a magnitude prática** | Um resultado "significativo" com amostra gigante pode ser irrelevante na prática |
| **Pressupostos violados** | Usar teste que assume normalidade em dados não normais |
| **Amostra pequena demais** | Baixo poder estatístico — risco de não detectar um efeito que realmente existe |

---

## 🧠 Síntese geral da Unidade

Fluxo lógico da aula:
**Entender Probabilidade e distribuições → Coletar amostras representativas (TLC como ponte) → Quantificar a incerteza com Intervalos de Confiança → Validar hipóteses com testes rigorosos → Integrar tudo num framework de análise profissional, evitando armadilhas comuns.**

Frase-chave para lembrar: *"Nenhuma conclusão estatística é 100% certa — mas uma análise bem-feita reduz o risco de decisões erradas."*
