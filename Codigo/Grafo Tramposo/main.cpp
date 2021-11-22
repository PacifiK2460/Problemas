#include<iostream>
using namespace std;

template <typename Type>
struct List{
    private:
        struct node{
            //Node
            //  pointing to next node (none/null)
            //  initialized in 0. 
            Type value = 0;
            node *next = nullptr;
        };
        // "Usefull" variables, size of the list, first, last and temporaly variable
        double tam = 0;
        struct node<Type> *primero = nullptr;
        struct node<Type> *ultimo  = nullptr;
        struct node<Type> *temp  = nullptr;
    
    public:
        void append(Type value){
            struct node<Type> *new_node = new node<Type>;
            new_node -> value = value;
            new_node -> next  = nullptr;

            if( primero == nullptr )
                primero = new_node;
            else
            {
                temp = primero;
                while(temp->next != nullptr)
                    temp = temp -> next;
                // Una vez en el ultimo nodo (en blanco), 
                // este es reasignado con un nodo (dirección) funcional.
                temp -> next = new_node;
                ultimo = new_node;
            }
            tam++;
        }

        void insert_at(double index, Type value){
            if(index > tam)
                throw "Ilegal Memory Acces";
            temp = primero;
            for(int i = 0; i < index; i++)
                temp = temp -> next;
            struct node<Type> *new_node = new node<Type>;
            new_node -> value = value;
            new_node -> next  = temp -> next;
            temp -> next = new_node;
            tam++;        
        }

        void edit(double index, Type value){
            if(index > tam)
                throw "Ilegal Memory Acces";
            temp = primero;
            for(int i = 0; i < index; i++)
                temp = temp -> next;
            temp -> value = value;
        }

        void pop(double index){
            if(index > tam || index < 0)
                throw "Ilegal Memory Acces";
            if(index == 0){
                temp = primero -> next;
                delete primero;
                primero = temp;
            } else {
                struct node<Type> *temporal = primero;
                temp = primero -> next;
                for(int i=1;i<index;i++){
                    temporal = temp;
                    temp = temp -> next;
                }
                if(index == tam-1){
                    ultimo = temporal;
                    delete temporal -> next;
                }
                else{
                    temporal -> next = temp -> next;
                    delete temp;
                }
            }
            tam--;
        }

        Type item(double index){
            if(index > tam || index < 0)
                throw "Out of index";
            temp = primero;
            for(int i = 0; i < index; i++)
                temp = temp -> next;
            return temp -> value;
        }
        
        Type last(void){
            return ultimo -> value;
        }
        
        Type first(void){
            return primero -> value;
        }
      
        double size(void){
            return tam;
        }
};  

struct lista{
    private:
        struct nodo{
            Type valor          = 0;
            Type end_value      = 0;
            Type rango_menor    = 0;
            Type rango_mayor    = 0;
            lista* next_chid    = nullptr;
        };
        struct nodo<Type> *head = nullptr;
        struct nodo<Type> *temp = nullptr;
    public:
        void append(Type value, Type end_value, Type rango_menor, Type rango_menor){
            struct node<Type> *new_node = new node<Type>;
            new_node -> value       = value;
            new_node -> end_value   = end_value;
            new_node -> rango_menor = rango_menor;
            new_node -> rango_mayor = rango_mayor;
            new_node -> next_child  = nullptr;

            if( primero == nullptr )
                primero = new_node;
            else
            {
                temp = primero;
                while(temp->next != nullptr)
                    temp = temp -> next;
                // Una vez en el ultimo nodo (en blanco), 
                // este es reasignado con un nodo (dirección) funcional.
                temp -> next = new_node;
                ultimo = new_node;
            }
            tam++;
        }
};

int main(){

}