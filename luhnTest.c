#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <sys/wait.h>

int mygetch(void);

int main(){
    printf("This file will go through testcards.txt through one or more of the codes provided\n");
    printf("Choose J or C at the start if you want the whole file to be ran in either Java or CPP\n");
    
    
    
    printf("Or choose j or c and each card will prompt you for the one you want to run\n");
    printf("Or choose w to exit\n");
    printf("Enter first Character: ");
    char c;
    char number[34];
    char val[16];
    FILE * myfile;
    myfile = fopen("testcards.txt","r");
    char * line;
    ssize_t read;
    size_t len;




    while((c = mygetch()) != 'w'){
        int pid;
        if((read = getline(&line,&len, myfile)) !=EOF)
            goto end;
        if(pid == 0){
            switch(c){
                case 'J':
                    goto J_run;
                    break;
                case 'C':
                    goto C_run;
                    break;
                break;
                case 'j':
                    pid = fork();
                    printf("testing %s in java\n", line);
                    execlp("java",
                        "java",
                            "luhnjava",
                            line,
                            NULL);
                    break;
                case 'c':
                    pid = fork();
                    printf("testing %s in c++\n", line);
                    execlp("./luhncpp","./luhncpp",line,NULL);
                    break;
                default:
                    printf("Invalid character, try again\n");
                    break;
            }
        }else{
        printf("%c inputted\n",c);
        wait(&pid);
        }
        printf("Enter another character\n");
    }
    goto end;
    J_run:
        
        goto end;
    C_run:
    
        goto end;
    end:
        return 0;
    return 0;
}

int mygetch(void){
    int ch;
    struct termios oldt,newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO,TCSANOW, &oldt);

    return ch;

}