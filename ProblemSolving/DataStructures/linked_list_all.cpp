#include <iostream>
#include <limits>
#include <fstream>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;

        SinglyLinkedList() {
            this->head = nullptr;
        }

};

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

void print_singly_linked_list(SinglyLinkedListNode* node, string sep) {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
}

SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    if (head == nullptr){
        head = new SinglyLinkedListNode(data);
    }
    else{
        SinglyLinkedListNode* elem = head;
        while (elem->next != nullptr) {
            elem = elem->next;
        }
        elem->next = new SinglyLinkedListNode(data);        
    }
    return head;
}

SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    SinglyLinkedListNode* newhead(new SinglyLinkedListNode(data));
    newhead->next = llist;
    return newhead;
}

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* node = new SinglyLinkedListNode(data);
    if (position == 0){
        node->next = llist;
        return node;
    }
    else{
        // Go to current (pos-1)-th node
        SinglyLinkedListNode* tmp = llist;
        for (int i = 0; i < position-1; i++)
            tmp = tmp->next;
        node->next = tmp->next;
        tmp->next = node;
        return llist;
    }
}

void reversePrint(SinglyLinkedListNode* llist) {
    // Creates temporary reversed singly-linked list while iterating
    // through the original one
    SinglyLinkedListNode* rev_head = new SinglyLinkedListNode(llist->data), *new_head;
    SinglyLinkedListNode* tmp = llist;
    while ((tmp = tmp->next)) {
        new_head = new SinglyLinkedListNode(tmp->data);
        new_head->next = rev_head;
        rev_head = new_head;
    }
    SinglyLinkedListNode* to_delete;
    while (rev_head) {
        cout << rev_head->data << endl;
        to_delete = rev_head;
        rev_head = rev_head->next;
        delete to_delete;
    }
}

SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    if (!llist)
        return NULL;
    if (!llist->next)
        return llist;
    SinglyLinkedListNode *tmp1 = llist->next, *tmp2 = tmp1->next;
    llist->next = NULL;
    tmp1->next = llist;
    while (tmp2) {
        llist = tmp1;
        tmp1 = tmp2;
        tmp2 = tmp2->next;
        tmp1->next = llist;
    }
    return tmp1;
}

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    if (position == 0){
        SinglyLinkedListNode* head = llist->next;
        delete llist;
        return head;
    }
    else{
        SinglyLinkedListNode* tmp = llist;
        while (--position)
            tmp = tmp->next;
        SinglyLinkedListNode* to_delete = tmp->next;
        tmp->next = to_delete->next;
        delete to_delete;
        return llist;        
    }
}

bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode *n1 = head1, *n2 = head2;
    while (true) {
        if (!n1 && !n2)
            return true;
        else if (n1 && n2){
            if (n1->data != n2->data)
                return false;
            else {
                n1 = n1->next;
                n2 = n2->next;
            }
        }
        else
            return false;
    }
}

// Merges two linked lists by consequent pairs, e.g.
// a1->a2->a3->a4->a5 & b1->b2-b3 into
// a1->b1->a2->b2->a3->b3->a4->a5
SinglyLinkedListNode* mergeByPairs(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if (!head1)
        return head2;
    if (!head2)
        return head1;
    SinglyLinkedListNode *Aprev, *Anext, *Bprev, *Bnext;
    Aprev = head1, Anext = head1->next;
    Bprev = head2, Bnext = head2->next;
    while (true) {
        Aprev->next = Bprev;
        if (!Anext)
            break;
        Bprev->next = Anext;
        if (!Bnext)
            break;
        Aprev = Anext;
        Bprev = Bnext;
        Anext = Anext->next;
        Bnext = Bnext->next;
    }
    return head1;
}

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if (!head1)
        return head2;
    if (!head2)
        return head1;
    SinglyLinkedListNode *Aprev = head1, *Anext = head1->next;
    SinglyLinkedListNode *Bprev = head2, *Bnext = head2->next;
    bool checkA = true;
    while (Anext || Bnext) {
        if (checkA){
            if (Bprev->data < Anext->data) {
                Aprev->next = Bprev;
                checkA = false;
            }
            Aprev = Anext;
            Anext = Anext->next;
        }
        else {
            if (Aprev->data < Bnext->data) {
                Bprev->next = Aprev;
                checkA = true;
            }
            Bprev = Bnext;
            Bnext = Bnext->next;
        }
    }
    if (checkA)
        Aprev->next = Bprev;
    else
        Bprev->next = Aprev;
    return head1;
}


void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
      	SinglyLinkedListNode* llist_head = insertNodeAtTail(llist->head, llist_item);
        llist->head = llist_head;
    }

    print_singly_linked_list(llist->head, "\n");
    cout << "\n";

    free_singly_linked_list(llist->head);


    return 0;
}
