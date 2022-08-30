#ifndef SortingArray_H
#define SortingArray_H

#include<iostream>
using std::cerr;
using std::string;

//ִ������������
template<typename T>
class SortingMethod
{
public:
	//���캯��
	SortingMethod():num(nullptr),length(0),Greater(0) {}

	//���ڳ�ʼ���������������Ӧ��SortingArray�󶨡��󶨺�numָ����������SortingArray�е�data��length����data�ĳ���
	void setData(T* a, int b) { num = a, length = b; }
	
	void setGreater(bool isGreater) { Greater = isGreater; }


	//�����ڵ��ԣ����ڻ��num�������λ��
	T* _getDataLoc() { return num; }
	
	//�����ڵ��ԣ����ڻ��num����ĳ���
	int _getLength() { return length; }


	//�麯��sort�������಻ͬ�������,ִ��SortingMethod�����Ҫ�߼�
	virtual void sort() {};

	
protected:
	//ָ����֮��Ӧ��SortingArray��data����ĵ�ַ��SortingMethod�����ͨ��numָ���޸�SortingArray.data��ֵ
	T* num;
	int length;
	bool Greater;
};

//���ڴ�����Ҫ�����ֵ,ͨ����һ��SortingMethodʵ��������,�±��1��ʼ
template<typename T>
class SortingArray
{
public:
	SortingArray() = delete;

	//��һ����������鸴�Ƶ�SortingArray�У��������±��1��ʼ����n����
	SortingArray(const T const* a, const int& n):_method(nullptr)
	{
		length = n;
		data = new T[n];
		for (int i = 1; i <= n; ++i) { data[i] = a[i]; }
		methodSet = 0;
	}

	~SortingArray() { delete[] data; }

	//�ú������ڰ�һ��SortingMethod������Ҫ�󶨵�SortingMethod������ʽ��Ĭ�ϵ�����,sm�����data�ĵ�ַ����ͨ�������ֱַ�ӷ���/�޸�data
	void setMethod(SortingMethod<T>* sm, bool isGreater = 1) { if (!sm) { cerr << "Not legal"; return; } _method = sm; _method->setData(data, length); methodSet = 1; _method->setGreater(isGreater); }

	//ִ��sorting
	void sorting()
	{
		if (!methodSet) { cerr << "MethodNotSet"; return; }
		_method->sort();
	}

	//debug use only
	void _show() const
	{
		std::cout << length << std::endl;
		for (int i = 1; i <= length; ++i) std::cout << data[i] << " ";
	}
	bool _getMethodSet()const { return methodSet; }
	void _getSortingMethodType()const
	{
		std::cout << typeid(*_method).name();
	}
	T* getData()const { return data; }
	SortingMethod<T>* _getSortingMethod() { return _method; }

private:
	T* data;
	int length;
	SortingMethod<T>* _method;
	bool methodSet;//1 if the sorting method is set.
	
};



#endif // !SortingArray
