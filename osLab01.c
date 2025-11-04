#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure to pass data to threads
typedef struct {
    int number;
    unsigned long long result;
} ThreadData;

// Function executed by each thread
void* compute_factorial(void* arg) {
    ThreadData* data = (ThreadData*) arg;
    int n = data->number;
    unsigned long long fact = 1;

    for (int i = 1; i <= n; i++)
        fact *= i;

    data->result = fact;
    return NULL;
}

int main() {
    int a, b, c;

    printf("Enter three positive integers: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3 || a <= 0 || b <= 0 || c <= 0) {
        printf("Invalid input. Please enter three positive integers.\n");
        return 1;
    }

    pthread_t threads[3];
    ThreadData data[3] = { {a, 0}, {b, 0}, {c, 0} };

    // Create three threads
    for (int i = 0; i < 3; i++) {
        if (pthread_create(&threads[i], NULL, compute_factorial, &data[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print results and total sum
    unsigned long long total = 0;
    for (int i = 0; i < 3; i++) {
        printf("Factorial of %d is : %llu\n", data[i].number, data[i].result);
        total += data[i].result;
    }

    printf("The sum of all factorials is: %llu\n", total);

    return 0;
}
