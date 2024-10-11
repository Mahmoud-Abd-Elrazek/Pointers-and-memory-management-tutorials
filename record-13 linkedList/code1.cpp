// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <iostream>
#include <vector>
using namespace std;

struct ListNode { 
    int data;
    ListNode*next;

    ListNode () { 
        next = nullptr;
    }

};
int main() {

    ListNode* lis = nullptr;
    
    lis = new ListNode;
    lis->data = 10;

    lis->next = new ListNode;
    lis->next->data = 20;

    lis->next->next = new ListNode;
    lis->next->next->data = 30;

    ListNode*current = lis;
    while(current != nullptr) { 

        cout << current->data << " ";
        current = current->next;
        
    }
    
    // lis -> (10,&n2) -> (20,&n3) -> (30,null)


}