# Resumo – Modelagem de Banco de Dados
## Unidade 1: Fundamentos e Contexto da Modelagem de Banco de Dados

---

## 1. Dado x Informação

| Conceito | Definição | Exemplo |
|---|---|---|
| **Dado** | Fato bruto, valor isolado, sem contexto específico (Elmasri e Navathe, 2019) | O número `25` |
| **Informação** | Dado processado, organizado e contextualizado, com significado e relevância (Date, 2004) | "João tem 25 anos" |

**Por que importa:** um banco de dados bem projetado armazena dados de forma eficiente e permite transformá-los em informação por meio de consultas, relatórios e análises.

**Exemplo (e-commerce):** códigos de produtos, preços, datas e CEPs são dados. O "Relatório de vendas por região no último trimestre" é informação estratégica.

### Características dos dados
- **Atômicos:** menor unidade armazenável sem perder o significado.
- **Persistentes:** permanecem disponíveis até serem removidos ou modificados.
- **Granularidade:** nível de detalhe (ex.: vendas mensais agregadas x cada transação individual). Impacta a flexibilidade das consultas e o desempenho.

### Hierarquia DIKW
**Data → Information → Knowledge → Wisdom**
Dados → Informação → Conhecimento (informação aplicada com experiência) → Sabedoria (conhecimento aplicado com julgamento). É a base de como sistemas de *Business Intelligence* geram insights.

### Etapas da transformação de dados em informação
1. **Coleta:** captura de dados brutos de várias fontes.
2. **Validação:** garante os critérios de qualidade.
3. **Processamento:** organização, cálculo e relacionamento (ex.: somar vendas para gerar totais mensais).
4. **Contextualização:** aplicação de regras de negócio e metadados.
5. **Apresentação:** relatórios, dashboards ou interfaces.

---

## 2. Aspectos Éticos, Legais e Tecnológicos

### LGPD (Lei 13.709/2018)
- Marco regulatório brasileiro para o tratamento de dados pessoais, inspirado no **GDPR** europeu.
- **Princípios:** minimização (coletar só o necessário), finalidade (usar só para o declarado) e transparência (informar como os dados serão usados).
- **Obrigações:** segurança dos dados, documentação das operações de tratamento e uso apenas para as finalidades declaradas.
- **Sanções:** multas de até 2% do faturamento da empresa no Brasil, limitadas a R$ 50 milhões, conforme regulamento da ANPD. Os danos à reputação e à confiança dos clientes costumam pesar mais que as multas.

### Princípios éticos (Barocas, Hardt e Narayanan, 2023)
- **Não maleficência:** o uso de dados não deve causar danos.
- **Beneficência:** o uso de dados deve gerar benefícios tangíveis.
- **Autonomia:** o titular controla seus dados (consentimento informado, acesso, correção e exclusão).
- **Justiça:** benefícios e riscos distribuídos de forma equitativa, protegendo grupos vulneráveis.

> **Caso Cambridge Analytica (2018):** coleta de dados de milhões de usuários do Facebook sem consentimento adequado para influenciar eleições. Destaca a importância da transparência e do consentimento informado.

### Desafios tecnológicos
- **Controle de acesso granular:** autenticação multifatorial, autorização baseada em papéis e auditoria detalhada.
- **Criptografia:** em repouso e em trânsito, com gestão adequada das chaves.
- **Pseudonimização e anonimização:** reduzem riscos no tratamento de dados pessoais.
- **Auditoria e monitoramento:** rastreiam quem acessou quais dados, quando e para quê.

### Governança de dados (Khatri e Brown, 2020)
Framework de políticas, procedimentos e controles ao longo do ciclo de vida dos dados. Abrange qualidade, privacidade, segurança, conformidade regulatória e valor de negócio.
- **Qualidade:** precisão, completude, consistência e atualidade (com limpeza e validação).
- **Ciclo de vida:** coleta, armazenamento, uso, arquivamento e descarte, com políticas de retenção.

---

## 3. Dados Estruturados, Semiestruturados e Não Estruturados

| Tipo | Características | Exemplos | Tecnologias adequadas |
|---|---|---|---|
| **Estruturados** | Formato fixo e predefinido, tabelas com linhas e colunas, esquema rígido, consulta via SQL | CRM, transações financeiras, inventários, cadastro de livros (ISBN, título, autor) | PostgreSQL, MySQL, Oracle |
| **Semiestruturados** | Alguma organização, sem a rigidez do esquema relacional; flexíveis, mas podem gerar inconsistências | XML, JSON, e-mails, dados de redes sociais, APIs web | PostgreSQL (tipo JSON), MongoDB |
| **Não estruturados** | Sem formato predefinido, esquema flexível, exigem análise especializada (PLN, reconhecimento de padrões) | Texto livre, imagens, vídeos, áudios, logs, dados de sensores IoT | NoSQL (MongoDB, Cassandra), Hadoop HDFS, Elasticsearch |

