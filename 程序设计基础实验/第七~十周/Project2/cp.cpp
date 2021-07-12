#include "main.h"
#include "cp.h"

bool dir_copy(string from_path, string to_path, string to_path_directory_name);
bool directory_copy(string from_path, string to_path, string to_path_directory_name);

void all_cp()
{
  if(cmd2 == "-r")//判断是否为cp -r
    cp_r();
  else
    cp();
  myshell();
}

void cp()
{
  cp_format_check();
  char filename1[1000], filename2[1000];
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
  if(!realpath(cmd2.c_str(), filename1))
  {
    cout << "cp: cannot stat '" << cmd2 << "' : No such file or directory" << endl;
    myshell();
  }
  struct stat statbuf1;
  lstat(cmd2.c_str(), &statbuf1);
  if(S_ISDIR(statbuf1.st_mode) != 0)
  {
    cout << "cp: omitting directory '" << cmd2 << "'" << endl;
    myshell();
  }
  if(cmd2 == cmd3)
  {
    cout << "cp: '" << cmd2 << "' and '" << cmd3 << "' are the sam file" << endl;
    myshell();
  }
  if(access(cmd2.c_str(), R_OK) != 0)
  {
    cout << "cp: cannot open '" << cmd2 << "' for reading: Permission denied" << endl;
    myshell();
  }
  int directory_flag = 0;
  for(int i = 0; i < cmd3.size(); i++)
  {
    if(cmd3[i] == '/' && (i == 0 || cmd3[i - 1] != '.'))
      directory_flag = 1;
  }
  string to_path_directory_name;
  string cmd3_1 = cmd3;
  string::iterator it3;
  it3 = cmd3_1.end() - 1;
  if(*it3 == '/')
    cmd3_1.erase(it3);
  if(!realpath(cmd3.c_str(), filename2) && directory_flag)//分离第二个路径的目录和文件名
  {
    string::iterator it;
    it = cmd3_1.end() - 1;
    if(*it != '/')
    {
      for(; *it != '/'; it--)
        cmd3_1.erase(it);
      cmd3_1.erase(it);
    }
  }
  if(!realpath(cmd3_1.c_str(), filename2))//第二个文件为目录，但路径错误
  {
    cout << "cp: cannot create regular file '" << cmd3 << "' : No such file or directory" << endl;
    myshell();
  }
  struct stat statbuf2;
  lstat(cmd3.c_str(), &statbuf2);
  if(S_ISDIR(statbuf2.st_mode) != 0)//第二个文件为目录
  {
    string file2;
    file2 = basename(const_cast<char*>(cmd2.c_str()));
    if(access(cmd3.c_str(), X_OK) != 0)//目录没执行权限
    {
      if(cmd3[cmd3.size() - 1] == '/')
        cmd3 = cmd3 + file2;
      else
        cmd3 = cmd3 + '/' + file2;
      cout << "cp: cannot stat '" << cmd3 << "': Permission denied" << endl;
      myshell(); 
    }
    if(access(cmd2.c_str(), R_OK) != 0)//file1没读权限
    {
      cout << "cp: cannot open '" << cmd2 << "' for reading: Permission denied" << endl;
      myshell(); 
    }
    if(access(cmd3.c_str(), W_OK) != 0)//目录没写权限
    {
      if(cmd3[cmd3.size() - 1] == '/')
        cmd3 = cmd3 + file2;
      else
        cmd3 = cmd3 + '/' + file2;
      cout << "cp: cannot create regular file '" << cmd3 << "': Permission denied" << endl;
      myshell(); 
    }
    else//目录有权限
    {
      if(cmd3[cmd3.size() - 1] == '/')
        cmd3 = cmd3 + file2;
      else
        cmd3 = cmd3 + '/' + file2;
      if(access(cmd2.c_str(), R_OK) != 0)//file1没读权限
      {
        cout << "cp: cannot open '" << cmd2 << "' for reading: Permission denied" << endl;
        myshell(); 
      }
      if((access(cmd3.c_str(), F_OK) == 0) && (access(cmd3.c_str(), W_OK) != 0))//判断文件存在且没有写权限
      { 
        cout << "cp: cannot create regular file '" << cmd3 << "' : Permission denied" << endl;
        myshell();
      }
      else
      {
        if(access(cmd3.c_str(), F_OK) ==0)//第二个文件存在 
        {
          FILE* fp1 = fopen(cmd2.c_str(), "r");
          FILE* fp2 = fopen(cmd3.c_str(), "w");
          char ch;
          ch = fgetc(fp1);
          while(!feof(fp1))
          {
            fputc(ch, fp2);
            ch = fgetc(fp1);
          }
          fclose(fp1);
          fclose(fp2);
        }
        else
        {
          FILE* fp1 = fopen(cmd2.c_str(), "r");
          FILE* fp2 = fopen(cmd3.c_str(), "w");
          char ch;
          ch = fgetc(fp1);
          while(!feof(fp1))
          {
            fputc(ch, fp2);
            ch = fgetc(fp1);
          }
          fclose(fp1);
          fclose(fp2);
          chmod(cmd3.c_str(), 777);
          chmod(cmd3.c_str(), statbuf1.st_mode&ALLPERMS);//保证权限不变
        }
      }
    }
    myshell();
  }
  if(access(cmd2.c_str(), R_OK) != 0)//file1没读权限
  {
    cout << "cp: cannot open '" << cmd2 << "' for reading: Permission denied" << endl;
    myshell(); 
  }
  if((access(cmd3.c_str(), F_OK) == 0) && (access(cmd3.c_str(), W_OK) != 0))//判断文件存在且没有写权限
  {
    cout << "cp: cannot create regular file '" << cmd3 << "' : Permission denied" << endl;
    myshell();
  }
  else
  {
    if(access(cmd3.c_str(), F_OK) ==0)//第二个文件存在 
        {
          FILE* fp1 = fopen(cmd2.c_str(), "r");
          FILE* fp2 = fopen(cmd3.c_str(), "w");
          char ch;
          ch = fgetc(fp1);
          while(!feof(fp1))
          {
            fputc(ch, fp2);
            ch = fgetc(fp1);
          }
          fclose(fp1);
          fclose(fp2);
        }
        else
        {
          FILE* fp1 = fopen(cmd2.c_str(), "r");
          FILE* fp2 = fopen(cmd3.c_str(), "w");
          char ch;
          ch = fgetc(fp1);
          while(!feof(fp1))
          {
            fputc(ch, fp2);
            ch = fgetc(fp1);
          }
          fclose(fp1);
          fclose(fp2);
          chmod(cmd3.c_str(), 777);
          chmod(cmd3.c_str(), statbuf1.st_mode&ALLPERMS);//保证权限不变
        }
  }
}

