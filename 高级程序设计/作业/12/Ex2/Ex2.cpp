#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream out_file("C:\\南\\大二下\\高级程序设计\\作业\\12\\zero_search.txt", ios::out);
	if (!out_file)
		exit(-1);
	for (int i = 1; i <= 100; i++)
		out_file << i;
	out_file.close();
	ifstream in_file("C:\\南\\大二下\\高级程序设计\\作业\\12\\zero_search.txt", ios::in);
	if (!in_file)
		exit(-1);
	char ch;
	int len = 2;
	char num[4];
	num[3] = '\0';
	while(!in_file.eof())
	{
		in_file >> ch;
		if (ch == '0')
		{
			in_file >> ch;
			in_file.seekg(-3, ios::cur);
			if (ch == '0')
				len = 3;
			in_file.read(num, len);
			cout << num << endl;
			if (len == 3)
				break;
		}
	}
	in_file.close();
	return 0;
}