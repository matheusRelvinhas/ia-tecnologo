# Resumo da Aula: Correlação, Regressão, Visualização e Decisão Baseada em Dados
*Material de revisão — Unidade 4 (Páginas 3 a 7)*

---

## 📘 Página 3 — Correlação e Regressão Linear

**Ideia central:** correlação mede *se* duas variáveis estão relacionadas; regressão modela *como* essa relação funciona e permite prever.

### Correlação
- Mede o grau em que duas variáveis mudam juntas.
- **Coeficiente de Pearson (r):** varia de **-1 a +1**.
  - **+1** = correlação positiva perfeita (uma sobe, a outra sobe junto).
  - **-1** = correlação negativa perfeita (uma sobe, a outra desce).
  - **0** = nenhuma correlação linear.
  - Valores intermediários (ex.: +0,7 forte, +0,3 fraca) indicam força parcial da relação.
- ⚠️ **Correlação ≠ Causalidade:** exemplo clássico dos anos 1950 — TVs por domicílio correlacionavam com doenças cardíacas, mas a causa real era uma terceira variável oculta (renda/estilo de vida urbano).
- **Paradoxo de Simpson:** uma correlação pode desaparecer ou se inverter quando os dados são segmentados (caso real: admissões em Berkeley, que pareciam discriminar mulheres no agregado, mas se invertiam por departamento).

### Regressão Linear
- Responde: "como as variáveis se relacionam exatamente?" e "posso prever com isso?"
- Fórmula: **Y = a + bX**
  - Y = variável dependente (o que se quer prever)
  - X = variável independente (o previsor)
  - a = interceptação (valor de Y quando X = 0)
  - b = inclinação (efeito de cada unidade de X sobre Y)
- Método usado: **mínimos quadrados ordinários (OLS)** — encontra a linha que minimiza a distância vertical entre os pontos e a reta.
- **Limitações:** assume relação linear (se a relação for curva, distorce) e é sensível a **outliers** (um ponto extremo pode "puxar" a linha inteira).
- Para relações não lineares: regressão polinomial (curvas), logística (prever categorias) ou não paramétrica.

---

## 📘 Página 4 — Visualização de Dados

**Ideia central:** um gráfico ruim é pior que nenhum gráfico — visualização é a linguagem que traduz análise em compreensão.

### Por que visualização importa
- O cérebro processa imagens muito mais rápido que texto/números.
- **"Fator de mentira" (Tufte):** razão entre o efeito visual de uma mudança e a mudança real nos dados. Fator próximo de 1 = visualização ética e fiel.

### Guia de qual gráfico usar
| Situação | Gráfico ideal |
|---|---|
| Mudança ao longo do tempo | Linhas |
| Comparar categorias | Barras (verticais para poucos valores; horizontais para nomes longos/muitas categorias) |
| Relação entre 2 variáveis contínuas | Dispersão (scatter) — pode incluir linha de regressão |
| Distribuição de 1 variável contínua | Histograma |
| Comparar distribuições entre grupos | Box plot (mediana, quartis, outliers) |
| Partes de um todo (poucas categorias, diferenças óbvias) | Pizza (usar com moderação — olho humano erra ao comparar fatias parecidas) |

### Princípios de design eficaz
1. **Clareza em primeiro lugar** — cada elemento visual deve ter propósito; nada de 3D ou decoração inútil.
2. **Cor como aliada** — usar no máximo 5–7 cores; considerar daltonismo (~8% dos homens).
3. **Proporção adequada** — ajustar tamanho/formato ao meio (slide, impresso, celular).
4. **Contexto e referência** — um número sozinho não diz nada; comparar com meta, mês anterior, média histórica etc.

---

## 📘 Página 5 — Ferramentas Computacionais

**Ideia central:** não existe ferramenta universalmente superior — a escolha depende do problema, dos dados e do contexto.

| Ferramenta | Melhor para... | Limitação principal |
|---|---|---|
| **Python** (Pandas, NumPy, Scikit-learn) | Versatilidade geral, ML, comunidade enorme | Curva de aprendizado para quem não programa |
| **R** (ggplot2, RMarkdown) | Estatística pesada, relatórios reproduzíveis | Mais lento com grandes volumes; difícil para não programadores |
| **Excel** | Datasets pequenos/médios, análise rápida, público não técnico | Não escala para big data; baixa reprodutibilidade |
| **Tableau / Power BI** | Dashboards interativos para múltiplos usuários | Custo de licenciamento |
| **SQL** | Extrair dados diretamente de bancos de dados corporativos | Não é uma ferramenta de análise estatística em si |

