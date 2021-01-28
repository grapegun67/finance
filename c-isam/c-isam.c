#include "c-isam.h"

int hash_func(char* name)
{
	int i = 0;
	int result = 0;
	
	while (i < strlen(name)) {
		
		result += *(name + i++);

	}
	result %= ODDNUM;

	return result;
}

void print_hash_table(Node hash_table[])
{
	Node* tmp;

	for (int i = 0; i < ODDNUM; i++) {

		printf("%d) ", i);

		if (hash_table[i].next == NULL) {
			printf("\n");
			continue;
		}

		else {

			printf("-%s", hash_table[i].data.name);
			tmp = hash_table[i].next;

			while (tmp->next != NULL) {
				printf("-%s", tmp->data.name);
				tmp = tmp->next;
			}
		}

		printf("\n");
	}

	printf("\n----------------------------------------------------------------------------\n");
}

void insert_hash_table(Node hash_table[])
{
	int index, i;
	char name[NAME_LENGTH];
	Node* tmp;

	printf("문자열을 입력하세요:");
	scanf("%s", name);

	index = hash_func(name);

	/* 입력값을 노드에 삽입 코드 */
	tmp = hash_table[index].next;

	if (tmp == NULL) {
		hash_table[index].next = (Node*)malloc(sizeof(Node));
		strncpy(hash_table[index].data.name, name, sizeof(name));

		tmp = hash_table[index].next;

		//새로운 노드 생성 및 초기화
		memset(tmp->data.name, 0, sizeof(hash_table[index].data.name));
		tmp->next = NULL;
	}

	else {

		while (tmp->next != NULL) {
			tmp = tmp->next;
		}

		strncpy(tmp->data.name, name, sizeof(name));

		//새로운 노드 생성 및 초기화
		tmp->next = (Node*)malloc(sizeof(Node));
		memset(tmp->next->data.name, 0, sizeof(hash_table[index].data.name));
		tmp->next->next = NULL;
	}

}

