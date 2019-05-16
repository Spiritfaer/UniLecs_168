#include <stdio.h>
#include <stdint.h>
#include <time.h>

int32_t	backpack(int32_t sum, int32_t const *w, int32_t size)
{
	int32_t temp, i, j, answer;
	answer = temp = 0;
	j = size;
	while (temp != sum && j >= 0)
	{
		i = 0;
		temp = w[j];
		while (temp < sum)
		{
			if ((temp + w[i]) < sum)
				temp += w[i++];
			else
				break;
		}
		if (temp > answer && temp < sum)
			answer = temp;
		j--;
	}
	return (answer);
}

int main(void)
{
	int32_t sum = 18;
	int32_t weights[] = { 3, 7, 10, 16 };

	clock_t start_time = clock();
	printf("Answer = %d\n", backpack(sum, weights, sizeof(weights) / sizeof(int32_t) - 1));
	double time = clock() - start_time;
	time /= CLOCKS_PER_SEC;
	printf("time = %f", time);
	return (0);
}
