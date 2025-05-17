#include "tporo.h"
using namespace std;

class TListaNodo {

    private:
        TPoro e;
        TListaNodo *anterior;
        TListaNodo *siguiente;
    
    public:
        TListaNodo(); 
        TListaNodo(const TListaNodo &); 
        ~TListaNodo(); 
        TListaNodo& operator=(const TListaNodo &);

    friend class TListaPosicion;
    friend class TListaPoro;
};

class TListaPosicion {
    private:
        TListaNodo *pos;

    public:
        TListaPosicion();
        TListaPosicion(const TListaPosicion &); 
        ~TListaPosicion();
        TListaPosicion& operator=(const TListaPosicion &);

        bool operator==(const TListaPosicion &) const;
        TListaPosicion Anterior();
        TListaPosicion Siguiente();
        bool EsVacia() const;
    
    friend class TListaPoro;
};

class TListaPoro {
    private:
        TListaNodo *primero;
        TListaNodo *ultimo;
    
    public:
        TListaPoro();
        TListaPoro(const TListaPoro&);
        ~TListaPoro();
        TListaPoro& operator=(const TListaPoro&);

        bool operator==(const TListaPoro&) const; 
        TListaPoro operator+(const TListaPoro&); 
        TListaPoro operator-(const TListaPoro&); 
        bool EsVacia() const; 
        bool Insertar(const TPoro&); 
        bool Borrar(const TPoro&); 
        bool Borrar(const TListaPosicion&); 
        TPoro Obtener(const TListaPosicion&) const; 
        bool Buscar(TPoro&) const; 
        int Longitud() const; 
        TListaPosicion Primera() const;
        TListaPosicion Ultima() const;
        TListaPoro ExtraerRango(int n1, int n2);
    
    friend ostream & operator<<(ostream&, TListaPoro&);
};