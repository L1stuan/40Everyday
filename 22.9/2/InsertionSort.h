#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
// from ./22.8.30/SortingArray.h
#include"SortingArray.h"
using std::swap;

template<typename T>
class InsertionSort :public SortingMethod<T>
{
public:
	//ģ�常��������������в���ֱ�ӿɼ��ģ�������Ҫ��ʽ�ñ�����Ѱ�Ҹ���
	using SortingMethod<T>::num;
	using SortingMethod<T>::length;
	using SortingMethod<T>::Greater;


	InsertionSort() :SortingMethod<T>(){}


	void sort() override
	{
		//��������Ĭ����������
		for (int i = 1; i < length; ++i)//��֤��1��iλ�õ�Ԫ��һ����������
		{
			int j = i+1;	//�����i+1��Ԫ��
			while (j > 1 && (num[j-1]>num[j]) )	//whileѭ�������Ԫ��һ������ǰ�ƶ�����һ������С������
			{
				swap(num[j - 1], num[j]);
				j--;
			}
		}

		//���Ҫ�������У��򽻻���β
		if (!Greater) { for (int i = 1; i <= length / 2; ++i) swap(num[i], num[length + 1 - i]); }

		return;
	};

};



#endif