#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning (disable : 4996)
/*
������ ���� ����, ����, ���
*/
void main() {
	int arr[100];
	int* ptr_arr;
	int fi;

	srand((unsigned)time(NULL));				// random num ����

	ptr_arr = &arr[0];							// �����Ϳ� �迭�� ù��°ĭ �ּ� ����
	printf("address of arr[0] is %p\n", &arr[0]);	// arr[0]�� �ּ� ���
	printf("arr is pointing %p\n", arr);			// arr�� �ּ� ��� (arr[0]�� ����)
	printf("ptr_arr is pointing %p\n\n", ptr_arr);	// ptr_arr�� �ּ� ��� (&arr[0]���� �ʱ�ȭ ����)
	
	printf("address of arr[1] is %p\n", &arr[1]);	// arr[1]�� �ּ� ���(arr[0]�ּҿ� 4 ���Ѱ�)
	printf("arr + 1 is pointing %p\n", arr + 1);	// arr[1] �� ���� (arr + 1 = &arr[1])
	printf("ptr_arr + 1 is pointing %p\n\n", ptr_arr + 1);	//arr[1] �� ����

	for (fi = 0; fi < 100; fi++) {
		arr[fi] = rand() % 101;		// 0 ~ 100�� ���ڷ� �ʱ�ȭ  
	}

	printf("arr[0] = %d\n", arr[0]);	// arr[0]�� �� ���
	printf("*arr = %d\n", *arr);		// arr[0]�� ���� ���� ���� ��µ�(arr[0]�� �ּҸ� ���� -> �� �ּҰ� ������ ���� ����ϱ� ����)
	printf("*ptr_arr = %d\n\n", *ptr_arr); // �����ϰ� ���

	printf("arr[20] = %d\n", arr[20]);	// arr[20] �� ���
	printf("*(arr + 20) = %d\n", *(arr + 20));	// arr[20]�� ���� �� ���
	printf("*(ptr_arr + 20) = %d\n\n", *(ptr_arr + 20));	// �����ϰ� ���
	printf("*arr + 20 = %d\n", *arr + 20);		// *arr = arr[0] �� �� ���ٰ� 20�� ���� �� ���
	printf("*ptr_arr + 20 = %d\n", *ptr_arr + 20);	// �����ϰ� ���
}