#include "game.h"

void Game::StartField()
{
	FirstLoader();
	int menu;
	bool exit = true;

	do
	{
		menu = Menu();

		if (menu == 1)
		{
			GameProsses();

			int ch = 0;
			system("cls");

			bool choose = true, exit = true;
			cout << "\n\t Do you want save your resalt?\n";
			cout << "\t          >  Yes < \n";
			cout << "\t             No\n";

			do
			{
				ch = _getch();

				switch (ch)
				{
				case 72:
				{// íàæàòà êëàâèøà ââåðõ
					system("cls");
					cout << "\n\t Do you want save your resalt?\n";
					cout << "\t          >  Yes < \n";
					cout << "\t             No\n";

					choose = true;
					break;
				}
				case 80:
				{// íàæàòà êëàâèøà âíèç
					system("cls");
					cout << "\n\t Do you want save your resalt?\n";
					cout << "\t             Yes\n";
					cout << "\t          >  No < \n";
					choose = false;
					break;
				}
				case 13:
					exit = false;
					break;
				default:
					break;
				}
			} while (exit);

			if (choose)
			{
				system("cls");

				cout << "\n -Save resalts-\n";
				cout << " Enter your name: ";
				cin >> nameuser;

				system("cls");
				SetColor(10, 0);
				cout << "\n Congradulation! Your record save!\n";
				SetColor(15, 0);
				system("pause");

				//çðàçó ï³ñëÿ ãðè çàïèñ ãðàâöÿ ³ éîãî ðåçóëüòàòó ó òåêñòîâèé ôàéë
				write.open("Board_champ.txt", ios::app);  //â³äêðèâàºìî ôàéë äëÿ çàïèñó
				write << " " << nameuser;
				write << " " << bestscore << endl;
				write.close();  //çàêðèâàºìî ôàéë

				system("cls");
			}
		}
		else if (menu == 2)
		{
			system("cls");
			string temp;
			int temp2;
			read.open("Board_champ.txt");  //â³äêðèâàºìî ôàéë äëÿ çàïèñó
			SetColor(14, 0);
			cout << "  --- Board of Champions --- \n";
			SetColor(10, 0);
			cout << "    -User-    ";
			cout << "     -Rezalt- \n";
			SetColor(15, 0);
			int k = 0;
			while (!read.eof())
			{
				k++;
				if (k % 2 == 0)
				{
					read >> temp2;
					userready.insert({ temp, temp2 });   //ç÷èòóºìî
				}
				else
				{
					read >> temp;
				}
			}

			//ñîðòóºìî äëÿ íîðìàëüíîãî âèâîäó íà åêðàí
			vector<pair<string, int>> vec;
			// copy key-value pairs from the map to the vector
			map<string, int> ::iterator it2;
			for (it2 = userready.begin(); it2 != userready.end(); it2++)
			{
				vec.push_back(make_pair(it2->first, it2->second));
			}

			// sort the vector by increasing order of its pair's second value
			sort(vec.begin(), vec.end(), [](const pair<string, int>& a,
				const pair<string, int>& b)
				{
					return (a.second > b.second);
				});

			for (auto el : vec)
			{
				cout << setw(10) << el.first << "     -     " << el.second << endl;
			}
			cout << endl;
			cout << endl;

			system("pause");
			read.close();  //îáîâÿçêîâî çàêðèâàºìî
		}
		else if (menu == 3)
		{
			system("cls");
			SetColor(14, 0);
			cout << "\n \t\t-Settings-\n";
			SetColor(15, 0);
			bool choose = true, exit = true;
			char ch1;
			cout << "\t Do you want change color of Menu?\n";
			cout << "\t          >  Yes < \n";
			cout << "\t             No\n";

			do
			{
				ch1 = _getch();

				switch (ch1)
				{
				case 72:
				{// íàæàòà êëàâèøà ââåðõ
					system("cls");
					SetColor(14, 0);
					cout << "\n \t\t-Settings-\n";
					SetColor(15, 0);
					cout << "\t Do you want change color of Menu?\n";
					cout << "\t          >  Yes < \n";
					cout << "\t             No\n";

					choose = true;
					break;
				}
				case 80:
				{// íàæàòà êëàâèøà âíèç
					system("cls");
					SetColor(14, 0);
					cout << "\n \t\t-Settings-\n";
					SetColor(15, 0);
					cout << "\t Do you want change color of Menu?\n";
					cout << "\t             Yes  \n";
					cout << "\t          >  No <\n";
					choose = false;
					break;
				}
				case 13:
					exit = false;
					break;
				default:
					break;
				}
			} while (exit);

			if (choose)
			{
				system("cls");
				cout << "\n \t -CHOOSE COLOR- \n";
				cout << " Black = 0 \n Blue = 1 \n Green = 2 \n Cyan = 3 \n Red = 4 \n Magenta = 5 \n Brown = 6 ";
				cout << "\n LightGray = 7 \n DarkGray = 8 \n LightBlue = 9 \n LightGreen = 10 \n LightCyan = 11 ";
				cout << " \n LightRed = 12 \n LightMagenta = 13 \n Yellow = 14 \n White = 15\n";
				cout << " Answer: ";
				cin >> color;

				if (color < 0 || color >15)
				{
					color = 12;
				}

			}
			else
			{

			}

		}
		else  // ê³íåöü ãðè
		{
			exit = false;
			system("cls");
			SetColor(0, 14);
			cout << "\t\t Goodbye! Have a nice day ;)\n\n";
			SetColor(15, 0);
		}

	} while (exit);
}
