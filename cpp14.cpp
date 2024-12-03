1. Return Type Deduction for Functions
In C++14, you can use the auto keyword for the return type of a function, allowing the compiler to deduce the return type based on the function’s return expression.
  #include <iostream>

auto add(int a, int b) {
    return a + b;
}

int main() {
    std::cout << add(3, 5) << std::endl; // Output: 8
}

***********************************************************
2. Lambda Expressions with Generic Parameters
C++14 allows lambdas to take generic type parameters using auto in the parameter list. This is useful for creating more general-purpose lambda expressions.
  #include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4};

    // Lambda that can take any type (generic)
    auto print = [](auto x) { std::cout << x << " "; };

    for (const auto& val : vec) {
        print(val);  // Output: 1 2 3 4
    }
}
**************************************************************
3. Improved Type Deduction for std::make_unique
In C++14, std::make_unique (introduced in C++11) can now infer types more flexibly, including for arrays.
  #include <iostream>
#include <memory>

int main() {
    // Create a unique pointer for an array of 10 integers
    auto p = std::make_unique<int[]>(10); // Array of 10 ints

    // Initialize and print array values
    for (int i = 0; i < 10; ++i) {
        p[i] = i;
        std::cout << p[i] << " ";
    }

    // Output: 0 1 2 3 4 5 6 7 8 9
}
***************************************
4. std::shared_timed_mutex
C++14 introduced std::shared_timed_mutex, which allows multiple threads to share a mutex for read access but provides exclusive access for writing. 
This is useful for scenarios where many threads need to read data, but only one thread needs to write.
  #include <iostream>
#include <thread>
#include <shared_mutex>
#include <vector>

std::shared_timed_mutex mtx;
std::vector<int> data = {1, 2, 3, 4, 5};

void read_data() {
    std::shared_lock<std::shared_timed_mutex> lock(mtx);
    std::cout << "Reading data: ";
    for (const auto& val : data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

void write_data(int value) {
    std::unique_lock<std::shared_timed_mutex> lock(mtx);
    data.push_back(value);
    std::cout << "Added value: " << value << std::endl;
}

int main() {
    std::thread t1(read_data);
    std::thread t2(write_data, 6);
    std::thread t3(read_data);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
*************************
5. constexpr Enhancements
C++14 allows for more flexibility in constexpr functions, such as the use of constexpr with if statements, return statements, and more complex expressions.
  #include <iostream>

constexpr int factorial(int n) {
    return n <= 1 ? 1 : n * factorial(n - 1);
}

int main() {
    std::cout << "Factorial of 5: " << factorial(5) << std::endl; // Output: 120
}
***************************
6. decltype(auto)
C++14 introduces decltype(auto), which allows the return type of a function to be deduced based on the expression used in the return statement, 
while maintaining type qualifications (like references).
#include <iostream>

int&& foo() {
    int a = 10;
    return std::move(a);  // Returning an rvalue reference
}

decltype(auto) bar() {
    int x = 20;
    return x;  // Returning by value, `decltype(auto)` preserves type
}

int main() {
    int&& result1 = foo();  // rvalue reference
    int result2 = bar();    // Copy of value
    std::cout << result2 << std::endl;  // Output: 20
}
********************************
7. std::integer_sequence and std::index_sequence
C++14 added the ability to work with sequences of integers using std::integer_sequence and std::index_sequence. These are often used in template metaprogramming.
  #include <iostream>
#include <utility>

template <typename T, typename... Args>
void print_sequence(T first, Args... args) {
    std::cout << first << " ";
    if constexpr (sizeof...(args) > 0) {
        print_sequence(args...);  // Recursive unpacking of arguments
    }
}

int main() {
    print_sequence(1, 2, 3, 4);  // Output: 1 2 3 4
}
*******************************
8. Variable Templates
C++14 allows you to define variable templates, which provide a way to define template-like variables that can vary depending on the type.
#include <iostream>

template<typename T>
constexpr T pi = T(3.1415926535897932385);  // Variable template for pi

int main() {
    std::cout << pi<int> << std::endl;  // Output: 3
    std::cout << pi<double> << std::endl;  // Output: 3.141592653589793
}

