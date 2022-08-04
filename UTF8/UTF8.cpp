#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <iomanip>

using namespace std;

int main()
{
	int decimal, hexa;
	bool loop = true;
	
	while (loop)
	{
		cout << "Enter intiger x (0 <= x <= 1114111): ";
		cin >> decimal;
		system("CLS");

		if(decimal >= 0 && decimal <= 1114111)
		{
			cout << "Entered number: " << decimal << '\n' << '\n';

			int hexa = decimal;
			vector<int> x;
			while (hexa != 0)
			{
				x.insert(x.begin(), hexa % 16);
				hexa /= 16;
			}

			printf("Unicode: U+");
			if (x.size() < 4)
				for (int i = 0; i < 4 - x.size(); i++)
					cout << "0";

			for (int i = 0; i < x.size(); i++)
			{
				printf("%X", x[i]);
			}
			cout << '\n';

			if (decimal >= 0 && decimal <= 127)
			{
				printf("UTF-8: ");
				for (auto i : x)
					printf("%X", i);
				cout << '\n';
			}
			else if (decimal >= 128 && decimal <= 2047)
			{
				int b, c, temp;

				c = 0b10000000;
				temp = decimal & 0b00111111;
				c = c | temp;

				b = 0b11000000;
				temp = decimal & 0b11111000000;
				temp = temp >> 6;
				b = b | temp;

				printf("UTF-8: %X ", b);
				printf("%X\n", c);

			}
			else if (decimal >= 2048 && decimal <= 65535)
			{
				int a, b, c, temp;

				c = 0b10000000;
				temp = decimal & 0b00111111;
				c = c | temp;

				b = 0b10000000;
				temp = decimal & 0b111111000000;
				temp = temp >> 6;
				b = b | temp;

				a = 0b11100000;
				temp = decimal & 0b1111000000000000;
				temp = temp >> 12;
				a = a | temp;

				printf("UTF-8: %X ", a);
				printf("%X ", b);
				printf("%X\n", c);

			}
			else if (decimal >= 65536 && decimal <= 1114111)
			{
				int a, b, c, d, temp;

				d = 0b10000000;
				temp = decimal & 0b00111111;
				d = d | temp;

				c = 0b10000000;
				temp = decimal & 0b111111000000;
				temp = temp >> 6;
				c = c | temp;

				b = 0b10000000;
				temp = decimal & 0b111111000000000000;
				temp = temp >> 12;
				b = b | temp;

				a = 0b11110000;
				temp = decimal & 0b111000000000000000000;
				temp = temp >> 18;
				a = a | temp;

				printf("UTF-8: %X ", a);
				printf("%X ", b);
				printf("%X ", c);
				printf("%X\n", d);
			}

			char c = decimal;
			ofstream fout("output.txt");
			cout << "CHAR: " << c;
			fout << "CHAR: " << c;
			fout.close();

			while (true)
			{
				int opt;
				cout << '\n' << '\n' << setw(13) << "_OPTIONS_" << '\n' << '\n';
				cout << "(1) |NEXT NUMBER|" << '\n';
				cout << "(2) |TERMINTATE|" << '\n';
				cin >> opt;
				if (opt == 1)
				{
					system("CLS");
					break;
				}
				else if (opt == 2)
				{
					system("CLS");
					loop = false;
					break;
				}
				else
				{
					system("CLS");
					cout << "Invalid input";
				}

			}
		}
		else
		{
			system("CLS");
			cout << "Invalid input" << '\n' << '\n';

		}
	}

	return 0;
}
