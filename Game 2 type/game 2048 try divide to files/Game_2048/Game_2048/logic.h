#include "dessign.h"

class Logic :public Dessign
{
private:
	int board[4][4]; // ����, ����� ��� 
	int dirLine[4] = { 1, 0, -1, 0 };
	int dirColumn[4] = { 0, 1 ,0, -1 };
public:
	int lose = 0;

	pair<int, int>generateUnocccupiedPosition()  // ��� ���� ��� ���������� � �� ���������� � �� ��������
	{
		int occupied = 1, line, column;
		while (occupied)
		{
			line = rand() % 4;
			column = rand() % 4;

			if (board[line][column] == 0)
			{
				occupied = 0;
			}
		}

		return make_pair(line, column);
	}

	void addPiace(); // ���� �� ��� ��� �������� ���� 2 �� �����

	void newGame(); // �������� ������ ���� ���
	
	void printUI();  // �������� �� ����� ������ ���� 
	
	bool canDoMove(int line, int column, int nextLine, int nextColumn); // �������� �� ����� ������ ��������� ����
	
	void applyMove(int direction);  // ����� ��������� ������ ����� �� ����� 
	
	void GameProsses(); // ����� ��� ��� ���� ��� ���(�� ������� �� ���� �� ����� �������� ��� ������ ���)
	
};