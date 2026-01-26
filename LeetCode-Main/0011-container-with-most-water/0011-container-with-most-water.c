#include <stdio.h>
#include <stdlib.h>
int* input_array(int size) {
    int* array = (int*)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i=0; i<size; i++) {
        scanf("%d",&array[i]);
    }
    return array;
}
int maxArea(int* height, int heightSize) {
    int max =0;
    int left =0;
    int right = heightSize -1;
    while (left < right) {
        int h = height[right] > height[left] ? height[left] : height[right];
        int temp = h*(right-left); 
        if (max < temp) { 
            max = temp; 
        }
        if (height[right]>height[left]) {
            left++;
        }
        else {
            right--;
        }
    }
    return max;
}
void main() {
    int size;
    scanf ("%d",&size);
    int* array = input_array(size);
    printf("%d",maxArea(array,size));
    free(array);
}