#include "Header.h"


extern int what_mode;
extern string user_name;
extern string address;
//Перегрузка cout<< для структуры Time

std::ostream& operator<<(std::ostream& out, const Time& time)
{
	out << time.hours << " " << time.minutes;
	return out;
}


//Перегрузка cin>> для структуры Time

std::istream& operator>>(std::istream& in, Time& time)
{
	cout << "\tEnter hours\n";
	in >> time.hours;
	cout << endl;
	cout << "\tEnter minutes\n";
	in>> time.minutes;
	cout << endl;
	return in;
}


//Перегрузка ofstream<< для структуры Time

std::ofstream& operator<<(std::ofstream& out, const Time& time)
{
	out << time.hours << ' ' << time.minutes;
	return out;
}


//Перегрузка ifstream<< для структуры Time

std::ifstream& operator>>(std::ifstream& in, Time& time)
{
	in >> time.hours >> time.minutes;
	return in;
}


//Перегрузка cout<< для структуры Date

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	out << date.day <<"."<< date.month <<"."<< date.year;
	return out;
}


//Перегрузка cin>> для структуры Date

std::istream& operator>>(std::istream& in, Date& date)
{
	cout << "\tEnter day\n";
	in >> date.day;
	cout << endl;
	cout << "\tEnter month\n";
	in >> date.month;
	cout << endl;
	cout << "\tEnter year\n";
	in>> date.year;
	cout << endl;
	return in;
}


//Перегрузка ofstream<< для структуры Date

std::ofstream& operator<<(std::ofstream& out, const Date& date)
{
	out << date.day << ' ' << date.month << ' ' << date.year;
	return out;
}


//Перегрузка ifstream>> для структуры Date

std::ifstream& operator>>(std::ifstream& in, Date& date)
{
	in >> date.day >> date.month >> date.year;
	return in;
}


//Перегрузка cout<< для класса Affair

std::ostream& operator<<(std::ostream& out, const Affair& affair)
{
	out << "Name: " << affair.name << "\tType: " << affair.type <<"\tPlace: "<< affair.place << "\tImportance : " << affair.importance <<"\tDone? : "<<affair.done<< endl << affair.additional;
	return out;
}


//Перегрузка cin>> для класса Affair

std::istream& operator>>(std::istream& in, Affair& affair)
{
	cout << "Enter date:\n";
	in >> affair.date;
	cout << "Enter time:\n";
	in >> affair.time;
	in.ignore();
	cout << "Enter name\n";
	getline(in, affair.name);
	cout << "Enter type\n";
	getline(in, affair.type);
	cout << "Enter place\n";
	getline(in, affair.place);
	cout << "Enter importance (number from 1 to 3)\n";
	in>>affair.importance;
	affair.done=0;
	in.ignore();
	cout << "Enter additional\n";
	getline(in,affair.additional);
	return in;
}


//Перегрузка ofstream<< для класса Affair

std::ofstream& operator<<(std::ofstream& out, const Affair& affair)
{
	out << affair.date << endl << affair.time << endl << affair.name << endl << affair.type << endl<<affair.place<<endl << affair.importance<<endl<<affair.done << endl << affair.additional<<endl;
	return out;
}


//Перегрузка ifstream>> для класса Affair

std::ifstream& operator>>(std::ifstream& in, Affair& affair)
{
	in >> affair.date;
	in >> affair.time;
	in.ignore();
	getline(in, affair.name);
	getline(in, affair.type);
	getline(in, affair.place);
	in >> affair.importance;
	in >> affair.done;
	in.ignore();
	getline(in, affair.additional);
	return in;
}




bool operator>(Time time1, Time time2)
{
	if (time1.hours > time2.hours) {
		return true;
	}
	else if (time1.hours == time2.hours && time1.minutes > time2.minutes) {
		return true;
	}
	else return false;
}

bool operator==(Time time1, Time time2)
{
	if (time1.hours == time2.hours && time1.minutes == time2.minutes) {
		return true;
	}
	else return false;
}

