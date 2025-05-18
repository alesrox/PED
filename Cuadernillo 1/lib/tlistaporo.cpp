#include "../include/tlistaporo.h"
#include <iostream>
using namespace std;

TListaPoro::TListaPoro() {
    primero = NULL;
    ultimo = NULL;
}

TListaPoro::TListaPoro(const TListaPoro &lista) {
    primero = NULL;
    ultimo = NULL;

    TListaPosicion pos = lista.Primera();
    while (!pos.EsVacia()) {
        TPoro cp = lista.Obtener(pos);
        Insertar(cp);
        TListaPosicion next = pos.Siguiente(); 
        pos = next;
    }
}


TListaPoro::~TListaPoro() {
    TListaNodo *temp;
    while (primero != NULL) {
        temp = primero->siguiente;
        delete primero;
        primero = temp;
    }

    ultimo = NULL;
}


bool TListaPoro::operator==(const TListaPoro & lista) const {
    TListaPosicion pos0, pos1;
    pos0.pos = primero;
    pos1.pos = lista.primero;
    
    if (Longitud() != lista.Longitud())
    return false;
    
    while (!pos0.EsVacia() && !pos1.EsVacia()) {
        if (pos0.pos->e != pos1.pos->e)
            return false;

        pos0 = pos0.Siguiente();
        pos1 = pos1.Siguiente();
    }

    return true;
}

TListaPoro & TListaPoro::operator=(const TListaPoro &lista) {
    if (this != &lista) {
        this->~TListaPoro();
        primero = ultimo = NULL;

        TListaPosicion pos = lista.Primera();
        while (!pos.EsVacia()) {
            TPoro cp = lista.Obtener(pos);
            Insertar(cp);
            TListaPosicion next = pos.Siguiente();
            pos = next;
        }
    }

    return *this;
}


TListaPoro TListaPoro::operator+(const TListaPoro & lista) {
    TListaPoro result = TListaPoro(*this);
    TListaPosicion actualPos = lista.Primera();

    while (!actualPos.EsVacia()) {
        result.Insertar(actualPos.pos->e);
        TListaPosicion next = actualPos.Siguiente();
        actualPos = next;
    }

    return result;
}

TListaPoro TListaPoro::operator-(const TListaPoro & lista) {
    TListaPoro result;
    TListaPosicion actualPos = this->Primera();

    while (!actualPos.EsVacia())
        if (lista.Obtener(actualPos).EsVacio())
            result.Insertar(actualPos.pos->e);

    return result;
}

bool TListaPoro::EsVacia() const {
    return primero == NULL && ultimo == NULL;
}

bool TListaPoro::Insertar(const TPoro &poro) {
    TListaPosicion current = Primera();

    while (!current.EsVacia()) {
        if(current.pos->e == poro)
            return false;

        TListaPosicion next = current.Siguiente();
        current = next;
    }
    

    if (primero == NULL) {
        TListaNodo *nuevo = new TListaNodo();
        nuevo->e = poro;
        primero = nuevo;
        ultimo = nuevo;

        return true;
    }

    TListaNodo *nuevo = new TListaNodo();
    nuevo->e = poro;
    TListaPosicion primero = Primera();
    current = primero;

    while (!current.Siguiente().EsVacia() && poro.Volumen() >= current.pos->e.Volumen()) {
        TListaPosicion next = current.Siguiente();
        current = next;
    }

    if (poro.Volumen() >= current.pos->e.Volumen()) {
        nuevo->siguiente = current.pos->siguiente;
        nuevo->anterior = current.pos;
        current.pos->siguiente = nuevo;

        if (nuevo->siguiente == NULL)
            ultimo = nuevo;
    } else {
        nuevo->anterior = current.pos->anterior;
        nuevo->siguiente = current.pos;
        current.pos->anterior = nuevo;
        if (nuevo->anterior == NULL)
            this->primero = nuevo;
    }

    return true;
}


bool TListaPoro::Borrar(const TPoro & poro) {
    if (poro.EsVacio())
        return false;

    if (poro == primero->e) {
        TListaNodo *temp = primero;
        primero = primero->siguiente;
        if (primero) 
            primero->anterior = NULL;

        delete temp;
        return true;
    }

    TListaPosicion current = Primera();
    do {
        if (poro == current.pos->e) {
            current.pos->anterior->siguiente = current.pos->siguiente;
            if (current.pos->siguiente != NULL)
                current.pos->siguiente->anterior = current.pos->anterior;

            return true;
        }

        TListaPosicion next = current.Siguiente();
        current = next;
    } while (!current.EsVacia());

    return false;
}

