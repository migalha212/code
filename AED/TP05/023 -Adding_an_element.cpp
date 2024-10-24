// ! check file Examples//singlyLinkedList for full implementation

/*
    void insert(int pos, const T & v){
        if(pos > length || pos < 0){
            return;
        }
        else{
            if(pos == 0) addFirst(v);
            else if(pos == length) addLast(v);
            else{
                Node<T> *cur = first;
                for(int i = 0; i < pos - 1; i++){
                    cur = cur->getNext();
                }
                Node<T> *to_add = new Node<T>(v, cur->getNext());
                cur->setNext(to_add);
                length++;
            }
        }
    }
*/