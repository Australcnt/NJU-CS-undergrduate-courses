#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
using namespace std;
struct Stu//���ڴ洢ѧ�����ơ�ѧ��ѧ�š����Ƴɼ�
{
	char name[30];
	int id;
	int Math;
	int Chinese;
	int English;
};
struct Student//���ڴ洢ѧ�����ơ�ѧ��ѧ�š����Ƴɼ�
{
	char name[30];
	int id;
	int Math;
	int Chinese;
	int English;
	Student* next;
};
void Step1();
void Step2();
Student* ListSort(Student* head);
Student* ListSort(Student* head);
Student* ListSortInsert(Student* head, Student* p);
Student* AppCreateList();
void Step3();
void Step4();
int main()
{
	Step1();
	Step2();
	Step3();
	Step4();
	return 0;
}
void Step1()
{

	FILE* fp = fopen("grade.dat", "wb");//�Զ����Ʒ�ʽ���ļ��������
	if (fp == NULL)//�ж��ļ����Ƿ�ɹ�
	{
		printf("Fail to open file!\n");
		exit(-1);
	}
	Stu st;
	printf("Please input the information below into file grade.dat!\n");
	printf("End with name's value equal 'E'\n\n");
	printf("%-20s %-15s %-10s %-10s %-10s\n", "name", "id", "Math", "Chinese", "English");
	scanf("%29s", st.name);//�����һ��ѧ��������
	while (!(st.name[0] == 'E' && st.name[1] == '\0'))
	{
		scanf("%d", &st.id);
		scanf("%d", &st.Math);
		scanf("%d", &st.Chinese);
		scanf("%d", &st.English);
		fwrite(&st, sizeof(st), 1, fp);
		scanf("%29s", st.name);
	}
	fclose(fp);//�ر��ļ�
}
void Step2()
{
	FILE* fp2 = fopen("grade.dat", "rb");//�Զ����Ʒ�ʽ���ļ���������
	if (fp2 == NULL)//�ж��ļ����Ƿ�ɹ�
	{
		printf("Fail to open file2!\n");
		exit(-1);
	}
	Stu st2;
	printf("\n\nConstruct data struct and display into the screen!\n");
	printf("Display person's information!\n\n");
	printf("%-20s%-15s%-10s%-10s%-10s\n", "name", "id", "Math", "Chinese", "English");
	fread(&st2, sizeof(st2), 1, fp2);//�����һ��ѧ������Ϣ
	while (!feof(fp2))
	{
		printf("%-20s%-15d%-10d%-10d%-10d\n", st2.name, st2.id, st2.Math, st2.Chinese, st2.English);
		fread(&st2, sizeof(st2), 1, fp2);//������һ��ѧ������Ϣ
	}
	fclose(fp2);//�ر��ļ�
}
Student* ListSort(Student* head) //���뷨����
{ 
	if(head == NULL)   
		return NULL;  
	if(head -> next == NULL)   
		return head;  
	Student *cur = head -> next;  
	head -> next = NULL;   
	while(cur)   
	{ 
		Student *prev = cur;   
		cur = cur -> next;   
		head = ListSortInsert(head, prev);  
	}  
	return head;  
} 
Student* ListSortInsert(Student* head, Student* p) //����ڵ�
{
	if (((p->Math+p->Chinese+p->English) > (head->Math + head->Chinese + head->English))|| ((p->Math + p->Chinese + p->English) == (head->Math + head->Chinese + head->English)&&strcmp(p->name,head->name)<0))
	{
		p->next = head;
		head = p;
		return head;
	}  
	Student* cur = head;
	Student* prev = head;
	while (cur)
	{
		if (((p->Math + p->Chinese + p->English) > (cur->Math + cur->Chinese + cur->English)) || ((p->Math + p->Chinese + p->English) == (cur->Math + cur->Chinese + cur->English) && strcmp(p->name, cur->name) < 0))
			break;
		prev = cur;
		cur = cur->next;
	}
	p->next = prev->next;
	prev->next = p;
	return head;
}
Student* AppCreateList()//��������
{
	Stu st3;
	FILE* fp33 = fopen("grade.dat", "rb");//�Զ����Ʒ�ʽ���ļ���������
	if (fp33 == NULL)//�ж��ļ����Ƿ�ɹ�
	{
		printf("Fail to open file2!\n");
		return NULL;
	}
	Student* head = NULL, * tail = NULL;
	fread(&st3, sizeof(st3), 1, fp33);
	for (;;)
	{
		Student* p = new Student;
		for (int i = 0; i == 0 || st3.name[i - 1] != '\0'; i++)
			p->name[i] = st3.name[i];
		p->id = st3.id;
		p->Math = st3.Math;
		p->Chinese = st3.Chinese;
		p->English = st3.English;
		p->next = NULL;
		if (head == NULL)
			head = p;
		else
			tail->next = p;
		tail = p;
		fread(&st3, sizeof(st3), 1, fp33);
		if (feof(fp33))
			break;
	}
	fclose(fp33);//�ر��ļ�
	return head;
}
void Step3()
{
	printf("\n\n\nWrite into the grade_update.txt\n\n\n");
	FILE* fp3 = fopen("grade_update.txt", "w");//���ı���ʽ���ļ��������
	if (fp3 == NULL)//�ж��ļ����Ƿ�ɹ�
	{
		printf("Fail to open file3!\n");
		exit(-1);
	}
	Student* head = AppCreateList();
	Student* head2 = NULL;
	head2 = ListSort(head);
	int Sum = 0;
	fprintf(fp3, "%-30s%-20s%-10s%-10s%-10s%-10s", "name", "id", "Math", "Chinese", "English", "Sum");
	fputc('\n', fp3);
	while(head2)
	{
		Sum = head2->Math + head2->Chinese + head2->English;//�����ܳɼ�
		fprintf(fp3, "%-30s%-20d%-10d%-10d%-10d%-10d", head2->name, head2->id, head2->Math, head2->Chinese, head2->English, Sum);
		fputc('\n', fp3);
		head2 = head2->next;
	}
	fclose(fp3);//�ر��ļ�
}
void Step4()
{
	printf("Please choose which line you will revise:\n");
	printf("Please input name what you want to revise:\n\n\n");
	int line = 0;
	char name[30];
	scanf("%d", &line);
	scanf("%29s", name);
	FILE* fp4 = fopen("grade.dat", "w+b");//�Զ����Ʒ�ʽ���ļ��������
	if (fp4 == NULL)//�ж��ļ����Ƿ�ɹ�
	{
		printf("Fail to open file!\n");
		exit(-1);
	}
	printf("\n\nRevise the name of the ");
	printf("%d", line);
	printf(" name for Person information!\n\n\n");
	fseek(fp4, (line - 1) * 48, SEEK_SET);
	fwrite(name, sizeof(name), 1, fp4);
	//fseek(fp4, -30, SEEK_CUR);
	//fread(name, sizeof(name), 1, fp4);
	//printf("%s \n", name);�����Ƿ�ı�ɹ�
	fclose(fp4);//�ر��ļ�
}