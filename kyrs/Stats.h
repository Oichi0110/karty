#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

extern void UserStats() {
	system("cls");
	fstream file("reg.txt", ios::in | ios::out | ios::app);
	fstream banfile("ban.txt", ios::in | ios::out | ios::app);
	if (!file.is_open() || !banfile.is_open()) {
		cout << "Error. File not open!" << endl;
		return;
	}
	string banus, user, role, pass;  bool userban;
	cout << "Users registered in the program:" << endl;
	while (file >> user >> pass >> role) {
		userban = false;
		if (role == "User") {
			banfile.clear();
			banfile.seekg(0, ios::beg);
			while (banfile >> banus) {
				if (banus == user) {
					cout << user << ": have ban" << endl;
					userban = true;
					break;
				}
			}
			if (!userban)
				cout << user << endl;
		}
	}
	file.close();
	banfile.close();
}

extern void AdmStats() {
	system("cls");
	fstream file("reg.txt", ios::in | ios::out | ios::app);
	if (!file.is_open()) {
		cout << "Error. File not open!" << endl;
		return;
	}
	string  user, role, pass;
	cout << "Admin registered in the program:" << endl;
	while (file >> user >> pass >> role) {
		if (role == "Admin") {
			cout << user << endl;
		}
	}
	file.close();
}