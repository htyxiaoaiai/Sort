#pragma once

#include<iostream>
#include<assert.h>
#include<stack>


using namespace std;

void InsertSort(int * data, size_t n)
{
	assert(data && n > 0);

	for (size_t i = 0; i < n - 1; i++)
	{
		int tmp = data[i + 1];
		int index = i;
		while (index >= 0 && data[index]>tmp)
		{
			data[index + 1] = data[index];
			index--;
		}
		data[index + 1] = tmp;
	}
}
void Print(int * data, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

void TestInsertSort()
{
	int a[] = { 4,8,3,7,5,3,0,1,10,9 };
	size_t size_a = sizeof(a) / sizeof(a[0]);
	InsertSort(a, size_a);
	Print(a, size_a);
	int b[] = { 10,9,8,7,5,4,3,2,1,0 };
	size_t size_b = sizeof(b) / sizeof(b[0]);
	InsertSort(b, size_b);
	Print(b, size_b);
}

void HillSort(int * data, size_t n)
{
	assert(data);

	int gap = n;
	int end = n;
	while (gap > 1)
	{
		//更新gap
		gap = gap / 3 + 1;
		//插入排序
		for (int i = 0; i < end - gap; i++)
		{
			int index = i;
			int tmp = data[index + gap];
			while (index >= 0 && tmp < data[index])
			{
				data[index + gap] = data[index];
				index -= gap;
			}
			data[index + gap] = tmp;
		}
	}
}

void TestHillSort()
{
	int a[] = { 4,8,3,7,5,3,0,1,10,9 };
	size_t size_a = sizeof(a) / sizeof(a[0]);
	HillSort(a, size_a);
	Print(a, size_a);
	int b[] = { 10,9,8,7,5,4,3,2,1,0 };
	size_t size_b = sizeof(b) / sizeof(b[0]);
	HillSort(b, size_b);
	Print(b, size_b);
}

void SelectSort(int * data, size_t n)
{
	assert(data);
	for (size_t j = n - 1; j > 0; --j)
	{
		size_t end = j;
		//选择一个最大的数据的下标
		int maxIndex = 0;
		for (size_t i = 1; i <= end; ++i)
		{
			if (data[i] > data[maxIndex])
			{
				maxIndex = i;
			}
		}
		swap(data[maxIndex], data[end]);
	}
}



void TestSelectSort()
{
	int a[] = { 4,8,3,7,5,3,0,1,10,9 };
	size_t size_a = sizeof(a) / sizeof(a[0]);
	SelectSort(a, size_a);
	Print(a, size_a);
	int b[] = { 10,9,8,7,5,4,3,2,1,0 };
	size_t size_b = sizeof(b) / sizeof(b[0]);
	SelectSort(b, size_b);
	Print(b, size_b);
}
//
//void SelectSortOP(int * data, size_t n)
//{
//	assert(data);
//	size_t start = 0;
//	size_t end = n - 1;
//	while (start < end)
//	{
//		int maxIndex = start;
//		int minIndex = start;
//		for (size_t i = start + 1; i <= end; ++i)
//		{
//			if (data[i] > data[maxIndex])
//			{
//				maxIndex = i;
//			}
//
//			if (data[i] < data[minIndex])
//			{
//				minIndex = i;
//			}
//		}
//		if (start == maxIndex)
//		{
//			minIndex = maxIndex;
//		}
//		swap(data[minIndex], data[start]);
//		swap(data[maxIndex], data[end]);
//		start++;
//		end--;
//	}
//}


//void TestSelectSortOP()
//{
//	int a[] = { 9,8,3,7,5,3,0,1,10,4 };
//	size_t size_a = sizeof(a) / sizeof(a[0]);
//	SelectSortOP(a, size_a);
//	Print(a, size_a);
//	int b[] = { 10,9,8,7,6,5,4,3,2,1,0 };
//	size_t size_b = sizeof(b) / sizeof(b[0]);
//	SelectSortOP(b, size_b);
//	Print(b, size_b);
//}

void AdjustDown(int *data, size_t n, size_t parent)
{
	assert(data);

	size_t child = parent * 2 + 1;
	while (child < n)
	{
		//挑选左右孩子中较大的
		if (child + 1 < n&&data[child + 1] > data[child])
		{
			child++;
		}

		//与父亲节点比较
		if (data[child]>data[parent])
		{
			swap(data[child], data[parent]);
			//继续调整孩子为堆
			parent = child;
			child = parent * 2 + 1;
		}
		//本身为大堆不需要调整
		else
		{
			break;
		}
	}
}
void HeapSort(int *data, size_t n)
{
	assert(data);
	//建堆
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(data, n, i);
	}

	//排序
	for (int i = n - 1; i > 0; i--)
	{
		swap(data[0], data[i]);
		AdjustDown(data, i, 0);
	}
}

