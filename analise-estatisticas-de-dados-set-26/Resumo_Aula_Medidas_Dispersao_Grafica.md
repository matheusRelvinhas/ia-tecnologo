# Resumo da Aula: Medidas Descritivas e Análise Gráfica
*Material de revisão — Unidade 2 (Páginas 3 a 6)*

---

## 📘 Página 3 — Medidas de Tendência Central

**Ideia central:** não existe uma medida "certa" universal — média, mediana e moda respondem perguntas diferentes sobre o mesmo conjunto de dados.

### Média Aritmética
- Soma todos os valores e divide pela quantidade.
- **Ponto forte:** resume o conjunto inteiro em um único número, é matematicamente elegante (permite cálculos posteriores).
- **Ponto fraco:** muito sensível a **outliers** (valores extremos distorcem o resultado).
- Exemplo clássico: 9 funcionários ganhando R$ 2.000 + 1 dono ganhando R$ 100.000 → a média (R$ 11.800) não representa a realidade da maioria.

### Mediana
- Valor que fica exatamente no meio quando os dados são ordenados (50% abaixo, 50% acima).
- **Ponto forte:** imune a outliers — robusta.
- **Ponto fraco:** não entra em cálculos algébricos mais sofisticados e pode "esconder" a forma real da distribuição.
- No exemplo acima, a mediana salarial (R$ 2.000) reflete melhor a realidade dos funcionários.

### Moda
- Valor (ou categoria) que aparece com mais frequência.
- Única medida que funciona bem com **dados categóricos** (cores, marcas etc.).
- Pode ser **unimodal**, **bimodal** ou multimodal.
- **Ponto fraco:** ignora toda a distribuição — só olha para o valor mais repetido.

### 🎯 Guia rápido de quando usar cada uma
| Medida | Use quando... |
|---|---|
| **Média** | Dados numéricos, sem outliers relevantes, precisa de cálculos posteriores |
| **Mediana** | Há outliers ou assimetria, dados apenas ordenáveis |
| **Moda** | Dados categóricos, quer saber a opção mais escolhida |

💡 Na prática: calcule as três. Se estiverem próximas, os dados são bem-comportados. Se muito distantes, é sinal de assimetria ou outliers.

---

## 📘 Página 4 — Medidas de Dispersão

**Ideia central:** conhecer o "centro" dos dados não é suficiente — dois conjuntos podem ter a mesma média e comportamentos totalmente diferentes.

- Exemplo: Máquina A (peças entre 9,5–10,5 cm) vs Máquina B (peças entre 7–13 cm) — ambas com média 10 cm, mas a B é muito mais instável.

### Amplitude (Range)
- Fórmula: **Máximo − Mínimo**.
- Simples e rápida, mas ignora tudo que está "no meio" — usa só 2 valores.

### Variância
- Mede, em média, o quanto cada valor se afasta da média (desvios elevados ao quadrado).
- Eleva ao quadrado para (1) eliminar sinais negativos e (2) penalizar desvios grandes com mais força.
- **População:** divide por *n* | **Amostra:** divide por *(n − 1)* — correção de Bessel.
- Limitação: a unidade fica "ao quadrado" (ex.: cm²), difícil de interpretar intuitivamente.

### Desvio Padrão
- É a **raiz quadrada da variância** → volta para a unidade original dos dados (mais interpretável).
- É a medida de dispersão mais usada na prática.

### 📏 Regra Empírica (68-95-99,7) — para dados ~normais
- **68%** dos dados dentro de ±1 desvio padrão da média
- **95%** dentro de ±2 desvios padrão
- **99,7%** dentro de ±3 desvios padrão

💡 **Quando a dispersão importa mais que a média:** ao comparar fornecedores, investimentos ou processos, a *consistência* (desvio padrão baixo) muitas vezes é mais importante do que acertar a média.

---

## 📘 Página 5 — Análise Gráfica de Dados

