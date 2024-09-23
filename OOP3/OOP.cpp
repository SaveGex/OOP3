#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime>
#include <vector>

#include "SQLite.h"
#include "Person.h"

using namespace std;

int Person::counter = 0;


void print_array(vector<Person> people);

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	srand(static_cast<int>(time(nullptr)));

	vector<Person> people{ create_DB() };
	uint16_t index = 0, index_flat = 1;
	bool ticket = true;

	while (ticket) {
		int choose;
		cout << "Print full info about someone[1]\n print all people in array[2]";
		cin >> choose;
		switch (choose) {
		case 1:	
			int someone;
			cin >> someone;
			(someone > people.size() - 1 || someone < 0) ? someone = 0 : someone = someone;
			people[someone].print_all();
			break;
		case 2:	print_array(people); break;
		default: ticket = !ticket; break;
		}
	}



	return 0;
}



void print_array(vector<Person> people) {
	for (Person pep : people) {
		pep.print_all();
	}
}