### Fluxo típico de análise em Python
1. **Importação** dos dados (Pandas) → 2. **Limpeza** (valores faltantes, duplicatas) → 3. **Análise exploratória** (estatísticas, correlações) → 4. **Modelagem** (Scikit-learn) → 5. **Visualização** (Matplotlib/Seaborn/Plotly) → 6. **Comunicação** (Jupyter Notebook/relatório).

💡 **RMarkdown** (em R) mistura código, resultados e narrativa em um único documento reproduzível — ideal para relatórios que outra pessoa pode "rodar de novo" com um clique.

---

## 📘 Página 6 — Tomada de Decisão Baseada em Dados

**Ideia central:** análise só tem valor quando vira decisão e ação — e o caminho até lá está cheio de armadilhas conhecidas.

### O Ciclo de Decisão Baseado em Dados (8 etapas)
1. **Definição do problema** (específico, não vago)
2. **Coleta de dados**
3. **Limpeza e exploração** (geralmente a etapa mais demorada)
4. **Análise** (testes, regressão, gráficos)
5. **Interpretação com contexto**
6. **Comunicação** para quem decide
7. **Decisão e ação**
8. **Monitoramento** dos resultados

### ⚠️ Armadilhas comuns (mesmo especialistas caem nelas)
| Armadilha | O que é | Defesa |
|---|---|---|
| **Viés de confirmação** | Buscar só dados que confirmam a própria hipótese | Procurar ativamente evidências contrárias |
| **Regressão à média** | Um valor extremo tende a ser seguido por um valor mais "normal" — sem que nada tenha mudado | Reconhecer que variação aleatória sempre existe |
| **Cherry-picking / testes múltiplos** | Testar muitos períodos/subgrupos aumenta a chance de achar "padrões" por puro acaso | Definir a hipótese antes de olhar os dados |
| **Confundimento** | X e Y parecem relacionadas, mas uma terceira variável (Z) causa ambas | Sempre perguntar: existe uma variável oculta aqui? |

### Ética em análise de dados (princípios da ASA)
- Responsabilidade com quem usará a análise.
- Honestidade sobre limitações e resultados não significativos.
- Respeito aos dados (nunca manipular ou escolher métodos para forçar um resultado).
- Consciência do impacto social das análises sobre pessoas e comunidades.

### Comunicando para públicos não técnicos
- Comece pelo contexto/pergunta, não pelo método.
- Use linguagem simples.
- Mostre (gráficos), não apenas diga (números).
- Reconheça a incerteza.
- Contextualize a magnitude dos achados.

---

## 📘 Página 7 — Síntese da Unidade

**Fluxo lógico completo da Unidade:**
**Descobrir relações (correlação/regressão) → Comunicar com clareza (visualização) → Escolher a ferramenta certa (Python/R/Excel/BI/SQL) → Integrar tudo em um ciclo de decisão, vigiando armadilhas cognitivas e éticas.**

### Pontos-chave para não esquecer
- Nenhuma ferramenta é universalmente superior — a escolha depende do contexto.
- O caminho do dado à decisão não é linear: envolve definição de problema, coleta, limpeza (a parte mais demorada), análise, interpretação, comunicação e monitoramento.
- A defesa contra armadilhas é dupla: **rigor metodológico** (protocolos, hipóteses registradas antes da análise) + **pensamento crítico** (questionar as próprias conclusões).
- Um analista completo sabe não só executar técnicas, mas **quando usá-las, como comunicá-las e quais implicações éticas elas carregam**.

Frase-chave para lembrar: *"Uma análise brilhante que não é compreendida — ou que não leva à ação — é, na prática, inútil."*

---

## 📚 Referências da Unidade

- ASSOCIAÇÃO BRASILEIRA DE NORMAS TÉCNICAS. **NBR 6023**: Informação e documentação – Referências – Elaboração. Rio de Janeiro: ABNT, 2018.
- BUSSAB, W. O.; MORETTIN, P. A. **Estatística básica**. 9. ed. São Paulo: Saraiva, 2017.
- DEVORE, J. L. **Probabilidade e estatística para engenharia e ciências**. 8. ed. São Paulo: Cengage Learning, 2012.
- KNOWLES, M. S.; HOLTON, E. F.; SWANSON, R. A. **The adult learner**: the definitive classic in adult education and human resource development. 7. ed. Burlington: Elsevier, 2011.
- MCKINNEY, W. **Python for data analysis**: data wrangling with pandas, NumPy, and IPython. 2. ed. Sebastopol: O'Reilly, 2017.
- MONTGOMERY, D. C.; RUNGER, G. C. **Estatística aplicada e probabilidade para engenheiros**. 5. ed. Rio de Janeiro: LTC, 2012.
- TRIOLA, M. F. **Introdução à estatística**. 12. ed. Rio de Janeiro: LTC, 2017.
- TUFTE, E. R. **The visual display of quantitative information**. 2. ed. Cheshire: Graphics Press, 2001.
