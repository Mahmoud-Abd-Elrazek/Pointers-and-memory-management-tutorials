// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <iostream>
using namespace std;

void F1 () { 
    int num = 10;
    const int& rn = num; // read only rev

    // rn += 50;
    cout << rn << " " << num << "\n"; // 60 60
    cout << &rn << " " << &num << endl;

    const double pi = 3.1415;
    const double& rev = pi; 


    string name = "Ali";
    
    // string & r = name;
    const string & r = "Ali";
}


void test (int*x)  { 
    cout << &x << "\n";
    (*x)+= 50;
}
void test (int&x)  { 
    cout << &x << " " ;
    x++;
}
void F2 ( ) {
    int cnt = 0;
    cout << &cnt << " " ; 
    test(&cnt);
    cout << cnt << "\n";
}

string& message () { 
    static string m = "hello world"; // global / stitic memory
    return m; // end 
}
void F3 () { 
    string str = "hello world";
    // str += ", Ahmed";
    str.operator+=(" ,Ahmed");
    cout << str << "\n";
}

struct Array { 
    int ar[5] = {1,2,3,4,5};

    int& operator[] (int i) { 
        return ar[i];
    }

};
int main() {

    Array ob;

    ob[0] = 800;
    for (int i =0 ; i < 5 ; ++i)  {
        cout << ob[i] << "\n" ;
    }

    return 0;
}