#include "Header.h"



void cleaning(deque<int>& c) {
	int bbb = 0;
	for (int nn = 0; c[nn] == 0 && nn < c.size() - 1; nn++) {
		bbb += 1;
	}
	if (c[0] == 0) {
		c.erase(c.begin(), c.begin() + bbb);
	}
}


void equal_arrays(deque<int>a, deque<int>& b) {
	b.clear();
	for (int c = 0; c < a.size(); c++) {
		b.push_back(a[c]);
	}
}


void equal_strings(string& a, string& b) {
	b = "";
	for (int c = 0; c < a.size(); c++) {
		b += a[c];
	}
}


int first_bigger(deque<int>a, deque<int>b) {
	bool aa = false;
	if (a[0] > 0) {
		aa = true;
	}
	bool bb = false;
	if (b[0] > 0) {
		bb = true;
	}
	int first_bigger_second = 0;
	while (a.size() < b.size()) {
		a.push_front(0);
	}
	while (b.size() < a.size()) {
		b.push_front(0);
	}
	if (a[0] > b[0]) {
		first_bigger_second = 1;
	}
	else if (b[0] > a[0]) {
		first_bigger_second = 2;
	}
	else {
		for (int qq = 0; qq < b.size(); qq++) {
			if (b[qq] > a[qq]) {
				first_bigger_second = 2;
				break;
			}
			else if (a[qq] > b[qq]) {
				first_bigger_second = 1;
				break;
			}
			else {
				first_bigger_second = 3;
				continue;
			}
		}
	}
	return first_bigger_second;
}



void out(deque<int>d) {
	for (int n = 0; n < d.size(); n++) {
		cout << d[n];
	}
}

void out2(deque<char>d) {
	for (int n = 0; n < d.size(); n++) {
		cout << d[n];
	}
}


//Long arithmetic, minuses
void arrange_minus_arrange(deque<int>arrange_1, deque<int>arrange_2, deque<int>& arrange_answer) {
	arrange_answer.clear();
	if (first_bigger(arrange_1, arrange_2) == 3) {
		arrange_answer.push_front(0);
	}
	else if (arrange_1[0] >= 0 && arrange_2[0] >= 0 || arrange_1[0] < 0 && arrange_2[0] >= 0) {
		while (arrange_1.size() < arrange_2.size()) {
			arrange_1.push_front(0);
		}
		while (arrange_2.size() < arrange_1.size()) {
			arrange_2.push_front(0);
		}
		for (int m = 0; m < arrange_1.size(); m++) {
			arrange_answer.push_front(0);
		}
		if (first_bigger(arrange_1, arrange_2) == 1) {
			for (int i = arrange_answer.size() - 1; i >= 1; i--) {
				if (arrange_1[i] - arrange_2[i] >= 0) {
					arrange_answer[i] += (arrange_1[i] - arrange_2[i]);
				}
				else {
					arrange_answer[i] += (arrange_1[i] - arrange_2[i] + 10);
					arrange_1[i - 1] -= 1;
				}
			}
			arrange_answer[0] = arrange_1[0] - arrange_2[0];
			int bbb = 0;
			for (int nn = 0; arrange_answer[nn] == 0; nn++) {
				bbb += 1;
			}
			if (arrange_answer[0] == 0) {
				arrange_answer.erase(arrange_answer.begin(), arrange_answer.begin() + bbb);
			}
		}
		else {
			for (int i = arrange_answer.size() - 1; i >= 1; i--) {
				if (arrange_2[i] - arrange_1[i] >= 0) {
					arrange_answer[i] += (arrange_2[i] - arrange_1[i]);
				}
				else {
					arrange_answer[i] += (arrange_2[i] - arrange_1[i] + 10);
					arrange_2[i - 1] -= 1;
				}
			}
			arrange_answer[0] = arrange_2[0] - arrange_1[0];
			int bbb = 0;
			for (int nn = 0; arrange_answer[nn] == 0; nn++) {
				bbb += 1;
			}
			if (arrange_answer[0] == 0) {
				arrange_answer.erase(arrange_answer.begin(), arrange_answer.begin() + bbb);
			}
			arrange_answer[0] = -arrange_answer[0];
		}
	}
	else if (arrange_1[0] >= 0 && arrange_2[0] < 0) {
		arrange_2[0] = fabs(arrange_2[0]);
		arrange_plus_arrange(arrange_1, arrange_2, arrange_answer);
	}
	else {
		if (first_bigger(arrange_1, arrange_2) == 2) {
			arrange_1[0] = -arrange_1[0];
			arrange_2[0] = -arrange_2[0];
			arrange_minus_arrange(arrange_1, arrange_2, arrange_answer);
			arrange_answer[0] = -arrange_answer[0];
		}
		else if (first_bigger(arrange_1, arrange_2) == 1) {
			arrange_1[0] = -arrange_1[0];
			arrange_2[0] = -arrange_2[0];
			arrange_minus_arrange(arrange_2, arrange_1, arrange_answer);
		}
	}
}

