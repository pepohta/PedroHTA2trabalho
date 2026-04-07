#include <iostream>
#include "../include/linked_list.h"

using namespace std;

void verificar(bool condicao, string mensagem) {
    if (condicao)
        cout << "[OK] " << mensagem << endl;
    else
        cout << "[ERRO] " << mensagem << endl;
}

void testeInsercao() {
    ListaDuplamenteEncadeada* lista = criaLista();

    inserirNoFim(*lista, "A");
    inserirNoFim(*lista, "B");
    inserirNoFim(*lista, "C");

    verificar(contarParadas(*lista) == 3, "Insercao - quantidade");
    verificar(obterParadaNaPosicao(*lista, 0) == "A", "Insercao - pos 0");
    verificar(obterParadaNaPosicao(*lista, 1) == "B", "Insercao - pos 1");
    verificar(obterParadaNaPosicao(*lista, 2) == "C", "Insercao - pos 2");

    destroiLista(*lista);
    delete lista;
}

void testeRemocao() {
    ListaDuplamenteEncadeada* lista = criaLista();

    inserirNoFim(*lista, "A");
    inserirNoFim(*lista, "B");
    inserirNoFim(*lista, "C");

    removerPrimeiraParada(*lista);
    verificar(obterParadaNaPosicao(*lista, 0) == "B", "Remover inicio");

    removerUltimaParada(*lista);
    verificar(contarParadas(*lista) == 1, "Remover fim");

    destroiLista(*lista);
    delete lista;
}

void testeBusca() {
    ListaDuplamenteEncadeada* lista = criaLista();

    inserirNoFim(*lista, "Terminal Norte");
    inserirNoFim(*lista, "Centro");
    inserirNoFim(*lista, "Universidade");

    Node* n = buscarParadaPorNome(*lista, "Centro");

    verificar(n != NULL, "Busca encontrou");
    if (n != NULL)
        verificar(n->nome == "Centro", "Busca correta");

    destroiLista(*lista);
    delete lista;
}

int main() {
    cout << "Iniciando testes..." << endl;

    testeInsercao();
    testeRemocao();
    testeBusca();

    cout << "Testes finalizados." << endl;

    return 0;
}