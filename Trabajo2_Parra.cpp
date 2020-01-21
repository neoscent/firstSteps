// Daniel Parra Ponce
// Trabajo I
// 30.10
// Rosa Barrera Capot
// GNU GCC Compiler
// IDE: XCode 11.0

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct careerLec
{
    char name[100];
    int demre;
    char titulo[30];
    char grado[30];
    int largo;
    int acredAn;
    char etica[3];
    char intGrad[3];
    int asign;
};

struct asignLec
{
    char name[100];
    int nivel;
    int cred;
    int teo;
    int ejec;
    int practica;
    char tipo[30];
};

struct asign
{
    char name[100];
    int nivel;
    int cred;
    int teo;
    int ejec;
    int practica;
    char tipo[30];
    asign * next;
};

struct career
{
    char name[100];
    int demre;
    char titulo[30];
    char grado[30];
    int largo;
    int acredAn;
    char etica[3];
    char intGrad[3];
    int asign;
    career * next;
    struct asign * top;
};

class carrera
{
private:
    career * top;
public:
    void mostrar();
    void mostrarNodo(career * q);
    void mostrarAsig(asign * top);
    void ingresar();
    void entCar(career w);
    asign *entAs(asign x, asign * head);
    void addCareer();
    void addAsign(career * q);
    void delAsign(career * q);
    void menuModAsign(career * q);
    void eliminar(career * q);
    void save();
    asign saveAs(asign toList, asign * fromList);
    career saveCar(career toList, career * fromList);
    void Main();
    void menuIni();
    void menuVer();
    void menuMod();
    void menuModCareer(career * q);
    void modCareer(career * q);
    void search();
    void verAsign(career * q);
    carrera();
    ~carrera();
};

int main(){
    carrera a;
    a.Main();
    return 0;
}

void carrera::Main(){
    ingresar();
    menuIni();
}

void carrera::menuIni(){
    int option;
    do{
        cout << "(1) Ver Carreras" << endl;
        cout << "(2) Modificar Info." << endl;
        cout << "(3) Guardar Mod." << endl;
        cout << "(4) Salir" << endl;
        cout << "Ingresa Opcion: ";
        cin >> option;
        switch (option){
            case 1:
                menuVer();
                break;
            case 2:
                menuMod();
                break;
            case 3:
                save();
                break;
            case 4:
                exit(0);
                break;
            default:
                cout << "Opcion no valida" << endl;
        }
        system("cls");
    }while(option!=4);
    
}

void carrera::menuVer(){
    int option;
    system("cls");
    do{
        cout << "(1) Mostrar Todas" << endl;
        cout << "(2) Buscar carrera" << endl;
        cout << "(3) Volver" << endl;
        cout << "Ingresa Opcion: ";
        cin >> option;
        system("cls");
        switch (option){
            case 1:
                mostrar();
                break;
            case 2:
                search();
                break;
            default:
                cout << "Opcion no valida" << endl;
        }
        system("cls");
    }while(option!=3);
    
}

void carrera::menuMod(){
    int option = 0, demCod;
    career * q;
    q = top;
    system("cls");
    do{
        cout << "(1) Agregar Carrera" << endl;
        cout << "(2) Modificar Carrera" << endl;
        cout << "(3) Volver" << endl;
        cout << "Ingresa Opcion: ";
        cin >> option;
        system("cls");
        switch (option){
            case 1:
                addCareer();
                break;
            case 2:
                cout << "Ingrese codigo Demre: ";
                cin >> demCod;
                while(q&&q->demre!=demCod){
                    q = q -> next;
                }
                if(q&&q->demre==demCod)
                    menuModCareer(q);
                else
                    cout << "Codigo inexistente" << endl;
                break;
            case 3:
                break;
            default:
                cout << "Opcion no valida" << endl;
                system("PAUSE");
            }
        system("cls");
    }while(option!=3);
    
}

