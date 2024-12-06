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
