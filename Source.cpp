#if 1
#include<stdio.h>
char str[100000 + 10];
/*
()(((()())(())()))(())
*/
void main()
{
	freopen("쇠막대기.txt", "r", stdin);
	scanf("%s", &str);
	int i, cnt = 0, sum = 0;
	for (i = 0; str[i]; i++)
	{
		if (str[i] == '(')  //    올려놓은 쇠막대기 추가
		{
			cnt++;
		}
		else// 레이저 또는 쇠막대기 감소
		{
			cnt--;
			if (str[i - 1] == '(')
			{
				sum += cnt; //    레이저
			}
			else
			{
				sum++;       //    쇠막대기 하나 끝나므로, 조각개수 증가
			}
		}
	}
	printf("%d\n", sum);
}
#endif
#if 0
// 도약
#include<stdio.h>
/*
입력 예시
5
3
1
10
7
4
*/
int N;
int arr[1010];
void sort()
{
	int i, j, tmp;
	for (i = 0; i < N - 1; i++)
	{
		for (j = 0; j < N - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
int bs_up(int d)
{
	int s = 0, e = N-1, m, sol = 0;
	while (s <= e) {
		m = (s + e) / 2;
		if (arr[m]<d) {
			sol = m + 1;
			s = m + 1;
		}
		else e = m - 1;
	}
	return sol;
}
void main()
{
	freopen("도약.txt", "r", stdin);
	int i, j, k, sol=0;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort();
	int step1, step2;
	int a, b;
	for (i = 0; i < N - 2; i++)
	{
		for (j = i + 1; j < N - 1; j++)
		{
			step1 = arr[j] - arr[i];
			a = bs_up(arr[j] + step1 * 2 + 1);
			b = bs_up(arr[j] + step1);
			sol = sol + (a - b);
			//for (k = j + 1; k < N; k++)
			//{
			//	step2 = arr[k] - arr[j];
			//	if (step2 < step1 || (step1 * 2) < step2) continue;
			//	printf("i: %d(%d), j: %d(%d), k: %d(%d), sol: %d\n", i, arr[i], j, arr[j], k, arr[k], sol++);
			//}
		}
	}
	printf("%d", sol);
}

#endif 