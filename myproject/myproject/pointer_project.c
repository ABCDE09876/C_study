#include <stdio.h>
#include<time.h>


//����Ⱑ 6������ �־��
//�̵��� ���׿� ��� �ִµ�, �縷�̿���
//�縷�� �ʹ� ������, �ʹ� �����ؼ� ���� ���� ���� ������ �ؿ�
//���� �� �����ϱ� ���� �������� ���׿� ���� �༭ ����⸦ ����ּ���
//������ �ð��� �������� ���� Ŀ����....���߿���...�ȳ�....

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
		printf("��� ���׿� ���� �ֽðھ��?");
		scanf_s("%d", &num);

		//�Է°� üũ
		if (num < 1 || num>6)
		{
			printf("\n�Է°��� �߸��Ǿ����ϴ�\n");
			continue;
		}

		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("�� ��� �ð�: %ld�� \n", totalElapsedTime);

		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("�ֱ� ��� �ð�: %ld��n", prevElapsedTime);

		if (cursor[num - 1] <= 0)
		{
			printf("%d�� ������ �̹� �׾����ϴ�.. ���� ���� �ʽ��ϴ�\n", num);
		}
		
		else if (cursor[num - 1] + 1 <= 100)
		{
			printf("%d�� ���׿� ���� �ݴϴ� \n\n", num);
			cursor[num - 1] += 1;
		}

		if (totalElapsedTime / 20 > level - 1)
		{
			level++;
			printf("***�� ������! ���� %d�������� %d������ ���׷��̵� ***\n\n", level - 1, level);

			if (level == 5)
			{
				printf("\n\n�����մϴ�. �ְ� ������ �޼��Ͽ����ϴ�. ������ �����մϴ�!\\n");
				exit(0);
			}
		}


		//��� ����Ⱑ �׾����� Ȯ��
		if (checkFishAlive() == 0)
		{
			//����� ��� �Ф�
			printf("��� ����Ⱑ....�Ф�..����...\n");
			exit(0);
		}
		else
		{
			//�ּ� �Ѹ��� �̻��� ������ �������
			printf("����Ⱑ ���� ��� �־��!\n");
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
	printf("%3d�� %3d�� %3d�� %3d�� %3d�� %3d��\n", 1, 2, 3, 4, 5, 6);
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
		arrayFish[i] -= (level * 3 * (int)elapsedTime);//3: ���̵� ������ ���� ��
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