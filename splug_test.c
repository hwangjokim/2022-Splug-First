#include <stdio.h>
#include <stdlib.h>
void print_main(void);

int main(void){
	while(1){
		int select;
		print_main();
		printf("선택 : ");
		scanf("%d",&select);
		switch(select){
			case(1):
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

	system("clear");
	printf("        ==메뉴==\n");
	printf("1. 모든 주소록 정보 출력\n");
	printf("2. 회원 등록\n");
	printf("3. 회원 정보 검색\n");
	printf("4. 회원 정보 수정\n");
	printf("5. 회원 삭제\n");
	printf("6. 프로그램 종료\n");
	return ;

}
