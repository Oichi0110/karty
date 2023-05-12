#include "Header.h"

int production() {
	int choice;
	do {
		cout << "[1] ���� ������ � ������������ ���������" << endl;
		cout << "[2] ����� ������ �� ������������ ������ �������" << endl;
		cout << "[3] ����� ��������������� ������ �� �������������" << endl;
		cout << "[4] �������� ���������� ������������� ���������" << endl;
		cout << "[5] �����" << endl;
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
			DataProduction();
			break;
		case 2:
			OutProdData();
			break;
		case 3:
			SorNameProd();
			break;
		case 4:
			NumberProd();
			break;
		default:
			cout << "������� ���������� ��������" << endl;
			break;
		}
	} while (choice != 5);
	return 0;
}


bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(int day, int month, int year) {
	if (year < 1970 || year > 2050)
		return false;

	if (month < 1 || month > 12)
		return false;

	int daysInMonth = 31;

	if (month == 4 || month == 6 || month == 9 || month == 11)
		daysInMonth = 30;
	else if (month == 2) {
		if (isLeapYear(year))
			daysInMonth = 29;
		else
			daysInMonth = 28;
	}

	return (day >= 1 && day <= daysInMonth);
}

void inputDate(int& day, int& month, int& year) {
	string input;
	while (true) {
		cout << "������� ���� (1-31): ";
		while (true) {
			getline(cin, input);
			if (input.find_first_not_of("0123456789") == string::npos) {
				day = stoi(input);
				break;
			}
			else {
				cout << "������� ����� �����(1-31): ";
			}
		}
		cout << "������� ����� (1-12): ";
		while (true) {
			getline(cin, input);
			if (input.find_first_not_of("0123456789") == string::npos) {
				month = stoi(input);
				break;
			}
			else {
				cout << "������� ����� �����(1-12): ";
			}
		}
		cout << "������� ��� (1970-2050): ";
		while (true) {
			getline(cin, input);
			if (input.find_first_not_of("0123456789") == string::npos) {
				year = stoi(input);
				break;
			}
			else {
				cout << "������� ����� �����(1970-2050): ";
			}
		}
		if (isValidDate(day, month, year))
			break;
		cout << "������������ ����, ��������� ����.\n";
	}
}

bool isValidFullName(const string& fullName) {
	size_t firstSpacePos = fullName.find(' ');
	size_t lastSpacePos = fullName.find_last_of(' ');
	if (firstSpacePos != string::npos && firstSpacePos != 0 && lastSpacePos != fullName.length() - 1) {
		if (firstSpacePos != lastSpacePos) {
			return true;
		}
	}
	return false;
}

void DataProduction() {
	fstream file("Production.txt", ios::in | ios::out | ios::app);
	if (!file.is_open()) {
		cout << "������. ���� �� �����������!" << endl;
		return;
	}
	Prodd Prod;
	string quantity, workshop;
	inputDate(Prod.day, Prod.month, Prod.year);
	Prod.data = to_string(Prod.day) + "." + to_string(Prod.month) + "." + to_string(Prod.year);
	cout << "������� ������������ ���������: ";
	while (true) {
		getline(cin, Prod.NameProd);
		bool validInput = true;
		for (char c : Prod.NameProd) {
			if (!isalpha(c) || !isascii(c)) {
				validInput = false;
				break;
			}
		}
		if (validInput) {
			break;
		}
		else {
			std::cout << "������������ ����, ��������� �������: ";
		}
	}
	cout << "������� ���������� ������������� ���������: "; 
	while (true) {
		cin >> Prod.QuantityProd;
		quantity = to_string(Prod.QuantityProd);
		if (quantity.find_first_not_of("0123456789") == string::npos) {
			Prod.QuantityProd = stoi(quantity);
			break;
		}
		else {
			cout << "������� ��������� �����: ";
		}
	}
	cout << "������� ��� ����������� �����: "; cin.ignore(); 
	while (true) {
		getline(cin, Prod.FullName);
		if (isValidFullName(Prod.FullName))
			break;
		else
			cout << "������� ��������� ������: ";
	}
	cout << "������� ����� ����������: "; 
	while (true) {
		getline(cin, workshop);
		if (workshop.find_first_not_of("0123456789") == string::npos) {
			Prod.NumberWorkshop = stoi(workshop);
			break;
		}
		else {
			cout << "������� ���������� �����: ";
		}
	}
	file << Prod.data << "," << Prod.NameProd << "," << Prod.QuantityProd << "," << Prod.FullName << "," << Prod.NumberWorkshop << "\n";
	file.close();
}


