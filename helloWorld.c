//
//  helloWorld.c
//  
//
//  Created by Taj Shaik on 6/20/18.
//

#include <stdio.h>
int multiplication(int a, int b){
    return a * b;
}
int main(){
    int mult = multiplication(3,4);
    printf("%d\n", mult);
    printf("Hello World");
    return 0;
}
