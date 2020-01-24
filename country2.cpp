#include "Header.h"





void give(deque<country>&c) {
	ifstream fin;
	ofstream fout;
	fout.open("dout2.txt");
	fin.open("cppstudio2.txt");
	string s;
	string name;
	char k;
	deque<string>cc;
	country ss;
	int m = 0;
	try {
		int k = 1;
		int q = 0;
		char b = 0;
		bool y = false;
		bool o = false;
		while (!fin.eof()) {
			s = "";
			getline(fin, s);
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == '\t' || s[i] == ' ') continue;
				if (i == 0 || (s[i] != '\t' && s[i] != ' ' && (s[i - 1] == '\t') || s[i - 1] == ' ')) {
					q++;
					cc.push_back("");
				}
				cc[q - 1] += s[i];
			}
		}
		fin.close();
		fout.close();
	}
	catch (const exception& ex) {
		cout << ex.what() << endl;
		cout << "File wasn't open";
	}
	for (int i = 0; i < cc.size() - 1; i++) {
		if ((cc[i][cc[i].size() - 1] < 48 || cc[i][cc[i].size() - 1]>57) && (cc[i + 1][cc[i + 1].size() - 1] < 48 || cc[i + 1][cc[i + 1].size() - 1]>57)) {
			cc[i] += " ";
			cc[i] += cc[i + 1];
			cc.erase(cc.begin() + i + 1);
			i--;
		}
	}
	for (int i = 0; i < cc.size(); i++) {
		if (i % 5 == 0) {
			c.push_back(ss);
			c[c.size() - 1].name = cc[i];
		}
		else {
			m = 0;
			if (cc[i][0] == '-') {
				for (int j = 1; j < cc[i].size(); j++) {
					m += (cc[i][j] - '0') * pow(10, (cc[i].size() - j - 1));
				}
				m = -m;
			}
			else {
				for (int j = 0; j < cc[i].size(); j++) {
					m += (cc[i][j] - '0') * pow(10, (cc[i].size() - j - 1));
				}
			}
			if (i % 5 == 1) {
				c[c.size() - 1].temp1 = m;
			}
			if (i % 5 == 2) {
				c[c.size() - 1].temp2 = m;
			}
			if (i % 5 == 3) {
				c[c.size() - 1].temp3 = m;
			}
			if (i % 5 == 4) {
				c[c.size() - 1].temp4 = m;
			}
		}
	}
}


