#pragma once
#include <iostream>
#include <deque>
#include <string>
#include<ctime>
#include <fstream>
#include <windows.h>
#include <stdio.h>
using namespace std;




struct Time {
	int hours;
	int minutes;
	friend std::ostream& operator<< (std::ostream& out, const Time& time);
	friend std::istream& operator>>(std::istream& in, Time& time);
	friend std::ofstream& operator<<(std::ofstream& out, const Time& time);
	friend std::ifstream& operator>>(std::ifstream& in, Time& time);
};

struct Date{
	int day;
	int month;
	int year;
	friend std::ostream& operator<< (std::ostream& out, const Date& date);
	friend std::istream& operator>>(std::istream& in, Date& date);
	friend std::ofstream& operator<<(std::ofstream& out, const Date& date);
	friend std::ifstream& operator>>(std::ifstream& in, Date& date);
};

class Affair {
public:
	Date date = {};
	Time time = {};
	string name;
	string type;
	string place;
	int importance;
	bool done;
	string additional;
	void get_affair() {
		/*cout << "Enter date" << endl;
		cin >> date;*/
	}
	void Ashow_date_and_time() {
		cout << date << "\t" << time << endl;
	}
	void set_time(Time& a) {
		a = time;
	}
	void set_date(Date &a) {
		a = date;
	}
private:
	friend std::istream& operator>> (std::istream& in, Affair& affair);
	friend std::ostream& operator<< (std::ostream& out, const Affair& affair);
	friend std::ofstream& operator<<(std::ofstream& out, const Affair& affair);
	friend std::ifstream& operator>>(std::ifstream& in, Affair& affair);
};


class Day {
public:
	Date dayDate;
	deque<Affair>dayAffairs;
private:
	
};



bool operator >(Time time1, Time time2);
bool operator ==(Time time1, Time time2);
bool operator >(Date date1, Date date2);
bool operator ==(Date date1, Date date2);



bool is_sort(deque<Affair>& ToSort);
void sort_affairs(deque<Affair>&ToSort);
void insert_in_sorted(deque<Affair>& Sorted, Affair aff);
void mode_display(deque<Affair>& Affairs);
int display_menu();
void main_menu(deque<Affair>& Affairs);
void mode_edit(deque<Affair>& Affairs);