void cp_format_check()
{
  if(!cmd4.empty())//是否参数大于两个
  {
    cout << "cp: This situation is not implemented!" << endl;
    myshell();
  }
  if(cmd2 == "--help" || cmd2 == "--hel" || cmd2 == "--he" || cmd2 == "--h" || cmd3 == "--help" || cmd3 == "--hel" || cmd3 == "--he" || cmd3 == "--h")//是否满足--help的条件
  {
    FILE* fp3 = fopen("./help/cp_help.txt", "r");
    char cp_help[200];
    fgets(cp_help, 199, fp3);
    while(!feof(fp3))
    {
      cout << cp_help;
      fgets(cp_help, 199, fp3);
    }
    fclose(fp3);
    myshell();
  }
  else if(cmd2.empty())//没有参数
  {
    cout << "cp: missing file operand" << endl;
    cout << "Try 'cp --help' for more information." << endl;
    myshell();
  }
  else if(cmd2[0] == '-' && cmd2[1] == '-' && cmd2[2] && cmd2[3])//不可识别的命令
  {
    cout << "cp: unrecognized option  '" << cmd2 << "'" << endl;
    cout << "Try 'cp --help' for more information." << endl;
    myshell();
  }
  else if(cmd2[0] == '-' && cmd2[1] && cmd3.empty())//无效参数
  {
    cout << "cp: missing file operand" << endl;
    cout << "Try 'cp --help' for more information." << endl;
    myshell();
  }
  else if(!cmd2.empty() && cmd3.empty())//有效参数
  {
    cout << "cp: missing destination file operand after '" << cmd2 << "'" << endl;
    cout << "Try 'cp --help' for more information." << endl;
    myshell();
  }
  if(cmd2[0] == '-' && cmd2[1] && cmd3[0] == '-' && cmd3[1] == '-' && cmd3[2] && cmd3[3])//不可识别的命令
  {
    cout << "cp: unrecognized option  '" << cmd3 << "'" << endl;
    cout << "Try 'cp --help' for more information." << endl;
    myshell();
  }
  else if(cmd2[0] == '-' && cmd2[1] && cmd3[0] == '-' && cmd3[1])//无效参数
  {
    cout << "cp: missing file operand" << endl;
    cout << "Try 'cp --help' for more information." << endl;
    myshell();
  }
  else if(cmd2[0] == '-' && cmd2[1])//有效参数
  {
    cout << "cp: missing destination file operand after '" << cmd3 << "'" << endl;
    cout << "Try 'cp --help' for more information." << endl;
    myshell();
  }
  else if(cmd3[0] == '-' && cmd3[1] == '-' && cmd3[2] && cmd3[3])//不可识别的命令
  {
    cout << "cp: unrecognized option  '" << cmd3 << "'" << endl;
    cout << "Try 'cp --help' for more information." << endl;
    myshell();
  }
  else if(cmd3[0] == '-' && cmd3[1])//有效参数
  {
    cout << "cp: missing destination file operand after '" << cmd2 << "'" << endl;
    cout << "Try 'cp --help' for more information." << endl;
    myshell();
  }
}

