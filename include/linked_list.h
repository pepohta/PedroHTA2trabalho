#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>

using namespace std;

struct Node {
    string nome;
    Node* anterior;
    Node* proximo;
};

struct ListaDuplamenteEncadeada {
    int cardinalidade;
    Node* inicio;
    Node* fim;
};

ListaDuplamenteEncadeada* criaLista();
void destroiLista(ListaDuplamenteEncadeada& lista);

bool listaVazia(const ListaDuplamenteEncadeada& lista);
int contarParadas(const ListaDuplamenteEncadeada& lista);

void inserirNoInicio(ListaDuplamenteEncadeada& lista, const string& nome);
void inserirNoFim(ListaDuplamenteEncadeada& lista, const string& nome);
bool inserirNaPosicao(ListaDuplamenteEncadeada& lista, const string& nome, int posicao);

bool removerPrimeiraParada(ListaDuplamenteEncadeada& lista);
bool removerUltimaParada(ListaDuplamenteEncadeada& lista);

Node* buscarParadaPorNome(const ListaDuplamenteEncadeada& lista, const string& trecho);

void listarRotaIda(const ListaDuplamenteEncadeada& lista);
void listarRotaVolta(const ListaDuplamenteEncadeada& lista);

string obterParadaNaPosicao(const ListaDuplamenteEncadeada& lista, int posicao);

string paraMinusculo(string texto);
bool contemTrecho(const string& texto, const string& trecho);

#endif