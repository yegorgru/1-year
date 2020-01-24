#include "Header.h"

int suma(deque<int>a) {
	int suma = 0;
	for (int i = 0; i < a.size(); i++) {
		suma += a[i];
	}
	return suma;
}


void sort(deque<int>& a) {
	int help;
	for (int i = 0; i < a.size(); i++) {
		for (int j = i + 1; j < a.size(); j++) {
			if (a[j] > a[i]) {
				help = a[i];
				a[i] = a[j];
				a[j] = help;
			}
		}
	}
}


bool yy(deque<int>a, int b) {
	int c = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == b) c++;
	}
	if (c >= 2) {
		return false;
	}
	return true;
}

void first(int a, int b, int& count) {
	if (a == 1) {
		count++;
		return;
	}
	if (a == 2) {
		count++;
		return;
	}
	if (a > 0) {
		if (a < b) {
			count++;
		}
		int x = 0;
		int u = 0;
		for (int i = 0; ; i++) {
			u += i;
			if (u >= a) {
				break;
			}
			x++;
		}
		for (int i = x; i < a; i++) {
			if (i < b) {
				first(a - i, i, count);
			}
		}
	}
}



void perestanovka(deque<string>&a,int c, string&s) {
	char ch = s[c];
	if (c == 0) {
		string k;
		a.push_front(k);
		a[0] += ch;
		perestanovka(a, 1, s);
	}
	else {
		deque<string>copy;
		for (int i = 0; i < a.size(); i++) {
			copy.push_back(a[i]);
		}
		a.clear();
		string help;
		for (int j = 0; j < copy.size(); j++) {
			for (int i = 0; i < copy[j].size(); i++) {
				help = copy[j];
				help.insert(i, 1, ch);
				a.push_back(help);
			}
			help = copy[j];
			a.push_back((help + ch));
		}
		c++;
		if (c == s.size()) {
			return;
		}
		perestanovka(a, c, s);
	}
}


int coins(deque<int>&sum, deque<int>&a,bool y,int N) {
	y = false;
	if(yy(sum,a[0])) sum.push_back(a[0]);
	else {
		a.pop_front();
		if (a.empty()) {
			return 0;
		}
		coins(sum, a, y, N);
	}
	if (suma(sum) == N) {
		return sum.size();
	}
	else if (suma(sum) < N) {
		coins(sum, a, y, N);
	}
	else {
		if (a.empty()) {
			return 0;
		}
		a.pop_front();
		if (a.empty()) {
			return 0;
		}
		sum.pop_back();
		coins(sum, a, y, N);
	}
}



bool sablon(string a,string b) {
	if (a.empty() && b.empty()) {
		return true;
	}
	if (a.empty()) {
		bool yyyy = true;
		for (int i = 0; i < b.size(); i++) {
			if (b[i] != '*') {
				yyyy = false;
			}
		}
		if (yyyy) {
			return true;
		}
	}
	bool l = false;
	bool ll = false;
	for (int i = 0; i < b.size(); i++) {
		if (b[i] == '*') l = true;
		if (b[i] == '?') ll = true;
	}
	if (a.size() == b.size()&& l==false && ll==false) {
		for (int i = 0; i < a.size();i++) {
			if (a[i] != b[i]) return false;
		}
		return true;
	}
	if (a.size() < b.size()&&l==false) {
		return false;
	}
	if (b.size() == 1 && b[0] == '*') {
		return true;
	}
	for (int i = 0; i < a.size(); i++) {
		if (b[i] == '*') {
			bool k = false;
			while (b[i] == '*') {
				b.erase(b.begin() + i);
				k = true;
			}
			if (k) {
				if (b[i] == '?') {
					b.insert(1, "*a", 1);
					a.insert(1, 'a', 1);
					return sablon(a, b);
				}
			}
			deque<int>n;
			if (i == b.size()) {
				a += 'a';
				b += 'a';
			}
			for (int j = a.size() - 1;j>i-1&&j>-1;j--) {
				if (a[j] == b[i]) {
					n.push_back(j);
				}
			}
			string copy = a;
			for (int h = 0; h < n.size(); h++) {
				a.erase(a.begin() + i, a.begin() + n[h]);
				if (sablon(a, b) == false) {
					a = copy;
				}
				else return true;
			}
			return false;
		}
		if (b[i] == '?') {
			b.erase(b.begin() + i);
			a.erase(a.begin() + i);
			return sablon(a,b);
		}
		else {
			if (a[i] != b[i]) {
				return false;
			}
		}
	}
}

