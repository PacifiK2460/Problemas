template <typename Type>
class tree{
private:
        class leaf{
            private:
                // Every leaf has other 2 leafs
                // and the value of the current leaf
                leaf *left = nullptr;
                leaf *right = nullptr;
                Type value = 0;
            public:
                // At the constructor, we asign the respective values
                leaf(Type input_value){
                    value = input_value;
                }
                ~leaf(){

                }
        };

        unsigned long long int tam = 0;
        leaf *head = nullptr;
        leaf *temp = nullptr;
public:
        void append(Type value){
            leaf *new_leaf = new leaf(value);

            if (head == nullptr){
                head = new_leaf;
            }
            else{
                temp = head;
                while(temp.right != nullptr or temp.left != nullptr){
                    if (new_leaf.value > temp.value){
                        temp = temp.right;
                    }
                    else if (new_leaf.value < temp.value)
                    {
                        temp = temp.left;
                    }
                    
                    else{
                        break;
                    }
                }
            }
            

        }
        

    // tree();
    // ~tree();
};