void carrera::menuModAsign(career * q){
    int op;
    char option;
    asign * p;
    system("cls");
    p = q -> top;
    do{
        mostrarAsig(p);
        cout << "Es esta la asignatura a modificar?";
        cin >> option;
        system("cls");
        if (option=='n')
            p = p -> next;
    }while(p&&option=='n');
    cout << "Elige elemento a modificar: " << endl;
    cout << "\t(1) Nombre" << endl;
    cout << "\t(2) Nivel" << endl;
    cout << "\t(3) STC" << endl;
    cout << "\t(4) Horas de Teoria" << endl;
    cout << "\t(5) Horas de Ejercitacion" << endl;
    cout << "\t(6) Horas de Practica" << endl;
    cout << "\t(7) Naturaleza" << endl;
    cout << "\t(8) Volver" << endl;
    cout << "Opcion: ";
    cin >> op;
    system ("cls");
    switch (op){
        case 1:
            cout << "Nombre: ";
            cin >> p -> name;
            break;
        case 2:
            cout << "Nivel: ";
            cin >> p -> nivel;
            break;
        case 3:
            cout << "STC: ";
            cin >> p -> cred;
            break;
        case 4:
            cout << "Hrs. Teoria: ";
            cin >> p -> teo;
            break;
        case 5:
            cout << "Hrs. Ejercitacion: ";
            cin >> p -> ejec;
            break;
        case 6:
            cout << "Hrs. Practica: ";
            cin >> p -> practica;
            break;
        case 7:
            cout << "Naturaleza: ";
            cin >> p -> tipo;
            break;
        case 8:
            break;
        default:
            cout << "Opcion no valida" << endl;
    }
}


void carrera::menuModCareer(career * q){
    int option;
    system("cls");
    cout << "(1) Modificar Datos" << endl;
    cout << "(2) Modificar Asignatura" << endl;
    cout << "(3) Agregar Asignatura" << endl;
    cout << "(4) Eliminar Asignatura" << endl;
    cout << "(5) Eliminar Carrera" << endl;
    cout << "(6) Volver" << endl;
    cout << "Ingrese una opcion: ";
    cin >> option;
    system("cls");
    switch (option){
        case 1:
            modCareer(q);
            break;
        case 2:
            menuModAsign(q);
            break;
        case 3:
            addAsign(q);
            break;
        case 4:
            delAsign(q);
            break;
        case 5:
            eliminar(q);
            break;
        case 6:
            break;
        default:
            cout << "Opcion no valida..." << endl;
    }
}


void carrera::ingresar(){
    int n;
    ifstream inFile;
    career w;
    asign x, * head = NULL;
    inFile.open("data2.txt");
    if (inFile.fail()){
        cout << "Archivo no encontrado, por favor ubique archivo y reinicie el programa." << endl;
        system("PAUSE");
        exit(0);
    }
    while(!inFile.eof()&&!inFile.fail()){
        inFile.read((char *)(&w), sizeof(careerLec));
        entCar(w);
        for(n=0; n < w.asign; n++){
            inFile.read((char *)(&x), sizeof(asignLec));
            head = entAs(x, head);
        }
        head = NULL;
    }
    eliminar(top);
}

void carrera::entCar(career w){
    career * q = new career;
    strcpy(q -> name, w.name);
    q -> demre = w.demre;
    strcpy(q -> titulo, w.titulo);
    strcpy(q -> grado, w.grado);
    q -> largo = w.largo;
    q -> acredAn = w.acredAn;
    strcpy(q -> etica, w.etica);
    strcpy(q -> intGrad, w.intGrad);
    q -> asign = w.asign;
    q -> next = top;
    top = q;
}

asign* carrera::entAs(asign x, asign * head){
    asign * p = new asign;
    strcpy(p -> name, x.name);
    p -> nivel = x.nivel;
    p -> cred = x.cred;
    p -> teo = x.teo;
    p -> ejec = x.ejec;
    p -> practica = x.practica;
    strcpy(p -> tipo, x.tipo);
    p -> next = head;
    head = p;
    top -> top = p;
    return p;
}

void carrera::eliminar(career * q){
    career * p = top;
    if (p!=q){
        while(p->next!=q){
            p=p->next;
        }
        p -> next = q -> next;
    }
    else
        top = q -> next;
    delete q;
}

