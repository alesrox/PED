#include <iostream>

using namespace std;

#include "tlistaporo.h"

int
main(void)
{
  TPoro p(1, 1, 1, "rojo"), q(2, 2, 2, "verde"), r(3, 3, 3, "amarillo");
  TListaPoro a;

  a.Insertar(p); a.Insertar(q);

  if(a.Buscar(p))
    cout << "SI" << endl;
  else
    cout << "NO" << endl;

  if(a.Buscar(q))
    cout << "SI" << endl;
  else
    cout << "NO" << endl;

  if(a.Buscar(r))
    cout << "SI" << endl;
  else
    cout << "NO" << endl;
}
