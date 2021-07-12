#include "main.h"
#include "function.h"

vector<Node> all_polynomial;//输入的所有多项式

//****************************************************主功能函数********************************************************

void polynomial_typein()//多项式输入
{
  cout << "多项式长度：";
  int length = 0;
  cin >> length;
  if(length <= 0)
  {
    cout << "多项式长度必须为正数！请重新输入！" << endl << endl;
    polynomial_typein();
  }
  if(length > 50)
  {
    cout << "多项式长度不能超过50！请重新输入！" << endl << endl;
    polynomial_typein();
  }
  cout << "多项式系数(从高位到低位,用空格隔开)：";
  //cin.sync();
  //fflush(stdin);
  getchar();//清空输入流中残存的回车，不然getline读不到内容
  string str;
  getline(cin, str);
  istringstream all_coefficient(str);
  Node current_polynomial;
  memset(current_polynomial.polynomial, 0, sizeof(current_polynomial.polynomial));
  current_polynomial.length = length;
  for(int i = length - 1; i >= 0; i--)
  {
    all_coefficient >> current_polynomial.polynomial[i];
    //cout << current_polynomial.polynomial[i] << endl;
  }
  for(int j = length -1 ; j >= 0; j--)//多项式头部系数是否为0
  {
    if(current_polynomial.polynomial[j] != 0)
      break;
    current_polynomial.length--;
  }
  //cout << current_polynomial.length << endl;
  if(current_polynomial.length == 0)//多项式系数是否全部为0
  {
    cout << "多项式系数不能全为0！请重新输入！" << endl << endl;
    polynomial_typein();
  }
  cout << "多项式名：";
  string name;
  cin >> name;
  while(name.empty())//多项式名是否为空
  {
    cout << "多项式名不能为空！请重新输入！" << endl;
    cout << "多项式名：";
    cin >> name;
  }
  while(!polynomial_check(name))//多项式名是否重复
  {
    cout << "不能输入重复的多项式名！请重新输入！" << endl;
    cout << "多项式名：";
    cin >> name;
  }
  current_polynomial.name = name;
  all_polynomial.push_back(current_polynomial);
  cout << "输入成功，是否继续输入？（y/n）：";
  string choice;
  cin >> choice;
  while(choice != "n")//选择是否正确
  {
    if(choice == "y")
    {
      cout << endl;
      polynomial_typein();
    }
    else if(choice != "n")
    {
      cout << "你输入的选择不正确，请重新输入！" << endl;
      cout << "是否继续输入？（y/n）：";
      cin >> choice;
    }
  }
  cout << endl;
  begin();
}

