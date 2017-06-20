#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void shiftRight(vector<vector<int>> &values);
void shiftLeft(vector<vector<int>>	&values);
void shiftUp(vector<vector<int>>	&values);
void shiftDown(vector<vector<int>> 	&values);


int main()
{
	vector<vector<int>> arr(4, vector<int>(8));	
	arr[1][1] = 9;
	arr[0][3] = 3;

	cout <<arr.size() << endl;
	cout <<arr[0].size() << endl;


	cout << "BEFORE:" << endl;

	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			cout << arr[i][j] << "   ";
		}
		cout << endl;
	}
	cout << endl;


	cout << "AFTR:" << endl;
	shiftDown(arr);


	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			cout << arr[i][j] << "   ";
		}
		cout << endl;
	}
	cout << endl;

	cout << endl;

	return 0;
}

void shiftRight(vector<vector<int>> &values)
{
	int temp;
	for (int i = 0; i < values[i].size(); i++)
	{
		for (int j = 0; j < values.size(); j++)
		{
			if(values[j][i] != 0)
			{
				if(((i+1) != values[i].size()) and (values[j][i+1] == 0))
				{
					temp = values[j][i];
					values[j][i] = 0;
					values[j][i+1] = temp;
					i++;
				}
			}
		}
	}
}

void shiftLeft(vector<vector<int>> &values)
{
	int temp;
	for (int i = 0; i < values[i].size(); i++)
	{
		for (int j = 0; j < values.size(); j++)
		{
			if(values[j][i] != 0)
			{
				if(((i-1) >= 0) and (values[j][i-1] == 0))
				{
					temp = values[j][i];
					values[j][i] = 0;
					values[j][i-1] = temp;
					i++;
				}
			}
		}
	}
}

void shiftUp(vector<vector<int>> &values)
{
	int temp;
	for (int i = 0; i < values[i].size(); i++)
	{
		for (int j = 0; j < values.size(); j++)
		{
			if(values[j][i] != 0)
			{
				if(((j-1) >= 0) and (values[j-1][i] == 0))
				{
					temp = values[j][i];
					values[j][i] = 0;
					values[j-1][i] = temp;
					i++;
				}
			}
		}
	}
}

void shiftDown(vector<vector<int>> &values)
{
	int temp;
	for (int i = 0; i < values[i].size(); i++)
	{
		for (int j = 0; j < values.size(); j++)
		{
			if(values[j][i] != 0)
			{
				if(((j+1) != values[i].size()) and (values[j+1][i] == 0))
				{
					temp = values[j][i];
					values[j][i] = 0;
					values[j+1][i] = temp;
					i++;
				}
			}
		}
	}
}