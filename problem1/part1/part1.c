#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>

int main(){

int pid = fork();
if(pid == 0){
// child process
struct timeval tim;
printf("Child process\n");
for(;;){
gettimeofday(&tim, NULL);
printf("In child process: pid = %d, time of the day = %ld\n", getpid(), tim.tv_sec);
sleep(1);
}

} else if(pid > 0) {
// parent process
sleep(5);
kill(pid, SIGTERM);
printf("Child %d killed\n", pid);
} else {
// fork failed
printf("Creating child process failed\n");
}

return 0;
}
