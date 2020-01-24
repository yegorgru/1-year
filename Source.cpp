#include <fstream>
#include<iostream>
#include<string>
#include<deque>
#include "Header.h"
using namespace std;


void numbers() {
	setlocale(LC_ALL, "ru");
	ifstream fin;
	fin.open("C:\cppstudio.txt");
	if (!fin.is_open()) {
		cout << "File wasn't opened";
	}
	else {
		cout << "file is opened"<<endl;
		char a;
		string s;
		deque<string>sss;
		char last='&';
		int l = 0;
		while (fin.get(a)) {
			if ((a > 64 && a < 91) || (a > 96 && a < 123)) {
				l++;
			}
		}
		fin.close();
		fin.open("C:\cppstudio.txt");
		int k = 0;
		while (fin.get(a)) {
			if (a != ' ' && a != '\n') {
				k++;
			}
		}
		fin.close();
		fin.open("C:\cppstudio.txt");
		int r = 0;
		while (fin.get(a)) {
			if (a=='.'||a==','||a=='-'||a=='!'||a=='?'||a==':'||a==';'||a=='('||a==')'||a=='Ф') {
				r++;
			}
		}
		fin.close();
		fin.open("C:\cppstudio.txt");
		int w = 0;
		while (!fin.eof()) {
			s = "";
			fin >> s;//считывает до пробела
			if (s == "-") {
				continue;
			}
			w++;
		}
		fin.close();
		fin.open("C:\cppstudio.txt");
		int ss = 0;
		while (!fin.eof()) {
			s = "";
			fin >> s; 
			if (s[s.size() - 1] == '.' || s[s.size() - 1] == '!' || s[s.size() - 1] == '?') {
				ss++;
			}
		}
		fin.close();
		fin.open("C:\cppstudio.txt");
		int d = 0;
		while (!fin.eof()) {
			s = "";
			fin >> s;
			last = '$';
			for (int i = 0; i < s.size(); i++) {
				a = s[i];
				if (a == last&&a!='.') {
					d++;
					if (s[s.size() - 1] == '.' && s[s.size() - 2] == '.' && s[s.size() - 3] == '.') {
						s.resize(s.size() - 3);
					}
					else if (s[s.size() - 1] == '.' || s[s.size() - 1] == ',' || s[s.size() - 1] == ';' || s[s.size() - 1] == '!' || s[s.size() - 1] == '?' || s[s.size() - 1] == ':' || s[s.size() - 1] == '"') {
						s.resize(s.size() - 1);
					}
					if (s[0] == '"') {
						s.replace(0, s.size() - 1, s, 1, s.size());
					}
					sss.push_back(s);
					break;
				}
				last = a;
			}
		}
		fin.close();
		cout <<"There are "<< l<<" letters\n";
		cout << "There are " << k << " symbols\n";
		cout << "There are " << r << " punctuation marks\n";
		cout << "There are " << w << " words\n";
		cout << "There are " << ss << " sentences\n";
		cout << "There are " << d << " words with double letter\n"<<"This words: ";
		for (int i = 0; i < sss.size(); i++) {
			cout << sss[i]<<"\t";
		}
	}
}

void words() {
	setlocale(LC_ALL, "ru");
	ifstream fin;
	fin.open("C:\cppstudio.txt");
	if (!fin.is_open()) {
		cout << "File wasn't open";
	}
	else {
		cout << "file is open"<<endl;
		string s;
		int g1 = 0;
		int g2 = 0;
		int n1 = 0;
		int n2 = 0;
		bool gg = false;
		bool nn=false;
		char a[] = { 'a','e','i','o','u','A','E','I','O','U' };
		while (!fin.eof()) {
			s = "";
			fin >> s;
			if (s == "-") {
				continue;
			}
			if (s[s.size() - 1] == '.' && s[s.size() - 2] == '.' && s[s.size() - 3] == '.') {
				s.resize(s.size() - 3);
			}
			else if (s[s.size() - 1] == '.' || s[s.size() - 1] == '!' || s[s.size() - 1] == '?'|| s[s.size() - 1] == ',') {
				for (int i = 0; i < 10; i++) {
					if (s[s.size() - 2] == a[i]) {
						g2++;
						gg = true;
						break;
					}
				}
				if (gg == false) {
					n2++;
				}
				gg=false;
			}
			else {
				for (int i = 0; i < 10; i++) {
					if (s[s.size()-1] == a[i]) {
						g2++;
						gg = true;
						break;
					}
				}
				if (gg == false) {
					n2++;
				}
				gg = false;
			}
			if (s[0] == '"') {
				for (int i = 0; i < 10; i++) {
					if (s[1] == a[i]) {
						g1++;
						nn = true;
						break;
					}
				}
				if (nn == false) {
					n1++;
				}
				nn = false;
			}
			else {
				for (int i = 0; i < 10; i++) {
					if (s[0] == a[i]) {
						g1++;
						nn = true;
						break;
					}
				}
				if (nn == false) {
					n1++;
				}
				nn = false;
			}
		}
		fin.close();
		cout << "There are " << g1 << " words , that start from vowel letter\n";
		cout << "There are " << g2 << " words , that end with vowel letter\n";
		cout << "There are " << n1 << " words , that start from consonant letter\n";
		cout << "There are " << n2 << " words , that end with consonant letter\n";
	}
}

