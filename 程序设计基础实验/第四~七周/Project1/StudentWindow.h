#pragma once
#ifndef _STUDENTWINDOW_H
#define _STUDENTWINDOW_H

struct Student
{
	char id[21];
	char password[21];
	char question[51];
	char answer[51];
	char assistant_course[10][4];
	int assistant_course_amount;
	char course[10][4];
	int course_amount;
	char course_assistant[10][20];
	char assistant_delete[10][4];
	int assistant_delete_flag;
	int wrong_times;
	Student* next;
};

extern char stu_id[21];
extern char stu_password[21];
extern Student* stuhead;
extern Student* stutail;
extern char filename2[30];

//功能函数
extern void student_window();
extern void course_view();
extern void course_select();
extern void student_course_view();
extern void student_course_drop();
extern void assistant_apply_or_drop();
extern void my_assistant();
extern void student_security_check();
extern void student_logout();

//辅助函数
extern void assistant_drop_check();
extern void course_upsort(int course_amount, char course[][4], char course_assistant[][20]);
extern void student_course_update();
extern void course_update2();
extern bool student_course_duplicatcheck(char id[], Student* s);
extern void assistant_drop_remind(char id[]);
extern void assistant_apply();
extern void assistant_drop();
extern void assistant_choose();
extern void assistant_change();
extern void assistant_cancel();
extern void assistant_update();
extern void otherstudent_course_update(char otherstudent_name[]);

#endif