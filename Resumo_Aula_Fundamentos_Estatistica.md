# Resumo da Aula: Os Fundamentos da Estatística
*Material de revisão — Unidade 1 (Páginas 3 a 7)*

---

## 📘 Página 3 — O que é Estatística e por que ela importa

**Ideia central:** Estatística é o conjunto de técnicas que transforma observações do mundo real em conhecimento útil, sempre lidando com incerteza.

- **Definição prática:** não é só "coletar e analisar números" — é um processo de planejar, coletar, interpretar e apresentar dados (Triola, 2017).
- **Estatística Descritiva:** resume e descreve os dados que você já tem (ex.: idade média dos funcionários).
- **Estatística Inferencial:** usa uma amostra para tirar conclusões sobre uma população inteira (ex.: pesquisar 1.000 pessoas para representar 100 milhões).
- 👉 Nesta unidade o foco é a **Descritiva** — a base para tudo que vem depois.
- **Qualidade dos dados ("garbage in, garbage out"):** dados bons precisam ser **precisos, completos, consistentes, oportunos e acessíveis** (os 5 pilares).
- **Contexto histórico:** Fisher (testes de hipótese) e Florence Nightingale (visualização de dados) como pioneiros.

---

## 📘 Página 4 — Tipos de Dados

**Ideia central:** classificar o tipo de dado corretamente define quais ferramentas e gráficos você pode usar.

### Qualitativos (categóricos) — respondem "qual tipo?"
- **Nominais:** sem ordem (cores, marcas, departamentos).
- **Ordinais:** com ordem natural (nível de satisfação, faixa de risco).

### Quantitativos (numéricos) — respondem "quanto?"
- **Discretos:** valores contáveis, "aos saltos" (nº de clientes, chamados).
- **Contínuos:** qualquer valor num intervalo (peso, tempo, temperatura).

### Escalas de medição (Stevens, 1946)
| Escala | Ordem? | Zero absoluto? | Exemplo |
|---|---|---|---|
| Nominal | Não | Não | Tipo de pagamento |
| Ordinal | Sim | Não | Nível de escolaridade |
| Intervalo | Sim | Não | Temperatura (°C) |
| Razão | Sim | Sim | Peso, renda |

⚠️ **Erro comum:** tratar dados ordinais como nominais (perde a ordem) ou quantitativos como ordinais (perde precisão).

---

## 📘 Página 5 — Organização de Dados

**Ideia central:** transformar uma lista bruta e caótica de números em uma estrutura compreensível.

1. **Dados brutos → Rol:** simplesmente ordenar os valores (crescente/decrescente) já revela padrões.
2. **Tabela de frequência simples:** lista cada valor único e conta ocorrências (usada quando há poucos valores distintos).
3. **Tabela de frequência agrupada (em classes):** agrupa valores em faixas — útil para dados contínuos ou muitos valores.
   - Nº de classes ideal: geralmente 5 a 20 (Regra de Sturges).
   - Amplitude da classe = (máximo − mínimo) ÷ nº de classes.
4. **Três tipos de frequência:**
   - **Absoluta (f):** contagem bruta.
   - **Relativa (fr):** proporção/porcentagem do total.
   - **Acumulada (F):** soma progressiva até aquela classe.

💡 **Reflexão importante:** a escolha de quantas classes usar é uma decisão de comunicação, não só técnica — poucas classes simplificam demais, muitas fragmentam a visão geral.

---

## 📘 Página 6 — Distribuições de Frequência e Padrões

**Ideia central:** a *forma* da distribuição conta uma história sobre os dados.

| Tipo de distribuição | Característica | Exemplo |
|---|---|---|
| **Normal** | Simétrica, forma de sino | Alturas |
| **Enviesada à direita** | Cauda longa à direita | Renda (poucos ganham muito) |
| **Enviesada à esquerda** | Cauda longa à esquerda | Idade de morte |
| **Uniforme** | Frequências iguais | Resultado de um dado justo |
| **Bimodal** | Dois picos | Alturas em grupo misto (H/M) |

- **Distribuições bivariadas / tabelas de contingência:** cruzam duas variáveis categóricas (ex.: gênero × marca preferida) para ver se estão relacionadas.
- ⚠️ **Correlação ≠ Causalidade:** dois eventos ocorrerem juntos com frequência não prova que um causa o outro (pode haver uma terceira variável envolvida).

---

## 📘 Página 7 — Visualização de Dados

**Ideia central:** gráficos comunicam padrões mais rápido que números, mas também podem enganar se mal construídos.

### Gráficos para dados QUALITATIVOS
- **Barras:** compara categorias (2 a 10 categorias funciona melhor).
- **Pizza:** mostra "partes do todo" (mas difícil comparar fatias parecidas).
- **Frequência relativa:** como o de barras, mas em % (bom para comparar amostras de tamanhos diferentes).

### Gráficos para dados QUANTITATIVOS
- **Histograma:** mostra a distribuição de dados contínuos/agrupados (barras coladas, sem espaço).
- **Linhas:** ideal para tendências ao longo do tempo.
- **Dispersão (scatter plot):** mostra relação entre duas variáveis numéricas (ex.: idade × renda).

### Boas práticas em visualização
1. Escolha o gráfico certo para o tipo de dado e a mensagem.
2. Etiquete eixos e unidades claramente.
3. Mantenha a simplicidade (evite 3D e excesso de cor).
4. Use cores com propósito (pense em daltonismo).
5. Dê contexto (texto + tabela de apoio).
6. Questione sempre a escala usada — ela pode distorcer a percepção.

---

## 🧠 Síntese geral da Unidade

Fluxo lógico da aula:
**Definir o que é Estatística → Classificar os tipos de dados → Organizar dados brutos em tabelas → Identificar a forma da distribuição → Visualizar com o gráfico certo.**

Frase-chave para lembrar: *"Dados devidamente organizados e compreendidos são o fundamento de tudo que vem depois."*
