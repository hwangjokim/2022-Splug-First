#include <stdio.h>
#include <stdlib.h>


typedef struct info{
	char name[20];
	char address[40];
	char phone[15];
	struct info *next;
}info;

void print_main(void);
info* load_data(FILE *fp);
void print_user(info *user);

int main(void){
	while(1){
		int select;
		FILE *fp=fopen("명단.txt","r");
		info *user=load_data(fp);
		print_main();
		printf("선택 : ");
		scanf("%d",&select);
		switch(select){
			case(1):
				print_user(user);
				break;
			case(2):
				break;
			case(3):
				break;
			case(4):
				break;
			case(5):
				break;
			case(6):
				return 0;
				break;
		}

	}
}

void print_main(void){

	//system("clear");
	printf("        ==메뉴==\n");
	printf("1. 모든 주소록 정보 출력\n");
	printf("2. 회원 등록\n");
	printf("3. 회원 정보 검색\n");
	printf("4. 회원 정보 수정\n");
	printf("5. 회원 삭제\n");
	printf("6. 프로그램 종료\n");
	return ;
}

info* load_data(FILE *fp){
	info *head=(info *)malloc(sizeof(info));
	if (fscanf(fp,"%s %s %s",head->name,head->address,head->phone)==EOF){
		free(head);
		return NULL;
	}
	head->next=load_data(fp);
	return head;
}

void print_user(info* user){

	for(info *search=user;search!=NULL;search=search->next){
		printf("%s %s %s\n",search->name,search->address,search->phone);
	}






}
