void cp_r()
{
  cp_r_format_check();
  char filename1[1000], filename2[1000];
  char* path1;
  char* path2;
  struct passwd *passwd;
  passwd = getpwuid(getuid());
//对~/情况的处理
  if(cmd3[0] == '~' && (!cmd3[1] || cmd3[1] == '/' || cmd3[1] == '.'))
  {
    path1 = strcat(passwd->pw_dir, cmd3.c_str() + 1);
    cmd3 = path1;
  }
  if(cmd4[0] == '~' && (!cmd4[1] || cmd4[1] == '/' || cmd4[1] == '.'))
  {
    path2 = strcat(passwd->pw_dir, cmd4.c_str() + 1);
    cmd4 = path2;
  }
  if(!realpath(cmd3.c_str(), filename1))
  {
    cout << "cp: cannot stat '" << cmd3 << "' : No such file or directory" << endl;
    myshell();
  }
  struct stat statbuf1;
  lstat(cmd3.c_str(), &statbuf1);
  if(S_ISREG(statbuf1.st_mode) != 0)//第一个目录为文件，则转交给cp函数进行处理
  {
    cmd2 = cmd3;
    cmd3 = cmd4;
    string().swap(cmd4);
    cp();
  }
  struct stat statbuf2;
  lstat(cmd4.c_str(), &statbuf2);
  if(access(cmd3.c_str(), R_OK) != 0)//第一个目录没有读权限
  {
    if(S_ISREG(statbuf2.st_mode) != 0)//第二个目录为文件
    {
      string file1, file2;
      file2 = cmd3;
      file1 = basename(const_cast<char*>(cmd3.c_str()));
      cmd3 = file2;
      if(cmd4[cmd4.size() - 1] == '/')
        cmd4 = cmd4 + file1;
      else
        cmd4 = cmd4 + '/' + file1;
      cout<< "cp: cannot overwrite non-directory '" << cmd4 << "' with directory '" << cmd3 << "'" << endl;
      myshell();
    }
  }
  string to_path_directory_name;
  string cmd4_1 = cmd4;
  string::iterator it3;
  it3 = cmd4_1.end() - 1;
  if(*it3 == '/')
    cmd4_1.erase(it3);
  if(!realpath(cmd4.c_str(), filename2))//分离第二个路径的目录和文件名
  {
    to_path_directory_name = basename(const_cast<char*>(cmd4.c_str()));
    string::iterator it;
    it = cmd4_1.end() - 1;
    if(*it != '/')
    {
      for(; *it != '/'; it--)
        cmd4_1.erase(it);
      cmd4_1.erase(it);
    }
  }
  else
    to_path_directory_name = basename(const_cast<char*>(cmd3.c_str()));
  lstat(cmd4_1.c_str(), &statbuf2);
  if(!realpath(cmd4_1.c_str(), filename2))//第二个目录路径错误
  {
    cout << "cp: cannot create directory '" << cmd4 << "' : No such file or directory" << endl;
    myshell();
  }
  if(S_ISREG(statbuf2.st_mode) != 0)//第二个目录为文件
  {
    cout<< "cp: cannot overwrite non-directory '" << cmd4 << "' with directory '" << cmd3 << "'" << endl;
    myshell();
  }
  if(S_ISDIR(statbuf2.st_mode) != 0)//第二个文件为目录
  {
    string file1, file2;
    file2 = cmd3;
    file1 = basename(const_cast<char*>(cmd3.c_str()));
    cmd3 = file2;
    if(access(cmd4_1.c_str(), X_OK) != 0)//第二个目录没执行权限
    {
      if(cmd4[cmd4.size() - 1] == '/')
        cmd4 = cmd4 + file1;
      else
        cmd4 = cmd4 + '/' + file1;
      cout << "cp: cannot stat '" << cmd4 << "': Permission denied" << endl;
      myshell(); 
    }
    if(access(cmd4_1.c_str(), W_OK) != 0)//第二个目录没写权限
    {
      if(cmd4[cmd4.size() - 1] == '/')
        cmd4 = cmd4 + file1;
      else
        cmd4 = cmd4 + '/' + file1;
      cout << "cp: cannot create regular file '" << cmd4 << "': Permission denied" << endl;
      myshell(); 
    }
    if(access(cmd3.c_str(), R_OK) == 0 && dir_empty_check())//第一个目录为空
    {
      if(cmd4[cmd4.size() - 1] == '/')
        cmd4 = cmd4 + file1;
      else
        cmd4 = cmd4 + '/' + file1;
      cout<< "cp: cannot overwrite non-directory '" << cmd4 << "' with directory '" << cmd3 << "'" << endl;
      myshell();
    }
    string::iterator it1;
    string::iterator it2;
    it1 = cmd3.end() - 1;
    it2 = cmd4.end() - 1;
    if(*it1 == '/')
      cmd3.erase(it1);//删除末尾的"/"
    if(*it2 == '/')
      cmd4.erase(it2);//删除末尾的"/"
    dir_copy(cmd3, cmd4_1, to_path_directory_name);//递归复制目录
    myshell();
  }
}

