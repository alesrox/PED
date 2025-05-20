#include <iostream>
using namespace std;
#include "tporo.h"

/* CHEQUEO DE ESVACIO() */
int
main(void)
{
  TPoro a;
  a.Color("");
  TPoro b(0,0,0,"");
  TPoro c(0,0,0,NULL);

  if(a.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "LLENO" << endl;
  if(b.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "LLENO" << endl;
  if(c.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "LLENO" << endl;

}
