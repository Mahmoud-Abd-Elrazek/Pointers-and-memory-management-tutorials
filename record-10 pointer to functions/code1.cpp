// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <iostream>
using namespace std;

void sum () { 
    cout << "hello sum()\n";
}

int sum (int a , int b) { 
    return a + b;
}

int sum (int* ar , int n) { 
    int s = 0;
    for (int *p = ar ; p != ar + n ; ++p)
        s += *p;
    return s;
}

void f () {
    // return type + (*name)(par..);

    void (*f)() = sum;
    f();

    int (*f2)(int,int) = sum;
    cout << f2(5,3) << "\n";


    int ar[5] = {1,2,3,4,5};
    int (*s)(int* , int) = sum;
    cout << s (ar , 5) << "\n";
}

int add (int a, int b) { return a + b;}
int subtract (int a, int b) { return a - b;}
int multiply (int a, int b) { return a * b;}
int divide (int a, int b) { return a / b;}

int main() {
    int n1 = 100 , n2 = 50;
    int (*p[4])(int,int) = {add , subtract , multiply ,divide};

    for (int i = 0 ; i < 4 ; ++i )
        cout << p[i](n1,n2) << "\n";

}