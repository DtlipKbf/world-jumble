#include "main.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	enum { WORD, HINT, NUM_FIELD };
	const int NUM_WORDS = 12;
	const string WORDS[NUM_WORDS][NUM_FIELD] =
	{
		{"миндовг"," первый князь вкл"},
		{"рогнеда"," княжна с тремя именами"},
		{"кроманьонцы","первобытные люди"},
	    {"погоня", "назввание герба вкл"},
		{"владимир", "крестил русь, насильно женился"},
		{"пятилетка", "экономический план, предполагавшие быстрое развитие СССР"},
		{"великая_война", "событие 1409 - 1411"},
		{"песняры", "ансамбль под управлением владимира мулявина"},
		{"горбачев", "его политикой стала перестройка"},
		{"лукянович", "спас немецкую девочку,но сам при этом погиб"},
		{"курловский_расстрел","событие 18.10.1905"},
		{"кровавое_воскресенье","событие 09.01.1905"}
	};

	cout << "\t\tЭто игра";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << " Word Jumble";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "\n\tПравила:";
	cout << "\n1.Если вы передумали или устали от участия в игре - напишите 'стоп'";
	cout << "\n2.Если вы зашли в тупик, то напишите 'подсказка'";
	
	string b = "";
	cout << "\n\nхочешь отгадать слово: ";
	do {
		cin >> b;
	} while (b != "да" && b != "нет");
	
	while (b != "нет") {
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
		cout << "\nперемешанное слово: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << jumble;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "\nтвой вариант: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cin >> guess;

		//игровой цикл
		while (guess != word && guess != "стоп") {
			if (guess == "подсказка") {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				cout << hint;
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << "\nнет, это не верный вариант";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << "\nтвой вариант: ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cin >> guess;
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		if (guess == word) cout << "ты отгадал!!!\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		if (guess == "стоп") {
			b="нет";
		}
	}

	system("pause");
	return 0;
}