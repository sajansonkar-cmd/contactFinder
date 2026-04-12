#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 100;

struct Contact {
    string name;
    string phone;
};

Contact contacts[MAX];
int countContacts = 0;

// Add contact
void addContact(string name, string phone) {
    if (countContacts >= MAX) {
        cout << "Contact list full\n";
        return;
    }
    contacts[countContacts].name = name;
    contacts[countContacts].phone = phone;
    countContacts++;
}

// Search by name
int searchByName(string name) {
    for (int i = 0; i < countContacts; i++) {
        if (contacts[i].name == name) {
            return i;
        }
    }
    return -1;
}

// Search by phone
int searchByPhone(string phone) {
    for (int i = 0; i < countContacts; i++) {
        if (contacts[i].phone == phone) {
            return i;
        }
    }
    return -1;
}

// Update contact
void updateContact(string name) {
    int index = searchByName(name);
    if (index == -1) {
        cout << "Contact not found\n";
        return;
    }

    string newPhone;
    cout << "Enter new phone: ";
    cin >> newPhone;
    contacts[index].phone = newPhone;
    cout << "Updated successfully\n";
}

// Display all contacts
void displayContacts() {
    if (countContacts == 0) {
        cout << "No contacts available\n";
        return;
    }

    for (int i = 0; i < countContacts; i++) {
        cout << i + 1 << ". " << contacts[i].name 
             << " - " << contacts[i].phone << endl;
    }
}

void deleteContact(string name) {
    int index = searchByName(name);

    if (index == -1) {
        cout << "Contact not found\n";
        return;
    }

    // Shift elements left
    for (int i = index; i < countContacts - 1; i++) {
        contacts[i] = contacts[i + 1];
    }

    countContacts--;
    cout << "Contact deleted successfully\n";
}

string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {
    int choice;
    string name, phone;

    while (true) {
        cout << "\n--- Contact Finder ---\n";
        cout << "1. Add Contact\n";
        cout << "2. Search by Name\n";
        cout << "3. Search by Phone\n";
        cout << "4. Update Contact\n";
        cout << "5. Display All\n";
        cout << "6. Delete Contact\n";
cout << "7. Exit\n";
cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
    cout << "Enter name: ";
    cin.ignore(); // VERY IMPORTANT
    getline(cin, name);

    cout << "Enter phone: ";
    getline(cin, phone);

    addContact(name, phone);
    break;

       case 2:
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);

    {
        bool found = false;

        for (int i = 0; i < countContacts; i++) {
            string searchName = toLowerCase(name);
string contactName = toLowerCase(contacts[i].name);

if (contactName.find(searchName) != string::npos) {
                if (!found) {
                    cout << "Matching Contacts:\n";
                }
                found = true;

                cout << "Name: " << contacts[i].name << endl;
                cout << "Phone: " << contacts[i].phone << endl;
                cout << "------------------\n";
            }
        }

        if (!found) {
            cout << "No contact found\n";
        }
    }
    break;

       case 3:
    cout << "Enter phone: ";
    cin.ignore();
    getline(cin, phone);

    {
        int index = searchByPhone(phone);
        if (index != -1) {
            cout << "Contact Found:\n";
            cout << "Name: " << contacts[index].name << endl;
            cout << "Phone: " << contacts[index].phone << endl;
        } else {
            cout << "Not Found\n";
        }
    }
    break;

        case 4:
            cout << "Enter name to update: ";
            cin.ignore();
            getline(cin, name);
            updateContact(name);
            break;

        case 5:
            displayContacts();
            break;

        case 6:
    cout << "Enter name to delete: ";
    cin.ignore();
    getline(cin, name);
    deleteContact(name);
    break;

case 7:
    cout << "Exiting...\n";
    return 0;

        default:
            cout << "Invalid choice\n";
        }
    }
}