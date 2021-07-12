#include "Login.h"
#include "StudentWindow.h"
#include "AdministratorWindow.h"
char my_id[21] = "Admin";
char my_password[21] = "admin";
char my_question[51] = "NULL";
char my_answer[51] = "NULL";
char admin_id[21];
char admin_password[21];
int admin_wrong_times = 0;
char stu_id[21];
char stu_password[21];
char filename2[30];

//功能函数
void welcome()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			if (i == 7 && j == 6)
				cout << "   学生选课";
			else if (i == 7 && j == 7)
				cout << "信息管理";
			else if (i == 7 && j == 8)
				cout << "系统     ";
			else if (((((i == j + 5) && i != 14) || (i == j - 7)) && j != 0 && j != 1 && j != 2 && j != 13 && j != 14) || (j == 5 && i >= 4 && i <= 10) || (j == 10 && i >= 3 && i <= 9))
				cout << "*\t";
			else
				cout << "\t";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 90; i++)
	{
		if (i == 45)
			cout << " 欢迎进入学生选课信息管理系统！";
		else
			cout << '*';
	}
	cout << endl << endl << endl;
}
void begin()
{
	switch (login())
	{
	case 1: student_window(); break;
	case 2: student_window(); break;
	case 3: administrator_window(); break;
	case 4: begin(); break;
	case 5: begin(); break;
	case 6: begin(); break;
	case 7: exit(0); break;
	}
}
int login()
{
	for (int i = 0; i < 120; i++)
		cout << '=';
	cout << endl;
	for (int i = 0; i < 45; i++)
	{
		if (i == 2)
			cout << setw(10) << "1、学生登录";
		else if (i == 9)
			cout << setw(10) << "2、学生注册";
		else if (i == 16)
			cout << setw(10) << "3、管理员登录";
		else if (i == 23)
			cout << setw(10) << "4、修改密码";
		else if (i == 30)
			cout << setw(10) << "5、密保功能";
		else if (i == 37)
			cout << setw(10) << "6、找回密码";
		else if (i == 44)
			cout << setw(10) << "7、退出系统";
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
	while (1)
	{
		if (choice > 0 && choice < 8)
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
	case 1: student_login(); break;
	case 2: student_register(); break;
	case 3: administrator_login(); break;
	case 4: password_change(); break;
	case 5: question_set_or_change(); break;
	case 6: password_retrieve(); break;
	case 7: logdown(); break;
	}
	return choice;
}
void student_login()
{
	while (1)
	{
		cout << "请输入学生ID（输入'*'返回上一级）：";
		cin >> stu_id;
		if (stu_id[0] == '*')
			begin();
		cout << "请输入学生个人密码（输入'*'返回上一级）：";
		int i = 0;
		char ch;
		while((ch=_getch())!='\r')
		{
			if(ch=='\b'&&i>0)
			{
				printf("\b \b");
				--i;
			}
			else if(ch!='\b')
			{
				stu_password[i] = ch;
				i++;
				printf("*");
			}
		}
		stu_password[i] = '\0';
		cout << endl;
		if (stu_password[0] == '*')
			begin();
		if (match_account(stu_id, stu_password))//函数中需输出不匹配的原因
			break;
	}
	cout << endl;
	Student* s = stuhead;
	while (strcmp(s->id, stu_id))
		s = s->next;
	if (s->wrong_times == 5)
	{
		cout << "该ID已被锁定！请找回密码后登录！" << endl << endl;
		begin();
	}
	s->wrong_times = 0;
	strcpy(filename2, stu_id);
	int fn_it = 0;
	while (filename2[fn_it] != '\0')
		fn_it++;
	filename2[fn_it] = '.';
	filename2[fn_it + 1] = 't';
	filename2[fn_it + 2] = 'x';
	filename2[fn_it + 3] = 't';
	filename2[fn_it + 4] = '\0';
	FILE* fp = fopen("./currentcourse.txt", "r");
	if (fp == NULL)
	{
		cout << "当前管理员尚未录入课程！无法登录学生端！" << endl;
		for (int i = 0; i < 120; i++)
			cout << '*';
		cout << endl;
		begin();
	}
	fclose(fp);
	for (int i = 0; i < 104; i++)
	{
		if (i == 52)
			cout << " 成功登录学生端！";
		else
			cout << '*';
	}
	cout << endl << endl;
}
void student_register()
{
	while (1)
	{
		cout << "（ID与密码只能含有小写字母和数字，且不超过20个字符！）" << endl;
		cout << "请输入学生ID（输入'*'返回上一级）：";
		cin >> stu_id;
		if (stu_id[0] == '*')
			begin();
		cout << "请输入学生个人密码（输入'*'返回上一级）：";
		cin >> stu_password;
		if (stu_password[0] == '*')
			begin();
		strcpy(filename2, stu_id);
		int fn_it = 0;
		while (filename2[fn_it] != '\0')
			fn_it++;
		filename2[fn_it] = '.';
		filename2[fn_it + 1] = 't';
		filename2[fn_it + 2] = 'x';
		filename2[fn_it + 3] = 't';
		filename2[fn_it + 4] = '\0';
		if (!format_check(stu_id, stu_password))
			student_register();
		else if (duplicat_check(stu_id))//函数中需输出用户名是否重复
		{
			FILE* fp = fopen(filename2, "w");
			if (fp == NULL)
			{
				cout << stu_id << ".txt文件创建失败！注册失败！" << endl << endl;
				begin();
			}
			fclose(fp);
			Student* p = new Student;
			cout << endl << "（若不设置密保问题，则ID被锁定时需先在“密保功能”中设置密保后才能找回密码！）" << endl;
			cout << "是否设置用于找回密码的密保问题（1、是  2、否）：";
			int choice = 0;
			cin >> choice;
			while (1)
			{
				if (choice >= 1 && choice <= 2)
					break;
				else
				{
					cout << "您输入的操作序号不正确，请重新输入！" << endl << endl;
					cout << "是否设置用于找回密码的密保问题（1、是  2、否）：";
					cin >> choice;
				}
			}
			if (choice == 1)
			{
				cout << "请输入您想设置的密保问题（不超过50个字符）：";
				cin >> p->question;
				cout << "请输入密保问题的答案（不超过50个字符）：";
				cin >> p->answer;
				cout << "密保设置成功！" << endl;
			}
			else
			{
				strcpy(p->question, "NULL");
				strcpy(p->answer, "NULL");
			}
			strcpy(p->id, stu_id);
			strcpy(p->password, stu_password);
			p->assistant_course_amount = 0;
			p->course_amount = 0;
			p->assistant_delete_flag = 0;
			p->wrong_times = 0;
			p->next = NULL;
			if (!stuhead)
				stuhead = p;
			else
				stutail->next = p;
			stutail = p;
			register_account();
			cout << endl;
			FILE* fp1 = fopen("./currentcourse.txt", "r");
			if (fp1 == NULL)
			{
				cout << "注册成功！" << endl;
				cout << "当前管理员尚未录入课程！无法登录学生端！" << endl;
				for (int i = 0; i < 120; i++)
					cout << '*';
				cout << endl << endl;
				begin();
			}
			else
			{
				fclose(fp1);
				for (int i = 0; i < 92; i++)
				{
					if (i == 46)
						cout << " 注册成功！并成功登录学生端！";
					else
						cout << '*';
				}
				cout << endl << endl;
				break;
			}
		}
		else
			begin();
	}
}
void administrator_login()
{
	while (1)
	{
		cout << "请输入管理员ID（输入'*'返回上一级）：";
		cin >> admin_id;
		if (admin_id[0] == '*')
			begin();
		cout << "请输入管理员密码（输入'*'返回上一级）：";
		int i = 0;
		char ch;
		while ((ch = _getch()) != '\r')
		{
			if (ch == '\b' && i > 0)
			{
				printf("\b \b");
				--i;
			}
			else if (ch != '\b')
			{
				admin_password[i] = ch;
				i++;
				printf("*");
			}
		}
		admin_password[i] = '\0';
		cout << endl;
		if (admin_password[0] == '*')
			begin();
		if (strcmp(admin_id, my_id))
			cout << "管理员ID输入错误！请重新输入！" << endl;
		else if (strcmp(admin_password, my_password))
		{
			if (admin_wrong_times == 5)
			{
				cout << "该ID已被锁定！请找回密码后登录！" << endl << endl;
				begin();
			}
			admin_wrong_times++;
			if (admin_wrong_times == 5)
			{
				cout << "密码输入错误5次！该ID已被锁定！请找回密码后登录！" << endl << endl;
				begin();
			}
			cout << "密码输入错误！密码输入错误5次将锁定该ID！" << "您还可以输入" << 5 - admin_wrong_times << "次！" << endl;
			cout << "请重新输入！" << endl;
		}
		else
			break;
	}
	if (admin_wrong_times == 5)
	{
		cout << "该ID以被锁定！请找回密码后登录！" << endl << endl;
		begin();
	}
	admin_wrong_times = 0;
	if(!strcmp(my_question,"NULL"))
	{
		cout << endl << "（若不设置密保问题，则ID被锁定时需先在“密保功能”中设置密保后才能找回密码！）" << endl;
		cout << "是否设置用于找回密码的密保问题（1、是  2、否  3、返回上一级）：";
		int choice = 0;
		cin >> choice;
		while (1)
		{
			if (choice >= 1 && choice <= 3)
				break;
			else
			{
				cout << "您输入的操作序号不正确，请重新输入！" << endl << endl;
				cout << "是否设置用于找回密码的密保问题（1、是  2、否  3、返回上一级）：";
				cin >> choice;
			}
		}
		if (choice == 1)
		{
			cout << "请输入您想设置的密保问题（不超过50个字符）（输入'*'返回上一级）：";
			cin >> my_question;
			if (my_question[0] == '*')
			{
				strcpy(my_question, "NULL");
				begin();
			}
			cout << "请输入密保问题的答案（不超过50个字符）（输入'*'返回上一级）：";
			cin >> my_answer;
			if (my_answer[0] == '*')
			{
				strcpy(my_question, "NULL");
				strcpy(my_answer, "NULL");
				begin();
			}
			cout << "密保设置成功！" << endl;
		}
		if (choice == 3)
			begin();
	}
	cout << endl;
	for (int i = 0; i < 102; i++)
	{
		if (i == 51)
			cout << " 成功登录管理员端！";
		else
			cout << '*';
	}
	cout << endl << endl;
}
void password_change()
{
	cout << "请输入您想修改密码的身份（1、学生 2、管理员 3、返回主界面）：";
	int choice = 0;
	cin >> choice;
	while (1)
	{
		if (choice >= 1 && choice <= 3)
			break;
		else
		{
			cout << "您输入的操作序号不正确，请重新输入！" << endl << endl;
			cout << "请输入您想修改密码的身份（1、学生 2、管理员 3、返回主界面）：";
			cin >> choice;
		}
	}
	cout << endl << endl;
	switch (choice)
	{
	case 1: student_password_change(); break;
	case 2: administrator_password_change(); break;
	case 3: begin(); break;
	}
	begin();
}
void question_set_or_change()
{
	cout << "请输入您想设置/修改问题的身份（1、学生 2、管理员 3、返回主界面）：";
	int choice = 0;
	cin >> choice;
	while (1)
	{
		if (choice >= 1 && choice <= 3)
			break;
		else
		{
			cout << "您输入的操作序号不正确，请重新输入！" << endl << endl;
			cout << "请输入您想设置/修改问题的身份（1、学生 2、管理员 3、返回主页面）：";
			cin >> choice;
		}
	}
	cout << endl << endl;
	switch (choice)
	{
	case 1: student_question_set_or_change(); break;
	case 2: administrator_question_set_or_change(); break;
	case 3: begin(); break;
	}
	begin();
}
void password_retrieve()
{
	cout << "请输入您想找回密码的身份（1、学生 2、管理员 3、返回主界面）：";
	int choice = 0;
	cin >> choice;
	while (1)
	{
		if (choice >= 1 && choice <= 3)
			break;
		else
		{
			cout << "您输入的操作序号不正确，请重新输入！" << endl << endl;
			cout << "请输入您想找回密码的身份（1、学生 2、管理员 3、返回主界面）：";
			cin >> choice;
		}
	}
	cout << endl << endl;
	switch (choice)
	{
	case 1: student_password_retrieve(); break;
	case 2: administrator_password_retrieve(); break;
	case 3: begin(); break;
	}
	begin();
}
void logdown()
{
	cout << "您已退出学生选课信息系统！" << endl;
	
}

//辅助函数
bool match_account(char stu_id[], char stu_password[])
{
	FILE* fp = fopen("./student.txt", "r");
	if (fp == NULL)
	{
		printf("尚未有学生注册，请您先注册！\n");
		begin();
	}
	char id[21], password[21], question[51], answer[51];
	fscanf(fp, "%20s", id);
	if (id == NULL)
	{
		printf("尚未有学生注册，请您先注册！\n\n");
		fclose(fp);
		begin();
	}
	else
		while (!feof(fp))
		{
			fseek(fp, 3, SEEK_CUR);
			fscanf(fp, "%20s", password);
			if (!strcmp(stu_id, id) && !strcmp(stu_password, password))
			{
				fclose(fp);
				return true;
			}
			if(!strcmp(stu_id, id) && strcmp(stu_password, password))
			{
				Student* s = stuhead;
				while (strcmp(s->id, stu_id))
					s = s->next;
				s->wrong_times++;
				if(s->wrong_times>=5)
				{
					cout << "密码输入错误已满5次！该ID已被锁定！请找回密码后登录！" << endl << endl;
					begin();
				}
				cout << "密码输入错误！密码输入错误5次将锁定该ID！" << "您还可以输入" << 5 - s->wrong_times << "次！" << endl;
				cout << "请重新输入！" << endl;
				fclose(fp);
				return false;
			}
			fseek(fp, 3, SEEK_CUR);
			fscanf(fp, "%50s", question);
			fseek(fp, 3, SEEK_CUR);
			fscanf(fp, "%50s", answer);
			fscanf(fp, "%20s", id);
		}
	printf("ID输入错误！请重新输入！\n\n");
	fclose(fp);
	return false;
}
bool format_check(char stu_id[], char stu_password[])
{
	int check1 = 0, check2 = 0;
	for (int i = 0; stu_id[i] != '\0'; i++)
	{
		if(i==20)
		{
			cout << "请不要输入超过20字符的ID或密码！请重新输入！" << endl << endl;
			return false;
		}
		if (!((stu_id[i] >= 'a' && stu_id[i] <= 'z') || (stu_id[i] >= '0' && stu_id[i] <= '9')))
		{
			check1 = 1;
			break;
		}
	}
	for (int j = 0; stu_password[j] != '\0'; j++)
	{
		if (j == 20)
		{
			cout << "请不要输入超过20字符的ID或密码！请重新输入！" << endl << endl;
			return false;
		}
		if (!((stu_password[j] >= 'a' && stu_password[j] <= 'z') || (stu_password[j] >= '0' && stu_password[j] <= '9')))
		{
			check2 = 1;
			break;
		}
	}
	if(!check1&&!check2)
		return true;
	else if(check1&&!check2)
	{
		cout << "您输入的ID不符合要求！请重新输入！" << endl << endl;
		return false;
	}
	else if (!check1 && check2)
	{
		cout << "您输入的密码不符合要求！请重新输入！" << endl << endl;
		return false;
	}
	else
	{
		cout << "您输入的ID和密码均不符合要求！请重新输入！" << endl << endl;
		return false;
	}
}
bool duplicat_check(char stu_id[])
{
	FILE* fp = fopen("./student.txt", "r");
	if (fp == NULL)
	{
		fp = fopen("./student.txt", "w+");
	}
	char id[21], password[21], question[51], answer[51];
	fscanf(fp, "%20s", id);
	if (id == NULL)
	{
		fclose(fp);
		return true;
	}
	else
		while (!feof(fp))
		{
			fseek(fp, 3, SEEK_CUR);
			fscanf(fp, "%20s", password);
			if (!strcmp(stu_id, id))
			{
				cout << "该ID已存在！注册失败！" << endl << endl;
				fclose(fp);
				return false;
			}
			fseek(fp, 3, SEEK_CUR);
			fscanf(fp, "%50s", question);
			fseek(fp, 3, SEEK_CUR);
			fscanf(fp, "%50s", answer);
			fscanf(fp, "%20s", id);
		}
	fclose(fp);
	return true;
}
void register_account()
{

	FILE* fp = fopen("./student.txt", "w");
	if (fp == NULL)
	{
		printf("打开student.txt失败！\n");
		exit(-1);
	}
	Student* s = stuhead;
	while (s)
	{
		fprintf(fp, "%s %c %s %c %s %c %s", s->id, ',', s->password, ',', s->question, ',', s->answer);
		fputc('\n', fp);
		s = s->next;
	}
	fclose(fp);
}
void student_password_change()
{
	FILE* fp = fopen("./student.txt", "r");
	if (fp == NULL)
	{
		printf("尚未有学生注册，请您先注册！\n\n");
		begin();
	}
	char id[21];
	fscanf(fp, "%20s", id);
	if (id == NULL)
	{
		printf("尚未有学生注册，请您先注册！\n\n");
		fclose(fp);
		begin();
	}
	while (1)
	{
		cout << "请输入学生ID（输入'*'返回上一级）：";
		cin >> stu_id;
		if (stu_id[0] == '*')
			password_change();
		cout << "请输入学生个人密码（以确认身份）（输入'*'返回上一级）：";
		int i = 0;
		char ch;
		while ((ch = _getch()) != '\r')
		{
			if (ch == '\b' && i > 0)
			{
				printf("\b \b");
				--i;
			}
			else if (ch != '\b')
			{
				stu_password[i] = ch;
				i++;
				printf("*");
			}
		}
		stu_password[i] = '\0';
		cout << endl;
		if (stu_password[0] == '*')
			password_change();
		if (match_account(stu_id, stu_password))
			break;
	}
	cout << endl;
	char change_password[21];
	char change_password2[21];
	while (1)
	{
		cout << "（密码只能含有小写字母和数字，且不超过20个字符！）" << endl;
		cout << "请输入修改后的密码（输入'*'返回上一级）：";
		cin >> change_password;
		if (change_password[0] == '*')
			password_change();
		if (!format_check(stu_id, change_password))
			continue;
		cout << "请再次确认修改后的密码（输入'*'返回上一级）：";
		cin >> change_password2;
		if (change_password2[0] == '*')
			password_change();
		if (strcmp(change_password, change_password2))
		{
			cout << "两次输入的密码不相同！请重新输入修改后的密码！" << endl;
			continue;
		}
		else
			break;
	}
	strcpy(stu_password, change_password);
	Student* s = stuhead;
	while (strcmp(s->id, stu_id))
		s = s->next;
	strcpy(s->password, stu_password);
	register_account();
	cout << "密码修改成功！" << endl << endl;
}
void administrator_password_change()
{
	while (1)
	{
		cout << "请输入管理员ID（输入'*'返回上一级）：";
		cin >> admin_id;
		if (admin_id[0] == '*')
			password_change();
		cout << "请输入管理员密码（以确认身份）：";
		int i = 0;
		char ch;
		while ((ch = _getch()) != '\r')
		{
			if (ch == '\b' && i > 0)
			{
				printf("\b \b");
				--i;
			}
			else if (ch != '\b')
			{
				admin_password[i] = ch;
				i++;
				printf("*");
			}
		}
		admin_password[i] = '\0';
		cout << endl;
		if (admin_password[0] == '*')
			password_change();
		if (!strcmp(admin_id, my_id) && !strcmp(admin_password, my_password))
			break;
		if (strcmp(admin_id, my_id))
		{
			cout << "管理员ID输入错误！请重新输入！" << endl << endl;
			continue;
		}
		if (strcmp(admin_password, my_password))
		{
			cout << "管理员密码输入错误！请重新输入！" << endl << endl;
			continue;
		}
	}
	char change_password[21];
	char change_password2[21];
	while (1)
	{
		cout << "（密码只能含有小写字母和数字，且不超过20个字符！）" << endl;
		cout << "请输入修改后的密码（输入'*'返回上一级）：";
		cin >> change_password;
		if (change_password[0] == '*')
			password_change();
		if (!format_check(my_password, change_password))
			continue;
		cout << "请再次确认修改后的密码（输入'*'返回上一级）：";
		cin >> change_password2;
		if (change_password[0] == '*')
			password_change();
		if (strcmp(change_password, change_password2))
		{
			cout << "两次输入的密码不相同！请重新输入修改后的密码！" << endl;
			continue;
		}
		else
			break;
	}
	strcpy(my_password, change_password);
	cout << "密码修改成功！" << endl << endl;
}
void student_question_set_or_change()
{
	FILE* fp = fopen("./student.txt", "r");
	if (fp == NULL)
	{
		printf("尚未有学生注册，请您先注册！\n\n");
		begin();
	}
	char id[21];
	fscanf(fp, "%20s", id);
	if (id == NULL)
	{
		printf("尚未有学生注册，请您先注册！\n\n");
		fclose(fp);
		begin();
	}
	while (1)
	{
		cout << "请输入学生ID（输入'*'返回上一级）：";
		cin >> stu_id;
		if (stu_id[0] == '*')
			question_set_or_change();
		cout << "请输入学生个人密码（以确认身份）（输入'*'返回上一级）：";
		int i = 0;
		char ch;
		while ((ch = _getch()) != '\r')
		{
			if (ch == '\b' && i > 0)
			{
				printf("\b \b");
				--i;
			}
			else if (ch != '\b')
			{
				stu_password[i] = ch;
				i++;
				printf("*");
			}
		}
		stu_password[i] = '\0';
		cout << endl;
		if (stu_password[0] == '*')
			question_set_or_change();
		if (match_account(stu_id, stu_password))
			break;
	}
	cout << endl;
	char change_question[51];
	char change_answer[51];
	char change_answer2[51];
	while (1)
	{
		cout << "请输入设置/修改后的问题（不超过50个字符）（输入'*'返回上一级）：";
		cin >> change_question;
		if (change_question[0] == '*')
			question_set_or_change();
		cout << "请输入设置/修改后的问题答案（不超过50个字符）（输入'*'返回上一级）：";
		cin >> change_answer;
		if (change_answer[0] == '*')
			question_set_or_change();
		cout << "请再次确认设置/修改后的问题答案（输入'*'返回上一级）：";
		cin >> change_answer2;
		if (change_answer2[0] == '*')
			question_set_or_change();
		if (strcmp(change_answer, change_answer2))
		{
			cout << "两次输入的问题答案不相同！请重新输入！" << endl;
			continue;
		}
		else
			break;
	}
	Student* s = stuhead;
	while (strcmp(s->id, stu_id))
		s = s->next;
	strcpy(s->question, change_question);
	strcpy(s->answer, change_answer);
	register_account();
	cout << "问题设置/修改成功！" << endl << endl;
}
void administrator_question_set_or_change()
{
	while (1)
	{
		cout << "请输入管理员ID（输入'*'返回上一级）：";
		cin >> admin_id;
		if (admin_id[0] == '*')
			question_set_or_change();
		cout << "请输入管理员密码（以确认身份）（输入'*'返回上一级）：";
		int i = 0;
		char ch;
		while ((ch = _getch()) != '\r')
		{
			if (ch == '\b' && i > 0)
			{
				printf("\b \b");
				--i;
			}
			else if (ch != '\b')
			{
				admin_password[i] = ch;
				i++;
				printf("*");
			}
		}
		admin_password[i] = '\0';
		cout << endl;
		if (admin_password[0] == '*')
			question_set_or_change();
		if (!strcmp(admin_id, my_id) && !strcmp(admin_password, my_password))
			break;
		if (strcmp(admin_id, my_id))
		{
			cout << "管理员ID输入错误！请重新输入！" << endl << endl;
			continue;
		}
		if (strcmp(admin_password, my_password))
		{
			cout << "管理员密码输入错误！请重新输入！" << endl << endl;
			continue;
		}
	}
	cout << endl;
	char change_question[51];
	char change_answer[51];
	char change_answer2[51];
	while (1)
	{
		cout << "请输入设置/修改后的问题（不超过50个字符）（输入'*'返回上一级）：";
		cin >> change_question;
		if (change_question[0] == '*')
			question_set_or_change();
		cout << "请输入设置/修改后的问题答案（不超过50个字符）（输入'*'返回上一级）：";
		cin >> change_answer;
		if (change_answer[0] == '*')
			question_set_or_change();
		cout << "请再次确认设置/修改后的问题答案（输入'*'返回上一级）：";
		cin >> change_answer2;
		if (change_answer2[0] == '*')
			question_set_or_change();
		if (strcmp(change_answer, change_answer2))
		{
			cout << "两次输入的问题答案不相同！请重新输入！" << endl;
			continue;
		}
		else
			break;
	}
	strcpy(my_question, change_question);
	strcpy(my_answer, change_answer);
	cout << "问题设置/修改成功！" << endl << endl;
}
void student_password_retrieve()
{
	FILE* fp = fopen("./student.txt", "r");
	if (fp == NULL)
	{
		printf("尚未有学生注册，请您先注册！\n\n");
		begin();
	}
	char id[21];
	fscanf(fp, "%20s", id);
	if (id == NULL)
	{
		printf("尚未有学生注册，请您先注册！\n\n");
		fclose(fp);
		begin();
	}
	cout << "请输入您的学生ID（输入'*'返回上一级）：";
	cin >> stu_id;
	if (stu_id[0] == '*')
		password_retrieve();
	Student* s = stuhead;
	while (strcmp(s->id, stu_id))
	{
		s = s->next;
		if(!s)
		{
			cout << "您输入的学生ID不存在！密码找回失败！" << endl << endl;
			begin();
		}
	}
	if(!strcmp(s->question,"NULL"))
	{
		cout << "您未设置问题！无法找回密码！" << endl << endl;
		begin();
	}
	cout << "请回答问题：" << s->question << endl;
	cout << "请输入答案（输入'*'返回上一级）：";
	char answer[51];
	cin >> answer;
	if (answer[0] == '*')
		password_retrieve();
	if(strcmp(s->answer,answer))
	{
		cout << "您输入的答案不正确！密码找回失败！" << endl << endl;
		begin();
	}
	cout << "密码找回成功！您的密码是：" << s->password << endl << endl;
	s->wrong_times = 0;
	cout << "是否需要修改密码（1、是  2、否）：";
	int choice = 0;
	cin >> choice;
	while (1)
	{
		if (choice == 1 || choice == 2)
			break;
		else
		{
			cout << "您输入的操作序号不正确，请重新输入！" << endl << endl;
			cout << "是否需要修改密码（1、是  2、否）：";
			cin >> choice;
		}
	}
	if(choice==1)
	{
		char change_password[21];
		char change_password2[21];
		while (1)
		{
			cout << "（密码只能含有小写字母和数字，且不超过20个字符！）" << endl;
			cout << "请输入修改后的密码（输入'*'返回上一级）：";
			cin >> change_password;
			if (change_password[0] == '*')
				password_retrieve();
			if (!format_check(stu_id, change_password))
				continue;
			cout << "请再次确认修改后的密码（输入'*'返回上一级）：";
			cin >> change_password2;
			if (change_password2[0] == '*')
				password_retrieve();
			if (strcmp(change_password, change_password2))
			{
				cout << "两次输入的密码不相同！请重新输入修改后的密码！" << endl;
				continue;
			}
			else
				break;
		}
		strcpy(stu_password, change_password);
		strcpy(s->password, stu_password);
		register_account();
		cout << "密码修改成功！" << endl << endl;
	}
}
void administrator_password_retrieve()
{
	cout << "请输入您的管理员ID（输入'*'返回上一级）：";
	cin >> admin_id;
	if (admin_id[0] == '*')
		password_retrieve();
	if(strcmp(my_id,admin_id))
	{
		cout << "您输入的管理员ID不正确！密码找回失败！" << endl << endl;
		begin();
	}
	if(!strcmp(my_question,"NULL"))
	{
		cout << "您未设置问题！无法找回密码！" << endl << endl;
		begin();
	}
	cout << "请回答问题：" << my_question << endl;
	cout << "请输入答案（输入'*'返回上一级）：";
	char answer[51];
	cin >> answer;
	if (answer[0] == '*')
		password_retrieve();
	if (strcmp(my_answer,answer))
	{
		cout << "您输入的答案不正确！密码找回失败！" << endl << endl;
		begin();
	}
	cout << "密码找回成功！您的密码是：" << my_password << endl << endl;
	admin_wrong_times = 0;
	cout << "是否需要修改密码（1、是  2、否）：";
	int choice = 0;
	cin >> choice;
	while (1)
	{
		if (choice == 1 || choice == 2)
			break;
		else
		{
			cout << "您输入的操作序号不正确，请重新输入！" << endl << endl;
			cout << "是否需要修改密码（1、是  2、否）：";
			cin >> choice;
		}
	}
	if (choice == 1)
	{
		char change_password[21];
		char change_password2[21];
		while (1)
		{
			cout << "（密码只能含有小写字母和数字，且不超过20个字符！）" << endl;
			cout << "请输入修改后的密码（输入'*'返回上一级）：";
			cin >> change_password;
			if (change_password[0] == '*')
				password_retrieve();
			if (!format_check(my_password, change_password))
				continue;
			cout << "请再次确认修改后的密码（输入'*'返回上一级）：";
			cin >> change_password2;
			if (change_password2[0] == '*')
				password_retrieve();
			if (strcmp(change_password, change_password2))
			{
				cout << "两次输入的密码不相同！请重新输入修改后的密码！" << endl;
				continue;
			}
			else
				break;
		}
		strcpy(my_password, stu_password);
		cout << "密码修改成功！" << endl << endl;
	}
}