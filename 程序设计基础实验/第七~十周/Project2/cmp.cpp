#include "main.h"
#include "cmp.h"

void all_cmp()
{
//对输入格式的判断
  if(cmd2.empty())
  {
    cout << "cmp: missing operand after 'cmp'" << endl;
    cout << "cmp: Try 'cmp --help' for more information." << endl;
    myshell();
  }
  if(cmd2[0] == '-'|| (!cmd3.empty() && cmd3[0] == '-' && cmd3[1] == '-' && cmd3[2]))
    cmp_help();
  if(!cmd4.empty())
  {
    cout << "cmp: invalid --ignore-initial value '" << cmd4 << "'" << endl;
    cout << "cmp: Try 'cmp --help' for more information." << endl;
    myshell();
  }
  char* path1;
  char* path2;
  struct passwd *passwd;
  passwd = getpwuid(getuid());
//对~/情况的处理
  if(cmd2[0] == '~' && (!cmd2[1] || cmd2[1] == '/' || cmd2[1] == '.'))
  {
    path1 = strcat(passwd->pw_dir, cmd2.c_str() + 1);
    cmd2 = path1;
  }
  if(cmd3[0] == '~' && (!cmd3[1] || cmd3[1] == '/' || cmd3[1] == '.'))
  {
    path2 = strcat(passwd->pw_dir, cmd3.c_str() + 1);
    cmd3 = path2;
  }
  if(cmd2[0] == '-')//第一个参数第一位为“-”，且第二个参数存在
  {
    if(access(cmd3.c_str(), F_OK) != 0)//file2不存在
    {
      cout << "cmp: " << cmd3 << ": No such file or directory" << endl;
      myshell();
    } 
    struct stat statbuf3;
    lstat(cmd3.c_str(), &statbuf3);
    if(S_ISDIR(statbuf3.st_mode) != 0)//file2为目录
    {
      cout << "cmp: " << cmd3 << ": Is a directory" << endl;
      myshell();
    }
    else//file2为文件且存在
    {
      cout << "cmp: This situation is not implemented!" << endl;
      myshell();
    }
  }
  int byte = 0, line = 1;
  if(access(cmd2.c_str(), F_OK) != 0)
  {
    cout << "cmp: " << cmd2 << ": No such file or directory" << endl; 
    myshell();
  }
  if(access(cmd2.c_str(), R_OK) != 0)
  {
    cout << "cmp: " << cmd2 << ": Permission denied" << endl;
    myshell();
  }
  FILE* fp1 = fopen(cmd2.c_str(), "r");
  if(cmd3[0] == '-')
  {
    if(access(cmd2.c_str(), F_OK) != 0)//file1不存在
    {
      cout << "cmp: " << cmd2 << ": No such file or directory" << endl;
      fclose(fp1);
      myshell();
    }
    struct stat statbuf3;
    lstat(cmd2.c_str(), &statbuf3);
    if(S_ISDIR(statbuf3.st_mode) != 0)//file1为目录
    {
      cout << "cmp: " << cmd2 << ": Is a directory" << endl;
      fclose(fp1);
      myshell();
    }
    else//file1为文件且存在
    {
      cout << "cmp: This situation is not implemented!" << endl;
      fclose(fp1);
      myshell();
    }
  }
//对文件或目录的判断
  struct stat statbuf1;
  lstat(cmd2.c_str(), &statbuf1);
  if(S_ISDIR(statbuf1.st_mode) != 0)
  {
    cout << "cmp: " << cmd2 << ": Is a directory" << endl;
    fclose(fp1);
    myshell();
  }
  if(cmd3.empty())
  {
    cout << "cmp: This situation is not implemented!" << endl;
    fclose(fp1);
    myshell();
  }
  if(access(cmd3.c_str(), F_OK) != 0)
  {
    cout << "cmp: " << cmd3 << ": No such file or directory" << endl;
    fclose(fp1); 
    myshell();
  }
  if(access(cmd3.c_str(), R_OK) != 0)
  {
    cout << "cmp: " << cmd3 << ": Permission denied" << endl;
    fclose(fp1);
    myshell();
  }
  FILE* fp2 = fopen(cmd3.c_str(), "r");
//对文件或目录的判断
  struct stat statbuf2;
  lstat(cmd3.c_str(), &statbuf2);
  if(S_ISDIR(statbuf2.st_mode) != 0)
  {
    cout << "cmp: " << cmd3 << ": Is a directory" << endl;
    fclose(fp1);
    fclose(fp2);
    myshell();
  }
  char ch1, ch2;
  ch1 = fgetc(fp1);
  ch2 = fgetc(fp2);
  byte++;
  if(feof(fp1) && feof(fp2))//两个文件均无内容
  {  
    fclose(fp1);
    fclose(fp2);
    myshell();
  }
  else if(feof(fp1) && !feof(fp2))//第一个文件无内容，第二个文件有内容
  {
    fclose(fp1);
    fclose(fp2);
    cout << "cmp: EOF on " << cmd2 << endl;
    myshell();
  }
  else if(!feof(fp1) && feof(fp2))//第一个文件有内容，第二个文件无内容
  {
    fclose(fp1);
    fclose(fp2);
    cout << "cmp: EOF on " << cmd3 << endl;
    myshell();
  }
//还需判断是否为目录 
  while(1)
  {  
    if(feof(fp1) || feof(fp2))
    { 
      cout << cmd2 << " " << cmd3 << " differ: byte " << byte << ", line " << line << endl;
      break;
    }
    if(ch1 != ch2)
    { 
      cout << cmd2 << " " << cmd3 << " differ: byte " << byte << ", line " << line << endl;
      break;
    }
    if(ch1 == '\n')
      line++;
    char ch3 = ch1;
    char ch4 = ch2;
    ch1 = fgetc(fp1); 
    ch2 = fgetc(fp2);
    byte++;
    if(feof(fp1) && feof(fp2))
      break;
    if(feof(fp1) && ch4 == '\n')//两个文件第一部分相同，但第二个文件后面还有数据
    {
      cout << "cmp: EOF on " << cmd2 << endl;
      break;
    } 
    if(feof(fp2) && ch3 == '\n')//两个文件第一部分相同，但第一个文件后面还有数据
    {
      cout << "cmp: EOF on " << cmd3 << endl;
      break;
    }
  }
  fclose(fp1);
  fclose(fp2);   
}

