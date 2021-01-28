#include "c-isam.h"

int main()
{
	int index, i;
	char name[NAME_LENGTH];
	Node* tmp;

	Node hash_table[ODDNUM];
	/* hash_table 초기화 */
	for (i = 0; i < ODDNUM; i++) {
		memset(hash_table[i].data.name, 0, sizeof(hash_table[i].data.name));
		hash_table[i].next = NULL;
	}


	while (1) {

		insert_hash_table(hash_table);
		
		printf("\n해쉬 테이블 상태입니다.\n");

		print_hash_table(hash_table);
	}

	return 0;
}
