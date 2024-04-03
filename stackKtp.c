#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct {
    char name[50];
    int age;
} KTP;

KTP stack[MAX_SIZE];
int top = -1;

void push(KTP data);
KTP pop();
void display();
KTP peek();
int isEmpty();

int main() {
    KTP ktp1 = {"Anies Baswedan", 23};
    KTP ktp2 = {"Prabowo Subianto", 61};
    KTP ktp3 = {"Ganjar Pranowo", 16};

    push(ktp1);
    push(ktp2);
    push(ktp3);

    KTP peeked_ktp = peek();
    printf("Peek: \nName: %s, Age: %d\n", peeked_ktp.name, peeked_ktp.age);

    printf("Popped: \n");
    pop();

    printf("Popped: \n");
    pop();

    printf("Popped: \n");
    pop();

    printf("Popped: \n");
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        pop();
    }

    return 0;
}

void push(KTP data) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack overflow. Cannot push %s.\n", data.name);
        return;
    }
    stack[++top] = data;
}

KTP pop() {
    if (isEmpty()) {
        printf("Stack underflow. Cannot pop.\n");
        KTP empty_ktp = {"", 0};
        return empty_ktp;
    }
    KTP popped_ktp = stack[top];
    top--;
    printf("Name: %s, Age: %d\n", popped_ktp.name, popped_ktp.age);
    return popped_ktp;
}

KTP peek() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        KTP empty_ktp = {"", 0};
        return empty_ktp;
    }
    return stack[top];
}

int isEmpty() {
    return top == -1;
}
