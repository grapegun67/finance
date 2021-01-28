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
		printf("문자열을 입력하세요:");
		scanf("%s", name);
		index = hash_func(name);

																	/* 입력값을 노드에 삽입 코드 */
																	tmp = hash_table[index].next;
																	if (tmp == NULL) {														hash_table[index].next = (Node*)malloc(sizeof(Node));									strncpy(hash_table[index].data.name, name, sizeof(name));
			tmp = hash_table[index].next;

																																//새로운 노드 생성 및 초기화
		memset(tmp->data.name, 0, sizeof(hash_table[index].data.name));
		tmp->next = NULL;
		}

		else{

			while (tmp->next != NULL) {
				tmp = tmp->next;												}
			
			strncpy(tmp->data.name, name, sizeof(name));
			
			//새로운 노드 생성 및 초기화
			tmp->next = (Node*)malloc(sizeof(Node));
			memset(tmp->next->data.name, 0, sizeof(hash_table[index].data.name));
			tmp->next->next = NULL;
		}
																	printf("\n해쉬 테이블 상태입니다.\n");
																	/* hash_table 상태 출력 코드 */
																																for (i = 0; i < ODDNUM; i++) {
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
	
	return 0;
}
