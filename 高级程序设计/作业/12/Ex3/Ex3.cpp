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
	// 1.������Ҫ�Ӽ���¼��ɼ��ļ�¼��Ϣ��Ȼ�󱣴浽�ļ� a ���С�
	cout << "������ѧ����������Ҫ¼��ĳɼ���¼��Ϣ��" << endl;
	cin >> n;
	GradeList gradelist;
	cin >> gradelist;
	ofstream out_filea("C:\\��\\�����\\�߼��������\\��ҵ\\12\\a.txt", ios::out);
	if (!out_filea)
		exit(-1);
	out_filea << gradelist;
	out_filea.close();

	// 2.���ļ� a �ж����ɼ���Ϣ��
	ifstream in_filea("C:\\��\\�����\\�߼��������\\��ҵ\\12\\a.txt", ios::in);
	if (!in_filea)
		exit(-1);
	GradeList gradelist2;
	in_filea >> gradelist2;

	// 3.����ɼ�ǰ3����ѧ����Ϣ����������ļ� b �С�
	sort(gradelist2.grade_list.begin(), gradelist2.grade_list.end(), [](Grade& grade1, Grade& grade2) {return grade1.score > grade2.score; });
	ofstream out_fileb("C:\\��\\�����\\�߼��������\\��ҵ\\12\\b.txt", ios::out);
	if (!out_fileb)
		exit(-1);
	out_fileb << gradelist2.grade_list[0] << endl;
	out_fileb << gradelist2.grade_list[1] << endl;
	out_fileb << gradelist2.grade_list[2] << endl;

	// 4.������Ů��������ƽ���֣��ٽ��ɼ���ƽ�������µļ�¼�����һ�����ļ� c �С�
	double average_male = 0, average_female = 0;
	GradeList gradelist_male, gradelist_female;
	copy_if(gradelist.grade_list.begin(), gradelist.grade_list.end(), back_inserter(gradelist_male.grade_list), [](Grade& grade) {return grade.sex == "��"; });
	copy_if(gradelist.grade_list.begin(), gradelist.grade_list.end(), back_inserter(gradelist_female.grade_list), [](Grade& grade) {return grade.sex == "Ů"; });
	average_male = accumulate(gradelist_male.grade_list.begin(), gradelist_male.grade_list.end(), 0.0, [](double a, Grade& grade) {return a + grade.score; }) / gradelist_male.grade_list.size();
	average_female = accumulate(gradelist_female.grade_list.begin(), gradelist_female.grade_list.end(), 0.0, [](double a, Grade& grade) {return a + grade.score; }) / gradelist_female.grade_list.size();
	GradeList gradelist_male_below, gradelist_female_below;
	copy_if(gradelist_male.grade_list.begin(), gradelist_male.grade_list.end(), back_inserter(gradelist_male_below.grade_list), [average_male](Grade& grade) {return grade.score<average_male; });
	copy_if(gradelist_female.grade_list.begin(), gradelist_female.grade_list.end(), back_inserter(gradelist_female_below.grade_list), [average_female](Grade& grade) {return grade.score < average_female; });
	ofstream out_filec("C:\\��\\�����\\�߼��������\\��ҵ\\12\\c.txt", ios::out);
	if (!out_filec)
		exit(-1);
	out_filec << gradelist_male_below << gradelist_female_below;
	out_filec.close();

	// 5.���Ӽ����µĲ�����¼���Է����� 90% ����¼��ϵͳ��
	cout << "�����벹��ѧ����������Ҫ¼��Ĳ����ɼ���¼��Ϣ��" << endl;
	int n_rest;
	cin >> n_rest;
	Grade grade_rest;
	for (int i = 0; i < n_rest; i++)
	{
		cin >> grade_rest;
		grade_rest.score *= 0.9;
		gradelist.grade_list.push_back(grade_rest);
	}

	// 6.������ݵ��ļ� a �У���ɱ��ĸ��¡�
	ofstream out_filea2("C:\\��\\�����\\�߼��������\\��ҵ\\12\\a.txt", ios::out);
	if (!out_filea2)
		exit(-1);
	out_filea2 << gradelist;
	out_filea2.close();

	return 0;
}