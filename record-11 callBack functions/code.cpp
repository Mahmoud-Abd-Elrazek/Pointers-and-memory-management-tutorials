// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <iostream>
#include <algorithm>
using namespace std;

int add (int a, int b) { return a + b;}
int subtract (int a, int b) { return a - b;}
int multiply (int a, int b) { return a * b;}
int divide (int a, int b) { return a / b;}

void Do (int a ,int b , int(*callBack)(int,int)) {
    cout << callBack(a , b) << "\n";
} 

void ex1 () { 
    int n1 = 100 , n2 = 50;
    Do(n1,n2 , add);
    Do(n1,n2 , subtract);
}


void print (string*const list , int size , void(*pf)(string)) {
    for (int i = 0 ; i< size ; ++i) { 
        pf(list[i]);
    }
}

void userLevel (string name) { 
    cout << name << " | ";
}
void ex2 () { 
    string names[] = {"Koko" , "Temon" , "Bomba" , "Abousen"};
    int size = sizeof(names) / sizeof(*names);
    print(names,size,userLevel);
}

bool ascending (int a ,int b) { 
    return a < b;
}
bool descending (int a ,int b) { 
    return a > b;
}

void insertionSort (int ar[],int N , bool(*compareFunction)(int,int)) {
    for (int i = 1 ; i < N ; ++i) 
    { 
        int curr = i;
        while (curr && compareFunction(ar[curr] , ar[curr - 1])) 
        {
            int temp = ar[curr];
            ar[curr] = ar[curr - 1];
            ar[curr-1] = temp;
            curr--;
        }
    }
}
void ex3 () { 
    int nums[5] = {50,10,9,8,7};
    insertionSort(nums , 5 , descending);
    for (int i = 0 ; i < 5 ; ++i) {
        cout << nums[i] << " ";
    }

}

int sum (int a , int b) { 
    return a +b;
}
int(*getAddressF()) (int,int) { 
    return sum;
}

void ex4 () {
    int(*pf)(int,int) = getAddressF();

    cout << pf(80,10) << "\n";
}


int main() {

    int nums[5] = {50,10,9,8,7};
    sort(nums , nums+5 , descending);
    for (int i = 0 ; i < 5 ; ++i) {
        cout << nums[i] << " ";
    }


}