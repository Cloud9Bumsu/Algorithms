//2018112085 박범수 Week3 Q1
#include <iostream> 

int sorted[10]; // 정렬된 배열 

using namespace std;

void merge(int* data, int start, int mid, int end)
{
	int i = start;
	int j = mid + 1;
	int k = start;
	while (i <= mid && j <= end)
	{
		if (data[i] <= data[j])
		{
			sorted[k] = data[i];
			i++;
		}
		else
		{ // data[i] > data[j] 
			sorted[k] = data[j];
			j++;
		}
		k++;
	}
	if (i > mid)
	{
		for (int t = j; t <= end; t++)
		{
			sorted[k] = data[t];
			k++;
		}
	}
	else
	{
		for (int t = i; t <= mid; t++)
		{
			sorted[k] = data[t];
			k++;
		}
	}
	// 정렬된 배열을 삽입 
	for (int t = start; t <= end; t++)
	{
		data[t] = sorted[t];
	}
}

void merge_sort(int* data, int start, int end)
{
	int n = end - start;
	int data_length=n+1;
	for (int i = 1; i < n; i = 2 * i) {
		int Left = 0;
		while (Left <= n) {
			int Right = Left + 2 * i - 1;
			if (Right > n) Right = n;
			int Mid = Left+i-1;	
			
			if (Mid <= data_length)
			{
				cout << "merge 인자들" << endl;
				cout << Left <<" "<< Mid<< " "<< Right << endl;
				merge(data, Left, Mid, Right);
			}
			Left = Right + 1;
			for (int i = 0; i < 10; i++)
			{
				cout << sorted[i] << " ";
			}
			cout << endl;
		}
	}



		
	
}

int main(void) {
	int data[10] = { 30,20,40,35,5,50,45,10,25,15 };
	merge_sort(data, 0, 9); // 결과 확인 

	cout << endl;
	cout << "최종: ";
	for (int i = 0; i < 10; i++)
	{
		cout << data[i] << " ";
	}
	return 0;
}