void OutProdData() {
	fstream file("Production.txt", ios::in | ios::out | ios::app);
	if (!file.is_open()) {
		cout << "������. ���� �� �����������!" << endl;
		return;
	}
	string time, line;
	int n = 0;
	int day, month, year;
	vector<Date> times;
	vector<Date1> dr;
	Date date;
	Date1 date1;
	SortProd Sort;
	cout << "������� ������ ���������: ";
	inputDate(Sort.BegDay, Sort.BegMonth, Sort.BegYear);
	cout << "������� ����� ���������: ";
	inputDate(Sort.EndDay, Sort.EndMonth, Sort.EndYear);
	while (getline(file, line)) {
		day = stoi(line.substr(0, 2));
		month = stoi(line.substr(3, 2));
		year = stoi(line.substr(6, 4));
		if ((Sort.BegYear < year && Sort.EndYear > year) || (Sort.BegYear == year && Sort.EndYear == year && Sort.BegMonth < month && Sort.EndMonth > month) || (Sort.BegYear == year && Sort.EndYear == year && Sort.BegMonth == month && Sort.EndMonth == month && Sort.BegDay < day && Sort.EndDay > day)) {
			time = line.substr(11);
			date = { time, day, month, year };
			date1 = { day, month, year };
			times.push_back(date);
			dr.push_back(date1);
		}
	}
	system("cls");
	int size = dr.size();
	file.close();
	Sorted(times, size);
}

void Sorted(vector<Date>& times, int size) {
	sort(times.begin(), times.end(), compare);
	for (const auto& date : times) {
		cout << date.day << "." << date.month << "." << date.year << ": " << date.line << endl;
	}
}

bool compare(const Date& d1, const Date& d2)
{
	if (d1.year < d2.year)
		return true;
	if (d1.year == d2.year && d1.month < d2.month)
		return true;
	if (d1.year == d2.year && d1.month == d2.month &&
		d1.day < d2.day)
		return true;
	return false;
}

bool Sname(const SortName& d1, const SortName& d2)
{
	string name1 = d1.name;
	string name2 = d2.name;
	transform(name1.begin(), name1.end(), name1.begin(), [](unsigned char c) { return tolower(c); });
	transform(name2.begin(), name2.end(), name2.begin(), [](unsigned char c) { return tolower(c); });
	return name1 < name2;
}

void SorNameProd() {
	fstream file("Production.txt", ios::in | ios::out | ios::app);
	if (!file.is_open()) {
		cout << "������. ���� �� �����������!" << endl;
		return;
	}
	string name, line, str;
	int day, month, year;
	vector<SortName> sortName;
	SortName sor;
	SortProd Sort;
	cout << "������� ������ ���������: ";
	inputDate(Sort.BegDay, Sort.BegMonth, Sort.BegYear);
	cout << "������� ����� ���������: ";
	inputDate(Sort.EndDay, Sort.EndMonth, Sort.EndYear);
	while (getline(file, line)) {
		day = stoi(line.substr(0, 2));
		month = stoi(line.substr(3, 2));
		year = stoi(line.substr(6, 4));
		if ((Sort.BegYear < year && Sort.EndYear > year) || (Sort.BegYear == year && Sort.EndYear == year && Sort.BegMonth < month && Sort.EndMonth > month) || (Sort.BegYear == year && Sort.EndYear == year && Sort.BegMonth == month && Sort.EndMonth == month && Sort.BegDay < day && Sort.EndDay > day)) {
			size_t pos1 = line.find(",");
			size_t pos2 = line.find(",", pos1 + 1);
			name = line.substr(pos1 + 1, pos2 - pos1 - 1);
			str = line.substr(0, pos1) + "," + line.substr(pos2 + 1);
			sor = { name, str };
			sortName.push_back(sor);
		}
	}
	system("cls");
	sort(sortName.begin(), sortName.end(), Sname);
	for (const auto& sor : sortName) {
		cout << sor.name << " " << sor.line << endl;
	}
	file.close();
}

void NumberProd() {
	fstream file("Production.txt", ios::in | ios::out | ios::app);
	if (!file.is_open()) {
		cout << "������. ���� �� �����������!" << endl;
		return;
	}
	int choice = 0;
	cout << "[1] ����� ���������� ���������, ������������� �� ��� �����" << endl;
	cout << "[2] ����� ���������� ���������, ������������� �� ������������ ������ �������" << endl;
	cout << "[3] �������� ���������� ��������� ������������� ��������" << endl;
	cout << "����: ";
	string input;
	while (true) {
		getline(cin, input);
		if (input.find_first_not_of("0123456789") == string::npos) {
			choice = stoi(input);
			break;
		}
		else {
			cout << "������� ����� �����(1-3): ";
		}
	}
	switch (choice)
	{
	case 1:
		NumberAllTime();
		break;
	case 2:
		NumberCertainPeriod();
		break;
	case 3:
		NumberCertainProd();
		break;
	default:
		cout << "������� ���������� �����" << endl;
		NumberProd();
		break;
	}
	file.close();
}

