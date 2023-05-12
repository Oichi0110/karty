#pragma once
#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

extern void DeleteAccount() {
	fstream banFile("ban.txt", ios::in | ios::out | ios::app);
	fstream outBan("outban.txt", ios::in | ios::out | ios::app);
	fstream inputfile("reg.txt", ios::in | ios::out | ios::app);
	fstream outputfile("Out.txt", ios::in | ios::out | ios::app);
	if (!inputfile.is_open() || !banFile.is_open())
	{
		cout << "Error. File not open" << endl;
		return;
	}
	string line, user, userFile, banUser, banline;
	cout << "Enter User: ";
	cin.ignore();
	getline(cin, user);
	bool Delete = false;
	while (getline(inputfile, line) && !inputfile.eof()) {
		userFile = line.substr(0, line.find(' '));
		if (userFile == user && !Delete)
		{
			Delete = true;
			continue;
		}
		outputfile << line << "\n";
	}
	if (Delete)
	{
		bool ban = false;
		while (getline(banFile, banUser)) {
			if (user == banUser && !ban)
			{
				ban = true;
				continue;
			}
			outBan << banUser << "\n";
		}
		cout << "User delete" << endl;
	}
	else
		cout << "User not found" << endl;
	inputfile.close();
	outputfile.close();
	remove("reg.txt");
	rename("Out.txt", "reg.txt");
	banFile.close();
	outBan.close();
	remove("ban.txt");
	rename("outban.txt", "ban.txt");
}