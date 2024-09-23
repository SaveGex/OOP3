#ifndef PERSON_H
#define PERSON_H

#include <cstdint> // ��� uint16_t
#include <Windows.h>
#include <string>


using namespace std;

#pragma region Data_classes

class Name {
public:
	string name;
	string surname;
	string middle_name;

	// ����������� � �����������
	Name(const string& name = "", const string& surname = "", const string& middle_name = "")
		: name(name), surname(surname), middle_name(middle_name) {}

	// ����������� ���������
	Name(const Name& other) : name(other.name), surname(other.surname), middle_name(other.middle_name) {}

	Name& operator=(const Name& other) {
		if (this == &other) return *this;
		name = other.name;
		surname = other.surname;
		middle_name = other.middle_name;
		return *this;
	}
};


class Date {
public:
	uint16_t year;
	uint16_t month;
	uint16_t day;
};
#pragma endregion

class Person {
private:
	uint16_t id;
	Name data_of_name;
	Date data_of_date;
	static int counter;

	static void cros_counter() {
		counter++;
	}

public:    
	
	static uint16_t getter_counter() { return counter; }
	Person(uint16_t idet, Name nickname, uint16_t year, uint16_t month, uint16_t day);
	Person(const Person& obj){
		
	};
	Person(Person&& object);
	Person() = default;
	//Person();
	Name getter_Fname();
	uint16_t getter_id();
	string getter_date();
	uint8_t generete_age_for_person() {
		return 8 + rand() % (60);
	}
	void setter_name(Name new_name);
	void setter_date(Date data_of_date);
	void setter_date();
	void print_all();
	//~Person();
};
#endif