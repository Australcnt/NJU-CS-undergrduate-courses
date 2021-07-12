#include "Login.h"
#include "AdministratorWindow.h"
#include "StudentWindow.h"

//功能函数
void administrator_window()
{
	for (int i = 0; i < 120; i++)
		cout << '=';
	cout << endl;
	for (int i = 0; i < 23; i++)
	{
		if (i == 1)
			cout << setw(10) << "1、录入课程信息";
		else if (i == 4)
			cout << setw(10) << "2、查看全部课程信息";
		else if (i == 7)
			cout << setw(10) << "3、增加课程";
		else if (i == 10)
			cout << setw(10) << "4、删除课程";
		else if (i == 13)
			cout << setw(10) << "5、修改课程";
		else if (i == 16)
			cout << setw(10) << "6、查看具体课程";
		else if (i == 19)
			cout << setw(10) << "7、查看密保";
		else if (i == 22)
			cout << setw(10) << "8、注销登录";
		else
			cout << ' ';
	}
	cout << endl;
	for (int i = 0; i < 120; i++)
		cout << '=';
	cout << endl << endl << endl;
	int choice;
	cout << "请输入操作序号：";
	cin >> choice;
	if(!administrator_first)
	{
		while (1)
		{
			if (choice==1||choice==7||choice==8)
				break;
			else
			{
				cout << "管理员第一次登录必须先录入课程（或查看密保和注销登录），请重新输入！" << endl << endl;
				cout << "请输入操作序号：";
				cin >> choice;
			}
		}
	}
	else
	{
		while (1)
		{
			if (choice > 0 && choice < 9)
				break;
			else
			{
				cout << "您输入的操作序号不正确，请重新输入！" << endl << endl;
				cout << "请输入操作序号：";
				cin >> choice;
			}
		}
	}
	cout << endl << endl;
	switch(choice)
	{
	case 1: course_typein(); break;
	case 2: allcourse_view(); break;
	case 3: course_add(); break;
	case 4: course_delete(); break;
	case 5: course_change(); break;
	case 6: specificcourse_view(); break;
	case 7: administrator_security_check(); break;
	case 8: administrator_logout(); break;
	}
}
void course_typein()
{
	FILE* p = fopen("./currentcourse.txt", "r");
	if(p)
	{
		cout << "此前课程信息已录入！不能重复录入！" << endl << endl;
		cout << "请重新选择操作！" << endl << endl;
		fclose(p);
		administrator_window();
	}
	char filename[1000];
	cout << "请输入需要录入的课程文件的名称（输入'*'返回上一级）：";
	cin >> filename;
	if (filename[0] == '*')
		administrator_window();
	course_get(filename);
	course_update();
	administrator_first++;
	cout << endl << endl << "课程信息录入成功！" << endl << endl;
	administrator_window();
}
void allcourse_view()
{
	for (int i = 0; i < 90; i++)
		cout << '*';
	cout << endl << endl;
	cout << left << setw(12) << "课程编号";
	cout << left << setw(30) << "课程名称";
	cout << left << setw(20) << "授课老师";
	cout << left << setw(10) << "上限人数";
	cout << left << setw(10) << "已选人数";
	cout << left << setw(10) << "课程类型";
	cout << endl;
	for (int i = 0; i < 90; i++)
		cout << '-';
	cout << endl;
	Course* p = head;
	while(p)
	{
		cout << left << setw(12) << p->number;
		cout << left << setw(30) << p->name;
		cout << left << setw(20) << p->teacher; 
		cout << left << setw(10) << p->capacity;
		cout << left << setw(10) << p->amount;
		cout << left << setw(10) << p->type;
		cout << endl;
		p = p->next;
	}
	cout << endl;
	for (int i = 0; i < 90; i++)
		cout << '*';
	cout << endl << endl;
	administrator_window();
}
void course_add()
{
	cout << "（请依次输入：课程名称、授课老师、上限人数、已选人数、课程类型，中间用空格分隔开！)" << endl;
	cout << "（每门课程输入后请敲入回车！最后以#结束！）" << endl << endl;
	cout << "请输入需要增加的课程信息（输入'*'返回上一级，已输入的课程会正常读入）：" << endl;
	while (1)
	{
		Course* head2 = new Course;
		if(head)
			head2 = head;
		while (head && head2->next)
			head2 = head2->next;
		char ch;
		Course* p = new Course;
		if (head)
		{
			strcpy_s(p->number, head2->number);
			if (p->number[2] != '9')
				p->number[2]++;
			else if (p->number[2] == '9' && p->number[1] != '9')
			{
				p->number[2] = '0';
				p->number[1]++;
			}
			else
			{
				p->number[2] = '0';
				p->number[1] = '0';
				p->number[0] = '1';
			}
		}
		else
			strcpy(p->number, "001");
		cin >> p->name;
		if (p->name[0] == '*')
			administrator_window();
		if (p->name[0] == '#')
			break;
		if (ch = getchar() != ' ')
		{
			cout << p->name << " 课程信息格式错误！该课程增加失败！" << endl << endl;
			continue;
		}
		cin >> p->teacher;
		if (ch = getchar() != ' ')
		{
			cout << p->name << " 课程信息格式错误！该课程增加失败！" << endl << endl;
			continue;
		}
		cin >> p->capacity;
		if (ch = getchar() != ' ')
		{
			cout << p->name << " 课程信息格式错误！该课程增加失败！" << endl << endl;
			continue;
		}
		cin >> p->amount;
		if (ch = getchar() != ' ')
		{
			cout << p->name << " 课程信息格式错误！该课程增加失败！" << endl << endl;
			continue;
		}
		cin >> p->type;
		p->assistantamount = 0;
		if (p->capacity <= 0)
		{
			cout << p->name << " 课程上限人数必须为正数！该课程增加失败！" << endl << endl;
			continue;
		}
		if (p->amount < 0)
		{
			cout << p->name << " 课程已选人数不能为负数！该课程增加失败！" << endl << endl;
			continue;
		}
		if (p->amount > p->capacity)
		{
			cout << p->name << " 课程已选人数不能超过上限人数！该课程增加失败！" << endl << endl;
			continue;
		}
		if (!head || course_duplicatcheck(p))//检查课程是否重复
		{
			p->next = NULL;
			if (head)
			{
				head2->next = p;
				head2 = p;
			}
			else
				head = p;
			FILE* fp = fopen("./currentcourse.txt", "a");
			if (fp == NULL)
			{
				cout << "currentcourse.txt打开失败！" << endl;
			}
			fprintf(fp, "%-4s%-30s%-20s%-5d%-5d%-10s", p->number, p->name, p->teacher, p->capacity, p->amount, p->type);
			fputc('\n', fp);
			fclose(fp);
		}
	}
	cout << "课程增加成功！(不包括增加失败的课程）" << endl << endl;
	allcourse_view();
}
void course_delete()
{
	if(!head)
	{
		cout << "当前没有任何课程！无法删除课程！" << endl;
		administrator_window();
	}
	cout << "请输入需要删除的课程编号（输入'*'返回上一级）：";
	char id[4];
	cin >> id;
	if (id[0] == '*')
		administrator_window();
	Course* head2 = head;
	if (!strcmp(id, head->number) && head->amount == 0)
	{
		Course* cur = head;
		cout << head->name << " 课程删除成功！" << endl << endl;
		head = head->next;
		delete(cur);
	}
	else if (!strcmp(id, head->number) && head->amount != 0)
		cout << "该课程已有学生选择！无法删除！" << endl << endl;
	else
	{
		while (head2->next)
		{
			if (!strcmp(id, head2->next->number) && head2->next->amount == 0)
			{
				Course* cur = head2->next;
				cout << head2->next->name << " 课程删除成功！" << endl << endl;
				head2->next = head2->next->next;
				delete(cur);
				break;
			}
			if (!strcmp(id, head2->next->number) && head2->next->amount != 0)
			{
				cout << head2->next->name << " 课程已有学生选择！无法删除！" << endl << endl;
				break;
			}
			head2 = head2->next;
			if (!head2->next)
				cout << "您输入的课程不存在！无法删除！" << endl << endl;
		}
	}
	course_update();
	administrator_window();
}
void course_change()
{
	if (!head)
	{
		cout << "当前没有任何课程！无法修改课程！" << endl;
		administrator_window();
	}
	cout << "请输入需要修改的操作序号（1、授课老师  2、上限人数  3、返回上一级）：";
	int choice = 0;
	cin >> choice;
	if (choice == 3)
		administrator_window();
	while (choice < 1 || choice > 3)
	{
		cout << "您输入的操作序号不正确，请重新输入！" << endl << endl;
		cout << "请输入需要修改的操作序号（1、授课老师  2、上限人数  3、返回上一级）：";
		cin >> choice;
		if (choice == 3)
			administrator_window();
	}
	cout << "请输入需要修改的课程编号（输入'*'返回上一级）：";
	char id[4];
	cin >> id;
	if (id[0] == '*')
		course_change();
	switch (choice)
	{
	case 1: teacher_change(id); break;
	case 2: capacity_change(id); break;
	case 3:administrator_window(); break;
	}
	administrator_window();
}
void specificcourse_view()
{
	if (!head)
	{
		cout << "当前没有任何课程！无法查看具体课程！" << endl;
		administrator_window();
	}
	int choice;
	cout << "请输入您查看课程的方式（1、课程编号  2、课程名称  3、返回上一级）：";
	cin >> choice;
	while(choice < 1 || choice > 3)
	{
		cout << "您输入的操作序号不正确，请重新输入！" << endl << endl;
		cout << "请输入您查看课程的方式（1、课程编号  2、课程名称  3、返回上一级）：";
		cin >> choice;
	}
	Course* p = head;
	if (choice == 1)
	{
		cout << "请输入需要查看的课程编号（输入'*'返回上一级）：";
		char id[4];
		cin >> id;
		if (id[0] == '*')
			administrator_window();
		while (strcmp(p->number, id))
		{
			p = p->next;
			if (!p)
			{
				cout << "您输入的课程不存在！" << endl << endl;
				administrator_window();
			}
		}
	}
	else if (choice == 2)
	{
		cout << "请输入需要查看的课程名称（输入'*'返回上一级）：";
		char name[30];
		cin >> name;
		if (name[0] == '*')
			administrator_window();
		Course* p = head;
		while (strcmp(p->name, name))
		{
			p = p->next;
			if (!p)
			{
				cout << "您输入的课程不存在！" << endl << endl;
				administrator_window();
			}
		}
	}
	else
		administrator_window();
	cout << endl;
	for (int i = 0; i < 90; i++)
		cout << '*';
	cout << endl << endl;
	cout << left << setw(12) << "课程编号";
	cout << left << setw(30) << "课程名称";
	cout << left << setw(20) << "授课老师";
	cout << left << setw(10) << "上限人数";
	cout << left << setw(10) << "已选人数";
	cout << left << setw(10) << "课程类型";
	cout << endl;
	for (int i = 0; i < 90; i++)
		cout << '-';
	cout << endl;
	cout << left << setw(12) << p->number;
	cout << left << setw(30) << p->name;
	cout << left << setw(20) << p->teacher;
	cout << left << setw(10) << p->capacity;
	cout << left << setw(10) << p->amount;
	cout << left << setw(10) << p->type;
	cout << endl;
	cout << endl;
	for (int i = 0; i < 90; i++)
		cout << '*';
	cout << endl << endl;
	cout << "还想进行以下哪项操作：1、查看该课程学生名单  2、查看该课程报名助教名单  3、返回主界面" << endl;
	cout << "请输入操作序号：";
	int choice2;
	cin >> choice2;
	while (choice2 < 1 || choice2 > 3)
	{
		cout << "您输入的操作序号不正确，请重新输入！" << endl << endl;
		cout << "请输入操作序号：";
		cin >> choice2;
	}
	switch (choice2)
	{
	case 1: student_view(p); break;
	case 2: assistant_view(p); break;
	case 3: administrator_window(); break;
	}
}
void administrator_security_check()
{
	if (!strcmp(my_question, "NULL"))
		cout << "您尚未设置密保问题！" << endl << endl;
	else
	{
		cout << "密保问题：" << my_question << endl;
		cout << "密保答案：" << my_answer << endl << endl;
	}
	administrator_window();
}
void administrator_logout()
{
	cout << "您已成功注销管理员端！" << endl;
	for (int i = 0; i < 120; i++)
		cout << '*';
	cout << endl << endl;
	welcome();
	begin();
}

