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
    
    filename = "nnapped.bin";
//new crap begin
	stat(filename, &st);
	size = st.st_size;
	printf("size%isize",size);
	numint = size / sizeof(int);	
	printf("ints%iints",numint);

//new crap end
    fd = open(filename, O_RDWR);
    result = lseek(fd, size-1, SEEK_SET);
    result = write(fd, "", 1);
    result = lseek(fd, 0L, SEEK_END);
    printf("%i\n",result);

    map = mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    for (i = 1; i <=numint; ++i) {
//        map[i] = 0x4d6e6e61;
	map[i] = 0x8;
	i = i + 1;
    }
    printf("%x",map[111]);
    munmap(map, size);
    close(fd);
    return 0;
}