void TestHeapSort()
{
	int a[] = { 4,8,3,7,5,3,0,1,10,9 };
	size_t size_a = sizeof(a) / sizeof(a[0]);
	HeapSort(a, size_a);
	Print(a, size_a);
	int b[] = { 10,9,8,7,5,4,3,2,1,0 };
	size_t size_b = sizeof(b) / sizeof(b[0]);
	HeapSort(b, size_b);
	Print(b, size_b);
}

void BubbleSort(int *data, size_t n)
{
	assert(data);
	//优化
	bool change = false;
	//冒泡的轮数
	for (size_t i = 1; i < n; i++)
	{
		//单次冒泡排序，将最大的冒到最后边
		size_t end = n - i;
		for (size_t j = 1; j <= end; j++)
		{
			if (data[j - 1] > data[j])
			{
				swap(data[j - 1], data[j]);
				change = true;
			}
		}
		//有序的序列，直接跳出
		if (!change)
		{
			break;
		}
	}
}

void TestBubbleSort()
{
	int a[] = { 4,8,3,7,5,3,0,1,10,9,6 };
	size_t size_a = sizeof(a) / sizeof(a[0]);
	BubbleSort(a, size_a);
	Print(a, size_a);
	int b[] = { 10,9,8,7,6,5,4,3,2,1,0 };
	size_t size_b = sizeof(b) / sizeof(b[0]);
	BubbleSort(b, size_b);
	Print(b, size_b);
	int c[] = { 0,1,2,3,4,5,6,7,8,9,10 };
	size_t size_c = sizeof(c) / sizeof(c[0]);
	BubbleSort(c, size_c);
	Print(c, size_c);
}

int GetMidNum(int *data, int left, int right)
{
	assert(data);
	int mid = (right + left) / 2;
	if (data[left] > data[right])
	{
		if (data[right] > data[mid])
		{
			return right;
		}
		else if (data[mid] < data[left])
		{
			return mid;
		}
		else
		{
			return left;
		}
	}
	else
	{
		if (data[left] > data[mid])
		{
			return left;
		}
		else if (data[mid] < data[right])
		{
			return mid;
		}
		else
		{
			return right;
		}
	}
}

////单趟快排
//int PartSort(int *data, int left, int right)
//{
//	//栈溢出，为什么？
//	/*int mid = GetMidNum(data, left, right);
//	swap(data[mid], data[right]);*/
//
//	int key = right;
//	while (left < right)
//	{
//		//找到比key大的
//		while (left < right && data[left] <= data[key])
//		{
//			left++;
//		}
//		//找到比key小的
//		while (right > left && data[right] >= data[key])
//		{
//			right--;
//		}
//
//		//交换
//		if (left < right)
//		{
//			swap(data[left], data[right]);
//			left++;
//			right--;
//		}
//	}
//
//	swap(data[left], data[key]);
//	return left;
//}
//
//void QuickSort(int *data, int left, int right)
//{
//	assert(data);
//	//不能改成等于 ，因为可能只剩一个元素的时候，right小于0；
//	//left， right最好使用int类型的，尽量不使用size_t 坑太多
//	if (left >= right)
//	{
//		return;
//	}
//
//	int mid = PartSort(data, 0, right);
//	QuickSort(data, 0, mid - 1);
//	QuickSort(data, mid + 1, right);
//}
//
//
//void TestQuickSort()
//{
//	int a[] = { 4,8,3,7,5,3,0,1,10,9,6 };
//	size_t size_a = sizeof(a) / sizeof(a[0]);
//	QuickSort(a, 0, size_a - 1);
//	Print(a, size_a);
//	int b[] = { 10,9,8,7,6,5,4,3,2,1,0 };
//	size_t size_b = sizeof(b) / sizeof(b[0]);
//	QuickSort(b, 0, size_b - 1);
//	Print(b, size_b);
//	int c[] = { 0,1,2,3,4,5,6,7,8,9,10 };
//	size_t size_c = sizeof(c) / sizeof(c[0]);
//	QuickSort(c, 0, size_c - 1);
//	Print(c, size_c);
//}

