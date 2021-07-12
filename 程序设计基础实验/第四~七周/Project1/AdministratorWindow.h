#pragma once
#ifndef _ADMINISTRATOR_H
#define _ADMINISTRATOR_H

struct Course
{
	char number[4];
	char name[30];
	char teacher[20];
	int capacity;
	int amount;
	char type[10];
	int assistantamount;
	char student[100][20];
	char assistant[100][20];
	Course* next;
};

extern int administrator_first;
extern char my_id[21];
extern char my_password[21];
extern char my_question[51];
extern char my_answer[51];
extern char admin_id[21];
extern char admin_password[21];
extern Course* head;

extern void administrator_window();
extern void course_typein();
extern void allcourse_view();
extern void course_add();
extern void course_delete();
extern void course_change();
extern void specificcourse_view();
extern void administrator_security_check();
extern void administrator_logout();

extern void course_get(char filename[]);
extern void course_update();
extern bool course_duplicatcheck(Course* p);
extern void teacher_change(char id[]);
extern void capacity_change(char id[]);
extern void student_view(Course* p);
extern void assistant_view(Course* p);
extern void student_of_assistant_view(Course* p);
extern bool assistant_check(Course* p, char assistant_id[]);

#endif