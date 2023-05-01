#include "main.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	enum { WORD, HINT, NUM_FIELD };
	const int NUM_WORDS = 12;
	const string WORDS[NUM_WORDS][NUM_FIELD] =
	{
		{"�������"," ������ ����� ���"},
		{"�������"," ������ � ����� �������"},
		{"�����������","����������� ����"},
	    {"������", "��������� ����� ���"},
		{"��������", "������� ����, �������� �������"},
		{"���������", "������������� ����, �������������� ������� �������� ����"},
		{"�������_�����", "������� 1409 - 1411"},
		{"�������", "�������� ��� ����������� ��������� ��������"},
		{"��������", "��� ��������� ����� �����������"},
		{"���������", "���� �������� �������,�� ��� ��� ���� �����"},
		{"����������_��������","������� 18.10.1905"},
		{"��������_�����������","������� 09.01.1905"}
	};

	cout << "\t\t��� ����";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << " Word Jumble";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "\n\t�������:";
	cout << "\n1.���� �� ���������� ��� ������ �� ������� � ���� - �������� '����'";
	cout << "\n2.���� �� ����� � �����, �� �������� '���������'";
	
	string b = "";
	cout << "\n\n������ �������� �����: ";
	do {
		cin >> b;
	} while (b != "��" && b != "���");
	
	while (b != "���") {
		int i = rand() % NUM_WORDS;
		string word = WORDS[i][WORD];
		string hint = WORDS[i][HINT];

		string jumble = word;
		for (int i = 0; i < jumble.size(); i++) {
			int index1 = rand() % jumble.size();
			int index2 = rand() % jumble.size();
			char temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}

		string guess = "";
		cout << "\n������������ �����: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << jumble;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "\n���� �������: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cin >> guess;

		//������� ����
		while (guess != word && guess != "����") {
			if (guess == "���������") {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				cout << hint;
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << "\n���, ��� �� ������ �������";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << "\n���� �������: ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cin >> guess;
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		if (guess == word) cout << "�� �������!!!\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		if (guess == "����") {
			b="���";
		}
	}

	system("pause");
	return 0;
}