void hybrid_operation()//多项式混合运算
{
  cout << "是否先展示输入规则（1、是 2、否）：";
  string choice;
  cin >> choice;
  while(choice != "2")//选择是否正确
  {
    if(choice == "1")
    {
      cout << "输入规则：" << endl;
      cout << "1、以多项式名、左括号、定积分符开头，以右括号、多项式名、求导符结尾" << endl;
      cout << "2、加法、乘法、减法、除法后面只能是多项式名、左括号、定积分符号" << endl;
      cout << "3、定积分符号后只能接 区间 + 左括号/多项式名，区间采用[a,b]固定格式，且a<b" << endl;
      cout << "4、求导符号后面只能为双目运算符、右括号" << endl;
      cout << "5、括号要匹配，左括号后面只能是左括号、定积分符号或多项式名，右括号后面只能是右括号，双目运算符或求导符号" << endl;
      cout << "6、多项式名后面只能是双目运算符、求导符或右括号" << endl;
      cout << "7、左括号数目应与右括号数目必须相等，且扫描过程中左括号数目不能小于右括号数目" << endl;
      cout << "8、多项式必须存在" << endl;
      break;
    }
    else if(choice != "2")
    {
      cout << "你输入的选择不正确，请重新输入！" << endl;
      cout << "是否先展示输入规则（1、是 2、否）：";
      cin >> choice;
    }
  }
  cout << endl;
  cout << "请输入表达式：";
  string expression;
  cin >> expression;
  if(!expression_format_check(expression))
  {
    cout << "您输入的表达式不合法！请重新输入！" << endl;
    hybrid_operation();
  }
  stack<string> operators;//运算符
  deque<string> postfix_expression;//后缀表达式
  stack<Node> forming_polynomial;//生成的新多项式
  vector<Node> temporary_polynomial;//暂时生成的多项式
  //缺少将表达式用空格隔开的操作
  //将表达式转为后缀表达式，用双端队列postfix_expression储存
  for(int ix = 0; ix != expression.size(); ++ix)
  {
    if(expression[ix] == '*' || expression[ix] == '+' || expression[ix] == '/' || expression[ix] == '-' || expression[ix] == '!' || expression[ix] == '$' || expression[ix] == '(')//对象是运算符
    {
      string current_operator;
      current_operator = expression[ix];
      if(!operators.empty() && expression[ix] != '(')//栈非空
      {
        string previous_operator;
        previous_operator = operators.top();
        while(priority(current_operator) <= priority(previous_operator))//当前运算符与栈顶运算符的优先级比较
        {
          previous_operator = operators.top();
          operators.pop();
          postfix_expression.push_back(previous_operator);
          if(operators.empty())
            break;
        }
      }
      if(expression[ix] == '$')
      {
        ++ix;
        while(expression[ix] != ']')
        {
          current_operator = current_operator + expression[ix];
          ++ix;
        }
        current_operator = current_operator + expression[ix];
      }
      operators.push(current_operator);
    }
    else if(expression[ix] == ')')
    {
      string previous_operator;
      while(!operators.empty())
      {
        if(operators.top() == "(")
        {
          operators.pop();
          break;
        }
        previous_operator = operators.top();
        operators.pop();
        postfix_expression.push_back(previous_operator);
      }
    }
    else//对象是多项式名
    {
      string current_name;
      current_name = expression[ix];
      if(ix != expression.size() - 1 && expression[ix + 1] != '*' && expression[ix + 1] != '+' && expression[ix + 1] != '/' && expression[ix + 1] != '-' && expression[ix + 1] != '!' && expression[ix + 1] != '$' && expression[ix + 1] != '(' && expression[ix + 1] != ')')
      {
        ++ix;
        while(ix != expression.size() && expression[ix] != '*' && expression[ix] != '+' && expression[ix] != '/' && expression[ix] != '-' && expression[ix] != '!' && expression[ix] != '$' && expression[ix] != '(' && expression[ix] != ')')
        {
          current_name = current_name + expression[ix];
          ++ix;
        }
        --ix;
      }
      postfix_expression.push_back(current_name);
    }
    if(ix == expression.size() - 1)
      while(!operators.empty())
      {
        postfix_expression.push_back(operators.top());
        operators.pop();
      }
  }
  //后缀表达式求值
  while(!postfix_expression.empty())
  {
    string current_object;
    current_object = postfix_expression.front();
    postfix_expression.pop_front();
    if(current_object == "+")
    {
      Node polynomial_1, polynomial_2;
      polynomial_2 = forming_polynomial.top();
      forming_polynomial.pop();
      polynomial_1 = forming_polynomial.top();
      forming_polynomial.pop();
      Node new_polynomial;
      new_polynomial = addition(polynomial_1, polynomial_2);
      temporary_polynomial.push_back(new_polynomial);
      forming_polynomial.push(new_polynomial);
    }
    else if(current_object == "*")
    {
      Node polynomial_1, polynomial_2;
      polynomial_2 = forming_polynomial.top();
      forming_polynomial.pop();
      polynomial_1 = forming_polynomial.top();
      forming_polynomial.pop();
      Node new_polynomial;
      new_polynomial = multiplication(polynomial_1, polynomial_2);
      temporary_polynomial.push_back(new_polynomial);
      forming_polynomial.push(new_polynomial);
    }
    else if(current_object == "-")
    {
      Node polynomial_1, polynomial_2;
      polynomial_2 = forming_polynomial.top();
      forming_polynomial.pop();
      polynomial_1 = forming_polynomial.top();
      forming_polynomial.pop();
      Node new_polynomial;
      new_polynomial = subtraction(polynomial_1, polynomial_2);
      temporary_polynomial.push_back(new_polynomial);
      forming_polynomial.push(new_polynomial);
    }
    else if(current_object == "/")
    {
      Node polynomial_1, polynomial_2;
      polynomial_2 = forming_polynomial.top();
      forming_polynomial.pop();
      polynomial_1 = forming_polynomial.top();
      forming_polynomial.pop();
      if(polynomial_2.length == 1 && polynomial_2.polynomial[0] == 0)
      {
        cout << "除数不能为0！运算失败！" << endl;
        cout << "是否继续运算？（y/n）：";
        string choice3;
        cin >> choice3;
        while(choice3 != "n")//选择是否正确
        {
          if(choice3 == "y")
          {
            cout << endl;
            hybrid_operation();
          }
          else if(choice3 != "n")
          {
            cout << "您输入的选择不正确！请重新输入！" << endl;
            cout << "是否继续运算？（y/n）：";
            cin >> choice3;
          }
        }
        cout << endl << endl;
        begin();
      }
      Node new_polynomial;
      new_polynomial = quotient(polynomial_1, polynomial_2);
      temporary_polynomial.push_back(new_polynomial);
      forming_polynomial.push(new_polynomial);
    }
    else if(current_object == "!")
    {
      Node polynomial_1;
      polynomial_1 = forming_polynomial.top();
      forming_polynomial.pop();
      Node new_polynomial;
      new_polynomial = derivation(polynomial_1);
      temporary_polynomial.push_back(new_polynomial);
      forming_polynomial.push(new_polynomial);
    }
    else if(current_object[0] == '$')
    {
      string lower_bound, upper_bound;
      lower_bound = current_object[2];
      string::size_type ix = 3;
      while(current_object[ix] != ',')
      {
        lower_bound = lower_bound + current_object[ix];
        ++ix;
      }
      ++ix;
      upper_bound = current_object[ix];
      ++ix;
      while(current_object[ix] != ']')
      {
        upper_bound = upper_bound + current_object[ix];
        ++ix;
      }
      Node polynomial_1;
      polynomial_1 = forming_polynomial.top();
      forming_polynomial.pop();
      Node new_polynomial;
      new_polynomial = definite_integral(polynomial_1, atof(lower_bound.c_str()), atof(upper_bound.c_str()));
      temporary_polynomial.push_back(new_polynomial);
      forming_polynomial.push(new_polynomial);
    }
    else
    {
      Node new_polynomial;
      for(vector<Node>::iterator it = all_polynomial.begin(); it != all_polynomial.end(); ++it)
      {
        if((*it).name == current_object)
        {
          new_polynomial =*it;
          break;
        }
      }
      forming_polynomial.push(new_polynomial);
    }
  }
  Node result_polynomial;
  result_polynomial = forming_polynomial.top();
  cout << expression << " = ";
  coefficient_to_polynomial(result_polynomial);
  cout << endl;
  cout << "运算成功，是否继续运算？（y/n）：";
  string choice2;
  cin >> choice2;
  while(choice2 != "n")//选择是否正确
  {
    if(choice2 == "y")
    {
      cout << endl;
      hybrid_operation();
    }
    else if(choice2 != "n")
    {
      cout << "您输入的选择不正确！请重新输入！" << endl;
      cout << "是否继续运算？（y/n）：";
      cin >> choice2;
    }
  }
  cout << endl << endl;
  begin();
}

void inverse_operation()//多项式求逆
{
  cout << "请输入您的选择（1、狭义求逆 2、广义求逆 3、概念辨析）：";
  string choice;
  cin >> choice;
  while(choice != "1" && choice != "2")//选择是否正确
  {
    if(choice == "3")
    {
      cout << "两组概念：" << endl;
      cout << "狭义求逆：F(x)*G(x) ≡ 1 (mod x^n), n为F(x)最高项次数加一" << endl;
      cout << "广义求逆：F(x)*G(x) ≡ 1 (mod x^m), m为任意正整数" << endl << endl;
      cout << "请输入您的选择（1、狭义求逆 2、广义求逆 3、退出）：";
      cin >> choice;
      while(choice != "1" && choice != "2" && choice != "3")
      {
        cout << "您输入的选择不正确！请重新输入！" << endl;
        cout << "请输入您的选择（1、狭义求逆 2、广义求逆 3、退出）：";
        cin >> choice;
      }
      if(choice == "1" || choice == "2")
        break;
      else
      {
        cout << endl;
        begin();
      }
    }
    else if(choice != "1" && choice != "2")
    {
      cout << "您输入的选择不正确！请重新输入！" << endl;
      cout << "请输入您的选择（1、狭义求逆 2、广义求逆 3、概念辨析）：";
      cin >> choice;
    }
  }
  if(choice == "1")
    special_inverse_operation();
  else
    generalized_inverse_operation();
}

