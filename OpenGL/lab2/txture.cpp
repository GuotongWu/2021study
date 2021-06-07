#include<iostream>
#include"../stb/stb_image.h"
using namespace std;

int main(){
    int width, height, nrChannels;
    unsigned char *data = stbi_load("th.bmp", &width, &height, &nrChannels, 0); 
    for(int i=0; i<10; ++i)
        cout<<data[i]<<endl;
}