#pragma once

#include <iostream>
#include<cmath>
#include<deque>
using namespace std;


void first(int a,int b, int &count);
void perestanovka(deque<string>& a, int c, string &s);
int coins(deque<int>& sum, deque<int>&a, bool y, int N);
int suma(deque<int>a);
bool yy(deque<int>a, int b);
void sort(deque<int>& a);
bool sablon(string a, string b);
void cod(deque<string>& a, string s, int c,int kk);
void cod1(deque<string>& answer, int K, string s, int c, int first, int second, string ss, deque<int>seconds);