void arrange_minuss(deque<int>arrange_1, deque<int>arrange_2, deque<int>& arrange_answer) {
	arrange_answer.clear();
	if (first_bigger(arrange_1, arrange_2) == 3) {
		arrange_answer.push_front(0);
	}
	else if (arrange_1[0] >= 0 && arrange_2[0] >= 0 || arrange_1[0] < 0 && arrange_2[0] >= 0) {
		while (arrange_1.size() < arrange_2.size()) {
			arrange_1.push_front(0);
		}
		while (arrange_2.size() < arrange_1.size()) {
			arrange_2.push_front(0);
		}
		for (int m = 0; m < arrange_1.size(); m++) {
			arrange_answer.push_front(0);
		}
		if (first_bigger(arrange_1, arrange_2) == 1) {
			for (int i = arrange_answer.size() - 1; i >= 1; i--) {
				if (arrange_1[i] - arrange_2[i] >= 0) {
					arrange_answer[i] += (arrange_1[i] - arrange_2[i]);
				}
				else {
					arrange_answer[i] += (arrange_1[i] - arrange_2[i] + 10);
					arrange_1[i - 1] -= 1;
				}
			}
			arrange_answer[0] = arrange_1[0] - arrange_2[0];
			if (arrange_answer[0] == 0) {
				arrange_answer.erase(arrange_answer.begin());
			}
		}
		else {
			for (int i = arrange_answer.size() - 1; i >= 1; i--) {
				if (arrange_2[i] - arrange_1[i] >= 0) {
					arrange_answer[i] += (arrange_2[i] - arrange_1[i]);
				}
				else {
					arrange_answer[i] += (arrange_2[i] - arrange_1[i] + 10);
					arrange_2[i - 1] -= 1;
				}
			}
			arrange_answer[0] = arrange_2[0] - arrange_1[0];
			if (arrange_answer[0] == 0) {
				arrange_answer.erase(arrange_answer.begin());
			}
			arrange_answer[0] = -arrange_answer[0];
		}
	}
	else if (arrange_1[0] >= 0 && arrange_2[0] < 0) {
		arrange_2[0] = fabs(arrange_2[0]);
		arrange_plus_arrange(arrange_1, arrange_2, arrange_answer);
	}
	else {
		if (first_bigger(arrange_1, arrange_2) == 2) {
			arrange_1[0] = -arrange_1[0];
			arrange_2[0] = -arrange_2[0];
			arrange_minus_arrange(arrange_1, arrange_2, arrange_answer);
			arrange_answer[0] = -arrange_answer[0];
		}
		else if (first_bigger(arrange_1, arrange_2) == 1) {
			arrange_1[0] = -arrange_1[0];
			arrange_2[0] = -arrange_2[0];
			arrange_minus_arrange(arrange_2, arrange_1, arrange_answer);
		}
	}
}

void arrange_minusss(deque<int>& arrange_1, deque<int>arrange_2) {
	deque<int>copy_1;
	for (int i = 0; i < arrange_1.size(); i++) {
		copy_1.push_back(arrange_1[i]);
	}
	arrange_minuss(copy_1, arrange_2, arrange_1);
}

void arrange_minus(deque<int>& arrange_1, deque<int>arrange_2) {
	deque<int>copy_1;
	for (int i = 0; i < arrange_1.size(); i++) {
		copy_1.push_back(arrange_1[i]);
	}
	arrange_minus_arrange(copy_1, arrange_2, arrange_1);
}


