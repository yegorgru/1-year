#pragma once

#include <iostream>
#include <deque>
#include <string>
using namespace std;


struct drib;
void cleaning(deque<int>& c);
void equal_arrays(deque<int>a, deque<int>& b);
void equal_strings(string& a, string& b);
int first_bigger(deque<int>a, deque<int>b);
void out(deque<int>d);
void out2(deque<char>d);
void arrange_minus_arrange(deque<int>arrange_1, deque<int>arrange_2, deque<int>& arrange_answer);
void arrange_division_arrange(deque<int>a, deque<int>b, deque<int>& answer, deque<int>& ost);
void arrange_plus_arrange(deque<int>arrange_1, deque<int>arrange_2, deque<int>& arrange_answer);
void arrange_plus(deque<int>& arrange_1, deque<int>arrange_2);
void arrange_multiplication_arrange(deque<int>arrange_1, deque<int>arrange_2, deque<int>& arrange_answer);
void arrange_minus(deque<int>& arrange_1, deque<int>arrange_2);
void wit(int c, int d, deque<string>& s);
void arrange_divwo(deque<int>a, deque<int>b, deque<int>& answer);
void arrange_minuss(deque<int>arrange_1, deque<int>arrange_2, deque<int>& arrange_answer);
void arrange_minusss(deque<int>& arrange_1, deque<int>arrange_2);
void itos(deque<int>n, string& s);
void stoi(string s, deque<int>& n);
bool eq_strings(string a, string b);
void calculator(string sss, deque<string>& s, deque<string>vars, deque<string>values, bool& t, int pppp);


