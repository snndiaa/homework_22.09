#include <iostream>
#include "Journal.h"

using namespace std;

void print_menu() {
    cout << "Journal Menu" << endl;
    cout << "1. Show current journal info" << endl;
    cout << "2. Edit all journal info (using input())" << endl;
    cout << "3. Change journal name" << endl;
    cout << "4. Change foundation year" << endl;
    cout << "5. Show total object count" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    char name[] = "Vogue";
    char desc[] = "Fashion & Lifestyle magazine";
    char phone[] = "1-800-VOGUE";
    char email[] = "contact@vogue.com";
    Journal my_journal(name, 1892, desc, phone, email);

    cout << "Welcome! An initial journal has been created." << endl;
    my_journal.print();

    int choice;
    const int BUFFER_SIZE = 256;
    char temp_buffer[BUFFER_SIZE];
    int new_year;

    while (true) {
        print_menu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Current Journal Data" << endl;
            my_journal.print();
            break;

        case 2:
            cout << "Enter New Journal Data" << endl;
            my_journal.input();
            cout << "Journal updated successfully" << endl;
            break;

        case 3:
            cout << "Enter new name: ";
            cin.getline(temp_buffer, BUFFER_SIZE);
            my_journal.setName(temp_buffer);
            cout << "Name updated successfully" << endl;
            break;

        case 4:
            cout << "Enter new foundation year: ";
            cin >> new_year;
            my_journal.setFoundationYear(new_year);
            cout << "Year updated successfully" << endl;
            break;

        case 5:
            cout << "Total Journal objects ever created: " << Journal::getObjectCount() << endl;
            break;

        case 0:
            cout << "Bye" << endl;
            return 0;

        default:
            cout << "error" << endl;
            break;
        }
    }

    return 0;
}