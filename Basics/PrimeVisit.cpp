#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N, a, b;

	cin >> N >> a >> b;

	while (N--)
	{
		int count = 0;
		// for(int i=a; i<b; i++)
		bool isprime = true;
		for (int j = a; j < b; j++)
		{
			if (a % j == 0)
			{
				isprime = false;
				break;
			}
		}

		if (isprime)
			count++;

		cout << count << endl;
	}

	return 0;
}