bool operator==(Date date1, Date date2)
{
	if (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day) {
		return true;
	}
	else return false;
}

bool operator>(Date date1, Date date2)
{
	if ((date1.year > date2.year) || (date1.year == date2.year && date1.month > date2.month) || (date1.year == date2.year && date1.month == date2.month && date1.day > date2.day)) {
		return true;
	}
	else return false;
}










bool is_sort(deque<Affair>& ToSort)
{
	Affair help;
	for (int i = 0; i < ToSort.size(); i++) {
		for (int j = i+1; j < ToSort.size(); j++) {
			if (ToSort[i].date > ToSort[j].date) {
				help = ToSort[i];
				ToSort[i] = ToSort[j];
				ToSort[j] = help;
				return true;
			}
			else if (ToSort[i].date == ToSort[j].date && ToSort[i].time > ToSort[j].time) {
				help = ToSort[i];
				ToSort[i] = ToSort[j];
				ToSort[j] = help;
				true;
			}
		}
	}
	return false;
}

void sort_affairs(deque<Affair> &ToSort)
{
	while (is_sort(ToSort));
}



void insert_in_sorted(deque<Affair>& Sorted, Affair aff)
{
	if ((Sorted[0].date > aff.date) || (Sorted[0].date == aff.date && Sorted[0].time > aff.time)) {
		Sorted.push_front(aff);
		return;
	}
	else if ((aff.date > Sorted[Sorted.size()-1].date) || (aff.date > Sorted[Sorted.size() - 1].date && aff.time > Sorted[Sorted.size() - 1].time)) {
		Sorted.push_back(aff);
		return;
	}
	else {
		for (int i = 0; i < Sorted.size()-1; i++) {
			if (aff.date == Sorted[i].date && aff.time == Sorted[i].time) {
				Sorted.insert(Sorted.begin() + i+1, aff);
				return;
			}
			if ((aff.date > Sorted[i].date && Sorted[i+1].date > aff.date) || (aff.date == Sorted[i].date && aff.time > Sorted[i].time && Sorted[i+1].date > aff.date) || (aff.date > Sorted[i].date && aff.date == Sorted[i+1].date && Sorted[i + 1].time > aff.time) || (aff.date == Sorted[i].date && aff.time > Sorted[i].time && aff.date == Sorted[i + 1].date && Sorted[i + 1].time > aff.time)) {
				Sorted.insert(Sorted.begin() + i+1, aff);
				return;
			}
		}
	}
}

void main_menu(deque<Affair>& all_affairs)
{
	//Getting local time with www.vsokovikov.narod.ru/New_MSDN_API/Time/str_systemtime.htm
	SYSTEMTIME lt;
	GetLocalTime(&lt);
	string time = to_string(lt.wHour) + ":" + to_string(lt.wMinute) + ", " + to_string(lt.wDay) + " " + to_string(lt.wMonth) + " " + to_string(lt.wYear);
	cout << endl << "Time is :\n" << time << endl << endl;
	Date current_date = { lt.wDay,lt.wMonth,lt.wYear };



	//Today affairs
	deque<Affair>this_day_affairs;
	for (int i = 0; i < all_affairs.size(); i++) {
		if (current_date == all_affairs[i].date) {
			this_day_affairs.push_back(all_affairs[i]);
		}
	}
	cout << "Today you have this affairs:\n\n";
	for (int i = 0; i < this_day_affairs.size(); i++) {
		cout << this_day_affairs[i] << endl << endl;
	}


	//Choose mode
	cout << "Please, choose mode of session:\n"
		<< "1 - Display mode\n"
		<< "2 - Edit mode\n"
		<< "3 - Exit program\n";

	cin >> what_mode;
	if (what_mode == 1) {
		mode_display(all_affairs);
	}
	else if (what_mode == 2) {
		mode_edit(all_affairs);
	}
	else if (what_mode == 3) {
		ofstream planerout;
		planerout.open(address);
		planerout << user_name<<endl;
		for (int i = 0; i < all_affairs.size(); i++) {
			planerout << all_affairs[i];
		}
		return;
	}
}



