#include <iostream>
using namespace std;

class Student {
private:
    string name, address;
    int prn;
    int percentage;

    // Arrays for hash table
    int mychain[10]; // Stores the chain for collisions
    int mykey[10];   // Stores the PRN keys

public:
    Student() {
        prn = -1;
        name = address = "";
        percentage = 0;
        // Initialize arrays
        for (int i = 0; i < 10; i++) {
            mychain[i] = -1; // -1 indicates no chain
            mykey[i] = -1;   // -1 indicates empty slot
        }
    }

    void accept();
    void table();
    void search();
    void modify();
    void deleteRecord();
    void insertWithoutReplacement(); // New method
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

        // Handle collisions using linear probing with chaining
        if (mykey[loc] == -1) {
            mykey[loc] = s.prn;
            H[loc] = s;
        } else {
            // Find the next available slot and chain it
            while (mychain[loc] != -1) {
                loc = mychain[loc];
            }
            int newLoc = (loc + 1) % 10;
            while (mykey[newLoc] != -1) {
                newLoc = (newLoc + 1) % 10;
                if (newLoc == originalloc) {
                    cout << "Hash table is full.\n";
                    return;
                }
            }
            mykey[newLoc] = s.prn;
            H[newLoc] = s;
            mychain[loc] = newLoc;
        }
    }
}

// Insert student record without replacement
void Student::insertWithoutReplacement() {
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

    // If the slot is empty, insert the record
    if (mykey[loc] == -1) {
        mykey[loc] = s.prn;
        H[loc] = s;
    } else {
        // Find the next available slot for chaining without replacing
        while (mychain[loc] != -1) {
            loc = mychain[loc];
        }
        int newLoc = (loc + 1) % 10;
        while (mykey[newLoc] != -1) {
            newLoc = (newLoc + 1) % 10;
            if (newLoc == originalloc) {
                cout << "Hash table is full.\n";
                return;
            }
        }
        mykey[newLoc] = s.prn;
        H[newLoc] = s;
        mychain[loc] = newLoc; // Chain the new record
    }
}

// Display hash table
void Student::table() {
    cout << "\nIndex\tPRN\tName\t\tAddress\t\tPercentage\tChain\n";
    for (int i = 0; i < 10; i++) {
        if (mykey[i] != -1) {
            cout << i << "\t" << mykey[i] << "\t" << H[i].name
                 << "\t\t" << H[i].address << "\t\t" << H[i].percentage
                 << "\t\t" << mychain[i] << "\n";
        } else {
            cout << i << "\t-\t-\t\t-\t\t-\t\t" << mychain[i] << "\n";
        }
    }
}

// Search for a student record
void Student::search() {
    int key;
    cout << "\nEnter the PRN to search: ";
    cin >> key;

    int loc = key % 10;
    while (loc != -1) {
        if (mykey[loc] == key) {
            cout << "Record found at index " << loc << ":\n";
            cout << "Name: " << H[loc].name
                 << ", Address: " << H[loc].address
                 << ", Percentage: " << H[loc].percentage << "\n";
            return;
        }
        loc = mychain[loc];
    }
    cout << "Record not found.\n";
}

// Modify a student record
void Student::modify() {
    int key;
    cout << "\nEnter the PRN to modify: ";
    cin >> key;

    int loc = key % 10;
    while (loc != -1) {
        if (mykey[loc] == key) {
            cout << "Record found at index " << loc << ":\n";
            cout << "Enter new Name: ";
            cin >> H[loc].name;
            cout << "Enter new Address: ";
            cin >> H[loc].address;
            cout << "Enter new Percentage: ";
            cin >> H[loc].percentage;
            cout << "Record updated successfully.\n";
            return;
        }
        loc = mychain[loc];
    }
    cout << "Record not found.\n";
}

// Delete a student record
void Student::deleteRecord() {
    int key;
    cout << "\nEnter the PRN to delete: ";
    cin >> key;

    int loc = key % 10, prev = -1;
    while (loc != -1) {
        if (mykey[loc] == key) {
            cout << "Record found at index " << loc << ". Deleting...\n";
            mykey[loc] = -1;
            if (prev != -1) {
                mychain[prev] = mychain[loc];
            }
            mychain[loc] = -1;
            H[loc] = Student(); // Reset the object at loc
            cout << "Record deleted successfully.\n";
            return;
        }
        prev = loc;
        loc = mychain[loc];
    }
    cout << "Record not found.\n";
}

int main() {
    Student s;
    int choice;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student Records\n";
        cout << "2. Insert Record without Replacement\n";
        cout << "3. Display Hash Table\n";
        cout << "4. Search for a Record\n";
        cout << "5. Modify a Record\n";
        cout << "6. Delete a Record\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            s.accept();
            break;
        case 2:
            s.insertWithoutReplacement();
            break;
        case 3:
            s.table();
            break;
        case 4:
            s.search();
            break;
        case 5:
            s.modify();
            break;
        case 6:
            s.deleteRecord();
            break;
        case 7:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
