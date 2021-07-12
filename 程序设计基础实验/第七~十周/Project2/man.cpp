#include "main.h"
#include "man.h"

void all_man()
{
  if(!cmd3.empty() || (cmd2 != "cp" &&  cmd2 != "cmp" &&  cmd2 != "wc" &&  cmd2 != "cat" &&  cmd2 != "man" && cmd2 != "sh"))
    man_format_check();
  else if(cmd2 == "cp")
  {
    FILE* fp1 = fopen("./man/man_cp.txt", "r");
    if(fp1 == NULL)
    {
      cout << "fail to open man_cp.txt" << endl;
      myshell();
    }
    char man_cp[200];
    fgets(man_cp,199,fp1);
    while(!feof(fp1))
    {
      cout << man_cp;
      fgets(man_cp,199,fp1);
    }
    fclose(fp1);
    myshell();
  }
  else if(cmd2 == "cmp")
  {
    FILE* fp2 = fopen("./man/man_cmp.txt", "r");
    if(fp2 == NULL)
    {
      cout << "fail to open man_cmp.txt" << endl;
      myshell();
    }
    char man_cmp[200];
    fgets(man_cmp,199,fp2);
    while(!feof(fp2))
    {
      cout << man_cmp;
      fgets(man_cmp,199,fp2);
    }
    fclose(fp2);
    myshell();
  }
  else if(cmd2 == "cp")
  {
    FILE* fp3 = fopen("./man/man_wc.txt", "r");
    if(fp3 == NULL)
    {
      cout << "fail to open man_wc.txt" << endl;
      myshell();
    }
    char man_wc[200];
    fgets(man_wc,199,fp3);
    while(!feof(fp3))
    {
      cout << man_wc;
      fgets(man_wc,199,fp3);
    }
    fclose(fp3);
    myshell();
  }
  else if(cmd2 == "cat")
  {
    FILE* fp4 = fopen("./man/man_cat.txt", "r");
    if(fp4 == NULL)
    {
      cout << "fail to open man_cat.txt" << endl;
      myshell();
    }
    char man_cat[200];
    fgets(man_cat,199,fp4);
    while(!feof(fp4))
    {
      cout << man_cat;
      fgets(man_cat,199,fp4);
    }
    fclose(fp4);
    myshell();
  }
  else if(cmd2 == "man")
  {
    FILE* fp5 = fopen("./man/man_man.txt", "r");
    if(fp5 == NULL)
    {
      cout << "fail to open man_man.txt" << endl;
      myshell();
    }
    char man_man[200];
    fgets(man_man,199,fp5);
    while(!feof(fp5))
    {
      cout << man_man;
      fgets(man_man,199,fp5);
    }
    fclose(fp5);
    myshell();
  }
  else if(cmd2 == "sh")
  {
    FILE* fp8 = fopen("./man/man_sh.txt", "r");
    if(fp8 == NULL)
    {
      cout << "fail to open man_sh.txt" << endl;
      myshell();
    }
    char man_sh[200];
    fgets(man_sh,199,fp8);
    while(!feof(fp8))
    {
      cout << man_sh;
      fgets(man_sh,199,fp8);
    }
    fclose(fp8);
    myshell();
  }
}

