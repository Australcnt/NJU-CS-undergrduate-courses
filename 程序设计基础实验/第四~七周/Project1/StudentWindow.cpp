#include "Login.h"
#include "AdministratorWindow.h"
#include "StudentWindow.h"

//功能函数
void student_window()
{
	for (int i = 0; i < 120; i++)
		cout << '=';
	cout << endl;
	for (int i = 0; i < 22; i++)
	{
		if (i == 0)
			cout << setw(10) << "1、查看课程信息";
		else if (i == 3)
			cout << setw(10) << "2、选择课程";
		else if (i == 6)
			cout << setw(10) << "3、查看个人课表";
		else if (i == 9)
			cout << setw(10) << "4、退出课程";
		else if (i == 12)
			cout << setw(10) << "5、助教报名/撤销";
		else if (i == 15)
			cout << setw(10) << "6、我的个人助教";
		else if (i == 18)
			cout << setw(10) << "7、查看密保";
		else if (i == 21)
			cout << setw(10) << "8、注销登录";
		else
			cout << ' ';
	}
	cout << endl;
	for (int i = 0; i < 120; i++)
		cout << '=';
	cout << endl << endl << endl;
	assistant_drop_check();
	int choice;
	cout << "请输入操作序号：";
	cin >> choice;
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
	cout << endl << endl;
	
	switch (choice)
	{
	case 1: course_view(); break;
	case 2: course_select(); break;
	case 3: student_course_view(); break;
	case 4: student_course_drop(); break;
	case 5: assistant_apply_or_drop(); break;
	case 6: my_assistant(); break;
	case 7: student_security_check(); break;
	case 8: student_logout(); break;
	}
}
void course_view()
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
	while (p)
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
	student_window();
}
void course_select()
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
	while (p)
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
	cout << "（如选择多门课程，课程之间用空格分隔开！）" << endl;
	cout << "请输入想要选择的课程编号（输入'*'返回上一级，已输入的课程会正常读入）：";
	char id[4];
	char ch;
	while(1)
	{
		cin >> id;
		if (id[0] == '*')
		{
			cout << endl << "课程选择成功！已添加至个人课表！（除显示选择失败的课程）" << endl << endl;
			student_window();
		}
		Course* p2 = head;
		while(strcmp(p2->number,id))
		{
			p2 = p2->next;
			if (!p2)
				break;
		}
		if(!p2)
		{
			cout << "不存在课程编号为" << id << "的课程！该课程选择失败！" << endl;
			if (ch = getchar() != ' ')
				break;
			continue;
		}
		if(p2->amount>=p2->capacity)
		{
			cout << id << " " << p2->name << " 课程人数已满！该课程选择失败！" << endl;
			if (ch = getchar() != ' ')
				break;
			continue;
		}
		Student* s = stuhead;
		while (strcmp(s->id, stu_id))
			s = s->next;
		if(!student_course_duplicatcheck(id, s))
		{
			cout << "已选过" << id << "课程！该课程选择失败！" << endl;
			if (ch = getchar() != ' ')
				break;
			continue;
		}
		strcpy(s->course[s->course_amount], p2->number);
		strcpy(s->course_assistant[s->course_amount], "NULL");
		s->course_amount++;
		course_upsort(s->course_amount, s->course, s->course_assistant);
		strcpy(p2->student[p2->amount], stu_id);
		p2->amount++;
		course_update2();
		if (ch = getchar() != ' ')
			break;
		student_course_update();
	}
	student_course_update();
	cout << endl << "课程选择成功！已添加至个人课表！（除显示选择失败的课程）" << endl << endl;
	student_window();
}
void student_course_view()
{
	cout << "当前已选择的课程如下：" << endl << endl;
	for (int i = 0; i < 100; i++)
		cout << '*';
	cout << endl << endl;
	cout << left << setw(12) << "课程编号";
	cout << left << setw(30) << "课程名称";
	cout << left << setw(20) << "授课老师";
	cout << left << setw(20) << "课程类型";
	cout << left << setw(20) << "个人助教";
	cout << endl;
	for (int i = 0; i < 100; i++)
		cout << '-';
	cout << endl;
	int type1 = 0, type2 = 0;
	Student* s = stuhead;
	while (strcmp(s->id, stu_id))
		s = s->next;
	for (int i = 0; i < s->course_amount; i++)
	{
		Course* p = head;
		while (strcmp(p->number, s->course[i]))
			p = p->next;
		cout << left << setw(12) << p->number;
		cout << left << setw(30) << p->name;
		cout << left << setw(20) << p->teacher;
		cout << left << setw(20) << p->type;
		if (!strcmp(p->type, "专业课"))
			type1++;
		if (!strcmp(p->type, "非专业课"))
			type2++;
		cout << left << setw(20) << s->course_assistant[i];
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 100; i++)
		cout << '*';
	cout << endl << endl;
	cout << "根据学院要求，至少需要选择4门专业课和2门非专业课！";
	if (type1 >= 4 && type2 >= 2)
		cout << "您的选课已符合要求！" << endl << endl;
	else if (type1 >= 4 && type2 < 2)
		cout << "您至少还需选择" << 2 - type2 << "门非专业课！" << endl << endl;
	else if (type1 < 4 && type2 >= 2)
		cout << "您至少还需选择" << 4 - type1 << "门专业课！" << endl << endl;
	else
		cout << "您至少还需选择" << 4 - type1 << "门专业课和" << 2 - type2 << "门非专业课！" << endl << endl;
	student_window();
}
void student_course_drop()
{
	cout << "请选择需要退出的课程编号（输入'*'返回上一级）：";
	char id[4];
	cin >> id;
	if (id[0] == '*')
		student_window();
	Course* p = head;
	while (strcmp(p->number, id))
	{
		p = p->next;
		if (!p)
		{
			cout << "您输入的课程不存在！" << endl << endl;
			student_window();
		}
	}
	Student* s = stuhead;
	while (strcmp(s->id, stu_id))
		s = s->next;
	for (int i = 0; i < s->course_amount; i++)
	{
		if (!strcmp(s->course[i], id))
			break;
		if (i == s->course_amount - 1)
		{
			cout << "您尚未选择该门课程！课程退出失败！" << endl << endl;
			student_window();
		}
	}
	for (int i = 0; i < p->assistantamount; i++)
	{
		if(!strcmp(p->assistant[i], stu_id))
		{
			for(int j=i;j<p->assistantamount-1;j++)
				strcpy(p->assistant[j], p->assistant[j + 1]);
			strcpy(p->assistant[p->assistantamount - 1], "\0");
			p->assistantamount--;
			assistant_drop_remind(id);
			assistant_update();
		}
	}
	for (int i = 0; i < s->assistant_course_amount; i++)
	{
		if (!strcmp(s->assistant_course[i], id))
		{
			for (int j = i; j < s->assistant_course_amount - 1; j++)
				strcpy(s->assistant_course[j], s->assistant_course[j + 1]);
			strcpy(s->assistant_course[s->assistant_course_amount], "\0");
			s->assistant_course_amount--;
		}
	}
	for (int i = 0; i < p->amount; i++)
	{
		if (!strcmp(p->student[i], stu_id))
		{
			for (int j = i; j < p->amount - 1; j++)
				strcpy(p->student[j], p->student[j + 1]);
			strcpy(p->student[p->amount - 1], "\0");
			p->amount--;
		}
	}
	for(int i=0;i<s->course_amount;i++)
	{
		if (!strcmp(s->course[i], id))
		{
			for (int j = i; j < s->course_amount - 1; j++)
			{
				strcpy(s->course[j], s->course[j + 1]);
				strcpy(s->course_assistant[j], s->course_assistant[j + 1]);
			}
			strcpy(s->course[s->course_amount - 1], "\0");
			strcpy(s->course_assistant[s->course_amount - 1], "\0");
			s->course_amount--;
		}
	}
	student_course_update();
	course_update2();
	cout << "已退出课程 " << id << ' ' << p->name << "！" << endl << endl;
	student_course_view();
	student_window();
}
void assistant_apply_or_drop()
{
	cout << "请输入您选择的操作（1、助教报名 2、助教撤销 3、返回上一级）：";
	int choice = 0;
	cin >> choice;
	while (1)
	{
		if (choice >= 1 && choice <= 3)
			break;
		else
		{
			cout << "您输入的操作序号不正确，请重新输入！" << endl << endl;
			cout << "请输入您选择的操作（1、助教报名 2、助教撤销 3、返回上一级）：";
			cin >> choice;
		}
	}
	switch (choice)
	{
	case 1: assistant_apply(); break;
	case 2: assistant_drop(); break;
	case 3: student_window(); break;
	}
	student_window();
}
void my_assistant()
{
	
	cout << "请输入您选择的操作（1、选择助教 2、更换助教 3、取消助教 4、返回上一级）：";
	int choice = 0;
	cin >> choice;
	while (1)
	{
		if (choice >= 1 || choice <= 4)
			break;
		else
		{
			cout << "您输入的操作序号不正确，请重新输入！" << endl << endl;
			cout << "请输入您选择的操作（1、选择助教 2、更换助教 3、取消助教 4、返回上一级）：";
			cin >> choice;
		}
	}
	switch (choice)
	{
	case 1: assistant_choose(); break;
	case 2: assistant_change(); break;
	case 3: assistant_cancel(); break;
	case 4: student_window(); break;
	}
	student_window();
}
void student_security_check()
{
	Student* s = stuhead;
	while (strcmp(s->id, stu_id))
		s = s->next;
	if (!strcmp(s->question, "NULL"))
		cout << "您尚未设置密保问题！" << endl << endl;
	else
	{
		cout << "密保问题：" << s->question << endl;
		cout << "密保答案：" << s->answer << endl << endl;
	}
	student_window();
}
void student_logout()
{
	Student* s = stuhead;
	while (strcmp(s->id, stu_id))
		s = s->next;
	int type1 = 0, type2 = 0;
	for (int i = 0; i < s->course_amount; i++)
	{
		Course* p = head;
		while (strcmp(p->number, s->course[i]))
			p = p->next;

		if (!strcmp(p->type, "专业课"))
			type1++;
		if (!strcmp(p->type, "非专业课"))
			type2++;
	}
	cout << "根据学院要求，至少需要选择4门专业课和2门非专业课！";
	if (type1 >= 4 && type2 < 2)
		cout << "您至少还需选择" << 2 - type2 << "门非专业课！" << endl;
	else if (type1 < 4 && type2 >= 2)
		cout << "您至少还需选择" << 4 - type1 << "门专业课！" << endl;
	else
		cout << "您至少还需选择" << 4 - type1 << "门专业课和" << 2 - type2 << "门非专业课！" << endl;
	cout << "请记得以后将课程选择完毕！！！" << endl;
	cout << "您已成功注销学生端！" << endl;
	for (int i = 0; i < 120; i++)
		cout << '*';
	cout << endl << endl;
	welcome();
	begin();
}