void divide_operation()//多项式除法/取模
{
  Node dividend_polynomial;
  Node divisor_polynomial;
  cout << "请输入被除数的多项式名：";
  cin >> dividend_polynomial.name;
  while(polynomial_check(dividend_polynomial.name))//被除数的多项式是否存在
  {
    cout << "您输入的被除数的多项式不存在！请重新输入！" << endl;
    cout << "请输入被除数的多项式名：";
    cin >> dividend_polynomial.name;
  }
  for(vector<Node>::iterator it = all_polynomial.begin(); it != all_polynomial.end(); ++it)
    if((*it).name == dividend_polynomial.name)
      dividend_polynomial = *it;
  cout << "请输入除数的多项式名：";
  cin >> divisor_polynomial.name;
  while(polynomial_check(divisor_polynomial.name))//除数的多项式是否存在
  {
    cout << "您输入的被除数的多项式不存在！请重新输入！" << endl;
    cout << "请输入被除数多项式名：";
    cin >> divisor_polynomial.name;
  }
  for(vector<Node>::iterator it = all_polynomial.begin(); it != all_polynomial.end(); ++it)
    if((*it).name == divisor_polynomial.name)
      divisor_polynomial = *it;
  if(divisor_polynomial.length == 1 && divisor_polynomial.polynomial[0] == 0)//除数是否为0
  {
    cout << "除数不能为0！运算失败！" << endl << endl;
    begin();
  }
  Node quotient_polynomial;
  Node remainder_polynomial;
  quotient_polynomial = quotient(dividend_polynomial, divisor_polynomial);
  remainder_polynomial = remainder(dividend_polynomial, divisor_polynomial);
  cout << "商为：";
  coefficient_to_polynomial(quotient_polynomial);
  cout << endl;
  cout << "余数为：";
  coefficient_to_polynomial(remainder_polynomial);
  cout << endl;
  cout << "运算成功！是否继续输入？（y/n）：";
  string choice;
  cin >> choice;
  while(choice != "n")//选择是否正确
  {
    if(choice == "y")
    {
      cout << endl;
      divide_operation();
    }
    else if(choice != "n")
    {
      cout << "你输入的选择不正确，请重新输入！" << endl;
      cout << "是否继续输入？（y/n）：";
      cin >> choice;
    }
  }
  cout << endl;
  begin();
}

void root_extract()//多项式求根
{
  cout << "多项式名：";
  string name;
  cin >> name;
  while(name.empty())//多项式名是否为空
  {
    cout << "多项式名不能为空！请重新输入！" << endl;
    cout << "多项式名：";
    cin >> name;
  }
  while(polynomial_check(name))//多项式名是否存在
  {
    cout << "您输入的多项式名不存在！请重新输入！" << endl;
    cout << "多项式名：";
    cin >> name;
  }
  Node current_polynomial;
  for(vector<Node>::iterator it = all_polynomial.begin(); it != all_polynomial.end(); ++it)
    if((*it).name == name)
      current_polynomial = *it;
  Node root_polynomial;
  root_polynomial = root_extraction(current_polynomial);//不考虑无根的情况
  cout << current_polynomial.name << "存在实数根为： x = " << root_polynomial.polynomial[0] << endl;
  cout << "运算成功！是否继续输入？（y/n）：";
  string choice;
  cin >> choice;
  while(choice != "n")//选择是否正确
  {
    if(choice == "y")
    {
      cout << endl;
      root_extract();
    }
    else if(choice != "n")
    {
      cout << "你输入的选择不正确，请重新输入！" << endl;
      cout << "是否继续输入？（y/n）：";
      cin >> choice;
    }
  }
  cout << endl;
  begin();
}

void evaluate_operation()
{
  cout << "多项式名：";
  string name;
  cin >> name;
  while(name.empty())//多项式名是否为空
  {
    cout << "多项式名不能为空！请重新输入！" << endl;
    cout << "多项式名：";
    cin >> name;
  }
  while(polynomial_check(name))//多项式名是否存在
  {
    cout << "您输入的多项式名不存在！请重新输入！" << endl;
    cout << "多项式名：";
    cin >> name;
  }
  Node current_polynomial;
  for(vector<Node>::iterator it = all_polynomial.begin(); it != all_polynomial.end(); ++it)
    if((*it).name == name)
      current_polynomial = *it;
  cout << "x的值：";
  double x0 = 0;
  cin >> x0;
  Node evaluation_polynomial;
  evaluation_polynomial = evaluation(current_polynomial, x0);
  cout << current_polynomial.name << "在 x = " << x0 << " 处的值为：" << evaluation_polynomial.polynomial[0] << endl;
  cout << "运算成功！是否继续输入？（y/n）：";
  string choice;
  cin >> choice;
  while(choice != "n")//选择是否正确
  {
    if(choice == "y")
    {
      cout << endl;
      evaluate_operation();
    }
    else if(choice != "n")
    {
      cout << "你输入的选择不正确，请重新输入！" << endl;
      cout << "是否继续输入？（y/n）：";
      cin >> choice;
    }
  }
  cout << endl;
  begin();
}

void polynomial_typeout()//多项式输出
{
  cout << "请输入您的选择（1、单个多项式  2、所有多项式）：";
  string choice;
  cin >> choice;
  if(choice == "1")
    single_polynomial_typeout();
  else if(choice == "2")
    all_polynomial_typeout();
  else
  {
    cout << "您输入的选择不正确！请重新输入！" << endl;
    polynomial_typeout();
  }
  begin();
}

//*****************************************************辅助函数*********************************************************

bool polynomial_check(string name)//多项式名是否重复
{
  for(vector<Node>::iterator it = all_polynomial.begin(); it != all_polynomial.end(); ++it)
    if((*it).name == name)
      return false;
  return true;
}

