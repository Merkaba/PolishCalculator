#include <stdio.h>

long long int stack[100];
int counter = 0;

long long int pop(){
    counter--;
    return stack[counter];
}

void push(long long int n){
    stack[counter] = n;
    counter++;
}

void printTop(){
    printf("%lld\n", *(stack + counter - 1));
}

void swapTop(){
    long long int x = pop();
    long long int y = pop();
    push(x);
    push(y);
}

void duplicateTop(){
    push(stack[counter-1]);
}

void checkForOperator(char * c){
    long long int n;
    switch(c[0]){
        case '/':
            n = pop();
            long long int n2;
            n2 = pop();
            push(n2/n);
            break;
        case '*':
            n = pop();
            push(pop() * n);
            break;
        case '+':
            n = pop();
            push(pop() + n);
            break;
        case 'p':
            printTop();
            break;
        case 's':
            swapTop();
            break;
        case 'd':
            duplicateTop();
            break;
        case '-':
            if(c[1] == '\0'){
                n = pop();
                push(pop() - n);
                break;
            }
        default:
            push(atoll(c)); 
    }
}

char * moveToBuffer(char * buffer, char * input, int * inputCounter){
    int counter = 0;
    while(input[*inputCounter]){
        if(input[*inputCounter] == ' ' || input[*inputCounter] == '\n' || input[*inputCounter] == '\0'){
            (*inputCounter)++;
            buffer[counter] = '\0';
            return buffer;
        }
        buffer[counter] = input[*inputCounter];
        counter++;
        (*inputCounter)++;
    }
    return NULL;
}

void clearBuffer(char * buffer){
    strcpy(buffer, "");

}
void polishCalculator(){
    char buffer[100], input[100];
    fgets(input, 100, stdin);
    int inputCounter = 0;
    while(input[inputCounter]){
        moveToBuffer(buffer, input, &inputCounter);
        checkForOperator(buffer);
        clearBuffer(buffer);
    }
}
int main(){
    //push(5);
    //printTop();
    //push(10);
    //printTop();
    //push(15);
    //printTop();
    //printf(" here is pop%d\n", pop());
    //printTop();
    //swapTop();
    //printTop();
    polishCalculator(); 
    /*
    checkForOperator('p');
    checkForOperator('d');
    printf("%d", pop());
    printf("%d", pop());
    printf("%d", pop());
    */
}