int edit_menu() {
	int a;
	cout << "What do you want to edit?\n"
		<< "1 - to mark affair as done\n"
		<< "2 - To add affair\n"
		<< "3 - To delete affair\n"
		<< "4 - To edit affair\n"
		<< "5 - Return to main mode\n";
	cin >> a;
	return a;
}

void mode_edit(deque<Affair>& Affairs)
{
	int control = 0;
	int control_4;
	int what_edit;
	bool is_edit = false;
	string name_1;
	string name_3;
	string name_4;
	Affair affair_1;
	Affair edited;
	ofstream planerout;
	planerout.open(address);
	ifstream planerin;
	planerin.open(address);
	while (control != 5) {
		control = edit_menu();
		switch (control) {
		case 1:
			cout << "Please, enter name of affair\n";
			cin.ignore();
			getline(cin, name_1);
			for (int i = 0; i < Affairs.size(); i++) {
				if (Affairs[i].name == name_1) {
					Affairs[i].done = 1;
				}
				break;
			}
			break;
		case 2:
			cin >> affair_1;
			insert_in_sorted(Affairs, affair_1);
			break;
		case 3:
			cout << "Enter name of affair\n";
			cin.ignore();
			getline(cin, name_3);
			for (int i = 0; i < Affairs.size(); i++) {
				if (Affairs[i].name == name_3) {
					Affairs.erase(Affairs.begin()+i);
				}
				break;
			}
			break;
		case 4:
			cout << "Enter name of affair\n";
			cin.ignore();
			getline(cin, name_4);
			for (int i = 0; i < Affairs.size(); i++) {
				if (Affairs[i].name == name_4) {
					is_edit = true;
					what_edit = i;
					break;
				}
			}
			if (is_edit == false) {
				cout << "There isn't this affair\n";
				break;
			}
			cout << "What do you want to edit\n"
				<<"1 - name\n"
				<< "2 - type\n"
				<< "3 - place\n"
				<< "4 - importance\n"
				<< "5 - done\n"
				<< "6 - date\n"
				<< "7 - time\n"
				<< "8 - additional\n";
			cin >> control_4;
			switch (control_4) {
			case 1:
				cin.ignore();
				cout << "Enter new name\n";
				getline(cin, Affairs[what_edit].name);
				break;
			case 2:
				cin.ignore();
				cout << "Enter new type\n";
				getline(cin, Affairs[what_edit].type);
				break;
			case 3:
				cin.ignore();
				cout << "Enter new place\n";
				getline(cin, Affairs[what_edit].place);
				break;
			case 4:
				cout << "Enter new importance (1-3)\n";
				cin >> Affairs[what_edit].importance;
				break;
			case 5:
				cout << "Done or not done?\n";
				cin >> Affairs[what_edit].done;
				break;
			case 6:
				cout << "Enter new date\n";
				cin >> Affairs[what_edit].date;
				break;
			case 7:
				cout << "Enter new time\n";
				cin >> Affairs[what_edit].time;
				break;
			case 8:
				cout << "Enter additional\n";
				cin.ignore();
				getline(cin, Affairs[what_edit].additional);
				break;
			}
			break;
		case 5:
			main_menu(Affairs);
			return;
		}
		is_edit = false;
	}
}


int display_menu() {
	cout << "What do you want to see?\n"
		<< "1 - All affairs\n"
		<< "2 - Affair with some name\n"
		<< "3 - All affairs with special type\n"
		<< "4 - All affairs with special place\n"
		<< "5 - All affairs on some day\n"
		<< "6 - All affairs on some month\n"
		<< "7 - All affairs on some time\n"
		<< "8 - All affairs with 3-importance\n"
		<< "9 - All affairs with 2-importance\n"
		<< "10 - All affairs with 1-importance\n"
		<< "11 - All uncomplited affairs\n"
		<< "12 - All complited affairs\n"
		<< "13 - Return to main mode\n";
	int a=0;
	cin >> a;
	return a;
}





