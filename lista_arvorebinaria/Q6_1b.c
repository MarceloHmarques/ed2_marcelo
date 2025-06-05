// codigo b
#include <stdio.h>
#include <stdlib.h>

// Função para criar um novo nó
No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    novo->dado = valor;
    novo->esquerdo = NULL;
    novo->direito = NULL;
    return novo;
}

// Função para inserir um valor na árvore
No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->dado) {
        raiz->esquerdo = inserir(raiz->esquerdo, valor);
    } else if (valor > raiz->dado) {
        raiz->direito = inserir(raiz->direito, valor);
    }
    return raiz;
}

No* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->dado == valor) {
        return raiz;
    }
    if (valor < raiz->dado) {
        return buscar(raiz->esquerdo, valor);
    }
    return buscar(raiz->direito, valor);
}

No* encontrarMinimo(No* no) {
    while (no->esquerdo != NULL) {
        no = no->esquerdo;
    }
    return no;
}

No* remover(No* raiz, int valor) {
    if (raiz == NULL) return raiz;
    
    if (valor < raiz->dado) {
        raiz->esquerdo = remover(raiz->esquerdo, valor);
    } else if (valor > raiz->dado) {
        raiz->direito = remover(raiz->direito, valor);
    } else {
        if (raiz->esquerdo == NULL) {
            No* temp = raiz->direito;
            free(raiz);
            return temp;
        } else if (raiz->direito == NULL) {
            No* temp = raiz->esquerdo;
            free(raiz);
            return temp;
        }
        
        No* temp = encontrarMinimo(raiz->direito);
        raiz->dado = temp->dado;
        raiz->direito = remover(raiz->direito, temp->dado);
    }
    return raiz;
}