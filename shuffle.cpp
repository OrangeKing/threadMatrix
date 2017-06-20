#include <iostream>
#include <vector>
#include <iomanip>

#include "window.h"


void shiftRight(std::vector<std::vector<char>> &values)
{
	int temp;
	for (int i = 0; i < values[i].size(); i++)
	{
		for (int j = 0; j < values.size(); j++)
		{
			if(values[j][i] == 'x')
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

void shiftLeft(std::vector<std::vector<char>> &values)
{
	int temp;
	for (int i = 0; i < values[i].size(); i++)
	{
		for (int j = 0; j < values.size(); j++)
		{
			if(values[j][i] == 'x')
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

void shiftUp(std::vector<std::vector<char>> &values)
{
	int temp;
	for (int i = 0; i < values[i].size(); i++)
	{
		for (int j = 0; j < values.size(); j++)
		{
			if(values[j][i] == 'x')
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

void shiftDown(std::vector<std::vector<char>> &values)
{
	int temp;
	for (int i = 0; i < values[i].size(); i++)
	{
		for (int j = 0; j < values.size(); j++)
		{
			if(values[j][i] == 'x')
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