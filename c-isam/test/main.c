#include "c-isam.h"

#define PATHNAME	"test"

int main()
{
	int index, money, flag;
	FILE *file_hash_table[ODDNUM];
	char name[NAME_LENGTH];
	char buf[ODDNUM];
	Data data_buf;

	for(int i = 0; i < ODDNUM; i++){

		snprintf(buf, sizeof(buf), "%s%d", PATHNAME, i);
		
		file_hash_table[i] = fopen(buf, "a+");
		if(file_hash_table[i] == NULL){
			perror("fopen()-error\n");
			return 0;
		}
	}


	while(1){

		printf("1. 입력 2. 출력 3.전체출력\n");
		scanf("%d", &flag);

		switch(flag)
		{
		case 1:

			printf("문자열을 입력하세요\n");
			scanf("%s", name);

			printf("돈을 입력하세요\n");	
			scanf("%d", &money);

			memset(&data_buf, 0, sizeof(data_buf));
			strncpy(data_buf.name, name, sizeof(name));
			data_buf.money = money;

			index = hash_func(name);
			
			fseek(file_hash_table[index], 0, SEEK_END);
			if(fwrite(&data_buf, sizeof(data_buf), 1, file_hash_table[index]) == 0){
				perror("fwrite()-error\n");
				return 0;
			}

			break;
		case 2:
			
			printf("문자열을 입력하세요\n");
			scanf("%s", name);

			index = hash_func(name);
			memset(&data_buf, 0 ,sizeof(data_buf));

			fseek(file_hash_table[index], 0, SEEK_SET);
			if(fread(&data_buf, sizeof(data_buf), 1, file_hash_table[index]) == 0){
		
				perror("fread()-error\n");
				return 0;
			}

			printf("result: %s %d\n", data_buf.name, data_buf.money);

			break;
		case 3:


			break;
		}
	}

	return 0;
}
