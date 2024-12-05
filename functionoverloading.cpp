C++ Function Overloading:

#function overloading is a feature of OOPS in c++
#function overloading having same function name and diffrent paramter
#function overloading is the example of polymorphism
#it is a type of compile time polymorphism
#Example
#Parameters should have a different type
  add(int a, int b)
  add(double a, double b)
#Parameters should have a different number 
  add(int a, int b)
  add(int a, int b, int c)
#Parameters should have a different sequence of parameters.
  add(int a, double b)
  add(double a, int b)
#Note: In C++, function overloading is primarily based on the function name and the types or number of its parameters. 
The return type alone does not distinguish overloaded functions. 
Therefore, changing only the return type of a function without changing its parameters does not create an overload and may lead to a compilation error due to ambiguity.
#How does Function Overloading work?
Exact match:- (Function name and Parameter)
If a not exact match is found:–
               ->Char, Unsigned char, and short are promoted to an int.
               ->Float is promoted to double
If no match is found:
               ->C++ tries to find a match through the standard conversion.
ELSE ERROR 🙁
*********************************************
Constructor Overloading in C++:

In C++, We can have more than one constructor in a class with same name, as long as each has a different list of arguments.
This concept is known as Constructor Overloading and is quite similar to function overloading. 
// C++ program to illustrate 
// Constructor overloading 
#include <iostream> 
using namespace std; 

class construct 
{ 

public: 
	float area; 
	
	// Constructor with no parameters 
	construct() 
	{ 
		area = 0; 
	} 
	
	// Constructor with two parameters 
	construct(int a, int b) 
	{ 
		area = a * b; 
	} 
	
	void disp() 
	{ 
		cout<< area<< endl; 
	} 
}; 

int main() 
{ 
	// Constructor Overloading 
	// with two different constructors 
	// of class name 
	construct o; 
	construct o2( 10, 20); 
	
	o.disp(); 
	o2.disp(); 
	return 1; 
} 
****************************************************
C++ Functions that Cannot be Overloaded:

1) Function declarations that differ only in the return type. For example, the following program fails in compilation. 

  #include<iostream>
int foo() { 
return 10; 
}

char foo() { 
return 'a'; 
}

int main()
{
char x = foo();
getchar();
return 0;
}

2) Member function declarations with the same name and the name parameter-type-list cannot be overloaded if any of them is a static member function declaration. 
  For example, following program fails in compilation. 
  #include<iostream>
class Test {
static void fun(int i) {}
void fun(int i) {} 
};

int main()
{
Test t;
getchar();
return 0;
}

3) Parameter declarations that differ only in a pointer * versus an array [] are equivalent. 
That is, the array declaration is adjusted to become a pointer declaration.
Only the second and subsequent array dimensions are significant in parameter types.
For example, following two function declarations are equivalent. 
int fun(int *ptr);
int fun(int ptr[]); // redeclaration of fun(int *ptr)

4) Parameter declarations that differ only in that one is a function type and the other is a pointer to the same function type are equivalent. 
void h(int ());
void h(int (*)()); // redeclaration of h(int())

5) Parameter declarations that differ only in the presence or absence of const and/or volatile are equivalent.
That is, the const and volatile type-specifiers for each parameter type are ignored when determining which function is being declared, defined, or called. 
For example, following program fails in compilation with error “redefinition of `int f(int)’ “ Example:
#include<iostream>
#include<stdio.h>

using namespace std;

int f ( int x) {
	return x+10;
}

int f ( const int x) {
	return x+10;
}

int main() {	 
getchar();
return 0;
}
************************************
Function overloading and const keyword

#include <iostream>
using namespace std;

class Test {
protected:
	int x;

public:
	Test(int i)
		: x(i)
	{
	}
	void fun() const
	{
		cout << "fun() const called " << endl;
	}
	void fun() { cout << "fun() called " << endl; }
};

int main()
{
	Test t1(10);
	const Test t2(20);
	t1.fun();
	t2.fun();
	return 0;
}
Output
fun() called 
fun() const called 
***************************
// PROGRAM 1 (Fails in compilation) 
#include<iostream> 
using namespace std; 

void fun(const int i) 
{ 
	cout << "fun(const int) called "; 
} 
void fun(int i) 
{ 
	cout << "fun(int ) called " ; 
} 
int main() 
{ 
	const int i = 10; 
	fun(i); 
	return 0; 
} 
Output:

Compiler Error: redefinition of 'void fun(int)'
*******************************
// PROGRAM 2 (Compiles and runs fine) 
#include<iostream> 
using namespace std; 

void fun(char *a) 
{ 
cout << "non-const fun() " << a; 
} 

void fun(const char *a) 
{ 
cout << "const fun() " << a; 
} 

int main() 
{ 
const char *ptr = "GeeksforGeeks"; 
fun(ptr); 
return 0; 
} 
Output
const fun() GeeksforGeeks
*******************************************
#include<iostream> 
using namespace std; 

void fun(const int &i) 
{ 
	cout << "fun(const int &) called "; 
} 
void fun(int &i) 
{ 
	cout << "fun(int &) called " ; 
} 
int main() 
{ 
	const int i = 10; 
	fun(i); 
	return 0; 
} 
Output
fun(const int &) called 
*********************
C++ Function Overloading and Return Type

Why is Function overloading not possible with different return types and identical parameters? 

Function overloading comes under the compile-time polymorphism. During compilation, the function signature is checked. So, functions can be overloaded, 
if the signatures are not the same. The return type of a function has no effect on function overloading, 
therefore the same function signature with different return type will not be overloaded. 
Example: if there are two functions: int sum() and float sum(), these two will generate a compile-time error as function overloading is not possible here.

Note: However, function overloading with different return types and different parameter list is possible.
(eg. if there are two functions: int sum(int a, int b) and float sum(float a, float b ) can be overloaded.
// CPP Program to demonstrate that function overloading
// fails if only return types are different
#include <iostream>
int fun() { return 10; }

char fun() { return 'a'; }
// compiler error as it is a new declaration of fun()

// Driver Code
int main()
{
    char x = fun();
    getchar();
    return 0;
}
*********
Function Overloading and float in C++

#include<iostream>
using namespace std;
void test(float s,float t)
{
	cout << "Function with float called ";
}
void test(int s, int t)
{
	cout << "Function with int called ";
}
int main()
{
	test(3.5, 5.6);
	return 0;
}
In function 'int main()':
13:13: error: call of overloaded 'test(double, double)' is ambiguous
 test(3.5,5.6);
It’s a well known fact in Function Overloading, that the compiler decides which function needs to be invoked among the overloaded functions. If the compiler can not choose a function amongst two or more overloaded functions, the situation is -” Ambiguity in Function Overloading”.

The reason behind the ambiguity in above code is that the floating literals 3.5 and 5.6 are actually treated as double by the compiler. As per C++ standard, floating point literals (compile time constants) are treated as double unless explicitly specified by a suffix [See 2.14.4 of C++ standard here). 
Since compiler could not find a function with double argument and got confused if the value should be converted from double to int or float.

#include<iostream>
using namespace std;
void test(float s,float t)
{
	cout << "Function with float called ";
}
void test(int s,int t)
{
	cout << "Function with int called ";
}
int main()
{
	test(3.5f, 5.6f); // Added suffix "f" to both values to 
					// tell compiler, it's a float value
	return 0;
}

Output:
Function with float called
**************************************