//辅助函数
void course_get(char filename[])
{
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		cout << filename << "打开失败" << endl;
		cout << "请重新选择操作！" << endl << endl;
		administrator_window();
	}
	if (feof(fp))
	{
		cout << "该课程文件为空！请重新选择课程文件！" << endl << endl;
		course_typein();
	}
	Course* tail = NULL;
	while (!feof(fp))
	{
		Course* p = new Course;
		fscanf(fp, "%s", p->number);
		if (feof(fp))
			break;
		fscanf(fp, "%s", p->name);
		fscanf(fp, "%s", p->teacher);
		fscanf(fp, "%d", &p->capacity);
		fscanf(fp, "%d", &p->amount);
		fscanf(fp, "%s", p->type);
		p->assistantamount = 0;
		p->next = NULL;
		if (head == NULL)
			head = p;
		else
			tail->next = p;
		tail = p;
	}
	fclose(fp);
}
void course_update()
{
	FILE* fp = fopen("./currentcourse.txt", "w");
	if (fp == NULL)
	{
		cout << "currentcourse.txt打开失败" << endl;
		cout << "请重新选择操作！" << endl << endl;
		administrator_window();
	}
	Course* head2 = head;
	while (head2)
	{
		fprintf(fp, "%-4s%-30s%-20s%-5d%-5d%-10s", head2->number, head2->name, head2->teacher, head2->capacity, head2->amount, head2->type);
		fputc('\n', fp);
		head2 = head2->next;
	}
	
	fclose(fp);
}
bool course_duplicatcheck(Course*p)
{
	Course* head2 = head;
	while (head2)
	{
		if (!strcmp(head2->name, p->name))
		{
			cout << p->name << " 课程已存在！该课程增加失败！" << endl;
			return false;
		}
		head2 = head2->next;
	}
	return true;
}
void teacher_change(char id[])
{
	char teacher[20];
	Course* head2 = head;
	while(head2)
	{
		if(!strcmp(head2->number,id))
		{
			cout << "请输入修改后的授课老师（输入'*'返回上一级）：";
			cin >> teacher;
			if (teacher[0] == '*')
				course_change();
			strcpy(head2->teacher, teacher);
			break;
		}
		head2 = head2->next;
		if (!head2)
			cout << "您输入的课程不存在！" << endl;
	}
	course_update();
	if (head2)
		cout << endl << "授课老师修改成功！" << endl << endl;
}
void capacity_change(char id[])
{
	int capacity = 0;
	Course* head2 = head;
	while (head2)
	{
		if (!strcmp(head2->number,id))
		{
			cout << "请输入修改后的上限人数（输入'0'返回上一级）：";
			cin >> capacity;
			if (capacity == 0)
				course_change();
			else if(capacity < 0)
				cout << "修改的上限人数必须为正数！修改失败！" << endl << endl;
			else if (capacity >= head2->amount)
				head2->capacity = capacity;
			else
				cout << "修改的上限人数不能小于已选人数！修改失败！" << endl << endl;
			break;
		}
		head2 = head2->next;
		if (!head2)
			cout << "您输入的课程不存在！" << endl;
	}
	course_update();
	if (head2 && capacity >= head2->amount && capacity != 0)
		cout << endl << "上限人数修改成功！" << endl << endl;
}
void student_view(Course* p)
{
	if (!p->amount)
		cout << "当前没有学生选择该门课程！" << endl;
	else
	{
		cout << "当前选择该门课程的学生有：";
		for(int i=0;i<p->amount;i++)
		{
			cout << p->student[i];
			if (i != p->amount - 1)
				cout << ',';
		}
		cout << endl;
		cout << "共计" << p->amount << "名学生，距离满课还差" << p->capacity - p->amount << "人！" << endl << endl;
	}
	cout << "还想进行以下哪项操作：1、查看该课程报名助教名单  2、返回主界面" << endl;
	cout << "请输入操作序号：";
	int choice;
	cin >> choice;
	while (choice < 1 || choice > 2)
	{
		cout << "您输入的操作序号不正确，请重新输入！" << endl << endl;
		cout << "请输入操作序号：";
		cin >> choice;
	}
	cout << endl;
	switch (choice)
	{
	case 1: assistant_view(p); break;
	case 2: administrator_window(); break;
	}
}
void assistant_view(Course* p)
{
	if (!p->assistantamount)
		cout << "当前该门课程没有学生报名助教！" << endl;
	else
	{
		cout << "当前选择该门课程报名的助教有：";
		for (int i = 0; i < p->assistantamount; i++)
		{
			cout << p->assistant[i];
			if (i != p->assistantamount - 1)
				cout << ',';
		}
		cout << endl;
		cout << "共计" << p->assistantamount << "名助教！" << endl << endl;
	}
	cout << "还想进行以下哪项操作：1、查看特定助教下的学生名单 2、查看该课程学生名单  3、返回主界面" << endl;
	cout << "请输入操作序号：";
	int choice;
	cin >> choice;
	while (choice < 1 || choice > 3)
	{
		cout << "您输入的操作序号不正确，请重新输入！" << endl << endl;
		cout << "请输入操作序号：";
		cin >> choice;
	}
	cout << endl;
	switch (choice)
	{
	case 1: student_of_assistant_view(p); break;
	case 2: student_view(p); break;
	case 3: administrator_window(); break;
	}
}
void student_of_assistant_view(Course*p)
{
	if (!p->assistantamount)
		cout << "当前该门课程没有学生报名助教！" << endl << endl;
	else
	{
		cout << "当前选择该门课程报名的助教有：";
		for (int i = 0; i < p->assistantamount; i++)
		{
			cout << p->assistant[i];
			if (i != p->assistantamount - 1)
				cout << ',';
		}
		cout << endl;
		cout << "请输入您想查看的助教ID（输入'*'返回上一级）：";
		char assistant_id[21];
		cin >> assistant_id;
		if (assistant_id[0] == '*')
			specificcourse_view();
		while(!assistant_check(p,assistant_id))
		{
			cout << "您输入的助教不存在！请重新输入！" << endl;
			cout << "请输入您想查看的助教ID（输入'*'返回上一级）：";
			cin >> assistant_id;
			if (assistant_id[0] == '*')
				specificcourse_view();
		}
		cout << "该助教下的学生名单为：" << endl;
		Student* s = stuhead;
		int student_number = 0;
		while(1)
		{
			for(int i=0;i<s->course_amount;i++)
			{
				if((!strcmp(s->course[i],p->number))&&!strcmp(s->course_assistant[i],assistant_id))
				{
					cout << s->id << endl;
					student_number = 1;
					break;
				}
			}
			s = s->next;
			if (!s)
				break;
		}
		if (student_number == 0)
			cout << "NULL" << endl;
		cout << endl;
	}
	cout << "还想进行以下哪项操作：1、查看该课程学生名单  2、返回主界面" << endl;
	cout << "请输入操作序号：";
	int choice;
	cin >> choice;
	while (choice < 1 || choice > 2)
	{
		cout << "您输入的操作序号不正确，请重新输入！" << endl << endl;
		cout << "请输入操作序号：";
		cin >> choice;
	}
	cout << endl;
	switch (choice)
	{
	case 1: student_view(p); break;
	case 2: administrator_window(); break;
	}
}
bool assistant_check(Course*p,char assistant_id[])
{
	for (int i = 0; i < p->assistantamount; i++)
	{
		if (!strcmp(p->assistant[i], assistant_id))
			return true;
		if (i == p->assistantamount - 1)
		{
			return false;
		}
	}
}