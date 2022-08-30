#ifndef BUBBLESORT_H
#define BUBBLESORT_H
// from ./22.8.30/SortingArray.h
#include"SortingArray.h"
using std::swap;

template<typename T>
class Bubblesort :public SortingMethod<T>
{
public:
	//ģ�常��������������в���ֱ�ӿɼ��ģ�������Ҫ��ʽ�ñ�����Ѱ�Ҹ���
	using SortingMethod<T>::num;
	using SortingMethod<T>::length;
	using SortingMethod<T>::Greater;


	Bubblesort() :SortingMethod<T>(){}


	void sort() override
	{
		//ð������Ĭ����������
		for (int i = 1; i <= length; ++i)
		{
			for (int j = i + 1; j <= length; ++j)
			{
				if (num[i] > num[j]) swap(num[i], num[j]);
			}
		}

		//���Ҫ�������У��򽻻���β
		if (!Greater) { for (int i = 1; i <= length / 2; ++i)swap(num[i], num[length + 1 - i]); }

		return;
	};

};



#endif