#include <iostream>
#include "include/linked_list.h"

using namespace std;

void menu() {
    cout << endl;
    cout << "===== MENU =====" << endl;
    cout << "1 Inserir inicio" << endl;
    cout << "2 Inserir fim" << endl;
    cout << "3 Inserir posicao" << endl;
    cout << "4 Remover inicio" << endl;
    cout << "5 Remover fim" << endl;
    cout << "6 Buscar parada" << endl;
    cout << "7 Listar ida" << endl;
    cout << "8 Listar volta" << endl;
    cout << "9 Contar paradas" << endl;
    cout << "0 Sair" << endl;
    cout << "Opcao: ";
}

int main() {
    ListaDuplamenteEncadeada* lista = criaLista();
    int op;

    do {
        menu();
        cin >> op;
        cin.ignore();

        switch (op) {
            case 1: {
                string nome;
                cout << "Nome: ";
                getline(cin, nome);
                inserirNoInicio(*lista, nome);
                break;
            }

            case 2: {
                string nome;
                cout << "Nome: ";
                getline(cin, nome);
                inserirNoFim(*lista, nome);
                break;
            }

            case 3: {
                string nome;
                int pos;
                cout << "Nome: ";
                getline(cin, nome);
                cout << "Posicao: ";
                cin >> pos;
                cin.ignore();
                inserirNaPosicao(*lista, nome, pos);
                break;
            }

            case 4:
                removerPrimeiraParada(*lista);
                break;

            case 5:
                removerUltimaParada(*lista);
                break;

            case 6: {
                string nome;
                cout << "Buscar: ";
                getline(cin, nome);
                Node* n = buscarParadaPorNome(*lista, nome);
                if (n != NULL)
                    cout << "Encontrado: " << n->nome << endl;
                else
                    cout << "Nao encontrado" << endl;
                break;
            }

            case 7:
                listarRotaIda(*lista);
                break;

            case 8:
                listarRotaVolta(*lista);
                break;

            case 9:
                cout << "Total: " << contarParadas(*lista) << endl;
                break;

        }

    } while (op != 0);

    destroiLista(*lista);
    delete lista;

    return 0;
}