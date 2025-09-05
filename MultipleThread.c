#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include <pthread.h>

struct thread_data {
    int *array;
    int start;
    int end;
};

void* partial_sum(void* arg) {
    int sum = 0;
    struct thread_data* data = (struct thread_data*)arg;
    for (int i = data->start; i < data->end; i++) {
        sum += data->array[i];
    }

    int* sum_ptr = malloc(sizeof(int));
    *sum_ptr = sum;
    return (void*)sum_ptr;
}

int main() {
    int array[100];
    for (int i = 0; i < 100; i++) {
        array[i] = i + 1;
    }

    struct thread_data data1, data2;
    int n = sizeof(array) / sizeof(array[0]);

    data1.array = array;
    data1.start = 0;
    data1.end = n / 2;

    data2.array = array;
    data2.start = n / 2;
    data2.end = n;

    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, partial_sum, (void*)&data1);
    pthread_create(&thread2, NULL, partial_sum, (void*)&data2);

    void* sum1;
    void* sum2;

    pthread_join(thread1, &sum1);
    pthread_join(thread2, &sum2);

    int* sum_first_half = (int*)sum1;
    int* sum_second_half = (int*)sum2;

    printf("Sum of first half: %d\n", *sum_first_half);
    printf("Sum of second half: %d\n", *sum_second_half);
    printf("Total sum: %d\n", *sum_first_half + *sum_second_half);

    free(sum_first_half);
    free(sum_second_half);

    return 0;
}