void single_polynomial_typeout()//单个多项式输出
{
  cout << "多项式名：";
  string name;
  cin >> name;
  Node current_polynomial;
  vector<Node>::iterator it = all_polynomial.begin();
  while(1)
  {
    if((*it).name == name)
      break;
    ++it;
    if(it == all_polynomial.end())
    {
      cout << "您输入的多项式名不存在！请重新输入！" << endl;
      single_polynomial_typeout();
    }
  }
  current_polynomial = *it;
  cout << current_polynomial.name << " =";
  for(int i = current_polynomial.length - 1; i >= 0; i--)
  {
    if(fabs(current_polynomial.polynomial[i] - 1) < 1e-7)//系数为1
    {
      if(i != current_polynomial.length - 1)
        cout << " +";
      if(i == 1)
        cout << " " << "x";
      else if(i == 0)
        cout << " 1" ;
      else
        cout << " " << "x^" << i;
    }
    else if(fabs(current_polynomial.polynomial[i] + 1) < 1e-7)//系数为-1
    {
      if(i == current_polynomial.length - 1)
      {
        if(i == 1)
          cout << " -" << "x";
        else if(i == 0)
          cout << " -1" ;
        else
          cout << " -" << "x^" << i;
      }
      else
      {
        if(i != current_polynomial.length - 1)
          cout << " -";
        if(i == 1)
          cout << " " << "x";
        else if(i == 0)
          cout << " 1" ;
        else
          cout << " " << "x^" << i;
      }
    }
    else if(fabs(current_polynomial.polynomial[i] - 0) < 1e-7)//系数为0
    {
      if(current_polynomial.length == 1)
        cout << " 0";
      else
        continue;
    }
    else if(current_polynomial.polynomial[i] - 0 >= 1e-7)//系数为正数，且不为1
    {
      if(i != current_polynomial.length - 1)
        cout << " +";
      if(i == 1)
        cout << " " << current_polynomial.polynomial[i] << "x";
      else if(i == 0)
        cout << " " << current_polynomial.polynomial[i];
      else
        cout << " " << current_polynomial.polynomial[i] << "x^" << i;
    }
    else//系数为负数，且不为-1
    {
      if(i == current_polynomial.length - 1)
      {
        if(i == 1)
          cout << " " << current_polynomial.polynomial[i] << "x";
        else if(i == 0)
          cout << " " << current_polynomial.polynomial[i];
        else
          cout << " " << current_polynomial.polynomial[i] << "x^" << i;
      }
      else
      {
        if(i != current_polynomial.length - 1)
          cout << " -";
        if(i == 1)
          cout << " " << fabs(current_polynomial.polynomial[i]) << "x";
        else if(i == 0)
          cout << " " << fabs(current_polynomial.polynomial[i]);
        else
          cout << " " << fabs(current_polynomial.polynomial[i]) << "x^" << i;
      }
    }
  }
  cout << endl;
  cout << "输出成功，是否继续输出？（y/n）：";
  string choice;
  cin >> choice;
  while(choice != "n")//选择是否正确
  {
    if(choice == "y")
    {
      cout << endl;
      single_polynomial_typeout();
    }
    else if(choice != "n")
    {
      cout << "你输入的选择不正确，请重新输入！" << endl;
      cout << "是否继续输出？（y/n）：";
      cin >> choice;
    }
  }
  cout << endl;
  begin();
}
    
void all_polynomial_typeout()//所有多项式输出
{
  for(vector<Node>::iterator it = all_polynomial.begin(); it != all_polynomial.end(); ++it)
  {
    Node current_polynomial;
    current_polynomial = *it;
    cout << current_polynomial.name << " =";
    for(int i = current_polynomial.length - 1; i >= 0; i--)
    {
      if(fabs(current_polynomial.polynomial[i] - 1) < 1e-7)//系数为1
      {
        if(i != current_polynomial.length - 1)
          cout << " +";
        if(i == 1)
          cout << " " << "x";
        else if(i == 0)
          cout << " 1" ;
        else
          cout << " " << "x^" << i;
      }
      else if(fabs(current_polynomial.polynomial[i] + 1) < 1e-7)//系数为-1
      {
        if(i == current_polynomial.length - 1)
        {
          if(i == 1)
            cout << " -" << "x";
          else if(i == 0)
            cout << " -1" ;
          else
            cout << " -" << "x^" << i;
        }
        else
        {
          if(i != current_polynomial.length - 1)
            cout << " -";
          if(i == 1)
            cout << " " << "x";
          else if(i == 0)
            cout << " 1" ;
          else
            cout << " " << "x^" << i;
        }
      }
      else if(fabs(current_polynomial.polynomial[i] - 0) < 1e-7)//系数为0
      {
        if(current_polynomial.length == 1)
          cout << " 0";
        else
          continue;
      }
      else if(current_polynomial.polynomial[i] - 0 >= 1e-7)//系数为正数，且不为1
      {
        if(i != current_polynomial.length - 1)
          cout << " +";
        if(i == 1)
          cout << " " << current_polynomial.polynomial[i] << "x";
        else if(i == 0)
          cout << " " << current_polynomial.polynomial[i];
        else
          cout << " " << current_polynomial.polynomial[i] << "x^" << i;
      }
      else//系数为负数，且不为-1
      {
        if(i == current_polynomial.length - 1)
        {
          if(i == 1)
            cout << " " << current_polynomial.polynomial[i] << "x";
          else if(i == 0)
            cout << " " << current_polynomial.polynomial[i];
          else
            cout << " " << current_polynomial.polynomial[i] << "x^" << i;
        }
        else
        {
          if(i != current_polynomial.length - 1)
            cout << " -";
          if(i == 1)
            cout << " " << fabs(current_polynomial.polynomial[i]) << "x";
          else if(i == 0)
            cout << " " << fabs(current_polynomial.polynomial[i]);
          else
            cout << " " << fabs(current_polynomial.polynomial[i]) << "x^" << i;
        }
      }
    }
    cout << endl;
  }
  cout << endl;
  begin();
}

