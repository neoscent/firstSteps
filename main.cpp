#include <iostream>
using namespace std;

struct node{
    int dato;
    node * L;
    node * R;
};

node* enterData(node *A, int x);
int contarNodo(node * A);
void inorden(node *A);
void preorden(node *A);
void postorden(node *A);
int esta (node *A, int x);
node* eliminar(node* A, int x);

int main(){
    int i=0, no[9]={7,15,11,1,9,5,13,3,17};
    node * root;
    root = NULL;
    while(i<9){
        root=enterData(root, no[i]);
        i++;
    }
    cout << "El arbol contiene " << contarNodo(root) << "nodos." <<endl;
    cout << "InOrder: ";
    inorden(root);
    cout << "\nPreOrder: ";
    preorden(root);
    cout << "\nPostOrder: ";
    postorden(root);
    return 0;
}

node* enterData(node *A, int x){
    if(A==NULL){
        A = new node;
        if(!A){
          cout << "NO HAY SUFICIENTE MEMORIA";
            return A;
        }
        A->dato=x;
        A->L=A->R=NULL;
    }
    else if(A->dato < x)
        A->R=enterData(A->R,x);
    else if (A->dato > x)
        A->L=enterData(A->L,x);
    else{
        cout << "EL ELEMENTO YA EXISTE, NO PUEDE REPETIRSE";
    cin.get();
  }
    return A;
}

int contarNodo(node * A){
    if (A){
        int izq = contarNodo(A->L);
        int der = contarNodo(A->R);
        int medio = 1;
        return izq + der + medio;
    }
    return 0;
}

void inorden(node *A){
    if(A){
        inorden(A->L);
        cout << A->dato<<" - ";
        inorden(A->R);
    }
}

void preorden(node *A){
    if(A){
        cout << A->dato <<" - ";
        preorden(A->L);
        preorden(A->R);
    }
}

void postorden(node *A){
    if(A){
        postorden(A->L);
        postorden(A->R);
        cout << A->dato <<" - ";
    }
}

int esta (node *A, int x){
    if(!A)
        return 0;
    if(A->dato==x)
        return 1;
    else if(A->dato > x)
        return esta(x, A->L);
        else
            return esta(x, A->R);
}

node* eliminar(node* A, int x){
    node *p;
    int Mayor;
    if(A->dato == x){
        if(A->L == NULL && A->R == NULL){                            // caso 1: El elemento se encuentra en una hoja
            delete A;
            return NULL;
        }
        else if(A->L == NULL){                                       // caso 2: La rama izquierda del dato es nula y en la derecha
            p= A->R;                                                 // hay información
            delete A;
            return p;
        }
        else{
        Mayor=MayorElem(A->L);                                      // Caso 3: Que sea un nodo interno con rama izq. y rama der.
            A->dato = Mayor;
            A->L = eliminar(A->L, Mayor);
        }
    }
    else{
        if (A->dato > x)                                            // Parte recursiva para recorrer el arbol hasta encontrar elemento
            A->L = eliminar(A->L, x);
        else
            A->R = eliminar(A->R, x);
  }
    return A;
}

/*
    Notas:
            Un nodo interno es aquel que no es Hoja.
            Un nodo hoja es aquel que no tiene nodos hijos.
            El grado es el nivel en que se encuentra el último nodo interno.
            La altura es el nivel máximo alcanzado.
            El nivel se cuenta desde la raiz (1) hasta abajo (n)
 
Para encontrar la altura, se necesita dividir recursivamente el árbol en otros más pequeños.
Para ver si existe un camino entre un elemento y otro, se buscan ambos elementos, y del primero que se encuentre
se declara como raíz de un subárbol, y a este se le aplica esta(); para buscar el otro elemento.
 */
