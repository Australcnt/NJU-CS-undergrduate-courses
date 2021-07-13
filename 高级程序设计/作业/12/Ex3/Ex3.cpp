#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int n;

class Grade
{
public:
	string id;
	string name;
	string sex;
	double score;

	friend istream& operator >> (istream& in, Grade& grade);
	friend ostream& operator << (ostream& out, const Grade& grade);
};

istream& operator >> (istream& in, Grade& grade)
{
	in>>grade.id >> grade.name >> grade.sex >> grade.score;
	return in;
}

ostream& operator << (ostream& out, const Grade& grade)
{
	out << grade.id << ' ' << grade.name << ' ' << grade.sex << ' ' << grade.score;
	return out;
}

class GradeList
{
public:
	vector<Grade>grade_list;

	friend istream& operator >> (istream& in, GradeList& gradelist);
	friend ostream& operator << (ostream& out, const GradeList& gradelist);
};

istream& operator >> (istream& in, GradeList& gradelist)
{
	Grade grade;
	for (int i = 0; i < n; i++)
	{
		in >> grade;
		gradelist.grade_list.push_back(grade);
	}
	return in;
}

ostream& operator << (ostream& out, const GradeList& gradelist)
{
	for (int i = 0; i < gradelist.grade_list.size(); i++)
		out << gradelist.grade_list[i] << endl;
	return out;
}

int main()
{
	// 1.我们需要从键盘录入成绩的记录信息，然后保存到文件 a 当中。
	cout << "请输入学生人数和需要录入的成绩记录信息：" << endl;
	cin >> n;
	GradeList gradelist;
	cin >> gradelist;
	ofstream out_filea("C:\\南\\大二下\\高级程序设计\\作业\\12\\a.txt", ios::out);
	if (!out_filea)
		exit(-1);
	out_filea << gradelist;
	out_filea.close();

	// 2.从文件 a 中读出成绩信息。
	ifstream in_filea("C:\\南\\大二下\\高级程序设计\\作业\\12\\a.txt", ios::in);
	if (!in_filea)
		exit(-1);
	GradeList gradelist2;
	in_filea >> gradelist2;

	// 3.输出成绩前3名的学生信息，输出到新文件 b 中。
	sort(gradelist2.grade_list.begin(), gradelist2.grade_list.end(), [](Grade& grade1, Grade& grade2) {return grade1.score > grade2.score; });
	ofstream out_fileb("C:\\南\\大二下\\高级程序设计\\作业\\12\\b.txt", ios::out);
	if (!out_fileb)
		exit(-1);
	out_fileb << gradelist2.grade_list[0] << endl;
	out_fileb << gradelist2.grade_list[1] << endl;
	out_fileb << gradelist2.grade_list[2] << endl;

	// 4.对于男女生各计算平均分，再将成绩在平均分以下的记录输出到一个新文件 c 中。
	double average_male = 0, average_female = 0;
	GradeList gradelist_male, gradelist_female;
	copy_if(gradelist.grade_list.begin(), gradelist.grade_list.end(), back_inserter(gradelist_male.grade_list), [](Grade& grade) {return grade.sex == "男"; });
	copy_if(gradelist.grade_list.begin(), gradelist.grade_list.end(), back_inserter(gradelist_female.grade_list), [](Grade& grade) {return grade.sex == "女"; });
	average_male = accumulate(gradelist_male.grade_list.begin(), gradelist_male.grade_list.end(), 0.0, [](double a, Grade& grade) {return a + grade.score; }) / gradelist_male.grade_list.size();
	average_female = accumulate(gradelist_female.grade_list.begin(), gradelist_female.grade_list.end(), 0.0, [](double a, Grade& grade) {return a + grade.score; }) / gradelist_female.grade_list.size();
	GradeList gradelist_male_below, gradelist_female_below;
	copy_if(gradelist_male.grade_list.begin(), gradelist_male.grade_list.end(), back_inserter(gradelist_male_below.grade_list), [average_male](Grade& grade) {return grade.score<average_male; });
	copy_if(gradelist_female.grade_list.begin(), gradelist_female.grade_list.end(), back_inserter(gradelist_female_below.grade_list), [average_female](Grade& grade) {return grade.score < average_female; });
	ofstream out_filec("C:\\南\\大二下\\高级程序设计\\作业\\12\\c.txt", ios::out);
	if (!out_filec)
		exit(-1);
	out_filec << gradelist_male_below << gradelist_female_below;
	out_filec.close();

	// 5.增加几条新的补考记录，对分数按 90% 折算录进系统。
	cout << "请输入补考学生人数和需要录入的补考成绩记录信息：" << endl;
	int n_rest;
	cin >> n_rest;
	Grade grade_rest;
	for (int i = 0; i < n_rest; i++)
	{
		cin >> grade_rest;
		grade_rest.score *= 0.9;
		gradelist.grade_list.push_back(grade_rest);
	}

	// 6.输出数据到文件 a 中，完成表格的更新。
	ofstream out_filea2("C:\\南\\大二下\\高级程序设计\\作业\\12\\a.txt", ios::out);
	if (!out_filea2)
		exit(-1);
	out_filea2 << gradelist;
	out_filea2.close();

	return 0;
}