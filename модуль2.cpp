#include <iostream>
#include<fstream>
using namespace std;


bool numbers(char *a,char *b) {
	for (int i = 0; i < 50; i++) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;
}

bool strings(char* a, char* b) {
	for (int i = 0; i < 50; i++) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;
}



bool check(char* a, char* b,bool(*foop)(char* a, char* b)) {
	if (foop == numbers) {
		return numbers(a, b);
	}
	else if (foop == strings) {
		return strings(a, b);
	}
}

int second(int a, int b) {
	if (a == b) {
		return a;
	}
	else if (a > b) {
		return second(a - b, b);
	}
	else {
		return second(a, b - a);
	}
}


void third() {
	ifstream fin;
	fin.open("eng_in.txt");
	ofstream fout;
	fout.open("eng_out.txt");
	char a[50];
	while (fin >> a) {
		if (a[0] == '-') {
			continue;
		}
		char b[] = { 'a','e','i','o','u','A','E','I','O','U','y','Y' };
		bool y = false;
		for (int i = 0; i < 12; i++) {
			if (a[0] == b[i]) {
				y = true;
			}
		}
		bool z = false;
		for (int i = 0; i < 50; i++) {
			if (!((a[i] > 64 && a[i] < 91)||(a[i] > 96 && a[i] < 123))) {
				if (a[i - 1] == '.' || a[i - 1] == ',' || a[i - 1] == ':' || a[i - 1] == '!' || a[i - 1] == '?') {
					for (int j = 0; j < 12; j++) {
						if (a[i - 2] == b[j]) {
							z = true;
						}
					}
				}
				for (int j = 0; j < 12; j++) {
					if (a[i - 1] == b[j]) {
						z = true;
					}
				}
			}
		}
		if (y||!z) {
			continue;
		}
		int count = 0;
		for (int i = 0; (a[i] > 64 && a[i] < 91) || (a[i] > 96 && a[i] < 123) &&i<50; i++) {
			for (int j = 0; j < 12; j++) {
				if (a[i] == b[j]) {
					count++;
				}
			}
		}
		if (count > 1) {
			for (int k = 0; (a[k] > 64 && a[k] < 91) || (a[k] > 96 && a[k] < 123) && k < 50; k++) {
				fout << a[k];
			}
			fout << '\n';
		}
	}
	fin.close();
	fout.close();
}


void fourth() {
	ifstream fin;
	fin.open("names.txt");
	char a[200];
	char aa[2][20][20];
	for (int r = 0; r < 2; r++) {
		for (int i = 0; i < 200; i++) {
			a[i] = ' ';
		}
		fin.getline(a, 200);
		int count = 0;
		for (int i = 0; a[i] != '\0' && i < 200; i++) {
			if (a[i] == ' ') {
				continue;
			}
			for (int j = 0; a[i] != '\0' && j < 20; j++) {
				if (a[i] == ' ') {
					count++;
					i++;
					j = 0;
					continue;
				}
				aa[r][count][j] = a[i];
				i++;
			}
		}
		for (int i = 1; i < 20; i++) {
			for (int j = 0; j < 19; j++) {
				aa[r][i][j] = aa[r][i][j + 1];
			}
		}
	}
	fin.close();
	char bb[20][20];
	int coo = 0;
	for (int i = 0; i < 20; i++) {
		if (!(aa[0][i][0] > 64 && aa[0][i][0] < 91) || (aa[0][i][0] > 96 && aa[0][i][0] < 123)) {
			continue;
		}
		for (int j = 0; j < 20; j++) {
			if (!(aa[0][j][0] > 64 && aa[0][j][0] < 91) || (aa[0][j][0] > 96 && aa[0][j][0] < 123)) {
				continue;
			}
			bool yy = false;
			for (int k = 0; k < 20; k++) {
				if (aa[0][i][k] != aa[1][j][k]) {
					yy = true;
					break;
				}
			}
			if (yy) {
				continue;
			}
			for (int kk = 0; kk < 20; kk++) {
				bb[coo][kk] = aa[0][i][kk];
			}
			coo++;
		}
	}
	for (int i = 0; i < 20; i++) {
		if (!(bb[i][0] > 64 && bb[i][0] < 91) || (bb[i][0] > 96 && bb[i][0] < 123)) {
			break;
		}
		for (int j = 0; j < 20; j++) {
			if (!(bb[i][j] > 64 && bb[i][j] < 123)) {
				break;
			}
			cout << bb[i][j];
		}
		cout << "\n";
	}
	cout << endl << endl;
	int j;
	for (j = 0; j < 20; j++) {
		bool yyy = false;
		for (int i = 0; i < 20; i++) {
			for (int k = 0; k < 20; k++) {
				if (aa[0][j][k] == bb[i][k]) {
					yyy = true;
					continue;
				}
				if (aa[0][j][k] != bb[i][k]) {
					yyy = false;
					break;
				}
			}
			if (yyy == true)  break;
		}
		if (!yyy) {
			if (!(aa[0][j][0] > 64 && aa[0][j][0] < 91) || (aa[0][j][0] > 96 && aa[0][j][0] < 123)) {
				continue;
			}
			for (int kk = 0; kk < 20; kk++) {
				if (!(aa[0][j][kk] > 64 && aa[0][j][kk] < 123)) {
					break;
				}
				cout << aa[0][j][kk];
			}
			cout << endl;
		}
	}
	for (j = 0; j < 20; j++) {
		bool yyy = false;
		for (int i = 0; i < 20; i++) {
			for (int k = 0; k < 20; k++) {
				if (aa[1][j][k] == bb[i][k]) {
					yyy = true;
					continue;
				}
				if (aa[1][j][k] != bb[i][k]) {
					yyy = false;
					break;
				}
			}
			if (yyy == true)  break;
		}
		if (!yyy) {
			if (!(aa[1][j][0] > 64 && aa[1][j][0] < 91) || (aa[1][j][0] > 96 && aa[1][j][0] < 123)) {
				continue;
			}
			for (int kk = 0; kk < 20; kk++) {
				if (!(aa[1][j][kk] > 64 && aa[1][j][kk] < 123)) {
					break;
				}
				cout << aa[1][j][kk];
			}
			cout << endl;
		}
	}
}

int main()
{
	//Завдання 1
	/*char a[50];
	cin >> a;
	char b[50];
	cin >> b;
	bool(*foop)(char* a, char* b) = 0;
	if (a[0] > 47 && a[0] < 58 && b[0] > 47 && b[0] < 58) {
		foop = numbers;
	}
	else {
		foop = strings;
	}
	cout << check(a, b, foop);*/


	//Завдання 2
	/*int c;
	cin >> c;
	int d;
	cin >> d;
	cout<<second(c, d);*/




	//Завдання 3
	//third();



	//Завдання 4
	//fourth();
}

