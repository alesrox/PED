#include <iostream>

using namespace std;

#include "tlistaporo.h"

int
main(void)
{
  TPoro p(1, 1, 1, "rojo"), q(2, 2, 2, "verde"), r(3, 3, 3, "amarillo");
  TListaPoro a;
  TListaPosicion pos;

  a.Insertar(p); a.Insertar(q); a.Insertar(r);

    pos = a.Ultima();
    a.Borrar(pos);

    pos = a.Ultima();
    a.Borrar(pos);

    pos = a.Ultima();
    a.Borrar(pos);

  cout << a << endl;
}
