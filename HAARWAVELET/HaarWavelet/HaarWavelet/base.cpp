#include<iostream>
#include<cmath>
using namespace std;

void wavelet(int L, double* p, double* q)
{
	int n = pow(2, L);
	/*
	cout << "L: " << L << endl;
	for (int i = 0; i < n; i++)
	{
		cout << p[i] << ' ';
	}
	cout << endl << endl;
	*/
	for (int i = 0; i < n / 2; i++)
	{
		q[i] = (p[2 * i] + p[2 * i + 1]) / 2;
	}
	for (int i = n / 2; i < n; i++)
	{
		q[i] = -(p[2 * (i - (n / 2))] - p[2 * (i - (n / 2)) + 1]) / 2;
	}
	for (int i = 0; i < n; i++)
	{
		p[i] = q[i];
	}
	/*
	for (int i = 0; i < n; i++)
	{
		cout << p[i] << ' ';
	}
	cout << endl << endl;
	*/
}

int main()
{
	cout.setf(ios::fixed);
	cout.precision(4);
	int L, l, n;
	cin >> L;
	l = L;
	n = pow(2, L);
	double* p = new double[n];
	double* q = new double[n];
	for (int i = 0; i < n; i++)
		cin >> p[i];
	//cout << endl << endl;
	while (l >= 1)
	{
		wavelet(l, p, q);
		l--;
	}
	for (int i = 0; i < n; i++)
	{
		cout << p[i] << ' ';
	}
	return 0;
}