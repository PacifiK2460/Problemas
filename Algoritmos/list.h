#define tipe unsigned long
template<typename type>
class list{
    private:
        class node{
            public:
                type value = 0;
                node *next = nullptr;
        };
    private:
        tipe tam = 0;
        node *head = nullptr;
        node *tail = nullptr;
        node *tmp = nullptr;
    public:
        void append(type value){
            node*new_node = new node;
            if(new_node == nullptr)
                throw "Fatal Error.";
            new_node -> value = value;
            if(head == nullptr)
                head = new_node;
            else{
                tmp = head;
                while(tmp -> next != nullptr)
                    tmp = tmp -> next;
                tmp -> next = new_node;
                tail = new_node;
            }
            tam++;
        }
        void insert(tipe index, type value){
            if(index > tam)
                throw "Ilegal Memory Acces";
            tmp = head;
            for(tipe i = 0; i < index; i++)
                tmp = tmp -> next;
            node *new_node = new node;
            new_node -> value = value;
            new_node -> next = tmp -> next;
            tmp -> next = new_node;
            tam++;
        }
        void edit(tipe index, type value){
            if(index > tam)
                throw "Ilegal Memory Acces";
            tmp = head;
            for(tipe i = 0; i < index; i++)
                tmp = tmp -> next;
            tmp -> value = value;
        }
        void pop(tipe index){
            if(index > tam || index < 0)
                throw "Ilegal Memory Acces";
            if(index == 0)
                head = head -> next;
            else{
                tmp = head;
                for(tipe i = 0; i < index-1; i++)
                    tmp = tmp -> next;
                tmp -> next = tmp -> next -> next;
            }
            tam--;
        }
        type item(tipe index){
            if(index > tam || index < 0)
                throw "Out of index";   
            tmp = head;
            for(tipe i = 0; i < index; i++)
                tmp = tmp -> next;
            return tmp -> value;
        }
        type last(void){
            return tail -> value;
        }
        type first(void){
            return head -> value;
        }
        tipe size(void){
            return tam;
        }
};