void fi(deque<country>& c) {
	int maxt1 = 0;
	int maxt2 = 0;
	int maxt3 = 0;
	int maxt4 = 0;
	int mint1 = 100;
	int mint2 = 100;
	int mint3 = 100;
	int mint4 = 100;
	for (int i = 0; i < c.size(); i++) {
		if (c[i].temp1 > maxt1) {
			maxt1 = c[i].temp1;
		}
		if (c[i].temp1 < mint1) {
			mint1 = c[i].temp1;
		}
		if (c[i].temp2 > maxt2) {
			maxt2 = c[i].temp2;
		}
		if (c[i].temp2 < mint2) {
			mint1 = c[i].temp2;
		}
		if (c[i].temp3 > maxt3) {
			maxt3 = c[i].temp3;
		}
		if (c[i].temp3 < mint3) {
			mint3 = c[i].temp3;
		}
		if (c[i].temp4 > maxt4) {
			maxt4 = c[i].temp4;
		}
		if (c[i].temp4 < mint4) {
			mint4 = c[i].temp4;
		}
	}
	float maxs = 0;
	int n9 = -1;
	float mins = 100;
	int n10 = -1;
	for (int i = 0; i < c.size(); i++) {
		float h = (float)(c[i].temp1 + c[i].temp2 + c[i].temp3 + c[i].temp4) / 4;
		if (h > maxs) {
			maxs = h;
			n9 = i;
		}
		if (h < mins) {
			mins = h;
			n10 = i;
		}
	}
	cout << "Max temperature in summer: " << maxt1 << " ";
	for (int i = 0; i < c.size(); i++) {
		if (c[i].temp1 == maxt1) {
			cout << c[i].name << " ";
		}
	}
	cout << endl;
	cout << "Max temperature in autumn: " << maxt2 << " ";
	for (int i = 0; i < c.size(); i++) {
		if (c[i].temp2 == maxt2) {
			cout << c[i].name << " ";
		}
	}
	cout << endl;
	cout << "Max temperature in winter: " << maxt3 << " ";
	for (int i = 0; i < c.size(); i++) {
		if (c[i].temp3 == maxt3) {
			cout << c[i].name << " ";
		}
	}
	cout << endl;
	cout << "Max temperature in spring: " << maxt4 << " ";
	for (int i = 0; i < c.size(); i++) {
		if (c[i].temp4 == maxt4) {
			cout << c[i].name << " ";
		}
	}
	cout << endl;
	cout << "Min temperature in summer: " << maxt1 << " ";
	for (int i = 0; i < c.size(); i++) {
		if (c[i].temp1 == mint1) {
			cout << c[i].name << " ";
		}
	}
	cout << endl;
	cout << "Min temperature in autumn: " << maxt2 << " ";
	for (int i = 0; i < c.size(); i++) {
		if (c[i].temp2 == mint2) {
			cout << c[i].name << " ";
		}
	}
	cout << endl;
	cout << "Min temperature in winter: " << maxt3 << " ";
	for (int i = 0; i < c.size(); i++) {
		if (c[i].temp3 == mint3) {
			cout << c[i].name << " ";
		}
	}
	cout << endl;
	cout << "Min temperature in spring: " << maxt4 << " ";
	for (int i = 0; i < c.size(); i++) {
		if (c[i].temp4 == mint4) {
			cout << c[i].name << " ";
		}
	}
	cout << endl;
	cout << "Max average temperature: " << maxs << ", " << c[n9].name << endl;
	cout << "Min average temperature: " << mins << ", " << c[n10].name << endl;
}

void se(deque<country>& c) {
	int maxt1 = 0;
	int maxt2 = 0;
	int maxt3 = 0;
	int maxt4 = 0;
	int mint1 = 100;
	int mint2 = 100;
	int mint3 = 100;
	int mint4 = 100;
	for (int i = 0; i < c.size(); i++) {
		if (c[i].temp1 > maxt1) {
			maxt1 = c[i].temp1;
		}
		if (c[i].temp1 < mint1) {
			mint1 = c[i].temp1;
		}
		if (c[i].temp2 > maxt2) {
			maxt2 = c[i].temp2;
		}
		if (c[i].temp2 < mint2) {
			mint1 = c[i].temp2;
		}
		if (c[i].temp3 > maxt3) {
			maxt3 = c[i].temp3;
		}
		if (c[i].temp3 < mint3) {
			mint3 = c[i].temp3;
		}
		if (c[i].temp4 > maxt4) {
			maxt4 = c[i].temp4;
		}
		if (c[i].temp4 < mint4) {
			mint4 = c[i].temp4;
		}
	}
	float maxs = 0;
	int n9 = -1;
	float mins = 100;
	int n10 = -1;
	for (int i = 0; i < c.size(); i++) {
		float h = (float)(c[i].temp1 + c[i].temp2 + c[i].temp3 + c[i].temp4) / 4;
		if (h > maxs) {
			maxs = h;
			n9 = i;
		}
		if (h < mins) {
			mins = h;
			n10 = i;
		}
	}
	int max = maxt1;
	int min = mint1;
	cout << "Max temperature : " << max << endl;
	for (int i = 0; i < c.size(); i++) {
		if (max == c[i].temp1) {
			cout << c[i].name << " summer " << endl;
		}
		if (max == c[i].temp2) {
			cout << c[i].name << " spring " << endl;
		}
		if (max == c[i].temp3) {
			cout << c[i].name << " autumn " << endl;
		}
		if (max == c[i].temp4) {
			cout << c[i].name << " winter " << endl;
		}
	}
	cout << "Min temperature : " << min << "," << endl;
	for (int i = 0; i < c.size(); i++) {
		if (min == c[i].temp1) {
			cout << c[i].name << " summer " << endl;
		}
		if (min == c[i].temp2) {
			cout << c[i].name << " autumn " << endl;
		}
		if (min == c[i].temp3) {
			cout << c[i].name << " winter " << endl;
		}
		if (min == c[i].temp4) {
			cout << c[i].name << " spring " << endl;
		}
	}
}




