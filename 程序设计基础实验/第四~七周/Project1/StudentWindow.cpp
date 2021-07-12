#include "Login.h"
#include "AdministratorWindow.h"
#include "StudentWindow.h"

//���ܺ���
void student_window()
{
	for (int i = 0; i < 120; i++)
		cout << '=';
	cout << endl;
	for (int i = 0; i < 22; i++)
	{
		if (i == 0)
			cout << setw(10) << "1���鿴�γ���Ϣ";
		else if (i == 3)
			cout << setw(10) << "2��ѡ��γ�";
		else if (i == 6)
			cout << setw(10) << "3���鿴���˿α�";
		else if (i == 9)
			cout << setw(10) << "4���˳��γ�";
		else if (i == 12)
			cout << setw(10) << "5�����̱���/����";
		else if (i == 15)
			cout << setw(10) << "6���ҵĸ�������";
		else if (i == 18)
			cout << setw(10) << "7���鿴�ܱ�";
		else if (i == 21)
			cout << setw(10) << "8��ע����¼";
		else
			cout << ' ';
	}
	cout << endl;
	for (int i = 0; i < 120; i++)
		cout << '=';
	cout << endl << endl << endl;
	assistant_drop_check();
	int choice;
	cout << "�����������ţ�";
	cin >> choice;
	while (1)
	{
		if (choice > 0 && choice < 9)
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
	cout << left << setw(12) << "�γ̱��";
	cout << left << setw(30) << "�γ�����";
	cout << left << setw(20) << "�ڿ���ʦ";
	cout << left << setw(10) << "��������";
	cout << left << setw(10) << "��ѡ����";
	cout << left << setw(10) << "�γ�����";
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
	cout << left << setw(12) << "�γ̱��";
	cout << left << setw(30) << "�γ�����";
	cout << left << setw(20) << "�ڿ���ʦ";
	cout << left << setw(10) << "��������";
	cout << left << setw(10) << "��ѡ����";
	cout << left << setw(10) << "�γ�����";
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
	cout << "����ѡ����ſγ̣��γ�֮���ÿո�ָ�������" << endl;
	cout << "��������Ҫѡ��Ŀγ̱�ţ�����'*'������һ����������Ŀγ̻��������룩��";
	char id[4];
	char ch;
	while(1)
	{
		cin >> id;
		if (id[0] == '*')
		{
			cout << endl << "�γ�ѡ��ɹ�������������˿α�������ʾѡ��ʧ�ܵĿγ̣�" << endl << endl;
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
			cout << "�����ڿγ̱��Ϊ" << id << "�Ŀγ̣��ÿγ�ѡ��ʧ�ܣ�" << endl;
			if (ch = getchar() != ' ')
				break;
			continue;
		}
		if(p2->amount>=p2->capacity)
		{
			cout << id << " " << p2->name << " �γ������������ÿγ�ѡ��ʧ�ܣ�" << endl;
			if (ch = getchar() != ' ')
				break;
			continue;
		}
		Student* s = stuhead;
		while (strcmp(s->id, stu_id))
			s = s->next;
		if(!student_course_duplicatcheck(id, s))
		{
			cout << "��ѡ��" << id << "�γ̣��ÿγ�ѡ��ʧ�ܣ�" << endl;
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
	cout << endl << "�γ�ѡ��ɹ�������������˿α�������ʾѡ��ʧ�ܵĿγ̣�" << endl << endl;
	student_window();
}
void student_course_view()
{
	cout << "��ǰ��ѡ��Ŀγ����£�" << endl << endl;
	for (int i = 0; i < 100; i++)
		cout << '*';
	cout << endl << endl;
	cout << left << setw(12) << "�γ̱��";
	cout << left << setw(30) << "�γ�����";
	cout << left << setw(20) << "�ڿ���ʦ";
	cout << left << setw(20) << "�γ�����";
	cout << left << setw(20) << "��������";
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
		if (!strcmp(p->type, "רҵ��"))
			type1++;
		if (!strcmp(p->type, "��רҵ��"))
			type2++;
		cout << left << setw(20) << s->course_assistant[i];
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 100; i++)
		cout << '*';
	cout << endl << endl;
	cout << "����ѧԺҪ��������Ҫѡ��4��רҵ�κ�2�ŷ�רҵ�Σ�";
	if (type1 >= 4 && type2 >= 2)
		cout << "����ѡ���ѷ���Ҫ��" << endl << endl;
	else if (type1 >= 4 && type2 < 2)
		cout << "�����ٻ���ѡ��" << 2 - type2 << "�ŷ�רҵ�Σ�" << endl << endl;
	else if (type1 < 4 && type2 >= 2)
		cout << "�����ٻ���ѡ��" << 4 - type1 << "��רҵ�Σ�" << endl << endl;
	else
		cout << "�����ٻ���ѡ��" << 4 - type1 << "��רҵ�κ�" << 2 - type2 << "�ŷ�רҵ�Σ�" << endl << endl;
	student_window();
}
void student_course_drop()
{
	cout << "��ѡ����Ҫ�˳��Ŀγ̱�ţ�����'*'������һ������";
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
			cout << "������Ŀγ̲����ڣ�" << endl << endl;
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
			cout << "����δѡ����ſγ̣��γ��˳�ʧ�ܣ�" << endl << endl;
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
	cout << "���˳��γ� " << id << ' ' << p->name << "��" << endl << endl;
	student_course_view();
	student_window();
}
void assistant_apply_or_drop()
{
	cout << "��������ѡ��Ĳ�����1�����̱��� 2�����̳��� 3��������һ������";
	int choice = 0;
	cin >> choice;
	while (1)
	{
		if (choice >= 1 && choice <= 3)
			break;
		else
		{
			cout << "������Ĳ�����Ų���ȷ�����������룡" << endl << endl;
			cout << "��������ѡ��Ĳ�����1�����̱��� 2�����̳��� 3��������һ������";
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
	
	cout << "��������ѡ��Ĳ�����1��ѡ������ 2���������� 3��ȡ������ 4��������һ������";
	int choice = 0;
	cin >> choice;
	while (1)
	{
		if (choice >= 1 || choice <= 4)
			break;
		else
		{
			cout << "������Ĳ�����Ų���ȷ�����������룡" << endl << endl;
			cout << "��������ѡ��Ĳ�����1��ѡ������ 2���������� 3��ȡ������ 4��������һ������";
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
		cout << "����δ�����ܱ����⣡" << endl << endl;
	else
	{
		cout << "�ܱ����⣺" << s->question << endl;
		cout << "�ܱ��𰸣�" << s->answer << endl << endl;
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

		if (!strcmp(p->type, "רҵ��"))
			type1++;
		if (!strcmp(p->type, "��רҵ��"))
			type2++;
	}
	cout << "����ѧԺҪ��������Ҫѡ��4��רҵ�κ�2�ŷ�רҵ�Σ�";
	if (type1 >= 4 && type2 < 2)
		cout << "�����ٻ���ѡ��" << 2 - type2 << "�ŷ�רҵ�Σ�" << endl;
	else if (type1 < 4 && type2 >= 2)
		cout << "�����ٻ���ѡ��" << 4 - type1 << "��רҵ�Σ�" << endl;
	else
		cout << "�����ٻ���ѡ��" << 4 - type1 << "��רҵ�κ�" << 2 - type2 << "�ŷ�רҵ�Σ�" << endl;
	cout << "��ǵ��Ժ󽫿γ�ѡ����ϣ�����" << endl;
	cout << "���ѳɹ�ע��ѧ���ˣ�" << endl;
	for (int i = 0; i < 120; i++)
		cout << '*';
	cout << endl << endl;
	welcome();
	begin();
}

//��������
void assistant_drop_check()
{
	Student* s = stuhead;
	while (strcmp(s->id, stu_id))
		s = s->next;
	if(s->assistant_delete_flag)
	{
		for (int i = 0; i < s->assistant_delete_flag; i++)
		{
			cout << "��ѡ��� " << s->assistant_delete[i] << " �γ̵ĸ����������˿λ��ѳ������̣�" << endl;
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
		cout << filename2 << "�ļ���ʧ�ܣ�" << endl;
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
		cout << "currentcourse.txt��ʧ�ܣ�" << endl;
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
	cout << "��������Ҫ�������̵Ŀγ̱�ţ�����'*'������һ������";
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
			cout << "������Ŀγ̲����ڣ�" << endl << endl;
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
			cout << "����δѡ����ſγ̣����̱���ʧ�ܣ�" << endl << endl;
			student_window();
		}
	}
	for (int i = 0; i < s->assistant_course_amount; i++)
	{
		if (!strcmp(s->assistant_course[i], id))
		{
			cout << "���ѱ��������ſγ̵����̣��޷��ظ�������" << endl << endl;
			student_window();
		}
	}
	if (s->assistant_course_amount == 2)
	{
		cout << "�����ֻ�ܱ���2�ſγ̵����̣����̱���ʧ�ܣ�" << endl << endl;
		student_window();
	}
	strcpy(p->assistant[p->assistantamount], stu_id);
	p->assistantamount++;
	strcpy(s->assistant_course[s->assistant_course_amount], id);
	s->assistant_course_amount++;
	assistant_update();
	cout << "���̱����ɹ���" << endl << endl << endl;
}
void assistant_drop()
{
	cout << "��������Ҫ�������̵Ŀγ̱�ţ�����'*'������һ������";
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
			cout << "������Ŀγ̲����ڣ�" << endl << endl;
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
			cout << "����δѡ����ſγ̣����̳���ʧ�ܣ�" << endl << endl;
			student_window();
		}
	}
	if (s->assistant_course_amount == 0)
	{
		cout << "����δ�����κογ̵����̣����̳���ʧ�ܣ�" << endl << endl;
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
			cout << "��δ�������ſγ̵����̣����̳���ʧ�ܣ�" << endl << endl;
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
	cout << "���̳����ɹ���" << endl << endl << endl;
}
void assistant_choose()
{
	cout << "��������Ҫѡ�����̵Ŀγ̱�ţ�����'*'������һ������";
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
			cout << "������Ŀγ̲����ڣ�" << endl << endl;
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
			cout << "����δѡ����ſγ̣�����ѡ��ʧ�ܣ�" << endl << endl;
			student_window();
		}
	}
	if (p->assistantamount == 0)
	{
		cout << "���ſγ̵�ǰû�����̣��޷�ѡ��" << endl << endl;
		student_window();
	}
	cout << id << ' ' << p->name << " �γ̵������У�";
	for (int i = 0; i < p->assistantamount - 1; i++)
	{
		cout << p->assistant[i] << ',';
	}
	cout << p->assistant[p->assistantamount - 1] << endl << endl;
	cout << "����������������ѡ��һ����Ϊ�Լ������̣�����'*'������һ������";
	char assistant_id[20];
	cin >> assistant_id;
	if (assistant_id[0] == '*')
		assistant_choose();
	if (!strcmp(assistant_id, stu_id))
	{
		cout << "������ѡ���Լ�Ϊ�Լ������̣�����ѡ��ʧ�ܣ�" << endl << endl;
		student_window();
	}
	for (int i = 0; i < p->assistantamount; i++)
	{
		if (!strcmp(p->assistant[i], assistant_id))
			break;
		if (i == p->assistantamount - 1)
		{
			cout << "����������̲���ȷ������ѡ��ʧ�ܣ�" << endl << endl;
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
				cout << "ÿ�ſγ�����ѡ��һ�����̣�����ѡ��ʧ�ܣ�" << endl << endl;
				student_window();
			}
		}
	}
	student_course_update();
	cout << endl << "��������ѡ��ɹ���" << endl << endl;
}
void assistant_change()
{
	cout << "��������Ҫ�������̵Ŀγ̱�ţ�����'*'������һ������";
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
			cout << "������Ŀγ̲����ڣ�" << endl << endl;
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
			cout << "����δѡ����ſγ̣����̸���ʧ�ܣ�" << endl << endl;
			student_window();
		}
	}
	if (p->assistantamount == 0)
	{
		cout << "���ſγ̵�ǰû�����̣��޷�������" << endl << endl;
		student_window();
	}
	for (int i = 0; i < s->course_amount; i++)
	{
		if (!strcmp(s->course[i], id))
		{
			if(!strcmp(s->course_assistant[i],"NULL"))
			{
				cout << "����δѡ����ſγ̵����̣�����ѡ�����̣�" << endl << endl;
				student_window();
			}
		}
	}
	cout << id << ' ' << p->name << " �γ̵������У�";
	for (int i = 0; i < p->assistantamount - 1; i++)
	{
		cout << p->assistant[i] << ',';
	}
	cout << p->assistant[p->assistantamount - 1] << endl << endl;
	cout << "����������������ѡ��һ����Ϊ�Լ�������ĵ����̣�����'*'������һ������";
	char assistant_id[20];
	cin >> assistant_id;
	if (assistant_id[0] == '*')
		assistant_change();
	if (!strcmp(assistant_id, stu_id))
	{
		cout << "������ѡ���Լ�Ϊ�Լ������̣����̸���ʧ�ܣ�" << endl << endl;
		student_window();
	}
	for (int i = 0; i < p->assistantamount; i++)
	{
		if (!strcmp(p->assistant[i], assistant_id))
			break;
		if (i == p->assistantamount - 1)
		{
			cout << "����������̲���ȷ�����̸���ʧ�ܣ�" << endl << endl;
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
	cout << endl << "�������̸����ɹ���" << endl << endl;
}
void assistant_cancel()
{
	cout << "��������Ҫȡ�����̵Ŀγ̱�ţ�����'*'������һ������";
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
			cout << "������Ŀγ̲����ڣ�" << endl << endl;
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
			cout << "����δѡ����ſγ̣�����ȡ��ʧ�ܣ�" << endl << endl;
			student_window();
		}
	}
	if (p->assistantamount == 0)
	{
		cout << "���ſγ̵�ǰû�����̣��޷�ȡ����" << endl << endl;
		student_window();
	}
	for (int i = 0; i < s->course_amount; i++)
	{
		if (!strcmp(s->course[i], id))
		{
			if (!strcmp(s->course_assistant[i], "NULL"))
			{
				cout << "����δѡ����ſγ̵����̣��޷�ȡ�����̣�" << endl << endl;
				student_window();
			}
			else
				strcpy(s->course_assistant[i], "NULL");

		}
	}
	student_course_update();
	cout << endl << "��������ȡ���ɹ���" << endl << endl;
}
void assistant_update()
{
	FILE* fp = fopen("./assistant.txt", "w");
	if(fp==NULL)
	{
		cout << "assistant.txt�ļ���ʧ�ܣ�" << endl;
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
		cout << filename3 << "�ļ���ʧ�ܣ�" << endl;
		exit(-1);
	}
	for (int i = 0; i < s->course_amount; i++)
	{
		fprintf(fp, "%s %s", s->course[i], s->course_assistant[i]);
		fputc('\n', fp);
	}
	fclose(fp);
}