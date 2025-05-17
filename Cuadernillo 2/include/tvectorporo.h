#pragma once
#include <iostream>
#include "tporo.h"
using namespace std;

class TVectorPoro {
    private:
        int dimension;
        TPoro *datos;
        TPoro error;
    
    public:
        TVectorPoro();
        TVectorPoro(int);
        TVectorPoro(const TVectorPoro&);
        ~TVectorPoro();
        TVectorPoro & operator=(const TVectorPoro&);

        bool operator==(const TVectorPoro &) const; 
        bool operator!=(const TVectorPoro & other) const; 
        TPoro & operator[](int); 
        TPoro operator[](int) const; 
        int Longitud() const;
        int Cantidad() const;
        bool Redimensionar(int);
    
    friend ostream& operator<<(ostream&, const TVectorPoro&);
};