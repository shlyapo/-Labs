#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>


using namespace std;

int main()
{
	short k; 
	string s;
	srand(time(NULL)); /*���������� srand, ����� ������ ��� �������� ����� ������*/
	setlocale(LC_ALL, "Russian");
	cin >> k; /* ������ ���������� ��������*/
	string* arry= new string[k]; /* ������� ������������ ������*/
	for ( int j = 0; j < k; j++)
		arry[j] = "0"; 
	/*����� ������� ������ � ����������, ������� ����� ����� ��� ������ �������*/
	string arr[] = {"�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
	for (int i = 0; i < 76; i++) 
	{
		for (int j = 0; j < k; j++)
		{
			string a = arr[rand()%76]; /*������� � ������� ������� rand ��������� ������� � �������*/
			arry[j] = a; /*������ ��� � ����� ������, �� �������� ���� ������� ������*/
		}
	}
	while (s.length()<101) /*������� ���� ��� ����, ����� ������ �������� ������*/
	{
		for (int j = 0; j < k; j++)
		{
			string d =arry[rand()%k]; /*��� �� �� ������ ������� ����� ��������� �������*/
			s += d; /*��������� ��� � ������*/
		}
	}
	cout << s << endl; /*������� ������*/
	return 0;
}
//������� ������ : ��9�������������9�������9�9���������������������9���������������������������������9����ͨ�����ĸ�������͸�;
//�����������5�����������7�������6��������7����������7������6�����������5����������������5�������ި����7�����
