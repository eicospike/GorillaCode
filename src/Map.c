#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <dirent.h>
//older pre generated file size can be removed
#define FILEPATH "mmapped.bin"
#define NUMINTS  (1000000)
#define FILESIZE (NUMINTS * sizeof(int))

int main(int argc, char *argv[])
{
    int i, fd, result, dirres, size, numint;
    DIR *dp;
    struct dirent *ep;
    int *map;  
    char *filename, *dirname;
    char *info;
    struct stat st;

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
    for (i = 25; i <=numint; ++i) {
//        map[i] = 0x4d6e6e61;
//	map[i] = 0x12345678;
	map[i] = 0xF0F0F0F0;
//	map[i] = map[0];
	i = i + 200;
    }
    for (i = 25; i <=numint; i++) {
    	map[i] = 0x0F0F0F0F;
	i = i + 401;
    }
    printf("%x\n",map[2]);
    munmap(map, size);
    close(fd);
    return 0;
}
