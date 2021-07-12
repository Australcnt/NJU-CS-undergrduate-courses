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

//���ܺ���
void welcome()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			if (i == 7 && j == 6)
				cout << "   ѧ��ѡ��";
			else if (i == 7 && j == 7)
				cout << "��Ϣ����";
			else if (i == 7 && j == 8)
				cout << "ϵͳ     ";
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
			cout << " ��ӭ����ѧ��ѡ����Ϣ����ϵͳ��";
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
			cout << setw(10) << "1��ѧ����¼";
		else if (i == 9)
			cout << setw(10) << "2��ѧ��ע��";
		else if (i == 16)
			cout << setw(10) << "3������Ա��¼";
		else if (i == 23)
			cout << setw(10) << "4���޸�����";
		else if (i == 30)
			cout << setw(10) << "5���ܱ�����";
		else if (i == 37)
			cout << setw(10) << "6���һ�����";
		else if (i == 44)
			cout << setw(10) << "7���˳�ϵͳ";
		else
			cout << ' ';
	}
	cout << endl;
	for (int i = 0; i < 120; i++)
		cout << '=';
	cout << endl << endl << endl;
	int choice;
	cout << "�����������ţ�";
	cin >> choice;
	while (1)
	{
		if (choice > 0 && choice < 8)
			break;
		else
		{
			cout << "������Ĳ�����Ų���ȷ�����������룡" << endl << endl;
			cout << "�����������ţ�";
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
		cout << "������ѧ��ID������'*'������һ������";
		cin >> stu_id;
		if (stu_id[0] == '*')
			begin();
		cout << "������ѧ���������루����'*'������һ������";
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
		if (match_account(stu_id, stu_password))//�������������ƥ���ԭ��
			break;
	}
	cout << endl;
	Student* s = stuhead;
	while (strcmp(s->id, stu_id))
		s = s->next;
	if (s->wrong_times == 5)
	{
		cout << "��ID�ѱ����������һ�������¼��" << endl << endl;
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
		cout << "��ǰ����Ա��δ¼��γ̣��޷���¼ѧ���ˣ�" << endl;
		for (int i = 0; i < 120; i++)
			cout << '*';
		cout << endl;
		begin();
	}
	fclose(fp);
	for (int i = 0; i < 104; i++)
	{
		if (i == 52)
			cout << " �ɹ���¼ѧ���ˣ�";
		else
			cout << '*';
	}
	cout << endl << endl;
}
void student_register()
{
	while (1)
	{
		cout << "��ID������ֻ�ܺ���Сд��ĸ�����֣��Ҳ�����20���ַ�����" << endl;
		cout << "������ѧ��ID������'*'������һ������";
		cin >> stu_id;
		if (stu_id[0] == '*')
			begin();
		cout << "������ѧ���������루����'*'������һ������";
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
		else if (duplicat_check(stu_id))//������������û����Ƿ��ظ�
		{
			FILE* fp = fopen(filename2, "w");
			if (fp == NULL)
			{
				cout << stu_id << ".txt�ļ�����ʧ�ܣ�ע��ʧ�ܣ�" << endl << endl;
				begin();
			}
			fclose(fp);
			Student* p = new Student;
			cout << endl << "�����������ܱ����⣬��ID������ʱ�����ڡ��ܱ����ܡ��������ܱ�������һ����룡��" << endl;
			cout << "�Ƿ����������һ�������ܱ����⣨1����  2���񣩣�";
			int choice = 0;
			cin >> choice;
			while (1)
			{
				if (choice >= 1 && choice <= 2)
					break;
				else
				{
					cout << "������Ĳ�����Ų���ȷ�����������룡" << endl << endl;
					cout << "�Ƿ����������һ�������ܱ����⣨1����  2���񣩣�";
					cin >> choice;
				}
			}
			if (choice == 1)
			{
				cout << "�������������õ��ܱ����⣨������50���ַ�����";
				cin >> p->question;
				cout << "�������ܱ�����Ĵ𰸣�������50���ַ�����";
				cin >> p->answer;
				cout << "�ܱ����óɹ���" << endl;
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
				cout << "ע��ɹ���" << endl;
				cout << "��ǰ����Ա��δ¼��γ̣��޷���¼ѧ���ˣ�" << endl;
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
						cout << " ע��ɹ������ɹ���¼ѧ���ˣ�";
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
		cout << "���������ԱID������'*'������һ������";
		cin >> admin_id;
		if (admin_id[0] == '*')
			begin();
		cout << "���������Ա���루����'*'������һ������";
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
			cout << "����ԱID����������������룡" << endl;
		else if (strcmp(admin_password, my_password))
		{
			if (admin_wrong_times == 5)
			{
				cout << "��ID�ѱ����������һ�������¼��" << endl << endl;
				begin();
			}
			admin_wrong_times++;
			if (admin_wrong_times == 5)
			{
				cout << "�����������5�Σ���ID�ѱ����������һ�������¼��" << endl << endl;
				begin();
			}
			cout << "����������������������5�ν�������ID��" << "������������" << 5 - admin_wrong_times << "�Σ�" << endl;
			cout << "���������룡" << endl;
		}
		else
			break;
	}
	if (admin_wrong_times == 5)
	{
		cout << "��ID�Ա����������һ�������¼��" << endl << endl;
		begin();
	}
	admin_wrong_times = 0;
	if(!strcmp(my_question,"NULL"))
	{
		cout << endl << "�����������ܱ����⣬��ID������ʱ�����ڡ��ܱ����ܡ��������ܱ�������һ����룡��" << endl;
		cout << "�Ƿ����������һ�������ܱ����⣨1����  2����  3��������һ������";
		int choice = 0;
		cin >> choice;
		while (1)
		{
			if (choice >= 1 && choice <= 3)
				break;
			else
			{
				cout << "������Ĳ�����Ų���ȷ�����������룡" << endl << endl;
				cout << "�Ƿ����������һ�������ܱ����⣨1����  2����  3��������һ������";
				cin >> choice;
			}
		}
		if (choice == 1)
		{
			cout << "�������������õ��ܱ����⣨������50���ַ���������'*'������һ������";
			cin >> my_question;
			if (my_question[0] == '*')
			{
				strcpy(my_question, "NULL");
				begin();
			}
			cout << "�������ܱ�����Ĵ𰸣�������50���ַ���������'*'������һ������";
			cin >> my_answer;
			if (my_answer[0] == '*')
			{
				strcpy(my_question, "NULL");
				strcpy(my_answer, "NULL");
				begin();
			}
			cout << "�ܱ����óɹ���" << endl;
		}
		if (choice == 3)
			begin();
	}
	cout << endl;
	for (int i = 0; i < 102; i++)
	{
		if (i == 51)
			cout << " �ɹ���¼����Ա�ˣ�";
		else
			cout << '*';
	}
	cout << endl << endl;
}
void password_change()
{
	cout << "�����������޸��������ݣ�1��ѧ�� 2������Ա 3�����������棩��";
	int choice = 0;
	cin >> choice;
	while (1)
	{
		if (choice >= 1 && choice <= 3)
			break;
		else
		{
			cout << "������Ĳ�����Ų���ȷ�����������룡" << endl << endl;
			cout << "�����������޸��������ݣ�1��ѧ�� 2������Ա 3�����������棩��";
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
	cout << "��������������/�޸��������ݣ�1��ѧ�� 2������Ա 3�����������棩��";
	int choice = 0;
	cin >> choice;
	while (1)
	{
		if (choice >= 1 && choice <= 3)
			break;
		else
		{
			cout << "������Ĳ�����Ų���ȷ�����������룡" << endl << endl;
			cout << "��������������/�޸��������ݣ�1��ѧ�� 2������Ա 3��������ҳ�棩��";
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
	cout << "�����������һ��������ݣ�1��ѧ�� 2������Ա 3�����������棩��";
	int choice = 0;
	cin >> choice;
	while (1)
	{
		if (choice >= 1 && choice <= 3)
			break;
		else
		{
			cout << "������Ĳ�����Ų���ȷ�����������룡" << endl << endl;
			cout << "�����������һ��������ݣ�1��ѧ�� 2������Ա 3�����������棩��";
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
	cout << "�����˳�ѧ��ѡ����Ϣϵͳ��" << endl;
	
}

//��������
bool match_account(char stu_id[], char stu_password[])
{
	FILE* fp = fopen("./student.txt", "r");
	if (fp == NULL)
	{
		printf("��δ��ѧ��ע�ᣬ������ע�ᣡ\n");
		begin();
	}
	char id[21], password[21], question[51], answer[51];
	fscanf(fp, "%20s", id);
	if (id == NULL)
	{
		printf("��δ��ѧ��ע�ᣬ������ע�ᣡ\n\n");
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
					cout << "���������������5�Σ���ID�ѱ����������һ�������¼��" << endl << endl;
					begin();
				}
				cout << "����������������������5�ν�������ID��" << "������������" << 5 - s->wrong_times << "�Σ�" << endl;
				cout << "���������룡" << endl;
				fclose(fp);
				return false;
			}
			fseek(fp, 3, SEEK_CUR);
			fscanf(fp, "%50s", question);
			fseek(fp, 3, SEEK_CUR);
			fscanf(fp, "%50s", answer);
			fscanf(fp, "%20s", id);
		}
	printf("ID����������������룡\n\n");
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
			cout << "�벻Ҫ���볬��20�ַ���ID�����룡���������룡" << endl << endl;
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
			cout << "�벻Ҫ���볬��20�ַ���ID�����룡���������룡" << endl << endl;
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
		cout << "�������ID������Ҫ�����������룡" << endl << endl;
		return false;
	}
	else if (!check1 && check2)
	{
		cout << "����������벻����Ҫ�����������룡" << endl << endl;
		return false;
	}
	else
	{
		cout << "�������ID�������������Ҫ�����������룡" << endl << endl;
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
				cout << "��ID�Ѵ��ڣ�ע��ʧ�ܣ�" << endl << endl;
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
		printf("��student.txtʧ�ܣ�\n");
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
		printf("��δ��ѧ��ע�ᣬ������ע�ᣡ\n\n");
		begin();
	}
	char id[21];
	fscanf(fp, "%20s", id);
	if (id == NULL)
	{
		printf("��δ��ѧ��ע�ᣬ������ע�ᣡ\n\n");
		fclose(fp);
		begin();
	}
	while (1)
	{
		cout << "������ѧ��ID������'*'������һ������";
		cin >> stu_id;
		if (stu_id[0] == '*')
			password_change();
		cout << "������ѧ���������루��ȷ����ݣ�������'*'������һ������";
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
		cout << "������ֻ�ܺ���Сд��ĸ�����֣��Ҳ�����20���ַ�����" << endl;
		cout << "�������޸ĺ�����루����'*'������һ������";
		cin >> change_password;
		if (change_password[0] == '*')
			password_change();
		if (!format_check(stu_id, change_password))
			continue;
		cout << "���ٴ�ȷ���޸ĺ�����루����'*'������һ������";
		cin >> change_password2;
		if (change_password2[0] == '*')
			password_change();
		if (strcmp(change_password, change_password2))
		{
			cout << "������������벻��ͬ�������������޸ĺ�����룡" << endl;
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
	cout << "�����޸ĳɹ���" << endl << endl;
}
void administrator_password_change()
{
	while (1)
	{
		cout << "���������ԱID������'*'������һ������";
		cin >> admin_id;
		if (admin_id[0] == '*')
			password_change();
		cout << "���������Ա���루��ȷ����ݣ���";
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
			cout << "����ԱID����������������룡" << endl << endl;
			continue;
		}
		if (strcmp(admin_password, my_password))
		{
			cout << "����Ա��������������������룡" << endl << endl;
			continue;
		}
	}
	char change_password[21];
	char change_password2[21];
	while (1)
	{
		cout << "������ֻ�ܺ���Сд��ĸ�����֣��Ҳ�����20���ַ�����" << endl;
		cout << "�������޸ĺ�����루����'*'������һ������";
		cin >> change_password;
		if (change_password[0] == '*')
			password_change();
		if (!format_check(my_password, change_password))
			continue;
		cout << "���ٴ�ȷ���޸ĺ�����루����'*'������һ������";
		cin >> change_password2;
		if (change_password[0] == '*')
			password_change();
		if (strcmp(change_password, change_password2))
		{
			cout << "������������벻��ͬ�������������޸ĺ�����룡" << endl;
			continue;
		}
		else
			break;
	}
	strcpy(my_password, change_password);
	cout << "�����޸ĳɹ���" << endl << endl;
}
void student_question_set_or_change()
{
	FILE* fp = fopen("./student.txt", "r");
	if (fp == NULL)
	{
		printf("��δ��ѧ��ע�ᣬ������ע�ᣡ\n\n");
		begin();
	}
	char id[21];
	fscanf(fp, "%20s", id);
	if (id == NULL)
	{
		printf("��δ��ѧ��ע�ᣬ������ע�ᣡ\n\n");
		fclose(fp);
		begin();
	}
	while (1)
	{
		cout << "������ѧ��ID������'*'������һ������";
		cin >> stu_id;
		if (stu_id[0] == '*')
			question_set_or_change();
		cout << "������ѧ���������루��ȷ����ݣ�������'*'������һ������";
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
		cout << "����������/�޸ĺ�����⣨������50���ַ���������'*'������һ������";
		cin >> change_question;
		if (change_question[0] == '*')
			question_set_or_change();
		cout << "����������/�޸ĺ������𰸣�������50���ַ���������'*'������һ������";
		cin >> change_answer;
		if (change_answer[0] == '*')
			question_set_or_change();
		cout << "���ٴ�ȷ������/�޸ĺ������𰸣�����'*'������һ������";
		cin >> change_answer2;
		if (change_answer2[0] == '*')
			question_set_or_change();
		if (strcmp(change_answer, change_answer2))
		{
			cout << "�������������𰸲���ͬ�����������룡" << endl;
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
	cout << "��������/�޸ĳɹ���" << endl << endl;
}
void administrator_question_set_or_change()
{
	while (1)
	{
		cout << "���������ԱID������'*'������һ������";
		cin >> admin_id;
		if (admin_id[0] == '*')
			question_set_or_change();
		cout << "���������Ա���루��ȷ����ݣ�������'*'������һ������";
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
			cout << "����ԱID����������������룡" << endl << endl;
			continue;
		}
		if (strcmp(admin_password, my_password))
		{
			cout << "����Ա��������������������룡" << endl << endl;
			continue;
		}
	}
	cout << endl;
	char change_question[51];
	char change_answer[51];
	char change_answer2[51];
	while (1)
	{
		cout << "����������/�޸ĺ�����⣨������50���ַ���������'*'������һ������";
		cin >> change_question;
		if (change_question[0] == '*')
			question_set_or_change();
		cout << "����������/�޸ĺ������𰸣�������50���ַ���������'*'������һ������";
		cin >> change_answer;
		if (change_answer[0] == '*')
			question_set_or_change();
		cout << "���ٴ�ȷ������/�޸ĺ������𰸣�����'*'������һ������";
		cin >> change_answer2;
		if (change_answer2[0] == '*')
			question_set_or_change();
		if (strcmp(change_answer, change_answer2))
		{
			cout << "�������������𰸲���ͬ�����������룡" << endl;
			continue;
		}
		else
			break;
	}
	strcpy(my_question, change_question);
	strcpy(my_answer, change_answer);
	cout << "��������/�޸ĳɹ���" << endl << endl;
}
void student_password_retrieve()
{
	FILE* fp = fopen("./student.txt", "r");
	if (fp == NULL)
	{
		printf("��δ��ѧ��ע�ᣬ������ע�ᣡ\n\n");
		begin();
	}
	char id[21];
	fscanf(fp, "%20s", id);
	if (id == NULL)
	{
		printf("��δ��ѧ��ע�ᣬ������ע�ᣡ\n\n");
		fclose(fp);
		begin();
	}
	cout << "����������ѧ��ID������'*'������һ������";
	cin >> stu_id;
	if (stu_id[0] == '*')
		password_retrieve();
	Student* s = stuhead;
	while (strcmp(s->id, stu_id))
	{
		s = s->next;
		if(!s)
		{
			cout << "�������ѧ��ID�����ڣ������һ�ʧ�ܣ�" << endl << endl;
			begin();
		}
	}
	if(!strcmp(s->question,"NULL"))
	{
		cout << "��δ�������⣡�޷��һ����룡" << endl << endl;
		begin();
	}
	cout << "��ش����⣺" << s->question << endl;
	cout << "������𰸣�����'*'������һ������";
	char answer[51];
	cin >> answer;
	if (answer[0] == '*')
		password_retrieve();
	if(strcmp(s->answer,answer))
	{
		cout << "������Ĵ𰸲���ȷ�������һ�ʧ�ܣ�" << endl << endl;
		begin();
	}
	cout << "�����һسɹ������������ǣ�" << s->password << endl << endl;
	s->wrong_times = 0;
	cout << "�Ƿ���Ҫ�޸����루1����  2���񣩣�";
	int choice = 0;
	cin >> choice;
	while (1)
	{
		if (choice == 1 || choice == 2)
			break;
		else
		{
			cout << "������Ĳ�����Ų���ȷ�����������룡" << endl << endl;
			cout << "�Ƿ���Ҫ�޸����루1����  2���񣩣�";
			cin >> choice;
		}
	}
	if(choice==1)
	{
		char change_password[21];
		char change_password2[21];
		while (1)
		{
			cout << "������ֻ�ܺ���Сд��ĸ�����֣��Ҳ�����20���ַ�����" << endl;
			cout << "�������޸ĺ�����루����'*'������һ������";
			cin >> change_password;
			if (change_password[0] == '*')
				password_retrieve();
			if (!format_check(stu_id, change_password))
				continue;
			cout << "���ٴ�ȷ���޸ĺ�����루����'*'������һ������";
			cin >> change_password2;
			if (change_password2[0] == '*')
				password_retrieve();
			if (strcmp(change_password, change_password2))
			{
				cout << "������������벻��ͬ�������������޸ĺ�����룡" << endl;
				continue;
			}
			else
				break;
		}
		strcpy(stu_password, change_password);
		strcpy(s->password, stu_password);
		register_account();
		cout << "�����޸ĳɹ���" << endl << endl;
	}
}
void administrator_password_retrieve()
{
	cout << "���������Ĺ���ԱID������'*'������һ������";
	cin >> admin_id;
	if (admin_id[0] == '*')
		password_retrieve();
	if(strcmp(my_id,admin_id))
	{
		cout << "������Ĺ���ԱID����ȷ�������һ�ʧ�ܣ�" << endl << endl;
		begin();
	}
	if(!strcmp(my_question,"NULL"))
	{
		cout << "��δ�������⣡�޷��һ����룡" << endl << endl;
		begin();
	}
	cout << "��ش����⣺" << my_question << endl;
	cout << "������𰸣�����'*'������һ������";
	char answer[51];
	cin >> answer;
	if (answer[0] == '*')
		password_retrieve();
	if (strcmp(my_answer,answer))
	{
		cout << "������Ĵ𰸲���ȷ�������һ�ʧ�ܣ�" << endl << endl;
		begin();
	}
	cout << "�����һسɹ������������ǣ�" << my_password << endl << endl;
	admin_wrong_times = 0;
	cout << "�Ƿ���Ҫ�޸����루1����  2���񣩣�";
	int choice = 0;
	cin >> choice;
	while (1)
	{
		if (choice == 1 || choice == 2)
			break;
		else
		{
			cout << "������Ĳ�����Ų���ȷ�����������룡" << endl << endl;
			cout << "�Ƿ���Ҫ�޸����루1����  2���񣩣�";
			cin >> choice;
		}
	}
	if (choice == 1)
	{
		char change_password[21];
		char change_password2[21];
		while (1)
		{
			cout << "������ֻ�ܺ���Сд��ĸ�����֣��Ҳ�����20���ַ�����" << endl;
			cout << "�������޸ĺ�����루����'*'������һ������";
			cin >> change_password;
			if (change_password[0] == '*')
				password_retrieve();
			if (!format_check(my_password, change_password))
				continue;
			cout << "���ٴ�ȷ���޸ĺ�����루����'*'������һ������";
			cin >> change_password2;
			if (change_password2[0] == '*')
				password_retrieve();
			if (strcmp(change_password, change_password2))
			{
				cout << "������������벻��ͬ�������������޸ĺ�����룡" << endl;
				continue;
			}
			else
				break;
		}
		strcpy(my_password, stu_password);
		cout << "�����޸ĳɹ���" << endl << endl;
	}
}