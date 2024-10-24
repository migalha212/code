// ! check file Examples//singlyLinkedList for full implementation

/*
    void remove(int pos){
        if(!isEmpty() && pos < length){ 
            Node<T> *cur = first;
            Node<T> *previous;
            if(pos == 0) this->removeFirst();
            else {
                for(int i = 0; i < pos; i++){
                    previous = cur;
                    cur = cur->getNext();
                }
                previous->setNext(cur->getNext());
                delete cur;
                this->length--;
            }
        }
    }
*/