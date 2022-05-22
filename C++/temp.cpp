#include <cstdio>
#include <iostream>
using namespace std;

bool A()
{
   printf("Funciona");
}

bool B()
{
   printf("Funciona");
   
}

bool C()
{

   printf("non");
 
}

int main()
{
  bool (*choice) ();
  int x = 4;

  // now if there is if-else statement for making "choice" to 
  // point at a particular function then proceed as following

  if ( x == 1 )
   choice = A;

  else if ( x == 2 )
   choice = B;


if(choice())
 printf("Success\n");

else
 printf("Failure\n");
}