#include "Login.h"
#include "AdministratorWindow.h"
#include "StudentWindow.h"

//���ܺ���
void administrator_window()
{
	for (int i = 0; i < 120; i++)
		cout << '=';
	cout << endl;
	for (int i = 0; i < 23; i++)
	{
		if (i == 1)
			cout << setw(10) << "1��¼��γ���Ϣ";
		else if (i == 4)
			cout << setw(10) << "2���鿴ȫ���γ���Ϣ";
		else if (i == 7)
			cout << setw(10) << "3�����ӿγ�";
		else if (i == 10)
			cout << setw(10) << "4��ɾ���γ�";
		else if (i == 13)
			cout << setw(10) << "5���޸Ŀγ�";
		else if (i == 16)
			cout << setw(10) << "6���鿴����γ�";
		else if (i == 19)
			cout << setw(10) << "7���鿴�ܱ�";
		else if (i == 22)
			cout << setw(10) << "8��ע����¼";
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
	if(!administrator_first)
	{
		while (1)
		{
			if (choice==1||choice==7||choice==8)
				break;
			else
			{
				cout << "����Ա��һ�ε�¼������¼��γ̣���鿴�ܱ���ע����¼�������������룡" << endl << endl;
				cout << "�����������ţ�";
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
				cout << "������Ĳ�����Ų���ȷ�����������룡" << endl << endl;
				cout << "�����������ţ�";
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
		cout << "��ǰ�γ���Ϣ��¼�룡�����ظ�¼�룡" << endl << endl;
		cout << "������ѡ�������" << endl << endl;
		fclose(p);
		administrator_window();
	}
	char filename[1000];
	cout << "��������Ҫ¼��Ŀγ��ļ������ƣ�����'*'������һ������";
	cin >> filename;
	if (filename[0] == '*')
		administrator_window();
	course_get(filename);
	course_update();
	administrator_first++;
	cout << endl << endl << "�γ���Ϣ¼��ɹ���" << endl << endl;
	administrator_window();
}
void allcourse_view()
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
	cout << "�����������룺�γ����ơ��ڿ���ʦ��������������ѡ�������γ����ͣ��м��ÿո�ָ�����)" << endl;
	cout << "��ÿ�ſγ������������س��������#��������" << endl << endl;
	cout << "��������Ҫ���ӵĿγ���Ϣ������'*'������һ����������Ŀγ̻��������룩��" << endl;
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
			cout << p->name << " �γ���Ϣ��ʽ���󣡸ÿγ�����ʧ�ܣ�" << endl << endl;
			continue;
		}
		cin >> p->teacher;
		if (ch = getchar() != ' ')
		{
			cout << p->name << " �γ���Ϣ��ʽ���󣡸ÿγ�����ʧ�ܣ�" << endl << endl;
			continue;
		}
		cin >> p->capacity;
		if (ch = getchar() != ' ')
		{
			cout << p->name << " �γ���Ϣ��ʽ���󣡸ÿγ�����ʧ�ܣ�" << endl << endl;
			continue;
		}
		cin >> p->amount;
		if (ch = getchar() != ' ')
		{
			cout << p->name << " �γ���Ϣ��ʽ���󣡸ÿγ�����ʧ�ܣ�" << endl << endl;
			continue;
		}
		cin >> p->type;
		p->assistantamount = 0;
		if (p->capacity <= 0)
		{
			cout << p->name << " �γ�������������Ϊ�������ÿγ�����ʧ�ܣ�" << endl << endl;
			continue;
		}
		if (p->amount < 0)
		{
			cout << p->name << " �γ���ѡ��������Ϊ�������ÿγ�����ʧ�ܣ�" << endl << endl;
			continue;
		}
		if (p->amount > p->capacity)
		{
			cout << p->name << " �γ���ѡ�������ܳ��������������ÿγ�����ʧ�ܣ�" << endl << endl;
			continue;
		}
		if (!head || course_duplicatcheck(p))//���γ��Ƿ��ظ�
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
				cout << "currentcourse.txt��ʧ�ܣ�" << endl;
			}
			fprintf(fp, "%-4s%-30s%-20s%-5d%-5d%-10s", p->number, p->name, p->teacher, p->capacity, p->amount, p->type);
			fputc('\n', fp);
			fclose(fp);
		}
	}
	cout << "�γ����ӳɹ���(����������ʧ�ܵĿγ̣�" << endl << endl;
	allcourse_view();
}
void course_delete()
{
	if(!head)
	{
		cout << "��ǰû���κογ̣��޷�ɾ���γ̣�" << endl;
		administrator_window();
	}
	cout << "��������Ҫɾ���Ŀγ̱�ţ�����'*'������һ������";
	char id[4];
	cin >> id;
	if (id[0] == '*')
		administrator_window();
	Course* head2 = head;
	if (!strcmp(id, head->number) && head->amount == 0)
	{
		Course* cur = head;
		cout << head->name << " �γ�ɾ���ɹ���" << endl << endl;
		head = head->next;
		delete(cur);
	}
	else if (!strcmp(id, head->number) && head->amount != 0)
		cout << "�ÿγ�����ѧ��ѡ���޷�ɾ����" << endl << endl;
	else
	{
		while (head2->next)
		{
			if (!strcmp(id, head2->next->number) && head2->next->amount == 0)
			{
				Course* cur = head2->next;
				cout << head2->next->name << " �γ�ɾ���ɹ���" << endl << endl;
				head2->next = head2->next->next;
				delete(cur);
				break;
			}
			if (!strcmp(id, head2->next->number) && head2->next->amount != 0)
			{
				cout << head2->next->name << " �γ�����ѧ��ѡ���޷�ɾ����" << endl << endl;
				break;
			}
			head2 = head2->next;
			if (!head2->next)
				cout << "������Ŀγ̲����ڣ��޷�ɾ����" << endl << endl;
		}
	}
	course_update();
	administrator_window();
}
void course_change()
{
	if (!head)
	{
		cout << "��ǰû���κογ̣��޷��޸Ŀγ̣�" << endl;
		administrator_window();
	}
	cout << "��������Ҫ�޸ĵĲ�����ţ�1���ڿ���ʦ  2����������  3��������һ������";
	int choice = 0;
	cin >> choice;
	if (choice == 3)
		administrator_window();
	while (choice < 1 || choice > 3)
	{
		cout << "������Ĳ�����Ų���ȷ�����������룡" << endl << endl;
		cout << "��������Ҫ�޸ĵĲ�����ţ�1���ڿ���ʦ  2����������  3��������һ������";
		cin >> choice;
		if (choice == 3)
			administrator_window();
	}
	cout << "��������Ҫ�޸ĵĿγ̱�ţ�����'*'������һ������";
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
		cout << "��ǰû���κογ̣��޷��鿴����γ̣�" << endl;
		administrator_window();
	}
	int choice;
	cout << "���������鿴�γ̵ķ�ʽ��1���γ̱��  2���γ�����  3��������һ������";
	cin >> choice;
	while(choice < 1 || choice > 3)
	{
		cout << "������Ĳ�����Ų���ȷ�����������룡" << endl << endl;
		cout << "���������鿴�γ̵ķ�ʽ��1���γ̱��  2���γ�����  3��������һ������";
		cin >> choice;
	}
	Course* p = head;
	if (choice == 1)
	{
		cout << "��������Ҫ�鿴�Ŀγ̱�ţ�����'*'������һ������";
		char id[4];
		cin >> id;
		if (id[0] == '*')
			administrator_window();
		while (strcmp(p->number, id))
		{
			p = p->next;
			if (!p)
			{
				cout << "������Ŀγ̲����ڣ�" << endl << endl;
				administrator_window();
			}
		}
	}
	else if (choice == 2)
	{
		cout << "��������Ҫ�鿴�Ŀγ����ƣ�����'*'������һ������";
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
				cout << "������Ŀγ̲����ڣ�" << endl << endl;
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
	cout << "��������������������1���鿴�ÿγ�ѧ������  2���鿴�ÿγ̱�����������  3������������" << endl;
	cout << "�����������ţ�";
	int choice2;
	cin >> choice2;
	while (choice2 < 1 || choice2 > 3)
	{
		cout << "������Ĳ�����Ų���ȷ�����������룡" << endl << endl;
		cout << "�����������ţ�";
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
		cout << "����δ�����ܱ����⣡" << endl << endl;
	else
	{
		cout << "�ܱ����⣺" << my_question << endl;
		cout << "�ܱ��𰸣�" << my_answer << endl << endl;
	}
	administrator_window();
}
void administrator_logout()
{
	cout << "���ѳɹ�ע������Ա�ˣ�" << endl;
	for (int i = 0; i < 120; i++)
		cout << '*';
	cout << endl << endl;
	welcome();
	begin();
}

//��������
void course_get(char filename[])
{
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		cout << filename << "��ʧ��" << endl;
		cout << "������ѡ�������" << endl << endl;
		administrator_window();
	}
	if (feof(fp))
	{
		cout << "�ÿγ��ļ�Ϊ�գ�������ѡ��γ��ļ���" << endl << endl;
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
		cout << "currentcourse.txt��ʧ��" << endl;
		cout << "������ѡ�������" << endl << endl;
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
			cout << p->name << " �γ��Ѵ��ڣ��ÿγ�����ʧ�ܣ�" << endl;
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
			cout << "�������޸ĺ���ڿ���ʦ������'*'������һ������";
			cin >> teacher;
			if (teacher[0] == '*')
				course_change();
			strcpy(head2->teacher, teacher);
			break;
		}
		head2 = head2->next;
		if (!head2)
			cout << "������Ŀγ̲����ڣ�" << endl;
	}
	course_update();
	if (head2)
		cout << endl << "�ڿ���ʦ�޸ĳɹ���" << endl << endl;
}
void capacity_change(char id[])
{
	int capacity = 0;
	Course* head2 = head;
	while (head2)
	{
		if (!strcmp(head2->number,id))
		{
			cout << "�������޸ĺ����������������'0'������һ������";
			cin >> capacity;
			if (capacity == 0)
				course_change();
			else if(capacity < 0)
				cout << "�޸ĵ�������������Ϊ�������޸�ʧ�ܣ�" << endl << endl;
			else if (capacity >= head2->amount)
				head2->capacity = capacity;
			else
				cout << "�޸ĵ�������������С����ѡ�������޸�ʧ�ܣ�" << endl << endl;
			break;
		}
		head2 = head2->next;
		if (!head2)
			cout << "������Ŀγ̲����ڣ�" << endl;
	}
	course_update();
	if (head2 && capacity >= head2->amount && capacity != 0)
		cout << endl << "���������޸ĳɹ���" << endl << endl;
}
void student_view(Course* p)
{
	if (!p->amount)
		cout << "��ǰû��ѧ��ѡ����ſγ̣�" << endl;
	else
	{
		cout << "��ǰѡ����ſγ̵�ѧ���У�";
		for(int i=0;i<p->amount;i++)
		{
			cout << p->student[i];
			if (i != p->amount - 1)
				cout << ',';
		}
		cout << endl;
		cout << "����" << p->amount << "��ѧ�����������λ���" << p->capacity - p->amount << "�ˣ�" << endl << endl;
	}
	cout << "��������������������1���鿴�ÿγ̱�����������  2������������" << endl;
	cout << "�����������ţ�";
	int choice;
	cin >> choice;
	while (choice < 1 || choice > 2)
	{
		cout << "������Ĳ�����Ų���ȷ�����������룡" << endl << endl;
		cout << "�����������ţ�";
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
		cout << "��ǰ���ſγ�û��ѧ���������̣�" << endl;
	else
	{
		cout << "��ǰѡ����ſγ̱����������У�";
		for (int i = 0; i < p->assistantamount; i++)
		{
			cout << p->assistant[i];
			if (i != p->assistantamount - 1)
				cout << ',';
		}
		cout << endl;
		cout << "����" << p->assistantamount << "�����̣�" << endl << endl;
	}
	cout << "��������������������1���鿴�ض������µ�ѧ������ 2���鿴�ÿγ�ѧ������  3������������" << endl;
	cout << "�����������ţ�";
	int choice;
	cin >> choice;
	while (choice < 1 || choice > 3)
	{
		cout << "������Ĳ�����Ų���ȷ�����������룡" << endl << endl;
		cout << "�����������ţ�";
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
		cout << "��ǰ���ſγ�û��ѧ���������̣�" << endl << endl;
	else
	{
		cout << "��ǰѡ����ſγ̱����������У�";
		for (int i = 0; i < p->assistantamount; i++)
		{
			cout << p->assistant[i];
			if (i != p->assistantamount - 1)
				cout << ',';
		}
		cout << endl;
		cout << "����������鿴������ID������'*'������һ������";
		char assistant_id[21];
		cin >> assistant_id;
		if (assistant_id[0] == '*')
			specificcourse_view();
		while(!assistant_check(p,assistant_id))
		{
			cout << "����������̲����ڣ����������룡" << endl;
			cout << "����������鿴������ID������'*'������һ������";
			cin >> assistant_id;
			if (assistant_id[0] == '*')
				specificcourse_view();
		}
		cout << "�������µ�ѧ������Ϊ��" << endl;
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
	cout << "��������������������1���鿴�ÿγ�ѧ������  2������������" << endl;
	cout << "�����������ţ�";
	int choice;
	cin >> choice;
	while (choice < 1 || choice > 2)
	{
		cout << "������Ĳ�����Ų���ȷ�����������룡" << endl << endl;
		cout << "�����������ţ�";
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