bool expression_format_check(string expression)//表达式合法性判断
{
  int bracket_flag = 0;
  for(int ix = 0; ix < expression.size(); ++ix)
  {
    if(!((expression[0] >= 'a' && expression[0] <= 'z') || (expression[0] >= 'A' && expression[0] <= 'Z')) && expression[0] != '(' && expression[0] != '$')//开头
    {
      cout << "未遵循规则1" << endl;
      return false;
    }
    if(!((expression[expression.size() - 1] >= 'a' && expression[expression.size() - 1] <= 'z') || (expression[expression.size() - 1] >= 'A' && expression[expression.size() - 1] <= 'Z')) && expression[expression.size() - 1] != ')' && expression[expression.size() - 1] != '!')//结尾
    {
      cout << "未遵循规则1" << endl;
      return false;
    }
    if(expression[ix] == '+' || expression[ix] == '*' || expression[ix] == '-' || expression[ix] == '/')//加减号和乘除号
    {
      if(!((expression[ix + 1] >= 'a' && expression[ix + 1] <= 'z') || (expression[ix + 1] >= 'A' && expression[ix + 1] <= 'Z')) && expression[ix + 1] != '(' && expression[ix + 1] != '$')
      {
        cout << "未遵循规则2" << endl;
        return false;
      }
    }
    else if(expression[ix] == '$')//定积分号
    {
      string lower_bound, upper_bound;
      ++ix;
      if(expression[ix] != '[')
      {
        cout << "未遵循规则3" << endl;
        return false;
      }
      ++ix;
      if(ix == expression.size())
      {
        cout << "未遵循规则3" << endl;
        return false;
      }
      if(expression[ix] == '-')
      {
        lower_bound = expression[ix];
        ++ix;
        if(ix == expression.size())
        {
          cout << "未遵循规则3" << endl;
          return false;
        }
      }
      int lower_point = 0, upper_point = 0;
      while(expression[ix] != ',')
      {
        if(ix == expression.size() || !((expression[ix] >= '0' && expression[ix] <= '9') || expression[ix] == '.'))
        {
          cout << "未遵循规则3" << endl;
          return false;
        }
        if(expression[ix] == '.')
          lower_point++;
        if(lower_point > 1)
        {
          cout << "未遵循规则3" << endl;
          return false;
        }
        lower_bound = lower_bound + expression[ix];
        ++ix;
      }
      ++ix;
      if(ix == expression.size())
      {
        cout << "未遵循规则3" << endl;
        return false;
      }
      if(expression[ix] == '-')
      {
        upper_bound = expression[ix];
        ++ix;
        if(ix == expression.size())
        {
          cout << "未遵循规则3" << endl;
          return false;
        }
      }
      while(expression[ix] != ']')
      {
        if(ix == expression.size() || !((expression[ix] >= '0' && expression[ix] <= '9') || expression[ix] == '.'))
        {
          cout << "未遵循规则3" << endl;
          return false;
        }
        if(expression[ix] == '.')
          upper_point++;
        if(upper_point > 1)
        {
          cout << "未遵循规则3" << endl;
          return false;
        }
        upper_bound = upper_bound + expression[ix];
        ++ix;
      }
      if(ix == expression.size() - 1 || (!((expression[ix + 1] >= 'a' && expression[ix + 1] <= 'z') || (expression[ix + 1] >= 'A' && expression[ix + 1] <= 'Z')) && expression[ix + 1] != '('))
      {
        cout << "未遵循规则3" << endl;
        return false;
      }
      if(atof(lower_bound.c_str()) >= atof(upper_bound.c_str()))
      {
        cout << "未遵循规则3" << endl;
        return false;
      }
    }
    else if(expression[ix] == '!')//求导号
    {
      if(ix != expression.size() - 1 && (expression[ix + 1] != '+' && expression[ix + 1] != '*' && expression[ix + 1] != '-' && expression[ix + 1] != '/' && expression[ix + 1] != ')'))
      {
        cout << "未遵循规则4" << endl;
        return false;
      }
    }
    else if(expression[ix] == '(')//左括号
    {
      bracket_flag++;
      if(!((expression[ix + 1] >= 'a' && expression[ix + 1] <= 'z') || (expression[ix + 1] >= 'A' && expression[ix + 1] <= 'Z')) && expression[ix + 1] != '(' && expression[ix + 1] != '$')
      {
        cout << "未遵循规则5" << endl;
        return false;
      }
    }
    else if(expression[ix] == ')')//右括号
    {
      bracket_flag--;
      if(ix != expression.size() - 1 && (expression[ix + 1] != '+' && expression[ix + 1] != '*' && expression[ix + 1] != '-' && expression[ix + 1] != '/' && expression[ix + 1] != ')' && expression[ix + 1] != '!'))
      {
        cout << "未遵循规则5" << endl;
        return false;
      }
    }
    else//多项式名
    {
      string polynomial_name;
      polynomial_name = expression[ix];
      ++ix;
      while(ix != expression.size() && (expression[ix] != '+' && expression[ix] != '*' && expression[ix] != '-' && expression[ix] != '/' && expression[ix] != '(' && expression[ix] != ')' && expression[ix] != '!' && expression[ix] != '$') && ((expression[ix] >= 'a' && expression[ix] <= 'z') || (expression[ix] >= 'A' && expression[ix] <= 'Z')))
      {
        polynomial_name = polynomial_name + expression[ix];
        ++ix;
      }
      if(polynomial_check(polynomial_name))
      {
        cout << "未遵循规则8" << endl;
        return false;
      }
      if(ix != expression.size() && (expression[ix] != '+' && expression[ix] != '*' && expression[ix] != '-' && expression[ix] != '/' && expression[ix] != ')' && expression[ix] != '!'))
      {
        cout << "未遵循规则6" << endl;
        return false;
      }
      --ix;
    }
    if(bracket_flag < 0)
    {
      cout << "未遵循规则7" << endl;
      return false;
    }
  }
  if(bracket_flag)
  {
    cout << "未遵循规则7" << endl;
    return false;
  }
  return true;
}

int priority(string current_operator)//设置运算符优先级
{
  if(current_operator == "(" || current_operator == ")")
    return 1;
  if(current_operator == "+" || current_operator == "-")
    return 2;
  if(current_operator == "*" || current_operator == "/")
    return 3;
  if(current_operator[0] == '$')
    return 4;
  if(current_operator == "!")
    return 5;
  return 0;
}

