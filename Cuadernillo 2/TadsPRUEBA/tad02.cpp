#include <iostream>
#include "tabbporo.h"
using namespace std;

int
main(void)
{
/*******************************************************************/
/***************** Insertar(), Borrar() */
/*******************************************************************/
  
  TABBPoro a,b;

  TPoro p1(1,2,1,(char *) "rojo");
  TPoro p2(1,2,2,(char *) "rojo");
  TPoro p3(1,2,3,(char *) "rojo");
  TPoro p4(1,2,4,(char *) "rojo");
  TPoro p5(1,2,5,(char *) "rojo");
  TPoro p6(1,2,6,(char *) "rojo");
  TPoro p7(1,2,7,(char *) "rojo");

  a.Insertar(p1);
  a.Insertar(p2);
  
  b.Insertar(p1);
  b.Insertar(p2);

  if (a==b)
	cout << "IGUALES" << endl;



  return 1;
}
