/*
In C++, the term "mutable" is a keyword that is used to allow a class member variable to be modified even if the object it belongs to is const. 
Normally, if you have a const object, you cannot modify any of its member variables (because the object is considered immutable). 
However, with mutable, a member variable can be modified even when the object is marked as const.
*/
#include <iostream>
using namespace std;

class Example {
private:
    int regularVar;
    mutable int mutableVar;  // This can be modified even in const objects

public:
    Example(int regVal, int mutVal) : regularVar(regVal), mutableVar(mutVal) {}

    // Regular member function
    void display() const {
        cout << "regularVar = " << regularVar << ", mutableVar = " << mutableVar << endl;
    }

    // Function to modify mutableVar
    void modifyMutableVar(int newVal) const {
        mutableVar = newVal;  // Allowed because mutableVar is mutable
    }

    // Function to modify regularVar (not allowed in const functions)
    void modifyRegularVar(int newVal) {
        regularVar = newVal;  // Not allowed if the object is const
    }
};

int main() {
    const Example obj(10, 20);

    // We can call the const function `display` on a const object
    obj.display();

    // We can modify mutableVar even though obj is const
    obj.modifyMutableVar(100);
    
    // Display again to show mutableVar is changed
    obj.display();

    // Uncommenting the line below would result in a compile-time error
    // obj.modifyRegularVar(30);  // This will not work because obj is const

    return 0;
}
