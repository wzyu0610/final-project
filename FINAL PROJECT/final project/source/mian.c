#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void deal(int *who);
void niuniu(int *who);
int aa, bb, temp;

int main(void)
{
	
	int order,x,continu=1;
	int Bookmaker[5] = { 0 };
	int Player[5] = { 0 };
	int repeat[52] = { 0 };
	srand(time(NULL));
	while (continu==1)
	{
		for (int i = 0; i < 52; i++)
		{
		again:
			order = rand() % 52;;
			if (i != 0)
			{
				for (int j = 0; j < i; j++)
				{
					if (repeat[j] == order)
						goto again;
					else
						repeat[i] = order;
				}
			}
			else
				repeat[i] = order;
		}
		x = 0;
		for (int i = 0; i < 10; i += 2)
		{
			Bookmaker[x] = repeat[i];
			x++;
		}
		x = 0;
		for (int i = 1; i < 10; i += 2)
		{
			Player[x] = repeat[i];
			x++;
		}
		printf("���a�P:");
		deal(Bookmaker);
		niuniu(Bookmaker);
		aa = temp;
		printf("\n  ��P:");
		deal(Player);
		niuniu(Player);
		bb = temp;
		if (bb == 0)
		{
			printf("���a�鱼�`�X\n");
			goto abc;
		}
			if (aa > bb)
			{
				printf("\n      ���a�ӧQ\n\n");
			}
			if (bb > aa)
			{
				printf("\n      ���a�ӧQ\n\n");
			}
			if (bb == aa)
			{
				printf("\n      ����\n\n");
			}
			if (bb == 10 && bb > aa)
			{
				printf("���aĹ�o3���m��\n");
			}
			if (bb == 7 || bb == 8 || bb == 9 && bb > aa)
			{
				printf("���aĹ�o2���m��\n");
			}
			if (bb < 7 && bb > aa)
			{
				printf("���aĹ�o1���m��\n");
			}
			if (aa > bb)
			{
				printf("���a�鱼�`�X\n");
			}
			if (aa == bb)
			{
				printf("���a�i���^�`�X\n");
			}
		abc:
		printf("\n�~���J1�A������J0:");
		scanf_s("%d", &continu);
		if (continu==0)
		{
			system("pause");
			return 0;
		}
	}
}
void deal(int *who)
{
	int judge, color;
	for (int i = 0; i < 5; i++)
	{
		judge = who[i] / 13;
		color = who[i] % 13 + 1;
		switch (judge)
		{
		case 0:
			switch (color)
			{
			case 1:
				printf("�®�A ");
				break;
			case 11:
				printf("�®�J ");
				break;
			case 12:
				printf("�®�Q ");
				break;
			case 13:
				printf("�®�K ");
				break;
			default:
				printf("�®�%d ", color);
				break;
			}
			break;
		case 1:
			switch (color)
			{
			case 1:
				printf("�R��A ");
				break;
			case 11:
				printf("�R��J ");
				break;
			case 12:
				printf("�R��Q ");
				break;
			case 13:
				printf("�R��K ");
				break;
			default:
				printf("�R��%d ", color);
				break;
			}
			break;
		case 2:
			switch (color)
			{
			case 1:
				printf("���A ");
				break;
			case 11:
				printf("���J ");
				break;
			case 12:
				printf("���Q ");
				break;
			case 13:
				printf("���K ");
				break;
			default:
				printf("���%d ", color);
				break;
			}
			break;
		case 3:
			switch (color)
			{
			case 1:
				printf("����A ");
				break;
			case 11:
				printf("����J ");
				break;
			case 12:
				printf("����Q ");
				break;
			case 13:
				printf("����K ");
				break;
			default:
				printf("����%d ", color);
				break;
			}
			break;
		}
	}
}
void niuniu(int *who)
{
	int value[10], Point[10], x = 0;
	for (int i = 0; i < 5; i++)
	{
		if (who[i] % 13 + 1 > 9)
			who[i] = 9;
	}
	value[0] = (who[0] % 13 + who[1] % 13 + who[2] % 13 + 3) % 10; Point[0] = who[3] % 13 + who[4] % 13 + 2;
	value[1] = (who[0] % 13 + who[1] % 13 + who[3] % 13 + 3) % 10; Point[1] = who[2] % 13 + who[4] % 13 + 2;
	value[2] = (who[0] % 13 + who[1] % 13 + who[4] % 13 + 3) % 10; Point[2] = who[2] % 13 + who[3] % 13 + 2;
	value[3] = (who[0] % 13 + who[2] % 13 + who[3] % 13 + 3) % 10; Point[3] = who[1] % 13 + who[4] % 13 + 2;
	value[4] = (who[0] % 13 + who[2] % 13 + who[4] % 13 + 3) % 10; Point[4] = who[1] % 13 + who[3] % 13 + 2;
	value[5] = (who[0] % 13 + who[3] % 13 + who[4] % 13 + 3) % 10; Point[5] = who[1] % 13 + who[2] % 13 + 2;
	value[6] = (who[1] % 13 + who[2] % 13 + who[3] % 13 + 3) % 10; Point[6] = who[0] % 13 + who[4] % 13 + 2;
	value[7] = (who[1] % 13 + who[2] % 13 + who[4] % 13 + 3) % 10; Point[7] = who[0] % 13 + who[3] % 13 + 2;
	value[8] = (who[1] % 13 + who[3] % 13 + who[4] % 13 + 3) % 10; Point[8] = who[0] % 13 + who[2] % 13 + 2;
	value[9] = (who[2] % 13 + who[3] % 13 + who[4] % 13 + 3) % 10; Point[9] = who[0] % 13 + who[1] % 13 + 2;
	for (int i = 0; i < 10; i++)
	{
		if (value[i] == 0)
		{
			if (Point[i] > 10)
			{
				Point[i] = Point[i] % 10;
				if (Point[i] == 0)
				{
					Point[i] = Point[i] + 10;
					printf("\n\n      �I�Ƭ�:����LP33\n");
					x++;
					temp = Point[i];
					goto end;
				}
				printf("\n\n      �I�Ƭ�:%d\n", Point[i]);
				x++;
				temp = Point[i];
				goto end;
			}
			printf("\n\n      �I�Ƭ�:%d\n", Point[i]);
			x++;
			temp = Point[i];
			
		}
	}
	end:
	if (x == 0)
	{
		printf("\n\n      �S�I\n\n");
		temp = x;
	}
}