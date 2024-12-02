# CPPprograms

#include <iostream>

int main()
{
    int a=10;
    void *ptr=&a;
    std::cout << *(int*)ptr << std::endl;
    
    return 0;
}
//////////////////////////////
1.class:collection of objects
2.objects:any entity has state and behavior
3.Encapsulation:Binds the data with function
4.Abstraction:Hiding the internal details and showing functionality
5.polymorphism
-two types
    1.compile time polymorphism
      -method overloading - function name is same but arguments is diffrent
      -operator overloading - it give the diffrent meaning of existing operator
    2.runtime polymorphism
      -method overriding - function name and arguments should be same 
6.Inheritance
    1.single inheritance
    2.multi level inheritance
    3.multiple inheritance
    4.hirarchical inheritance
    5.hybrid inheritance
7.Dynamic binding:Function executed in run time:using virtual in function
8.message passing:passing object as argument to the function
/////////////////////////////////////////////////

#include <iostream>
using namespace std;
int i=0;
class parent
{
    public:
    
    parent()
    {
        std::cout << "default constructor" << std::endl;
    }
     parent(int a)
    {
        std::cout << "paramterized constructor" << std::endl;
    }
     parent(int a,int b)
    {
        std::cout << "double paramterized constructor" << std::endl;
    }
    ~parent()
    {
       i++;
        std::cout << "default destructor : " << i<<std::endl;
    }
};

int main()
{
    parent p1;
parent p2(12);
parent p3(12,13);
    return 0;
}
output:
default constructor
paramterized constructor
double paramterized constructor
default destructor : 1
default destructor : 2
default destructor : 3

/////////////////
friend class

#include <iostream>
using namespace std;
int i=0;
class parent
{
    private:
    int parent_id=10;
    
friend class child;
};

class child
{
    
    public:
    child(const parent& p)
    {
        std::cout << p.parent_id << std::endl;
    }
};

int main()
{
 parent p;
 child c(p);
 //c.print(p);
    return 0;
}

********************************************
friend function

#include <iostream>
using namespace std;
int i=0;
class parent
{
    protected:
    int parent_id=10;
    
friend void print(const parent&);
};
void print(const parent& p)
{
    std::cout << p.parent_id << std::endl;
}

int main()
{
 parent p;
 print(p);
    return 0;
}

****************************************************
Default Constructor
Copy Constructor
Move Constructors
Assignment Operator
Destructor