//Long arithmetic, divisions
void arrange_division_arrange(deque<int>a, deque<int>b, deque<int>& answer, deque<int>& ost) {
	answer.clear();
	ost.clear();
	if (a[0] >= 0 && b[0] > 0 || a[0] < 0 && b[0] < 0) {
		deque<int>un;
		equal_arrays(b, un);
		while (first_bigger(a, b) == 1 || first_bigger(a, b) == 3) {
			if (answer.size() > 0 && a[0] == 0) {
				answer.push_back(0);
				a.pop_front();
			}
			else {
				int cur = 0;
				while (first_bigger(a, b) == 1 || first_bigger(a, b) == 3) {
					b.push_back(0);
				}
				b.pop_back();
				while (first_bigger(a, b) == 1 || first_bigger(a, b) == 3) {
					arrange_minusss(a, b);
					cur += 1;
				}
				answer.push_back(cur);
				equal_arrays(un, b);
			}
		}
		equal_arrays(a, ost);
	}
	else if (a[0] < 0) {
		a[0] = -a[0];
		arrange_divwo(a, b, answer);
		answer[0] = -answer[0];
	}
	else if (b[0] < 0) {
		b[0] = -b[0];
		arrange_divwo(a, b, answer);
		answer[0] = -answer[0];
	}

}



void arrange_divwo(deque<int>a, deque<int>b, deque<int>& answer) {
	answer.clear();
	bool only_nulls = false;
	for (int q = 0; q < b.size(); q++) {
		if (b[q] == 0) {
			only_nulls = true;
		}
		else {
			only_nulls = false;
			break;
		}
	}
	if (only_nulls) {
		cout << "You can't divide on null" << endl;
		return;
	}
	if (a[0] > 0 && b[0] > 0 || a[0] < 0 && b[0] < 0) {
		a[0] = fabs(a[0]);
		b[0] = fabs(b[0]);
		deque<int>un;
		equal_arrays(b, un);
		if (first_bigger(a, b) == 2) {
			answer.push_front(0);
		}
		while (first_bigger(a, b) == 1 || first_bigger(a, b) == 3) {
			if (answer.size() > 0 && a[0] == 0) {
				answer.push_back(0);
				a.pop_front();
			}
			else {
				int cur = 0;
				while (first_bigger(a, b) == 1 || first_bigger(a, b) == 3) {
					b.push_back(0);
				}
				b.pop_back();
				while (first_bigger(a, b) == 1 || first_bigger(a, b) == 3) {
					arrange_minusss(a, b);
					cur += 1;
				}
				answer.push_back(cur);
				equal_arrays(un, b);
			}
		}
	}
	else if (a[0] < 0) {
		a[0] = -a[0];
		arrange_divwo(a, b, answer);
		answer[0] = -answer[0];
	}
	else if (b[0] < 0) {
		b[0] = -b[0];
		arrange_divwo(a, b, answer);
		answer[0] = -answer[0];
	}
}

//Long arithmetic, pluses
void arrange_plus_arrange(deque<int>arrange_1, deque<int>arrange_2, deque<int>& arrange_answer) {
	arrange_answer.clear();
	if (arrange_1[0] >= 0 && arrange_2[0] >= 0) {
		while (arrange_1.size() < arrange_2.size()) {
			arrange_1.push_front(0);
		}
		while (arrange_2.size() < arrange_1.size()) {
			arrange_2.push_front(0);
		}
		for (int m = 0; m <= arrange_1.size(); m++) {
			arrange_answer.push_front(0);
		}
		arrange_1.push_front(0);
		arrange_2.push_front(0);
		for (int i = arrange_answer.size() - 1; i >= 1; i--) {
			if (arrange_1[i] + arrange_2[i] < 10) {
				arrange_answer[i] += (arrange_1[i] + arrange_2[i]);
			}
			else {
				arrange_answer[i] += ((arrange_1[i] + arrange_2[i]) % 10);
				arrange_answer[i - 1] += 1;
			}
		}
		if (arrange_answer[0] == 0)
			arrange_answer.pop_front();
	}
	else if (arrange_1[0] >= 0 && arrange_2[0] < 0) {
		arrange_2[0] = -arrange_2[0];
		arrange_minus_arrange(arrange_1, arrange_2, arrange_answer);
	}
	else if (arrange_1[0] < 0 && arrange_2[0] >= 0) {
		arrange_1[0] = -arrange_1[0];
		arrange_minus_arrange(arrange_2, arrange_1, arrange_answer);
	}
	else {
		arrange_1[0] = -arrange_1[0];
		arrange_2[0] = -arrange_2[0];
		arrange_plus_arrange(arrange_1, arrange_2, arrange_answer);
		arrange_answer[0] = -arrange_answer[0];
	}
}


void arrange_plus(deque<int>& arrange_1, deque<int>arrange_2) {
	deque<int>copy_1;
	for (int i = 0; i < arrange_1.size(); i++) {
		copy_1.push_back(arrange_1[i]);
	}
	arrange_plus_arrange(copy_1, arrange_2, arrange_1);
}



