#include "account.h"

void Create(int fd, char *name)
{
	Account tmp_account;
	int flag = 0;

	memset(&tmp_account, 0, sizeof(Account));
	strncpy(tmp_account.name, name, sizeof(tmp_account.name));
	tmp_account.money = 0;

	if(write(fd, &tmp_account, sizeof(Account)) == -1)
	{
		perror("account.c -> write()-error\n");
		return;
	}
	
}

void Read(int fd, char *name)
{
	Account tmp_account;
	int flag = 0;
	memset(&tmp_account, 0, sizeof(Account));
	lseek(fd, 0, SEEK_SET);


	while(flag == 0){

		if(read(fd, &tmp_account, sizeof(Account)) == -1){
			perror("account.c -> read()-error\n");
			return;
		}
	
		if(strcmp(tmp_account.name, name) == 0){
		
			printf("%s %d\n", tmp_account.name, tmp_account.money);
			lseek(fd, 0, SEEK_END);
			return;
		}

	}

	printf("No account\n");
	lseek(fd, 0, SEEK_END);
}

void Deposit(int fd, char *name, int money)
{
	Account tmp_account;
	int flag = 0;
	int num = -1;
	memset(&tmp_account, 0, sizeof(Account));
	lseek(fd, 0, SEEK_SET);


	while(flag == 0){

		if(read(fd, &tmp_account, sizeof(Account)) == -1){
			perror("account.c -> read()-error\n");
			return;
		}

		num++;

		if(strcmp(tmp_account.name, name) == 0){
			

			tmp_account.money += money;
			lseek(fd, num*sizeof(Account), SEEK_SET);
			write(fd, &tmp_account, sizeof(Account));
			lseek(fd, 0, SEEK_END);
			return;
		}
	}
}

void Withdraw(int fd, char *name, int money)
{
	Account tmp_account;
	int flag = 0;
	int num = -1;
	memset(&tmp_account, 0, sizeof(Account));
	lseek(fd, 0, SEEK_SET);


	while(flag == 0){

		if(read(fd, &tmp_account, sizeof(Account)) == -1){
			perror("account.c -> read()-error\n");
			return;
		}
		num++;

		if(strcmp(tmp_account.name, name) == 0){
			
			if(tmp_account.money < money){
				printf("잔액이 부족합니다\n");
				return;
			}

			tmp_account.money -= money;
			lseek(fd, num*sizeof(Account), SEEK_SET);
			write(fd, &tmp_account, sizeof(Account));

			lseek(fd, 0, SEEK_END);
			return;
		}
	}
}