void th(deque<country>& c) {
	cout << "Enter \">\" or \"<\"" << endl;
	char f;
	cin >> f;
	cout << "Enter \"summer\",\"autumn\", \"winter\"  or \"spring\"" << endl;
	string ff;
	cin >> ff;
	if (f == '<' && ff == "summer") {
		deque<country>first;
		for (int i = 0; i < c.size(); i++) {
			first.push_back(c[i]);
		}
	again:
		for (int i = 0; i < c.size(); i++) {
			for (int j = i + 1; j < c.size(); j++) {
				if (first[i].temp1 > first[j].temp1) {
					country help = first[i];
					first[i] = first[j];
					first[j] = help;
					goto again;
				}
			}
		}
		for (int i = 0; i < c.size(); i++) {
			cout << first[i].name << endl;
		}
	}
	else if (f == '<' && ff == "autumn") {
		deque<country>first;
		for (int i = 0; i < c.size(); i++) {
			first.push_back(c[i]);
		}
	again1:
		for (int i = 0; i < c.size(); i++) {
			for (int j = i + 1; j < c.size(); j++) {
				if (first[i].temp2 > first[j].temp2) {
					country help = first[i];
					first[i] = first[j];
					first[j] = help;
					goto again1;
				}
			}
		}
		for (int i = 0; i < c.size(); i++) {
			cout << first[i].name << endl;
		}
	}
	else if (f == '<' && ff == "winter") {
		deque<country>first;
		for (int i = 0; i < c.size(); i++) {
			first.push_back(c[i]);
		}
	again2:
		for (int i = 0; i < c.size(); i++) {
			for (int j = i + 1; j < c.size(); j++) {
				if (first[i].temp3 > first[j].temp3) {
					country help = first[i];
					first[i] = first[j];
					first[j] = help;
					goto again2;
				}
			}
		}
		for (int i = 0; i < c.size(); i++) {
			cout << first[i].name << endl;
		}
	}
	else if (f == '<' && ff == "spring") {
		deque<country>first;
		for (int i = 0; i < c.size(); i++) {
			first.push_back(c[i]);
		}
	again3:
		for (int i = 0; i < c.size(); i++) {
			for (int j = i + 1; j < c.size(); j++) {
				if (first[i].temp4 > first[j].temp4) {
					country help = first[i];
					first[i] = first[j];
					first[j] = help;
					goto again3;
				}
			}
		}
		for (int i = 0; i < c.size(); i++) {
			cout << first[i].name << endl;
		}
	}
	else if (f == '>' && ff == "summer") {
		deque<country>first;
		for (int i = 0; i < c.size(); i++) {
			first.push_back(c[i]);
		}
	again5:
		for (int i = 0; i < c.size(); i++) {
			for (int j = i + 1; j < c.size(); j++) {
				if (first[i].temp1 < first[j].temp1) {
					country help = first[i];
					first[i] = first[j];
					first[j] = help;
					goto again5;
				}
			}
		}
		for (int i = 0; i < c.size(); i++) {
			cout << first[i].name << endl;
		}
	}
	else if (f == '>' && ff == "autumn") {
		deque<country>first;
		for (int i = 0; i < c.size(); i++) {
			first.push_back(c[i]);
		}
	again6:
		for (int i = 0; i < c.size(); i++) {
			for (int j = i + 1; j < c.size(); j++) {
				if (first[i].temp2 < first[j].temp2) {
					country help = first[i];
					first[i] = first[j];
					first[j] = help;
					goto again6;
				}
			}
		}
		for (int i = 0; i < c.size(); i++) {
			cout << first[i].name << endl;
		}
	}
	else if (f == '>' && ff == "winter") {
		deque<country>first;
		for (int i = 0; i < c.size(); i++) {
			first.push_back(c[i]);
		}
	again7:
		for (int i = 0; i < c.size(); i++) {
			for (int j = i + 1; j < c.size(); j++) {
				if (first[i].temp3 < first[j].temp3) {
					country help = first[i];
					first[i] = first[j];
					first[j] = help;
					goto again7;
				}
			}
		}
		for (int i = 0; i < c.size(); i++) {
			cout << first[i].name << endl;
		}
	}
	else if (f == '>' && ff == "spring") {
		deque<country>first;
		for (int i = 0; i < c.size(); i++) {
			first.push_back(c[i]);
		}
	again8:
		for (int i = 0; i < c.size(); i++) {
			for (int j = i + 1; j < c.size(); j++) {
				if (first[i].temp4 < first[j].temp4) {
					country help = first[i];
					first[i] = first[j];
					first[j] = help;
					goto again8;
				}
			}
		}
		for (int i = 0; i < c.size(); i++) {
			cout << first[i].name << endl;
		}
	}
	else {
		cout << "Incorrect";
	}
}





