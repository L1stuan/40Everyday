#ifndef SHELLSORT_H
#define SHELLSORT_H
// from ./22.8.30/SortingArray.h
#include"SortingArray.h"
using std::swap;

template<typename T>
class ShellSort :public SortingMethod<T>
{
public:
	//ģ�常��������������в���ֱ�ӿɼ��ģ�������Ҫ��ʽ�ñ�����Ѱ�Ҹ���
	using SortingMethod<T>::num;
	using SortingMethod<T>::length;
	using SortingMethod<T>::Greater;


	ShellSort() :SortingMethod<T>(){}

	void sort() override
	{
		for (int gap = length / 2; gap > 0; gap /= 2)	//��һ��for����ö�پ���gap
			for (int i = gap + 1; i <= length; ++i)		//�ڶ���for����ö���������λ��
			{
				int j = i;
				for (; j > gap && num[j] < num[j - gap]; j -= gap)	//��num[i]�ƶ������ʵ�λ��
				{													//��gap=1ʱ���˻�Ϊ��������
					swap(num[j], num[j - gap]);
				}

			}

		//���Ҫ�������У��򽻻���β
		if (!Greater) { for (int i = 1; i <= length / 2; ++i)swap(num[i], num[length + 1 - i]); }

		return;
	};

};



#endif