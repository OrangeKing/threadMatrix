#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void shiftRight(vector<vector<int>>, int size);
void shiftLeft(vector<vector<int>>, int size);

void shiftUp(vector<vector<int>>, int size);
void shiftDown(vector<vector<int>>, int size);


int main()
{
	vector<vector<int>> arr(5, vector<int>(5));	
	arr[3][3] = 9;
	arr[0][0] = 3;

	cout << "BEFORE:" << endl;

	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size(); j++)
		{
			cout << arr[i][j] << "   ";
		}
		cout << endl;
	}
	cout << endl;


	cout << "AFTR:" << endl;
	shiftLeft(arr,5);

	return 0;
}

void shiftRight(vector<vector<int>> values, int size)
{
	int temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if(values[j][i] != 0)
			{
				if(((i+1) != size) and (values[j][i+1] == 0))
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

void shiftLeft(vector<vector<int>> values, int size)
{
	int temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if(values[j][i] != 0)
			{
				if(((i-1) > 0) and (values[j][i-1] == 0))
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

// 		{
// 			if(((i-1) > 0) and (values[i-1] == 0))
// 			{
// 				temp = values[i];
// 				values[i] = 0;
// 				values[i-1] = temp;
// 				i++;