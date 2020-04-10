//2018112085 박범수 Week3 Q2

#include <iostream>

using namespace std;

void Swap(int* A, int* B) {
	int temp = *A;
	*A = *B;
	*B = temp;
}

void makeheap(int* A, int Root, int LastNode) {
	int Parent, LeftSon, RightSon, Son, RootValue;
	// 입력 당시 A[Root+1:LastNode] 는 이미 힙 구조임을 가정
	Parent = Root;
	RootValue = A[Root];
	LeftSon = 2 * Parent + 1;
	RightSon = LeftSon + 1;
	while (LeftSon <= LastNode) {
		if (RightSon <= LastNode && A[LeftSon] < A[RightSon])
			Son = RightSon; // child 중 작은 것을 골라 son에 넣음
		else Son = LeftSon;

		if (RootValue < A[Son]) {// 루트값보다 son값이 작으면
			A[Parent] = A[Son]; //Son을 위로 올림
			Parent = Son;//Son이 parent가 됨
			LeftSon = Parent * 2 + 1;//child 다시 지정
			RightSon = LeftSon + 1;	}
		else break;
	}
	A[Parent] = RootValue;	
}

void heapsort(int* A,int n) {
	int i;
	for (i = n / 2; i >= 0; i--)
		makeheap(A, i,  n - 1); // 정렬할 배열을 heap로 변환
	for (i = n - 1; i > 0; i--) {
		Swap(&A[0], &A[i]);	//heap의 최솟값을 제거하고 A[i]와 교환
		makeheap(A, 0, i - 1);
	}
	
}

void main() {
	int A[] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
	



	for (int i = 10 / 2; i >= 0; i--)
		makeheap(A, i, 10 - 1); // 정렬할 배열을 heap로 변환
				
		for (int i = 0; i < 10; i++)
		{
			cout << A[i] << " ";
		}
		cout << endl;
	
	heapsort(A, 10);

	for (int i = 0; i < 10; i++)
	{
		cout << A[i] << " ";
	}
 }