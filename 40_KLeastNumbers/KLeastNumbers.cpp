#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//��Ŀ: �ҳ������е�kС����

//����1���������ѽṹ���Ƚ�ͷk�����������鲢�����ٱ����������ȥ�ж�
//ʱ�临�Ӷȣ�O(nk)
int KLeastNumbers1(vector<int>& array, int k)
{
	if (array.size() == 0 || k == 0 || k > array.size()) 
		throw new exception("Invalid Input!");

	vector<int> containKNumbers{ array.begin(), array.begin() + k };

	std::sort(containKNumbers.begin(), containKNumbers.end()); // Ĭ�ϵ���
	if (k == array.size())
		return containKNumbers[k - 1];

	for (int i = k; i < array.size(); ++i)
	{
		if (k == 1) //ֻ����С����
		{
			if (containKNumbers[0] > array[i])
				containKNumbers[0] = array[i];
		}
		else if(containKNumbers[k - 1] > array[i])
		{
			if(containKNumbers[k - 2] <= array[i])
				containKNumbers[k - 1] = array[i];
			else
			{
				int j = k - 2;
				while (j >= 0 && containKNumbers[j] > array[i])
				{
					containKNumbers[j + 1] = containKNumbers[j];
					--j;
				}
				containKNumbers[j + 1] = array[i];
			}
		}
	}
	return containKNumbers[k - 1];
}

//����2�������ѽṹ���Ƚ�����Ԫ�ز�����С�ѣ� ��ɾ��k - 1��
//ʱ�临�Ӷȣ�O(n)
int KLeastNumbersWithHeap1(vector<int>& array, int k)
{
	if (array.size() == 0 || k == 0 || k > array.size())
		throw new exception("Invalid Input!");
	priority_queue<int, vector<int>, greater<int> > minHeap; // ��С��
	for (int i = 0; i < array.size(); ++i)
		minHeap.push(array[i]);
	while (k > 1)
	{
		minHeap.pop();
		--k;
	}
	return minHeap.top();
}


//����2�������ѽṹ���Ƚ�ǰk��Ԫ�ز������ѣ� ����ʣ��Ԫ��ȥ�Ƚ�
//ʱ�临�Ӷȣ�O(n)
int KLeastNumbersWithHeap2(vector<int>& array, int k)
{
	if (array.size() == 0 || k == 0 || k > array.size())
		throw new exception("Invalid Input!");
	priority_queue<int> maxHeap; // ����

	for (int i = 0; i < k; ++i)
		maxHeap.push(array[i]);

	if (maxHeap.size() == array.size()) // ���k�����鳤��
		return maxHeap.top();

	for (int i = k; i < array.size(); ++i)
	{
		if (array[i] < maxHeap.top())
		{
			maxHeap.pop();
			maxHeap.push(array[i]);
		}
	}
	return maxHeap.top();
}

int main()
{
	vector<int> vec{4, 5, 1, 6, 2, 7, 3};
	int result = KLeastNumbers1(vec, 4);
	cout << result << endl;
	int result2 = KLeastNumbersWithHeap1(vec, 4);
	cout << result2 << endl;
	cout << KLeastNumbersWithHeap2(vec, 4);
	return 0;
}