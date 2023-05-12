#include "Header.h"

void Admin_menu() {
	int choice=0;
	cout << "���������� ��������������: " << endl;
	do {
		cout << "[1] �������� ������������" << endl;
		cout << "[2] ������ ����� �����" << endl;
		cout << "[3] ������� ������� ������������" << endl;
		cout << "[4] ������� ���������� �������������" << endl;
		cout << "[5] ������� ���������� ���������������" << endl;
		cout << "[6] ������/������� ������ � ���������" << endl;
		cout << "[7] �����" << endl;
		cout << "����: ";
		string input;
		while (true) {
			getline(cin, input);
			if (input.find_first_not_of("0123456789") == string::npos) {
				choice = stoi(input);
				break;
			}
			else {
				cout << "������� ����� �����(1-7): ";
			}
		}
		switch (choice)
		{
		case 1:
			BanUser();
			break;
		case 2:
			GrantAdmin();
			break;
		case 3:
			DeleteAccount();
			break;
		case 4:
			UserStats();
			break;
		case 5:
			AdmStats();
			break;
		case 6:
			production();
			break;
		case 7:
			cout << "Programm closing" << endl;
			break;
		default:
			cout << "Valiable choice" << endl;
			break;
		}
	} while (choice != 7);
}

void BanUser() {
	fstream file("ban.txt", ios::in | ios::app | ios::out);
	ifstream RegFile("reg.txt");
	if (!file.is_open() && !RegFile.is_open()) {
		cout << "������. ���� �� �����������." << endl;
		return;
	}
	string users, line, banUs, pass, role, user;
	bool User;
	do {
		cout << "������� ������������ (�� �� ������ �������� ������): ";
		while (true) {
			getline(cin, user);
			bool validInput = true;
			for (char c : user) {
				if (!isalnum(c) || !isascii(c)) {
					validInput = false;
					break;
				}
			}
			if (user.find(" ") == string::npos && validInput) {
				break;
			}
			else {
				cout << "����������� ����, ��������� �������: ";
			}
		}
		file.clear();
		file.seekg(0, ios::beg);
		User = true;
		while (file >> banUs) {
			if (user == banUs) {
				cout << "������������ ����� ���" << endl;
				User = false;
				break;
			}
		}
	} while (!User);
	file.clear();
	file.seekg(0, ios::beg);
	bool foundUser = false;
	while (RegFile >> users >> pass >> role) {
		if (users == user) {
			foundUser = true;
			if (role != "Admin") {
				file << user << "\n";
				cout << "������ ������������ ������� ���" << endl;
				break;
			}
			else {
				cout << "�� �� ������ �������� ��������������" << endl;
				break;
			}
		}
	}
	if (!foundUser) {
		cout << "������������ �� ������" << endl;
	}
	file.close();
	RegFile.close();
}

void DeleteAccount() {
	fstream banFile("ban.txt", ios::in | ios::out | ios::app);
	fstream outBan("outban.txt", ios::in | ios::out | ios::app);
	fstream inputfile("reg.txt", ios::in | ios::out | ios::app);
	fstream outputfile("Out.txt", ios::in | ios::out | ios::app);
	if (!inputfile.is_open() || !banFile.is_open())
	{
		cout << "������. ���� �� �����������" << endl;
		return;
	}
	string line, user, userFile, banUser, banline, role;
	cout << "������� ������������: ";
	while (true) {
		getline(cin, user);
		bool validInput = true;
		for (char c : user) {
			if (!isalnum(c) || !isascii(c)) {
				validInput = false;
				break;
			}
		}
		if (user.find(" ") == string::npos && validInput) {
			break;
		}
		else {
			cout << "����������� ����, ��������� �������: ";
		}
	}
	bool Delete = false;
	while (getline(inputfile, line)) {
		role = line.substr(line.find_last_of(" ")+1);
		userFile = line.substr(0, line.find(' '));
		if (userFile == user && !Delete && role != "Admin")
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
		cout << "������� ������������ ��� ������� ������" << endl;
	}
	else
	cout << "������������ �� ������" << endl;
	inputfile.close();
	outputfile.close();
	remove("reg.txt");
	rename("Out.txt", "reg.txt");
	banFile.close();
	outBan.close();
	remove("ban.txt");
	rename("outban.txt", "ban.txt");
}

void GrantAdmin() {
	ifstream banFile("ban.txt");
	fstream inputf("reg.txt", ios::in | ios::app | ios::out);
	fstream outf("out.txt", ios::in | ios::app | ios::out);
	if (!inputf.is_open() && !outf.is_open() && !banFile.is_open()) {
		cout << "������. ���� �� �����������" << endl;
		return;
	}
	string line, role, user, users, newline, banUser; int last_pos = 0;
	cout << "������� ������������: ";
	while (true) {
		getline(cin, user);
		bool validInput = true;
		for (char c : user) {
			if (!isalnum(c) || !isascii(c)) {
				validInput = false;
				break;
			}
		}
		if (user.find(" ") == string::npos && validInput) {
			break;
		}
		else {
			cout << "����������� ����, ��������� �������: ";
		}
	}
	while (banFile >> banUser) {
		if (user == banUser)
		{
			cout << "������������ ����� ���!" << endl;
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
		cout << "������������ �� ������" << endl;
	else
		cout << "������������ ������� ����� �����" << endl;
	inputf.close();
	outf.close();
	remove("reg.txt");
	rename("out.txt", "reg.txt");
}

void UserStats() {
	system("cls");
	fstream file("reg.txt", ios::in | ios::out | ios::app);
	fstream banfile("ban.txt", ios::in | ios::out | ios::app);
	if (!file.is_open() || !banfile.is_open()) {
		cout << "������. ���� �� �����������!" << endl;
		return;
	}
	string banus, user, role, pass;  bool userban;
	cout << "������������ ������������������ � ���������:" << endl;
	while (file >> user >> pass >> role) {
		userban = false;
		if (role == "User") {
			banfile.clear();
			banfile.seekg(0, ios::beg);
			while (banfile >> banus) {
				if (banus == user) {
					cout << user << ": ����� ���" << endl;
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

void AdmStats() {
	system("cls");
	fstream file("reg.txt", ios::in | ios::out | ios::app);
	if (!file.is_open()) {
		cout << "������ ���� �� �����������!" << endl;
		return;
	}
	string  user, role, pass;
	cout << "�������������� ������������������ � ���������:" << endl;
	while (file >> user >> pass >> role) {
		if (role == "Admin") {
			cout << user << endl;
		}
	}
	file.close();
}