

void rotate(Node* head,int rotations){
    Node* curNode = head;
    Node* tail = curNode;
    while(curNode){
        tail = curNode;
        curNode = curNode->next;
    }
    while(rotations--){
        Node* nextNode = curNode->next;

        head->prev = tail;
        head->next = NULL;

        tail->next = head;
        tail = head;

        nextNode->prev = NULL;
        
        head = nextNode;
    }
}
