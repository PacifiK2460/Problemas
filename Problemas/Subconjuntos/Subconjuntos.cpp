#include<bits/stdc++.h> 
using namespace std; 

void combinationUtil(char arr[], char data[], int start, int end, int index, int r) 
{ 
	if (index == r) 
	{ 
		for (int j = 0; j < r; j++)
        { 
			cout << data[j];
        } 
		cout << endl; 
		return; 
	} 

	for (int i = start; i <= end && end - i + 1 >= r - index; i++) 
	{ 
		data[index] = arr[i]; 
		combinationUtil(arr, data, i+1, end, index+1, r); 
	} 
} 

int main() 
{ 
	char arr[] = {'q','w','e','r','t'}; 
	int r = 2;
    char data[r];
	int n = sizeof(arr)/sizeof(arr[0]); 
	combinationUtil(arr,data ,0, n-1,0, r); 
} 