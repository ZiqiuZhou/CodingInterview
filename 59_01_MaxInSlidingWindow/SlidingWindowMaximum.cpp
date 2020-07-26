#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//�������ڴ����һ������飬�̶�������ÿһʱ�̴����е����ֵ
//������˫�˶��������һ�����ʵʱ���ֵ��������������ֻ���������
//����Ӧ����Ԫ��ֵ������á�
//������Ԫ�أ��Ͷ�β�Ƚϣ���β��ŵ�������ӦԪ��С����pop��β��ֱ������
//��������ӦԪ��ֵ������߶����ѿ�
//ɾ�������й���Ԫ�أ�����ͷ��һ���ǵ�ǰ���ֵ������������ֵ������������
vector<int> SlidingWindowMaxvector(vector<int>& array, int winLength)
{
	if (array.empty() || winLength > array.size())
		throw new exception("Invalid Input!");

	vector<int> maxInTime;
	deque<int> winDeque; // ˫�˶���
	for (int i = 0; i < array.size(); ++i)
	{
		//�������Ԫ��С��������pop,ֱ������Ϊ��
		while (!winDeque.empty() && array[winDeque.back()] < array[i])
			winDeque.pop_back();
		winDeque.push_back(i); // �������

		//ɾ�����ڽڵ�:�����ȴ���˻�С
		if (winDeque.front() == i - winLength)
			winDeque.pop_front();
		maxInTime.push_back(array[winDeque.front()]);
	}
	return maxInTime;
}

int main()
{
	vector<int> arr{1, 4, 6, 2, 8, 5, 11, 3, 6, 15, 9, 2, 6, 12, 8, 5};
	vector<int> result = SlidingWindowMaxvector(arr, 5);
	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << " ";
}