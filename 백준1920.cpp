#include <iostream>
using namespace std;

int Partition(int a[], int start, int end){
	int pivot = a[end];
	int index = start;
	int temp;
	for(int i = start; i < end; i++){
		if(a[i] <= pivot){
			temp = a[i];
			a[i] = a[index];
			a[index] = temp;
			index++;
		}
	}
	temp = a[index];
	a[index] = a[end];
	a[end] = temp;
	
	return index;
}

void qSort(int a[], int start, int end){
	int index;
	
	if(start < end){
		index = Partition(a, start, end);
		qSort(a, start, index - 1);
		qSort(a, index + 1, end);
	}
	else{
		return;
	}
}

int search(int a[], int n, int key){
	int first = 0;
	int last = n - 1;
	int mid;
	
	do{
		mid = (first+last)/2;
		if(a[mid] == key){
			return 1;
		}else if(a[mid] < key){
			first = mid + 1;
		}else{
			last = mid - 1;
		}
	}while(first <= last);
	return 0;
}

int main() {
	int n = 0;
	int m = 0;
	int a[100001] = {0};
	int b[100001] = {0};
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> b[i];
	}
	qSort(a, 0, n-1);
	int result = 0;
	for(int i = 0; i < m; i++){
		result = search(a, n, b[i]);
		cout << result << "\n";
	}
	return 0;
}