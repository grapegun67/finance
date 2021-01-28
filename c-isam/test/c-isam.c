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
