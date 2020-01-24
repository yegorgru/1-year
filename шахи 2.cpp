#include <iostream>
#include <deque>
using namespace std;




struct queen {
	char pos1;
	char pos2;
	int fn;
};


//Task: user enters positions of queens. To output queens that beats each other

int main()
{
	deque<int>what_beats;
	int c, b;
	int e, f;
	int number;
	cout << "Enter number of queens" << endl;
	cin >> number;
	queen a;

	//Record of queens in deque
	deque<queen>q;
	for (int i = 0; i < number; i++) {
		q.push_front(a);
	}
	for (int i = 0; i < number; i++) {
		cout << "Enter coordinates of queen" << endl;
		cin >> q[i].pos1 >> q[i].pos2;
		q[i].fn = i + 1;
	}

	//Sorting of queens
	char copy_pos1;
	char copy_pos2;
	int copy_fn;
	again:
	for (int i = 0; i < number; i++) {
		for (int j = i + 1; j < number; j++) {
			copy_pos1 = q[i].pos1;
			copy_pos2 = q[i].pos2;
			copy_fn = q[i].fn;
			if (q[i].pos1 > q[j].pos1|| (q[i].pos1 == q[j].pos1&& q[i].pos2 > q[j].pos2)) {
				q[i].pos1 = q[j].pos1;
				q[j].pos1 = copy_pos1;
				q[i].pos2 = q[j].pos2;
				q[j].pos2 = copy_pos2;
				q[i].fn = q[j].fn;
				q[j].fn = copy_fn;
				goto again;
			}
			else if (q[i].pos1 == q[j].pos1 && q[i].pos2 == q[j].pos2) {
				q.erase(q.begin() + j);
				number = q.size();
				goto again;
			}
		}
	}
	//Record queens that beat each other
	for (int i = 0; i < number; i++) {
		for (int j = i+1; j < number; j++) {
			c = q[i].pos1 - q[j].pos1;
			b = q[i].pos2 - q[j].pos2;
			if (c == b) {
				what_beats.push_back(q[i].fn);
				what_beats.push_back(q[j].fn);
				break;
			}
		}
	}
	for (int i = 0; i < number; i++) {
		for (int j = i + 1; j < number; j++) {
			c = q[i].pos1 - q[j].pos1;
			b = q[i].pos2 - q[j].pos2;
			if (c == -b) {
				what_beats.push_back(q[i].fn);
				what_beats.push_back(q[j].fn);
				break;
			}
		}
	}
	for (int i = 0; i < number; i++) {
		for (int j = i + 1; j < number; j++) {
			if (q[i].pos1 == q[j].pos1) {
				what_beats.push_back(q[i].fn);
				what_beats.push_back(q[j].fn);
				break;
			}
		}
	}
	for (int i = 0; i < number; i++) {
		for (int j = i + 1; j < number; j++) {
			if (q[i].pos2 == q[j].pos2) {
				what_beats.push_back(q[i].fn);
				what_beats.push_back(q[j].fn);
				break;
			}
		}
	}
	//Showing of answer
	if (!what_beats.empty()) {
		for (int i = 0; i < what_beats.size()/2; i++) {
			cout <<"Queen "<<what_beats[2*i]<<" beats queen "<< what_beats[2*i+1]<<" and conversely\n";
		}
	}
}
