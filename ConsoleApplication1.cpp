#include "Header.h"



int what_mode = 0;
string user_name;
string address="planer.txt";




void main() {
	cout.setf(ios_base::boolalpha);
	//Launch of programm. Checking if it is first launch off programm. Getting of user's name. Creating of data base. Greeting
	ifstream PLANERin;
	bool FirstLaunch = false;
	do {
		PLANERin.open("planer.txt");
		if (!PLANERin) {
			FirstLaunch = true;
			cout << "It is the first launch of PLANER, enter your name please" << endl << endl;
			ofstream PLANERout;
			PLANERout.open("planer.txt");
			ofstream PLANERDates;
			PLANERDates.open("dates.txt");
			getline(cin, user_name);
			PLANERout << user_name << endl << 0;
			cout << "Hello " << user_name << "!\n" <<
				"This program was created to be reliable storage of your plans, aims, thoughts\n"
				<< "let's start!\n";
			PLANERout.close();
		}
	} while (!PLANERin);
	getline(PLANERin, user_name);
	if (!FirstLaunch) {
		cout << "Hi, " << user_name << "!\n";
	}

	//get all affairs
	deque<Affair>all_affairs;
	while (!PLANERin.eof()) {
		Affair Ahelp;
		PLANERin >> Ahelp;
		all_affairs.push_back(Ahelp);
	}
	sort_affairs(all_affairs);
	main_menu(all_affairs);
}






