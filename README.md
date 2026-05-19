# Aproximação Inteira da Distância Euclidiana via Expansão Binária

Este repositório contém os códigos e a documentação referentes à pesquisa desenvolvida no âmbito do Programa de Educação Tutorial (PET) de Ciência da Computação da Universidade Federal de Uberlândia (UFU). O trabalho também teve seus resultados apresentados no Workshop de Teses, Dissertações e Trabalhos de Iniciação Científica em Curso (WTDCC).

## 📌 Sobre o Projeto

[cite_start]O cálculo de distâncias entre pontos em espaços N-dimensionais é fundamental em diversas áreas da computação, como Análise de Dados e Aprendizado de Máquina, mas tradicionalmente exige operações custosas de ponto flutuante e cálculos de raiz quadrada[cite: 70]. 

[cite_start]O objetivo principal desta pesquisa é desenvolver e analisar uma abordagem que reestrutura a equação da distância euclidiana, substituindo a estrutura tradicional por uma formulação baseada unicamente em operações com números inteiros[cite: 57, 74]. [cite_start]A lógica emprega o método de **expansão binária**[cite: 46], utilizando divisões inteiras (deslocamentos de bits / *bitshifts*) para aproximar resultados com alta eficiência de processamento. 

[cite_start]Embora o escopo original previsse a implementação em hardware (FPGAs com VHDL)[cite: 52], a pesquisa direcionou seu foco analítico para a **implementação, otimização e validação da lógica de software**, garantindo a extração do máximo desempenho computacional direto na linguagem C.

## 📂 Estrutura do Repositório

O repositório está organizado da seguinte maneira:

* **/software**: Contém a implementação otimizada do algoritmo em C, isolando a lógica matemática do script de *benchmark*.
    * `distancia.h` / `distancia.c`: Biblioteca contendo a implementação da distância euclidiana tradicional e a versão aproximada via expansão binária.
    * `main.c`: Script de testes (Benchmark) que avalia o tempo de execução, erro médio absoluto, erro percentual e detecta os piores casos.
* **/hardware**: Contém descrições em VHDL elaboradas na fase inicial de exploração em hardware.
* **/docs**: Documentação do projeto, incluindo o Plano de Trabalho e o Relatório Final da Pesquisa Individual PET.

## 🚀 Como Executar o Benchmark (Software)

Para compilar e rodar os testes da implementação em C no seu terminal, certifique-se de ter o compilador `gcc` instalado e execute os seguintes comandos dentro da pasta `software`:

1.  **Compile o código** (a flag `-lm` é necessária para linkar a biblioteca matemática `math.h` da função euclidiana original):
    ```bash
    gcc main.c distancia.c -o benchmark -lm
    ```

2.  **Execute o binário gerado**:
    ```bash
    ./benchmark
    ```

O programa realizará 100.000 testes com coordenadas aleatórias e imprimirá um relatório de desempenho e precisão no terminal.

## 👨‍💻 Autoria e Orientação

* [cite_start]**Aluno Pesquisador:** Gustavo Luis de Siqueira Nascimento [cite: 5, 39]
* [cite_start]**Professor Orientador:** Prof. Daniel Duarte Abdala [cite: 5, 39]
* **Instituição:** Faculdade de Computação (FACOM) - Universidade Federal de Uberlândia (UFU)
* [cite_start]**Grupo:** COMPET (Programa de Educação Tutorial) [cite: 4, 38]