//Long arithmetic, multiplication
void arrange_multiplication_arrange(deque<int>arrange_1, deque<int>arrange_2, deque<int>& arrange_answer) {
	arrange_answer.clear();
	if (arrange_1[0] >= 0 && arrange_2[0] >= 0 || arrange_1[0] < 0 && arrange_2[0] < 0) {
		arrange_1[0] = fabs(arrange_1[0]);
		arrange_2[0] = fabs(arrange_2[0]);
		while (arrange_1.size() < arrange_2.size()) {
			arrange_1.push_front(0);
		}
		while (arrange_2.size() < arrange_1.size()) {
			arrange_2.push_front(0);
		}
		for (int m = 0; m < 2 * arrange_1.size(); m++) {
			arrange_answer.push_front(0);
		}
		int ppp = 0;
		int kkk = 0;
		for (int ff = 0; ff < arrange_2.size(); ff++) {
			for (int f = 1; f < arrange_1.size() + 1; f++) {
				arrange_answer[arrange_answer.size() - f - ff] += arrange_1[arrange_2.size() - f] * arrange_2[arrange_2.size() - 1 - ff];
			}
		}
		for (int qqq = arrange_answer.size() - 1; qqq > 0; qqq--) {
			if (arrange_answer[qqq] > 9) {
				arrange_answer[qqq - 1] += arrange_answer[qqq] / 10;
				arrange_answer[qqq] = arrange_answer[qqq] % 10;
			}
		}
		int www = 0;
		for (int nn = 0; arrange_answer[nn] == 0 && nn < arrange_answer.size() - 1; nn++) {
			www += 1;
		}
		if (arrange_answer[0] == 0) {
			arrange_answer.erase(arrange_answer.begin(), arrange_answer.begin() + www);
		}
	}
	else if (arrange_1[0] < 0 || arrange_2[0] < 0) {
		arrange_1[0] = -arrange_1[0];
		arrange_multiplication_arrange(arrange_1, arrange_2, arrange_answer);
		arrange_answer[0] = -arrange_answer[0];
	}
}


void stoi(string s, deque<int>& n) {
	if (s[0] == '-') {
		n.push_back(-(s[1] - '0'));
		for (int i = 2; i < s.size(); i++) {
			n.push_back(s[i] - '0');
		}
	}
	else {
		for (int i = 0; i < s.size(); i++) {
			n.push_back(s[i] - '0');
		}
	}
}

void itos(deque<int>n, string& s) {
	if (n[0] < 0) {
		s += "-";
		s += ((-n[0]) + '0');
	}
	else {
		s += (n[0] + '0');
	}
	for (int i = 1; i < n.size(); i++) {
		s += (n[i] + '0');
	}
}

bool eq_strings(string a, string b) {
	bool y = false;
	if (a.size() == b.size()) {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == b[i]) {
				y = true;
			}
			else {
				y = false;
				break;
			}
		}
	}
	return y;
}


