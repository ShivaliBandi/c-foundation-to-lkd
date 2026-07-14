#include <stdio.h>      // perror() (optional)
#include <fcntl.h>      // open(), O_RDONLY
#include <unistd.h>     // read(), write(), close()
#include <stdlib.h>     // EXIT_SUCCESS, EXIT_FAILURE (optional)
#include <string.h>
#include<errno.h>
#include<sys/stat.h>
#include<time.h>
int main(int argc,char *argv[])
{

    if(argc!=2)
    {
        printf("SYNTAX: stat <Filename>\nUsage: used to get the metadata of a file\n");
        return -1;
    }
    struct stat sobj;
    if(stat(argv[1],&sobj)==-1)
    {
        perror("ERROR:");
        return -2;
    }
    printf("Stat of %s\nFile type-",argv[1]);
    switch (sobj.st_mode & S_IFMT)
    {
        case S_IFBLK:  printf("block device\n");            break;
        case S_IFCHR:  printf("character device\n");        break;
        case S_IFDIR:  printf("directory\n");               break;
        case S_IFIFO:  printf("FIFO/pipe\n");               break;
        case S_IFLNK:  printf("symlink\n");                 break;
        case S_IFREG:  printf("regular file\n");            break;
        case S_IFSOCK: printf("socket\n");                  break;
        default:       printf("unknown?\n");                break;
    }
    printf("File Size-%ld\n",sobj.st_size);
    printf("Inode number- %ld\n",sobj.st_ino);
    printf("UID-%d GID-%d\n",sobj.st_uid,sobj.st_gid);
    printf("Number of hardlinks-%ld\n",sobj.st_nlink);
    printf("Last status change:       %s", ctime(&sobj.st_ctime));
    printf("Last file access:         %s", ctime(&sobj.st_atime));
    printf("Last file modification:   %s", ctime(&sobj.st_mtime));
    printf("File permission:");
    (sobj.st_mode & S_IRUSR) ? printf("r") : printf("-");
    (sobj.st_mode & S_IWUSR) ? printf("w") : printf("-");
    (sobj.st_mode & S_IXUSR) ? printf("x") : printf("-");
    
    (sobj.st_mode & S_IRGRP) ? printf("r") : printf("-");
    (sobj.st_mode & S_IWGRP) ? printf("w") : printf("-");
    (sobj.st_mode & S_IXGRP) ? printf("x") : printf("-");

    (sobj.st_mode & S_IROTH) ? printf("r") : printf("-");
    (sobj.st_mode & S_IWOTH) ? printf("w") : printf("-");
    (sobj.st_mode & S_IXOTH) ? printf("x") : printf("-");
    printf("\n");
    return 0;
}