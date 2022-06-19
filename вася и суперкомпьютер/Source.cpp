#include <iostream>
#include <string>
#include<fstream>
#include <vector>
#include <algorithm>
using namespace std;

int key = 0, temp = 0;

void InsertSort(vector<int>& mas, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		key = i + 1;
		temp = mas[key];
		for (int j = i + 1; j > 0; j--)
		{
			if (temp > mas[j - 1])
			{
				mas[j] = mas[j - 1];
				key = j - 1;
			}
		}
		mas[key] = temp;
	}

}

int main()
{
	ifstream f1("input.txt");
	ofstream f2("output.txt");
	int N, length;
	f1 >> N;
	vector<int>a;/*01*/
	vector<int>b;/*10*/
	string str;

	int ch_00 = 0, ch_11 = 0;
	for (int i = 0; i < N; i++)
	{
		f1 >> length;
		f1 >> str;

		if (str[0] == '0')
		{
			if (str[length - 1] == '0')
			{
				ch_00 += length;
			}
			else
			{
				a.push_back(length);
			}
		}
		if (str[0] == '1')
		{
			if (str[length - 1] == '1')
			{
				ch_11 += length;
			}
			else
			{
				b.push_back(length);
			}
		}
	}

	int ch_01 = a.size();
	int ch_10 = b.size();

	if (ch_01 == 0 && ch_10 == 0) {
		f2 << max(ch_11, ch_00);
		return 0;
	}

	InsertSort(a, ch_01);
	InsertSort(b, ch_10);

	int sum = ch_11 + ch_00, len = min(ch_01, ch_10);
	for (int i = 0; i < len; i++)
	{
		sum += a[i] + b[i];
	}

	if (ch_01 > len)
	{
		sum += a[len];
	}
	if (ch_10 > len)
	{
		sum += b[len];
	}

	f2 << sum;

	a.clear();
	b.clear();
	return 0;
}