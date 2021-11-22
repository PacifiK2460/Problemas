#include <iostream>
#include "list.h"
using namespace std;

int main(void){
    list<int> data;
    for(int i=1;i<11;i++){
        data.append(i);
    }
    for(int i=0;i<11;i++){
        cout<<data.item(i)<<"\n";
    }
}