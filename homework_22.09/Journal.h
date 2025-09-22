#pragma once

class Journal
{
private:
    char* name;
    int foundation_year;
    char* description;
    char* phone;
    char* email;

    static int object_count;

public:
    Journal();
    Journal(char* name, int year, char* desc, char* phone, char* email);
    ~Journal();

    Journal(Journal& other);
    Journal(Journal&& other);

    void setName(char* name);
    char* getName();

    void setFoundationYear(int year);
    int getFoundationYear();

    void setDescription(char* desc);
    char* getDescription();

    void setPhone(char* phone);
    char* getPhone();

    void setEmail(char* email);
    char* getEmail();

    void input();
    void print();

    static int getObjectCount();
};