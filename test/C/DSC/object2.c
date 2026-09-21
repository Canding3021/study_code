#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define QUEUE_SIZE 26

typedef struct {
    char data[QUEUE_SIZE];
    int front;
    int rear;
    int count;
} CircularQueue;

void initQueue(CircularQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isQueueFull(CircularQueue *q) {
    return q->count == QUEUE_SIZE;
}

int isQueueEmpty(CircularQueue *q) {
    return q->count == 0;
}

void enqueue(CircularQueue *q, char ch) {
    if (isQueueFull(q)) {
        return;
    }
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->data[q->rear] = ch;
    q->count++;
}

char dequeue(CircularQueue *q) {
    if (isQueueEmpty(q)) {
        return '\0';
    }
    char ch = q->data[q->front];
    q->front = (q->front + 1) % QUEUE_SIZE;
    q->count--;
    return ch;
}

void buildShiftQueue(CircularQueue *q, int shift) {
    initQueue(q);
    for (int i = 0; i < 26; i++) {
        char ch = 'a' + (i + shift) % 26;
        enqueue(q, ch);
    }
}

char shiftChar(char ch, CircularQueue *q) {
    if (!isalpha(ch)) {
        return ch;
    }
    
    char lower = tolower(ch);
    int originalPos = lower - 'a';
    
    char shifted;
    for (int i = 0; i <= originalPos; i++) {
        shifted = dequeue(q);
        enqueue(q, shifted);
    }
    
    if (isupper(ch)) {
        return toupper(shifted);
    }
    return shifted;
}

char improvedCaesarCipher(char ch, CircularQueue *q, int mode) {
    if (!isalpha(ch)) {
        return ch;
    }
    
    if (mode == 0) {
        return shiftChar(ch, q);
    } else {
        char target = tolower(ch);
        char result;
        
        for (int i = 0; i < 26; i++) {
            char test = dequeue(q);
            enqueue(q, test);
            if (test == target) {
                result = 'a' + i;
                break;
            }
        }
        
        if (isupper(ch)) {
            return toupper(result);
        }
        return result;
    }
}

int main() {
    char text[1000];
    int shift;
    
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    
    printf("Enter shift (1-25): ");
    scanf("%d", &shift);
    
    CircularQueue cipherQueue;
    buildShiftQueue(&cipherQueue, shift);
    
    char encrypted[1000];
    CircularQueue tempQueue;
    
    for (int i = 0; i < strlen(text); i++) {
        encrypted[i] = improvedCaesarCipher(text[i], &cipherQueue, 0);
    }
    encrypted[strlen(text)] = '\0';
    
    printf("Encrypted: %s\n", encrypted);
    
    buildShiftQueue(&cipherQueue, shift);
    char decrypted[1000];
    
    for (int i = 0; i < strlen(encrypted); i++) {
        decrypted[i] = improvedCaesarCipher(encrypted[i], &cipherQueue, 1);
    }
    decrypted[strlen(encrypted)] = '\0';
    
    printf("Decrypted: %s\n", decrypted);
    
    return 0;
}