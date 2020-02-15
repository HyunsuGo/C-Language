#include <stdio.h>
#include <stdlib.h> //malloc, free 함수 사용을 위한 헤더 파일
#include <string.h>

void print_str(char** ps);
void print_str2(char**);

int main(int argc, char **argv) {
	int* pi;
	double* pd;

	pi = (int*)malloc(sizeof(int));
	if (pi == NULL) {
		printf("#으로 메모리가 부족합니다.\n");
		exit(1);
	}
	pd = (double*)malloc(sizeof(double));
	//malloc 함수는(void*)형을 반환하므로 용도에 맞는 포인터형으로 형변환하여 사용

	*pi = 10;
	*pd = 3.4;

	printf("정수형으로 사용 : %d\n", *pi);
	printf("실수형으로 사용 : %lf\n", *pd);

	free(pi);
	free(pd);


	int* pi;
	int i, sum = 0;

	pi = (int*)malloc(5 * sizeof(int));
	if (pi == NULL) {
		printf("메모리가 부족합니다!\n");
		exit(1);
	}
	printf("다섯 명의 나이를 입력하세요 : ");
	for (i = 0; i < 5; i++) {
		scanf("%d", &pi[i]);
		sum += pi[i];
	}
	printf("다섯 명의 평균 나이 : %.1lf\n", (sum / 5.0));
	free(pi);


	int* pi;
	int size = 5;
	int cnt = 0;
	int num;
	int i;
	//calloc 함수는 할당한 저장 공간을 모두 0으로 초기화하므로 0으로 초기화가 필요한 경우 편리함
	pi = (int*)calloc(size, sizeof(int));

	while (1) {
		printf("양수를 입력하세요 => ");
		scanf("%d", &num);
		if (num <= 0) break;
		if (cnt == size) {
			size += 5;	//realloc 함수는 이미 할당한 저장 공간의 포인터와 조정할 저장 공간의 전체 크기를 줌
			pi = (int*)realloc(pi, size * sizeof(int));
		}
		pi[cnt++] = num;
	}
	for (i = 0; i < cnt; i++) {
		printf("%5d", pi[i]);
	}
	free(pi);


	char temp[80];
	char* str[3];
	int i;

	for (int i = 0; i < 3; i++) {
		printf("문자열을 입력하세요 : ");
		gets(temp);
		str[i] = (char*)malloc(strlen(temp) + 1); //strlen함수는 널문자를 제외하고 길이계산 하므로 +1해줌
		strcpy(str[i], temp);
	}

	for (i = 0; i < 3; i++) {
		printf("%s\n", str[i]);
	}

	for (i = 0; i < 3; i++) {
		free(str[i]);
	}


	char temp[80];
	char* str[21] = { 0 };
	int i = 0;

	while (i < 20) {
		printf("문자열을 입력하세요 : ");
		gets(temp);
		if (strcmp(temp, "end") == 0) break;
		str[i] = (char*)malloc(strlen(temp) + 1);
		strcpy(str[i], temp);
		i++;
	}
	print_str(str);

	for (i = 0; str[i] != NULL; i++) {
		free(str[i]);
	}
	

	int i;

	for (i = 0; i < argc; i++) {
		printf("%s\n", argv[i]);
	}


	while (*argv != NULL) {
		printf("%s\n", *argv);
		argv++;
	}

	
	char temp[80];
	char** str;
	int max;
	int i;

	max = atoi(argv[1]);
	str = (char**)malloc((max + 1) * sizeof(char*));
	i = 0;

	while (1) {
		printf("문자열을 입력하세요 : ");
		gets(temp);
		if (temp[0] == '\0') break;

		str[i] = (char*)malloc(strlen(temp) + 1);
		strcpy(str[i], temp);
		i++;
		if (i == max) {
			printf("문자열 입력이 최댓값을 모두 채웠습니다.\n");
			break;
		}
	}
	str[i] = 0;
	print_str2(str);

	i = 0;
	while (str[i] != 0) {
		free(str[i]);
		i++;
	}
	free(str);
	
	
	
	return 0;

}

void print_str2(char** ps) {
	while (*ps != 0) {
		printf("%s\n", *ps);
		ps++;
	}
}

void print_str(char** ps) {
	while (*ps != NULL) {
		printf("%s\n", *ps);
		ps++;
	}
}