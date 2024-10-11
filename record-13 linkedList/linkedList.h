#ifndef LINKED_LIST_INCLUDED
#define LINKED_LIST_INCLUDED

#include<iostream>
#include<string>
using namespace std;

struct ListNode {
    void*data;
    ListNode* next;

    ListNode() {
        data = nullptr;
        next = nullptr;
    }
};

ListNode* createListNode (void*const val) { 

    ListNode* newNode = new ListNode;

    if (newNode == nullptr) { 
        cout << "Memory allocation failed.";
        exit(1);
    }

    newNode->data = val;
    return newNode;
}

void insert (ListNode*&list,void*const val) { 
    ListNode* newNode = createListNode(val);

    if (list == nullptr) {
        list = newNode;
        return;
    }

    ListNode*current = list;
    while (current->next != nullptr)
        current = current->next;

    current->next = newNode;
}

void printList (const ListNode*list,void(*comFun)(void*)) { 

    while (list != nullptr) { 
        comFun(list->data);
        list = list->next;
    }

    cout << "\n";

}

void freeList (ListNode*&list) { 
    while (list != nullptr) { 
        ListNode* del = list;
        list = list->next;
        delete del;
    }

    list = nullptr;
}

#endif // LINKED_LIST_INCLUDED