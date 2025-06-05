// codigo d
void imprimirInOrdem(No* raiz) {
    if (raiz != NULL) {
        imprimirInOrdem(raiz->esquerdo);
        printf("%d ", raiz->dado);
        imprimirInOrdem(raiz->direito);
    }
}
//
//

// codigo e
void imprimirPreOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);
        imprimirPreOrdem(raiz->esquerdo);
        imprimirPreOrdem(raiz->direito);
    }
}
//
//

// codigo f
void imprimirPosOrdem(No* raiz) {
    if (raiz != NULL) {
        imprimirPosOrdem(raiz->esquerdo);
        imprimirPosOrdem(raiz->direito);
        printf("%d ", raiz->dado);
    }
}
//
//

// codigo g
int altura(No* raiz) {
    if (raiz == NULL) {
        return -1;
    }
    int alturaEsq = altura(raiz->esquerdo);
    int alturaDir = altura(raiz->direito);
    return (alturaEsq > alturaDir ? alturaEsq : alturaDir) + 1;
}
//
//

// codigo h
int profundidade(No* raiz, int valor, int nivel) {
    if (raiz == NULL) return -1;
    if (raiz->dado == valor) return nivel;
    
    int profEsq = profundidade(raiz->esquerdo, valor, nivel + 1);
    if (profEsq != -1) return profEsq;
    
    return profundidade(raiz->direito, valor, nivel + 1);
}
//
//

// codigo i
int somaValores(No* raiz) {
    if (raiz == NULL) return 0;
    return raiz->dado + somaValores(raiz->esquerdo) + somaValores(raiz->direito);
}
//
//

// codigo j
int nivelNo(No* raiz, int valor) {
    return profundidade(raiz, valor, 0);
}
//
//

// codigo k
int contarNos(No* raiz) {
    if (raiz == NULL) return 0;
    return 1 + contarNos(raiz->esquerdo) + contarNos(raiz->direito);
}
//
//

// codigo l
int contarFolhas(No* raiz) {
    if (raiz == NULL) return 0;
    if (raiz->esquerdo == NULL && raiz->direito == NULL) return 1;
    return contarFolhas(raiz->esquerdo) + contarFolhas(raiz->direito);
}
//
//

//funçao auxiliar para limpar memoria.
void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerdo);
        liberarArvore(raiz->direito);
        free(raiz);
    }
}
//
//