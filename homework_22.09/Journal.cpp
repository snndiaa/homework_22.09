#include "Journal.h"
#include <iostream>

using namespace std;

int Journal::object_count = 0;

Journal::Journal()
{
    name = new char[1];
    name[0] = '\0';

    foundation_year = 0;

    description = new char[1];
    description[0] = '\0';

    phone = new char[1];
    phone[0] = '\0';

    email = new char[1];
    email[0] = '\0';

    object_count++;
}

Journal::Journal(char* name, int year, char* desc, char* phone, char* email)
    : foundation_year(year)
{
    this->name = new char[strlen(name) + 1];
    strcpy_s(this->name, strlen(name) + 1, name);

    this->description = new char[strlen(desc) + 1];
    strcpy_s(this->description, strlen(desc) + 1, desc);

    this->phone = new char[strlen(phone) + 1];
    strcpy_s(this->phone, strlen(phone) + 1, phone);

    this->email = new char[strlen(email) + 1];
    strcpy_s(this->email, strlen(email) + 1, email);

    object_count++;
}

Journal::~Journal()
{
    delete[] name;
    delete[] description;
    delete[] phone;
    delete[] email;
}

Journal::Journal(Journal& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy_s(name, strlen(other.name) + 1, other.name);

    description = new char[strlen(other.description) + 1];
    strcpy_s(description, strlen(other.description) + 1, other.description);

    phone = new char[strlen(other.phone) + 1];
    strcpy_s(phone, strlen(other.phone) + 1, other.phone);

    email = new char[strlen(other.email) + 1];
    strcpy_s(email, strlen(other.email) + 1, other.email);

    foundation_year = other.foundation_year;
    object_count++;
}

Journal::Journal(Journal&& other)
{
    name = other.name;
    other.name = nullptr;

    description = other.description;
    other.description = nullptr;

    phone = other.phone;
    other.phone = nullptr;

    email = other.email;
    other.email = nullptr;

    foundation_year = other.foundation_year;
    other.foundation_year = 0;
}

void Journal::setName(char* name)
{
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy_s(this->name, strlen(name) + 1, name);
}

char* Journal::getName()
{
    return name;
}

void Journal::setFoundationYear(int year)
{
    foundation_year = year;
}

int Journal::getFoundationYear()
{
    return foundation_year;
}

void Journal::setDescription(char* desc)
{
    delete[] description;
    description = new char[strlen(desc) + 1];
    strcpy_s(description, strlen(desc) + 1, desc);
}

char* Journal::getDescription()
{
    return description;
}

void Journal::setPhone(char* phone)
{
    delete[] this->phone;
    this->phone = new char[strlen(phone) + 1];
    strcpy_s(this->phone, strlen(phone) + 1, phone);
}

char* Journal::getPhone()
{
    return phone;
}

void Journal::setEmail(char* email)
{
    delete[] this->email;
    this->email = new char[strlen(email) + 1];
    strcpy_s(this->email, strlen(email) + 1, email);
}

char* Journal::getEmail()
{
    return email;
}

void Journal::input()
{
    char buffer[256];

    cout << "Enter journal name: ";
    cin.getline(buffer, 256);
    setName(buffer);

    cout << "Enter foundation year: ";
    cin >> foundation_year;
    cin.ignore();

    cout << "Enter description: ";
    cin.getline(buffer, 256);
    setDescription(buffer);

    cout << "Enter phone: ";
    cin.getline(buffer, 256);
    setPhone(buffer);

    cout << "Enter email: ";
    cin.getline(buffer, 256);
    setEmail(buffer);
}

void Journal::print()
{
    cout << "Journal Name: " << name << endl;
    cout << "Foundation Year: " << foundation_year << endl;
    cout << "Description: " << description << endl;
    cout << "Phone: " << phone << endl;
    cout << "Email: " << email << endl;
}

int Journal::getObjectCount()
{
    return object_count;
}