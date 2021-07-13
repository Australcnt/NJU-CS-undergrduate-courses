#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "Polynomial.h"
using namespace std;

void createItem(string s, int* array) {
    if(s == "")
        return;
    if(s[0] == '+')
        s.erase(s.begin());
    if(s[0] == 'x')
        s.insert(s.begin(), '1');
    else if(s[0] == '-' && s[1] == 'x')
        s.insert(s.begin() + 1, '1');
    
    int coefficent = 0;
    int power = 0;
    int index = 0;
    while(index < s.size() && s[index] != 'x') {
        index++;
    }
    coefficent = atoi(s.substr(0, index).c_str());
    if(index < s.size() - 1) {
        power = atoi(s.substr(index + 1, s.size() - index).c_str());
    } else if(index == s.size() - 1) {
        power = 1;
    } else {
        power = 0;
    }
    array[power] += coefficent;
}

int* convertString2Int(const char* c) {
    int* array = new int[100];
    for(int i = 0; i < 100; i++)
        array[i] = 0;
    string str(c);
    if(str == "")
        return array;
    int preIndex = 0;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '+' || str[i] == '-'){
            createItem(str.substr(preIndex, i - preIndex), array);
            preIndex = i;
        }
    }
    createItem(str.substr(preIndex, str.size() - preIndex), array);
    return array;
}

Polynomial::Polynomial(const char* expression)
{
    original_expr = new char [100];
    strcpy(original_expr, expression);
    coefficient_array = new int[100];
    for (int i = 0; i < 100; i++)
        coefficient_array[i] = 0;
    coefficient_array = convertString2Int(expression);
    max_exponent = 0;
    for (int i = 99; i >= 0; i--)
    {
        if (coefficient_array[i] != 0)
        {
            max_exponent = i;
            break;
        }
    }
}

Polynomial::Polynomial(const Polynomial& polynomial)
{
    //delete[]original_expr;
    original_expr = new char[100];
    strcpy(original_expr, polynomial.original_expr);
    //delete[]coefficient_array;
    coefficient_array = new int[100];
    for (int i = 0; i < 100; i++)
        coefficient_array[i] = 0;
    for (int i = 0; i <= polynomial.max_exponent; i++)
    {
        coefficient_array[i] = polynomial.coefficient_array[i];
    }
    max_exponent = polynomial.max_exponent;
}

Polynomial::~Polynomial() {
    if(coefficient_array != NULL) {
        delete[] coefficient_array;
        coefficient_array = NULL;
    }
    if(original_expr != NULL) {
        delete[] original_expr;
        original_expr = NULL;
    }
    max_exponent = 0;
}

char* Polynomial::getOriginal()
{
    return original_expr;
}

void Polynomial::printHighest()
{
    if (getOriginal() == NULL)
        cout << 0;
    else
    {
        if(max_exponent==0)
        {
            cout << coefficient_array[max_exponent];
        }
        else if(max_exponent==1)
        {
            if (coefficient_array[max_exponent] == 1)
                cout << "x";
            else if (coefficient_array[max_exponent] == -1)
                cout << "-x";
            else
                cout << coefficient_array[max_exponent] << "x";
        }
        else
        {
            if (coefficient_array[max_exponent] == 1)
                cout << "x" << max_exponent;
            else if (coefficient_array[max_exponent] == -1)
                cout << "-x" << max_exponent;
            else
                cout << coefficient_array[max_exponent] << "x" << max_exponent;
        }
    }
}

void Polynomial::printExpression()
{
    if (getOriginal() == NULL)
        cout << 0;
    else
    {
        printHighest();
        for (int i = max_exponent - 1; i >= 0; i--)
        {
            if (coefficient_array[i] == 0)
                continue;
            if (i == 0)
            {
                if (coefficient_array[i] > 0)
                    cout << "+" << coefficient_array[i];
                else
                    cout << coefficient_array[i];
            }
            else if (i == 1)
            {
                if (coefficient_array[i] == 1)
                    cout << "+x";
                else if (coefficient_array[i] == -1)
                    cout << "-x";
                else
                {
                    if (coefficient_array[i] > 0)
                        cout << "+" << coefficient_array[i] << "x";
                    else
                        cout << coefficient_array[i] << "x";
                }
            }
            else
            {
                if (coefficient_array[i] == 1)
                    cout << "+x" << i;
                else if (coefficient_array[i] == -1)
                    cout << "-x" << i;
                else
                {
                    if (coefficient_array[i] > 0)
                        cout << "+" << coefficient_array[i] << "x" << i;
                    else
                        cout << coefficient_array[i] << "x" << i;
                }
            }
        }
    }
}

int Polynomial::computeValue(int x1)
{
    int value = coefficient_array[max_exponent];
    for (int i = max_exponent-1; i >= 0; i--)
    {
        value = value * x1 + coefficient_array[i];
    }
    return value;
}

Polynomial Polynomial::operator + (const Polynomial& polynomial) const
{
    Polynomial* new_polynomial = new Polynomial(*this);
    new_polynomial->original_expr = strcat(polynomial.original_expr, original_expr);
    if (max_exponent > polynomial.max_exponent)
        new_polynomial->max_exponent = max_exponent;
    else
        new_polynomial->max_exponent = polynomial.max_exponent;
    for (int i = 0; i <= new_polynomial->max_exponent; i++)
    {
        new_polynomial->coefficient_array[i] = coefficient_array[i] + polynomial.coefficient_array[i];
    }
    new_polynomial->max_exponent = 0;
    for (int i = 99; i >= 0; i--)
    {
        if (new_polynomial->coefficient_array[i] != 0)
        {
            new_polynomial->max_exponent = i;
            break;
        }
    }
    return *new_polynomial;
}

Polynomial Polynomial::operator - (const Polynomial& polynomial) const
{
    Polynomial polynomial2(polynomial);
    for (int i = 0; i <= polynomial.max_exponent; i++)
        polynomial2.coefficient_array[i] = -polynomial2.coefficient_array[i];
    Polynomial* new_polynomial = new Polynomial(*this + polynomial2);
    //Polynomial new_polynomial("0");
    //new_polynomial = *this + polynomial2;
    return *new_polynomial;
}

Polynomial& Polynomial::operator = (const Polynomial& polynomial)
{
    max_exponent = polynomial.max_exponent;
    coefficient_array = new int[100];
    for (int i = 0; i <= max_exponent; i++)
    {
        coefficient_array[i] = polynomial.coefficient_array[i];
    }
    original_expr = new char[100];
    strcpy(original_expr, polynomial.original_expr);
    return *this;
}

bool Polynomial::operator == (const Polynomial& polynomial) const
{
    if (max_exponent != polynomial.max_exponent)
        return false;
    for (int i = 0; i <= max_exponent; i++)
    {
        if (coefficient_array[i] != polynomial.coefficient_array[i])
            return false;
        return true;
    }
}