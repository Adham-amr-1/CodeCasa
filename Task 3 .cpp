#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct userdata {
	string pass;
	string username;
};
void regist() {
	userdata dt;
	cout << "Enter UserName : ";
	cin >> dt.username;
	ifstream user("Username.txt");
	bool found = false;
	string temp;
	// check if exist
	while (user >> temp) {
		if (temp == dt.username) {
			found = true;
			break;
		}
	}
	user.close();
	// if exist
	if (found) {
		cout << "The User Is exists, Try another UserName \n";
	}
	// if not
	else {
		ofstream user("Username.txt", ios::app);
		user << dt.username << endl;
		user.close();
		cout << "Enter Password : ";
		cin >> dt.pass;
		ofstream password("password.txt", ios::app);
		password << dt.pass << endl;
		password.close();
		cout << "Registration Successfully\n";
		cout << "Welcome, " << dt.username << endl;
	}
}
void login() {
	userdata dt;
	cout << "Enter The Username : ";
	cin >> dt.username;

	ifstream user("Username.txt");
	string temp;
	bool found = false;
	if (user.is_open()) {
		// check if exist or not
		while (user >> temp) {
			if (temp == dt.username) {
				found = true;
				break;
			}
		}
		// if exist
		if (found) {
			cout << "Enter Password : ";
			cin >> dt.pass;
			ifstream password("password.txt");
			string pass;
			bool found = false;
			// check password
			while (password >> pass) {
				if (pass == dt.pass) {
					found = true;
					break;
				}
			}
			// if true
			if (found) {
				cout << "Logged in successfully \nWelcome back, " << dt.username << endl;
			}
			// if not
			else {
				cout << "Wrong Password, Try Again\n";
			}
		}
		else {
			cout << "Doesn't exist, go to registration\n";
		}
	}
	// if not exist
	else {
		cout << "Doesn't exist, go to registration\n";
	}
}
void printscreen() {
	cout << "1. Login \n";
	cout << "2. Register \n";
	cout << "3. Exit \n";
}
int main()
{
	int choice;
	while (1) {
		printscreen();
		cout << "Enter Your Choice : ";
		cin >> choice;
		if (choice == 1) {
			login();
		}
		else if (choice == 2) {
			regist();
		}
		else if (choice == 3) {
			break;
		}
		else {
			cout << "Wrong Choice\n";
		}
	}
}
