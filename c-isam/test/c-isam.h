#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ODDNUM  17
#define NAME_LENGTH     20

typedef struct data{

	char name[NAME_LENGTH];
	int money;
}Data;


int hash_func(char* name);
