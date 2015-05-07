#include <stdio.h>

#define PARENT(i) ((i) >> 1)
#define LEFT(i) ((i) << 1)
#define RIGHT(i) (((i) << 1) + 1)

void max_heapify(int *arr, int i, int heap_size)
{
	int largest = i;
	int left = LEFT(i);
	int right = RIGHT(i);
	int tmp;

	if (left <= heap_size && arr[left] > arr[largest]) {
		largest = left;
	}

	if (right <= heap_size && arr[right] > arr[largest]) {
		largest = right;
	}

	if (largest != i) {
		tmp = arr[largest];
		arr[largest] = arr[i];
		arr[i] = tmp;
		max_heapify(arr, largest, heap_size);
	}
}

void build_max_heap(int *arr, int heap_size)
{
	int i = PARENT(heap_size);

	for (; i >= 1; i--) {
		max_heapify(arr, i, heap_size);
	}
}

void heapsort(int *arr, int heap_size)
{
	int i, tmp;
	build_max_heap(arr, heap_size);

	for (i = heap_size; i >= 2; i--) {
		tmp = arr[1];
		arr[1] = arr[i];
		arr[i] = tmp;
		heap_size--;
		max_heapify(arr, 1, heap_size);
	}

}
