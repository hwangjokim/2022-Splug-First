#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct info{
	char name[20];
	char address[40];
	char phone[15];
	struct info *next;
}info;

void print_main(void);
info* load_data(FILE *fp);
void print_user(info *user);
void search_user(info *user); 

int main(void){
	print_main();
	printf("=======================\n");
	while(1){
		int select;
		FILE *fp=fopen("명단.txt","r");
		info *user=load_data(fp);
		//sorting_node(user);

		printf("선택 : ");

		scanf("%d",&select);
		printf("=======================\n");
		switch(select){
			case(1):
				print_user(user);
				printf("=======================\n");
				break;
			case(2):
				break;
			case(3):
				search_user(user);
				printf("=======================\n");
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
/*
   void sorting_node(info *user){	
   info *temp=(info *)malloc(sizeof(info));
   info *head=user;




   }
   */
void print_user(info* user){
	for(info *search=user;search!=NULL;search=search->next){
		printf("%s %s %s\n",search->name,search->address,search->phone);
	}

}

void search_user(info* user){
	char search_name[30];
	printf("찾을 회원의 이름을 입력하세요: ");
	scanf("%s",search_name);
	while(user!=NULL){
		if (!strcmp(search_name,user->name)){
			printf("이름 : %s\n",user->name);
			printf("주소 : %s\n",user->address);
			printf("전화번호 : %s\n",user->phone);
			return ;
		}
		user=user->next;
	}
	printf("찾는 회원은 존재하지 않습니다.\n");





}
















