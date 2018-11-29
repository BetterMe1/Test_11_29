/*
date��2018/11/29
author:BetterMe1
program:ѡ������ð�����򡢹鲢���򡢿������򡢲�������ʵ��;
compiler:Visual Studio 2013
*/
int len = 10;
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>//�õ�clock()����
#include<Windows.h>
//�������麯��;
void swap(int* a, int* b){
	int c = 0;
	c = *a;
	*a = *b;
	*b = c;
}

//ѡ������;
//������ѡ��һ����ֵ�������һ�������н�����len������len-1��;
void select_sort(int arr[]){
	int begintime, endtime;
	begintime = clock();	//��ʱ��ʼ;
	int min = 0;
	for (int i = 0; i < len - 1; i++){//���ѭ����������;
		min = i;//�����һ����Ϊ��Сֵ;
		for (int j = i + 1; j < len; j++){//����һ�������Ժ�һ������Ѱ����ֵ;
			if (arr[min] > arr[j]){ //�����б���ֵ��С��;
				min = j;     //�±�ǵ�min��;
			}
		}
		if (min != i){
			swap(&arr[min], &arr[i]);//����������ֵ����ʱ����С�����������˵�һλ;
		}
	}
	endtime = clock();	//��ʱ����;
	printf("\n\nRunning Time: %d ms\n", endtime - begintime);
}

//ð������;
//������ÿ�˱ȼ��н���len-1�ε������Ƚϣ���j�αȽ��н���len-j�εıȽϣ�ÿ�˽����󣬽���ֵ����;
void maopao_sort(int arr[]){
	int begintime, endtime;
	begintime = clock();	//��ʱ��ʼ;
	for (int i = 0; i < len - 1; i++){//���ѭ����������;
		for (int j = 0; j < len - i; j++){//��j�˱Ƚ�len-j��;
			if (arr[j] > arr[j + 1]){  //����һ��С;
				swap(&arr[j], &arr[j + 1]);//����;
			}
		}
	}
	endtime = clock();	//��ʱ����;
	printf("\n\nRunning Time: %d ms\n", endtime - begintime);
}
void merge(int arr[], int low, int mid, int high){
	int i, k;
	int *tmp = (int *)malloc((high - low + 1)*sizeof(int));
	//����ռ䣬ʹ���СΪ����;
	int left_low = low;
	int left_high = mid;
	int right_low = mid + 1;
	int right_high = high;
	for (k = 0; left_low <= left_high && right_low <= right_high; k++){ // �Ƚ�����ָ����ָ���Ԫ��;
		if (arr[left_low] <= arr[right_low]){
			tmp[k] = arr[left_low++];
		}
		else{
			tmp[k] = arr[right_low++];
		}
	}
	if (left_low <= left_high){ //����һ��������ʣ�ֱ࣬�Ӹ��Ƴ���ճ���ϲ�����β;
		for (i = left_low; i <= left_high; i++){
			tmp[k++] = arr[i];
		}
	}
	if (right_low <= right_high){
		//���ڶ���������ʣ�ֱ࣬�Ӹ��Ƴ���ճ���ϲ�����β;
		for (i = right_low; i <= right_high; i++){
			tmp[k++] = arr[i];
		}
	}
	for (i = 0; i < high - low + 1; i++){
		arr[low + i] = tmp[i];
	}
	free(tmp);
}
//�ϲ�����;
//�����������������з�Ϊ�����֣����ζԷֵõ����������ٴ�ʹ�ù鲢����֮���ٶ�����кϲ�;
void merge_sort(int arr[], unsigned int first, unsigned int last){
	int begintime, endtime;
	begintime = clock();	//��ʱ��ʼ;
	int mid = 0;
	if (first < last){
		mid = first/2 + last/2;// ��ֹ��� ;
		merge_sort(arr, first, mid);
		merge_sort(arr, mid + 1, last);
		merge(arr, first, mid, last);
	}
	endtime = clock();	//��ʱ����;
	printf("\n\nRunning Time: %d ms\n", endtime - begintime);
}

//�������������
//�����ð��������ԣ�ÿ�ν���������Ծʽ�ģ�����ð������һ��ֻ�������ڵ�������֮����н����������Ĵ������٣�����˳���������ٶȡ�����������£�ʱ�临�Ӷ��Ժ�ð������һ����O(N ^ 2)������ƽ�����Ӷ���O(NlonN);
void quick_sort(int arr[], int begin, int end){
	int begintime, endtime;
	begintime = clock();	//��ʱ��ʼ;
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
		quick_sort(arr, i, end - 1);//�õݹ齫ѡȡ�ı�׼���������߶���������;
		quick_sort(arr, begin + 1, j);
	}
	endtime = clock();	//��ʱ����;
	printf("\n\nRunning Time: %d ms\n", endtime - begintime);
}



//��������;
//������������ĵ�һ������Ϊ�������У����len-1������������У������������е������β�����������;
void charu_sort(int arr[]){
	int begintime, endtime;
	begintime = clock();	//��ʱ��ʼ;
	int t = 0;
	int j = 0;
	for (int i = 1; i < len; i++){//�ӵڶ�������ʼ��ֱ�����һ����;
		t = arr[i];//���������;
		for (j = i - 1; j >= 0 && t < arr[j]; j--){//������������Ѱ�Ҳ���λ��;
			arr[j + 1] = arr[j];//��δ�ҵ�����λ��,��ǰԪ�غ��ƣ�Ϊ�������׼���ռ�;
		}
		arr[j + 1] = t;//�ҵ�����λ�ã���Ԫ�ز���;
	}
	endtime = clock();	//��ʱ����;
	printf("\n\nRunning Time: %d ms\n", endtime - begintime);
}

int main(){
	//���ݹ�ģΪ10ʱ
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
	select_sort(arr1);//ѡ������;
	//maopao_sort(arr2);//ð������;
	//merge_sort(arr3, 0, len - 1);//�ϲ�����;
	//quick_sort(arr4, 0, len - 1);//��������;
	//charu_sort(arr5);//��������;
	for (i = 0; i < len; i++){
		printf("%d\n", arr1[i]);
		}
	system("pause");
	return 0;
}