void cp_r_format_check()
{
  if(!cmd5.empty())//是否参数大于两个
  {
    cout << "cp: This situation is not implemented!" << endl;
    myshell();
  }
  if(cmd3 == "--help" || cmd3 == "--hel" || cmd3 == "--he" || cmd3 == "--h" || cmd4 == "--help" || cmd4 == "--hel" || cmd4 == "--he" || cmd4 == "--h")//是否满足--help的条件
  {
    FILE* fp3 = fopen("./help/cp_help.txt", "r");
    char cp_help[200];
    fgets(cp_help, 199, fp3);
    while(!feof(fp3))
    {
      cout << cp_help;
      fgets(cp_help, 199, fp3);
    }
    fclose(fp3);
    myshell();
  }
  else if(cmd3.empty())//没有参数
  {
    cout << "cp: missing file operand" << endl;
    cout << "Try 'cp --help' for more information." << endl;
    myshell();
  }
  else if(cmd3[0] == '-' && cmd3[1] == '-' && cmd3[2] && cmd3[3])//不可识别的命令
  {
    cout << "cp: unrecognized option  '" << cmd3 << "'" << endl;
    cout << "Try 'cp --help' for more information." << endl;
    myshell();
  }
  else if(cmd3[0] == '-' && cmd3[1] && cmd4.empty())//无效参数
  {
    cout << "cp: missing file operand" << endl;
    cout << "Try 'cp --help' for more information." << endl;
    myshell();
  }
  else if(!cmd3.empty() && cmd4.empty())//有效参数
  {
    cout << "cp: missing destination file operand after '" << cmd3 << "'" << endl;
    cout << "Try 'cp --help' for more information." << endl;
    myshell();
  }
  if(cmd3[0] == '-' && cmd3[1] && cmd4[0] == '-' && cmd4[1] == '-' && cmd4[2] && cmd4[3])//不可识别的命令
  {
    cout << "cp: unrecognized option  '" << cmd4 << "'" << endl;
    cout << "Try 'cp --help' for more information." << endl;
    myshell();
  }
  else if(cmd3[0] == '-' && cmd3[1] && cmd4[0] == '-' && cmd4[1])//无效参数
  {
    cout << "cp: missing file operand" << endl;
    cout << "Try 'cp --help' for more information." << endl;
    myshell();
  }
  else if(cmd3[0] == '-' && cmd3[1])//有效参数
  {
    cout << "cp: missing destination file operand after '" << cmd4 << "'" << endl;
    cout << "Try 'cp --help' for more information." << endl;
    myshell();
  }
  else if(cmd4[0] == '-' && cmd4[1] == '-' && cmd4[2] && cmd4[3])//不可识别的命令
  {
    cout << "cp: unrecognized option  '" << cmd4 << "'" << endl;
    cout << "Try 'cp --help' for more information." << endl;
    myshell();
  }
  else if(cmd4[0] == '-' && cmd4[1])//有效参数
  {
    cout << "cp: missing destination file operand after '" << cmd3 << "'" << endl;
    cout << "Try 'cp --help' for more information." << endl;
    myshell();
  }
}

