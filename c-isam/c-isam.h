#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ODDNUM	17
#define NAME_LENGTH	20

typedef struct element {

	char name[NAME_LENGTH];

}Element;

typedef struct node {

	Element data;
	struct node* next;

}Node;


int hash_func(char* name);
void print_hash_table(Node hash_table[]);
void insert_hash_table(Node hash_table[]);


