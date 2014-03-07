#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <dirent.h>
#include <math.h>
//older pre generated file size can be removed
#define FILEPATH "mmapped.bin"
#define NUMINTS  (1000000)
#define FILESIZE (NUMINTS * sizeof(int))
#define PI 3.14159265

int main(int argc, char *argv[])
{
    int i, j, k, I, fd, result, dirres, size, numint, params, kk;
    DIR *dp;
    struct dirent *ep;
    int *map;  
    char *filename, *dirname;
    char *info;
    char buffer[50];
    int n, a, b, A;
    struct stat st;
    double param, results;

    	dirname = "./";
       dp = opendir (dirname);
       if (dp != NULL)
         {
           while (ep = readdir (dp))
             puts (ep->d_name);
           (void) closedir (dp);
         }
       else
         perror ("Couldn't open the directory");    
    filename = "data/nnapped.bin";
	stat(filename, &st);
	size = st.st_size;
	printf("size%isize",size);
	numint = size / sizeof(int);	
	printf("ints%iints\n",numint);
    fd = open(filename, O_RDWR);
    result = lseek(fd, size-1, SEEK_SET);
    result = write(fd, "", 1);
    result = lseek(fd, 0L, SEEK_END);
    printf("%i\n",result);
    map = mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    printf("%x\n",map[0]);
    for (i = 25; i <=numint; ++i) {
    	map[i] = 0x00000000;
    }
//###################################
//############TONE BEEP##############
//###################################
//###################################
//############TONE BEEP##############
//###################################

I = 0x00110011;
for (k = 1; k <= 12; k++){

for (i = 16 + k * 15; i <= 39 + k * 15; i++) {
	j = 0x11001100;
	I = I + j;
	printf("%x\n",I);
	map[i] = I;
	}
j = 0x00110011;
I = I + j;
j = 0xff00ff00;
I = I - j;
}
j = 0x01010101;
I = 0xAAAAAAAA;
a = 25;
A = 0;
//for (kk = 25; kk <=1000; kk++){
for (b = 1; b <=100; b++){
for (k = 1; k <=360; k++){
k = k + 100;
I = 0x00000000;
param = 0.1 + k;
results = sin(param *PI/180) * 100;
result = (int) results;
printf("%dsintest\n",result);
//I = I * sin(param *PI/180);
//sprintf(result, "%06X", (int)I & 0xffffff);
//n=sprintf (buffer, "%08X", (int)I & 0xffffffff);
//printf("%ssprint\n",buffer);
//I = result * j;
for (i = 1; i <= abs(result); i++){
I = I - j * result / abs(result);
}
printf("%08Xhexchange\n",I);
map[a + A] = I;
a = a + 1;
}
A = a + A;
}
//}
//###################################
//############TONE BEEP##############
//###################################
j = 0x01010101;
I = 0xAAAAAAAA;
a = 1;
for (b = 1; b <=100; b++){
for (k = 1; k <=360; k++){
k = k + 15;
I = 0x00000000;
param = 0.1 + k;
results = sin(param *PI/180) * 100;
result = (int) results;
printf("%dsintest\n",result);
for (i = 1; i <= abs(result); i++){
I = I - j * result / abs(result);
}
printf("%08Xhexchange\n",I);
map[a + A] = I;
a = a + 1;
}
}
//###################################
//############TONE BEEP##############
//###################################
j = 0x01010101;
I = 0xAAAAAAAA;
a = 1;
for (b = 1; b <=100; b++){
for (k = 1; k <=360; k++){
k = k + 10;
I = 0x00000000;
param = 0.1 + k;
results = sin(param *PI/180) * 100;
result = (int) results;
printf("%dsintest\n",result);
for (i = 1; i <= abs(result); i++){
I = I - j * result / abs(result);
}
printf("%08Xhexchange\n",I);
map[a + A] = I;
a = a + 1;
}
}
A = A + a;
//###################################
//############TONE BEEP##############
//###################################
j = 0x01010101;
I = 0xAAAAAAAA;
a = 25;
a = 1;
for (b = 1; b <=100; b++){
for (k = 1; k <=360; k++){
k = k + 5;
I = 0x00000000;
param = 0.1 + k;
results = sin(param *PI/180) * 100;
result = (int) results;
printf("%dsintest\n",result);
for (i = 1; i <= abs(result); i++){
I = I - j * result / abs(result);
}
printf("%08Xhexchange\n",I);
map[a + A] = I;
a = a + 1;
}
}
A = A + a;
j = 0x01010101;
I = 0xAAAAAAAA;
a = 25;
//###################################
//############TONE BEEP##############
//###################################
a = 1;
for (b = 1; b <=100; b++){
for (k = 1; k <=360; k++){
k = k + 2;
I = 0x00000000;
param = 0.1 + k;
results = sin(param *PI/180) * 100;
result = (int) results;
printf("%dsintest\n",result);
for (i = 1; i <= abs(result); i++){
I = I - j * result / abs(result);
}
printf("%08Xhexchange\n",I);
map[a + A] = I;
a = a + 1;
}
}
A = A + a;
//###################################
//############TONE BEEP##############
//###################################
a = 1;
for (b = 1; b <=100; b++){
for (k = 1; k <=360; k++){
k = k + 1;
I = 0x00000000;
param = 0.1 + k;
results = sin(param *PI/180) * 100;
result = (int) results;
printf("%dsintest\n",result);
for (i = 1; i <= abs(result); i++){
I = I - j * result / abs(result);
}
printf("%08Xhexchange\n",I);
map[a + A] = I;
a = a + 1;
}
}
A = A + a;
//###################################
//############TONE BEEP##############
//###################################
a = 1;
for (b = 1; b <=100; b++){
for (k = 1; k <=360; k++){
k = k + 3;
I = 0x00000000;
param = 0.1 + k;
results = sin(param *PI/180) * 100;
result = (int) results;
printf("%dsintest\n",result);
for (i = 1; i <= abs(result); i++){
I = I - j * result / abs(result);
}
printf("%08Xhexchange\n",I);
map[a + A] = I;
a = a + 1;
}
}
//###################################
//############TONE BEEP##############
//###################################
    printf("%x\n",map[0]);
    munmap(map, size);
    close(fd);
    return 0;
}
    
