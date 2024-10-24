// ! check file Examples//singlyLinkedList for full implementation

/*
    void removeAll(const T & v){
        if(isEmpty()) return;
        while(first != nullptr ) {
            if(first->getValue() == v) {
                removeFirst();
            } else 
                break;
        }
        if(isEmpty()) return;
        Node<T> *cur = first->getNext();
        Node<T> *prev = first;
        while(cur != nullptr){
            if(cur->getValue() == v){
                prev->setNext(cur->getNext());
                delete cur;
                cur = prev->getNext();
                length--;
                continue;
            }
            prev = cur;
            cur = cur->getNext();
        }
    }
*/