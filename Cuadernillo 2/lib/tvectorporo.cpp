#include "../include/tvectorporo.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

TVectorPoro::TVectorPoro() : error() {
    dimension = 0;
    datos = NULL;
}

TVectorPoro::TVectorPoro(int dimension) : error() {
    this->dimension = (dimension < 0) ? 0 : dimension;
    this->datos = new TPoro[this->dimension];
}

TVectorPoro::TVectorPoro(const TVectorPoro& other) : error() {
    if (other.datos == NULL || other.dimension == 0) {
        dimension = 0;
        datos = NULL;
    } else {
        dimension = other.dimension;
        datos = new TPoro[dimension];
        for (int i = 0; i < dimension; i++) {
            datos[i] = other.datos[i];
        }
    }
}

TVectorPoro::~TVectorPoro() {
    if (datos != NULL) {
        delete[] datos;
        datos = NULL;
    }

    dimension = 0;
}

TVectorPoro& TVectorPoro::operator=(const TVectorPoro& other) {
    if (this != &other) {
        delete[] datos;
        
        if (other.datos == NULL || other.dimension == 0) {
            datos = NULL;
            dimension = 0;
        } else {
            dimension = other.dimension;
            datos = new TPoro[dimension];
            for (int i = 0; i < dimension; i++) {
                datos[i] = other.datos[i];
            }
        }
    }
    return *this;
}

bool TVectorPoro::operator==(const TVectorPoro &other) const {
    if (dimension != other.dimension) 
        return false;

    for (int i = 0; i < dimension; i++)
        if (!(datos[i] == other.datos[i])) return false;

    return true;
}

bool TVectorPoro::operator!=(const TVectorPoro &other) const {
    return !(*this == other);
}

TPoro& TVectorPoro::operator[](const int pos) {
    if (pos < 1 || pos > dimension) return error;
    return datos[pos - 1];
}

TPoro TVectorPoro::operator[](const int pos) const {
    if (pos < 1 || pos > dimension) return error;
    return datos[pos - 1];
}

int TVectorPoro::Longitud() const {
    return dimension;
}

int TVectorPoro::Cantidad() const {
    int contador = 0;
    for (int i = 0; i < dimension; i++)
        if (!datos[i].EsVacio())
            contador++;

    return contador;
}

bool TVectorPoro::Redimensionar(const int newDim) {
    if (newDim <= 0 || newDim == dimension) return false;
    TPoro *newDatos = new TPoro[newDim];

    if (newDim < dimension) {
        for (int i = 0; i < newDim; i++)
            newDatos[i] = datos[i];
    } else {
        for (int i = 0; i < dimension; i++)
            newDatos[i] = datos[i];

        for (int i = dimension; i < newDim; i++)
            newDatos[i] = TPoro();
    }

    delete[] datos;
    datos = newDatos;
    dimension = newDim;
    return true;
}

ostream& operator<<(ostream & os, const TVectorPoro & vec){
    os << '[';
    for(int i = 0; i < vec.dimension; i++){
        os << i+1 << ' ' << vec[i+1];
        if(i != vec.dimension - 1) os << ' ';
    }
    os << ']';

    return os;
}