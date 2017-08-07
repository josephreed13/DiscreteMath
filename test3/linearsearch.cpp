// Linear Search algorithm

int linearSearch(int a[], int size, int key){
  
	for(int i=0; i < size; i++){
		if(key == a[i]){
        return i;
		}
	}
	return -1;
}