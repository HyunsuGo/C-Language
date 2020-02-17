#include <stdio.h>
#include <stdlib.h> //malloc, free 함수 사용을 위한 헤더 파일
#include <string.h>
#pragma pack(1) //바이트 얼라인먼트를 1로 설정하면 패딩바이트가 필요 없음. but 이 경우 데이터를 읽고쓰는 시간은 더 걸릴수도 있음
				//결국 멤버의 순서에 따라 구조체의 크기가 달라질 수 있으므로 패딩바이트가 가장 작도록 구조체를 선언하면 메모리 아낌
void print_str(char** ps);
void print_str2(char**);


struct student {
	int num;
	double grade;
};

struct profile {
	char name[20];
	int age;
	double height;
	char* intro;
};

struct profile2 {
	int age;
	double height;
};

struct student2 {
	struct profile pf;
	int id;
	double grade;
};

struct student3 {
	int id;
	char name[20];
	double grade;
};

struct vision {
	double left;
	double right;
};

struct children {	//비트 필드 구조체는 멤버의 크기를 비트(bit) 단위로 설정 할 수 있음
	unsigned int son : 2; //각 멤버가 사용할 비트수를 콜론(:) 옆에 표시
	unsigned int daughter : 2;	//자료형이 signed인 경우 음수까지 저장 할 수 있으나 부호비트의 처리방식이 시스템에
	unsigned int pet : 3;		//따라 다를 수 있으므로 unsigned를 주로 사용함
};

struct score {
	int kor;
	int eng;
	int mat;
};

struct address {
	char name[20];
	int age;
	char tel[20];
	char addr[80];
};

struct list {
	int num;
	struct list* next;
};

union student {
	int num; double grade;
};

typedef union {
	int ea;
	double kg;
	double liter;
} Unit;

typedef struct {
	char name[20];
	enum { EGG = 1, MILK, MEAT } kind;
	Unit amount;
} Gift;

enum season { SPRING, SUMMER, FALL, WINTER };

