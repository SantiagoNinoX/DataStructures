#ifndef AVL_TREE
#define AVL_TREE

/*
 *  Codigo AVL por Artemio Urbina para TC1031
 *
 *  Recuerda que este codigo es de referencia para apoyarte no lo compartas fuera de clase
 *  ni lo uses directamente en tus entregas. Estos son ejericios para que practiques y
 *  mejores tus habilidades para tu futuro.
 *
 */

#include "TemplateStack.h"

template <typename T>
class NodoAVL{
public:
    T               info;
    int             altura;
    NodoAVL<T>      *left;
    NodoAVL<T>      *right;
    NodoAVL(T dato) : info(dato), altura(0), left(nullptr), right(nullptr) {}
};

template <typename T>
class ArbolAVL{
private:
    NodoAVL<T>   *root;
    
public:
    ArbolAVL() : root(nullptr) {}
    ~ArbolAVL(){
        borrarArbol();
    }

    bool inserta(T dato) {
        return insertaRecursivo(root, dato);
    }

    bool elimina(T dato) {
        return(eliminaRecursivo(root, dato));
    }

    void borrarArbol() {
        borrarArbolRecursivo(root);
    }

    void imprimeInOrder() {
        imprimeInOrderRec(root);
        std::cout << std::endl;
    }

    void imprimirPorAlturas() {
        imprimirPorAlturasRec(root, 0);
    }

private:
    bool insertaRecursivo(NodoAVL<T> *&nodo, T dato);
    bool eliminaRecursivo(NodoAVL<T> *&nodo, T dato);
    void borrarArbolRecursivo(NodoAVL<T> *&nodo);
    NodoAVL<T>* reemplazaLeft(NodoAVL<T> *nodo, Stack<NodoAVL<T>*> &ancestrosBalancear);
    NodoAVL<T>* reemplazaRight(NodoAVL<T> *nodo, Stack<NodoAVL<T>*> &ancestrosBalancear);
    void imprimeInOrderRec(NodoAVL<T> *nodo);
    void imprimirPorAlturasRec(NodoAVL<T>* nodo, int nivel);

    int getAltura(NodoAVL<T>* nodo);
    int revisaBalance(NodoAVL<T>* nodo);
    void calculaAltura(NodoAVL<T>* nodo);
    void balancea(NodoAVL<T> *&nodo);
    NodoAVL<T>* rotacionDerecha(NodoAVL<T>* nodo);
    NodoAVL<T>* rotacionIzquierda(NodoAVL<T>* nodo);
    NodoAVL<T>* rotacionDobleDerecha(NodoAVL<T>* nodo);
    NodoAVL<T>* rotacionDobleIzquierda(NodoAVL<T>* nodo);
};

template <typename T>
bool ArbolAVL<T>::insertaRecursivo(NodoAVL<T> *&nodo, T dato) {
    if (!nodo) {
        nodo = new(std::nothrow) NodoAVL<T>(dato);
        if(!nodo)
            return false;
        
        nodo->altura = 0;
        return true;
    }

    if (dato < nodo->info) {
        if(insertaRecursivo(nodo->left, dato)) {
            calculaAltura(nodo);
            balancea(nodo);
            return true;
        }
        else
            return false;
    }
    else if (dato > nodo->info) {
        if(insertaRecursivo(nodo->right, dato)) {
            calculaAltura(nodo);
            balancea(nodo);
            return true;
        }
        else
            return false;
    }

    // El dato ya existe en el árbol, no se permite duplicados
    return false;
}

template <typename T>
void ArbolAVL<T>::borrarArbolRecursivo(NodoAVL<T> *&nodo) {
    if(!nodo)
        return;
    borrarArbolRecursivo(nodo->left);
    borrarArbolRecursivo(nodo->right);
    delete nodo;
    nodo = nullptr;
}

template <typename T>
bool ArbolAVL<T>::eliminaRecursivo(NodoAVL<T> *&actual, T dato) {
    Stack<NodoAVL<T>*> ancestrosBalancear;

    if(!actual)
        return false;

    if(dato < actual->info) {
        if(!eliminaRecursivo(actual->left, dato))
            return false;
    }
    else if (dato > actual->info) {
        if(!eliminaRecursivo(actual->right, dato))
            return false;
    }
    else {
        NodoAVL<T> *borrar = nullptr;

        borrar = actual;
        if(!actual->left)
            actual = actual->right;
        else if(!actual->right)
            actual = actual->left;
        else
            borrar = reemplazaRight(actual, ancestrosBalancear);
        delete borrar;
    }
    
    if (actual) {
        balancea(actual);
        while(!ancestrosBalancear.isEmpty()) {
            NodoAVL<T> *ancestro = ancestrosBalancear.getTop();
            calculaAltura(ancestro);
            ancestrosBalancear.pop();
        }
        calculaAltura(actual);
    }

    return true;
}