void carrera::addCareer(){
    int i;
    char option;
    career * q = new career;
    cout << "Ingresar nombre: ";
    cin >> q -> name;
    cout << "Ingresar Codigo Demre: ";
    cin >> q->demre;
    cout << "\nIngrese titulo: ";
    cin >> q -> titulo;
    cout << "\nIngrese Grado: ";
    cin >> q -> grado;
    cout << "\nIngrese duracion de la carrera (en semestres): ";
    cin >> q -> largo;
    cout << "\nIngrese anos de acreditacion: ";
    cin >> q -> acredAn;
    cout << "\nTiene etica? (si/no): ";
    cin >> q -> etica;
    cout << "\nTiene grados intermedios? (si/no): ";
    cin >> q -> intGrad;
    cout << "\nIngrese cantidad de asignaturas: ";
    cin >> q -> asign;
    cout << "\nDesea anadir asignaturas? (y/n): ";
    cin >> option;
    switch (option){
        case 'y':
            for(i=0; i<q->asign&&option=='y'; i++){
                addAsign(q);
                cout << "Anadir otra? (y/n): ";
                cin >> option;
                system("cls");
            }
            break;
        case 'n':
            q -> top = NULL;
            break;
        default:
            cout << "Opcion ingresada no es valida..." << endl;
    }
    q -> next = top;
    top = q;
}

void carrera::modCareer(career * q){
    int option;
    cout << "Elige elemento a modificar: " << endl;
    cout << "\t(1) Nombre" << endl;
    cout << "\t(2) Codigo Demre" << endl;
    cout << "\t(3) Titulo" << endl;
    cout << "\t(4) Grado" << endl;
    cout << "\t(5) Duracion" << endl;
    cout << "\t(6) Anos de Acreditacion" << endl;
    cout << "\t(7) Etica" << endl;
    cout << "\t(8) Grados Intermedios" << endl;
    cout << "\t(9) Cantidad de Asignaturas" << endl;
    cout << "\t(0) Volver" << endl;
    cout << "Opcion: ";
    cin >> option;
    system ("cls");
    switch (option){
        case 1:
            cout << "Nombre: ";
            cin >> q -> name;
            break;
        case 2:
            cout << "Codigo: ";
            cin >> q -> demre;
            break;
        case 3:
            cout << "Titulo: ";
            cin >> q -> titulo;
            break;
        case 4:
            cout << "Grado: ";
            cin >> q -> grado;
            break;
        case 5:
            cout << "Duracion: ";
            cin >> q -> largo;
            break;
        case 6:
            cout << "Acreditacion: ";
            cin >> q -> acredAn;
            break;
        case 7:
            cout << "Etica (si/no): ";
            cin >> q -> etica;
            break;
        case 8:
            cout << "Grados intermedios (si/no): ";
            cin >> q -> intGrad;
            break;
        case 9:
            cout << "Cantidad de Asignaturas: ";
            cin >> q -> asign;
            break;
        case 0:
            break;
    }
}

void carrera::addAsign(career * q){
    asign * p = new asign;
    cout << "Ingresar nombre: ";
    cin >> p -> name;
    cout << "\nIngrese Semestre: ";
    cin >> p -> nivel;
    cout << "\nIngrese STC: ";
    cin >> p -> cred;
    cout << "\nIngrese Horas de Teoria: ";
    cin >> p -> teo;
    cout << "\nIngrese Horas de Ejercitacion: ";
    cin >> p -> ejec;
    cout << "\nIngrese Hora de Practica: ";
    cin >> p -> practica;
    cout << "\nIngrese Naturaleza de la Asignatura: ";
    cin >> p -> tipo;
    p -> next = q -> top;
    q -> top = p;
    system("cls");
}

void carrera::delAsign(career * q){
    char option;
    asign * p = q -> top, * w = NULL;
    do{
        mostrarAsig(p);
        cout << "Es esta la asignatura a eliminar?";
        cin >> option;
        system("cls");
        if (option=='n'){
            w = p;
            p = p -> next;
        }
    }while(p&&option=='n');
    if (p!=q->top)
        w -> next = p -> next;
    else
        q -> top = p -> next;
    delete p;
}

