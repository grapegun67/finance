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

void input_value(FILE **file_hash_table)
{
	int money, index;
	char name[NAME_LENGTH];
	Data data_buf;

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
		return;
	}
}

void print_value(FILE **file_hash_table)
{
	int index, nodata = 0;
	char name[NAME_LENGTH];
	Data data_buf;

	printf("문자열을 입력하세요\n");
        scanf("%s", name);

	index = hash_func(name);
	memset(&data_buf, 0 ,sizeof(data_buf));

	fseek(file_hash_table[index], 0, SEEK_SET);

	while(1){

		if(fread(&data_buf, sizeof(data_buf), 1, file_hash_table[index]) == 0){

			if(feof(file_hash_table[index])) break;

			perror("fread()-error\n");
			return;
		}

		if(!strcmp(data_buf.name, name)){
			printf("result: %s %d\n", data_buf.name, data_buf.money);
			nodata = 1;
			break;
		}

	}

	if(nodata != 1){
		printf("nodata!!\n");
		nodata = 0;
	
	}
}

void print_file(FILE **file_hash_table)
{
	int index;
	char name[NAME_LENGTH];
	Data data_buf;

      	printf("문자열을 입력하세요\n");
	scanf("%s", name);

	index = hash_func(name);
	memset(&data_buf, 0 ,sizeof(data_buf));

	fseek(file_hash_table[index], 0, SEEK_SET);

	while(1){

		if(fread(&data_buf, sizeof(data_buf), 1, file_hash_table[index]) == 0){

			if(feof(file_hash_table[index])) break;

			perror("fread()-error\n");
			return;
		}

		printf("result: %s %d\n", data_buf.name, data_buf.money);
	}

}

void print_all(FILE **file_hash_table)
{

	Data data_buf;

	for(int ii = 0; ii<ODDNUM; ii++){

		memset(&data_buf, 0, sizeof(data_buf));
		fseek(file_hash_table[ii], 0, SEEK_SET);

		printf("-test%d: \n", ii);

		while(1){

			if(fread(&data_buf, sizeof(data_buf), 1, file_hash_table[ii]) == 0){

				if(feof(file_hash_table[ii])) break;

				perror("fread()-error\n");
				return;
			}

		printf("result: %s %d\n", data_buf.name, data_buf.money);
	
		}

		printf("\n");
	}

}


