// Daniel Parra Ponce
// PEP 2 - Problema 3
// 21.01.20
// Rosa Barrera Capot

#include <iostream>
using namespace std;

struct nodo{
    int dato;
    nodo * L;
    nodo * R;
};

nodo* ingreso(nodo *A, int x);
int queNivel(nodo * A, int x);
int nodeType(nodo * A, int x);
int esta (nodo *A, int x);

int main(){
    int i;
    char op;
    nodo * root;                                                 // Se asume que el arbol ya existe, y root es la raiz
    cout << "Ingrese nro. a encontrar: ";
    cin >> i;
    if(esta(root, i)){
        cout << "El elemento se encuentra en el nivel " << queNivel(root, i) << "y es ";
        if (root->dato==i)                                      //Si el dato raiz es igual al ingresado...
            cout << "raiz" << endl;
        else if(nodeType(root, i))
            cout << "nodo Interno" << endl;
        else if(!nodeType(root, i))
            cout << "hoja" << endl;
    }
    else{
        cout << "No se ha encontrado, desea agregarlo? (y/n)" << endl;
        cin >> op;
        if(op=='y')
            ingreso(root, i);
    }
}

int esta(nodo * A, int x){                                      // Funcion esta para un arbol binario ordenado
    if(!A)
        return 0;
    if(A->dato==x)
        return 1;
    else if (A->dato > x)
        return esta(A->L, x);
        else
            return esta(A->R, x);
}

int queNivel(nodo * A, int x){                                  // Funcion que cuenta recursivamente el nivel
    if (A->dato==x){
        return 1;
    }
    else if (A->dato > x)
        return queNivel(A->L, x)+1;
        else
            return queNivel(A->R, x)+1;
}

int nodeType(nodo * A, int x){                                  // Funcion que indentifica que tipo de nodo es
    if (A->dato==x){
        if(!A->L&&!A->R)                                        // Si ambos nodos hijos están vacíos, entonces el dato es hoja, y retorna 0.
            return 0;
        return 1;                                               // Si no, retorna 1, y es nodo interno.
    }
    else if (A->dato > x)
        return nodeType(A->L, x);
        else
            return nodeType(A->R, x);
}
