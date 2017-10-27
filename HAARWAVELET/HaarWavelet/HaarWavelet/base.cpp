#include<iostream>
#include<cmath>
using namespace std;

void sort(int parts, int length, double* p)
{
	double temp;
	int m;
	while (length > 2)
	{
		m = length / 2;
		//cout << "parts = " << parts << '\t' << "length = " << length << endl;
		for (int j = 0; j < parts; j++)
		{
			for (int i = 0; i < (m / 2); i++)
			{
				temp = p[2 * i + 1 + j * length];
				p[2 * i + 1 + j * length] = p[2 * i + m + j * length];
				p[2 * i + m + j * length] = temp;
				/*
				for (int i = 0; i < length; i++)
				{
					cout << p[i] << ' ';
				}
				cout << endl << endl;
				*/
			}
		}
		parts *= 2;
		length = m;
	}
}

void wavelet(int L, double* p)
{
	int n = pow(2, L);
	int m = n / 2;
	/*
	cout << "L: " << L << endl;
	for (int i = 0; i < n; i++)
	{
		cout << p[i] << ' ';
	}
	cout << endl << endl;
	*/
	for (int i = 0; i < m; i++)
	{
		p[2 * i] = (p[2 * i] + p[2 * i + 1]) / 2;
		p[2 * i + 1] = -(p[2 * i] - p[2 * i + 1]);
	}
	/*
	for (int i = 0; i < n; i++)
	{
		cout << p[i] << ' ';
	}
	cout << endl << endl;
	*/
	sort(1, n, p);
	/*
	for (int i = 0; i < n; i++)
	{
		cout << p[i] << ' ';
	}
	cout << endl << endl;
	*/
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
	double* p = new double[n];
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

#if 0
int main()
{
	double a[16];
	for (int i = 0; i < 16; i++)
	{
		a[i] = i;
	}
	for (int i = 0; i < 16; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl << endl;
	sort(1, 16, a);
	for (int i = 0; i < 16; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl << endl;
	return 0;
}
#endif