/*	작성자 : 홍길동
	제목 : 10과 20을 더하는 프로그램 */
#define	_CRT_SECURE_NO_WARNINGS //불필요한 경고메시지를 보고싶지 않다면...
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int add(int x, int y);
int get_pos(void);
void print_char(char ch, int cnt);
void print_line(void);
void fruit_recursive(int n);
void swap(int* pa, int* pb);

int main1(void) { //head = function prototype
	printf("Be happy!");  //body
	printf("Be happy!\n");
	printf("%d", 10);
	printf("%lf", 3.5);
	printf("%d\n", 10 + 20);
	10 + 20;
	printf("12345678901234567890\n");
	printf("Be happy\n");
	printf("My\tfriend\n");
	printf("Goot\bd\tchance\n");
	printf("Cow\rW\a\n");
	
	printf("%d\n", 10);
	printf("%lf\n", 3.4);
	printf("%.1lf\n", 3.45);
	printf("%.10lf\n", 3.4);

	printf("%d과 %d의 합은 %d입니다.\n", 10, 20, 10 + 20);

	printf("%d\n", 12); //10진수 정수형 상수 출력
	printf("%d\n", 014); //8진수 정수형 상수 출력
	printf("%d\n", 0xc); //16진수 정수형 상수 출력

	printf("%.1lf\n", 1e6);
	printf("%.7lf\n", 3.14e-5);

	printf("%c\n", 'A');
	printf("%s\n", "A");
	printf("%c은 %s입니다.\n", '1', "first");

	int a;
	int b, c;
	double da;
	char ch;

	a = 10;
	b = a;
	c = a + 20;
	da = 3.5;
	ch = 'A';

	printf("변수 a의 값 : %d\n", a);
	printf("변수 b의 값 : %d\n", b);
	printf("변수 c의 값 : %d\n", c);
	printf("변수 da의 값 : %.1lf\n", da);
	printf("변수 ch의 값 : %c\n", ch);

	int a1;
	int b1 = 20;
	int c1;

	a = 10;
	printf("a:%d\n", a1);
	printf("b:%d\n", b1);
	printf("c:%d\n", c1);

	char ch1 = 'A';
	char ch2 = 65;
	printf("문자 %c의 아스키 코드값 : %d\n", ch1, ch2);
	printf("아스키 코드값이 %d인 문자 : %c\n", ch2, ch2);

	short sh = 32767;
	int in = -2147483648;
	long ln = 2147483647;
	long long lln = 123451234512345;

	printf("short형 변수 출력 : %d\n", sh);
	printf("int형 변수 출력 : %d\n", in);
	printf("long형 변수 출력 : %ld\n", ln);
	printf("long long형 변수 출력 : %lld\n", lln);

	unsigned int a2;
	a2 = 4294967295;
	printf("%d\n", a2);
	a2 = -1;
	printf("%u\n", a2);
	
	float ft = 1.234567890123456789f; //float는 f를 넣어줘도 되고 안넣어줘도 됨
	double db = 1.234567890123456789;

	printf("float형 변수의 값 : %.20f\n", ft);
	printf("double형 변수의 값 : %.20lf\n", db);

	char fruit[20] = "strawberry";
	printf("딸기 : %s\n", fruit);
	printf("딸기잼 : %s %s\n", fruit, "jam");
	printf("좋아하는 과일 : %s\n", fruit);	

	char fruit[20] = "strawberry";
	printf("%s\n", fruit);
	strcpy(fruit, "banana"); //<string.h>
	printf("%s\n", fruit);

	int income = 0;
	double tax;
	const double tax_rate = 0.12;

	income = 456;
	tax = income * tax_rate;
	printf("세금은 : %.1lf입니다.\n", tax);

	int a3;
	scanf("%d", &a3);
	printf("입력된 값 : %d\n", a3);

	int age;
	double height;

	printf("나이와 키를 입력하세요 : ");
	scanf("%d %lf", &age, &height);
	printf("나이는 %d살 키는 %.1lfcm입니다.\n", age, height);

	char grade;
	char name[20];

	printf("학점 입력 : ");
	scanf("%c", &grade);
	printf("이름 입력 : ");
	scanf("%s", name);
	printf("%s의 학점은 %c입니다.\n", name, grade);

	int a, b;
	int sum, sub, mul, inv;
	a = 10;
	b = 20;
	sum = a + b;
	sub = a - b;
	mul = a * b;
	inv = -a;
	printf("a의 값 : %d, b의 값 : %d\n", a, b);
	printf("덧셈 : %d\n", sum);
	printf("뺄셈 : %d\n", sub);
	printf("곱셈 : %d\n", mul);
	printf("a의 음수연산 : %d\n", inv);

	system("pause"); //<stdlib.h>

	double apple;
	int banana;
	int orange;

	apple = 5.0 / 2.0;
	banana = 5 / 2;
	orange = 5 % 2; //실수연산에는 나머지의 개념이 없으므로 나머지연산자의
					//피연산자로는 반드시 정수만 사용해야함
	printf("apple : %.1lf\n", apple);
	printf("banana : %d\n", banana);
	printf("orange : %d\n", orange);

	int a = 10, b = 10;
	++a;
	--b;
	printf("a : %d\n", a);
	printf("b : %d\n", b);

	int a = 5, b = 5;
	int pre, post;
	pre = (++a) * 3;
	post = (b++) * 3;
	printf("초깃값 a = %d, b = %d\n", a, b);
	printf("전위형: (++a) * 3 = %d, 후위형: (b++) * 3 = %d\n", pre, post);

	int a = 10, b = 20, c = 10;
	int res;

	res = (a > b);
	printf("a > b : %d\n", res);
	res = (a >= b);
	printf("a >= b : %d\n", res);
	res = (a < b);
	printf("a < b : %d\n", res);
	res = (a <= b);
	printf("a <= b : %d\n", res);
	res = (a <= c);
	printf("a <= c : %d\n", res);
	res = (a == b);
	printf("a == b : %d\n", res);
	res = (a != c);
	printf("a != c : %d\n", res);

	int a = 30;
	int res;
	res = (a > 10) && (a < 20);
	printf("(a > 10) && (a < 20) : %d\n", res);
	res = (a < 10) || (a > 20);
	printf("(a <10 ) || (a > 20) : %d\n", res);
	res = !(a >= 30);
	printf("! ( a >= 30) : %d\n", res);

	int a = 10, b = 20, res;
	a + b;
	printf("%d + %d = %d\n", a, b, a + b);

	res = a + b;
	printf("%d + %d = %d\n", a, b, res);

	int a = 20, b = 3;
	double res;

	res = ((double)a) / ((double)b);
	printf("a = %d, b = %d\n", a, b);
	printf("a / b의 결과 %.1lf\n", res);

	a = (int)res;
	printf("(int) %.lf의 결과 %d\n", res, a);

	int a = 10;
	double b = 3.4;

	printf("int형 변수의 크기 : %d\n", sizeof(a));
	printf("double형 변수의 크기 : %d\n", sizeof(b));
	printf("정수형 상수의 킈 : %d\n", sizeof(10));
	printf("수식의 결과값의 크기 : %d\n", sizeof(1.5 + 3.4));
	printf("char 자료형의 크기 : %d\n", sizeof(char));

	int a = 10, b = 20;
	int res = 2;
	a += 20;
	res *= b + 10;

	printf("a = %d, b = %d\n", a, b);
	printf("res = %d\n", res);

	int a = 10, b = 20;
	int res;

	res = (++a, ++b);	//콤마연산자는 제어문에서 조건식을 나열하는 괄호 안과
						//같이 세미콜론 사용이 불가능한 구조에서 사용합니다.
	printf("a:%d, b:%d\n", a, b);
	printf("res:%d\n", res);

	int a = 10, b = 20, res;
	res = (a > b) ? a : b;
	printf("큰 값 : %d\n", res);

	int a = 10;
	int b = 12;

	printf("a & b : %d\n", a & b);
	printf("a ^ b : %d\n", a^ b);
	printf("a | b : %d\n", a | b);
	printf("~a : %d\n", ~a);
	printf("a <<1 : %d\n", a << 1);
	printf("a >> 2 : %d\n", a >> 2);	//새로운 비트는 부호비트로 채움
										//하지만 unsigned라면 항상 0으로 채움
	int a = 10, b = 5;
	int res;

	res = a / b * 2;
	printf("res= %d\n", res);
	res = ++a * 3;
	printf("res = %d\n", res);
	res = a > b && a != 5;
	printf("res = %d\n", res);
	res = a % 3 == 0;
	printf("res = %d\n", res);

	int a = 20;
	int b = 0;

	if (a > 10) {
		b = a;
	}
	printf("a : %d, b : %d\n", a, b);

	int a = 10;
	if (a >= 0) {
		a = 1;
	}
	else {
		a = -1;
	}
	printf("a : %d\n", a);

	int a = 0, b = 0;
	if (a > 0) {
		b = 1;
	}
	else if (a == 0) {
		b = 2;
	}
	else {
		b = 3;
	}
	printf("b : %d\n", b);

	int a = 20, b = 10;
	if (a > 10) {
		if (b >= 0) {
			b = 1;
		}
		else {
			b = -1;
		}
	}
	printf("a : %d, b : %d\n", a, b);

	int a = 10, b = 20;
	if (a < 0) {
		if (a < 0) {
			if (b > 0) {
				printf("ok");
			}
		}
		else {
			printf("ok");
		}
	}

	int rank = 2, m = 0;
	switch (rank) {
	case 1:
		m = 300;
		break;
	case 2:
		m = 200;
		break;
	case 3:
		m = 100;
		break;
	default:
		m = 10;
		break;
	}
	printf("m : %d\n", m);

	int a = 1;
	while (a < 10) {
		a = a * 2;
	}
	printf("a : %d\n", a);

	int a = 1;
	int i;
	for (i = 0; i < 3; i++) {
		a = a * 2;
	}
	printf("a : %d\n", a);

	int a = 1;
	do {
		a = a * 2;
	} while (a < 10);
	printf("a : %d\n", a);

	int i, j;
	for (int i = 0; i < 3; i++) {
		for (j = 0; j < 5; j++) {
			printf("*");
		}
		printf("\n");
	}


	int i, j;
	for (int i = 2; 2 < 10; i++) {
		for (int j = 1; j < 10; j++) {
			printf("%d * %d = %d\n", i, j, i * j);
		}
		printf("\n");
	}

	int i;
	int sum = 0;
	for (i = 1; i <= 10; i++) {
		sum += i;
		if (sum > 30) break;
	}
	printf("누적한 값 : %d\n", sum);
	printf("마지막으로 더한 값 : %d\n", i);

	int a = 10, b = 20;
	int res;

	res = add(a, b);
	printf("result : %d\n", res);

	int res;
	res = get_pos();
	printf("반환값 : %d\n", res);
	
	printf_char('@', 5);

	print_line();
	printf("학번      이름    전공   학점\n");
	print_line();

	fruit_recursive(1);

	int ary[5];
	ary[0] = 10;
	ary[1] = 20;
	ary[2] = ary[0] + ary[1];
	scanf("%d", &ary[3]);

	printf("%d\n", ary[2]);
	printf("%d\n", ary[3]);
	printf("%d\n", ary[4]);

	int ary1[5] = { 1, 2, 3, 4, 5 };
	int ary2[5] = { 1, 2, 3 };
	int ary3[] = { 1, 2, 3 };
	double ary4[5] = { 1.0, 2.0, 3.2, 4.3, 5.4 };
	char ary5[5] = { 'a', 'p', 'p', 'l', 'e' };

	ary1[0] = 10;
	ary1[1] = 20;
	ary1[2] = 30;
	ary1[3] = 40;
	ary1[4] = 50;

	int score[5];
	int i;
	int tot = 0;
	double avg;

	for (i = 0; i < 5; i++) {
		scanf("%d", &score[i]);
	}

	for (i = 0; i < 5; i++) {
		tot += score[i];
	}
	avg = tot / 5.0;

	for (i = 0; i < 5; i++) {
		printf("%5d", score[i]);
	}
	printf("\n");
	printf("평균 : %.1lf\n", avg);

	
	int score[5];
	int i;
	int tot = 0;
	double avg;
	int cnt;

	cnt = sizeof(score) / sizeof(score[0]);

	for (i = 0; i < cnt; i++) {
		scanf("%d", &score[i]);
	}

	for (i = 0; i < cnt; i++) {
		tot += score[i];
	}
	avg = tot / (double)cnt;
	
	for (i = 0; i < cnt; i++) {
		printf("%5d", score[i]);
	}
	printf("\n");
	printf("평균 : %.1lf\n", avg);

	char str[80] = "applejam";

	printf("최초 문자열 : %s\n", str);
	printf("문자열 입력 : ");
	scanf("%s", str);
	printf("입력 후 문자열 : %s\n", str);

	char str[5];

	str[0] = '0';
	str[1] = 'K';
	printf("%s\n", str);

	char str1[80] = "cat";
	char str2[80];
	strcpy(str1, "tiger"); //<string.h> 문자열을 다루는 함수들의 원형들이 있음
	strcpy(str2, str1);
	printf("%s, %s\n", str1, str2);

	char str[80];
	printf("문자열 입력 : ");
	gets(str);
	puts("입력된 문자열 : ");
	puts(str);

	int a;
	double b;
	char c;

	printf("int형 변수의 주소 : %u\n", &a); //주소는 양수이므로 %u변환문자 사용
	printf("%p\n", &a);	//%p, %x를 사용하여 16진수로도 출력가능
	printf("double형 변수의 주소 : %u\n", &b);
	printf("char형 변수의 주소 : %u\n", &c);

	int a;
	int* pa;

	pa = &a;
	*pa = 10;

	printf("포인터로 a값 출력 : %d\n", *pa);
	printf("변수명으로 a값 출력 : %d\n", a);

	int a = 10, b = 15, tot;
	double avg;
	int* pa, * pb;
	int* pt = &tot;
	double* pg = &avg;

	pa = &a;
	pb = &b;

	*pt = *pa + *pb;
	*pg = *pt / 2.0;

	printf("두 정수의 값 : %d, %d\n", *pb, *pa);
	printf("두 정수의 합 : %d\n", *pt);
	printf("두 정수의 평균 : %.1lf\n", *pg);
	
	int a = 10, b = 20;
	const int* pa = &a; //const는 주소값은 바꿀 수 있지만 해당값은 못바꿈

	printf("변수 a의 값 : %d\n", *pa);
	pa = &b;
	printf("변수 b값 : %d\n", *pa);
	pa = &a;
	a = 20;
	printf("변수 a값 : %d\n", *pa);

	char ch;
	int in;
	double db;

	char* pc = &ch;
	int* pi = &in;
	double* pd = &db;

	printf("char형 변수의 주소 크기 : %d\n", sizeof(&ch));
	printf("int형 변수의 주소 크기 : %d\n", sizeof(&in));
	printf("double형 변수의 주소 크기 : %d\n", sizeof(&db));

	printf("char * 포인터의 크기 : %d\n", sizeof(pc));
	printf("int * 포인터의 크기 : %d\n", sizeof(pi));
	printf("double * 포인터의 크기 : %d\n", sizeof(pd));

	printf("char * 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pc));
	printf("int * 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pi));
	printf("double * 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pd));

	int a = 10;
	int* p = &a;
	double* pd;

	pd = p;
	printf("%lf\n", *pd);

	double a = 3.4;
	double* pd = &a;
	int* pi;
	pi = (int*)pd; //포인터의 형변환 but 공간공유 범위가 다름

	int* p;
	p = (int*)100;
	*p = 10;

	int a = 10, b = 20;
	swap(&a, &b);
	printf("a:%d, b:%d\n", a, b);

	return 0;  
}

void swap(int* pa, int* pb) {
	int temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void fruit_recursive(int n) {
	printf("apple\n");
	if (n == 3) return;
	fruit_recursive(n+1);
	printf("jam\n");
}

void print_line(void) {
	int i;
	for (i = 0; i < 50; i++) {
		printf("-");
	}
	printf("\n");
}

void print_char(char ch, int cnt) {
	int i;
	if (cnt > 10) return;
	for (int i = 0; i < cnt; i++) {
		printf("%c", ch);
	}
}

int add(int x, int y) {
	int temp;
	temp = x + y;
	return temp;

}

int get_pos(void) {
	int pos;
	printf("양수 입력 : ");
	scanf("%d", &pos);
	while (pos < 0) {
		printf("음수가 입력되었습니다!\n");
		printf("양수 입력 : ");
		scanf("%d", &pos);
	}
	return pos;
}
