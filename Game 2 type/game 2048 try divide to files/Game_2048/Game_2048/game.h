#include "logic.h"

class Game : public Logic // ���� ���� ����� ��� � ������� �� ���� ������(����� ���������� �� �� ����� � ����� �����)
{
private:
	ifstream read;
	ofstream write;
	string nameuser;
	map<string, int> userready;
	int score;
public:
	void StartField();
};