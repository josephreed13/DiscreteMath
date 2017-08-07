// QuickSort algorithm

void QuickSort(vector<int> &num, int top, int bottom) {
	int middle;
	if(top < bottom) {
		middle = partition(num, top, bottom);
		QuickSort(num, top, middle); 
		QuickSort(num, middle + 1, bottom);
	}
	return;
}

int partition(vector<int> &array, int top, int bottom) {
	int x = array[top];
	int i = top - 1;
	int j = bottom + 1;
	int temp;

	do {
	
		do {
			j--;
		} while(x > array[i]);
	
		do {
			i++;
		} while(x < array[i]);

		if(i < j) {
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	} while(i < j);

	retun j; // returns middle index
}