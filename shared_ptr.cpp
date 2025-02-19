
#include <iostream>
#include <memory>
using namespace std;
//object -p1 p2
class parent
{
    public:
    int a;
    parent(int v)
    {
        a=v;
    }
    void value(int b)
    {
        a=b;
    }
    void print()
    {
        cout<<a<<endl;
    }
    
};
int main()
{
    shared_ptr<parent> p(new parent(10));
    p->print();
    shared_ptr<parent>p1;
    p1=p;
p1->print();
p->print();
p1->value(20);
p1->print();
p->print();
cout<<p.use_count()<<endl;

    return 0;
}