////挖坑法实现快速排序
////单趟快排
//int PartSort(int *data, int left, int right)
//{
//	//int mid = GetMidNum(data, left, right);
//	//swap(data[mid], data[right]);
//
//	int key = data[right];
//	while (left < right)
//	{
//		//找到比key大的
//		while (left < right && data[left] <= key)
//			left++;
//
//		if (left < right)
//			data[right] = data[left];
//
//		while (left < right&&data[right] >= key)
//			right--;
//
//		if (left < right)
//			data[left] = data[right];
//	}
//	data[left] = key;
//	return left;
//}
//
//void QuickSort(int *data, int left, int right)
//{
//	assert(data);
//	//不能改成等于 ，因为可能只剩一个元素的时候，right小于0；
//	//left， right最好使用int类型的，尽量不使用size_t 坑太多
//	if (left >= right)
//	{
//		return;
//	}
//
//	int mid = PartSort(data, 0, right);
//	QuickSort(data, 0, mid - 1);
//	QuickSort(data, mid + 1, right);
//}
//
//
//void TestQuickSort()
//{
//	int a[] = { 4,8,3,7,5,3,0,1,10,9,6 };
//	size_t size_a = sizeof(a) / sizeof(a[0]);
//	QuickSort(a, 0, size_a - 1);
//	Print(a, size_a);
//	int b[] = { 10,9,8,7,6,5,4,3,2,1,0 };
//	size_t size_b = sizeof(b) / sizeof(b[0]);
//	QuickSort(b, 0, size_b - 1);
//	Print(b, size_b);
//	int c[] = { 0,1,2,3,4,5,6,7,8,9,10 };
//	size_t size_c = sizeof(c) / sizeof(c[0]);
//	QuickSort(c, 0, size_c - 1);
//	Print(c, size_c);
//}





////单趟快排
//int PartSort(int *data, int left, int right)
//{
//	//int mid = GetMidNum(data, left, right);
//	//swap(data[mid], data[right]);
//	int prev = left - 1;
//	int cur = left;
//	int key = data[right];
//
//	while (cur < right)
//	{
//		if (data[cur] < key && ++prev != cur)
//			swap(data[cur], data[prev]);
//
//		++cur;
//	}
//	swap(data[++prev], data[right]);
//	return prev;
//}
//
//void QuickSort(int *data, int left, int right)
//{
//	assert(data);
//	//不能改成等于 ，因为可能只剩一个元素的时候，right小于0；
//	//left， right最好使用int类型的，尽量不使用size_t 坑太多
//	if (left >= right)
//	{
//		return;
//	}
//
//	int mid = PartSort(data, 0, right);
//	QuickSort(data, 0, mid - 1);
//	QuickSort(data, mid + 1, right);
//}
//
//
//void TestQuickSort()
//{
//	int a[] = { 4,8,3,7,5,3,0,1,10,9,6 };
//	size_t size_a = sizeof(a) / sizeof(a[0]);
//	QuickSort(a, 0, size_a - 1);
//	Print(a, size_a);
//	int b[] = { 10,9,8,7,6,5,4,3,2,1,0 };
//	size_t size_b = sizeof(b) / sizeof(b[0]);
//	QuickSort(b, 0, size_b - 1);
//	Print(b, size_b);
//	int c[] = { 0,1,2,3,4,5,6,7,8,9,10 };
//	size_t size_c = sizeof(c) / sizeof(c[0]);
//	QuickSort(c, 0, size_c - 1);
//	Print(c, size_c);
//}



//非递归排序
//单趟快排
int PartSort(int *data, int left, int right)
{
	//int mid = GetMidNum(data, left, right);
	//swap(data[mid], data[right]);
	int prev = left - 1;
	int cur = left;
	int key = data[right];

	while (cur < right)
	{
		if (data[cur] < key && ++prev != cur)
			swap(data[cur], data[prev]);

		++cur;
	}
	swap(data[++prev], data[right]);
	return prev;
}

void QuickSort(int *data, int left, int right)
{
	assert(data);
	//不能改成等于 ，因为可能只剩一个元素的时候，right小于0；
	//left， right最好使用int类型的，尽量不使用size_t 坑太多
	if (left >= right)
	{
		return;
	}

	stack<int>s;
	s.push(right);
	s.push(left);
	while (!s.empty())
	{
		int begin = s.top();
		s.pop();
		int end = s.top();
		s.pop();
		//begin<end
		if (begin < end)
		{
			int mid = PartSort(data, begin, end);
			s.push(mid - 1);
			s.push(begin);
			s.push(end);
			s.push(mid + 1);
		}
	}
}