- Os dados estruturados são **previsíveis e eficientes**, com recursos como **ACID**, índices e otimizadores de consulta.
- Estima-se que **80–90% dos dados gerados** hoje sejam não estruturados.
- **Desafios dos não estruturados:** dificuldade de indexação e busca, algoritmos especializados, grande volume de armazenamento e dificuldade para relacionar diferentes tipos de dados.

---

## 4. Modelo Lógico x Modelo Físico

| Aspecto | Modelo Lógico | Modelo Físico |
|---|---|---|
| **Foco** | Requisitos e regras de negócio | Implementação no SGBD escolhido |
| **Tecnologia** | Independente | Dependente |
| **Elementos** | Entidades, atributos e relacionamentos | Tipos de dados, índices, PK/FK, constraints, otimizações |
| **Notação** | Diagrama Entidade-Relacionamento (DER) | Scripts DDL, estruturas de armazenamento |
| **Público** | Usuários de negócio e analistas | Equipe técnica (DBAs, desenvolvedores) |
| **Exemplo (e-commerce)** | Entidades: Cliente, Produto, Pedido, ItemPedido | `id SERIAL PRIMARY KEY`, `nome VARCHAR(100) NOT NULL`, `email VARCHAR(255) UNIQUE` |

### Transformação do lógico para o físico
- **Entidades → tabelas** (nem sempre de forma direta, por questões de performance).
- **Atributos → colunas**, com tipos cuidadosamente definidos (ex.: `preço` → `DECIMAL(10,2)`).
- **Relacionamentos → chaves estrangeiras**, considerando integridade referencial e cascateamento (ex.: `cliente_id` em Pedido).

### Considerações de design
- **Normalização** x **desnormalização controlada**, conforme os padrões de acesso e a performance.
- **Indexação:** B-tree, Hash, GIN, GiST (PostgreSQL). Cada índice adicional impacta inserções e atualizações.
- **Particionamento:** por data ou hash, para grandes volumes.
- **Constraints:** `PRIMARY KEY`, `FOREIGN KEY`, `CHECK`, `UNIQUE`, `NOT NULL`.

---

## 5. Bancos Relacionais x Não Relacionais (NoSQL)

### Relacionais
- Baseados no modelo de **Edgar F. Codd (1970)**: tabelas (relações), linhas (tuplas) e colunas (atributos).
- **Vantagens:** SQL padronizado, propriedades **ACID**, normalização, esquema fixo, relacionamentos explícitos e otimizadores sofisticados.
- **Ideais para:** sistemas financeiros, ERP, RH e qualquer aplicação com integridade transacional crítica.

### NoSQL (*Not Only SQL*)
- Surgiu no final dos anos 2000 para big data, alta escalabilidade e dados não estruturados.
- **Vantagens:** escalabilidade horizontal, flexibilidade de esquema, performance otimizada e grandes volumes de dados diversos.
- **Trade-offs:** muitos sacrificam parte do ACID e adotam **consistência eventual** (teorema CAP).

| Tipo | Exemplos | Características e usos |
|---|---|---|
| **Documentos** | MongoDB, CouchDB | Armazenam JSON/BSON/XML com estruturas aninhadas, sem necessidade de joins. Bons para aplicações web, CMS e catálogos de produtos. |
| **Chave-valor** | Redis, DynamoDB | Mais simples, com performance excepcional por chave. Ideais para cache, sessões, carrinhos de compras e contadores. Consulta limitada (só por chave). |
| **Colunas** | Cassandra, HBase | Famílias de colunas (particionamento vertical) e Big Tables. Voltados para computação distribuída e mecanismos de busca como o Google. |
| **Grafos** | Neo4j, Amazon Neptune | Nós (entidades) e arestas (relacionamentos), com a linguagem Cypher. Ideais para redes sociais, recomendação e detecção de fraudes. |

### Teorema CAP
Sistemas distribuídos só garantem **duas das três** propriedades: **C**onsistency, **A**vailability e **P**artition Tolerance.
- Relacionais tradicionais: priorizam consistência e disponibilidade.
- Muitos NoSQL: priorizam disponibilidade e tolerância a partições (consistência eventual).

### Critérios de escolha
1. **Consistência:** rigorosa → relacional; eventual aceitável → NoSQL.
2. **Volume e variedade:** grandes volumes não/semiestruturados → NoSQL; dados estruturados com relacionamentos complexos → relacional.
3. **Escalabilidade:** horizontal → NoSQL; vertical → relacional.
4. **Experiência da equipe:** SQL é amplamente conhecido; cada NoSQL exige conhecimento específico.

---

