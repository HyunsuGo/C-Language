#include <stdio.h>

void print_ary(int* pa);
void print_ary2(int* pa, int size);
void input_ary(double* pa, int size);
double find_max(double* pa, int size);

int main2(void) {
	int ary[5] = { 10, 20, 30, 40, 50 };

	printf("배열명 자체의 값 : %u\n", ary);
	printf("첫 번째 배열 요소의 주소 : %u\n", &ary[0]);
	printf("배열명이 가리키는 요소의 값 : %d\n", *ary);
	printf("첫 번째 배열 요소의 값 : %d\n", ary[0]);

	int ary[3];
	int i;

	*(ary + 0) = 10;
	*(ary + 1) = *(ary + 0) + 10;
	printf("세 번째 배열 요소에 키보드 입력 : ");
	scanf("%d", ary + 2);

	for (i = 0; i < 3; i++) {
		printf("%5d", *(ary + i));
	}

	int ary[3];
	int* pa = ary;
	int i;

	*pa = 10;
	*(pa + 1) = 20;
	pa[2] = pa[0] + pa[1];

	for (i = 0; i < 3; i++) {
		printf("%5d", pa[i]);
	}

	int ary[3] = { 10, 20,30 };
	int* pa = ary;
	int i;

	printf("배열의 값 : ");
	for (i = 0; i < 3; i++) {
		printf("%d ", *pa);
		pa++;
	}

	printf("%d", pa[0]);
	printf("%d", *(pa + 0));
	printf("%d", *pa);

	for (i = 0; i < 3; i++) {
		scanf("%d", pa);
		pa++;
	}

	for (i = 0; i < 3; i++) {
		printf("%d", *(pa++));
	}

	int ary[5] = { 10,20,30,40,50 };
	int* pa = ary;
	int* pb = pa + 3;

	printf("pa : %u\n", pa);
	printf("pb : %u\n", pb);
	pa++;	//포인터 - 포인터 -> 값의차 / 가리키는 자료형의 크기
	printf("pb - pa : %u\b", pb - pa);

	printf("앞에 있는 배열 요소의 값 출력 : ");
	if (pa < pb) printf("%d\n", *pa);
	else printf("%d\n", *pb);

	int ary[5] = { 10,20,30,40,50 };
	print_ary(ary);

	int ary1[5] = { 10,20,30,40,50 };
	int ary2[7] = { 10,20,30,40,50,60,70 };

	print_ary2(ary1, 5);
	printf("\n");
	print_ary2(ary2, 7);
	print_ary2(ary2, sizeof(ary2) / sizeof(ary2[0]));


	double ary[5];
	double max;
	int size = sizeof(ary) / sizeof(ary[0]);

	input_ary(ary, size);
	max = find_max(ary, size);
	printf("배열의 최댓값 : %.1lf\n", max);


	int ch;

	printf("문자 a의 아스키 코드값 : %d\n", 'a');
	printf("아스키 코드값이 97인 문자 : %c\n", 97);
	printf("문자 상수의 크기 : %d바이트\n", sizeof('a'));

	ch = 'a';
	ch++;
	printf("문자 %c의 아스키 코드값 : %d\n", ch, ch);

	ch = 'a';
	while (ch <= 'z') {
		printf("%c", ch);
		ch++;
	}

	char small, cap = 'G';
	if ((cap >= 'A') && (cap <= 'Z')) {
		small = cap + ('a' - 'A');
	}
	printf("대문자 : %c %c", cap, '\n');
	printf("소문자 : %c", small);

	char a;
	a = 'A';
	a = 65;
	a = '\101';
	a = '\x41';
	a = '\0'; //null문자 =='\000'

	char ch1, ch2;

	scanf("%c%c", &ch1, &ch2);
	printf("[%c%c]", ch1, ch2);
	printf("%d, %d", ch1, ch2);

	int ch;
	ch = getchar();	//반환형이 int인 이유는 문자이외의 값도 반환하기 때문
	printf("입력한 문자 : ");	//ex) Ctrl+Z 누르면 -1값 반환
	putchar(ch);				//키보드로만 데이터입력할경우 char도 상관없음
	putchar('\n');				//하지만 입력경로가 파일일경우 문제생김
	//따라서 문자를 반복입력하는경우 반환값을 일단 int에 저장후, -1과 비교 후 char에 옴김
	return 0;
}

void print_ary(int pa[5]) { //매개변수에 선언된 배열은 포인터로 바뀜 (int* pa)
	int i;
	for (i = 0; i < 5; i++) {
		printf("%d ", pa[i]);
	}
}

double find_max(double* pa, int size) {
	double max;
	int i;
	max = pa[0];
	for (int i = 1; i < size; i++) {
		if (pa[i] > max) max = pa[i];
	}
	return max;
}

void input_ary(double* pa, int size) {
	int i;
	
	printf("%d개의 실수값 입략 : ", size);
	for (i = 0; i < size; i++) {
		scanf("%lf", pa + i);
	}
}

void print_ary2(int* pa, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", pa[i]);
	}
}

void print_ary(int* pa) {
	int i;
	for (i = 0; i < 5; i++) {	//포인터에 배열요소 표현식을 사용하면
		printf("%d ", pa[i]);	//배열처럼 사용가능
	}
}

