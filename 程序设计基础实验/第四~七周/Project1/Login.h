#pragma once
#ifndef _LOGIN_H
#define _LOGIN_H

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
using namespace std;

extern void welcome();
extern void begin();
extern int login();
extern void student_login();
extern void student_register();
extern void administrator_login();
extern void password_change();
extern void question_set_or_change();
extern void password_retrieve();
extern void logdown();

extern bool match_account(char stu_id[], char stu_password[]);
extern bool format_check(char stu_id[], char stu_password[]);
extern bool duplicat_check(char stu_id[]);
extern void register_account();
extern void student_password_change();
extern void administrator_password_change();
extern void student_question_set_or_change();
extern void administrator_question_set_or_change();
extern void student_password_retrieve();
extern void administrator_password_retrieve();

#endif