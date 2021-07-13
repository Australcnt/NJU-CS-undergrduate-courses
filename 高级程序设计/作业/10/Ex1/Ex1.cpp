#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

enum Sex { MALE, FEMALE };
enum Major { COMPUTER, PHYSICS, MATH, PHILOSOPHY };

class Student
{
    int no;
    string name;
    Sex sex;
    int age;
    string birth_place;
    Major major;
public:
    Student() {}
    Student(int no, string name, Sex sex, int age, string birth_place, Major major) {
        this->no = no; this->name = name; this->sex = sex; this->age = age; this->birth_place = birth_place; this->major = major;
    }
    int get_no() { return no; }
    string get_name() { return name; }
    int get_sex() { return sex; }
    int get_age() { return age; }
    string get_birth_place() { return birth_place; }
    Major get_major() { return major; }
};

// 升序输出计算机专业男生的姓名
void Fun1(vector<Student>students)
{
    vector<Student>now_students(students.size());
    auto it = copy_if(students.begin(), students.end(), now_students.begin(), [](Student& st) {return st.get_major() == COMPUTER && st.get_sex() == MALE; });
    now_students.resize(distance(now_students.begin(), it));
    sort(now_students.begin(), now_students.end(), [](Student& st1, Student& st2) {return st1.get_name() < st2.get_name(); });
    for_each(now_students.begin(), now_students.end(), [](Student& st) {cout << st.get_name() << endl; });
}

// 升序输出出生地是“南京”、专业为哲学或数学的学生的年龄(年龄计算可以以代码实现时的日期为准)
void Fun2(vector<Student>students)
{
    vector<Student>now_students(students.size());
    auto it = copy_if(students.begin(), students.end(), now_students.begin(), [](Student& st) {return st.get_birth_place()=="Nanjing" &&  (st.get_major() == PHILOSOPHY || st.get_major() == MATH); });
    now_students.resize(distance(now_students.begin(), it));
    sort(now_students.begin(), now_students.end(), [](Student& st1, Student& st2) {return st1.get_age() < st2.get_age(); });
    for_each(now_students.begin(), now_students.end(), [](Student& st) {cout << st.get_age() << endl; });
}

// 统计全部女生的平均年龄
double Fun3(vector<Student>students)
{
    vector<Student>now_students(students.size());
    auto it = copy_if(students.begin(), students.end(), now_students.begin(), [](Student& st) {return st.get_sex() == FEMALE; });
    now_students.resize(distance(now_students.begin(), it));
    return accumulate(now_students.begin(), now_students.end(), 0.0, [](double partial, Student& st) {return partial + st.get_age(); }) / now_students.size();
}

// 统计出生地是“南京”的计算机专业学生的平均年龄
double Fun4(vector<Student>students)
{
    vector<Student>now_students(students.size());
    auto it = copy_if(students.begin(), students.end(), now_students.begin(), [](Student& st) {return st.get_birth_place() == "Nanjing" && st.get_major() == COMPUTER; });
    now_students.resize(distance(now_students.begin(), it));
    return accumulate(now_students.begin(), now_students.end(), 0.0, [](double partial, Student& st) {return partial + st.get_age(); }) / now_students.size();
}

// 统计非计算机专业年龄小于20岁的学生的平均年龄
double Fun5(vector<Student>students)
{
    vector<Student>now_students(students.size());
    auto it = copy_if(students.begin(), students.end(), now_students.begin(), [](Student& st) {return  st.get_major() != COMPUTER && st.get_age() < 20; });
    now_students.resize(distance(now_students.begin(), it));
    return accumulate(now_students.begin(), now_students.end(), 0.0, [](double partial, Student& st) {return partial + st.get_age(); }) / now_students.size();
}

int main()
{
    vector<Student>students;
    Student st1(191220001, "张三", MALE, 19, "Chengdu", COMPUTER);
    Student st2(191220002, "李四", FEMALE, 21, "Nanjing", PHILOSOPHY);
    Student st3(191220003, "王五", MALE, 18, "Beijing", MATH);
    Student st4(191220004, "赵六", FEMALE, 20, "Nanjing", PHYSICS);
    Student st5(191220005, "陈七", MALE, 19, "Shanghai", COMPUTER);
    Student st6(191220006, "刘八", FEMALE, 18, "Chongqing", PHILOSOPHY);
    Student st7(191220007, "丁九", MALE, 21, "Nanjing", COMPUTER);
    Student st8(191220008, "周十", FEMALE, 19, "Hangzhou", MATH);
    students.push_back(st1);
    students.push_back(st2);
    students.push_back(st3);
    students.push_back(st4);
    students.push_back(st5);
    students.push_back(st6);
    students.push_back(st7);
    students.push_back(st8);
    Fun1(students);
    Fun2(students);
    cout << Fun3(students) << endl;
    cout << Fun4(students) << endl;
    cout << Fun5(students) << endl;
	return 0;
}