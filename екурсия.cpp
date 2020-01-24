#include "Header.h"

int main()
{
	//Рекурсія 1. Драбинка Драбинка - це набір кубиків, у якому кожен вищий шар складається з меншої кількості кубиків, ніж попередній.Вивести максимальну кількість сходинок, які можна побудувати з N(1 - 100) кубиків.
	//Recursion 1. Ladder Ladder is a set of cubes in which each higher layer consists of fewer cubes than the previous one.Print the maximum number of steps that can be built from N(1 - 100) cubes.
	/*int count = 0;
	int a;
	cin >> a;
	first(a,(a+1),count);
	cout << count;*/

	//2. Перестановки Є рядок з N (1-8) попарно різних символів. Необхідно вивести всі перестановки даного рядка. 
	//2. Permutations There is a line of N(1 - 8) in different characters.It is necessary to print all permutations of this line.
	/*string s;
	cin >> s;
	deque<string>b;
	if (s.size() == 1) {
		cout << s;
	}
	else {
		perestanovka(b, 0, s);
		for (int i = 0; i < b.size(); i++) {
			cout << b[i] << endl;
		}
	}*/

	//3. Монетки Є a1,...,am номіналів монеток. У людини є по 2 монетки кожного номіналу. Їй необхідно заплатити суму N копійок. Визначити, чи можна розплатитись без здачі. Вхід: N m a1 a2 … am  Вихід: найменша кількість монет, якою можна розплатитись без здачі. Якщо  без здачі ніяк - вивести 0. Якщо наявних монет не вистачає - вивести -1. 
	//3. Coins There are a1, ..., am denominations of coins. A person has 2 coins of each face value. She needs to pay the amount of N cents. Determine if you can pay without surrendering. Input: N m a1 a2… am Output: The least amount of coins that can be paid without delivery. If without delivery - to withdraw 0. If there are not enough coins - to output -1.
	/*cout << "Hello" << endl;
	int N;
	int m;
	cin >> N >> m;
	deque<int>a;
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		a.push_back(k);
	}
	int max = 0;
	for (int i = 0; i < a.size(); i++) {
		max += 2*a[i];
	}
	sort(a);
	if (max == N) {
		cout << 2*a.size()<<endl;
		for (int i = 0; i < a.size(); i++) {
			cout << a[i] << " " << a[i] << " ";
		}
	}
	else if (max < N) {
		cout << -1;
	}
	else {
		deque<int>sum;
		cout<<coins(sum, a,false,N)<<endl;
		for (int i = 0; i < sum.size(); i++) {
			cout << sum[i] << " ";
		}
	}*/


	//4. Шаблон Є слова (складаються з великих англійських букв) і шаблони (з великих англійських букв і символів ? та *). Слово підходить під шаблон, якщо в шаблоні символ ? можна замінити на одну англійську букву, а символ * на послідовність великих англійських букв (можливо, порожню) так, що отримати слово. Необхідно написати програму, яка перевірятиме чи підходить слово під шаблон. Вхід: слово і шаблон Вихід: yes/no 
	//4. Template There are words (uppercase English letters) and patterns (uppercase English letters and characters? And *). A word fits the template if the template has a character? can be replaced by one English letter, and the * character in a sequence of capital English letters (possibly blank) to obtain the word. You need to write a program that checks if the word fits into the template. Input: word and pattern Output: yes / no
	/*string a;
	string b;
	cout << "Enter your word" << endl;
	cin >> a;
	cout << "Enter your sablon" << endl;
	cin >> b;
	cout<<sablon(a, b);*/




	/*cout << "Enter length1"<<endl;
	int N;
	cin >> N;
	cout<<"Enter length2"<<endl;
	int K;
	cin >> K;
	string s;
	cin >> s;
	if (s.size() != N||K<=0) {
		cout << "Incorrect size";
	}
	else if (K == N) {
		cout << "No";
	}
	else {
		deque<string>a;
		cod(a,s, 0,K);
		for (int i = 0; i < a.size(); i++) {
			if (a[i].size() < K) {
				a.erase(a.begin() + i);
				i--;
			}
		}
		deque<string>answer;
		for (int i = 0; i < a.size(); i++) {
			int count = 0;
			bool y = false;
			for (int k = 0; k < i; k++) {
				if (a[i] == a[k]) {
					y = true;
					break;
				}
			}
			if (y == true)   break;
			for (int j = i + 1; j < a.size(); j++) {
				if (a[j] == a[i]) {
					count++;
				}
			}
			if (count == 1) {
				answer.push_back(a[i]);
			}
		}
		if (answer.size() == 0) {
			cout << "No";
		}
		else {
			cout << "Cod may be: "<<endl;
			for (int i = 0; i < answer.size(); i++) {
				cout << answer[i] << endl;
			}
		}
	}*/





	//5. Секретний код Надійшла шифровка довжиною N. В якій знаходиться номер секретної бази: суцільний довжиною K або розбитий на частини, сума довжин яких K. Щоб цей номер точно розшифрували, в шифровку його (або кожну з його частин) включили двічі. При чому два наведення суцільного коду або якоїсь його частинки можуть перекриватись (наприклад код 121 може бути наведений як 12121), але між собою різні частинки не перекриваються. Написати програму, яка виводить код бази (якщо він суцільний) або конкатенацію частинок коду. Якщо в шифровці коду не виявлено  - вивести NO. Вхід: [довжина_коду_K] [шифровка] Вихід: [номер_бази] або NO 
	//5. Secret code Received an encryption of length N.In which there is a secret base number : a continuous length of K or broken into parts whose sum of lengths K.To include this number accurately, encrypt it(or each of its parts) twice.The two pointers of the solid code or some of its particles may overlap(for example, code 121 may be referred to as 12121), but the different particles do not overlap.Write a program that displays the base code(if it is solid) or the concatenation of code particles.If no code is detected, output NO.Input : [code_ length_K] [encryption] Output : [base_number] or NO
	/*cout << "Enter length1"<<endl;
	int N;
	cin >> N;
	cout<<"Enter length2"<<endl;
	int K;
	cin >> K;
	string s;
	cin >> s;
	if (s.size() != N||K<=0) {
		cout << "Incorrect size";
	}
	else if (K == N) {
		cout << "No";
	}
	else {
		deque<string>answer;
		for (int i = K; i > 0; i--) {
			deque<int>seconds;
			seconds.clear();
			cod1(answer, K, s, i, 0, 1, "",seconds);
		}
		if (answer.empty()) {
			cout << "No" << endl;
		}
		else {
			agai:
			for (int i = 0; i < answer.size(); i++) {
				for (int j = i + 1; j < answer.size(); j++) {
					if (answer[i] == answer[j]) {
						answer.erase(answer.begin() + j);
						j--;
					}
				}
			}
			for (int i = 0; i < answer.size(); i++) {
				cout << answer[i] << endl;
			}
		}
	}*/
}

