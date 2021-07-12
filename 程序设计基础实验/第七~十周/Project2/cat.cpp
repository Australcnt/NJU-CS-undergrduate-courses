#include "main.h"
#include "cat.h"

void all_cat()
{
  if(!cmd3.empty())//参数过多
  {
    cout << "cat: This situation is nor implemented!" << endl;
    myshell();
  }
//判断输入格式和--help
  if(cmd2 == "--help" || cmd2 == "--hel" || cmd2 == "--he" || cmd2 == "--h")
  {
    FILE* fp2 = fopen("./help/cat_help.txt","r");
    char cat_help[200];
    fgets(cat_help, 199, fp2);
    while(!feof(fp2))
    {
      cout << cat_help;
      fgets(cat_help, 199, fp2);
    }
    fclose(fp2);
    myshell();
  }
  else if(cmd2[0] == '-' && cmd2[1] == '-' && cmd2[2])
  {
    cout << "cat: unrecognized option '" << cmd2 << "'" << endl;
    cout << "Try 'cat --help' for more information." << endl;
    myshell();
  }
  else if(cmd2[0] == '-' && cmd2[1] && cmd2[1] != '-')
  {
    cout << "cat: invalid option -- '" << cmd2[1] << "'" << endl;
    cout << "Try 'cat --help' for more information." << endl;
    myshell();
  }
  else if(cmd2.empty())
  {
    cout << "cat: This situation is not implemented!" << endl;
    myshell();
  }
  else if(cmd2[0] == '-' && (!cmd2[1] || (cmd2[1] == '-')))
  {
    cout << "cat: This situation is not implemented!" << endl;
    myshell();
  }
  char* path;
  struct passwd *passwd;
  passwd = getpwuid(getuid());
  if(cmd2[0] == '~' && (!cmd2[1] || cmd2[1] == '/' || cmd2[1] == '.'))
  {
    path = strcat(passwd->pw_dir, cmd2.c_str() + 1);
    cmd2 = path;
  }
  if(access(cmd2.c_str(), F_OK) != 0)
  {
    cout << "cat: " << cmd2 << ": No such file or directory" << endl;
    myshell();
  }
  if(access(cmd2.c_str(), R_OK) != 0)
  {
    cout << "cat: " << cmd2 << ": Permission denied" << endl;
    myshell();
  }
  FILE* fp = fopen(cmd2.c_str(), "r"); 
//判断文件或目录
  struct stat statbuf;
  lstat(cmd2.c_str(),&statbuf);
  if(S_ISDIR(statbuf.st_mode) != 0)
  {
    cout << "cat: " << cmd2 << ": Is a directory" << endl;
    fclose(fp);
    myshell();
  }
  char ch;
  ch = fgetc(fp);
  while(!feof(fp))
  {
    cout << ch;
    ch = fgetc(fp);
  }
  fclose(fp);
}
