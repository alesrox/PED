#pragma once
#include <iostream>
using namespace std;

class TPoro {
    private:
        int x, y;
        double volumen;  
        char* color;
        void noCapitalLetters(char* original, char* &dst);
    
    public:
        TPoro(); 
        TPoro(int, int, double); 
        TPoro(int, int, double, char *); 
        TPoro(TPoro &); 
        TPoro(const TPoro&); 
        ~TPoro(); 
        TPoro& operator=(const TPoro&);

        bool operator==(const TPoro&) const; 
        bool operator!=(const TPoro&) const;
        void Posicion(const int, const int); 
        void Volumen(const double);
        void Color(const char*); 
        int PosicionX() const; 
        int PosicionY() const; 
        double Volumen() const; 
        char* Color() const; 
        bool EsVacio() const;
    
    friend ostream & operator<<(ostream&, const TPoro&);
};