#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

extern void BanUser() {
	fstream file("ban.txt", ios::in | ios::app | ios::out);
	ifstream RegFile("reg.txt");
	if (!file.is_open() && !RegFile.is_open()) {
		cout << "Error. File not open." << endl;
		return;
	}
	string users, line, banUs, pass, role, user;
	cin.ignore();
	bool User;
	do {
		cout << "Enter Username (we don't can ban Adim): ";
		getline(cin, user);
		file.seekg(0, ios::beg);
		User = true;
		while (file >> banUs) {
			if (user == banUs) {
				cout << "User have banned" << endl;
				User = false;
				break;
			}
		}
	} while (!User);
	file.seekg(0, ios::beg);
	bool foundUser = false;
	while (RegFile >> users >> pass >> role) {
		if (users == user) {
			foundUser = true;
			if (role != "Admin") {
				file << user << "\n";
				cout << "User banned" << endl;
				break;
			}
			else {
				cout << "We cannot ban Admin" << endl;
				break;
			}
		}
	}
	if (!foundUser) {
		cout << "User name not found" << endl;
	}
	file.close();
	RegFile.close();
}