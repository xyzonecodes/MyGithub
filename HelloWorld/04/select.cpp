#include "select.h"
#include <iostream>
#include <ctime>

using namespace std;

namespace totcp{
	select::select()
	{
	}


	select::~select()
	{
	}

	void select::sort(T *t, int n){
		for (int i = 0; i < n-1; i++)
		{
			int pos = i;
			for (int j = i+1; j <n; j++)
			{
				if (t[j] < t[pos])
					pos = j;
			}
			swap(t[pos], t[i]);
		}
	}
	void select::showMain(){
		const int N = 10240;
		T  t[N];
		for (int i = 0; i < N; i++)
		{
			t[i] = N - i;
		}
		cout << "t[1023]:" << t[1023] << endl;
		time_t t1 = time(NULL);
		sort(t, N);
		time_t t2 = time(NULL);
		cout << "time:" << t2 - t1 << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << t[i] << " ";
		}
		cout << endl;
	}

}