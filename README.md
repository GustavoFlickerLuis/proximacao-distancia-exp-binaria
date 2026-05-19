Aproximação Inteira da Distância Euclidiana via Expansão Binária 📐

📌 Sobre o Projeto

O cálculo de distâncias entre pontos em espaços N-dimensionais é fundamental em diversas áreas da computação, como Análise de Dados e Aprendizado de Máquina, mas tradicionalmente exige operações custosas de ponto flutuante e cálculos de raiz quadrada.

O objetivo principal desta pesquisa é desenvolver e analisar uma abordagem que reestrutura a equação da distância euclidiana, substituindo a estrutura tradicional por uma formulação baseada unicamente em operações com números inteiros. A lógica emprega o método de expansão binária, utilizando divisões inteiras (deslocamentos de bits / bitshifts) para aproximar resultados com alta eficiência de processamento.

Embora o escopo original previsse a implementação em hardware (FPGAs com VHDL), a pesquisa direcionou seu foco analítico para a implementação, otimização e validação da lógica de software, garantindo a extração do máximo desempenho computacional direto na linguagem C.

📂 Estrutura do Repositório

O repositório está organizado da seguinte maneira:

📁 /software: Contém a implementação otimizada do algoritmo em C, isolando a lógica matemática do script de benchmark.

distancia.h / distancia.c: Biblioteca contendo a implementação da distância euclidiana tradicional e a versão aproximada via expansão binária.

main.c: Script de testes (Benchmark) que avalia o tempo de execução, erro médio absoluto, erro percentual e detecta os piores casos.

📁 /hardware: Contém a implementação da distância euclidiana tradicional e expansão binaria em VHDL

👨‍💻 Autoria e Orientação

🎓 Aluno Pesquisador: Gustavo Luis de Siqueira Nascimento
👨‍🏫 Professor Orientador: Prof. Daniel Duarte Abdala
🏛 Instituição: Faculdade de Computação (FACOM) - Universidade Federal de Uberlândia (UFU)
🌟 Grupo: COMPET (Programa de Educação Tutorial)
