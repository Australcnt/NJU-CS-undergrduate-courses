#ifndef _MAIN_H
#define _MAIN_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <pwd.h>
#include <string.h>
#include <libgen.h>
#include <fstream>

#include "cp.h"
#include "wc.h"
#include "cmp.h"
#include "cat.h"
#include "man.h"
#include "sh.h"

using namespace std;

extern string cmd1, cmd2, cmd3, cmd4, cmd5, cmd6, cmd7, cmd8, cmd9;
extern int sh_flag;
extern streambuf* x;

void myshell();
void current_information_get();

#endif
