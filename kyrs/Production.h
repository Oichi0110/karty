//#pragma once
//#include <cctype>
//#include <algorithm>
//#include <vector>
//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;
//
//struct Prodd {
//	string NameProd;
//	int NumberWorkshop;
//	string data;
//	int day, month, year;
//	string FullName;
//	int QuantityProd;
//} Prod;
//
//struct SortProd {
//	int BegDay, BegMonth, BegYear, EndDay, EndMonth, EndYear;
//} Sort;
//
//struct Date {
//	string line;
//	int day, month, year;
//};
//
//struct Date1 {
//	int day, month, year;
//};
//
//struct SortName {
//	string name, line;
//};
//
//struct Number {
//	string line;
//	int day, month, year, quantity;
//};
//
//bool Sname(const SortName& d1, const SortName& d2);
//bool compare(const Date& d1, const Date& d2);
//void Sorted(vector<Date>& times, int size);
//void DataProduction();
//void OutProdData();
//void SorNameProd();
//void NumberProd();
//void NumberAllTime();
//void NumberCertainPeriod();
//void NumberCertainProd();
//
//int production() {
//	int choice;
//	do {
//		cout << "[1] Enter data about manufactured products" << endl;
//		cout << "[2] Output data for a certain period of time" << endl;
//		cout << "[3] Output sorted data by name" << endl;
//		cout << "[4] View the number of products produced" << endl;
//		cout << "[5] Exit" << endl;
//		cout << "Enter: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			DataProduction();
//			break;
//		case 2:
//			OutProdData();
//			break;
//		case 3:
//			SorNameProd();
//			break;
//		case 4:
//			NumberProd();
//			break;
//		default:
//			cout << "Enter the correct value" << endl;
//			break;
//		}
//	} while (choice != 5);
//	return 0;
//}
//
//
//void DataProduction() {
//	fstream file("Production.txt", ios::in | ios::out | ios::app);
//	if (!file.is_open()) {
//		cout << "Error. File not open!" << endl;
//		return;
//	}
//	cout << "Enter day(1-31): "; cin >> Prod.day;
//	cout << "Enter month(1-12): "; cin >> Prod.month;
//	cout << "Enter year(2000-2032): "; cin >> Prod.year;
//	Prod.data = to_string(Prod.day) + "." + to_string(Prod.month) + "." + to_string(Prod.year);
//	cout << "Enter product names: ";
//	cin.ignore();
//	getline(cin, Prod.NameProd);
//	cout << "Enter the quantity of products produced: "; cin >> Prod.QuantityProd;
//	cout << "Enter the full name of the shop manager: ";
//	cin.ignore();
//	getline(cin, Prod.FullName);
//	cout << "Enter the workshop number: "; cin >> Prod.NumberWorkshop;
//	file << Prod.data << "," << Prod.NameProd << "," << to_string(Prod.QuantityProd) << "," << Prod.FullName << "," << to_string(Prod.NumberWorkshop) << "\n";
//	file.close();
//}
//
//
//void OutProdData() {
//	fstream file("Production.txt", ios::in | ios::out | ios::app);
//	if (!file.is_open()) {
//		cout << "Error. File not open!" << endl;
//		return;
//	}
//	string time, line;
//	int n = 0;
//	int day, month, year;
//	vector<Date> times;
//	vector<Date1> dr;
//	Date date;
//	Date1 date1;
//	cout << "Enter the beginning of the interval: ";
//	cout << "Day(1-31): "; cin >> Sort.BegDay;
//	cout << "Month(1-12): "; cin >> Sort.BegMonth;
//	cout << "Year(2000-2040): "; cin >> Sort.BegYear;
//	cout << "Enter the end of the gap: ";
//	cout << "Day(1-31): "; cin >> Sort.EndDay;
//	cout << "Month(1-12): "; cin >> Sort.EndMonth;
//	cout << "Year(2000-2040): "; cin >> Sort.EndYear;
//	while (getline(file, line)) {
//		day = stoi(line.substr(0, 2));
//		month = stoi(line.substr(3, 2));
//		year = stoi(line.substr(6, 4));
//		if ((Sort.BegYear < year && Sort.EndYear > year) || (Sort.BegYear == year && Sort.EndYear == year && Sort.BegMonth < month && Sort.EndMonth > month) || (Sort.BegYear == year && Sort.EndYear == year && Sort.BegMonth == month && Sort.EndMonth == month && Sort.BegDay < day && Sort.EndDay > day)) {
//			time = line.substr(11);
//			date = { time, day, month, year };
//			date1 = { day, month, year };
//			times.push_back(date);
//			dr.push_back(date1);
//		}
//	}
//	system("cls");
//	int size = dr.size();
//	file.close();
//	Sorted(times, size);
//}
//
//void Sorted(vector<Date>& times, int size) {
//	sort(times.begin(), times.end(), compare);
//	for (const auto& date : times) {
//		cout << date.day << "." << date.month << "." << date.year << " " << date.line << endl;
//	}
//}
//
//bool compare(const Date& d1, const Date& d2)
//{
//	if (d1.year < d2.year)
//		return true;
//	if (d1.year == d2.year && d1.month < d2.month)
//		return true;
//	if (d1.year == d2.year && d1.month == d2.month &&
//		d1.day < d2.day)
//		return true;
//	return false;
//}
//
//bool Sname(const SortName& d1, const SortName& d2)
//{
//	string name1 = d1.name;
//	string name2 = d2.name;
//	transform(name1.begin(), name1.end(), name1.begin(), [](unsigned char c) { return tolower(c); });
//	transform(name2.begin(), name2.end(), name2.begin(), [](unsigned char c) { return tolower(c); });
//	return name1 < name2;
//}
//
//void SorNameProd() {
//	fstream file("Production.txt", ios::in | ios::out | ios::app);
//	if (!file.is_open()) {
//		cout << "Error. File not open!" << endl;
//		return;
//	}
//	string name, line, str;
//	int day, month, year;
//	vector<SortName> sortName;
//	SortName sor;
//	cout << "Enter the beginning of the interval: ";
//	cout << "Day(1-31): "; cin >> Sort.BegDay;
//	cout << "Month(1-12): "; cin >> Sort.BegMonth;
//	cout << "Year(2000-2040): "; cin >> Sort.BegYear;
//	cout << "Enter the end of the gap: ";
//	cout << "Day(1-31): "; cin >> Sort.EndDay;
//	cout << "Month(1-12): "; cin >> Sort.EndMonth;
//	cout << "Year(2000-2040): "; cin >> Sort.EndYear;
//	while (getline(file, line)) {
//		day = stoi(line.substr(0, 2));
//		month = stoi(line.substr(3, 2));
//		year = stoi(line.substr(6, 4));
//		if ((Sort.BegYear < year && Sort.EndYear > year) || (Sort.BegYear == year && Sort.EndYear == year && Sort.BegMonth < month && Sort.EndMonth > month) || (Sort.BegYear == year && Sort.EndYear == year && Sort.BegMonth == month && Sort.EndMonth == month && Sort.BegDay < day && Sort.EndDay > day)) {
//			size_t pos1 = line.find(",");
//			size_t pos2 = line.find(",", pos1 + 1);
//			name = line.substr(pos1 + 1, pos2 - pos1 - 1);
//			str = line.substr(0, pos1) + "," + line.substr(pos2 + 1);
//			sor = { name, str };
//			sortName.push_back(sor);
//		}
//	}
//	system("cls");
//	sort(sortName.begin(), sortName.end(), Sname);
//	for (const auto& sor : sortName) {
//		cout << sor.name << " " << sor.line << endl;
//	}
//	file.close();
//}
//
//void NumberProd() {
//	fstream file("Production.txt", ios::in | ios::out | ios::app);
//	if (!file.is_open()) {
//		cout << "Error. File not open!" << endl;
//		return;
//	}
//	int choice = 0;
//	cout << "[1] Output the number of products produced for all time" << endl;
//	cout << "[2] Output the number of products produced for a certain period of time" << endl;
//	cout << "[3] Output the number of products of a certain product" << endl;
//	cout << "Enter: ";
//	cin >> choice;
//	switch (choice)
//	{
//	case 1:
//		NumberAllTime();
//		break;
//	case 2:
//		NumberCertainPeriod();
//		break;
//	case 3:
//		NumberCertainProd();
//		break;
//	default:
//		cout << "Enter the correct number" << endl;
//		NumberProd();
//		break;
//	}
//	file.close();
//}
//
//bool NumQuan(const Number& d1, const Number& d2)
//{
//	if (d1.year < d2.year)
//		return true;
//	if (d1.year == d2.year && d1.month < d2.month)
//		return true;
//	if (d1.year == d2.year && d1.month == d2.month &&
//		d1.day < d2.day)
//		return true;
//	return false;
//}
//
//void NumberAllTime() {
//	fstream file("Production.txt", ios::in | ios::out | ios::app);
//	if (!file.is_open()) {
//		cout << "Error. File not open!" << endl;
//		return;
//	}
//	Number date;
//	vector<Number> times;
//	string line, otherline;
//	int day, month, year, quantity, sumQuantity = 0;
//	while (getline(file, line))
//	{
//		size_t pos1 = line.find(",");
//		size_t pos2 = line.find(",", pos1 + 1);
//		size_t pos3 = line.find(",", pos2 + 1);
//		otherline = line.substr(pos1 + 1, pos2 - pos1 - 1) + "," + line.substr(pos3 + 1);
//		day = stoi(line.substr(0, 2));
//		month = stoi(line.substr(3, 2));
//		year = stoi(line.substr(6, 4));
//		quantity = stoi(line.substr(pos2+1, pos3-pos2-1));
//		sumQuantity += quantity;
//		date = {otherline, day, month, year, quantity};
//		times.push_back(date);
//	}
//	sort(times.begin(), times.end(), NumQuan);
//	cout << endl;
//	cout << "Quantity: " << sumQuantity << endl;
//	for (const auto& date : times) {
//		cout << date.day << "." << date.month << "." << date.year << ": " << date.quantity << endl;
//	}
//	file.close();
//}
//
//void NumberCertainPeriod() {
//	fstream file("Production.txt", ios::in | ios::out | ios::app);
//	if (!file.is_open()) {
//		cout << "Error. File not open!" << endl;
//		return;
//	}
//	Number date;
//	vector<Number> times;
//	string line, otherline;
//	int day, month, year, quantity, sumQuantity = 0;
//	cout << "Enter the beginning of the interval: ";
//	cout << "Day(1-31): "; cin >> Sort.BegDay;
//	cout << "Month(1-12): "; cin >> Sort.BegMonth;
//	cout << "Year(2000-2040): "; cin >> Sort.BegYear;
//	cout << "Enter the end of the gap: ";
//	cout << "Day(1-31): "; cin >> Sort.EndDay;
//	cout << "Month(1-12): "; cin >> Sort.EndMonth;
//	cout << "Year(2000-2040): "; cin >> Sort.EndYear;
//	while (getline(file, line))
//	{
//		day = stoi(line.substr(0, 2));
//		month = stoi(line.substr(3, 2));
//		year = stoi(line.substr(6, 4));
//		if ((Sort.BegYear < year && Sort.EndYear > year) || (Sort.BegYear == year && Sort.EndYear == year && Sort.BegMonth < month && Sort.EndMonth > month) || (Sort.BegYear == year && Sort.EndYear == year && Sort.BegMonth == month && Sort.EndMonth == month && Sort.BegDay < day && Sort.EndDay > day)) {
//			size_t pos1 = line.find(",");
//			size_t pos2 = line.find(",", pos1 + 1);
//			size_t pos3 = line.find(",", pos2 + 1);
//			otherline = line.substr(pos1 + 1, pos2 - pos1 - 1) + "," + line.substr(pos3 + 1);
//			quantity = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
//			sumQuantity += quantity;
//			date = { otherline, day, month, year, quantity };
//			times.push_back(date);
//		}
//	}
//	sort(times.begin(), times.end(), NumQuan);
//	cout << endl;
//	cout << "Quantity: " << sumQuantity << endl;
//	for (const auto& date : times) {
//		cout << date.day << "." << date.month << "." << date.year << ": " << date.quantity << endl;
//	}
//	file.close();
//}
//
//void NumberCertainProd() {
//	fstream file("Production.txt", ios::in | ios::out | ios::app);
//	if (!file.is_open()) {
//		cout << "Error. File not open!" << endl;
//		return;
//	}
//	Number date;
//	vector<Number> times;
//	string line, otherline, name, nameProd;
//	int day, month, year, quantity, sumQuantity = 0;
//	cout << "Name of products: ";
//	cin.ignore();
//	getline(cin, name);
//	while (getline(file, line))
//	{
//		size_t pos1 = line.find(",");
//		size_t pos2 = line.find(",", pos1 + 1);
//		nameProd = line.substr(pos1 + 1, pos2 - pos1 - 1);
//		if (nameProd==name) {
//			day = stoi(line.substr(0, 2));
//			month = stoi(line.substr(3, 2));
//			year = stoi(line.substr(6, 4));
//			size_t pos3 = line.find(",", pos2 + 1);
//			otherline = line.substr(pos1 + 1, pos2 - pos1 - 1) + "," + line.substr(pos3 + 1);
//			quantity = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
//			sumQuantity += quantity;
//			date = { otherline, day, month, year, quantity };
//			times.push_back(date);
//		}
//	}
//	sort(times.begin(), times.end(), NumQuan);
//	cout << endl;
//	cout << "Quantity: " << sumQuantity << endl;
//	for (const auto& date : times) {
//		cout << date.day << "." << date.month << "." << date.year << ": " << date.quantity << endl;
//	}
//	file.close();
//}