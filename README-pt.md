# Menu de Métodos de Ordenação em C

## Descrição

Esta é uma aplicação de console simples, desenvolvida em linguagem C, que permite ao usuário comparar o desempenho de três algoritmos de ordenação clássicos: Bubble Sort, Insertion Sort e Selection Sort.

O programa gera um vetor de números aleatórios e, em seguida, o usuário pode escolher qual método de ordenação aplicar, visualizando o tempo de execução de cada um.

## Tecnologias Utilizadas

* **Linguagem:** C

## Práticas Adotadas

* **Programação Procedural**
* **Interface Orientada a Menu**
* **Alocação Dinâmica de Memória**
* **Medição de Desempenho (Tempo de Execução)**

## Como Executar

1.  **Pré-requisitos:**
    * Um compilador C instalado (por exemplo, GCC).

2.  **Compilação:**
    * Clone o repositório ou baixe o arquivo `OrdençãoComMenu.c`.
    * Abra um terminal no diretório onde o arquivo está localizado.
    * Execute o seguinte comando para compilar o programa:
        ```bash
        gcc OrdençãoComMenu.c -o menu_ordenacao
        ```

3.  **Execução:**
    * Após a compilação, execute o programa com o comando:
        ```bash
        ./menu_ordenacao
        ```

## Como Usar o Sistema

Após executar o programa, um menu interativo será exibido no console. O fluxo de uso é o seguinte:

1.  **Gerar o Vetor:**
    * Primeiro, escolha a **Opção 1** para gerar um vetor com números aleatórios. Você precisará fazer isso antes de poder ordenar.
2.  **Escolher um Método de Ordenação:**
    * Escolha uma das opções de ordenação para aplicar ao vetor gerado:
        * **Opção 2:** Bubble Sort
        * **Opção 3:** Insertion Sort
        * **Opção 4:** Selection Sort
    * O programa exibirá o vetor original, o vetor ordenado e o tempo que o algoritmo levou para ser executado.
3.  **Repetir ou Sair:**
    * Você pode testar outros métodos de ordenação com o mesmo vetor ou gerar um novo vetor na **Opção 1**.
    * Para encerrar o programa, escolha a **Opção 5**.