bool dir_empty_check()//判断第一个目录是否为空
{
  DIR* dir = opendir(cmd3.c_str());
  struct dirent* ent;
  while(1)
  {
    ent = readdir(dir);
    if(ent <= 0)
      break;
    if(!strcmp(".", ent->d_name) || !strcmp("..", ent->d_name))
      continue;
    if(ent->d_type == DT_DIR || ent->d_type == DT_REG)
    {
      closedir(dir);
      return false;
    }
  }
  closedir(dir);
  return true;
}

bool dir_copy(string from_path, string to_path, string to_path_directory_name)
{
  if(access(from_path.c_str(), R_OK) != 0)
  {
    cout << "cp: cannot access '" << from_path << "' :Permission denied" << endl;
    return false;
  }
  DIR* dir1 = opendir(from_path.c_str());
  if(access(to_path.c_str(), X_OK) != 0 && access(from_path.c_str(), X_OK) == 0)
  {
    cout << "cp: cannot stat '" << to_path << '/' << to_path_directory_name << "' :Permission denied" << endl;
    return false;
  }
  DIR* dir2 = opendir(to_path.c_str());
  dirent* file1;
  dirent* file2;
  while(1)
  {
    if(!(file2 = readdir(dir2)))//dir2中无与to_path_directory_name同名的目录或文件，则递归调用函数directory_copy创建与之同名的目录
    {
      if(access(from_path.c_str(), X_OK) != 0)
      {
        cout << "cp: cannot stat '" << to_path << '/' << to_path_directory_name << "': Permission denied" << endl;
        break;
      }
      directory_copy(from_path, to_path, to_path_directory_name);
      break;
    }
    if(!strcmp(file2->d_name, to_path_directory_name.c_str()) && file2->d_type == DT_REG)//dir2中有与dir1同名的文件，则无法复制dir1
    {
      cout << "cp: cannot overwrite non-directory '" << to_path << '/' << to_path_directory_name << "' with directory '" << from_path << "'" << endl;
      break;
    }
    if(!strcmp(file2->d_name, to_path_directory_name.c_str()) && file2->d_type == DT_DIR)//dir2中有与to_path_directory_name同名的目录，则更新与之同名的目录
    {
      string to_path_directory;
      to_path_directory = file2->d_name;
      to_path_directory = to_path + '/' + to_path_directory;
      /*if(access(to_path_directory.c_str(), X_OK) != 0 && access(from_path.c_str(), X_OK) == 0)
      {
        cout << "cp: cannot stat '" << to_path_directory << "': Permission denied" << endl;
        closedir(dir1);
        closedir(dir2);
        return false;
      }*/
      if(access(to_path_directory.c_str(), W_OK) != 0 && access(from_path.c_str(), X_OK == 0))
      {
        cout << "cp: cannot create directory '" << to_path_directory << "': Permission denied" << endl;
        closedir(dir1);
        closedir(dir2);
        return false;
      }
      DIR* dir3 = opendir(to_path_directory.c_str());//打开dir2中与dir1同名的目录dir3
      dirent* file3;
      while(file1 = readdir(dir1))
      {
        if(!strcmp(file1->d_name, ".") || !strcmp(file1->d_name, ".."))//当前目录"."或上一级目录".."，不进行复制
          continue;
        while(1)
        {
          if(!(file3 = readdir(dir3)))//dir3中没有和file1同名的目录或文件
          {
            if(file1->d_type == DT_DIR)//file1为目录,则递归调用函数directory_copy创建与file1同名的目录
            {
              string from_path_directory;
              from_path_directory = file1->d_name;
              string to_path_directory_directory_name;
              to_path_directory_directory_name = file1->d_name;
              from_path_directory = from_path + '/' + from_path_directory;
              if(access(from_path.c_str(), X_OK) != 0)
                cout << "cp: cannot stat '" << from_path_directory << "': Permission denied" << endl;
              else
                directory_copy(from_path_directory, to_path_directory, to_path_directory_directory_name);
            }
            if(file1->d_type == DT_REG)//file1为文件，则创建与file1同名的文件
            {
              string from_path_file;
              from_path_file = file1->d_name;
              from_path_file = from_path + '/' + from_path_file;
              string to_path_file;
              to_path_file = file1->d_name;
              to_path_file = to_path_directory + '/' + to_path_file;
              if(access(from_path.c_str(), X_OK) != 0)
              {
                cout << "cp: cannot stat '" << from_path_file << "': Permission denied" << endl;
                break;
              }
              if(access(from_path_file.c_str(), R_OK) != 0)
              {
                cout << "cp: cannot open '" << from_path_file << "' for reading: Permission denied" << endl;
                break;
              }
              FILE* fp1 = fopen(from_path_file.c_str(), "r");
              if(access(to_path_directory.c_str(), X_OK) != 0)
              {
                cout << "cp: cannot stat '" << to_path_file << "': Permission denied" << endl;
                break;
              }
              FILE* fp2 = fopen(to_path_file.c_str(), "w");
              char ch;
              ch = fgetc(fp1);
              while(!feof(fp1))
              {
                fputc(ch, fp2);
                ch = fgetc(fp1);
              }
              fclose(fp1);
              fclose(fp2);
              chmod(to_path_file.c_str(), 777);
              struct stat statbuf1;
              lstat(from_path_file.c_str(), &statbuf1);
              chmod(to_path_file.c_str(), statbuf1.st_mode&ALLPERMS);//保证权限不变
            }
            break;
          }
          if(!strcmp(file1->d_name, file3->d_name) && file1->d_type == DT_DIR && file3->d_type == DT_REG)//dir3中有文件file3与目录file1同名，则无法复制
          {
            cout << "cp: cannot overwrite non-directory '" << to_path_directory << '/' << file1->d_name << "' with directory '" << from_path << '/' << file1->d_name << "'" << endl;
            break;
          }
          if(!strcmp(file1->d_name, file3->d_name) && file1->d_type == DT_REG && file3->d_type == DT_DIR)//dir3中有目录file3与文件file1同名，则无法复制
          {
            cout << "cp: cannot overwrite directory '" << to_path_directory << '/' << file1->d_name << "' with non-directory" << endl;
            break;
          }
          if(!strcmp(file1->d_name, file3->d_name) && file1->d_type == DT_REG && file3->d_type == DT_REG)//dir3中有文件file3与文件file1同名，则用file1覆盖file3
          {
            string from_path_file;
            from_path_file = file1->d_name;
            from_path_file = from_path + '/' + from_path_file;
            string to_path_file;
            to_path_file = file1->d_name;
            to_path_file = to_path_directory + '/' + to_path_file;
            if(access(from_path.c_str(), X_OK) != 0)
            {
              cout << "cp: cannot stat '" << from_path_file << "': Permission denied" << endl;
              break;
            }
            if(access(from_path_file.c_str(), R_OK) != 0 && access(to_path_directory.c_str(), X_OK) == 0)
            {
              cout << "cp: cannot open '" << from_path_file << "' for reading: Permission denied" << endl;
              break;
            }
            FILE* fp1 = fopen(from_path_file.c_str(), "r");
            if(access(to_path_directory.c_str(), X_OK) != 0)
            {
              cout << "cp: cannot stat '" << to_path_file << "': Permission denied" << endl;
              break;
            }
            if(access(to_path_file.c_str(), W_OK) != 0)
            {
              cout << "cp: cannot create regular file '" << from_path_file << "': Permission denied" << endl;
              break;
            }
            FILE* fp2 = fopen(to_path_file.c_str(), "w");
            char ch;
            ch = fgetc(fp1);
            while(!feof(fp1))
            {
              fputc(ch, fp2);
              ch = fgetc(fp1);
            }
            fclose(fp1);
            fclose(fp2);
            /*chmod(to_path_file.c_str(), 777);
            struct stat statbuf1;
            lstat(from_path_file.c_str(), &statbuf1);
            chmod(to_path_file.c_str(), statbuf1.st_mode&ALLPERMS);//保证文件权限不变*/
            break;
          }
          if(!strcmp(file1->d_name, file3->d_name) && file1->d_type == DT_DIR && file3->d_type == DT_DIR)//dir3中有目录file3与目录file1同名，则递归调用函数dir_copy
          {
            string from_path_file;
            from_path_file = file1->d_name;
            from_path_file = from_path + '/' + from_path_file;
            string to_path_file;
            //to_path_file = file1->d_name;
            //to_path_file = to_path_directory + '/' + to_path_file;
            string to_path_directory_directory_name;
            to_path_directory_directory_name = file1->d_name;
            if(access(from_path.c_str(), X_OK) != 0)
            {
              cout << "cp: cannot stat '" << from_path_file << "': Permission denied" << endl;
              break;
            }
            dir_copy(from_path_file, to_path_directory, to_path_directory_directory_name);
            break;
          }
        }
        rewinddir(dir3);//将dir3指针重置到目录开头
      }
      closedir(dir3);
      break;
    }
  }
  closedir(dir1);
  closedir(dir2);
  return true;
}