/* Asistentes de eliminar Recursivo */
template <typename T>
NodoAVL<T>* ArbolAVL<T>::reemplazaLeft(NodoAVL<T> *nodo, Stack<NodoAVL<T>*> &ancestrosBalancear) {
    NodoAVL<T> *rightmostFromLeft = nullptr, *parent = nullptr;

    parent = nodo;
    rightmostFromLeft = nodo->left;

    while(rightmostFromLeft->right) {
        parent = rightmostFromLeft;
        ancestrosBalancear.push(parent);
        rightmostFromLeft = rightmostFromLeft->right;
    }

    nodo->info = rightmostFromLeft->info;
    if(parent == nodo)
        parent->left = rightmostFromLeft->left;
    else
        parent->right = rightmostFromLeft->left;
    return rightmostFromLeft;
}

template <typename T>
NodoAVL<T>* ArbolAVL<T>::reemplazaRight(NodoAVL<T> *nodo, Stack<NodoAVL<T>*> &ancestrosBalancear) {
    NodoAVL<T> *leftmostFromRight = nullptr, *parent = nullptr;

    parent = nodo;
    leftmostFromRight = nodo->right;
    while(leftmostFromRight->left) {
        parent = leftmostFromRight;
        ancestrosBalancear.push(parent);
        leftmostFromRight = leftmostFromRight->left;
    }
    nodo->info = leftmostFromRight->info;
    if(parent == nodo)
        parent->right = leftmostFromRight->right;
    else
        parent->left = leftmostFromRight->right;
    return leftmostFromRight;
}

/* Funciones para AVL y balance */
template <typename T>
void ArbolAVL<T>::balancea(NodoAVL<T> *&nodo) {
    int balance = revisaBalance(nodo);

    // Casos de rotación
    if (balance > 1) {
        int balanceHijoLeft = revisaBalance(nodo->left);
        
        if (balanceHijoLeft >= 0)
            nodo = rotacionDerecha(nodo);
        else
            nodo = rotacionDobleDerecha(nodo);
    }

    if (balance < -1) {
        int balanceHijoRight = revisaBalance(nodo->right);
        
        if (balanceHijoRight <= 0)
            nodo = rotacionIzquierda(nodo);
        else
            nodo = rotacionDobleIzquierda(nodo);
    }
}

template <typename T>
int ArbolAVL<T>::getAltura(NodoAVL<T>* nodo)
{
    if (!nodo)
        return -1;
    return nodo->altura;
}

template <typename T>
int ArbolAVL<T>::revisaBalance(NodoAVL<T>* nodo) {
    if (!nodo)
        return -1;
    return getAltura(nodo->left) - getAltura(nodo->right);
}

template <typename T>
void ArbolAVL<T>::calculaAltura(NodoAVL<T>* nodo) {
    if(nodo)
        nodo->altura = 1 + std::max(getAltura(nodo->left), getAltura(nodo->right));
}

template <typename T>
NodoAVL<T>* ArbolAVL<T>::rotacionDerecha(NodoAVL<T>* nodo) {
    NodoAVL<T>* nRoot = nodo->left;
    NodoAVL<T>* temp = nRoot->right;

    nRoot->right = nodo;
    nodo->left = temp;

    calculaAltura(nodo);
    calculaAltura(nRoot);

    return nRoot;
}

template <typename T>
NodoAVL<T>* ArbolAVL<T>::rotacionIzquierda(NodoAVL<T>* nodo) {
    NodoAVL<T>* nRoot = nodo->right;
    NodoAVL<T>* temp = nRoot->left;

    nRoot->left = nodo;
    nodo->right = temp;

    calculaAltura(nodo);
    calculaAltura(nRoot);

    return nRoot;
}

template <typename T>
NodoAVL<T>* ArbolAVL<T>::rotacionDobleDerecha(NodoAVL<T>* nodo) {
    nodo->left = rotacionIzquierda(nodo->left);
    return rotacionDerecha(nodo);
}

template <typename T>
NodoAVL<T>* ArbolAVL<T>::rotacionDobleIzquierda(NodoAVL<T>* nodo) {
    nodo->right = rotacionDerecha(nodo->right);
    return rotacionIzquierda(nodo);
}

/* Funciones de impresion */

template <typename T>
void ArbolAVL<T>::imprimirPorAlturasRec(NodoAVL<T>* nodo, int nivel) {
    if (nodo == nullptr)
        return;

    imprimirPorAlturasRec(nodo->right, nivel + 1);

    for (int i = 0; i < nivel; ++i)
        std::cout << "    "; // Agregar espacios de indentación según el nivel
    std::cout << nodo->info << "(" << nodo->altura << ")" << std::endl;

    imprimirPorAlturasRec(nodo->left, nivel + 1);
}

template <typename T>
void ArbolAVL<T>::imprimeInOrderRec(NodoAVL<T> *nodo) {
    if(nodo == nullptr)
        return;
    imprimeInOrderRec(nodo->left);
    std::cout << nodo->info << " ";
    imprimeInOrderRec(nodo->right);
}

#endif