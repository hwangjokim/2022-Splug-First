/* 2022 SPLUG 2월 재학생 대상 정회원 심사 예시 코드 */

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
void sorting_node(info *user);
void print_user(info *user);
void add_user(info* user);
void search_user(info *user);
void edit_user(info* user);
void delete_user(info *user);
void exit_prog(info *user);
int main(void){
	print_main();
	printf("=======================\n");
	FILE *fp=fopen("명단.txt","r");
	info *user=load_data(fp);
	fclose(fp);
	while(1){
		int select;
		sorting_node(user);
		printf("선택 : ");

		scanf("%d",&select);
		printf("=======================\n");
		switch(select){
			case(1):
				print_user(user);
				printf("=======================\n");
				break;
			case(2):
				add_user(user);
				printf("=======================\n");
				break;
			case(3):
				search_user(user);
				printf("=======================\n");
				break;
			case(4):
				edit_user(user);
				printf("=======================\n");
				break;
			case(5):
				delete_user(user);
				printf("=======================\n");
				break;
			case(6):
				exit_prog(user);
				printf("프로그램을 종료합니다.\n");
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

   void sorting_node(info *user){	 //내림차 
   info *temp=(info *)malloc(sizeof(info));
   info *seek2=(info *)malloc(sizeof(info));
   info *seek=(info *)malloc(sizeof(info));
   info *head=user;
   for(seek2->next=user;seek2->next->next!=NULL;seek2=seek2->next){
   for(seek=seek2;seek->next->next!=NULL;seek=seek->next){
   if(strcmp(seek->next->name,seek->next->next->name)>0){
   temp->next=seek->next->next;
   seek->next->next=temp->next->next;
   temp->next->next=seek->next;
   seek->next=temp->next;
   }
   }
}
 




   }
   
void print_user(info* user){
	for(info *search=user;search!=NULL;search=search->next){
		printf("%s %s %s\n",search->name,search->address,search->phone);
	}

}

void add_user(info* user){
	info* new_usr=(info *)malloc(sizeof(info));
	printf("등록할 회원의 이름을 입력하세요: ");
	scanf("%s",new_usr->name);
	printf("등록할 회원의 주소를 입력하세요: ");
	scanf("%s",new_usr->address);
	printf("등록할 회원의 전화번호를 입력하세요: ");
	scanf("%s",new_usr->phone);
	while(user->next!=NULL) user=user->next;
	user->next=new_usr;
	new_usr->next=NULL;
	printf("정상 등록되었습니다.\n");



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

void edit_user(info* user){
	char search[30];
	printf("정보를 변경하고자 하는 회원의 이름을 입력하세요 : ");
	scanf("%s",search);
	while(user!=NULL){
	if(strcmp(search,user->name)==0){
	printf("%s 회원의 변경할 이름을 입력하세요 : ",search);
	scanf("%s",user->name);
	printf("변경할 주소를 입력하세요 : ");
	scanf("%s",user->address);
	printf("변경할 전화번호를 입력하세요 : ");
	scanf("%s",user->phone);
	printf("정상적으로 변경되었습니다.\n");
	return ;
	}
	user=user->next;
	}
	printf("찾는 회원이 존재하지 않습니다.\n");
	return ;

}

void delete_user(info* user){
	char search_name[30];
	printf("삭제할 회원의 이름을 입력하세요 : ");
	scanf("%s",search_name);
	info *seek=(info *)malloc(sizeof(info));
	seek->next=user;
	while (seek->next!=NULL){
		if (!strcmp(search_name,seek->next->name)){
			printf("경고 : 정말로 삭제하시겠습니까? 이 작업은 되돌릴 수 없습니다. [Y/N] : ");
			while(getchar()!='\n');
			char select;
			scanf("%c",&select);
			if (select==89 || select==121){
				if(!strcmp(search_name,user->name)) user=user->next;
				else{
				info *temp=seek->next->next;
				free(seek->next);
				seek->next=temp;
				}
				printf("삭제가 완료되었습니다. \n");
				return ;
			}
			else{
			return;
			}


		}
		seek=seek->next;


	}
	printf("존재하지 않는 회원입니다.\n");

}


void exit_prog(info *user){
FILE *fp=fopen("명단.txt","w");
while(user!=NULL){
fprintf(fp,"%s %s %s\n",user->name,user->address,user->phone);
user=user->next;
}
fclose(fp);
return ;
}













