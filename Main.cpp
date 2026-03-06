#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(nullptr));	// 난수 시드 초기화

	int ComputerCard[3] = { 0, };
	int PlayerCard[3] = { 0, };

	int ComputerSum = 0;
	int PlayerSum = 0;

	// 카드 뽑기
	for (int i = 0; i < 3; i++)
	{
		ComputerCard[i] = rand() % 13 + 1;	//1 ~ 13
		PlayerCard[i] = rand() % 13 + 1;
	}

	// 카드 내용 출력
	cout << "컴퓨터: ";
	for (int i = 0; i < 3; i++)	// 컴퓨터
	{
		switch (ComputerCard[i])
		{
		case 11:
			cout << "J";
			break;
		case 12:
			cout << "Q";
			break;
		case 13:
			cout << "K";
			break;
		default:
			cout << ComputerCard[i];
			break;
		}
		cout << " ";
	}
	cout << "\n플레이어: ";
	for (int i = 0; i < 3; i++)	// 플레이어
	{
		switch (PlayerCard[i])
		{
		case 11:
			cout << "J";
			break;
		case 12:
			cout << "Q";
			break;
		case 13:
			cout << "K";
			break;
		default:
			cout << PlayerCard[i];
			break;
		}
		cout << " ";
	}
	cout << "\n";

	// 카드 더하기
	for (int i = 0; i < 3; i++)
	{
		// 컴퓨터의 패가 10 이상이면 10을 더한다.
		if (ComputerCard[i] >= 10)
		{
			ComputerSum += 10;
		}
		else
		{
			ComputerSum += ComputerCard[i];
		}

		// 플레이어의 패가 10 이상이면 10을 더한다.
		if (PlayerCard[i] >= 10)
		{
			PlayerSum += 10;
		}
		else
		{
			PlayerSum += PlayerCard[i];
		}
	}

	// 각자 총합 출력
	cout << "\n컴퓨터 점수: " << ComputerSum << endl;
	cout << "플레이어 점수: " << PlayerSum << endl;

	// 크기 비교: 총합 21 초과면 패배
	if (PlayerSum > 21 || ComputerSum > 21)
	{
		if (ComputerSum > 21)
		{
			cout << "\n컴퓨터 패배" << endl;
			cout << "플레이어 승" << endl;
		}
		else
		{
			cout << "\n컴퓨터 승리" << endl;
			cout << "플레이어 패배" << endl;
		}
	}
	else if (ComputerSum <= PlayerSum) // 플레이어가 컴퓨터보다 점수가 크거나 같으면 플레이어 승리
	{
		cout << "\n컴퓨터 패배" << endl;
		cout << "플레이어 승" << endl;
	}
	else
	{
		cout << "\n컴퓨터 승리" << endl;
		cout << "플레이어 패배" << endl;
	}

	return 0;
}