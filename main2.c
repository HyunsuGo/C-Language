#include <stdio.h>
#include <string.h>

#define MSG "Be happy!" //문자열 "Be happy!"를 이후부터 MSG 이름으로 사용


void print_ary(int* pa);
void print_ary2(int* pa, int size);
void input_ary(double* pa, int size);
double find_max(double* pa, int size);
void m_gets(char* str, int size);
char* my_strcpy(char* pd, char* ps);
int my_strlen(char* ps);
char* my_strcat(char* pd, char* ps);
void assign(void);
void assign10(void);
void assign20(void);
void auto_func(void);
void static_func(void);
void add_ten(int a);
void add_ten(int* p);
int* sum1(int a, int b);

int a; //전역변수는 특별한 값으로 초기화하지 않아도 0으로 자동 초기화됨

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
	
	char ch;
	int i;

	for (i = 0;i < 3;i++) {
		scanf("%c", &ch);
		printf("%c", ch);
	}

	int res;
	char ch;

	while (1) {
		res = scanf("%c", &ch); //ctrl+Z(D) 누르면 -1반환
		if (res == -1) break;	//기본적으로 입력한 값의 개수를 반환함
		printf("%d", ch);
	}
	while (1) {
		res = scanf("%c", &ch);
		if (res == EOF) break; //-1대신 EOF 사용가능
	}
	
	char str[7];

	my_gets(str, sizeof(str));
	printf("입력한 문자열 : %s\n", str);

	int num, grade;
	printf("학번 입력 : ");
	scanf("%d", &num);
	fflush(stdin);
	printf("학점 입력 : ");
	grade = getchar();
	printf("학번 : %d, 학점 : %c", num, grade);

	int ch;
	ch = fgetc(stdin); //getchar()
	fputc(ch, stdout); //putcgar()

	printf("주소값 : %p\n", "mango");
	printf("첫 번째 문자 : %c\n", *"mango");
	printf("두 번째 문자 : %c\n", *("mango" + 1));
	printf("세 번째 문자 : %c\n", "mango"[2]);

	
	char* dessert = "apple";
	printf("오늘 후식은 %s입니다.\n", dessert);
	dessert = "banana";
	printf("내일 후식은 %s입니다.\n", dessert);

	char* pa = "apple";
	char* pb = "apple";
	printf("%p, %p", pa, pb);


	char str[80];

	printf("문자열 입력 : ");
	scanf("%s", str);
	printf("첫 번째 단어 : %s\n", str);
	scanf("%s", str);
	printf("버퍼에 남아 있는 두 번째 단어 : %s\n", str);

	char str[80];
	printf("공백이 포함된 문자열 입력 : ");
	gets(str);
	printf("입력한 문자열은 %s입니다.", str);


	char str[80];
	printf("공백이 포함된 문자열 입력 : ");
	fgets(str, sizeof(str), stdin);
	printf("입력된 문자열은 %s입니다\n", str);
	//fgets( , , )는 개행문자도 입력됨 따라서 개행문자를 지워주기 위해
	str[strlen(str) - 1] = '\0'; //으로 '\n'이 저장된위치에 null삽입


	int age;
	char name[20];

	printf("나이 입력 : ");
	scanf("%d", &age);
	printf("이름 입력 : ");
	gets(name);
	printf("나이 : %d, 이름 : %s\n", age, name);

	getchar();		//버퍼에서 하나의 문자를 읽어서 반환, 반환문자는 버림
	scanf("%*c");	//버퍼에서 하나의 문자를 읽어서 버림, 변수는 필요 없음
	fgetsc(stdin);	//버퍼에서 하나의 문자를 읽어서 반환, 반환 문자는 버림


	char str[80] = "apple juice";
	char* ps = "banana";

	puts(str);		//str배열에 저장된 문자열을 출력하고 자동으로 줄 바꿈
	fputs(ps, stdout);	//str배열에 저장된 문자열을 출력하고 줄 안바꿈
	puts("milk");


	char str1[80] = "strawberry";
	char str2[80] = "apple";
	char* ps1 = "banana";
	char* ps2 = str2;

	printf("최초 문자열 : %s\n", str1);
	strcpy(str1, str2);
	printf("바뀐 문자열 : %s\n", str1);

	strcpy(str1, ps1);
	printf("바뀐 문자열 : %s\n", str1);

	strcpy(str1, ps2);
	printf("바뀐 문자열 : %s\n", str1);

	strcpy(str1, "banana");
	printf("바뀐 문자열 : %s\n", str1);

	strcpy("banana", "apple");	//이렇게하면 안됨
	strcpy(ps1, "apple");		//이렇게하면 안됨


	char str[80] = "strawberry";

	printf("바꾸기 전 문자열 : %s\n", str);
	my_strcpy(str, "apple");
	printf("바꾼 후 문자열 : %s\n", str);
	printf("다른 문자열 대입 : %s\n", my_strcpy(str, "kiwi"));


	char str[20] = "mango tree";
	strncpy(str, "apple-pie", 5);
	printf("%s\n", str); //결과값 apple tree


	char str1[80], str2[80];
	char* resp;

	printf("2개의 과일 이름 입력 : ");
	scanf("%s%s", str1, str2);
	if (strlen(str1) > strlen(str2)) resp = str1;
	else resp = str2;
	printf("이름이 긴 과일은 : %s\n", resp);


	char str[80] = "straw";

	strcat(str, "berry");	//복사가될 배열을 최소한 '\0'값으로 초기화해놔야함
	printf("%s\n", str);	//'\0'값을 찾아서 거기부터 복사하기 때문임
	strncat(str, "piece", 3);
	printf("%ss\n", str);

	char str[80] = {'\0'}; //'\0'값으로 초기화방법들
	char str[80] = { 0 };
	char str[80] = "";
	str[0] = '\0';


	char str1[80] = "pear";
	char str2[80] = "peach";

	printf("사전에 나중에 나오는 과일 이름 : ");
	if (strcmp(str1, str2) > 0) printf("%s\n", str1);
	else printf("%s\n", str2);
	
	printf("앞에서 3개의 문자를 비교하면 ");
	if (strncmp(str1, str2, 3) == 0) printf("같다\n");
	else printf("다르다\n");


	auto int a = 0;
	assign();
	printf("main 함수 a : %d\n", a);

	int a = 10, b = 20;
	printf("교환 전 a와 b의 값 : %d, %d\n", a, b);
	{
		int temp;
		a = b;
		b = temp;
	}
	printf("교환 후 a와 b의 값 : %d, %d\n", a, b);


	printf("함수 호출 전 a값 : %d\n", a);

	assign10();
	assign20();

	printf("함수 호출 후 a값 : %d\n", a);


	int i;

	printf("auto 지역 변수를 사용한 함수...\n");
	for (i = 0; i < 3; i++) {
		auto_func();
	}

	printf("static 지역 변수를 사용한 함수...\n");
	for (i = 0; i < 3; i++) {
		static_func();
	}


	register int i;	//레지스터 변수는 cpu안의 저장공간인 레지스터를 사용
	auto int sum = 0;	//->사용횟수가 많을경우 실행시간을 줄일 수 있음
	//전역변수는 레지스터 선언불가능, 저장공간이아니므로 포인터사용 불가능, 레지스터사용 보장x
	for (i = 1; i <= 10000; i++) {	//레지스터사용여부는 컴파일러가 결정
		sum += i;
	}
	printf("%d\n", sum);


	int a = 10;
	add_ten(a);
	printf(" a : %d\n", a);


	int a = 10;

	add_ten(&a);
	printf("a : %d\n", a);


	int* p;
	p = sum1(10, 20);
	printf("두 정수의 합 : %d\n", *p);

	return 0;
}

