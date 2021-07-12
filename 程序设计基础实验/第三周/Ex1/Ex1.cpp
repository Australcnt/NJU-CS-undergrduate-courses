#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
using namespace std;
struct Stu//用于存储学生名称、学生学号、各科成绩
{
	char name[30];
	int id;
	int Math;
	int Chinese;
	int English;
};
struct Student//用于存储学生名称、学生学号、各科成绩
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

	FILE* fp = fopen("grade.dat", "wb");//以二进制方式打开文件用于输出
	if (fp == NULL)//判断文件打开是否成功
	{
		printf("Fail to open file!\n");
		exit(-1);
	}
	Stu st;
	printf("Please input the information below into file grade.dat!\n");
	printf("End with name's value equal 'E'\n\n");
	printf("%-20s %-15s %-10s %-10s %-10s\n", "name", "id", "Math", "Chinese", "English");
	scanf("%29s", st.name);//读入第一个学生的名字
	while (!(st.name[0] == 'E' && st.name[1] == '\0'))
	{
		scanf("%d", &st.id);
		scanf("%d", &st.Math);
		scanf("%d", &st.Chinese);
		scanf("%d", &st.English);
		fwrite(&st, sizeof(st), 1, fp);
		scanf("%29s", st.name);
	}
	fclose(fp);//关闭文件
}
void Step2()
{
	FILE* fp2 = fopen("grade.dat", "rb");//以二进制方式打开文件用于输入
	if (fp2 == NULL)//判断文件打开是否成功
	{
		printf("Fail to open file2!\n");
		exit(-1);
	}
	Stu st2;
	printf("\n\nConstruct data struct and display into the screen!\n");
	printf("Display person's information!\n\n");
	printf("%-20s%-15s%-10s%-10s%-10s\n", "name", "id", "Math", "Chinese", "English");
	fread(&st2, sizeof(st2), 1, fp2);//读入第一个学生的信息
	while (!feof(fp2))
	{
		printf("%-20s%-15d%-10d%-10d%-10d\n", st2.name, st2.id, st2.Math, st2.Chinese, st2.English);
		fread(&st2, sizeof(st2), 1, fp2);//读入下一个学生的信息
	}
	fclose(fp2);//关闭文件
}
Student* ListSort(Student* head) //插入法排序
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
Student* ListSortInsert(Student* head, Student* p) //插入节点
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
Student* AppCreateList()//创建链表
{
	Stu st3;
	FILE* fp33 = fopen("grade.dat", "rb");//以二进制方式打开文件用于输入
	if (fp33 == NULL)//判断文件打开是否成功
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
	fclose(fp33);//关闭文件
	return head;
}
void Step3()
{
	printf("\n\n\nWrite into the grade_update.txt\n\n\n");
	FILE* fp3 = fopen("grade_update.txt", "w");//以文本方式打开文件用于输出
	if (fp3 == NULL)//判断文件打开是否成功
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
		Sum = head2->Math + head2->Chinese + head2->English;//计算总成绩
		fprintf(fp3, "%-30s%-20d%-10d%-10d%-10d%-10d", head2->name, head2->id, head2->Math, head2->Chinese, head2->English, Sum);
		fputc('\n', fp3);
		head2 = head2->next;
	}
	fclose(fp3);//关闭文件
}
void Step4()
{
	printf("Please choose which line you will revise:\n");
	printf("Please input name what you want to revise:\n\n\n");
	int line = 0;
	char name[30];
	scanf("%d", &line);
	scanf("%29s", name);
	FILE* fp4 = fopen("grade.dat", "w+b");//以二进制方式打开文件用于输出
	if (fp4 == NULL)//判断文件打开是否成功
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
	//printf("%s \n", name);检验是否改变成功
	fclose(fp4);//关闭文件
}