**Ideia central:** gráficos comunicam padrões que números isolados não conseguem transmitir tão rápido.

### Gráficos de distribuição
- **Histograma:** barras que mostram a frequência dos dados agrupados em intervalos (bins) — revela a forma da distribuição (simétrica, assimétrica, bimodal, com outliers).
- **Curva de densidade:** versão "suavizada" do histograma, boa para dados contínuos.
- **Distribuição normal (Gaussiana):** simétrica, forma de sino, descrita só por média (μ) e desvio padrão (σ).
- **Assimetria à direita:** cauda longa para valores altos (ex.: renda).
- **Assimetria à esquerda:** cauda longa para valores baixos (ex.: notas de prova fácil).

### Gráficos de tendência (séries temporais)
- **Gráfico de linha:** tempo no eixo X, variável no eixo Y — ótimo para identificar:
  - **Tendência** (mudança consistente ao longo do tempo)
  - **Sazonalidade** (padrão que se repete em intervalos)
  - **Variação aleatória** (flutuação sem padrão)

### Gráficos de comparação
- **Barras/Colunas:** comparar valores entre categorias.
- **Dispersão (scatter plot):** relação entre duas variáveis contínuas — mostra correlação positiva, negativa, nenhuma relação, ou outliers.

### Gráficos de composição
- **Pizza:** mostra "partes do todo", mas o olho humano é ruim para comparar ângulos/áreas parecidas — prefira barras na maioria dos casos.
- **Área empilhada:** mostra como a composição de categorias muda ao longo do tempo.

### 🎨 Princípios de Edward Tufte
- **Razão dados-tinta:** quanto do gráfico é dado real vs. decoração desnecessária (evitar 3D, excesso de cor, grades supérfluas).
- **Integridade visual:** as proporções do gráfico devem refletir fielmente os dados (ex.: eixo começando em zero, não em 50, para não exagerar diferenças).

📌 **Não existe "o melhor gráfico" universal** — a escolha depende do tipo de dado, do objetivo (distribuição, comparação, relação ou tendência), do público e do contexto de apresentação.

---

## 📘 Página 6 — Aplicações Práticas e Interpretação Integrada

**Ideia central:** na prática profissional, medidas centrais, dispersão e gráficos trabalham **juntos**, não isoladamente.

### Rotina de Análise Descritiva Completa
1. **Resumo numérico inicial** (média, mediana, desvio padrão)
2. **Visualização** (histograma, linha, etc.)
3. **Análise crítica** (outliers, formato da distribuição)
4. **Narração** (comunicar os achados de forma clara ao público)

### ⚠️ Armadilhas Clássicas da Estatística Descritiva

| Armadilha | O que é | Exemplo |
|---|---|---|
| **Paradoxo de Simpson** | Uma tendência nos dados agregados pode se inverter quando os dados são segmentados | Um remédio parece eficaz no geral, mas é menos eficaz em cada subgrupo (idade/gênero) |
| **Correlação ≠ Causalidade** | Duas variáveis relacionadas não significa que uma causa a outra | Mais bibliotecas ↔ mais crimes → ambas ligadas ao tamanho da população, não uma à outra |
| **Manipulação de escala** | Mudar onde o eixo começa distorce a percepção visual da variação | Gráfico começando em R$ 98.000 (em vez de 0) faz uma variação de 2% parecer enorme |

💡 Na era do Big Data, ferramentas (Python/Pandas, R, SQL, Tableau, Power BI) automatizam os cálculos — mas a interpretação crítica continua sendo um trabalho humano.

---

## 🧠 Síntese geral da Unidade

Fluxo lógico da aula:
**Resumir o centro dos dados (média/mediana/moda) → Medir a variabilidade (amplitude/variância/desvio padrão) → Visualizar com o gráfico certo → Integrar tudo numa análise crítica, atenta a armadilhas de interpretação.**

Frase-chave para lembrar: *"Números informam, gráficos esclarecem, contexto enriquece."*
