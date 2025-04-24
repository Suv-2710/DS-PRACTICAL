#include <iostream>
using namespace std;

class Student {
private:
    string name, address;
    int prn;
    int percentage;

    // Arrays to replace vectors
    int mychain[10];
    int mykey[10];

public:
    Student() {
        prn = -1;
        name = address = "";
        percentage = 0;
        // Initialize arrays
        for (int i = 0; i < 10; i++) {
            mychain[i] = -2; // Initial value for chain
            mykey[i] = -1;   // Initial value for keys
        }
    }

    void accept();
    void table();
};

// Global hash table object
Student H[10];

// Accept student records
void Student::accept() {
    int n;
    cout << "Enter the number of records: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Student s;
        cout << "\nEnter PRN: ";
        cin >> s.prn;
        cout << "Enter Name: ";
        cin >> s.name;
        cout << "Enter Address: ";
        cin >> s.address;
        cout << "Enter Percentage: ";
        cin >> s.percentage;

        int loc = s.prn % 10; // Hash function
        int originalloc = loc;

        // Handle collisions using linear probing
        while (mykey[loc] != -1) 
        {
            loc = (loc + 1) % 10;
            if (loc == originalloc) 
            {
                cout << "Hash table is full.\n";
                return;
            }
        }

        mykey[loc] = s.prn;
        H[loc] = s;
    }
}

// Display hash table
void Student::table() {
    cout << "\nPRN\tName\t\tAddress\t\tPercentage\n";
    for (int i = 0; i < 10; i++) {
        if (mykey[i] != -1) {
            cout << i << "\t" << H[i].prn << "\t" << H[i].name
                 << "\t\t" << H[i].address << "\t\t" << H[i].percentage << "\n";
        } else {
            cout << i << "\t" << "-\t" << "-\t\t" << "-\t\t" << "-" << "\n";
        }
    }
}

int main() {
    Student s;
    int choice;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student Records\n";
        cout << "2. Display Hash Table\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            s.accept();
            break;
        case 2:
            s.table();
            break;
        case 3:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
