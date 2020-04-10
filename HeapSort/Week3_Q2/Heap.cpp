//2018112085 �ڹ��� Week3 Q2

#include <iostream>

using namespace std;

void Swap(int* A, int* B) {
	int temp = *A;
	*A = *B;
	*B = temp;
}

void makeheap(int* A, int Root, int LastNode) {
	int Parent, LeftSon, RightSon, Son, RootValue;
	// �Է� ��� A[Root+1:LastNode] �� �̹� �� �������� ����
	Parent = Root;
	RootValue = A[Root];
	LeftSon = 2 * Parent + 1;
	RightSon = LeftSon + 1;
	while (LeftSon <= LastNode) {
		if (RightSon <= LastNode && A[LeftSon] < A[RightSon])
			Son = RightSon; // child �� ���� ���� ��� son�� ����
		else Son = LeftSon;

		if (RootValue < A[Son]) {// ��Ʈ������ son���� ������
			A[Parent] = A[Son]; //Son�� ���� �ø�
			Parent = Son;//Son�� parent�� ��
			LeftSon = Parent * 2 + 1;//child �ٽ� ����
			RightSon = LeftSon + 1;	}
		else break;
	}
	A[Parent] = RootValue;	
}

void heapsort(int* A,int n) {
	int i;
	for (i = n / 2; i >= 0; i--)
		makeheap(A, i,  n - 1); // ������ �迭�� heap�� ��ȯ
	for (i = n - 1; i > 0; i--) {
		Swap(&A[0], &A[i]);	//heap�� �ּڰ��� �����ϰ� A[i]�� ��ȯ
		makeheap(A, 0, i - 1);
	}
	
}

void main() {
	int A[] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
	



	for (int i = 10 / 2; i >= 0; i--)
		makeheap(A, i, 10 - 1); // ������ �迭�� heap�� ��ȯ
				
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