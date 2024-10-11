// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <iostream>
#include <string>
using namespace std;

struct ListNode { 
    void* data;
    ListNode* next;

    ListNode () { 
        data = nullptr;
        next = nullptr;
    }

};

ListNode* createListNode (void* val) { 
    ListNode* n = new ListNode;
    
    if (n == nullptr) { 
        cout << "memory allocation fiald..";
        exit(0);
    }
    
    n ->data = val;
    return n;
}
void insert (ListNode*& list ,void*val) { 
    ListNode* newNode = createListNode(val);

    if (list == nullptr) { 
        list = newNode;
        return;
    }

    ListNode* current = list;
    while (current ->next != nullptr)
        current = current->next;
    
    current->next = newNode;
}

void printList (ListNode*lis , void(*callBack)(void*val)) { 

    while (lis != nullptr) { 
        callBack(lis->data);
        lis = lis->next;
    }
}

void freeList (ListNode*& list) { 

    while (list != nullptr) { 
        ListNode*del = list;
        list = list -> next;
        delete del;
    }

}

void printAsString (void*val) {
    cout << *((string*)(val)) << " ";
}

void printAsInt(void*val) { 
    cout << *((int*)(val)) << " ";   
}

int main() {
    const int N = 4;
    string names[N] = {"Koko" , "Temon" , "Bomba" , "AbouSen"};

    ListNode* list = nullptr;

    for (int i = 0 ; i < N ;++i) { 
        insert(list , &names[i]);
    }

    printList(list , printAsString );

    cout << "\n===================\n";
    ListNode* head = nullptr;
    int nums[4] = {10,20,30,40};
    for (int i = 0 ; i < N ;++i) { 
        insert(head , &nums[i]);
    }

    printList(head , printAsInt);
    
    freeList(head);
    freeList(list);
}