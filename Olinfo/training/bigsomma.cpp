// Punti: 100.0
#include<stdio.h>
#include<unistd.h>
// #pragma GCC optimize("O2")

#define BUFFER 32768
static char buff[BUFFER];

long long somma(FILE *f){
    int fd = fileno(f), n = 0, c, r = 0;
    
    while((c = read(fd, &r, 1) != 0) && r != '\n') n = n * 10 + (r - '0');
    // printf("%d\n", n);
    register long long sum = 0, tot = 0;
    short flag = 1;
    while(c){
        c = read(fd, buff, BUFFER);
        for(int e=0; e<c; e++){
            if(buff[e] < '0'){
                sum += tot * flag;
                tot = 0;
                flag = -2 * (buff[e] == '-') + 1;
            }
            else{
                tot = tot * 10 + (buff[e] - '0');
            }
        }
    }
    return sum;
}

#ifndef EVAL
int main(){
    printf("%lld\n", somma(stdin));
    return 0;
}
#endif