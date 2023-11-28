#include "Trie.h"
#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "");
	TrieNode* Trie = getNewNode();
	Trie->insert(Trie, "monday");
	Trie->insert(Trie, "morning");
	Trie->insert(Trie, "morrow");
	Trie->insert(Trie, "parmesan");
	Trie->insert(Trie, "pastor");
	Trie->insert(Trie, "party");
	string input;
	int res = 0;
	while (input != "q" and input != "Q")
	{
		input.clear();
		cout << "опции:" << endl;
		cout << "1 - добавить слово" << endl;
		cout << "2 - тест программы" << endl;
		cout << "q - выйти из программы" << endl << endl;
		cin >> input;
		if (input == "1") res = 1;
		else if (input == "2") res = 2;
		else if (input == "q" or input == "Q") return 0;
		else cout << "Неверная команда!" << endl;
		cout << endl;
		switch (res)
		{
		case 1:
		{
			cout << "Введите слово на латинице для включения в словарь " << endl;
			cout << "либо back для перехода в меню:" << endl << endl;
			while (input != "back" and input != "Back")
			{
				input.clear();
				cin >> input;
				if (input != "back" and input != "Back")
				{
					Trie->insert(Trie, input);
				}
			}
			cout << endl;
		}
		case 2:
		{
			cout << "Введите слово на латинице " << endl;
			cout << "либо back для перехода в меню:" << endl << endl;;
			while (input != "back" and input != "Back")
			{
				input.clear();
				cin >> input;
				if (input != "back" and input != "Back")
				{
					Trie->showVariants(Trie, input);
				}
			}
			cout << endl;
		}
		}
	}

	return 0;
}