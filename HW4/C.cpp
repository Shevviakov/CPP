/*
	Телефонная книга
Необходимо разработать программу, которая является промежуточным звеном в реализации телефонной книги. На вход подаётся N ≤ 1000 команд вида
ADD User Number
DELETE User
EDITPHONE User Number
PRINT User
Согласно этим командам нужно соответственно добавить пользователя в телефонную книгу, удалить пользователя, изменить его номер и вывести на экран его данные. В случае невозможности выполнить действие, необходимо вывести ERROR. Добавлять пользователя, уже существующего в телефонной книге нельзя.
Необходимо вывести протокол работы телефонной книге
	Input format
	Output format
В случае невозможности выполнения действия
ERROR
В случае команды PRINT User
User Number
	Examples
Input				Output
9
ADD IVAN 1178927
PRINT PETER
ADD EGOR 123412
PRINT IVAN
EDITPHONE IVAN 112358
PRINT IVAN
PRINT EGOR
DELETE EGOR
EDITPHONE EGOR 123456
				ERROR
				IVAN 1178927
				IVAN 112358
				EGOR 123412
				ERROR
	Notes
Вы должны использовать любую структуру данных, изученную на лекции, и реализованную вами. В случае использовании структуры данных из стандартной библиотеки, задача оценивается в половину баллов.
*/

#include <iostream>
#include <string>

using namespace std;


class contactCard {
	public:
	string num;
	string name;
	contactCard* next;
	
	contactCard () {
		next = NULL;
	}
	contactCard (string str, string tel) {
		name = str;
		num = tel;
		next = NULL;
	}
};

class phoneBook {
	
	contactCard *head;
	
	void error () {
		cout << "ERROR" << endl;
	}
	
	public:
		phoneBook () {
			head = new contactCard();
		}

		void add (string name, string num) {
			if (!head->next) {
				head->next = new contactCard(name, num);
				return;
			} else {
				contactCard *contact = new contactCard ();
				contact = head;
				while (contact->next) {
					if (name == contact->next->name) {
						error();
						return;
					}
					contact = contact->next;
				}
				contact->next = new contactCard(name, num);
			}
		}

		void del (string name) {
			contactCard *contact = new contactCard ();
			contact = head;
			while (contact->next) {
				if (name == contact->next->name) {
					contact->next = contact->next->next;
					return;
				}
				contact = contact->next;
			}
			error();
		}

		void edit (string name, string num) {
			contactCard *contact = new contactCard ();
			contact = head;
			while (contact->next) {
				if (name == contact->next->name) {
					contact->next->num = num;
					return;
				}
				contact = contact->next;
			}
			error();
		}

		void print (string name) {
			contactCard *contact = new contactCard ();
			contact = head;
			while (contact->next) {
				if (name == contact->next->name) {
					cout << contact->next->name << ' ' << contact->next->num << endl;
					return;
				}
				contact = contact->next;
			}
			error();
		}
		
};

int main () {
	
	int N;
	string cmd, name, num;
	
	phoneBook pb;
	
	cin >> N;
	
	for (int i=0; i<N; i++) {
		cin >> cmd;
		if (cmd == "ADD") {
			cin >> name >> num;
			pb.add(name, num);
			continue;
		}
		if (cmd == "DELETE") {
			cin >> name;
			pb.del(name);
			continue;
		}
		if (cmd == "PRINT") {
			cin >> name;
			pb.print(name);
			continue;
		}
		if (cmd == "EDITPHONE") {
			cin >> name >> num;
			pb.edit(name, num);
			continue;
		}
		cout << "ERROR" << endl;
	}
	
	return 0;
}
