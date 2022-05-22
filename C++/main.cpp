#include <iostream>
#include "linked list.cpp"

int main(void)
{
    linked_list<int> list;

    for(int i=0;i<10;i++)
        list.append(i);

    for(int i=0;i<10;i++)
        std::cout<<list.item(i)<<"\n";
}