#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_authentification(char * pwd){
    int auth_flag = 0;
    char pwd_buffer[16];

    strcpy(pwd_buffer, pwd);

    if(strcmp(pwd_buffer, "alphorm") == 0) auth_flag = 1;
    if(strcmp(pwd_buffer, "kondah") == 0) auth_flag = 1;
    return auth_flag;
}

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("Usage: %s &lt;password&gt;\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if(check_authentification(argv[1])){
        printf("Access Granted\n");
    }else{
        printf("Access Denied\n");
    }
    return EXIT_SUCCESS;
}