## 6. Comparação entre SGBDs Relacionais

| SGBD | Perfil | Pontos fortes | Limitações |
|---|---|---|---|
| **PostgreSQL** | Objeto-relacional, código aberto (desde 1986) | Conformidade com padrões SQL, extensibilidade, tipos avançados (JSON, arrays), índices variados (B-tree, GIN, GiST, BRIN...), PostGIS, consultas complexas | Configuração e tuning mais complexos |
| **MySQL** | Popular, mantido pela Oracle | Facilidade de uso, performance em leitura intensiva, engines (InnoDB, MyISAM), replicação, ampla documentação | SQL menos avançado, restrições em alta concorrência de escrita |
| **Oracle Database** | Comercial premium, enterprise | RAC, Data Guard, Advanced Security, In-Memory, otimizador sofisticado, suporte premium | Alto custo de licenciamento, complexidade, dependência de fornecedor |
| **SQL Server** | Microsoft | Integração com .NET, Azure, Active Directory; SSIS (ETL), SSAS (OLAP), SSRS (relatórios); edição Express gratuita | Dependência do ecossistema Microsoft e custos das edições comerciais |

> **Caso Instagram (2012):** manteve o PostgreSQL e o escalou com *sharding* horizontal, chegando a centenas de terabytes em milhares de instâncias.

### Tendências
- **Cloud:** Amazon RDS, Google Cloud SQL, Azure Database.
- **Bancos híbridos** (relacional + NoSQL): JSON no PostgreSQL, multimodelo no Oracle.
- **Automação e ML:** Oracle Autonomous Database, otimização automática e detecção de anomalias.
- **Containers e orquestração:** Docker, Kubernetes e operadores para bancos de dados.

### Recomendações de uso
- **Startups e projetos pequenos/médios:** PostgreSQL (bom custo-benefício).
- **Aplicações web simples:** MySQL Community.
- **Enterprise crítico:** Oracle.
- **Ambientes Microsoft:** SQL Server.
- **Microsserviços e aplicações modernas:** PostgreSQL com JSON e containers.
- **Análise de dados e BI:** SQL Server (SSIS) ou PostgreSQL. O Oracle lidera em data warehouses enterprise de grande escala.

---

## 7. Caso Prático: Sistema de E-commerce

- **Requisitos:** produtos, clientes, pedidos, pagamentos e estoque (dados estruturados e semiestruturados).
- **Modelo lógico:** Cliente, Produto, Pedido, ItemPedido e Pagamento.
- **Ética:** conformidade com a LGPD, criptografia de dados sensíveis (cartões) e políticas de retenção.
- **Arquitetura poliglota:**
  - **PostgreSQL:** pedidos, pagamentos e estoque.
  - **Redis:** cache de sessões e carrinho.
  - **Elasticsearch:** busca de produtos.
  - **MongoDB:** logs de comportamento do usuário.

### Boas práticas
| Área | Práticas |
|---|---|
| **Qualidade** | Constraints (`NOT NULL`, `CHECK`, `UNIQUE`) e validação na aplicação (formato de e-mail, dígito verificador do CPF). |
| **Auditoria** | Triggers que registram usuário, timestamp e valores anterior/posterior. |
| **Monitoramento** | Procedures que verificam anomalias, valores fora da faixa e relacionamentos órfãos. |
| **Backup** | Backups incrementais regulares, testes periódicos de restauração e documentação dos procedimentos. |
| **Performance** | Indexação estratégica (índices compostos), particionamento, desnormalização controlada e cache (Redis). |
| **Integração** | APIs RESTful (JWT e rate limiting), ETL, mensageria assíncrona (RabbitMQ, Kafka) e data lakes. |

---

## 8. Conexões e Próximos Passos

**Conexões interdisciplinares:** Programação, Sistemas Operacionais, Redes de Computadores e Engenharia de Software.

**Próximas unidades:**
- **Unidade 2:** modelagem conceitual (entidades, atributos e relacionamentos).
- **Unidade 3:** normalização e otimização.
- **Unidade 4:** implementação prática e manipulação de dados.

---

## Ideias-chave para revisão

1. Dado é bruto; informação é dado com contexto.
2. A LGPD e a ética não são opcionais: privacidade, segurança e transparência devem estar no projeto desde o início.
3. A natureza dos dados (estruturados, semiestruturados ou não estruturados) orienta a escolha da tecnologia.
4. O modelo lógico é o "o quê" (negócio); o físico é o "como" (implementação no SGBD).
5. Não existe solução universal: a escolha depende de consistência, volume, escalabilidade e experiência da equipe.
6. A tendência são arquiteturas híbridas (poliglotas), combinando várias tecnologias.
7. Os princípios de modelagem permanecem constantes, mesmo com a evolução das ferramentas.
