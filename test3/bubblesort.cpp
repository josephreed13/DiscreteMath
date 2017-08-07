// Bubble Sort algorithm 

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(int arr[], int n) {
	for(int i = 0; i < n-1; i++) {
		for(int j = 0; j < n-i-1; i++) {
			if(arr[j] > arr[j+1]) {
				swap(&arr[j], arr[j + 1]);
			}
		}
	}
}