#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

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
//        close(fds[READ]);//sending
//        char s[10] = "whakjs";
//        write(fds[WRITE], s, sizeof(s));
//    }
//    else{
//        close(fds[WRITE]);//receiving
//        char s[10];
//        read(fds[READ], s, sizeof(s));
//        printf("parent got [%s]\n", s);
//    }
    if (f){//parent
        close(fds[READ]);//sending to child
        int send[1];
        send[0]=29;
        printf("parent is sending %d\n", send[0]);
        write(fds[WRITE], send, sizeof(send));

        close(fds1[WRITE]);
        int receive[1];
        read(fds1[READ], receive, sizeof(receive));
        printf("parent received %d\n", /*WEXITSTATUS(status),*/ receive[0]);
    }
    else{//child
        close (fds[WRITE]);//reading from parent
        int receive[1];
        read(fds[READ], receive, sizeof(receive));
        printf("child received %d\n", receive[0]);

        receive[0]+=1;
        close(fds1[READ]);//sending to parent
        printf("child is sending %d\n", receive[0]);
        write(fds1[WRITE], receive, sizeof(receive));
    }
    return 0;
}