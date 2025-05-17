#include "../include/tporo.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <iomanip> // Para std::setw y std::left
using namespace std;

void TPoro::noCapitalLetters(char* original, const char* dst) {
    int len = strlen(original);
    char* temp = new char[len + 1];

    for (int i = 0; i < len; i++) {
        if (original[i] >= 'A' && original[i] <= 'Z')
            temp[i] = original[i] + 32;
        else
            temp[i] = original[i];
    }

    temp[len] = '\0';

    dst = temp;
}

TPoro::TPoro() {
    x = 0;
    y = 0;
    volumen = 0.0;
    color = nullptr;
}

TPoro::TPoro(int x, int y, double volumen) {
    this->x = x;
    this->y = y;
    this->volumen = volumen;
    color = nullptr;
}

TPoro::TPoro(int x, int y, double volumen, char* color) {
    this->x = x;
    this->y = y;
    this->volumen = volumen;
    noCapitalLetters(color, this->color);
}

TPoro::TPoro(TPoro& other) {
    this->x = other.x;
    this->y = other.y;
    this->volumen = other.volumen;
    this->color = other.color;
}

TPoro::TPoro(const TPoro& other) {
    this->x = other.x;
    this->y = other.y;
    this->volumen = other.volumen;
    this->color = other.color;
}

TPoro::~TPoro() {
    x = 0;
    y = 0;
    volumen = 0.0;

    delete[] color;
    color = nullptr;
}

TPoro& TPoro::operator=(const TPoro& other) {
    if (this == &other) {
        return *this; // Evitar la autoasignación
    }

    delete[] color;
    color = nullptr;

    x = other.x;
    y = other.y;
    volumen = other.volumen;

    if (other.color != nullptr) {
        color = new char[strlen(other.color) + 1];
        strcpy(color, other.color);
    }

    return *this;
}

bool TPoro::operator==(const TPoro &other) const {
    if (this == &other) return true;

    if (this->x != other.x || this->y != other.y || this->volumen != other.volumen)
        return false;

    if (this->color == nullptr && other.color == nullptr)
        return true;

    if (this->color == nullptr || other.color == nullptr)
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
    noCapitalLetters(this->color, color);
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
    if (x == 0 && y == 0 && volumen == 0.0 && color == nullptr)
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
    if (color == nullptr) os << "-";
    else os << color;

    return os;
}
