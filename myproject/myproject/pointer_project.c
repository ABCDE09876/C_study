#include <stdio.h>
#include<time.h>


//물고기가 6마리가 있어요
//이들은 어항에 살고 있는데, 사막이에요
//사막이 너무 더워서, 너무 건조해서 물이 아주 빨리 증발을 해요
//물이 다 증발하기 전에 부지런히 어항에 물을 줘서 물고기를 살려주세요
//물고기는 시간이 지날수록 점점 커져서....나중에는...냠냠....

int level;
int arrayFish[6];
int* cursor;

void initData();
void printFishes();
void decreaseWater(long elapsedTime);

int main(void)
{
	long startTime = 0;
	long totalElapsedTime = 0;
	long prevElapsedTime = 0;

	int num;
	initData();

	cursor = arrayFish;

	startTime = clock();
	while (1)
	{
		printFishes();
		printf("몇번 어항에 물을 주시겠어요?");
		scanf_s("%d", &num);

		//입력값 체크
		if (num < 1 || num>6)
		{
			printf("\n입력값이 잘못되었습니다\n");
			continue;
		}

		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("총 경과 시간: %ld초 \n", totalElapsedTime);

		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("최근 경과 시간: %ld초n", prevElapsedTime);

		if (cursor[num - 1] <= 0)
		{
			printf("%d번 물고기는 이미 죽었습니다.. 물을 주지 않습니다\n", num);
		}
		
		else if (cursor[num - 1] + 1 <= 100)
		{
			printf("%d번 어항에 물을 줍니다 \n\n", num);
			cursor[num - 1] += 1;
		}

		if (totalElapsedTime / 20 > level - 1)
		{
			level++;
			printf("***축 레벨업! 기존 %d레벨에서 %d레벨로 업그레이드 ***\n\n", level - 1, level);

			if (level == 5)
			{
				printf("\n\n축하합니다. 최고 레벨을 달성하였습니다. 게임을 종료합니다!\\n");
				exit(0);
			}
		}


		//모든 물고기가 죽었는지 확인
		if (checkFishAlive() == 0)
		{
			//물고기 모두 ㅠㅠ
			printf("모든 물고기가....ㅠㅠ..흑흑...\n");
			exit(0);
		}
		else
		{
			//최소 한마리 이상의 물고기는 살아있음
			printf("물고기가 아직 살아 있어요!\n");
		}
		prevElapsedTime = totalElapsedTime;


	}

	return 0;
}

void initData()
{
	level = 1;
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] = 0;
	}
}

void printFishes()
{
	printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++)
	{
		printf("%4d", arrayFish[i]);
	}
	printf("\n\n");
}

void decreaseWater(long elapsedTime)
{
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] -= (level * 3 * (int)elapsedTime);//3: 난이도 조절을 위한 값
		if (arrayFish[i] < 0)
		{
			arrayFish[i] = 0;
		}
	}
}

int checkFishAlive()
{
	for (int i = 0; i < 6; i++)
	{
		if (arrayFish[i] > 0)
			return 1;
	}
	return 0;
}