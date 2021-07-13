#include <iostream>
#include <cmath>
#define unit_capacity 5
using namespace std;

class FloatSet
{
    float* numbers;
    int count;
    int capacity;
    // 可根据需要添加其他成员变量
public:
    FloatSet();
    FloatSet(const FloatSet& s);
    ~FloatSet();
    FloatSet& operator = (const FloatSet& s);// 对象之间的赋值操作重载为与拷贝构造函数相同的操作
    bool is_empty() const; //判断是否为空集
    int size() const; //获取元素个数
    bool is_element(float e) const; //判断e是否属于集合
    bool is_subset(const FloatSet& s) const; //判断集合是否包含于s
    bool is_equal(const FloatSet& s) const; //判断集合是否相等
    bool insert(float e); //将元素e加⼊集合，成功返回true，否则返回false(e已属于集合)
    bool remove(float e); //将e从集合中删除，成功返回true，否则返回false(e不属于集合)
    void display() const; //打印集合所有元素
    FloatSet union2(const FloatSet& s) const; //计算集合和s的并集
    FloatSet intersection2(const FloatSet& s) const; //计算集合和s的交集
    FloatSet difference2(const FloatSet& s) const; //计算集合和s的差
};

FloatSet::FloatSet()
{
    count = 0;
    capacity = unit_capacity;
    numbers = new float[capacity];
}

FloatSet::FloatSet(const FloatSet& s)
{
    count = s.count;
    capacity = s.capacity;
    numbers = new float[s.capacity];
    for (int i = 0; i < s.count; i++)
        numbers[i] = s.numbers[i];
}

FloatSet::~FloatSet()
{
    count = 0;
    capacity = unit_capacity;
    delete[]numbers;
    numbers = NULL;
}

FloatSet& FloatSet::operator = (const FloatSet&s)// 对象之间的赋值操作重载为与拷贝构造函数相同的操作
{
    count = s.count;
    capacity = s.capacity;
    numbers = new float[s.capacity];
    for (int i = 0; i < s.count; i++)
        numbers[i] = s.numbers[i];
    return *this;
}

bool FloatSet::is_empty() const //判断是否为空集
{
    return count == 0;
}

int FloatSet::size() const //获取元素个数
{
    return count;
}

bool FloatSet::is_element(float e) const //判断e是否属于集合
{
    for (int i = 0; i < count; i++)
    {
        if (fabs(numbers[i] - e) < 0.00001)
            return true;
    }
    return false;
}

bool FloatSet::is_subset(const FloatSet& s) const //判断集合是否包含于s
{
    for (int i = 0; i < count; i++)
    {
        if (!s.is_element(numbers[i]))
            return false;
    }
    return true;
}

bool FloatSet::is_equal(const FloatSet& s) const //判断集合是否相等
{
    return is_subset(s) && s.is_subset(*this);
}

bool FloatSet::insert(float e) //将元素e加⼊集合，成功返回true，否则返回false(e已属于集合)
{
    if (is_element(e))
        return false;
    if (count == capacity)
    {
        float* temp = new float[capacity + unit_capacity];
        for (int i = 0; i < count; i++)
            temp[i] = numbers[i];
        delete[]numbers;
        numbers = temp;
        capacity += unit_capacity;
    }
    numbers[count] = e;
    count++;
    return true;
}

bool FloatSet::remove(float e) //将e从集合中删除，成功返回true，否则返回false(e不属于集合)
{
    for (int i = 0; i < count; i++)
    {
        if (numbers[i] == e)
        {
            for (int j = i; j < count - 1; j++)
                numbers[j] = numbers[j + 1];
            count--;
            return true;
        }
    }
    return false;
}

void FloatSet::display() const //打印集合所有元素
{
    for (int i = 0; i < count; i++)
        cout << numbers[i] << " ";
    cout << endl;
}

FloatSet FloatSet::union2(const FloatSet& s) const //计算集合和s的并集
{
    FloatSet x;
    for (int i = 0; i < count; i++)
        x.insert(numbers[i]);
    for (int j = 0; j < s.count; j++)
        x.insert(s.numbers[j]);
    return x;
}

FloatSet FloatSet::intersection2(const FloatSet& s) const //计算集合和s的交集
{
    FloatSet x;
    for (int i = 0; i < count; i++)
    {
        if (s.is_element(numbers[i]))
            x.insert(numbers[i]);
    }
    return x;
}

FloatSet FloatSet::difference2(const FloatSet& s) const //计算集合和s的差
{
    FloatSet x;
    for (int i = 0; i < count; i++)
    {
        if (!s.is_element(numbers[i]))
            x.insert(numbers[i]);
    }
    return x;
}

int main()
{
    FloatSet a, b, c;
    if (a.is_empty())
        cout << "a为空" << endl;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(5);
    a.display();
    if (a.is_element(1))
        cout << "1是a中的元素" << endl;
    a.remove(1);
    if (!a.is_element(1))
        cout << "1不是a中的元素" << endl;
    a.display();
    b.insert(3);
    b.insert(4);
    b.insert(5);
    b.insert(6);
    b.insert(7);
    b.display();
    if (!b.is_subset(a))
        cout << "b不是a的子集" << endl;
    c = a.union2(b);// =被重载
    c.display();
    c = a.intersection2(b);// =被重载
    c.display();
    c = a.difference2(b);// =被重载
    c.display();
    b.remove(7);
    b.remove(6);
    if (b.is_subset(a))
        cout << "b是a的子集" << endl;
    a.remove(2);
    if (a.is_equal(b))
        cout << "a和b相等" << endl;
    b.remove(5);
    b.remove(4);
    b.remove(3);
    if (b.is_empty())
        cout << "b为空" << endl;
    b.remove(2);
    if (b.is_empty())
        cout << "b为空" << endl;
    return 0;
}