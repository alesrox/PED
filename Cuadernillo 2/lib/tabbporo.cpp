#include "../include/tabbporo.h"
#include <iostream>

using namespace std;

TNodoABB::TNodoABB(const TNodoABB& other) {
    item = other.item;
    iz = other.iz;
    de = other.de;
}

TNodoABB& TNodoABB::operator=(const TNodoABB&other) {
    item = other.item;
    iz = other.iz;
    de = other.de;
    return *this;
}

TABBPoro::TABBPoro() {
    nodo = NULL;
}

TABBPoro::TABBPoro(const TABBPoro& other){
    nodo = NULL;
    if(other.nodo!=NULL){
        TVectorPoro v1;
        v1=other.Niveles();
        for(int i=0; i<v1.Longitud(); i++){
            Insertar(v1[i+1]);
        }
    }
}

TABBPoro::~TABBPoro() {
    delete nodo;
    nodo = NULL;
}

TABBPoro& TABBPoro::operator=(const TABBPoro &other) {
    if (nodo != NULL) {
        delete nodo;
        nodo = NULL;
    }

    nodo = (other.nodo != NULL) ? 
        new TNodoABB(*other.nodo) : new TNodoABB;

    return *this;
}

bool TABBPoro::operator==(const TABBPoro& other) const {
    TVectorPoro v1, v2;
    if (nodo == other.nodo) return true;
    if (nodo == NULL || other.nodo == NULL) return false;

    v1 = other.Inorden();
    v2 = Inorden();
    return v1 == v2;
}

bool TABBPoro::EsVacio() const {
    if (nodo == NULL) return true;

    bool es_vacio_iz, es_vacio_de, es_vacio_item;
    es_vacio_iz = nodo->iz==TABBPoro();
    es_vacio_de = nodo->de==TABBPoro();
    es_vacio_item = nodo->item.EsVacio();

    return 
        es_vacio_iz && es_vacio_de && es_vacio_item;
}

bool TABBPoro::Insertar(TPoro &poro) {
    if (EsVacio()) {
        nodo = new TNodoABB();
        nodo->item = poro;
        return true;
    }

    if (Buscar(poro) == true)
        return false;

    if (nodo->item.Volumen() > poro.Volumen()) {
        return nodo->iz.Insertar(poro);
    } else {
        return nodo->de.Insertar(poro);
    }

    return false;
}

bool TABBPoro::Borrar(TPoro &poro) {
    if (EsVacio()) return false;

    if (poro.Volumen() < nodo->item.Volumen())
        return nodo->iz.Borrar(poro);
    
    if (poro.Volumen() > nodo->item.Volumen())
        return nodo->de.Borrar(poro);

    if (nodo->de.EsVacio()) {
        TNodoABB *aux = nodo;
        nodo = nodo->iz.nodo;
        aux->iz.nodo = NULL;
        delete aux;
    } else if (nodo->iz.EsVacio()) {
        TNodoABB *aux = nodo;
        nodo = nodo->de.nodo;
        aux->de.nodo = NULL;
        delete aux;
    } else { // Ninguno es vacio
        TNodoABB *max_iz = nodo->iz.nodo;

        while (!max_iz->de.EsVacio()) {
            max_iz = max_iz->de.nodo;
        }

        nodo->item = max_iz->item;
        nodo->iz.Borrar(max_iz->item);
    }

    return true;
}

bool TABBPoro::Buscar(const TPoro& poro) const {
    if(nodo == NULL)return false;
    if(nodo->item == poro) return true;

    if(nodo->item.Volumen() > poro.Volumen())
        return nodo->iz.Buscar(poro);
    else 
        return nodo->de.Buscar(poro);

    return false;
}

TPoro TABBPoro::Raiz() const {
    if (EsVacio()) return TPoro();
    return nodo->item;
}

int TABBPoro::Altura() const {
    if (EsVacio()) return 0;

    int max_altura = max(nodo->iz.Altura(), nodo->de.Altura());
    return 1 + max_altura;
}

int TABBPoro::Nodos() const {
    if (EsVacio()) return 0;
    return 1 + nodo->iz.Nodos() + nodo->de.Nodos();
}

int TABBPoro::NodosHoja() const {
    if (EsVacio()) return 0;

    if (nodo->de.EsVacio() && nodo->iz.EsVacio())
        return 1;

    return nodo->iz.NodosHoja() + nodo->de.NodosHoja();
}

void TABBPoro::InordenAux(TVectorPoro &v, int &position) const {
    if (this->EsVacio()) return;
    
    nodo->iz.InordenAux(v, position);
    v[position] = nodo->item;
    position++;
    nodo->de.InordenAux(v, position);
}

TVectorPoro TABBPoro::Inorden() const {
    TVectorPoro v;
    int position = 1;
    if (this->EsVacio()) return v;

    v.Redimensionar(Nodos());
    InordenAux(v, position); 

    return v; 
}

void TABBPoro::PreordenAux(TVectorPoro &v, int &position) const {
    if (this->EsVacio()) return;

    v[position] = nodo->item;
    position++;
    nodo->iz.PreordenAux(v, position);
    nodo->de.PreordenAux(v, position);
}

TVectorPoro TABBPoro::Preorden() const{
    TVectorPoro v;
    int position = 1;
    if (EsVacio()) return v;

    v.Redimensionar(Nodos());
    PreordenAux(v, position);

    return v; 
}

void TABBPoro::PostordenAux(TVectorPoro &v,int &position) const {
    if (this->EsVacio()) return;

    nodo->iz.PostordenAux(v, position);
    nodo->de.PostordenAux(v, position);
    v[position] = nodo->item;
    position++;
}

TVectorPoro TABBPoro::Postorden() const {
    TVectorPoro v;
    int position = 1;
    if(EsVacio()) return v;

    v.Redimensionar(Nodos());
    PostordenAux(v, position); 

    return v; 
}

void TABBPoro::NivelesAux(TVectorPoro &v, int nivel, int& position) const {
    if(EsVacio()) return;

    if (nivel == 0) {
        v[position] = nodo->item;
        position++;
    } else {
        nodo->iz.NivelesAux(v, nivel - 1, position);
        nodo->de.NivelesAux(v, nivel - 1, position);
    }
}

TVectorPoro TABBPoro::Niveles() const {
    TVectorPoro v;
    int position = 1;
    if (EsVacio()) return v;

    v.Redimensionar(Nodos());
    for (int i = 0; i < Altura(); i++)
        NivelesAux(v, i, position);

    return v;
}

TABBPoro TABBPoro::operator+(const TABBPoro &other) const {
    TABBPoro nuevo(*this);
    TVectorPoro v = other.Inorden();

    for (int i = 1; i <= other.Nodos(); i++)
        nuevo.Insertar(v[i]);

    return nuevo;
}

TABBPoro TABBPoro::operator-(const TABBPoro &other) const {
    TABBPoro nuevo(*this);
    TVectorPoro v=other.Inorden();

    for(int i=1; i<v.Longitud()+1; i++) 
        nuevo.Borrar(v[i]);

    return nuevo;
}

ostream& operator<<(ostream& out, const TABBPoro &a){
    out << a.Niveles();
    return out;
}