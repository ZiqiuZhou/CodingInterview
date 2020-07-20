#include<iostream>
#include<vector>
using namespace std;

//С�������Լ���������

//С�����⣺�����������κ�һ��Ԫ�أ��ҳ�����߱���С�����ۼӺ�
//��������Ԫ������������ĺͽ���С��
int mergeSortSmallSum(vector<int>& array, int left, int right, int* tmp);
int mergeSmallSum(vector<int>&  array, int left, int center, int right, int* tmp);

void smallSum(vector<int>& array)
{
	if (array.size() == 0)
	{
		cout << "Invalid Input!" << endl;
		return ;
	}
	if (array.size() == 1)
	{
		cout << "No small sum." << endl;
		return ;
	}

	int sum; //����С��
	int left = 0;
	int right = array.size() - 1;
	int* tmp = new int[array.size()];
	sum = mergeSortSmallSum(array, left, right, tmp);
	cout << sum << endl;
	delete[] tmp;
}

int mergeSortSmallSum(vector<int>& array, int left, int right, int* tmp)
{
	if (left == right)
		return 0;
	int center = (left + right) / 2;
	int sum;
	if (left < right)
	{
		sum = mergeSortSmallSum(array, left, center, tmp) + mergeSortSmallSum(array, center + 1, right, tmp)
			+ mergeSmallSum(array, left, center, right, tmp);
	}
	return sum;
}

int mergeSmallSum(vector<int>& array, int left, int center, int right, int* tmp)
{
	int sum = 0;
	int ptrLeft = left;
	int ptrRight = center + 1;
	int current = left;
	while (ptrLeft <= center && ptrRight <= right)
	{
		sum += array[ptrLeft] < array[ptrRight] ? (right - ptrRight + 1) * array[ptrLeft] : 0;
		tmp[current++] = array[ptrLeft] < array[ptrRight] ? array[ptrLeft++] : array[ptrRight++];
	}
	
	while (ptrLeft <= center)
		tmp[current++] = array[ptrLeft++];
	while (ptrRight <= right)
		tmp[current++] = array[ptrRight++];
	
	for (int i = left; i <= right; ++i)
		array[i] = tmp[i];
	
	return sum;
}


//�������⣺��ӡ��������������Լ����������
int mergeSortInversePair(vector<int>& array, int left, int right, int* tmp);
int mergeInversePair(vector<int>& array, int left, int center, int right, int* tmp);

void InversePair(vector<int>& array)
{
	if (array.size() == 0 || array.size() == 1)
	{
		cout << "Invalid Input!" << endl;
		return;
	}

	int inversePairNum; //�������������
	int left = 0;
	int right = array.size() - 1;
	int* tmp = new int[array.size()];
	inversePairNum = mergeSortInversePair(array, left, right, tmp);
	cout << inversePairNum << endl;
	delete[] tmp;
}

int mergeSortInversePair(vector<int>& array, int left, int right, int* tmp)
{
	if (left == right)
		return 0;
	int center = (left + right) / 2;
	int sumOfInversePair;
	if (left < right)
	{
		sumOfInversePair = mergeSortInversePair(array, left, center, tmp) + mergeSortInversePair(array, center + 1, right, tmp)
			+ mergeInversePair(array, left, center, right, tmp);
	}
	return sumOfInversePair;
}

int mergeInversePair(vector<int>& array, int left, int center, int right, int* tmp)
{
	int numOfInversePair = 0;
	int ptrLeft = left;		
	int ptrRight = center + 1;
	int current = left;
	while (ptrLeft <= center && ptrRight <= right)
	{
		numOfInversePair += array[ptrLeft] > array[ptrRight] ? 1 : 0;
		if(array[ptrLeft] > array[ptrRight])
			cout << "(" << array[ptrLeft] << "," << array[ptrRight] << ")" << " ";
		tmp[current++] = array[ptrLeft] < array[ptrRight] ? array[ptrLeft++] : array[ptrRight++];
	}
	while (ptrLeft <= center)
		tmp[current++] = array[ptrLeft++];
	while (ptrRight <= right)
		tmp[current++] = array[ptrRight++];

	for (int i = left; i <= right; ++i)
		array[i] = tmp[i];

	return numOfInversePair;
}

int main()
{
	vector<int> array1{3, 2, 3, 6};
	smallSum(array1);
	vector<int> array2{ 7, 2, 3, 6};
	InversePair(array2);
	return 0;
}