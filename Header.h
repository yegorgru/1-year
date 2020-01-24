#pragma once

#include <iostream>
#include <fstream>
#include<string>
#include<cmath>
#include<deque>
using namespace std;

struct country {
	string name;
	int temp1;
	int temp2;
	int temp3;
	int temp4;
};

//void max();
void give(deque<country>& c);
void fi(deque<country>& c);
void se(deque<country>& c);
void th(deque<country>& c);
void fo(deque<country>& c);
void fiv(deque<country>& c);