bool NumQuan(const Number& d1, const Number& d2)
{
	if (d1.year < d2.year)
		return true;
	if (d1.year == d2.year && d1.month < d2.month)
		return true;
	if (d1.year == d2.year && d1.month == d2.month &&
		d1.day < d2.day)
		return true;
	return false;
}

void NumberAllTime() {
	fstream file("Production.txt", ios::in | ios::out | ios::app);
	if (!file.is_open()) {
		cout << "������. ���� �� �����������!" << endl;
		return;
	}
	Number date;
	vector<Number> times;
	string line, otherline;
	int day, month, year, quantity, sumQuantity = 0;
	while (getline(file, line))
	{
		size_t pos1 = line.find(",");
		size_t pos2 = line.find(",", pos1 + 1);
		size_t pos3 = line.find(",", pos2 + 1);
		otherline = line.substr(pos1 + 1, pos2 - pos1 - 1) + "," + line.substr(pos3 + 1);
		day = stoi(line.substr(0, 2));
		month = stoi(line.substr(3, 2));
		year = stoi(line.substr(6, 4));
		quantity = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
		sumQuantity += quantity;
		date = { otherline, day, month, year, quantity };
		times.push_back(date);
	}
	sort(times.begin(), times.end(), NumQuan);
	cout << endl;
	cout << "���������� ������������� ���������: " << sumQuantity << "\n����������" <<endl;
	for (const auto& date : times) {
		cout << date.day << "." << date.month << "." << date.year << ": " << date.quantity << endl;
	}
	file.close();
}

void NumberCertainPeriod() {
	fstream file("Production.txt", ios::in | ios::out | ios::app);
	if (!file.is_open()) {
		cout << "������. ���� �� �����������" << endl;
		return;
	}
	Number date;
	vector<Number> times;
	string line, otherline;
	SortProd Sort;
	int day, month, year, quantity, sumQuantity = 0;
	cout << "������� ������ ���������: ";
	inputDate(Sort.BegDay, Sort.BegMonth, Sort.BegYear);
	cout << "������� ����� ���������: ";
	inputDate(Sort.EndDay, Sort.EndMonth, Sort.EndYear);
	while (getline(file, line))
	{
		day = stoi(line.substr(0, 2));
		month = stoi(line.substr(3, 2));
		year = stoi(line.substr(6, 4));
		if ((Sort.BegYear < year && Sort.EndYear > year) || (Sort.BegYear == year && Sort.EndYear == year && Sort.BegMonth < month && Sort.EndMonth > month) || (Sort.BegYear == year && Sort.EndYear == year && Sort.BegMonth == month && Sort.EndMonth == month && Sort.BegDay < day && Sort.EndDay > day)) {
			size_t pos1 = line.find(",");
			size_t pos2 = line.find(",", pos1 + 1);
			size_t pos3 = line.find(",", pos2 + 1);
			otherline = line.substr(pos1 + 1, pos2 - pos1 - 1) + "," + line.substr(pos3 + 1);
			quantity = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
			sumQuantity += quantity;
			date = { otherline, day, month, year, quantity };
			times.push_back(date);
		}
	}
	sort(times.begin(), times.end(), NumQuan);
	cout << endl;
	cout << "��������� ���������� ������������� ���������: " << sumQuantity << "\n����������: " << endl;
	for (const auto& date : times) {
		cout << date.day << "." << date.month << "." << date.year << ": " << date.quantity << endl;
	}
	file.close();
}

void NumberCertainProd() {
	fstream file("Production.txt", ios::in | ios::out | ios::app);
	if (!file.is_open()) {
		cout << "������. ���� �� �����������!" << endl;
		return;
	}
	Number date;
	vector<Number> times;
	string line, otherline, name, nameProd;
	int day, month, year, quantity, sumQuantity = 0;
	cout << "������� ������������ ���������: ";
	getline(cin, name);
	while (getline(file, line))
	{
		size_t pos1 = line.find(",");
		size_t pos2 = line.find(",", pos1 + 1);
		nameProd = line.substr(pos1 + 1, pos2 - pos1 - 1);
		if (nameProd == name) {
			day = stoi(line.substr(0, 2));
			month = stoi(line.substr(3, 2));
			year = stoi(line.substr(6, 4));
			size_t pos3 = line.find(",", pos2 + 1);
			otherline = line.substr(pos1 + 1, pos2 - pos1 - 1) + "," + line.substr(pos3 + 1);
			quantity = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
			sumQuantity += quantity;
			date = { otherline, day, month, year, quantity };
			times.push_back(date);
		}
	}
	sort(times.begin(), times.end(), NumQuan);
	cout << endl;
	cout << "��������� ���������� ������������� ���������: " << sumQuantity << "\n����������: " << endl;
	for (const auto& date : times) {
		cout << date.day << "." << date.month << "." << date.year << ": " << date.quantity << endl;
	}
	file.close();
}