bool directory_copy(string from_path, string to_path, string to_path_directory_name)
{
  if(access(from_path.c_str(), R_OK) != 0)
  {
    cout << "cp: cannot access '" << from_path << "': Permission denied" << endl;
    return false;
  }
  DIR* dir1 = opendir(from_path.c_str());
  dirent* file1;
  string to_path_directory;
  to_path_directory = to_path + '/' + to_path_directory_name;
  if(access(to_path.c_str(), X_OK) != 0)
  {
    cout << "cp: cannot stat '" << to_path_directory << "': Permission denied" << endl;
    closedir(dir1);
    return false;
  }
  mkdir(to_path_directory.c_str(), S_IRWXU|S_IRWXG|S_IRWXO);
  DIR* dir2 = opendir(to_path_directory.c_str());
  dirent* file2;
  while(file1 = readdir(dir1))
  {
    if(!strcmp(file1->d_name, ".") || !strcmp(file1->d_name, ".."))//当前目录"."或上一级目录".."，不进行复制
      continue;
    string from_path_file;
    from_path_file = file1->d_name;
    from_path_file = from_path + '/' + from_path_file;
    if(file1->d_type == DT_DIR)//file1为目录，则创建与file1同名的目录
    {
      string to_path_directory_directory_name;
      to_path_directory_directory_name = file1->d_name;
      if(access(from_path.c_str(), X_OK) != 0)
      {
        cout << "cp: cannot stat '" << from_path_file << "': Permission denied" << endl;
        continue;
      }
      directory_copy(from_path_file, to_path_directory, to_path_directory_directory_name);//递归调用函数directory_copy
    }
    else//file1为文件，则创建与file1同名的文件
    {
      string to_path_file;
      to_path_file = file1->d_name;
      to_path_file = to_path_directory + '/' + to_path_file;
      if(access(from_path.c_str(), X_OK) != 0)
      {
        cout << "cp: cannot stat '" << from_path_file << "': Permission denied" << endl;
        continue;
      }
      if(access(from_path_file.c_str(), R_OK) != 0)
      {
        cout << "cp: cannot open '" << from_path_file << "' for reading: Permission denied" << endl;
        continue;
      }
      FILE* fp1 = fopen(from_path_file.c_str(), "r");
      if(access(to_path_directory.c_str(), X_OK) != 0)
      {
        cout << "cp: cannot stat '" << to_path_file << "': Permission denied" << endl;
        fclose(fp1);
        continue;
      }
      FILE* fp2 = fopen(to_path_file.c_str(), "w");
      char ch;
      ch = fgetc(fp1);
      while(!feof(fp1))
      {
        fputc(ch, fp2);
        ch = fgetc(fp1);
      }
      fclose(fp1);
      fclose(fp2);
      chmod(to_path_file.c_str(), 777);
      struct stat statbuf1;
      lstat(from_path_file.c_str(), &statbuf1);
      chmod(to_path_file.c_str(), statbuf1.st_mode&ALLPERMS);//保证文件权限不变
    }
  }
  closedir(dir1);
  closedir(dir2);
  struct stat statbuf;
  lstat(from_path.c_str(), &statbuf);
  chmod(to_path_directory.c_str(), statbuf.st_mode&ALLPERMS);//保证目录权限不变
  return true;
}