void print_list2(Gift a);
struct vision exchange(struct vision);
void print_list(struct address* lp);
typedef struct student Student;
void print_data(Student* ps);


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
	
	
	struct studnet s1;

	s1.num = 2;
	s1.grade = 2.7;
	printf("학번 : %d\n", s1.num);
	printf("학점 : %.1lf\n", s1.grade);
	

	struct profile yuni;

	strcpy(yuni.name, "서하윤");
	yuni.age = 17;
	yuni.height = 164.5;

	yuni.intro = (char*)malloc(80);
	printf("자기 소개 : ");
	gets(yuni.intro);

	printf("이름 : %s\n", yuni.name);
	printf("나이 : %d\n", yuni.age);
	printf("키 : %.1lf\n", yuni.height);
	printf("자기소개 : %s\n", yuni.intro);
	free(yuni.intro);


	struct stdent2 yuni2;

	yuni2.pf.age = 17;
	yuni2.pf.height = 164.5;
	yuni2.id = 315;
	yuni2 = 4.3;

	printf("나이 : %d\n", yuni2.pf.age);
	printf("키 : %.1lf\n", yuni2.pf.height);
	printf("학번 : %d\n", yuni2.id);
	printf("학점 : %.1lf\n", yuni2.grade);

	
	struct student3 s1 = { 315, "홍길동", 2.4 },
		s2 = { 316, "이순신", 3.7 },
		s3 = { 317, "세종대왕", 4.4 };
	
	struct student3 max;
	
	max = s1;
	if (s2.grade > max.grade) max = s2;
	if (s3.grade > max.grade) max = s3;

	printf("학번 : %s\n", max.id);
	printf("이름 : %s\n", max.name);
	printf("학점 : %.1lf\n", max.grade);


	struct vision robot;

	printf("시력 입력 : ");
	scanf("%lf%lf", &(robot.left), &(robot.right));
	robot = exchange(robot);
	printf("바뀐 시력 : %.1lf, %.1lf\n", robot.left, robot.right);
	

	struct children my { 1, 2, 3 };
	int sum;

	printf("struct children의 크기 : %d바이트\n", sizeof(my));
	sum = my.son + my.daughter + my.pet;
	printf("자식 수 : %d\n", sum);


	struct score yuni = { 90, 80, 70 };
	struct score* ps = &yuni;

	printf("국어 : %d\n", (*ps).kor);
	printf("영어 : %d\n", ps->eng);
	printf("수학 : %d\n", ps->mat);

	struct address list[5] = {
		{"홍길동", 23, "111-1111", "울릉도 독도"},
		{"이순신", 35, "222-2222", "서울 건천동"},
		{"장보고", 19, "333-3333", "완도 청해진"},
		{"유관순", 15, "444-4444", "충남 천안"},
		{"안중근", 45, "555-5555", "황해도 해주"}
	};
	int i;

	for (i = 0; i < 5; i++) {
		printf("%10s%5d%15s%20s\n", list[i].name, list[i].age, list[i].tel, list[i].addr);
	}


	struct address list[5] = {
		{"홍길동", 23, "111-1111", "울릉도 독도"},
		{"이순신", 35, "222-2222", "서울 건천동"},
		{"장보고", 19, "333-3333", "완도 청해진"},
		{"유관순", 15, "444-4444", "충남 천안"},
		{"안중근", 45, "555-5555", "황해도 해주"}
	};

	print_list(list);


	struct list a = { 10, 0 }, b = { 20, 0 }, c = { 30,0 };
	struct list* head = &a, * current;

	a.next = &b;
	b.next = &c;
	
	printf("head->num : %d\n", head - > num);
	printf("head->next->num : %d\n", head->next->num);

	printf("list all : ");
	current = head;
	while (current != NULL) {
		printf("%d ", current->num);
		current = current->next;
	}
	printf("\n");


	union student s1 = { 315 };

	printf("학번 : %d\n", s1.num);
	s1.grade = 4.4;
	printf("학점 : %.1lf\n", s1.grade);
	printf("학번 : %d\n", s1.num);


	enum season ss;
	char* pc;

	ss = SPRING;
	switch (ss) {
	case SPRING:
		pc = "inline"; break;
	case SUMMER:
		pc = "swimming"; break;
	case FALL:
		pc = "trip"; break;
	case WINTER:
		pc = "skiing"; break;
	}
	printf("나의 레저 활동 => %s\n", pc);


	Student s1 = { 315, 4.2 };
	
	print_data(&s1);


	Gift list2[5];
	int i;

	for (i = 0;i < 5; i++) {
		printf("이름 입력 : ");
		scanf("%s", list2[i].name);
		printf("품목 선택(1.계란, 2.우유, 3.고기) : ");
		scanf("%d", &list2[i].kind);

		switch (list2[i].kind) {
		case EGG: list2[i].amount.ea = 30; break;
		case MILK: list2[i].amount.liter = 4.5; break;
		case MEAT: list2[i].amount.kg = 0.6; break;
		}
	}
	printf("# 세 번째 경품 당첨다...\n");
	print_list2(list2[i]);

	return 0;

}

void print_list2(Gift a) {
	printf(" 이름 : %s, 선택 품목 : ", a.name);
	switch (a.kind) {
	case EGG: printf("계란 %d개\n", a.amount.ea); break;
	case MILK: printf("우유 %.1lf리터\n", a.amount.liter); break;
	case MEAT: printf("고기 %.1lfkg\n", a.amount.kg); break;
	}
}

void print_data(Student* ps) {
	printf("학번 : %d\n", ps->num);
	printf("학점 : %.1lf\n", ps->grade);
}

void print_list(struct address* lp) {
	int i;

	for (i = 0; i < 5; i++) {
		printf("%10s%5d%15s%20s\n", (lp + i)->name, (lp + i)->age, (lp + i)->tel, (lp + i)->addr);
		//printf("%10s%5d%15s%20s\n", lp[i].name, lp[i].age, lp[i].tel, lp[i].addr);
		//printf("%10s%5d%15s%20s\n", (*(lp + i)).name, (*(lp + i).age, (*(lp + i).tel, (*(lp + i).addr);
	}
}

struct vision exchange(struct vision robot) {
	double temp;

	temp = robot.left;
	robot.left = robot.right;
	robot.right = temp;

	return robot;
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