//The function that finds the value of simple expression without (,) in some parentheses. c, d - positions of external parentheses
void wit(int c, int d, deque<string>& s) {
	bool y = false;
	s.erase(s.begin() + c);
	s.erase(s.begin() + d - 1);
	if (d - c == 2) {
		return;
	}
	d -= 2;
	deque<int>hn1;
	deque<int>hn2;
	deque<int>answer;
	string help;
	int count = 0;
	do {
		count = 0;
		for (int i = c; i < d; i++) {
			if (s[i] == "*" || s[i] == "/") {
				count += 1;
			}
		}
		if (count > 0) {
			y = true;
		}
		if (count > 0) {
			for (int i = c; i < d; i++) {
				if (s[i] == "*") {
					stoi(s[i - 1], hn1);
					stoi(s[i + 1], hn2);
					arrange_multiplication_arrange(hn1, hn2, answer);
					s.erase(s.begin() + i - 1, s.begin() + i + 2);
					itos(answer, help);
					if (i - 1 < s.size()) {
						s.insert(s.begin() + i - 1, help);
					}
					else {
						s.push_back(help);
					}
					help.clear();
					hn1.clear();
					hn2.clear();
					d -= 2;
					count--;
					break;
				}
				if (s[i] == "/") {
					stoi(s[i - 1], hn1);
					stoi(s[i + 1], hn2);
					arrange_divwo(hn1, hn2, answer);
					s.erase(s.begin() + i - 1, s.begin() + i + 2);
					itos(answer, help);
					if (i - 1 < s.size()) {
						s.insert(s.begin() + i - 1, help);
					}
					else {
						s.push_back(help);
					}
					help.clear();
					hn1.clear();
					hn2.clear();
					d -= 2;
					count--;
					break;
				}
			}
		}
	} while (count > 0);
	do {
		count = 0;
		for (int i = c; i < d; i++) {
			if (s[i] == "+" || s[i] == "-") {
				count += 1;
			}
		}
		if (count > 0) {
			for (int i = c; i < d; i++) {
				if (s[i] == "+") {
					stoi(s[i - 1], hn1);
					stoi(s[i + 1], hn2);
					arrange_plus_arrange(hn1, hn2, answer);
					s.erase(s.begin() + i - 1, s.begin() + i + 2);
					itos(answer, help);
					if (i - 1 < s.size()) {
						s.insert(s.begin() + i - 1, help);
					}
					else {
						s.push_back(help);
					}
					help.clear();
					hn1.clear();
					hn2.clear();
					d -= 2;
					count--;
					break;
				}
				if (s[c] == "-") {
					if (s[c + 1][0] == '-') {
						s[c + 1].erase(s[c + 1].begin());
						s.erase(s.begin() + c);
					}
					else {
						s.erase(s.begin() + c);
						s[c].insert(s[c].begin(), '-');
					}
				}
				if (s[i] == "-" && i > 0) {
					stoi(s[i - 1], hn1);
					stoi(s[i + 1], hn2);
					arrange_minus_arrange(hn1, hn2, answer);
					s.erase(s.begin() + i - 1, s.begin() + i + 2);
					itos(answer, help);
					if (i - 1 < s.size()) {
						s.insert(s.begin() + i - 1, help);
					}
					else {
						s.push_back(help);
					}
					help.clear();
					hn1.clear();
					hn2.clear();
					d -= 2;
					count--;
					break;
				}
			}
		}
	} while (count > 0);
}