void cod(deque<string>& a, string s, int c, int kk) {
	if (c == s.size()) {
		return;
	}
	if (c == 0) {
		string k;
		a.push_back(k);
		a[0] += s[0];
		cod(a, s, 1,kk);
	}
	else {
		deque<string>copy;
		string k;
		a.push_back(k);
		a[a.size() - 1] += s[c];
		string help;
		for (int j = 0; j < a.size()-1; j++) {
			if (a[j].size() < kk) {
				copy.push_back(a[j] + s[c]);
			}
		}
		for (int i = 0; i < copy.size(); i++) {
			a.push_back(copy[i]);
		}
		c++;
		cod(a, s, c,kk);
	}
}

//1277123

void cod1(deque<string>& answer,int K, string s, int c, int first,int second,string ss, deque<int>seconds) {
	deque<string>ans;
	deque<deque<int>>pluss;
	deque<int>help;
	if (second > s.size() - c + 1) {
		return;
	}
	string ki;
	string kj;
	deque<int>firsec;
	bool y = false;
	int count = 0;
	for (int i = first; i < s.size() - c + 1; i++) {
		ki.clear();
		for (int ii = 0; ii < c; ii++) {
			ki += s[i + ii];
		}
		for (int j = second; j < s.size()-c+1; j++) {
			kj.clear();
			for (int jj = 0; jj < c; jj++) {
				kj += s[j + jj];
			}
			if (ki == kj) {
				ans.push_back(ki);
				firsec.push_back(i+c);
				firsec.push_back(j+c);
				pluss.push_back(help);
				for (int p = 0; p < c; p++) {
					pluss[pluss.size() - 1].push_back(j + p);
				}
			}
		}
		first++;
		second++;
	}
	again:
	for (int i = 0; i < ans.size(); i++) {
		y = false;
		for (int j = i + 1; j < ans.size(); j++) {
			if (ans[i] == ans[j]) {
				y = true;
				ans.erase(ans.begin() + j);
				firsec.erase(firsec.begin() + j * 2);
				firsec.erase(firsec.begin() + j * 2);
				pluss.erase(pluss.begin() + j);
				j--;
			}
		}
		if (y) {
			ans.erase(ans.begin() + i);
			firsec.erase(firsec.begin() + i*2);
			firsec.erase(firsec.begin() + i * 2);
			pluss.erase(pluss.begin() + i);
			goto again;
		}
	}
	bool yy = false;
	for (int i = 0; i < ans.size(); i++) {
		if ((ss + ans[i]).size() == K) {
			answer.push_back(ss + ans[i]);
			yy = true;
		}
	}
	if (yy) {
		return;
	}
	for (int j = 0; j < ans.size(); j++) {
		for (int i = K - 1; i > 0; i--) {
			if (ss.size()+ans[j].size() + i <= K) {
				for (int p = 0; p < seconds.size(); p++) {
					if (firsec[2 * j] == seconds[p]) {
						firsec[2 * j]++;
					}
				}
				for (int pp = 0; pp < pluss[j].size(); pp++) {
					if (firsec[2 * j] == pluss[j][pp]) {
						firsec[2 * j]++;
					}
				}
				if (firsec[2 * j] == firsec[2 * j + 1]) {
					firsec[2 * j + 1]++;
				}
				cod1(answer, K, s, i, firsec[2 * j], firsec[2 * j + 1], (ss + ans[j]),seconds);
			}
		}
	}
}