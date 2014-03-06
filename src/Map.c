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

//some directory mobility start    
    	dirname = "./";
       dp = opendir (dirname);
       if (dp != NULL)
         {
           while (ep = readdir (dp))
             puts (ep->d_name);
//	     fputs (0, ep->d_type);
           (void) closedir (dp);
         }
       else
         perror ("Couldn't open the directory");    
    
    filename = "data/nnapped.bin";
//new crap begin
	stat(filename, &st);
	size = st.st_size;
	printf("size%isize",size);
	numint = size / sizeof(int);	
	printf("ints%iints\n",numint);

//new crap end
    fd = open(filename, O_RDWR);
    result = lseek(fd, size-1, SEEK_SET);
    result = write(fd, "", 1);
    result = lseek(fd, 0L, SEEK_END);
    printf("%i\n",result);
//it now detects file size and maps it to memory, needs tested with all sizes and types of file
    map = mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    printf("%x\n",map[0]);
    for (i = 25; i <=numint; ++i) {
    	map[i] = 0x00000000;
    }
/*
//for (I =  0; I <=numint; ++I) {
    for (i = 25; i <=numint; i++) {
//        map[i] = 0x4d6e6e61;
//	map[i] = 0x12345678;
	map[i] = 0xFFFFFFFF;
//	map[i] = map[0];
	i = i + 200;
    }
//    I = I + 4;
//}
//k = 1;
//for (I =  0; I <=numint; I++) {
    for (i = 25; i <=numint; i++) {
    	map[i] = 0x0F0F0F0F;
	k = 1;
	for (j = 1; j <=10; j++) {
	map[i+j] = 0xFFFFFFFF;
	k = k + 1;
	map[i+j+k] = 0xFFFFFFFF;
	k = k + 1;
	map[i+j+k] = 0xFFFFFFFF;
	k = k + 1;
	map[i+j+k] = 0xFFFFFFFF;
	k = k + 1;
	map[i+j+k] = 0xFFFFFFFF;
	k = k + 1;
	map[i+j+k] = 0xFFFFFFFF;
	k = k + 1;
	map[i+j+k] = 0xFFFFFFFF;
        k = k + 1;
	map[i+j+k] = 0xFFFFFFFF;
        k = k + 1;
	map[i+j+k] = 0xFFFFFFFF;
        k = k + 1;
	map[i+j+k] = 0xFFFFFFFF;
        k = k + 1;
	map[i+j+k] = 0xFFFFFFFF;
        k = k + 1;
	map[i+j+k] = 0xFFFFFFFF;
        k = k + 1;
	map[i+j+k] = 0xFFFFFFFF;
        k = k + 1;
	map[i+j+k] = 0xFFFFFFFF;
        k = k + 1;
//	}
//
//	i = 101 + i;
//    }
//    I = I + 4;
//}
*/
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








j = 0x01010101;
I = 0xAAAAAAAA;
a = 25;


a = 1;
for (b = 1; b <=100; b++){
for (k = 1; k <=360; k++){
k = k + 15;
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

}

j = 0x01010101;
I = 0xAAAAAAAA;
a = 25;


a = 1;
for (b = 1; b <=100; b++){
for (k = 1; k <=360; k++){
k = k + 15;
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

}
A = A + a;

j = 0x01010101;
I = 0xAAAAAAAA;
a = 25;


a = 1;
for (b = 1; b <=100; b++){
for (k = 1; k <=360; k++){
k = k + 15;
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

}
A = A + a;
j = 0x01010101;
I = 0xAAAAAAAA;
a = 25;


a = 1;
for (b = 1; b <=100; b++){
for (k = 1; k <=360; k++){
k = k + 15;
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

}

//for (i = 25; i <= 39; i++) {
//        j = 0x00001100;
//        I = I + j;
//        printf("%x\n",I);
//}



    printf("%x\n",map[0]);
    munmap(map, size);
    close(fd);
    return 0;
}
    
