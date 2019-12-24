#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int seed, guess, lower = 1, higher = 100, frequency=1;
	srand(time(NULL));
	do
	{
		seed = rand() % 101;
	} while (seed == 0);
	printf("块 %d~%d 计\n", lower, higher); scanf("%d", &guess);
	do
	{
		if (lower <guess && guess<seed)
		{
			lower = guess;
			printf("块 %d~%d 计   Ω计=>%dΩ\n", lower, higher, frequency); scanf("%d", &guess);
			frequency++;
		}
		else if (guess>seed && higher>guess)
		{
			higher = guess;
			printf("块 %d~%d 计   Ω计=>%dΩ\n", lower, higher, frequency); scanf("%d", &guess);
			frequency++;
		}
		else
		{
			printf("%d ぃ琌 %d~%d 计\n",guess, lower, higher); scanf("%d", &guess);
		}
	} while (seed != guess);
	printf("bingo!!\n");
	system("pause");
	return 0;
}
