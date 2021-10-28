#include<stdio.h>

char* number_to_char(int number)
{
	char *res;
	*res = '\0';
	while(number > 0){
		*--res = number % 10;
		number /= 10;
	}
	return res;		
}

void main(){
    char * res = number_to_char(100);
    printf("%s\n", res);
    while(res)
        printf("%c", *res++);
}