#include<iostream>
#include<cmath>
using namespace std;

void sort(int parts, int length, float* p)
{
	float temp;
	int m;
	while (length > 2)
	{
		m = length / 2;
		for (int j = 0; j < parts; j++)
		{
			for (int i = 0; i < (m / 2); i++)
			{
				temp = p[2 * i + 1 + j * length];
				p[2 * i + 1 + j * length] = p[2 * i + m + j * length];
				p[2 * i + m + j * length] = temp;
			}
		}
		parts *= 2;
		length = m;
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
	int L, l, n;
	cin >> L;
	l = L;
	n = pow(2, L);
	float* p = new float[n];
	for (int i = 0; i < n; i++)
		cin >> p[i];
	while (l >= 1)
	{
		wavelet(l, p);
		l--;
	}
	for (int i = 0; i < n; i++)
	{
		cout << p[i] << ' ';
	}
	return 0;
}
#endif
