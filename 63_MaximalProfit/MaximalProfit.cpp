#include<iostream>
#include<vector>
using namespace std;

/*��Ŀ����������������Բ�ֵ�� Ҫ��������ǰһ��Ԫ�ر���С�ں�һ��Ԫ��
�������ҳ�����������˳�����Բ�������ֵ��˫��ѭ���������������Ǹ��Ӷȸߣ�
����ֻһ��������Ƚ���СԪ�ر�ʾΪ��Ԫ�أ���С���Բ��ʾΪǰ������֮�
�ڱ��������У����Ͽ�array[i - 1]�Ƿ�����֪��С��������ǣ�����С���滻
��array[i - 1]���������ܱ�֤���Բ���������ʱ��ֵ���Ƚ��Ƿ����֪
������Բ�Ҫ��

�����ϴ��⻹�����ҳ�����������Ե�����ֵ��ֻҪ���Ͻ�array[i - 1]��֮ǰ�ҵ�
�����Ԫ�رȽϣ�������֪���ֵ�͵�ǰֵ֮������ֵ

��˳��Ժ�����Ե���Сֵ�˷��������ã�������ͨ���鲢������O(nlogn)���Ӷ��ҵ�
����˳��Ի�����ԴӶ��ҳ���Сֵ
*/

//���˳�����Բ�
int MaxmalSequencePair(vector<int>& array)
{
	if (array.empty() || array.size() < 2)
		throw new exception("Invalid Input.");

	//��ʼ����Сֵ��������Բ�
	int min = array[0];
	int maxDiff = array[1] - array[0];
	for (int i = 1; i < array.size(); ++i)
	{
		if (array[i - 1] < min) // ������Сֵ
			min = array[i - 1];
		int currentDiff = array[i] - min;
		if (currentDiff > maxDiff)
			maxDiff = currentDiff;
	}
	return maxDiff;
}

//����������Բ�
int MaximalReversePair(vector<int>& array)
{
	if (array.empty() || array.size() < 2)
		throw new exception("Invalid Input.");

	//��ʼ�����ֵ��������Բ�
	int max = array[0];
	int maxDiff = array[0] - array[1];
	for (int i = 1; i < array.size(); ++i)
	{
		if (array[i - 1] > max) // ������Сֵ
			max = array[i - 1];
		int currentDiff = max - array[i];
		if (currentDiff > maxDiff)
			maxDiff = currentDiff;
	}
	return maxDiff;
}

int main()
{
	vector<int> arr{2, 5, 1, 7 ,5, 9, 3, 7, 0, 8};
	cout << MaxmalSequencePair(arr) << " " << MaximalReversePair(arr);
	return 0;
}