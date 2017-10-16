#include <iostream>

using namespace std;

struct node
{
	double x = 0;
	double y = 0;
};

struct vector
{
	double x = 1;
	double y = 0;
};

int main()
{
	int K = 0;
	cin >> K;
	for (int count = 0; count < K; count++)
	{
		bool convex = 1;
		int N = 0;
		cin >> N;
		struct node* p = new struct node[N];
		for (int i = 0; i < N; i++)
		{
			cin >> p[i].x >> p[i].y;
		}
		struct vector P, Q;

		// TODO:
		for (int i = 0; i < N; i++)
		{
			P.x = p[(i + 1) % N].x - p[i].x;
			P.y = p[(i + 1) % N].y - p[i].y;
			Q.x = p[(i + N - 1) % N].x - p[i].x;
			Q.y = p[(i + N - 1) % N].y - p[i].y;
			if ((P.x*Q.y - P.y*Q.x) > 0)
			{
				convex = 0;
				cout << i << ' ';
			}
		}
		// END

		if (convex)
			cout << 'y';
		delete[] p;
		cout << endl;
	}
	system("pause");
	return 0;
}