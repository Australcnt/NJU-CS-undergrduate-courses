#include "main.h"
#include "sh.h"

void all_sh()
{
  sh_sh();
}

void sh_sh()
{
  if(cmd2.empty())
  {
    cout << "This situation is not implemented!" << endl;
    myshell();
  }
  char* path;
  char filename[256];
  struct passwd *passwd;
  passwd = getpwuid(getuid());
//对开头~/情况的处理
  if(cmd2[0] == '~' && (!cmd2[1] || cmd2[1] == '/' || cmd2[1] == '.'))
  {
    path = strcat(passwd->pw_dir, cmd2.c_str() + 1);
    cmd2 = path;
  }
  if(!realpath(cmd2.c_str(), filename))//脚本文件路径错误
  {
    cout << "sh: 0: Can't open " << cmd2 << endl;
    myshell();
  }
  if((cmd2[cmd2.size()-3] != '.' || cmd2[cmd2.size()-2] != 's' || cmd2[cmd2.size()-1] != 'h') && (cmd2[cmd2.size()-4] != '.' || cmd2[cmd2.size()-3] != 't' || cmd2[cmd2.size()-2] != 'x' || cmd2[cmd2.size()-1] != 't'))//输入的文件非脚本文件或txt文件
  {
    cout << "sh: 0: Can't open " << cmd2 << endl;
    myshell();
  }
  if(access(cmd2.c_str(), R_OK) != 0)//脚本文件没有读权限
  {
    cout << "sh: 0: Can't open " << cmd2 << endl;
    myshell();
  }
  FILE* fp = fopen(cmd2.c_str(), "r");
  /*if(fp == NULL)
  {
    cout << "fail to open " << cmd2 << endl;
    myshell();
  }*/
  sh_flag++;
  std::ifstream log(cmd2.c_str());
  x = cin.rdbuf(log.rdbuf());//返回cin的流对象指针，使cin重定向到文件中
  myshell();
  //std::cin.rdbuf(x);//恢复cin的流对象指针
  //sh_flag--;
  //fclose(fp);
}
