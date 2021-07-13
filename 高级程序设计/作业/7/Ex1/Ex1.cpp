#include <iostream>
using namespace std;
class A {
public:
	A() { cout << "default construct A" << endl; }
	A(const A& a) { cout << "copy construct A" << endl; }
	virtual ~A() { cout << "destruct A" << endl; }
	void f() { cout << "A::f" << endl; }
	virtual void g() { cout << "A::g" << endl; }
};
class B : public A {
public:
	B() { cout << "default construct B" << endl; }
	B(const B& b) { cout << "copy construct B" << endl; }
	~B() { cout << "destruct B" << endl; }
	void f() { cout << "B::f" << endl; }
	void g() { cout << "B::g" << endl; }
};
void func1(A a) {
	a.f();
	a.g();
}
void func2(A& a) {
	a.f();
	a.g();
}
int main() {
	A* a = new A();
	A* b = new B();
	func1(*a); func2(*a);
	func1(*b); func2(*b);
	*a = *b;
	func1(*a); func2(*a);
	delete a; delete b;
	return 0;
}