void carrera::mostrar(){
    char option;
    career * q = top;
    while (q){
        mostrarNodo(q);
        cout << "Ver asignaturas? (y/n)" << endl;
        cin >> option;
        option=tolower(option);
        switch (option){
            case 'y':
                verAsign(q);
                break;
        }
        system("cls");
        q = q -> next;
    }
}

void carrera::mostrarAsig(asign * top){
        cout << "Asignatura: " << top -> name << endl;
        cout << "Semestre: " << top -> nivel << endl;
        cout << "STC: " << top -> cred << endl;
        cout << "Horas Teoria: " << top -> teo << endl;
        cout << "Horas Ejercicio: " << top -> ejec << endl;
        cout << "Horas Practica: " << top -> practica << endl;
        cout << "Naturaleza: " << top -> tipo << endl;
        system("PAUSE");
        system("cls");
        top = top -> next;
}


void carrera::mostrarNodo(career * q){
    cout << "Nombre: " << q->name << endl;
    cout << "Codigo: " << q->demre << endl;
    cout << "Titulo: " << q->titulo << endl;
    cout << "Grado: " << q->grado << endl;
    cout << "Duracion: " << q->largo << " semestres" << endl;
    cout << "Acreditacion: " << q->acredAn << " anos" << endl;
    cout << "Cursos de Etica: " << q->etica << endl;
    cout << "Grados Intermedios: " << q ->intGrad << endl;
    cout << "Cantidad de Asignaturas: " << q->asign << endl;
    system("PAUSE");
}

void carrera::verAsign(career * q){
    asign * p;
    p = q -> top;
    while(p){
        mostrarAsig(p);
        system("PAUSE");
        system("cls");
        p = p -> next;
    }
}

void carrera::search(){
    char ans;
    int demCod;
    career * q = top;
    cout << "Ingrese codigo Demre: ";
    cin >> demCod;
    while(q&&q->demre!=demCod){
        q = q -> next;
    }
    if (q&&q->demre==demCod){
        mostrarNodo(q);
        cout << "Desea ver asignaturas? (y/n): ";
        cin >> ans;
        ans = tolower(ans);
        if(ans=='y')
            verAsign(q);
    }
    else
        cout << "La Busqueda no Arrojo Resultados..." << endl;
}

void carrera::save(){
    career * p = top, pOut;
    asign * q, qOut;
    ofstream file;
    file.open("data2.txt");
    while(p){
        pOut = saveCar(pOut, p);
        file.write((char*)(p), sizeof(careerLec));
        q = p -> top;
        while(q){
            qOut = saveAs(qOut, q);
            file.write((char*)(q), sizeof(asignLec));
            q = q -> next;
        }
        p = p -> next;
    }
    file.close();
}

career carrera::saveCar(career toList, career * fromList){
    strcpy(toList.name, fromList -> name);
    toList.demre = fromList -> demre;
    strcpy(toList.titulo, fromList -> titulo);
    strcpy(toList.grado, fromList -> grado);
    toList.largo = fromList -> largo;
    toList.acredAn = fromList -> acredAn;
    strcpy(toList.etica, fromList -> etica);
    strcpy(toList.intGrad, fromList -> intGrad);
    toList.asign = fromList -> asign;
    return toList;
}

asign carrera::saveAs(asign toList, asign * fromList){
    strcpy(toList.name, fromList -> name);
    toList.nivel = fromList -> nivel;
    toList.cred = fromList -> cred;
    toList.teo = fromList -> teo;
    toList.ejec = fromList -> ejec;
    toList.practica = fromList -> practica;
    strcpy(toList.tipo, fromList -> tipo);
    return toList;
}

carrera::carrera(){
    top = NULL;
}

carrera::~carrera(){
    career * q;
    do{
        q = top;
        if (top)
            top = top -> next;
        delete q;
    }while(q);
}
