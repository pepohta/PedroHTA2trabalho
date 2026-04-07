# PedroHTA2trabalho
# Exercício – Lista Simplesmente Encadeada

## Descrição

Este projeto implementa uma Lista Simplesmente Encadeada, permitindo a manipulação dinâmica de elementos por meio de operações de inserção, remoção, busca e reorganização.

A lista é composta por nós encadeados, onde cada elemento aponta para o próximo, permitindo flexibilidade no uso de memória.

## Funcionalidades

- Criação da lista
- Inserção no início da rota
- Inserção no fim da rota
- Inserção em posição específica
- Remoção da primeira parada
- Remoção da última parada
- Busca de parada por nome (com correspondência parcial)
- Listagem da rota (ordem normal)
- Listagem da rota (ordem inversa)
- Contagem de paradas

---

## Estrutura Utilizada

Foi utilizada uma **Lista Duplamente Encadeada**.

Cada nó possui:
- Nome da parada
- Ponteiro para o próximo nó
- Ponteiro para o nó anterior

---

## Pontos de Análise e Justificativa

### 1. Qual variação de lista foi escolhida?

Foi escolhida a lista duplamente encadeada.

---

### 2. Por que essa estrutura é mais adequada?

A lista duplamente encadeada é mais adequada porque:

- Permite navegação em duas direções (ida e volta)
- Torna remoções mais eficientes, pois cada nó possui referência ao anterior
- Melhora a manipulação da lista sem necessidade de percorrer desde o início

---

### 3. Há cenário onde outra lista seria melhor?

Sim.

Em um cenário de linha circular de ônibus, onde o trajeto não possui início ou fim definido, uma lista circular seria mais vantajosa.

Nesse caso:
- O último nó aponta para o primeiro
- Permite navegação contínua

---

## Pré-requisitos

- Compilador: G++  
- Debugger: GDB (opcional)  
- Editor: Visual Studio Code (opcional)  

---

## Compilação e Execução

```bash
g++ main.cpp src/linked_list.cpp -o programa
.\programa.exe

g++ tests/tests.cpp src/linked_list.cpp -o testes
- Dentro da pasta testes:
.\testes.exe