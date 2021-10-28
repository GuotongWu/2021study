#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
using namespace std;

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

int main(){
    char * temp = number_to_char(100);
    strcat(temp, "Hz");
    cout<<temp<<endl;
}