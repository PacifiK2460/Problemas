/*

[USAGE]
    List<int/long/float/etc> [name]:
    
    Usable function: 
        append      (item):         Add an item at the end of the list.
        
        insert_at   (index, item):  Add an item at the selected location, 
                                    *moving* the next items and increasing size.

        edit        (index, item):  Edits the selected item.

        pop         (index):        Deletes the selected item.

        item        (index):        Returns selected item.

        last:       Returns last item.

        first:      Returns first item.

        size:       Return list's size.

    WARNING:
        Current version only support individual items (ints, doubles, etc),
        it can use other lists, but it won't add every item to the list itself:
        Example:
            If you append a list, it may use the whole list as a single item, and
            you may thread that item as a list, not the list's value(s).

    Future versions may include:
        usage as a python array.
        +, -, functions.

*/
template <typename Type>
struct node;
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
         node<Type> *primero = nullptr;
         node<Type> *ultimo  = nullptr;
         node<Type> *temp  = nullptr;
    
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