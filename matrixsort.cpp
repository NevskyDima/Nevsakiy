//Nevsky Dmitry , 3 seminar,variant 19.
//I had to output matrix rows in ascending order depending on the sum of their elements.
//I had to use "rand()" for random numbers and "define" for sizes of array.

#include <iostream>
using namespace std;
#define m 10
#define n 9
int arr[m][n];

int main()
{
	cout << "Array: " << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = rand() % 100;
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	int arr_buf[100];
	int s_now = 0, s_prev = 0;    // sums
 // Sort cycle
	for (int z = 0; z<m; z++)
	{
		int* ptr_arr = &arr[z][0]; // pointer to the first element of z-th row in the array
		for (int i = z; i < m; i++)
		{
			for (int j = 0; j < n; j++) //calc the sum un the row
			{
				s_prev += *ptr_arr;
				s_now += arr[i][j];
			}
			if (s_prev > s_now) //if the sum is bigger,change
			{
				for (int k = 0; k<n; k++)
				{
					arr_buf[k] = arr[i][k];
					arr[i][k] = *ptr_arr;
					*ptr_arr = arr_buf[k];
					ptr_arr++;
				}
				ptr_arr -= n;
			}
			s_now = 0; //zero the sums
			s_prev = 0;
		}
	}
	//sorted array
	cout << endl << "Sorted array: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}
