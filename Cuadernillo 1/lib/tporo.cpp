#include "../include/tporo.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <iomanip>
using namespace std;

void TPoro::noCapitalLetters(const char* original, char* &dst) {
    int len = strlen(original);
    dst = new char[len + 1];
    strcpy(dst, original);

    for (int i = 0; i < len; i++)
        dst[i] = tolower(dst[i]);
}

TPoro::TPoro() {
    x = 0;
    y = 0;
    volumen = 0.0;
    color = NULL;
}

TPoro::TPoro(int x, int y, double volumen) {
    this->x = x;
    this->y = y;
    this->volumen = volumen;
    color = NULL;
}

TPoro::TPoro(int x, int y, double volumen, const char* color) {
    this->x = x;
    this->y = y;
    this->volumen = volumen;

    if (color == NULL)
        this->color = NULL;
    else
        noCapitalLetters(color, this->color);
}

TPoro::TPoro(const TPoro& other) {
    this->x = other.x;
    this->y = other.y;
    this->volumen = other.volumen;
    this->color = other.color;
}

TPoro::~TPoro() {
    if (color != NULL) {
        delete[] color;
        color = NULL;
    }
}

TPoro& TPoro::operator=(const TPoro& other) {
    if (this == &other) return *this;

    delete[] color;
    color = NULL;

    x = other.x;
    y = other.y;
    volumen = other.volumen;

    if (other.color != NULL) {
        color = new char[strlen(other.color) + 1];
        strcpy(color, other.color);
    }

    return *this;
}

bool TPoro::operator==(const TPoro &other) const {
    if (this == &other) return true;

    if (this->x != other.x || this->y != other.y || this->volumen != other.volumen)
        return false;

    if (this->color == NULL && other.color == NULL)
        return true;

    if (this->color == NULL || other.color == NULL)
        return false;

    return (strcmp(this->color, other.color) == 0);
}

bool TPoro::operator!=(const TPoro& other) const {
    return !(*this == other);
}

void TPoro::Posicion(const int x, const int y) {
    this->x = x;
    this->y = y;
}

void TPoro::Volumen(double volumen) {
    this->volumen = volumen;
}

void TPoro::Color(const char* color) {
    if (this->color != NULL) {
        delete[] this->color;
        this->color = NULL;
    }

    if (color != NULL)
        noCapitalLetters(color, this->color);
}

int TPoro::PosicionX() const {
    return this->x;
}

int TPoro::PosicionY() const {
    return this->y;
}

double TPoro::Volumen() const {
    return this->volumen;
}

char* TPoro::Color() const {
    return this->color;
}

bool TPoro::EsVacio() const {
    if (x == 0 && y == 0 && volumen == 0.0 && color == NULL)
        return true;
    
    return false;
}

ostream& operator<<(ostream& os, const TPoro& poro) {
    if (poro.EsVacio()) {
        os << "()";
        return os;
    }

    os << "(" << poro.PosicionX() << ", " << poro.PosicionY() << ") ";
    os << fixed << setprecision(2) << poro.Volumen() << " ";

    char* color = poro.Color();
    if (color == NULL) os << "-";
    else os << color;

    return os;
}