//The function that finds the value of the expression
void calculator(string sss, deque<string>& s, deque<string>vars, deque<string>values, bool& t, int pppp) {
	bool q = true;
	bool kk = false;
	int fs = 0;
	int ff = 0;
	int c = 0;
	int d = 0;
	//Checking the correctness of the expression
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
		}
		int a = 0;
		int b = -1;
		while (a < sss.size()) {
			if (sss[a] == '-' && (a == 0 || sss[a - 1] == '(')) {
				s.push_back("");

				b += 1;
				a += 1;
				while (sss[a] != '(' && sss[a] != ')' && sss[a] != '+' && sss[a] != '-' && sss[a] != '*' && sss[a] != '/') {
					s[b] += sss[a];
					a += 1;
					if (a == sss.size()) {
						break;
					}
				}
				if (s[b] == "" && sss[a] == '(') {
					s[b].insert(s[b].begin(), '-');
					kk = true;
				}
				else if (s[b] == "") {
					s.erase(s.begin() + b);
					b--;
				}
				else {
					s[b].insert(s[b].begin(), '-');
				}
			}
			s.push_back("");
			b += 1;
			while (a < sss.size() && (sss[a] != '(' && sss[a] != ')' && sss[a] != '+' && sss[a] != '-' && sss[a] != '*' && sss[a] != '/')) {
				s[b] += sss[a];
				a += 1;
				if (a == sss.size()) {
					break;
				}
			}
			if (s[b] == "") {
				s.erase(s.begin() + b);
				b--;
			}

			if (sss[a] == '(' || sss[a] == ')' || sss[a] == '+' || sss[a] == '-' || sss[a] == '*' || sss[a] == '/') {
				b += 1;
				s.push_back("");
				s[b] += sss[a];
				a += 1;
				if (a == sss.size()) {
					break;
				}
			}
		}
		//Splitting an expression into parts, checking of variables correctness
		for (int i = 0; i < s.size(); i++) {
			for (int g = 0; g < s[i].size(); g++) {
				if ((s[i][g] < 48 || s[i][g]>57) && s[i][g] != '+' && s[i][g] != '-' && s[i][g] != '*' && s[i][g] != '/' && s[i][g] != ')' && s[i][g] != '(') {
					q = false;
				}
			}
			for (int k = 0; k < vars.size() - pppp; k++) {
				if (eq_strings(vars[k], s[i]) == true) {
					s.erase(s.begin() + i);
					s.insert(s.begin() + i, values[k]);
					q = true;
					break;
				}
			}
			if (s[i].size() > 1 && s[i][0] == '-' && (i == 0 || s[i - 1] == "(")) {
				s[i].erase(s[i].begin());
				for (int p = 0; p < vars.size(); p++) {
					if (eq_strings(vars[p], s[i]) == true) {
						s.erase(s.begin() + i);
						s.insert(s.begin() + i, values[p]);
						q = true;
						break;
					}
				}
				s.insert(s.begin() + i, "-");
			}
		}
		if (q == false) {
			cout << "There is word, that isn't variable in expression" << endl;
			t = true;
		}
	}
	if (t == false) {
		//Finding of values of the expressions in the urgent parentheses while there are parentheses
		while (fs > 0) {
			ff = 0;
			fs = 0;
			int l;
			int m = 0;
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == "(") {
					ff++;
					l = ff - fs;
					if (l > m) {
						m = l;
						c = i;
					}
				}
				if (s[i] == ")") {
					fs++;
					l = ff - fs;
					if (l > m) {
						m = l;
						c = i;
					}
				}
			}
			for (int i = c; s[i] != ")"; i++) {
				d = i + 1;
			}
			wit(c, d, s);
			fs = 0;
			ff = 0;
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == ")") {
					fs++;
				}
			}
		}
	}
	//Finding of value of the last expression without parentheses
	if (t == false) {
		c = 0;
		d = s.size() - 1;
		bool y;
		deque<int>hn1;
		deque<int>hn2;
		deque<int>answer;
		string help;
		int count = 0;
		do {
			count = 0;
			for (int i = c; i < d; i++) {
				if (s[i] == "*" || s[i] == "/") {
					count += 1;
				}
			}
			if (count > 0) {
				y = true;
			}
			if (count > 0) {
				for (int i = c; i < d; i++) {
					if (s[i] == "*") {
						stoi(s[i - 1], hn1);
						stoi(s[i + 1], hn2);
						arrange_multiplication_arrange(hn1, hn2, answer);
						s.erase(s.begin() + i - 1, s.begin() + i + 2);
						itos(answer, help);
						if (i - 1 < s.size()) {
							s.insert(s.begin() + i - 1, help);
						}
						else {
							s.push_back(help);
						}
						help.clear();
						hn1.clear();
						hn2.clear();
						d -= 2;
						count--;
						break;
					}
					if (s[i] == "/") {
						stoi(s[i - 1], hn1);
						stoi(s[i + 1], hn2);
						arrange_divwo(hn1, hn2, answer);
						if (answer.empty()) {
							t = true;
							s.clear();
							break;
						}
						s.erase(s.begin() + i - 1, s.begin() + i + 2);
						itos(answer, help);
						if (i - 1 < s.size()) {
							s.insert(s.begin() + i - 1, help);
						}
						else {
							s.push_back(help);
						}
						help.clear();
						hn1.clear();
						hn2.clear();
						d -= 2;
						count--;
						break;
					}
				}
			}
		} while (count > 0 && t == false);
		if (t == false) {
			do {
				count = 0;
				for (int i = c; i < d; i++) {
					if (s[i] == "+" || s[i] == "-") {
						count += 1;
					}
				}
				if (count > 0) {
					for (int i = c; i < d; i++) {
						if (s[i] == "+") {
							stoi(s[i - 1], hn1);
							stoi(s[i + 1], hn2);
							arrange_plus_arrange(hn1, hn2, answer);
							s.erase(s.begin() + i - 1, s.begin() + i + 2);
							itos(answer, help);
							if (i - 1 < s.size()) {
								s.insert(s.begin() + i - 1, help);
							}
							else {
								s.push_back(help);
							}
							help.clear();
							hn1.clear();
							hn2.clear();
							d -= 2;
							count--;
							break;
						}
						if (s[0] == "-") {
							if (s[1][0] == '-') {
								s[1].erase(s[1].begin());
								s.erase(s.begin());
							}
							else {
								s[1].insert(s[1].begin(), '-');
								s.erase(s.begin());
							}
						}
						if (s[i] == "-" && i > 0) {
							stoi(s[i - 1], hn1);
							stoi(s[i + 1], hn2);
							arrange_minus_arrange(hn1, hn2, answer);
							s.erase(s.begin() + i - 1, s.begin() + i + 2);
							itos(answer, help);
							if (i - 1 < s.size()) {
								s.insert(s.begin() + i - 1, help);
							}
							else {
								s.push_back(help);
							}
							help.clear();
							hn1.clear();
							hn2.clear();
							d -= 2;
							count--;
							break;
						}
					}
				}
			} while (count > 0);
		}
	}
}