void cmp_help()
{
  if(cmd2 == "--help" || cmd2 == "--hel" || cmd2 == "--he" || cmd2 == "--h")//是否满足--help条件
  {
    FILE* fp3 = fopen("./help/cmp_help.txt","r");
    if(fp3 == NULL)
    {
      cout << "fail to open cmp_help.txt" << endl;
      myshell();
    }
    char cmp_help[200];
    fgets(cmp_help,199,fp3);
    while(!feof(fp3))
    {
      cout << cmp_help;
      fgets(cmp_help,199,fp3);
    }
    fclose(fp3);
    myshell();
  }
//其他格式判断
  else if(!cmd2[1] && (cmd3.empty() || cmd3[0] == '-'))
    myshell();
  else if(cmd2[1] && !cmd2[2] && (cmd3.empty()))
  {
    cout << "cmp: missing operand after '" << cmd2 << "'" << endl;
    cout << "cmp: Try 'cmp --help' for more information." << endl;
    myshell();
  }
  else if(cmd2[1] && cmd2[1] != '-' && cmd3.empty())
  {
    cout << "cmp: invalid option -- '" << cmd2[1] << "'" << endl;
    cout << "cmp: Try 'cmp --help' for more information." << endl;
    myshell();
  }
  else if(cmd2[1] == '-')
  {
    cout << "cmp: unrecognized option '" << cmd2 << "'" << endl;
    cout << "Try 'cmp --help' for more information." << endl;
    myshell();
  }
  else if(!cmd3.empty() && cmd3[0] == '-' && cmd3[1] == '-' && cmd3[2])
  {
    cout << "cmp: unrecognized option '" << cmd3 << "'" << endl;
    cout << "Try 'cmp --help' for more information." << endl;
    myshell();
  } 
}
