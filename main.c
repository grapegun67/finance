#include "account.h"

#define PATHNAME	"exam.txt"

int main(int argc, char **argv)
{
	int num, fd, money;
	char *name;

	fd = open(PATHNAME, O_CREAT | O_RDWR , 0644);
	if(fd == -1)
	{
		perror("main.c -> open()-error\n");
		return 0;
	}

	while(1){

		printf("1.생성 2.조회 3.예금 4.출금 5.종료\n");
		scanf("%d", &num);


		switch(num)
		{
		case 1:

			printf("이름을 입력하세요\n");
			scanf("%s", name);
			Create(fd, name);

			break;

		case 2:

			printf("이름을 입력하세요\n");
			scanf("%s", name);
			Read(fd, name);

			break;

		case 3:
			printf("이름을 입력하세요\n");
			scanf("%s", name);
			printf("예금액을 입력하세요\n");
			scanf("%d", &money);
			Deposit(fd, name, money);

			break;

		case 4:
			printf("이름을 입력하세요\n");
			scanf("%s", name);
			printf("출금액을 입력하세요\n");
			scanf("%d", &money);
			Withdraw(fd, name, money);

			break;
		
		case 5:
			printf("종료\n");
			return 0;
		}

	}

	return 0;
}
