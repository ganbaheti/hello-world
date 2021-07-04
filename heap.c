include<iostream>
#include<cmath>

using namespace std;

int find_min_element_index(int a[] , int element , int left_child , int right_child){
	if(a[element] <= a[left_child] && a[element] <= a[right_child])
		return element;

	if(a[left_child] <= a[element] && a[left_child] <= a[right_child])
		return left_child;

	if(a[right_child] <= a[element] && a[right_child] <= a[left_child])
		return right_child;
}

int check_heap(int a[] , int n){

	int second_last_level = (int)log2(n);

	int check_elements_upto_index = pow( 2 , second_last_level+1)-2;
	for(int i=0; i<=check_elements_upto_index; i++){

		if(2*i+1 <= n-1 || 2*i+2 <= n-1){
				if(2*i+1 <= n-1 && 2*i+2 <= n-1){
					if(a[i] <= a[2*i+1] && a[i] <= a[2*i+2])
					 	continue;
					else
						return 0;
				}
				else if(2*i+1 <= n-1){
						if(a[i] <= a[2*i+1])
							continue;
						else
							return 0;
				}
				else{
						if(a[i] <= a[2*i+2])
							continue;
						else
							return 0;
				}
			}
			else{
			   break;
			}
	}
	return 1;
}

void heapify(int a[] , int n){
	int heap_flag = 0;
	while(heap_flag == 0){
		int level = (int)log2(n);
		int ending_index_at_corresponding_level = pow(2 ,level+1)-2;
		for(int i = ending_index_at_corresponding_level;i >= 0 ;i--){
					if(2*i+1 <= n-1 || 2*i+2 <= n-1){
						if(2*i+1 <= n-1 && 2*i+2 <= n-1){
				                    int min_index = find_min_element_index(a , i , 2*i+1 , 2*i+2);
							 		if(min_index == i){
							 			continue;
									}
									else{
										int temp = a[min_index];
										a[min_index] = a[i];
