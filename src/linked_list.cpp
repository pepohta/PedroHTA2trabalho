#include "../include/linked_list.h"
#include <iostream>
#include <cctype>

using namespace std;

string paraMinusculo(string texto) {
    for (int i = 0; i < texto.size(); i++) {
        texto[i] = tolower(texto[i]);
    }
    return texto;
}

bool contemTrecho(const string& texto, const string& trecho) {
    string t1 = paraMinusculo(texto);
    string t2 = paraMinusculo(trecho);
    return t1.find(t2) != string::npos;
}

ListaDuplamenteEncadeada* criaLista() {
    ListaDuplamenteEncadeada* lista = new ListaDuplamenteEncadeada;
    lista->cardinalidade = 0;
    lista->inicio = NULL;
    lista->fim = NULL;
    return lista;
}

void destroiLista(ListaDuplamenteEncadeada& lista) {
    Node* atual = lista.inicio;

    while (atual != NULL) {
        Node* temp = atual;
        atual = atual->proximo;
        delete temp;
    }

    lista.inicio = NULL;
    lista.fim = NULL;
    lista.cardinalidade = 0;
}

bool listaVazia(const ListaDuplamenteEncadeada& lista) {
    return lista.inicio == NULL;
}

int contarParadas(const ListaDuplamenteEncadeada& lista) {
    return lista.cardinalidade;
}

void inserirNoInicio(ListaDuplamenteEncadeada& lista, const string& nome) {
    Node* novo = new Node;
    novo->nome = nome;
    novo->anterior = NULL;
    novo->proximo = lista.inicio;

    if (lista.inicio != NULL)
        lista.inicio->anterior = novo;
    else
        lista.fim = novo;

    lista.inicio = novo;
    lista.cardinalidade++;
}

void inserirNoFim(ListaDuplamenteEncadeada& lista, const string& nome) {
    Node* novo = new Node;
    novo->nome = nome;
    novo->proximo = NULL;
    novo->anterior = lista.fim;

    if (lista.fim != NULL)
        lista.fim->proximo = novo;
    else
        lista.inicio = novo;

    lista.fim = novo;
    lista.cardinalidade++;
}

bool inserirNaPosicao(ListaDuplamenteEncadeada& lista, const string& nome, int posicao) {
    if (posicao < 0 || posicao > lista.cardinalidade)
        return false;

    if (posicao == 0) {
        inserirNoInicio(lista, nome);
        return true;
    }

    if (posicao == lista.cardinalidade) {
        inserirNoFim(lista, nome);
        return true;
    }

    Node* atual = lista.inicio;

    for (int i = 0; i < posicao; i++)
        atual = atual->proximo;

    Node* novo = new Node;
    novo->nome = nome;

    novo->proximo = atual;
    novo->anterior = atual->anterior;

    atual->anterior->proximo = novo;
    atual->anterior = novo;

    lista.cardinalidade++;
    return true;
}

bool removerPrimeiraParada(ListaDuplamenteEncadeada& lista) {
    if (listaVazia(lista))
        return false;

    Node* temp = lista.inicio;

    if (lista.inicio == lista.fim) {
        lista.inicio = NULL;
        lista.fim = NULL;
    } else {
        lista.inicio = lista.inicio->proximo;
        lista.inicio->anterior = NULL;
    }

    delete temp;
    lista.cardinalidade--;
    return true;
}

bool removerUltimaParada(ListaDuplamenteEncadeada& lista) {
    if (listaVazia(lista))
        return false;

    Node* temp = lista.fim;

    if (lista.inicio == lista.fim) {
        lista.inicio = NULL;
        lista.fim = NULL;
    } else {
        lista.fim = lista.fim->anterior;
        lista.fim->proximo = NULL;
    }

    delete temp;
    lista.cardinalidade--;
    return true;
}

Node* buscarParadaPorNome(const ListaDuplamenteEncadeada& lista, const string& trecho) {
    Node* atual = lista.inicio;

    while (atual != NULL) {
        if (contemTrecho(atual->nome, trecho))
            return atual;
        atual = atual->proximo;
    }

    return NULL;
}

void listarRotaIda(const ListaDuplamenteEncadeada& lista) {
    if (listaVazia(lista)) {
        cout << "Rota vazia." << endl;
        return;
    }

    Node* atual = lista.inicio;
    int i = 0;

    while (atual != NULL) {
        cout << i << " - " << atual->nome << endl;
        atual = atual->proximo;
        i++;
    }
}

void listarRotaVolta(const ListaDuplamenteEncadeada& lista) {
    if (listaVazia(lista)) {
        cout << "Rota vazia." << endl;
        return;
    }

    Node* atual = lista.fim;
    int i = lista.cardinalidade - 1;

    while (atual != NULL) {
        cout << i << " - " << atual->nome << endl;
        atual = atual->anterior;
        i--;
    }
}

string obterParadaNaPosicao(const ListaDuplamenteEncadeada& lista, int posicao) {
    if (posicao < 0 || posicao >= lista.cardinalidade)
        return "";

    Node* atual = lista.inicio;

    for (int i = 0; i < posicao; i++)
        atual = atual->proximo;

    return atual->nome;
}