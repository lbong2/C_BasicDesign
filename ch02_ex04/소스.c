#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning (disable : 4996)
/*
포인터 변수 접근, 연산, 출력
*/
void main() {
	int arr[100];
	int* ptr_arr;
	int fi;

	srand((unsigned)time(NULL));				// random num 생성

	ptr_arr = &arr[0];							// 포인터에 배열의 첫번째칸 주소 저장
	printf("address of arr[0] is %p\n", &arr[0]);	// arr[0]의 주소 출력
	printf("arr is pointing %p\n", arr);			// arr의 주소 출력 (arr[0]과 동일)
	printf("ptr_arr is pointing %p\n\n", ptr_arr);	// ptr_arr의 주소 출력 (&arr[0]으로 초기화 했음)
	
	printf("address of arr[1] is %p\n", &arr[1]);	// arr[1]의 주소 출력(arr[0]주소에 4 더한값)
	printf("arr + 1 is pointing %p\n", arr + 1);	// arr[1] 과 동일 (arr + 1 = &arr[1])
	printf("ptr_arr + 1 is pointing %p\n\n", ptr_arr + 1);	//arr[1] 과 동일

	for (fi = 0; fi < 100; fi++) {
		arr[fi] = rand() % 101;		// 0 ~ 100의 숫자로 초기화  
	}

	printf("arr[0] = %d\n", arr[0]);	// arr[0]의 값 출력
	printf("*arr = %d\n", *arr);		// arr[0]의 값과 같은 값이 출력됨(arr[0]의 주소를 저장 -> 그 주소값 내부의 값을 출력하기 때문)
	printf("*ptr_arr = %d\n\n", *ptr_arr); // 동일하게 출력

	printf("arr[20] = %d\n", arr[20]);	// arr[20] 값 출력
	printf("*(arr + 20) = %d\n", *(arr + 20));	// arr[20]과 같은 값 출력
	printf("*(ptr_arr + 20) = %d\n\n", *(ptr_arr + 20));	// 동일하게 출력
	printf("*arr + 20 = %d\n", *arr + 20);		// *arr = arr[0] 의 값 에다가 20을 더한 값 출력
	printf("*ptr_arr + 20 = %d\n", *ptr_arr + 20);	// 동일하게 출력
}