void TestQuickSort()
{
	int a[] = { 4,8,3,7,5,3,0,1,10,9,6 };
	size_t size_a = sizeof(a) / sizeof(a[0]);
	QuickSort(a, 0, size_a - 1);
	Print(a, size_a);
	int b[] = { 10,9,8,7,6,5,4,3,2,1,0 };
	size_t size_b = sizeof(b) / sizeof(b[0]);
	QuickSort(b, 0, size_b - 1);
	Print(b, size_b);
	int c[] = { 0,1,2,3,4,5,6,7,8,9,10 };
	size_t size_c = sizeof(c) / sizeof(c[0]);
	QuickSort(c, 0, size_c - 1);
	Print(c, size_c);
}


//归并排序
//合并数组
void _Merge(int*data, int *tmp, int left, int mid, int right)
{
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;

	int index = begin1;
	while (begin1 <= end1&&begin2 <= end2)
	{
		if (data[begin1] > data[begin2])
		{
			tmp[index++] = data[begin2++];
		}
		else
		{
			tmp[index++] = data[begin1++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[index++] = data[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = data[begin2++];
	}
	for (int i = left; i <= right; i++)
	{
		data[i] = tmp[i];
	}
}
void _MergeSort(int* data, int* tmp, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) / 2;
	//拆分成两个有序的序列
	_MergeSort(data, tmp, left, mid);
	_MergeSort(data, tmp, mid + 1, right);
	//合并
	_Merge(data, tmp, left, mid, right);
}

void MergeSort(int *data, size_t n)
{
	int *tmp = new int[n];
	memcpy(tmp, data, sizeof(int)*n);
	_MergeSort(data, tmp, 0, n - 1);
}

void TestMergeSort()
{
	int a[] = { 4,8,3,7,5,3,0,1,10,9,6 };
	size_t size_a = sizeof(a) / sizeof(a[0]);
	MergeSort(a, size_a);
	Print(a, size_a);
	int b[] = { 10,9,8,7,6,5,4,3,2,1,0 };
	size_t size_b = sizeof(b) / sizeof(b[0]);
	MergeSort(b, size_b);
	Print(b, size_b);
	int c[] = { 0,1,2,3,4,5,6,7,8,9,10 };
	size_t size_c = sizeof(c) / sizeof(c[0]);
	MergeSort(c, size_c);
	Print(c, size_c);
}

//基数排序
int MaxDig(int *data, size_t n)
{
	int max = 10;
	int digit = 1;
	for (int i = 0; i < n; i++)
	{
		while (data[i] >= max)
		{
			digit++;
			max *= 10;
		}
	}
	return digit;
}

void RadixSort(int*data, size_t n)
{
	int *Bucket = new int[n];
	int *start = new int[10];
	int *count = new int[10];
	int digit = MaxDig(data, n);
	for (int d = 1; d <= digit; d++)
	{
		start[0] = 0;
		memset(count, 0, sizeof(int)*n);

		for (int i = 0; i < n; i++)
		{
			int temp = data[i] / (pow(10, d - 1));
			int index = temp % 10;
			count[index]++;
		}
		for (int i = 1; i < n; i++)
		{
			start[i] = start[i - 1] + count[i - 1];
		}

		for (int i = 0; i < n; i++)
		{
			int temp = data[i] / (pow(10, d - 1));
			int index = temp % 10;
			Bucket[start[index]] = data[i];
			start[index]++;
		}
		memcpy(data, Bucket, n*sizeof(int));
	}
}

void TestRadixSort()
{
	int a[] = { 4,8,3,7,5,3,0,1,10,9,6 };
	size_t size_a = sizeof(a) / sizeof(a[0]);
	RadixSort(a, size_a);
	Print(a, size_a);
	int b[] = { 10,9,8,7,6,5,4,3,2,1,0 };
	size_t size_b = sizeof(b) / sizeof(b[0]);
	RadixSort(b, size_b);
	Print(b, size_b);
	int c[] = { 0,1,2,3,4,5,6,7,8,9,10 };
	size_t size_c = sizeof(c) / sizeof(c[0]);
	RadixSort(c, size_c);
	Print(c, size_c);
}