#include "main.h"

string cmd1, cmd2, cmd3, cmd4, cmd5, cmd6, cmd7, cmd8, cmd9;
int sh_flag = 0;
std::streambuf* x;

int main()
{
  printf("\033[1;33mWelcome to MyShell!\n\033[0m");
  myshell();
  return 0;
}

void myshell()
{
  while(1)
  {
    string().swap(cmd1);
    string().swap(cmd2);
    string().swap(cmd3);
    string().swap(cmd4);
    string().swap(cmd5);
    string().swap(cmd6);
    string().swap(cmd7);
    string().swap(cmd8);
    string().swap(cmd9);
    string str;
    if(!sh_flag)
      current_information_get();
    //cin.sync();
    //fflush(stdin);
    getline(cin, str);
    /*if(sh_flag)
    {
      string::iterator it;
      it = str.end()-1;
      str.erase(it);
    }*/
    if(str == "\000" && sh_flag)
    {
      std::cin.rdbuf(x);//恢复cin的流对象指针
      sh_flag--;
      continue;
    }
    istringstream cmd(str);
    cmd >> cmd1 >> cmd2 >> cmd3 >> cmd4 >> cmd5 >> cmd6 >> cmd7 >> cmd8 >> cmd9;
    if(cmd1[0] == '#' && sh_flag)
      continue;
    else if(cmd1 == "cp")
      all_cp();
    else if(cmd1 == "wc")  
      all_wc();
    else if(cmd1 == "cmp")  
      all_cmp();
    else if(cmd1 == "cat")  
      all_cat();
    else if(cmd1 == "man")  
      all_man();
    else if(cmd1 == "exit")
      exit(0);
    else if(cmd1.empty())
      continue;
    else if(cmd1 == "sh")
      all_sh();
    else
    {
      string::iterator it;
      for(it = str.begin(); it != str.end(); it++)
      {
        if(*it == ' ' || *it == '\t')
        {
          str.erase(it);
          it--;
        }
      }
      cout << str << ": command not found" << endl;
      continue;
    } 
  }
}

void current_information_get()//显示与terminal相同的命令行
{
  //get log name
  struct passwd *passwd;
  passwd = getpwuid(getuid());
  printf("\033[1;32m%s@\033[0m", passwd->pw_name);
  //get host name
  char name[128];
  gethostname(name, sizeof(name)-1);
  printf("\033[1;32m%s\033[0m", name);
  printf(":");
  //get cwd and currentpath
  char cwd[128];
  getcwd(cwd,sizeof(cwd)-1);
  char* s1 = strtok(cwd, "/");
  char* s2 = strtok(NULL, "/");
  char* s3 = strtok(NULL, "");
  if(!strcmp(s1,"home") && !strcmp(s2,passwd->pw_name))
  {
    char currentpath[128] = "~/";
    strcat(currentpath, s3);
  printf("\033[1;34m%s\033[0m", currentpath);
  printf("$ ");
  }
}
