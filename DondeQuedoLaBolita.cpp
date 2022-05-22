#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  long nuez, movimientos, movimiento,memoria[4];

  memoria[nuez] = 1;

  cin>>nuez>>movimientos;

  for(long i=0;i<movimientos;i++){
    cin>>movimiento;

    switch(movimiento) {
      case 1:
        swap(memoria[0],memoria[1]);
        break;
      case 2:
        swap(memoria[0],memoria[2]);
        break;
      case 3:
        swap(memoria[0],memoria[3]);
        break;
      case 4:
        swap(memoria[1],memoria[2]);
        break;
      case 5:
        swap(memoria[1],memoria[3]);
        break;
      case 6:
        swap(memoria[2],memoria[3]);
        break;
    }

    for(int i=0;i<3;i++){
      if(memoria[i]){
        cout<<i+1;
      }
    }

  }

  return 0;
}
