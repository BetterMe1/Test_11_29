/*
date：2018/11/29
author:BetterMe1
program:选择排序、冒泡排序、归并排序、快速排序、插入排序实现;
compiler:Visual Studio 2013
*/
int len = 10;
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>//用到clock()函数
#include<Windows.h>
//交换数组函数;
void swap(int* a, int* b){
	int c = 0;
	c = *a;
	*a = *b;
	*b = c;
}

//选择排序;
//分析：选出一个最值将其与第一个数进行交换，len个数是len-1趟;
void select_sort(int arr[]){
	int begintime, endtime;
	begintime = clock();	//计时开始;
	int min = 0;
	for (int i = 0; i < len - 1; i++){//外层循环控制趟数;
		min = i;//假设第一个数为最小值;
		for (int j = i + 1; j < len; j++){//从下一个数至以后一个数中寻找最值;
			if (arr[min] > arr[j]){ //后面有比最值更小的;
				min = j;     //下标记到min中;
			}
		}
		if (min != i){
			swap(&arr[min], &arr[i]);//交换两数的值，此时将最小的数交换到了第一位;
		}
	}
	endtime = clock();	//计时结束;
	printf("\n\nRunning Time: %d ms\n", endtime - begintime);
}

//冒泡排序;
//分析：每趟比价中进行len-1次的两两比较，第j次比较中进行len-j次的比较，每趟结束后，将最值沉底;
void maopao_sort(int arr[]){
	int begintime, endtime;
	begintime = clock();	//计时开始;
	for (int i = 0; i < len - 1; i++){//外层循环控制趟数;
		for (int j = 0; j < len - i; j++){//第j趟比较len-j次;
			if (arr[j] > arr[j + 1]){  //若下一个小;
				swap(&arr[j], &arr[j + 1]);//交换;
			}
		}
	}
	endtime = clock();	//计时结束;
	printf("\n\nRunning Time: %d ms\n", endtime - begintime);
}
void merge(int arr[], int low, int mid, int high){
	int i, k;
	int *tmp = (int *)malloc((high - low + 1)*sizeof(int));
	//申请空间，使其大小为两个;
	int left_low = low;
	int left_high = mid;
	int right_low = mid + 1;
	int right_high = high;
	for (k = 0; left_low <= left_high && right_low <= right_high; k++){ // 比较两个指针所指向的元素;
		if (arr[left_low] <= arr[right_low]){
			tmp[k] = arr[left_low++];
		}
		else{
			tmp[k] = arr[right_low++];
		}
	}
	if (left_low <= left_high){ //若第一个序列有剩余，直接复制出来粘到合并序列尾;
		for (i = left_low; i <= left_high; i++){
			tmp[k++] = arr[i];
		}
	}
	if (right_low <= right_high){
		//若第二个序列有剩余，直接复制出来粘到合并序列尾;
		for (i = right_low; i <= right_high; i++){
			tmp[k++] = arr[i];
		}
	}
	for (i = 0; i < high - low + 1; i++){
		arr[low + i] = tmp[i];
	}
	free(tmp);
}
//合并排序;
//分析：将待排序序列分为两部分，依次对分得的两个部分再次使用归并排序，之后再对其进行合并;
void merge_sort(int arr[], unsigned int first, unsigned int last){
	int begintime, endtime;
	begintime = clock();	//计时开始;
	int mid = 0;
	if (first < last){
		mid = first/2 + last/2;// 防止溢出 ;
		merge_sort(arr, first, mid);
		merge_sort(arr, mid + 1, last);
		merge(arr, first, mid, last);
	}
	endtime = clock();	//计时结束;
	printf("\n\nRunning Time: %d ms\n", endtime - begintime);
}

//快速排序的作用
//相对于冒泡排序而言，每次交换都是跳跃式的，不像冒泡排序一样只能在相邻的两个数之间进行交换，交换的次数较少，提高了程序的运行速度。在最差的情况下，时间复杂度仍和冒泡排序一样是O(N ^ 2)，但是平均复杂度是O(NlonN);
void quick_sort(int arr[], int begin, int end){
	int begintime, endtime;
	begintime = clock();	//计时开始;
	int i = begin;
	int j = end;
	int x = arr[begin];
	if (begin < end){
		while (begin < end){
			while (begin<end && arr[end]>x){
				end--;
			}
			if (begin < end){
				arr[begin++] = arr[end];
			}
			while (begin < end && arr[begin] < x){
				begin++;
			}
			if (begin < end){
				arr[end--] = arr[begin];
			}
		}
		arr[begin] = x;
		quick_sort(arr, i, end - 1);//用递归将选取的标准数左右两边都进行排序;
		quick_sort(arr, begin + 1, j);
	}
	endtime = clock();	//计时结束;
	printf("\n\nRunning Time: %d ms\n", endtime - begintime);
}



//插入排序;
//分析：将数组的第一个数记为有序序列，其后len-1个数组成无序列，将无序序列中的数依次插入有序序列;
void charu_sort(int arr[]){
	int begintime, endtime;
	begintime = clock();	//计时开始;
	int t = 0;
	int j = 0;
	for (int i = 1; i < len; i++){//从第二个数开始，直至最后一个数;
		t = arr[i];//待插入的数;
		for (j = i - 1; j >= 0 && t < arr[j]; j--){//在有序序列中寻找插入位置;
			arr[j + 1] = arr[j];//还未找到插入位置,当前元素后移，为插入的数准备空间;
		}
		arr[j + 1] = t;//找到插入位置，将元素插入;
	}
	endtime = clock();	//计时结束;
	printf("\n\nRunning Time: %d ms\n", endtime - begintime);
}

int main(){
	//数据规模为10时
	int arr1[] = { 0 };
	/*int arr2[] = { 0 };
	int arr3[] = { 0 };
	int arr4[] = { 0 };
	int arr5[] = { 0 };*/
	int i = 0;
	for (i = 0; i < len; i++){
		arr1[i] = rand();
		/*arr2[i] = arr1[i];
		arr3[i] = arr2[i];
		arr4[i] = arr3[i];
		arr5[i] = arr4[i];*/
	}
	/*for (i = 0; i < len; i++){
		arr2[i] = arr1[i];
	}*/
	for (i = 0; i < len; i++){
		printf("%d\n", arr1[i]);
	}
	/*printf("\n");
	for (i = 0; i < len; i++){
		printf("%d\n", arr2[i]);
	}*/
	select_sort(arr1);//选择排序;
	//maopao_sort(arr2);//冒泡排序;
	//merge_sort(arr3, 0, len - 1);//合并排序;
	//quick_sort(arr4, 0, len - 1);//快速排序;
	//charu_sort(arr5);//插入排序;
	for (i = 0; i < len; i++){
		printf("%d\n", arr1[i]);
		}
	system("pause");
	return 0;
}