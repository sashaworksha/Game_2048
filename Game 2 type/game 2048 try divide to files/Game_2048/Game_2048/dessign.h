#include "color.h"

class Dessign //���� � ����� ������ �������� ����� ����� ������������, ���� �� ���� 
{
public:
	int score = 0;  //�������
	int bestscore = 0;  // ��������� ��������� ������ ������
	int color = 12;

	void FirstLoader(); //������ ���� ����� ��������
	
	int Menu();

	void Name(); // ������ �������� ����� ���

	void InGame(); // �������� ����� � ������� ���� �� ��� ���
	
	void SpecialPrint(vector<string> temp, int el);  // ��� ������� ���� ��������

};