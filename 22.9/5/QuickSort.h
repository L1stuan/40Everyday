#ifndef QUICKSORT_H
#define QUICKSORT_H
// from ./22.8.30/SortingArray.h
#include"SortingArray.h"
using std::swap;

template<typename T>
class QuickSort :public SortingMethod<T>
{
public:
	//ģ�常��������������в���ֱ�ӿɼ��ģ�������Ҫ��ʽ�ñ�����Ѱ�Ҹ���
	using SortingMethod<T>::num;
	using SortingMethod<T>::length;
	using SortingMethod<T>::Greater;


	QuickSort() :SortingMethod<T>(){}


	int arrange(int l, int r)
	{
		int pivot = num[r];
		int i = l - 1;
		for (int j = l; j < r; ++j)
		{
			if (num[j] < pivot)
			{
				i++;
				swap(num[i], num[j]);
			}
		}
		swap(num[i + 1], num[r]);
		return (i + 1);
	}

	void Quick_Sort(int l, int r)
	{
		if (l >= r) return;
		int index = arrange(l, r);
		Quick_Sort(l, index - 1);
		Quick_Sort(index + 1, r);
	}


	void sort() override
	{
		Quick_Sort(1, length);

		//���Ҫ�������У��򽻻���β
		if (!Greater) { for (int i = 1; i <= length / 2; ++i)swap(num[i], num[length + 1 - i]); }

		return;
	};

};



#endif