void bs() {
	int big=0;
	int small=100;
	string b = "";
	string ss = "";
	ifstream fin;
	fin.open("C:\cppstudio.txt");
	string s;
	if (!fin.is_open()) {
		cout << "File wasn't open";
	}
	else {
		while (!fin.eof()) {
			s = "";
			fin >> s;
			if (s[s.size() - 1] == '.' && s[s.size() - 2] == '.' && s[s.size() - 3] == '.') {
				s.resize(s.size() - 3);
			}
			else if (s[s.size() - 1] == '.' || s[s.size() - 1] == '!' || s[s.size() - 1] == '?' || s[s.size() - 1] == ',') {
				s.resize(s.size() - 1);
			}
			if (s[0] == '"') {
				s.replace(0, s.size() - 1, s, 1, s.size()-2);
			}
			if (s.size() > big) {
				big = s.size();
				b = s;
			}
			if (s.size() < small) {
				small = s.size();
				ss = s;
			}
		}
		cout << "The biggest word has " << big << " letters. This word: "<<b<<endl;
		cout << "The shortest word has " << small << " letters.This word: "<<ss<<endl;
		fin.close();
	}
}


void is() {
	string want;
	bool a = false;
	cin >> want;
	bool y = true;
	ifstream fin;
	fin.open("C:\cppstudio.txt");
	string s;
	if (!fin.is_open()) {
		cout << "File wasn't open";
	}
	else {
		while (!fin.eof()) {
			s = "";
			fin >> s;
			if (s[s.size() - 1] == '.' && s[s.size() - 2] == '.' && s[s.size() - 3] == '.') {
				s.resize(s.size() - 3);
			}
			else if (s[s.size() - 1] == '.' || s[s.size() - 1] == '!' || s[s.size() - 1] == '?' || s[s.size() - 1] == ',' || s[s.size() - 1] == '"' || s[s.size() - 1] == ':' || s[s.size() - 1] == ';') {
				s.resize(s.size() - 1);
			}
			if (s[0] == '"') {
				s.replace(0, s.size() - 1, s, 1, s.size()-2);
			}
			if (s.size() == want.size()) {
				for (int i = 0; i < s.size(); i++) {
					if (want[i] < 100) {
						if (s[i] == want[i] || s[i] == want[i] + 32) {
							a = true;
						}
						else{
							a = false;
							break;
						}
					}
					if (want[i] > 100) {
						if (s[i] == want[i] || s[i] == want[i] - 32) {
							a = true;
						}
						else if (s[i] != want[i] && s[i] != want[i] - 32) {
							a = false;
							break;
						}
					}
				}
			}
			if (a == true) {
				break;
			}
		}
		if (a == true) {
			cout << "There is your word";
		}
		else {
			cout << "There isn't your word";
		}
		fin.close();
	}
}

void rep() {
	fstream f;
	bool y = false;
	f.open("cppstudio.txt");
	char a;
	char b[] = { 'a','e','i','o','u','A','E','I','O','U' };
	if (!f.is_open()) {
		cout << "Error";
	}
	else {
		fstream inpt("cppstudio.txt", ios_base::in);
		fstream outpt("dout.txt", ios_base::out);
		while (inpt.get(a)) {
			for (int i = 0; i < 10; i++) {
				if (a == b[i]) {
					outpt << '*';
					y = true;
				}
			}
			if (y == false) {
				outpt << a;
			}
			y = false;
		}
		inpt.close();
		outpt.close();
		inpt.open("dout.txt", ios_base::in);
		outpt.open("cppstudio.txt", ios_base::out);
		while (inpt.get(a)) {
			outpt << a;
		}
	}
}


void pep() {
	fstream f;
	bool y = false;
	f.open("cppstudio.txt");
	char a;
	char b[] = { 'a','e','i','o','u','A','E','I','O','U' };
	if (!f.is_open()) {
		cout << "Error";
	}
	else {
		fstream inpt("cppstudio.txt", ios_base::in);
		fstream outpt("dout.txt", ios_base::out);
		while (inpt.get(a)) {
			for (int i = 0; i < 10; i++) {
				if (a == b[i]) {
					y = true;
				}
			}
			if (y == false) {
				outpt << a;
			}
			y = false;
		}
		inpt.close();
		outpt.close();
		inpt.open("dout.txt", ios_base::in);
		outpt.open("cppstudio.txt", ios_base::out);
		while (inpt.get(a)) {
			outpt << a;
		}
	}
}


void kep() {
	fstream f;
	bool y = false;
	f.open("cppstudio.txt");
	char a;
	int k = 0;
	if (!f.is_open()) {
		cout << "Error";
	}
	else {
		fstream inpt("cppstudio.txt", ios_base::in);
		fstream outpt("dout.txt", ios_base::out);
		while (inpt.get(a)) {
			if (a == 'k') {
				outpt << "math";
				y = true;
			}
			if (y == false) {
				outpt << a;
			}
			y = false;
		}
		inpt.close();
		outpt.close();
		inpt.open("dout.txt", ios_base::in);
		outpt.open("cppstudio.txt", ios_base::out);
		while (inpt.get(a)) {
			outpt << a;
		}
	}
}

