#include "Header.h"

void User_Func(){
	int choice = 0;
	do {
		cout << "���������� ������������: " << endl;
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
} 