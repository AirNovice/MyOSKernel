#include<stdio.h>

int DandC(int *, int, int);
int MaxinThree(int, int, int);
int MaxSuminLine(int *, int, int);

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int list[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &list[i]);
	}
	printf("%d", DandC(list, 0, n - 1));
	return 0;
}

int MaxinThree(int a, int b, int c)
{
	return a > b ? a > c ? a : c : b > c ? b : c;
}

int MaxSuminLine(int *list, int begin, int end)
{
	int max_sum = 0, this_sum = 0;
	if(begin > end)
	{
		for(int i = begin; i >= end; i--)
		{
			this_sum += list[i];
			if(this_sum > max_sum)
				max_sum = this_sum;
		}
	}
	else if(begin < end)
	{
		for(int i = begin; i <= end; i++)
		{
			this_sum += list[i];
			if(this_sum > max_sum)
				max_sum = this_sum;
		}
	}
	return max_sum;
}

int DandC(int *list, int begin, int end)
{
	int max_sum = 0, max_left_sum, max_right_sum, max_accross_left, max_accross_right;
	int mid;
	if(begin == end)
	{
		if(list[begin] > max_sum)
			max_sum = list[begin];
		return max_sum;
	}
	mid = (begin + end) / 2;
	max_left_sum = DandC(list, begin, mid);
	max_right_sum = DandC(list, mid + 1, end);
	max_accross_left = MaxSuminLine(list, mid, begin);
	max_accross_right = MaxSuminLine(list, mid + 1, end);
	return MaxinThree(max_left_sum, max_right_sum, max_accross_left + max_accross_right);
}