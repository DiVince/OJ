#include<iostream>
#include<cmath>
using namespace std;



void wavelet(int L, double* p)
{
	int n = pow(2, L);
	int m = n / 2;
	double*q = new double[m];
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
		q[i] = -(p[2 * i] - p[2 * i + 1]) / 2;
	}
	for (int i = 0; i < m; i++)
	{
		p[i] = (p[2 * i] + p[2 * i + 1]) / 2;
	}
	for (int i = m; i < n; i++)
	{
		p[i] = q[i - m];
	}
	/*
	for (int i = 0; i < n; i++)
	{
		cout << p[i] << ' ';
	}
	cout << endl << endl;
	*/
	delete[] q;
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
	//double* q = new double[n];
	for (int i = 0; i < n; i++)
		cin >> p[i];
	//cout << endl << endl;
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