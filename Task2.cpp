#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void displayMenu();
void bookRoom();
void searchCustomer();
void displayAllottedRooms();
void modifyRecord();
void deleteRecord();
void displayBill();

int main() {
    char choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            bookRoom();
            break;
        case '2':
            searchCustomer();
            break;
        case '3':
            displayAllottedRooms();
            break;
        case '4':
            modifyRecord();
            break;
        case '5':
            deleteRecord();
            break;
        case '6':
            displayBill();
            break;
        case '7':
            cout << "Exiting the program. Thank you!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != '7');
    return 0;
}

void displayMenu() {
    cout << "\n======= Hotel Management System =======\n";
    cout << "1. Book a Room\n";
    cout << "2. Search Customer\n";
    cout << "3. Display Allotted Rooms\n";
    cout << "4. Modify Customer Record\n";
    cout << "5. Delete Customer Record\n";
    cout << "6. Display Customer Bill\n";
    cout << "7. Exit\n";
}

void bookRoom() {
    ofstream file("customer_data.txt", ios::app);

    cout << "\nEnter Customer Details:\n";
    cout << "Customer Name: ";
    string name;
    cin.ignore(); // Clear input buffer 
    cin >> name;

    cout << "Room Number: ";
    int roomNumber;
    cin >> roomNumber;

    cout << "Number of Days: ";
    int numDays;
    cin >> numDays;

    double roomRate = 100.0; // Assuming a fixed rate for all rooms

    double totalBill = roomRate * numDays;

    file << name << " " << roomNumber << " " << numDays << " " << totalBill << endl;

    file.close();
    cout << "Room booked successfully!\n";
}

void searchCustomer() {
    ifstream file("customer_data.txt");

    if (!file) {
        cout << "Error opening file. No records found.\n";
        return;
    }

    cout << "\nEnter Room Number to Search: ";
    int searchRoomNumber;
    cin >> searchRoomNumber;

    string name;
    int roomNumber, numDays;
    double totalBill;
    bool found = false;

    while (file >> name >> roomNumber >> numDays >> totalBill) {
        if (roomNumber == searchRoomNumber) {
            found = true;
            cout << "\nCustomer Details:\n";
            cout << "Name: " << name << "\n";
            cout << "Room Number: " << roomNumber << "\n";
            cout << "Number of Days: " << numDays << "\n";
            cout << "Total Bill: $" << fixed << setprecision(2) << totalBill << "\n";
            break;
        }
    }

    if (!found) {
        cout << "No records found for Room Number " << searchRoomNumber << ".\n";
    }

    file.close();
}

void displayAllottedRooms() {
    ifstream file("customer_data.txt");

    if (!file) {
        cout << "Error opening file. No records found.\n";
        return;
    }

    cout << "\nAllotted Rooms:\n";

    string name;
    int roomNumber, numDays;
    double totalBill;

    while (file >> name >> roomNumber >> numDays >> totalBill) {
        cout << "Room Number: " << roomNumber << "\n";
    }

    file.close();
}

void modifyRecord() {
    ifstream inFile("customer_data.txt");
    ofstream outFile("temp.txt");

    if (!inFile) {
        cout << "Error opening file. No records found.\n";
        return;
    }

    cout << "\nEnter Room Number to Modify: ";
    int modifyRoomNumber;
    cin >> modifyRoomNumber;

    string name;
    int roomNumber, numDays;
    double totalBill;
    bool found = false;

    while (inFile >> name >> roomNumber >> numDays >> totalBill) {
        if (roomNumber == modifyRoomNumber) {
            found = true;

            cout << "\nEnter new details:\n";
            cout << "New Customer Name: ";
            cin.ignore(); // Clear input buffer
            cin >> name;

            cout << "New Room Number: ";
            cin >> roomNumber;

            cout << "New Number of Days: ";
            cin >> numDays;
            double roomRate = 100.0;
            totalBill = roomRate * numDays;

            cout << "\nRecord modified successfully!\n";
        }

        outFile << name << " " << roomNumber << " " << numDays << " " << totalBill << endl;
    }

    if (!found) {
        cout << "No records found for Room Number " << modifyRoomNumber << ".\n";
    }

    inFile.close();
    outFile.close();

    // Remove the original file and rename the temporary file
    remove("customer_data.txt");
    rename("temp.txt", "customer_data.txt");
}

void deleteRecord() {
    ifstream inFile("customer_data.txt");
    ofstream outFile("temp.txt");

    if (!inFile) {
        cout << "Error opening file. No records found.\n";
        return;
    }

    cout << "\nEnter Room Number to Delete: ";
    int deleteRoomNumber;
    cin >> deleteRoomNumber;

    string name;
    int roomNumber, numDays;
    double totalBill;
    bool found = false;

    while (inFile >> name >> roomNumber >> numDays >> totalBill) {
        if (roomNumber == deleteRoomNumber) {
            found = true;
            cout << "\nRecord deleted successfully!\n";
        }
        else {
            outFile << name << " " << roomNumber << " " << numDays << " " << totalBill << endl;
        }
    }

    if (!found) {
        cout << "No records found for Room Number " << deleteRoomNumber << ".\n";
    }

    inFile.close();
    outFile.close();

    // Remove the original file and rename the temporary file
    remove("customer_data.txt");
    rename("temp.txt", "customer_data.txt");
}

void displayBill() {
    ifstream inFile("customer_data.txt");

    if (!inFile) {
        cout << "Error opening file. No records found.\n";
        return;
    }

    cout << "\nEnter Room Number to Display Bill: ";
    int displayRoomNumber;
    cin >> displayRoomNumber;

    string name;
    int roomNumber, numDays;
    double totalBill;
    bool found = false;

    while (inFile >> name >> roomNumber >> numDays >> totalBill) {
        if (roomNumber == displayRoomNumber) {
            found = true;
            cout << "\nCustomer Bill Details:\n";
            cout << "Name: " << name << "\n";
            cout << "Room Number: " << roomNumber << "\n";
            cout << "Number of Days: " << numDays << "\n";
            cout << "Total Bill: $" << fixed << setprecision(2) << totalBill << "\n";
            break;
        }
    }

    if (!found) {
        cout << "No records found for Room Number " << displayRoomNumber << ".\n";
    }

    inFile.close();
}