void man_format_check()
{
  if(!cmd3.empty())
  {
    cout << "This situation is not implemented!" << endl;
    myshell();
  }
  if(cmd2 == "--help" || cmd2 == "--hel" || cmd2 == "--he" || cmd2 == "-help" || cmd2 == "-hel" || cmd2 == "-he")
  {
    FILE* fp6 = fopen("./help/man_help.txt", "r");
    if(fp6 == NULL)
    {
      cout << "fail to open man_help.txt" << endl;
      myshell();
    }
    char man_help[200];
    fgets(man_help,199,fp6);
    while(!feof(fp6))
    {
      cout << man_help;
      fgets(man_help,199,fp6);
    }
    fclose(fp6);
    myshell();
  }
  if(cmd2 == "--usage" || cmd2 == "--usag" || cmd2 == "--usa" || cmd2 == "--us")
  {
    FILE* fp7 = fopen("./help/man_usage.txt", "r");
    if(fp7 == NULL)
    {
      cout << "fail to open man_help.txt" << endl;
      myshell();
    }
    char man_usage[200];
    fgets(man_usage,199,fp7);
    while(!feof(fp7))
    {
      cout << man_usage;
      fgets(man_usage,199,fp7);
    }
    fclose(fp7);
    myshell();
  }
  if(cmd2.empty())
  {
    cout << "What manual page do you want?" << endl;
    myshell();
  }
  if(cmd2[0] == '-')
  {
    if(cmd2[3] || (cmd2[1] == '-' && cmd2[2] == '-'))
    {
      cout << "man: unrecognized option '" << cmd2 << "'" << endl;
      cout << "Try 'man --help' or 'man --usage' for more information" << endl;
      myshell();
    }
    else if((cmd2[1] && cmd2[1] != '-') || (cmd2[1] == '-' && !cmd2[2]))
    {
      cout << "What manual page do you want?" << endl;
      myshell();
    }
    else if(cmd2[1] == '-' && cmd2[2] >= 'a' && cmd2[2] <= 'z')
    {
      if(cmd2[2] == 'a')
      {
        cout << "man: option '--a' is ambiguous; possibilities: '--apropos' '--ascii' '--all'" << endl;
        cout << "Try 'man --help' or 'man --usage' for more information." << endl;
        myshell();
      }
      if(cmd2[2] == 'b')
      {
        cout << "man: unrecognized option '--b'" << endl;
        cout << "Try 'man --help' or 'man --usage' for more information." << endl;
        myshell();
      }
      if(cmd2[2] == 'c')
      {
        cout << "man: option '--c' is ambiguous; possibilities: '--config-file' '--catman'" << endl;
        cout << "Try 'man --help' or 'man --usage' for more information." << endl;
        myshell();
      }
      if(cmd2[2] == 'd')
      {
        cout << "man: option '--d' is ambiguous; possibilities: '--debug' '--ditroff' '--default'" << endl;
        cout << "Try 'man --help' or 'man --usage' for more information." << endl;
        myshell();
      }
      if(cmd2[2] == 'e')
      {
        cout << "man: option '--e' is ambiguous; possibilities: '--extension' '--encoding'" << endl;
        cout << "Try 'man --help' or 'man --usage' for more information." << endl;
        myshell();
      }
      if(cmd2[2] == 'f')
      {
        cout << "man: unrecognized option '--f'" << endl;
        cout << "Try 'man --help' or 'man --usage' for more information." << endl;
        myshell();
      }
      if(cmd2[2] == 'g')
      {
        cout << "man: option '--g' is ambiguous; possibilities: '--global-apropos' '--gxditview'" << endl;
        cout << "Try 'man --help' or 'man --usage' for more information." << endl;
        myshell();
      }
      if(cmd2[2] == 'h')
      {
        cout << "man: option '--h' is ambiguous; possibilities: '--html' '--help'" << endl;
        cout << "Try 'man --help' or 'man --usage' for more information." << endl;
        myshell();
      }
      if(cmd2[2] == 'i')
      {
        cout << "What manual page do you want?" << endl;
        myshell();
      }
      if(cmd2[2] == 'j')
      {
        cout << "man: unrecognized option '--j'" << endl;
        cout << "Try 'man --help' or 'man --usage' for more information." << endl;
        myshell();
      }
      if(cmd2[2] == 'k')
      {
        cout << "man: unrecognized option '--k'" << endl;
        cout << "Try 'man --help' or 'man --usage' for more information." << endl;
        myshell();
      }
      if(cmd2[2] == 'l')
      {
        cout << "man: option '--l' is ambiguous; possibilities: '--location' '--locale' '--local-file' '--location-cat'" << endl;
        cout << "Try 'man --help' or 'man --usage' for more information." << endl;
        myshell();
      }
      if(cmd2[2] == 'm')
      {
        cout << "man: option '--m' is ambiguous; possibilities: '--manpath' '--match-case'" << endl;
        cout << "Try 'man --help' or 'man --usage' for more information." << endl;
        myshell();
      }
      if(cmd2[2] == 'n')
      {
        cout << "man: option '--n' is ambiguous; possibilities: '--names-only' '--nj' '--no-justification' '--nh' '--no-hyphenation' '--no-subpages'" << endl;
        cout << "Try 'man --help' or 'man --usage' for more information." << endl;
        myshell();
      }
      if(cmd2[2] == 'o')
      {
        cout << "man: unrecognized option '--o'" << endl;
        cout << "Try 'man --help' or 'man --usage' for more information." << endl;
        myshell();
      }
      if(cmd2[2] == 'p')
      {
        cout << "man: option '--p' is ambiguous; possibilities: '--path' '--program-name' '--preprocessor' '--prompt' '--pager'" << endl;
        cout << "Try 'man --help' or 'man --usage' for more information." << endl;
        myshell();
      }
      if(cmd2[2] == 'q')
      {
        cout << "man: unrecognized option '--q'" << endl;
        cout << "Try 'man --help' or 'man --usage' for more information." << endl;
        myshell();
      }
      if(cmd2[2] == 'r')
      {
        cout << "man: option '--r' is ambiguous; possibilities: '--recode' '--regex'" << endl;
        cout << "Try 'man --help' or 'man --usage' for more information." << endl;
        myshell();
      }
      if(cmd2[2] == 's')
      {
        cout << "man: option '--s' is ambiguous; possibilities: '--systems' '--sections'" << endl;
        cout << "Try 'man --help' or 'man --usage' for more information." << endl;
        myshell();
      }
      if(cmd2[2] == 't')
      {
        cout << "man: option '--t' is ambiguous; possibilities: '--troff' '--troff-device'" << endl;
        cout << "Try 'man --help' or 'man --usage' for more information." << endl;
        myshell();
      }
      if(cmd2[2] == 'u')
      {
        cout << "man: option '--u' is ambiguous; possibilities: '--update' '--usage'" << endl;
        cout << "Try 'man --help' or 'man --usage' for more information." << endl;
        myshell();
      }
      if(cmd2[2] == 'v')
      {
        cout << "man 2.7.5" << endl;
        myshell();
      }
      if(cmd2[2] == 'w')
      {
        cout << "man: option '--w' is ambiguous; possibilities: '--warnings' '--wildcard' '--where-cat' '--where' '--whatis'" << endl;
        cout << "Try 'man --help' or 'man --usage' for more information." << endl;
        myshell();
      }
      if(cmd2[2] == 'x')
      {
        cout << "man: unrecognized option '--x'" << endl;
        cout << "Try 'man --help' or 'man --usage' for more information." << endl;
        myshell();
      }
      if(cmd2[2] == 'y')
      {
        cout << "man: unrecognized option '--y'" << endl;
        cout << "Try 'man --help' or 'man --usage' for more information." << endl;
        myshell();
      }
      if(cmd2[2] == 'z')
      {
        cout << "man: unrecognized option '--z'" << endl;
        cout << "Try 'man --help' or 'man --usage' for more information." << endl;
        myshell();
      }
    }
    else if(cmd2[1] == '-')
    {
      cout << "man: unrecognized option '" << cmd2 << "'" << endl;
      cout << "Try 'man --help' or 'man --usage' for more information." << endl;
      myshell();
    }
    else
    {
      cout << "No manual entry for " << cmd2 << endl;
      myshell();
    }
  }
  else
  {
    cout << "No manual entry for " << cmd2 << endl;
    myshell();
  }
}