void coefficient_to_polynomial(Node current_polynomial)//输出多项式
{
  for(int i = current_polynomial.length - 1; i >= 0; i--)
  {
    if(fabs(current_polynomial.polynomial[i] - 1) < 1e-7)//系数为1
    {
      if(i != current_polynomial.length - 1)
        cout << " +";
      if(i == 1)
        cout << " " << "x";
      else if(i == 0)
        cout << " 1" ;
      else
        cout << " " << "x^" << i;
    }
    else if(fabs(current_polynomial.polynomial[i] + 1) < 1e-7)//系数为-1
    {
      if(i == current_polynomial.length - 1)
      {
        if(i == 1)
          cout << " -" << "x";
        else if(i == 0)
          cout << " -1" ;
        else
          cout << " -" << "x^" << i;
      }
      else
      {
        if(i != current_polynomial.length - 1)
          cout << " -";
        if(i == 1)
          cout << " " << "x";
        else if(i == 0)
          cout << " 1" ;
        else
          cout << " " << "x^" << i;
      }
    }
    else if(fabs(current_polynomial.polynomial[i] - 0) < 1e-7)//系数为0
    {
      if(current_polynomial.length == 1)
        cout << " 0";
      else
        continue;
    }
    else if(current_polynomial.polynomial[i] - 0 >= 1e-7)//系数为正数，且不为1
    {
      if(i != current_polynomial.length - 1)
        cout << " +";
      if(i == 1)
        cout << " " << current_polynomial.polynomial[i] << "x";
      else if(i == 0)
        cout << " " << current_polynomial.polynomial[i];
      else
        cout << " " << current_polynomial.polynomial[i] << "x^" << i;
    }
    else//系数为负数，且不为-1
    {
      if(i == current_polynomial.length - 1)
      {
        if(i == 1)
          cout << " " << current_polynomial.polynomial[i] << "x";
        else if(i == 0)
          cout << " " << current_polynomial.polynomial[i];
        else
          cout << " " << current_polynomial.polynomial[i] << "x^" << i;
      }
      else
      {
        if(i != current_polynomial.length - 1)
          cout << " -";
        if(i == 1)
          cout << " " << fabs(current_polynomial.polynomial[i]) << "x";
        else if(i == 0)
          cout << " " << fabs(current_polynomial.polynomial[i]);
        else
          cout << " " << fabs(current_polynomial.polynomial[i]) << "x^" << i;
      }
    }
  }
}

Node addition(Node polynomial_1, Node polynomial_2)//加法
{
  Node new_polynomial;
  if(polynomial_1.length >= polynomial_2.length)
    new_polynomial.length = polynomial_1.length;
  else
    new_polynomial.length = polynomial_2.length;
  new_polynomial.name = "(" + polynomial_1.name + "+" + polynomial_2.name + ")";
  memset(new_polynomial.polynomial, 0, sizeof(new_polynomial.polynomial));
  for(int i = 0; i < new_polynomial.length; i++)
    new_polynomial.polynomial[i] = polynomial_1.polynomial[i] + polynomial_2.polynomial[i];
  return new_polynomial;
}

Node multiplication(Node polynomial_1, Node polynomial_2)//乘法
{
  Node new_polynomial;
  new_polynomial.length = polynomial_1.length + polynomial_2.length - 1;
  if(new_polynomial.length == 0)
    new_polynomial.length++;
  new_polynomial.name = "(" + polynomial_1.name + "*" + polynomial_2.name + ")";
  memset(new_polynomial.polynomial, 0, sizeof(new_polynomial.polynomial));
  for(int i = 0; i < polynomial_1.length; i++)
    for(int j = 0; j < polynomial_2.length; j++)
      new_polynomial.polynomial[i + j] = new_polynomial.polynomial[i + j] + polynomial_1.polynomial[i] * polynomial_2.polynomial[j];
  return new_polynomial;
}

Node derivation(Node polynomial_1)//求导
{
  Node new_polynomial;
  new_polynomial.length = polynomial_1.length - 1;
  if(new_polynomial.length == 0)
    new_polynomial.length++;
  new_polynomial.name = "(" + polynomial_1.name + "!" + ")";
  memset(new_polynomial.polynomial, 0, sizeof(new_polynomial.polynomial));
  for(int i = 0; i < new_polynomial.length; i++)
    new_polynomial.polynomial[i] = polynomial_1.polynomial[i + 1] * (i + 1);
  return new_polynomial;
}

Node definite_integral(Node polynomial_1, double lower_bound, double upper_bound)//定积分
{
  Node new_polynomial;
  new_polynomial.length = polynomial_1.length + 1;
  new_polynomial.name = "($[a,b]" + polynomial_1.name + ")";
  memset(new_polynomial.polynomial, 0, sizeof(new_polynomial.polynomial));
  for(int i = 1; i < new_polynomial.length; i++)
    new_polynomial.polynomial[i] = polynomial_1.polynomial[i - 1] / i;
  double lower_result = 0, upper_result = 0;
  for(int j = 1; j < new_polynomial.length; j++)
  {
    lower_result = lower_result + new_polynomial.polynomial[j] * pow(lower_bound, j);
    upper_result = upper_result + new_polynomial.polynomial[j] * pow(upper_bound, j);
  }
  //coefficient_to_polynomial(new_polynomial) << endl;
  new_polynomial.length = 1;
  memset(new_polynomial.polynomial, 0, sizeof(new_polynomial.polynomial));
  new_polynomial.polynomial[0] = upper_result - lower_result;
  return new_polynomial;
}

Node subtraction(Node polynomial_1, Node polynomial_2)//减法
{
  Node new_polynomial;
  if(polynomial_1.length >= polynomial_2.length)
    new_polynomial.length = polynomial_1.length;
  else
    new_polynomial.length = polynomial_2.length;
  new_polynomial.name = "(" + polynomial_1.name + "-" + polynomial_2.name + ")";
  memset(new_polynomial.polynomial, 0, sizeof(new_polynomial.polynomial));
  for(int i = new_polynomial.length - 1; i >= 0; i--)
  {
    if(polynomial_1.polynomial[i] - polynomial_2.polynomial[i] != 0)
      break;
    else
      new_polynomial.length--;
  }
  if(new_polynomial.length == 0)
  {
    new_polynomial.length = 1;
    return new_polynomial;
  }
  for(int j = new_polynomial.length - 1; j >= 0; j--)
    new_polynomial.polynomial[j] = polynomial_1.polynomial[j] - polynomial_2.polynomial[j];
  return new_polynomial;
}

