#ifndef __ACCOUNT__
#define __ACCOUNT__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct Account{
	
	char name[20];
	int money;

}Account;


void Create(int fd, char *name);
void Read(int fd, char *name);
void Deposit(int fd, char *name, int money);
void Withdraw(int fd, char *name, int money);

#endif
