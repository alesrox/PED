#pragma once
#include <tvectorporo.h>
#include <iostream>

class TNodoABB;

class TABBPoro{
    friend ostream & operator<<(ostream&, const TABBPoro&);
    private:
        TNodoABB *nodo;
        void InordenAux(TVectorPoro&, int&) const;
        void PreordenAux(TVectorPoro&, int&) const;
        void PostordenAux(TVectorPoro&, int&) const;
        void NivelesAux(TVectorPoro&, int, int&) const;

    public:
        TABBPoro();
        TABBPoro(const TABBPoro&);
        ~TABBPoro();
        TABBPoro& operator=(const TABBPoro&);
        bool operator==(const TABBPoro&) const;
        bool EsVacio() const;
        bool Insertar(TPoro&);
        bool Borrar(TPoro&);
        bool Buscar(const TPoro&) const;
        TPoro Raiz() const;
        int Altura() const;
        int Nodos()const;
        int NodosHoja() const;
        TVectorPoro Inorden() const;
        TVectorPoro Preorden() const;
        TVectorPoro Postorden() const;
        TVectorPoro Niveles() const;
        TABBPoro operator+(const TABBPoro&) const;
        TABBPoro operator-(const TABBPoro&) const;
};


class TNodoABB{
    friend class TABBPoro;
    private:
        TPoro item;
        TABBPoro iz, de;
    public:
        TNodoABB() {};
        TNodoABB(const TNodoABB&);
        ~TNodoABB() {};
        TNodoABB& operator=(const TNodoABB&);
};