Node module(Node polynomial_1, int n)//取模，模x^n
{
  for(int i = n; i < polynomial_1.length; i++)
    polynomial_1.polynomial[i] = 0;
  if(polynomial_1.length > n)
    polynomial_1.length = n;
  polynomial_1.name = "(" + polynomial_1.name + "mod n)" ;
  //polynomial_1.name = polynomial_1.name + (char*)n;
  //polynomial_1.name = polynomial_1.name + ")";
  return polynomial_1;
}

Node inverse(Node polynomial_1)//狭义求逆
{
  Node inverse_polynomial;
  inverse_polynomial.length = 1;
  inverse_polynomial.name = "(" + polynomial_1.name + "^-1)";
  memset(inverse_polynomial.polynomial, 0, sizeof(inverse_polynomial.polynomial));
  inverse_polynomial.polynomial[0] = 1/polynomial_1.polynomial[0];
  Node two;
  two.length = 1;
  two.name = "(2)";
  memset(two.polynomial, 0, sizeof(two.polynomial));
  two.polynomial[0] = 2;
  for(int m = 2; m < polynomial_1.length * 2; m = 2 * m)//倍增法求逆元
    inverse_polynomial = module(subtraction(multiplication(two,inverse_polynomial), multiplication(polynomial_1,multiplication(inverse_polynomial,inverse_polynomial))), m);
  inverse_polynomial = module(inverse_polynomial, polynomial_1.length);
  return inverse_polynomial;
}

Node generalized_inverse(Node polynomial_1, int m)//广义求逆
//对于一个n次多项式F(x) 我们希望求出一个m-1次多项式G(x) ,满足F(x)G(x)≡1(modx^m)，即逆不一定是mod它的最高项=1，它可以是mod任意次项
{
  Node inverse_polynomial;
  inverse_polynomial.length = 1;
  inverse_polynomial.name = "(" + polynomial_1.name + "^-1)";
  memset(inverse_polynomial.polynomial, 0, sizeof(inverse_polynomial.polynomial));
  inverse_polynomial.polynomial[0] = 1/polynomial_1.polynomial[0];
  Node two;
  two.length = 1;
  two.name = "(2)";
  memset(two.polynomial, 0, sizeof(two.polynomial));
  two.polynomial[0] = 2;
  for(int k = 2; k < m * 2; k = 2 * k)//倍增法求逆元
    inverse_polynomial = module(subtraction(multiplication(two,inverse_polynomial), multiplication(polynomial_1,multiplication(inverse_polynomial,inverse_polynomial))), k);
  inverse_polynomial = module(inverse_polynomial, m);
  return inverse_polynomial;
}

Node coefficient_reverse(Node polynomial_1)//系数取反
{
  Node new_polynomial;
  new_polynomial.name = "(" + polynomial_1.name + "(reverse))";
  new_polynomial.length = polynomial_1.length;
  memset(new_polynomial.polynomial, 0, sizeof(new_polynomial.polynomial));
  for(int i = 0; i < new_polynomial.length; i++)
    new_polynomial.polynomial[i] = polynomial_1.polynomial[new_polynomial.length - 1 - i];
  for(int j = new_polynomial.length - 1; j >= 0; j--)
  {
    if(new_polynomial.polynomial[j] != 0)
      break;
    else
      new_polynomial.length--;
  }
  if(new_polynomial.length == 0)
    new_polynomial.length = 1;
  return new_polynomial;
}

Node quotient(Node dividend_polynomial, Node divisor_polynomial)//求商
{
  Node zero;
  zero.name = "(0)";
  zero.length = 1;
  memset(zero.polynomial, 0, sizeof(zero.polynomial));
  if(polynomial_greater_check(divisor_polynomial, dividend_polynomial))
    return zero;
  Node quotient_polynomial;
  quotient_polynomial.name = "(" + dividend_polynomial.name + "/" + divisor_polynomial.name + ")";
  quotient_polynomial.length = 1;
  quotient_polynomial = coefficient_reverse(module(multiplication(coefficient_reverse(dividend_polynomial), generalized_inverse(coefficient_reverse(divisor_polynomial), dividend_polynomial.length - divisor_polynomial.length + 1)), dividend_polynomial.length - divisor_polynomial.length + 1));
  return quotient_polynomial;
}

Node remainder(Node dividend_polynomial, Node divisor_polynomial)//求余数
{
  Node zero;
  zero.name = "(0)";
  zero.length = 1;
  memset(zero.polynomial, 0, sizeof(zero.polynomial));
  if(polynomial_greater_check(divisor_polynomial, dividend_polynomial))
    return dividend_polynomial;
  Node quotient_polynomial;
  quotient_polynomial.name = "(" + dividend_polynomial.name + "/" + divisor_polynomial.name + ")";
  quotient_polynomial.length = 1;
  quotient_polynomial = coefficient_reverse(module(multiplication(coefficient_reverse(dividend_polynomial), generalized_inverse(coefficient_reverse(divisor_polynomial), dividend_polynomial.length - divisor_polynomial.length + 1)), dividend_polynomial.length - divisor_polynomial.length + 1));
  Node remainder_polynomial;
  remainder_polynomial.name = "((" + dividend_polynomial.name + ")mod(" + divisor_polynomial.name + "))";
  remainder_polynomial.length = 1;
  remainder_polynomial = subtraction(dividend_polynomial, multiplication(divisor_polynomial, quotient_polynomial));
  return remainder_polynomial;
}

bool polynomial_greater_check(Node polynomial_1, Node polynomial_2)//多项式1是否大于多项式2
{
  if(polynomial_1.length > polynomial_2.length)
    return true;
  else if(polynomial_1.length < polynomial_2.length)
    return false;
  for(int i = polynomial_1.length - 1; i >= 0; i--)
  {
    if(polynomial_1.polynomial[i] > polynomial_2.polynomial[i])
      return true;
    else if(polynomial_1.polynomial[i] < polynomial_2.polynomial[i])
      return false;
    if(i == 0)
      return false;
  }
}

