#include "Header.h"


using namespace std;


//Програма рахує вираз, введений користувачем. Можна вводити змінні, працює "довга арифметика". Приклад: x=5 y=x+3 (5+x)*y-2

int main() {
	while (1)
	{
		system("cls");
		cout << "Hello , Enter your expression!" << endl;
		string help;
		deque<string>vars;
		deque<string>values;
		deque<string>s;
		deque<string>g;
		deque<string>help1;
		deque<int>n1;
		deque<int>n2;
		string sss;
		getline(cin, sss);
		bool t = false;
		bool v = false;
		bool tt = false;
		bool isvar = false;
		bool tiv = false;
		int ff = 0;
		int fs = 0;
		int c = 0;
		int d = 0;
		int v1 = 0;
		int v2 = 0;
		//Checking availability of variables
		for (int i = 0; i < sss.size(); i++) {
			if (sss[i] == '=') {
				isvar = true;
				break;
			}
		}
		//Variables Recording
		while (isvar == true) {
			int j;
			vars.push_back("");
			v1++;
			values.push_back("");
			v2++;
			for (j = 1; sss[j - 1] != '='; j++) {
				if (sss[j] > 47 && sss[j] < 58) {
					t = true;
					cout << "Incorrect name of variable" << endl;
					break;
					return 2;
				}
				else {
					vars[vars.size() - 1] += sss[j - 1];
				}
			}
			if (t == false) {
				help = "";
				for (; sss[j] != ' ' && j < sss.size(); j++) {
					help += sss[j];
				}
				calculator(help, g, vars, values, t, 1);
				if (g.empty() == false) {
					equal_strings(g[0], values[v2 - 1]);
				}
				help.clear();
				g.clear();
				if (j + 1 > sss.size()) {
					sss.clear();
				}
				else {
					sss.erase(sss.begin(), sss.begin() + j + 1);
				}
				isvar = false;
			}
			for (int i = 0; i < sss.size(); i++) {
				if (sss[i] == '=') {
					isvar = true;
					break;
				}
			}
		}
		//Checking the correctness of the expression
		if (sss.size() == 0 && t == false) {
			cout << "You entered only variables or expression before variables. Please , enter expression after variables!" << endl;
			t = true;
		}
		if (t == false) {
			for (int i = 0; i < sss.size(); i++) {
				if (i > 1 && sss[i - 1] == '(') {
					if (sss[i] == ')') {
						cout << "Nothing in brackets" << endl;
						t = true;
						break;
					}
				}
				if (sss[i] == '(') {
					ff++;
				}
				if (sss[i] == ')') {
					fs++;
				}
				if (fs > ff) {
					cout << "Incorrect number of brackets" << endl;
					t = true;
					break;
				}
			}
		}
		if (t == false) {
			if (fs != ff) {
				cout << "Incorrect number of brackets" << endl;
				t = true;
				return 5;
			}
			//Getting answer
			calculator(sss, s, vars, values, t, 0);
		}
		//Showing of answer
		if (s.empty() == false && t == false) {
			cout << s[0] << endl;
		}
		system("pause");
	}
}