void mode_display(deque<Affair>& Affairs) {
	string his_type;
	string his_name;
	string his_place;
	int year_5 = 0;
	int month_5 = 0;
	int help_6=0;
	int help_61;
	int help_62;
	int comb_1;
	int comb_2;
	Date his_date={};
	int control = 0;
	while (control != 12) {
		control = display_menu();
		switch (control) {
		case 1:
			for (int i = 0; i < Affairs.size(); i++) {
				cout << Affairs[i] << endl;
			}
			break;
		case 2:
			cout << "Write name\n";
			cin.ignore();
			getline(cin, his_name);
			for (int i = 0; i < Affairs.size(); i++) {
				if (Affairs[i].name == his_name) {
					cout << Affairs[i] << endl;
				}
			}
			break;
		case 3:
			cout << "Write type\n";
			cin.ignore();
			getline(cin, his_type);
			for (int i = 0; i < Affairs.size(); i++) {
				if (Affairs[i].type == his_type) {
					cout << Affairs[i] << endl;
				}
			}
			break;
		case 4:
			cout << "Write place\n";
			cin.ignore();
			getline(cin, his_place);
			for (int i = 0; i < Affairs.size(); i++) {
				if (Affairs[i].place == his_place) {
					cout << Affairs[i] << endl;
				}
			}
			break;
		case 5:
			cout << "Write your date:\nyear: ";
			cin >> his_date.year;
			cout << "\nmonth: ";
			cin >> his_date.month;
			cout << "\nday: ";
			cin >> his_date.day;
			cout << endl;
			for (int i = 0; i < Affairs.size(); i++) {
				if (Affairs[i].date == his_date) {
					cout << Affairs[i] << endl;
				}
			}
			break;
		case 6:
			cout << "Write your month and year: ";
			cin >> month_5;
			cin >> year_5;
			cout << endl;
			for (int i = 0; i < Affairs.size(); i++) {
				if (Affairs[i].date.month == month_5 && Affairs[i].date.year == year_5) {
					cout << Affairs[i] << endl;
				}
			}
			break;
		case 7:
			cout << "1 - To check only hours\n2 - To check strict time\n";
			cin >> help_6;
			cout << endl;
			switch (help_6) {
			case 1:
				cout << "Write your hours: ";
				cin >> help_61;
				for (int j = 0; j < Affairs.size(); j++) {
					if (Affairs[j].time.hours == help_61) {
						cout << Affairs[j] << endl;
					}
				}
				break;
			case 2:
				cout << "Write your hours: ";
				cin >> help_61;
				cout << "\nWrite your minutes: ";
				cin >> help_62;
				cout << endl;
				for (int j = 0; j < Affairs.size(); j++) {
					if (Affairs[j].time.minutes == help_62 && Affairs[j].time.hours == help_61) {
						cout << Affairs[j] << endl;
					}
				}
				break;
			}
		case 8:
			for (int i = 0; i < Affairs.size(); i++) {
				if (Affairs[i].importance == 3) {
					cout << Affairs[i] << endl;
				}
			}
			break;
		case 9:
			for (int i = 0; i < Affairs.size(); i++) {
				if (Affairs[i].importance == 2) {
					cout << Affairs[i] << endl;
				}
			}
			break;
		case 10:
			for (int i = 0; i < Affairs.size(); i++) {
				if (Affairs[i].importance == 1) {
					cout << Affairs[i] << endl;
				}
			}
			break;
		case 11:
			for (int i = 0; i < Affairs.size(); i++) {
				if (Affairs[i].done == 0) {
					cout << Affairs[i] << endl;
				}
			}
			break;
		case 12:
			for (int i = 0; i < Affairs.size(); i++) {
				if (Affairs[i].done == 1) {
					cout << Affairs[i] << endl;
				}
			}
			break;
		case 13:
			main_menu(Affairs);
			return;
		}
	}
}