Node evaluation(Node polynomial_1, double x0)//求值
{
  Node evaluation_polynomial;
  evaluation_polynomial.name = "(" + polynomial_1.name + "(x0))";
  memset(evaluation_polynomial.polynomial, 0, sizeof(evaluation_polynomial.polynomial));
  for(int i = 0; i < polynomial_1.length; i++)
  {
    if(i == 0)
      evaluation_polynomial.polynomial[0] = evaluation_polynomial.polynomial[0] + polynomial_1.polynomial[i];
    else
      evaluation_polynomial.polynomial[0] = evaluation_polynomial.polynomial[0] + polynomial_1.polynomial[i] * pow(x0, i);
  }
  return evaluation_polynomial;
}

Node root_extraction(Node polynomial_1)//求根
{
  Node root_polynomial;
  root_polynomial.name = "(" + polynomial_1.name + "(root))";
  root_polynomial.length = 1;
  memset(root_polynomial.polynomial, 0, sizeof(root_polynomial.polynomial));
  root_polynomial.polynomial[0] = -1;
  Node temp_polynomial;
  temp_polynomial.name = "(" + polynomial_1.name + "(temp))";
  temp_polynomial.length = 1;
  memset(temp_polynomial.polynomial, 0, sizeof(temp_polynomial.polynomial));
  while((evaluation(derivation(polynomial_1), temp_polynomial.polynomial[0])).polynomial[0] == 0)//防止切线斜率为0
    temp_polynomial.polynomial[0]++;
  while(fabs(root_polynomial.polynomial[0] - temp_polynomial.polynomial[0]) > 0.00001)
  {
    temp_polynomial.polynomial[0] = root_polynomial.polynomial[0];
    root_polynomial.polynomial[0] = temp_polynomial.polynomial[0] - (evaluation(polynomial_1, temp_polynomial.polynomial[0])).polynomial[0] / (evaluation(derivation(polynomial_1), temp_polynomial.polynomial[0])).polynomial[0];
  }
  return root_polynomial;
}

void special_inverse_operation()//多项式狭义求逆
{
  cout << "多项式名：";
  string name;
  cin >> name;
  while(name.empty())//多项式名是否为空
  {
    cout << "多项式名不能为空！请重新输入！" << endl;
    cout << "多项式名：";
    cin >> name;
  }
  while(polynomial_check(name))//多项式名是否存在
  {
    cout << "您输入的多项式名不存在！请重新输入！" << endl;
    cout << "多项式名：";
    cin >> name;
  }
  Node origin_polynomial;
  for(vector<Node>::iterator it = all_polynomial.begin(); it != all_polynomial.end(); ++it)
    if((*it).name == name)
      origin_polynomial = *it;
  if(origin_polynomial.polynomial[0] == 0)
  {
    cout << "您输入的多项式没有逆元！" << endl;
    cout << "是否继续输入？（y/n）：";
    string choice;
    cin >> choice;
    while(choice != "n")//选择是否正确
    {
      if(choice == "y")
      {
        cout << endl;
        inverse_operation();
      }
      else if(choice != "n")
      {
        cout << "你输入的选择不正确，请重新输入！" << endl;
        cout << "是否继续输入？（y/n）：";
        cin >> choice;
      }
    }
    cout << endl;
    begin();
  }
  Node inverse_polynomial;
  inverse_polynomial = inverse(origin_polynomial);
  cout << "逆元为：" << origin_polynomial.name << "^-1 =";
  coefficient_to_polynomial(inverse_polynomial);
  cout << endl;
  cout << "运算成功！是否继续输入？（y/n）：";
  string choice;
  cin >> choice;
  while(choice != "n")//选择是否正确
  {
    if(choice == "y")
    {
      cout << endl;
      inverse_operation();
    }
    else if(choice != "n")
    {
      cout << "你输入的选择不正确，请重新输入！" << endl;
      cout << "是否继续输入？（y/n）：";
      cin >> choice;
    }
  }
  cout << endl;
  begin();
}

void generalized_inverse_operation()//多项式广义求逆
{
  cout << "多项式名：";
  string name;
  cin >> name;
  while(name.empty())//多项式名是否为空
  {
    cout << "多项式名不能为空！请重新输入！" << endl;
    cout << "多项式名：";
    cin >> name;
  }
  while(polynomial_check(name))//多项式名是否存在
  {
    cout << "您输入的多项式名不存在！请重新输入！" << endl;
    cout << "多项式名：";
    cin >> name;
  }
  Node origin_polynomial;
  for(vector<Node>::iterator it = all_polynomial.begin(); it != all_polynomial.end(); ++it)
    if((*it).name == name)
      origin_polynomial = *it;
  if(origin_polynomial.polynomial[0] == 0)
  {
    cout << "您输入的多项式没有逆元！" << endl;
    cout << "是否继续输入？（y/n）：";
    string choice;
    cin >> choice;
    while(choice != "n")//选择是否正确
    {
      if(choice == "y")
      {
        cout << endl;
        inverse_operation();
      }
      else if(choice != "n")
      {
        cout << "你输入的选择不正确，请重新输入！" << endl;
        cout << "是否继续输入？（y/n）：";
        cin >> choice;
      }
    }
    cout << endl;
    begin();
  }
  int index = 0;
  cout << "请输入逆元取模的指数（只能为正整数）：";
  cin >> index;
  while(index <= 0)
  {
    cout << "指数只能为正整数！请重新输入！" << endl;
    cout << "请输入逆元取模的指数（只能为正整数）：";
    cin >> index;
  }
  Node inverse_polynomial;
  inverse_polynomial = generalized_inverse(origin_polynomial, index);
  cout << "逆元为：" << origin_polynomial.name << "^-1 =";
  coefficient_to_polynomial(inverse_polynomial);
  cout << endl;
  cout << "运算成功！是否继续输入？（y/n）：";
  string choice;
  cin >> choice;
  while(choice != "n")//选择是否正确
  {
    if(choice == "y")
    {
      cout << endl;
      inverse_operation();
    }
    else if(choice != "n")
    {
      cout << "你输入的选择不正确，请重新输入！" << endl;
      cout << "是否继续输入？（y/n）：";
      cin >> choice;
    }
  }
  cout << endl;
  begin();
}













