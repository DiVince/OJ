#include<iostream>
#include<cmath>
using namespace std;

void sort(int parts, int length, float* p)
{
	float temp;
	while (length > 2)
	{
		for (int j = 0; j < parts; j++)
		{
			for (int i = 0; i < (length / 4); i++)
			{
				temp = p[2 * i + 1 + j * length];
				p[2 * i + 1 + j * length] = p[2 * i + length / 2 + j * length];
				p[2 * i + length / 2 + j * length] = temp;
			}
		}
		parts *= 2;
		length /= 2;
	}
}

void wavelet(int L, float* p)
{
	int n = pow(2, L);
	for (int i = 0; i < (n / 2); i++)
	{
		p[2 * i] = (p[2 * i] + p[2 * i + 1]) / 2;
		p[2 * i + 1] = -(p[2 * i] - p[2 * i + 1]);
	}
	sort(1, n, p);
}

#if 1
int main()
{
	cout.setf(ios::fixed);
	cout.precision(4);
	int L, n;
	cin >> L;
	n = pow(2, L);
	float* p = new float[n];
	for (int i = 0; i < n; i++)
		cin >> p[i];
	while (L >= 1)
	{
		wavelet(L, p);
		L--;
	}
	for (int i = 0; i < n; i++)
	{
		cout << p[i] << ' ';
	}
	return 0;
}
#endif