void fo(deque<country>& c) {
	cout << "Countries, that have temperature in summer higher than 30*C :" << endl;
	bool y = false;
	for (int i = 0; i < c.size(); i++) {
		if (c[i].temp1 > 30) {
			cout << " " << c[i].name << endl;
			y = true;
		}
	}
	if (!y) {
		cout << "onyone";
	}
	cout << "Countries, that have negative temperature in winter : " << endl;
	bool yy = false;
	for (int i = 0; i < c.size(); i++) {
		if (c[i].temp3 < 0) {
			cout << " " << c[i].name << endl;
			yy = true;
		}
	}
	if (!yy) {
		cout << "onyone";
	}
}

void fiv(deque<country>& c) {
	cout << "Enter country" << endl;
	string hhh = "";
	cin.ignore();
	getline(cin, hhh);
	//cin >> hhh;
	int jj = -2;
	int maxh;
	int minh;
	for (int i = 0; i < c.size(); i++) {
		if (hhh == c[i].name) {
			jj = i;
			maxh = c[i].temp1;
			minh = c[i].temp1;
			if (c[i].temp2 > maxh) maxh = c[i].temp2;
			if (c[i].temp3 > maxh) maxh = c[i].temp3;
			if (c[i].temp4 > maxh) maxh = c[i].temp4;
			if (c[i].temp2 < minh) minh = c[i].temp2;
			if (c[i].temp3 < minh) minh = c[i].temp3;
			if (c[i].temp4 < minh) minh = c[i].temp4;
			cout << "Max temperature for your country : " << maxh << endl;
			cout << "Min temperature for your country : " << minh << endl;
			cout << "Average temperature for your country : " << (float)(c[i].temp1 + c[i].temp2 + c[i].temp3 + c[i].temp4) / 4 << endl;
			break;
		}
	}
	if (!(jj >= 0 && jj < c.size())) {
		cout << "Incorrect" << endl;
		return;
	}
	int kk;
	bool fff = false;
	bool sss = false;
	cout << "Enter your temperature";
	cin >> kk;
	if (c[jj].temp1 > kk) {
		fff = true;
	}
	if (c[jj].temp2 > kk) {
		fff = true;
	}
	if (c[jj].temp3 > kk) {
		fff = true;
	}
	if (c[jj].temp4 > kk) {
		fff = true;
	}
	if (c[jj].temp1 < kk) {
		sss = true;
	}
	if (c[jj].temp2 < kk) {
		sss = true;
	}
	if (c[jj].temp3 < kk) {
		sss = true;
	}
	if (c[jj].temp4 < kk) {
		sss = true;
	}
	if (fff) {
		cout << "There is temperature higher your" << endl;
	}
	else {
		cout << "There isn't temperature higher your" << endl;
	}
	if (sss) {
		cout << "There is temperature lower your" << endl;
	}
	else {
		cout << "There isn't temperature lower your" << endl;
	}
	cout << "Difference between max and min temperatures = " << maxh - minh;
}
