#include "c-isam.h"

#define PATHNAME	"test"

int main()
{
	int flag, nodata;
	char buf[ODDNUM];
	FILE *file_hash_table[ODDNUM];

	for(int i = 0; i < ODDNUM; i++){

		snprintf(buf, sizeof(buf), "%s%d", PATHNAME, i);
		
		file_hash_table[i] = fopen(buf, "a+");
		if(file_hash_table[i] == NULL){
			perror("fopen()-error\n");
			return 0;
		}
	}


	while(1){

		printf("1. 입력 2. 해당문자출력 3.해당문자의 파일 출력 4.모든파일내용\n");
		scanf("%d", &flag);

		switch(flag)
		{
		case 1:
			input_value(file_hash_table);
			break;

		case 2:
			print_value(file_hash_table);
			break;

		case 3:
			print_file(file_hash_table);
			break;

		case 4:
			print_all(file_hash_table);
			break;
		}
	}

	return 0;
}