int* sum1(int a, int b) {
	static int res;
	res = a + b;
	return &res;
}

void add_ten(int* p) {
	*p = *p + 10;
}

void add_ten(int a) {
	a = a + 10;
}

void auto_func(void) {
	auto int a = 0;
	a++;
	printf("%d\n", a);
}

void static_func(void) {
	static int a; //정적변수는 초기화하지 않으면 자동으로 0으로 초기화
	a++;
	printf("%d\n", a);
}

void assign10(void) {
	a = 10;
}

void assign20(void) {
	int a;
	a = 20;
}

void assign(void) {
	auto int a;
	a = 10;
	printf("assign 함수 a : %ㅇ\n", a);
}

int my_strcmp(char* pa, char* pb) {
	while ((*pa == *pb) && (*pa != '\0')) {
		pa++;
		pb++;
	}
	if (*pa > * pb) return 1;
	else if (*pa < *pb) return -1;
	else return 0;
}

char* my_strcat(char* pd, char* ps) {
	char* po = pd;
	while (*pd != '\0') {
		pd++;
	}
	while (*ps != '\0') {
		*pd = *ps;
		pd++;
		ps++;
	}
	*pd = '\0';
	return po;
}

int my_strlen(char* ps) {
	int cnt = 0;
	while (*ps != '\0') {
		cnt++;
		ps++;
	}
	return cnt;
}

char* my_strcpy(char* pd, char* ps) {
	char* po = pd;
	while (*ps != '\0') {
		*pd = *ps;
		pd++;
		ps++;
	}
	*pd = '\0';
	return po;
}


void my_gets(char* str, int size) {
	char ch;
	int i = 0;

	ch = getchar();
	while ((ch != '\n') && (i < size - 1)) {
		str[i] = ch;
		i++;
		ch = getchar();
	}
	str[i] = '\0';
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