//辅助函数
void assistant_drop_check()
{
	Student* s = stuhead;
	while (strcmp(s->id, stu_id))
		s = s->next;
	if(s->assistant_delete_flag)
	{
		for (int i = 0; i < s->assistant_delete_flag; i++)
		{
			cout << "您选择的 " << s->assistant_delete[i] << " 课程的个人助教已退课或已撤销助教！" << endl;
			strcpy(s->assistant_delete[i], "\0");
		}
		cout << endl;
		s->assistant_delete_flag = 0;
	}
}
void course_upsort(int course_amount,char course[][4],char course_assistant[][20])
{
	for(int i = 0; i < course_amount - 1;i++)
		for(int j = 0; j < course_amount - 1 - i; j++)
		{
			if(strcmp(course[j], course[j + 1]) > 0)
			{
				char temp1[4];
				char temp2[20];
				strcpy(temp1, course[j]);
				strcpy(course[j], course[j + 1]);
				strcpy(course[j + 1], temp1);
				strcpy(temp2, course_assistant[j]);
				for (int k=1; k < 20; k++)
					course_assistant[j][k] = '\0';
				strcpy(course_assistant[j], course_assistant[j + 1]);
				for (int k=1; k < 20; k++)
					course_assistant[j + 1][k] = '\0';
				strcpy(course_assistant[j + 1], temp2);
			}
		}
}
void student_course_update()
{
	Student* s = stuhead;
	while (strcmp(s->id, stu_id))
		s = s->next;
	FILE* fp = fopen(filename2, "w");
	if(fp==NULL)
	{
		cout << filename2 << "文件打开失败！" << endl;
		exit(-1);
	}
	for(int i=0;i<s->course_amount;i++)
	{
		fprintf(fp, "%s %s", s->course[i], s->course_assistant[i]);
		fputc('\n', fp);
	}
	fclose(fp);
}
void course_update2()
{
	FILE* fp = fopen("./currentcourse.txt", "w");
	if (fp == NULL)
	{
		cout << "currentcourse.txt打开失败！" << endl;
		exit(-1);
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
bool student_course_duplicatcheck(char id[],Student*s)
{
	for (int i = 0; i < s->course_amount; i++)
	{
		if (!strcmp(s->course[i], id))
			return false;
	}
	return true;
}
void assistant_drop_remind(char id[])
{
	Student* s = stuhead;
	while(s)
	{
		for (int i = 0; i < s->course_amount; i++)
		{
			if (!strcmp(s->course[i], id))
			{
				if (!strcmp(s->course_assistant[i], stu_id))
				{
					strcpy(s->course_assistant[i], "NULL");
					strcpy(s->assistant_delete[s->assistant_delete_flag], id);
					s->assistant_delete_flag++;
					otherstudent_course_update(s->id);
				}
			}
		}
		s = s->next;
	}
}
void assistant_apply()
{
	cout << "请输入想要报名助教的课程编号（输入'*'返回上一级）：";
	char id[4];
	cin >> id;
	if (id[0] == '*')
		assistant_apply_or_drop();
	Course* p = head;
	while (strcmp(p->number, id))
	{
		p = p->next;
		if (!p)
		{
			cout << "您输入的课程不存在！" << endl << endl;
			student_window();
		}
	}
	Student* s = stuhead;
	while (strcmp(s->id, stu_id))
		s = s->next;
	for (int i = 0; i < s->course_amount; i++)
	{
		if (!strcmp(s->course[i], id))
			break;
		if (i == s->course_amount - 1)
		{
			cout << "您尚未选择该门课程！助教报名失败！" << endl << endl;
			student_window();
		}
	}
	for (int i = 0; i < s->assistant_course_amount; i++)
	{
		if (!strcmp(s->assistant_course[i], id))
		{
			cout << "您已报名过该门课程的助教！无法重复报名！" << endl << endl;
			student_window();
		}
	}
	if (s->assistant_course_amount == 2)
	{
		cout << "您最多只能报名2门课程的助教！助教报名失败！" << endl << endl;
		student_window();
	}
	strcpy(p->assistant[p->assistantamount], stu_id);
	p->assistantamount++;
	strcpy(s->assistant_course[s->assistant_course_amount], id);
	s->assistant_course_amount++;
	assistant_update();
	cout << "助教报名成功！" << endl << endl << endl;
}
void assistant_drop()
{
	cout << "请输入想要撤销助教的课程编号（输入'*'返回上一级）：";
	char id[4];
	cin >> id;
	if (id[0] == '*')
		assistant_apply_or_drop();
	Course* p = head;
	while (strcmp(p->number, id))
	{
		p = p->next;
		if (!p)
		{
			cout << "您输入的课程不存在！" << endl << endl;
			student_window();
		}
	}
	Student* s = stuhead;
	while (strcmp(s->id, stu_id))
		s = s->next;
	for (int i = 0; i < s->course_amount; i++)
	{
		if (!strcmp(s->course[i], id))
			break;
		if (i == s->course_amount - 1)
		{
			cout << "您尚未选择该门课程！助教撤销失败！" << endl << endl;
			student_window();
		}
	}
	if (s->assistant_course_amount == 0)
	{
		cout << "您尚未报名任何课程的助教！助教撤销失败！" << endl << endl;
		student_window();
	}
	for (int i = 0; i < s->assistant_course_amount; i++)
	{
		if (!strcmp(s->assistant_course[i], id))
		{
			for (int j = i; j < s->assistant_course_amount - 1; j++)
				strcpy(s->assistant_course[j], s->assistant_course[j + 1]);
			strcpy(s->assistant_course[s->assistant_course_amount], "\0");
			s->assistant_course_amount--;
			break;
		}
		if(i==s->assistant_course_amount-1)
		{
			cout << "您未报名该门课程的助教！助教撤销失败！" << endl << endl;
			student_window();
		}
	}
	for (int i = 0; i < p->assistantamount; i++)
	{
		if (!strcmp(p->assistant[i], stu_id))
		{
			for (int j = i; j < p->assistantamount - 1; j++)
				strcpy(p->assistant[j], p->assistant[j + 1]);
			strcpy(p->assistant[p->assistantamount - 1], "\0");
			p->assistantamount--;
			assistant_drop_remind(id);
			assistant_update();
		}
	}
	cout << "助教撤销成功！" << endl << endl << endl;
}
void assistant_choose()
{
	cout << "请输入想要选择助教的课程编号（输入'*'返回上一级）：";
	char id[4];
	cin >> id;
	if (id[0] == '*')
		my_assistant();
	Course* p = head;
	while (strcmp(p->number, id))
	{
		p = p->next;
		if (!p)
		{
			cout << "您输入的课程不存在！" << endl << endl;
			student_window();
		}
	}
	Student* s = stuhead;
	while (strcmp(s->id, stu_id))
		s = s->next;
	for (int i = 0; i < s->course_amount; i++)
	{
		if (!strcmp(s->course[i], id))
			break;
		if (i == s->course_amount - 1)
		{
			cout << "您尚未选择该门课程！助教选择失败！" << endl << endl;
			student_window();
		}
	}
	if (p->assistantamount == 0)
	{
		cout << "该门课程当前没有助教！无法选择！" << endl << endl;
		student_window();
	}
	cout << id << ' ' << p->name << " 课程的助教有：";
	for (int i = 0; i < p->assistantamount - 1; i++)
	{
		cout << p->assistant[i] << ',';
	}
	cout << p->assistant[p->assistantamount - 1] << endl << endl;
	cout << "请您从以上助教中选择一名作为自己的助教（输入'*'返回上一级）：";
	char assistant_id[20];
	cin >> assistant_id;
	if (assistant_id[0] == '*')
		assistant_choose();
	if (!strcmp(assistant_id, stu_id))
	{
		cout << "您不能选择自己为自己的助教！助教选择失败！" << endl << endl;
		student_window();
	}
	for (int i = 0; i < p->assistantamount; i++)
	{
		if (!strcmp(p->assistant[i], assistant_id))
			break;
		if (i == p->assistantamount - 1)
		{
			cout << "您输入的助教不正确！助教选择失败！" << endl << endl;
			student_window();
		}
	}
	for (int i = 0; i < s->course_amount; i++)
	{
		if (!strcmp(s->course[i], id))
		{
			if (!strcmp(s->course_assistant[i], "NULL"))
			{
				strcpy(s->course_assistant[i], assistant_id);
				break;
			}
			else
			{
				cout << "每门课程至多选择一名助教！助教选择失败！" << endl << endl;
				student_window();
			}
		}
	}
	student_course_update();
	cout << endl << "个人助教选择成功！" << endl << endl;
}
void assistant_change()
{
	cout << "请输入想要更换助教的课程编号（输入'*'返回上一级）：";
	char id[4];
	cin >> id;
	if (id[0] == '*')
		my_assistant();
	Course* p = head;
	while (strcmp(p->number, id))
	{
		p = p->next;
		if (!p)
		{
			cout << "您输入的课程不存在！" << endl << endl;
			student_window();
		}
	}
	Student* s = stuhead;
	while (strcmp(s->id, stu_id))
		s = s->next;
	for (int i = 0; i < s->course_amount; i++)
	{
		if (!strcmp(s->course[i], id))
			break;
		if (i == s->course_amount - 1)
		{
			cout << "您尚未选择该门课程！助教更换失败！" << endl << endl;
			student_window();
		}
	}
	if (p->assistantamount == 0)
	{
		cout << "该门课程当前没有助教！无法更换！" << endl << endl;
		student_window();
	}
	for (int i = 0; i < s->course_amount; i++)
	{
		if (!strcmp(s->course[i], id))
		{
			if(!strcmp(s->course_assistant[i],"NULL"))
			{
				cout << "您尚未选择该门课程的助教！请先选择助教！" << endl << endl;
				student_window();
			}
		}
	}
	cout << id << ' ' << p->name << " 课程的助教有：";
	for (int i = 0; i < p->assistantamount - 1; i++)
	{
		cout << p->assistant[i] << ',';
	}
	cout << p->assistant[p->assistantamount - 1] << endl << endl;
	cout << "请您从以上助教中选择一名作为自己更换后的的助教（输入'*'返回上一级）：";
	char assistant_id[20];
	cin >> assistant_id;
	if (assistant_id[0] == '*')
		assistant_change();
	if (!strcmp(assistant_id, stu_id))
	{
		cout << "您不能选择自己为自己的助教！助教更换失败！" << endl << endl;
		student_window();
	}
	for (int i = 0; i < p->assistantamount; i++)
	{
		if (!strcmp(p->assistant[i], assistant_id))
			break;
		if (i == p->assistantamount - 1)
		{
			cout << "您输入的助教不正确！助教更换失败！" << endl << endl;
			student_window();
		}
	}
	for (int i = 0; i < s->course_amount; i++)
	{
		if (!strcmp(s->course[i], id))
		{
			strcpy(s->course_assistant[i], assistant_id);
			break;
		}
	}
	student_course_update();
	cout << endl << "个人助教更换成功！" << endl << endl;
}
void assistant_cancel()
{
	cout << "请输入想要取消助教的课程编号（输入'*'返回上一级）：";
	char id[4];
	cin >> id;
	if (id[0] == '*')
		my_assistant();
	Course* p = head;
	while (strcmp(p->number, id))
	{
		p = p->next;
		if (!p)
		{
			cout << "您输入的课程不存在！" << endl << endl;
			student_window();
		}
	}
	Student* s = stuhead;
	while (strcmp(s->id, stu_id))
		s = s->next;
	for (int i = 0; i < s->course_amount; i++)
	{
		if (!strcmp(s->course[i], id))
			break;
		if (i == s->course_amount - 1)
		{
			cout << "您尚未选择该门课程！助教取消失败！" << endl << endl;
			student_window();
		}
	}
	if (p->assistantamount == 0)
	{
		cout << "该门课程当前没有助教！无法取消！" << endl << endl;
		student_window();
	}
	for (int i = 0; i < s->course_amount; i++)
	{
		if (!strcmp(s->course[i], id))
		{
			if (!strcmp(s->course_assistant[i], "NULL"))
			{
				cout << "您尚未选择该门课程的助教！无法取消助教！" << endl << endl;
				student_window();
			}
			else
				strcpy(s->course_assistant[i], "NULL");

		}
	}
	student_course_update();
	cout << endl << "个人助教取消成功！" << endl << endl;
}
void assistant_update()
{
	FILE* fp = fopen("./assistant.txt", "w");
	if(fp==NULL)
	{
		cout << "assistant.txt文件打开失败！" << endl;
		exit(-1);
	}
	Course* head2 = head;
	while(head2)
	{
		fprintf(fp, "%s ", head2->number);
		if(head2->assistantamount==0)
		{
			fprintf(fp, "%s", "NULL");
			fputc('\n', fp);
			head2 = head2->next;
			continue;
		}
		for(int i=0;i<head2->assistantamount-1;i++)
			fprintf(fp, "%s ", head2->assistant[i]);
		fprintf(fp, "%s", head2->assistant[head2->assistantamount - 1]);
		fputc('\n', fp);
		head2 = head2->next;
	}
	fclose(fp);
}
void otherstudent_course_update(char otherstudent_name[])
{
	char filename3[30];
	strcpy(filename3, otherstudent_name);
	int fn3_it = 0;
	while (filename3[fn3_it] != '\0')
		fn3_it++;
	filename3[fn3_it] = '.';
	filename3[fn3_it + 1] = 't';
	filename3[fn3_it + 2] = 'x';
	filename3[fn3_it + 3] = 't';
	filename3[fn3_it + 4] = '\0';
	Student* s = stuhead;
	while (strcmp(s->id, stu_id))
		s = s->next;
	FILE* fp = fopen(filename3, "w");
	if (fp == NULL)
	{
		cout << filename3 << "文件打开失败！" << endl;
		exit(-1);
	}
	for (int i = 0; i < s->course_amount; i++)
	{
		fprintf(fp, "%s %s", s->course[i], s->course_assistant[i]);
		fputc('\n', fp);
	}
	fclose(fp);
}