#include <iostream>
using namespace std;
#include "tporo.h"

int
main(void)
{
  TPoro a(2, 2, 20,"rojo");
  TPoro b(2, 2, 20,"RoJo");
  TPoro c(2, 2, 20,"");
  TPoro d(2, 2, 20,NULL);
  
  a = c;
  b = d;

 if(a==c)
    cout << "IGUALES" << endl;
  else
    cout << "DISTINTOS" << endl;

 if(b==d)
    cout << "IGUALES" << endl;
  else
    cout << "DISTINTOS" << endl;

}
