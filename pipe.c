#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
   int READ = 0;
   int WRITE = 1;

   int fds[2];
   int fds1[2];
   int f;

   pipe(fds);
   pipe(fds1);
   f = fork();// if you pipe after fork, the parent can't talk to its kid bc parent's
   //gonna pipe and child will pipe -- separate

//    if (f==0){
//        close(fds[READ]);
//        char s[10] = "whakjs";
//        write(fds[WRITE], s, sizeof(s));
//    }
//    else{
//        close(fds[WRITE]);
//        char s[10];
//        read(fds[READ], s, sizeof(s));
//        printf("parent got [%s]\n", s);
//    }
    if (f){//parent
        close(fds[READ]);
        int send = 1;
        write(fds[WRITE], send, sizeof(send));

        read(fds1[READ], send, sizeof(send));
        printf("parent got [%s]\n", send);
    }
    else{
        close ()
    }

   return 0;
}