/*
In C++, the keyword explicit is used to prevent implicit type conversions. 
It is primarily used with constructors and conversion operators to avoid unintended or automatic conversions that could lead to errors or ambiguous behavior in your code.
*/

#include <iostream>
using namespace std;

class MyClass {
public:
    MyClass(int x) {
        cout << "Constructor called with " << x << endl;
    }
};

void func(MyClass obj) {
    // Do something with obj
    cout << "Function called!" << endl;
}

int main() {
    func(10);  // Implicitly converts 10 to MyClass(10)
    return 0;
}
output:
Constructor called with 10
Function called!
************************************************
#include <iostream>
using namespace std;

class MyClass {
public:
    explicit MyClass(int x) {
        cout << "Constructor called with " << x << endl;
    }
};

void func(MyClass obj) {
    // Do something with obj
    cout << "Function called!" << endl;
}

int main() {
    func(10);  // Error: no implicit conversion from int to MyClass
    return 0;
}
output:
error: no matching function for call to 'func(int)'
**********************************************************
#include <iostream>
using namespace std;

class MyClass {
public:
    explicit MyClass(int x) {
        cout << "Constructor called with " << x << endl;
    }
};

void func(MyClass obj) {
    // Do something with obj
    cout << "Function called!" << endl;
}
    int main() {
    func(MyClass(10));  // Explicit conversion
    return 0;
}
output:
Constructor called with 10
Function called!
