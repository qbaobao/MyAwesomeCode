#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool CalSeclectMethod(const vector<int>& weight, const vector<int>& value, const int& bagContain, vector<vector<int>>& selectMethd);
void PrintSelectMethod(const vector<int>& weight, const vector<int>& value, const int& bagContain, vector<vector<int>>& selectMethd);
int main()
{
	vector<int> weight, value;
	vector<vector<int>> selectMethd;
	int bagContain;
	weight.push_back(0);
	weight.push_back(4);
	weight.push_back(5);
	weight.push_back(6);
	weight.push_back(2);
	weight.push_back(2);
	value.push_back(0);
	value.push_back(6);
	value.push_back(4);
	value.push_back(5);
	value.push_back(3);
	value.push_back(6);
	bagContain = 10;

	bool result = CalSeclectMethod(weight, value, bagContain, selectMethd);
	PrintSelectMethod(weight, value, bagContain, selectMethd);

	if (result) {
		cout << "The selected item can be filled with a backpack!" << endl;
	}
	return 0;
}

bool CalSeclectMethod(const vector<int>& weight, const vector<int>& value, const int& bagContain, vector<vector<int>>& selectMethd)
{

	for (int i = 0; i < weight.size(); i++) {
		vector<int> tmp(bagContain + 1, 0);
		selectMethd.push_back(tmp);
	}

	for (int i = 1; i < weight.size(); i++) {
		for (int j = 1; j <= bagContain; j++) {
			selectMethd[i][j] = selectMethd[i - 1][j];
			if (weight[i] <= j) {
				selectMethd[i][j] = max(selectMethd[i - 1][j],
					selectMethd[i - 1][j - weight[i]] + value[i]);
			}
		}
	}
	return ((selectMethd[weight.size() - 1][bagContain]) > 0);
}
void PrintSelectMethod(const vector<int>& weight, const vector<int>& value, const int& bagContain, vector<vector<int>>& selectMethd)
{
	int remainWight = bagContain;
	for (int i = weight.size() - 1; i > 0; i--) {
		if (selectMethd[i][remainWight] - selectMethd[i - 1][remainWight - weight[i]] ==
			value[i]) {
			remainWight -= weight[i];
			cout << i << "th product's value is " << value[i] << ", weight is " << weight[i] << endl;
		}
		if (remainWight <= 0) {
			break;
		}
	}
	return;
}