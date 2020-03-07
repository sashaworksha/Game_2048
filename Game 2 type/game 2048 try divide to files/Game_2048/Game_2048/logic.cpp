#include "logic.h"

void Logic::addPiace() // ���� �� ��� ��� �������� ���� 2 �� �����
{
	pair<int, int>pos = generateUnocccupiedPosition();
	board[pos.first][pos.second] = 2;
}

void Logic::newGame() // �������� ������ ���� ���
{
	score = 0;
	lose = 0;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			board[i][j] = 0;
		}
	}

	addPiace();
}

void Logic::printUI()  // �������� �� ����� ������ ���� 
{
	InGame();
	char s = 254;
	for (int i = 0; i < 4; ++i)
	{
		SetColor(7, 8);
		cout << "       ";

		SetColor(8, 7);
		cout << setfill(' ') << setw(45) << " ";

		SetColor(7, 8);
		cout << "            " << endl;

		SetColor(7, 8);
		cout << "       ";
		for (int j = 0; j < 4; ++j)
		{
			if (board[i][j] == 0)
			{
				SetColor(15, 0);
				cout << setw(9);
				SetColor(15, 7);
				cout << s;
				SetColor(15, 0);
			}
			else
			{
				SetColor(15, 0);
				cout << setw(9);
				SetColor(15, 7);
				cout << board[i][j];
				SetColor(15, 0);
			}
		}
		SetColor(15, 7);
		cout << "         ";
		SetColor(7, 8);
		cout << "            ";
		SetColor(15, 0);
		cout << endl;

		SetColor(7, 8);
		cout << "       ";

		SetColor(8, 7);
		cout << setfill(' ') << setw(45) << " ";

		SetColor(7, 8);
		cout << "            " << endl;
	}
	SetColor(7, 8);
	cout << setfill(' ') << setw(64) << " " << endl;
	SetColor(14, 8);
	cout << " HOW TO PLAY: Use your arrow keys to move the tiles." << setw(12) << " " << endl;
	cout << " When two tiles with the same number touch, they merge into one!\n";
	cout << setfill(' ') << setw(64) << " " << endl;
	cout << setfill(' ') << setw(38) << " --- Also Use ---" << setfill(' ') << setw(26) << " " << endl;
	cout << setfill(' ') << setw(37) << " -n: new game- " << setfill(' ') << setw(27) << " " << endl;
	cout << setfill(' ') << setw(35) << "-q: quit- " << setfill(' ') << setw(29) << " " << endl;
	cout << setfill(' ') << setw(64) << " " << endl;
	SetColor(15, 0);
}

bool Logic::canDoMove(int line, int column, int nextLine, int nextColumn) // �������� �� ����� ������ ��������� ����
{
	if (nextLine < 0 || nextColumn < 0 || nextLine >= 4 || nextColumn >= 4 ||
		(board[line][column] != board[nextLine][nextColumn] && board[nextLine][nextColumn] != 0))
	{
		return false;
	}
	return true;
}

void Logic::applyMove(int direction)  // ����� ��������� ������ ����� �� ����� 
{
	int startLine = 0, startColumn = 0, lineStep = 1, columnStep = 1;

	if (direction == 0)
	{
		startLine = 3;
		lineStep = -1;
	}

	if (direction == 1)
	{
		startColumn = 3;
		columnStep = -1;
	}

	int movePossible = 0, canAddPiace = 0;
	do
	{
		movePossible = 0;

		for (int i = startLine; i >= 0 && i < 4; i += lineStep)
		{
			for (int j = startColumn; j >= 0 && j < 4; j += columnStep)
			{
				int nextI = i + dirLine[direction], nextJ = j + dirColumn[direction];
				if (board[i][j] && canDoMove(i, j, nextI, nextJ))
				{
					board[nextI][nextJ] += board[i][j];

					if (movePossible == 1)
					{
						score += board[i][j];
						if (score > bestscore)
						{
							bestscore = score;
						}
					}

					board[i][j] = 0;
					movePossible = canAddPiace = 1;
				}
			}
		}

		system("cls");
		printUI();  // ��� ����������� �������� ���������� ����
	} while (movePossible);

	if (canAddPiace)  // ������� �������� ��� �� ����� ����������� ���� 2
	{
		addPiace();
	}
}

void Logic::GameProsses() // ����� ��� ��� ���� ��� ���(�� ������� �� ���� �� ����� �������� ��� ������ ���)
{
	char commandToDir[248];
	commandToDir['s'] = 0;
	commandToDir['d'] = 1;
	commandToDir['w'] = 2;
	commandToDir['a'] = 3;
	newGame();

	while (true)
	{
		system("cls");
		printUI();
		char command;
		char ch = _getch();

		switch (ch)
		{
		case 72:
			// ������ ������� �����
			command = 'w';
			break;

		case 'w':
			// ������ ������� �����
			command = 'w';
			break;
		case 75:
			// ������ ������� ����
			command = 'a';
			break;

		case 's':
			// ������ ������� ����
			command = 's';
			break;

		case 77:
			// ������ ������� ������
			command = 'd';
			break;

		case 'd':
			// ������ ������� ������
			command = 'd';
			break;

		case 80:
			// ������ ������� �����
			command = 's';
			break;

		case 'a':
			// ������ ������� �����
			command = 'a';
			break;

		case 'n':
			// ������ ������� �����
			newGame();
			command = ' ';
			break;

		case 'q':
			// ������ ������� �����
			command = 'q';
			break;

		default:
			command = ' ';
			break;
		}

		if (command == 'q')
		{
			break;
		}
		else if (command == ' ')
		{

		}
		else
		{
			int currentDirection = commandToDir[command];
			applyMove(currentDirection);
		}
	}
}