bool TListaPoro::Borrar(const TListaPosicion & pos) {
    if (Obtener(pos).EsVacio())
        return false;

    Borrar(pos.pos->e);
    return true;
}

TPoro TListaPoro::Obtener(const TListaPosicion & pos) const {
    TListaPosicion actualPos(pos);
    while (!(actualPos.EsVacia())) {
        if(pos == actualPos)
            return actualPos.pos->e;

        TListaPosicion next = actualPos.Siguiente();
        actualPos = next;
    }

    return TPoro();
}

bool TListaPoro::Buscar(const TPoro& p) const {
    TListaNodo* actual = primero;
    while (actual != NULL) {
        if (actual->e == p)
            return true;
        actual = actual->siguiente;
    }
    return false;
}

int TListaPoro::Longitud() const {
    if(primero == NULL && ultimo == NULL)
        return 0;

    int contador = 0;
    TListaPosicion pos = Primera();

    while (!(pos.EsVacia())) {
        contador++;
        TListaPosicion next = pos.Siguiente();
        pos = next;
    }

    return contador;
}

TListaPosicion TListaPoro::Primera() const {
    if (this->EsVacia()) return TListaPosicion();
    TListaPosicion ret;
    ret.pos = primero;

    return ret;
}

TListaPosicion TListaPoro::Ultima() const {
    if (this->EsVacia()) return TListaPosicion();
    TListaPosicion ret;
    ret.pos = ultimo;

    return ret;
}

ostream & operator<<(ostream & os, TListaPoro & lista) {
    os << "(";

    TListaPosicion pos = lista.Primera();
    while (!pos.EsVacia()) {
        os << lista.Obtener(pos);
        if (!pos.Siguiente().EsVacia())
            os << " ";
        pos = pos.Siguiente();
    }

    os << ")";
    return os;
}

TListaPoro TListaPoro::ExtraerRango(int n1, int n2) {
    int length = Longitud();
    
    if (n2 > length) n2 = length;
    if (n1 < 1) n1 = 1;
    if (n1 > n2) return TListaPoro();

    TListaPoro ret;
    TListaPosicion pos = Primera();
    if (n1 != 1) {
        for (int i = 1; i < n1; i++) {
            TListaPosicion next = pos.Siguiente();
            pos = next;
        }
    }

    for (int i = n1; i <= n2; i++) {
        TPoro poro = Obtener(pos);
        ret.Insertar(poro);
        Borrar(poro);
        TListaPosicion next = pos.Siguiente();
        pos = next;
    }

    return ret;
}


TListaPosicion::TListaPosicion() { 
    pos = NULL; 
}

TListaPosicion::TListaPosicion(const TListaPosicion &lpos) {
    pos = lpos.pos; 
}

TListaPosicion::~TListaPosicion() {}

TListaPosicion &TListaPosicion::operator=(const TListaPosicion &lpos) {
    if (this != &lpos)
        this->pos = lpos.pos;

    return *this;
}

bool TListaPosicion::operator==(const TListaPosicion &lpos) const {
    return pos == lpos.pos;
}

TListaPosicion TListaPosicion::Anterior() {
    if (pos == NULL || pos->anterior == NULL)
        return TListaPosicion();

    TListaPosicion lpos;
    lpos.pos = pos->anterior;

    return lpos;
}

TListaPosicion TListaPosicion::Siguiente() {
    if (pos->siguiente == NULL)
        return TListaPosicion();

    TListaPosicion lpos;
    lpos.pos = pos->siguiente;
    return lpos;
}

bool TListaPosicion::EsVacia() const { 
    return pos == NULL;
}

TListaNodo::TListaNodo() {
    anterior = NULL;
    siguiente = NULL;
}

TListaNodo::TListaNodo(const TListaNodo &node) {
    e = TPoro(node.e);
    anterior = node.anterior;
    siguiente = node.siguiente;
}

TListaNodo::~TListaNodo() {}

TListaNodo &TListaNodo::operator=(const TListaNodo &node) {
    if (this != &node) {
        e = TPoro(node.e);
        anterior = node.anterior;
        siguiente = node.siguiente;
    }

    return *this;
}