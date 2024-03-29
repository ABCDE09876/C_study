#include<stdio.h>
#include<time.h>

int arrayAnimal[4][5];
int checkAnimal[4][5];
char* strAnimal[10];

char* startAnimal[10];
char* cPtr = "砺什闘";

void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);

int main(void)
{
	srand(time(NULL));

	initAnimalArray();
	initAnimalName();

	shuffleAnimal();

	int failCount = 0;

	while (1)
	{
		int select1 = 0;
		int select2 = 0;

		printAnimals();
		printQuestion();
		printf("及増聖 朝球研 2鯵 壱牽室推:");
		scanf_s("%d%d",&select1, &select2);

		if (select1 == select2)
			continue;

		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);

		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);

		if ((checkAnimal[firstSelect_x][firstSelect_y] == 0
			&& checkAnimal[secondSelect_x][secondSelect_y] == 0)

			&&

			(arrayAnimal[firstSelect_x][firstSelect_y]
				== arrayAnimal[secondSelect_x][secondSelect_y])
			)
		{
			printf("\n\n桜壱!:%s 降胃\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}
		else
		{
			printf("\n\n強!!(堂携暗蟹, 戚耕 及増微 朝球脊艦陥)\n");
			printf("%d:%s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("%d:%s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("\n\n");

			failCount++;
		}

		if (foundAllAnimals() == 1)
		{
			printf("\n\n 逐馬杯艦陥! 乞窮 疑弘聖 陥 達紹革推\n");
			printf("走榎猿走 恥 %d腰 叔呪馬心柔艦陥 \n", failCount);
			break;
		}
	}

	return 0;
}
void initAnimalArray()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arrayAnimal[i][j] = -1;
		}
	}
}

void initAnimalName()
{
	strAnimal[0] = "据周戚";
	strAnimal[0] = "馬原";
	strAnimal[0] = "悪焼走";
	strAnimal[0] = "壱丞戚";
	strAnimal[0] = "掬走";

	strAnimal[0] = "坪晦軒";
	strAnimal[0] = "奄鍵";
	strAnimal[0] = "開展";
	strAnimal[0] = "展繕";
	strAnimal[0] = "硲櫛戚";
}

void shuffleAnimal()
{
	//けけけけけ
	//けけけけけ
	//けけけけけ
	//けけけけけ


	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int pos = getEmptyPosition();
			int x = conv_pos_x(pos);
			int y = conv_pos_y(pos);

			arrayAnimal[x][y] = i;
		}
	}
}

int getEmptyPosition()
{
	//けけけけけ
	//けけけけけ
	//けけけけけ
	//けけけけけ
	//けけけけけ

	while (1)
	{
		int randPos = rand() % 20;

		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);

		if (arrayAnimal[x][y] == -1)
		{
			return randPos;
		}

	}
	return 0;
}

int conv_pos_x(int x)
{
	return x / 5;
}
int conv_pos_y(int y)
{
	return y % 5;
}

void printAnimals()
{
	printf("\n=================戚闇 搾腔昔汽 侯掘 左食掃艦陥==============\n\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%8s", strAnimal[arrayAnimal[i][j]]);
		}
		printf("\n");
	}
	printf("\n================\n\n");
}
void printQuestion()
{
	printf("\n\n(庚薦)\n");
	int seq = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (checkAnimal[i][j] != 0)
			{
				printf("%8s", strAnimal[arrayAnimal[i][j]]);
			}
			else
			{
				printf("%8d", seq++);
			}
		}
		printf("\n");
	}
}

int foundAllAnimals()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (checkAnimal[i][j] == 0)
			{
				return 0;
			}
		}
	}
}