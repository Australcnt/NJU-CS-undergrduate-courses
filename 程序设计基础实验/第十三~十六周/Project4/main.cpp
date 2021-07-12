#include "main.h"
#include "function.h"

int main()
{
  begin();
}

void begin()
{
  while(1)
  {
    option_bar();
    cout << "请选择:";
    int option = 0;
    cin >> option;
    if(all_polynomial.empty() && option != 1 && option != 8)
    {
      cout << "请先输入多项式，然后才能进行其他操作！" << endl << endl;
      continue;
    }
    switch(option)
    {
      case 1: polynomial_typein(); break;
      case 2: hybrid_operation(); break;
      case 3: inverse_operation(); break;
      case 4: divide_operation(); break;
      case 5: root_extract(); break;
      case 6: evaluate_operation(); break;
      case 7: polynomial_typeout(); break;
      case 8: exit(0);
      default: cout << "您输入的选项不正确，请重新选择!" << endl << endl;
    }
  }
}

void option_bar()
{
  for(int i = 0; i < 69; i++)
  {
    if(i == 33)
      cout << "多项式计算器";
    else
      cout << "=";
  }
  cout << endl;
  for(int j = 0; j < 24; j++)
  {
    if(j == 1)
      cout << "1.输入";
    else if(j == 4)
      cout << "2.混合运算";
    else if(j == 7)
      cout << "3.求逆元";
    else if(j == 10)
      cout << "4.除法/取模运算";
    else if(j == 13)
      cout << "5.求根";
    else if(j == 16)
      cout << "6.求值";
    else if(j == 19)
      cout << "7.输出";
    else if(j == 22)
      cout << "8.退出";
    else
      cout << " ";
  }
  cout << endl;
  for(int k = 0; k < 80; k++)
    cout << "=";
  cout << endl << endl;
}



























