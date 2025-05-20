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
  
  TPoro e(c);
  TPoro f(d);

 if(e==c)
    cout << "IGUALES" << endl;
  else
    cout << "DISTINTOS" << endl;

 if(f==d)
    cout << "IGUALES" << endl;
  else
    cout << "DISTINTOS" << endl;

}
