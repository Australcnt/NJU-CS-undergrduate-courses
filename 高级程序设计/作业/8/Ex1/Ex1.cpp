#include <iostream>

using namespace std;

class Object
{
public:
	Object() { cout << "construct Object" << endl; }
	~Object() { cout << "destruct Object" << endl; }
};

class Base : public Object
{
public:
	Base() { cout << "construct Base" << endl; }
	~Base() { cout << "destruct Base" << endl; }
};

class Derived1 : virtual public Base
{
public:
	Derived1() { cout << "construct Derived1" << endl; }
	~Derived1() { cout << "destruct Derived1" << endl; }
};

class Derived2 : virtual public Base
{
private:
	Object o;
public:
	Derived2() { cout << "construct Derived2" << endl; }
	~Derived2() { cout << "destruct Derived2" << endl; }
};

class Mid : public Derived1, public Derived2
{
public:
	Mid() { cout << "construct Mid" << endl; }
	~Mid() { cout << "destruct Mid" << endl; }
};

class Final : public Mid, public Object, public Derived1
{
private:
	Derived2 d2;
public:
	Final() { cout << "construct Final" << endl; }
	~Final() { cout << "destruct Final" << endl; }
};

int main()
{
	{
		cout << "¹¹ÔìË³Ðò£º" << endl;
		Final f;
		cout << endl;
		cout << "Îö¹¹Ë³Ðò£º" << endl;
	}
	return 0;
}
