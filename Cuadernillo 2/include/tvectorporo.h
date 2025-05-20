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
        TVectorPoro& operator=(const TVectorPoro&);

        bool operator==(const TVectorPoro&) const; 
        bool operator!=(const TVectorPoro&) const; 
        TPoro& operator[](const int); 
        TPoro operator[](const int) const; 
        int Longitud() const;
        int Cantidad() const;
        bool Redimensionar(const int);
    
    friend ostream& operator<<(ostream&, const TVectorPoro&);
};