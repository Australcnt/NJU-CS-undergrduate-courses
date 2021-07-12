#ifndef _FUUNCTION_H
#define _FUNCTION_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <string.h>
#include <sstream>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stack>
using namespace std;

struct Node
{
  string name;
  double polynomial[50];
  int length;
};

extern vector<Node> all_polynomial;

//主功能函数
void polynomial_typein();
void hybrid_operation();
void inverse_operation();
void divide_operation();
void root_extract();
void evaluate_operation();
void polynomial_typeout();

//辅助函数
bool polynomial_check(string name);
void single_polynomial_typeout();
void all_polynomial_typeout();
bool expression_format_check(string expression);
int priority(string current_operator);
void coefficient_to_polynomial(Node current_polynomial);
Node addition(Node polynomial_1, Node polynomial_2);
Node multiplication(Node polynomial_1, Node polynomial_2);
Node derivation(Node polynomial_1);
Node definite_integral(Node polynomial_1, double lower_bound, double upper_bound);
Node subtraction(Node polynomial_1, Node polynomial_2);
Node module(Node polynomial_1, int n);
Node inverse(Node polynomial_1);
Node generalized_inverse(Node polynomial_1, int m);
Node coefficient_reverse(Node polynomial_1);
Node quotient(Node dividend_polynomial, Node divisor_polynomial);
Node remainder(Node dividend_polynomial, Node divisor_polynomial);
bool polynomial_greater_check(Node polynomial_1, Node polynomial_2);
Node evaluation(Node polynomial_1, double x0);
Node root_extraction(Node polynomial_1);
void special_inverse_operation();
void generalized_inverse_operation();

#endif
