#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

extern void GrantAdmin() {
	ifstream banFile("ban.txt");
	fstream inputf("reg.txt", ios::in | ios::app | ios::out);
	fstream outf("out.txt", ios::in | ios::app | ios::out);
	if (!inputf.is_open() && !outf.is_open() && !banFile.is_open()) {
		cout << "Error. File not open" << endl;
		return;
	}
	string line, role, user, users, newline, banUser; int last_pos = 0;
	cout << "Enter user: ";
	cin.ignore();
	getline(cin, user);
	while (banFile >> banUser) {
		if (user == banUser)
		{
			cout << "User habe ban!" << endl;
			return;
		}
	}
	bool NewAdm = false;
	while (getline(inputf, line)) {
		users = line.substr(0, line.find(" "));
		if (user == users && !NewAdm) {
			newline = line.substr(0, line.find_last_of(" ")) + " Admin";
			outf << newline << "\n";
			NewAdm = true;
			continue;
		}
		outf << line << "\n";
	}
	if (!NewAdm)
		cout << "User not found" << endl;
	else
		cout << "User grant admin" << endl;
	inputf.close();
	outf.close();
	remove("reg.txt");
	rename("out.txt", "reg.txt");
}