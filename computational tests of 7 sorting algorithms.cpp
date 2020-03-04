/*
This code can be compiled and run ok.

This is to sort numbers through 7 different sorting algorithm 

usage:
	d44051208 input results
	where input is the input txt filename, results is the txt format filename
input file:
	input.txt : input is_p, n, a_min, a_max, rs 
output files:
	results.txt : records the algorithm time
compile:
	g++ -o d44051208 d44051208.cpp
	./run_all.bat
pseudocode:
func IS(A,n):
for i (from 2 to n)
 do key <- A[i]
    k <- i-1
    while k>=0 and A[k]<key
        do A[k+1]<-A[k]
            k-1
    A[k+1]<-key
------------------------------
func Merge(A,l,m,r):
 n1<-m-1+1
 n2<-r-m
 L<-new array[n1]
 R<-new array[n2]
 for i(from 1 to n1)
    do L[i]<-A[l+i-1]
 for j(from 1 to n2)
    do R[j]<-A[m+j]
 i<-0
 j<-0
 k<-1
 while i<n1 and j<n2
    do if L[i]>=R[j]
        then A[k]<-L[i]
            i+1
        else A[k]<-R[j]
            j++
    k++
 while i<n1
    do A[k]<-L[i]
        i+1
        k+1
 while j<n2
    do A[k]<-R[j]
        j+1
        k+1
 ------------------------------
 func MS(A,l,r):
 if l<r
    then m<-floor((l+r)/2)
        MS(A,l,m)
        MS(A,m+1,r)
        Merge(A,l,m,r)
------------------------------
func Min_Heapify(A,n,i):
 smallest<-i
 l<-2*i+1
 r<-2*i+2
 if l<n and A[l]<A[smallest]
    then smallest<-l
 if r<n and A[r]<A[smallest]
    then smallest<-r
 if smallest != i
    then swap(A[i],A[smallest])
        Min_Heapify(A,n,smallest)
------------------------------
func HS(A,n):
 for i(from n/2-1 to 0)
    do Min_Heapify(A,n,i)
 for i(from n-1 to 0)
    do swap(A[1],A[i+1]
        Min_Heapify(A,i,0)
------------------------------
func Partition(A,a,b):
 c<-A[b]
 i<-a-1
 for j(from a to b)
    do if A[j]>c
        i+1
        swap(A[i],A[j])
 swap(A[i+1],A[b])
 return i+1
------------------------------
func QS(A,a,b):
if b>a
 then c<-Partition(A,a,b)
    QS(A,a,c-1)
    QS(A,c+1,b)
------------------------------
func CS(A,n):
 Max<-Get_Max(A,n)
 Min<-Get_Min(A,n)
 range<-Max-Min+1
 B<-new array[n]
 Count<-new array[range]
 for i(from 1 to range)
    do Count[i]<-0
 for j(from 1 to n)
    do Count[A[j]-Min]+1
 for i(from range-1 to 0)
    do Count[i]<-Count[i]+Count[i+1]
 for j(from size to 0)
    do B[Count[A[j]-Min]<-A[j]
        Count[A[j]-Min]-1
 for i(from 1 to n)
    do A[i]<-B[i]
------------------------------
func CountSort(A,n,i):
 output<-new[n]
 max<-10
 count<-new[max]
 for i(from 1 to max)
    do count[i]<-0
 for i(from 0 to n)
    do Count[(A[i]/i)%10]+1
 for i(from max-1 to 0)
    do count[i]+=count[i+1]
 for i(from n to 0)
    do output[count[(A[i]/i)%10]<-A[i]
        count[(A[i]/i)%10]-1
 for i(from 0 to n)
    do A[i]<-output[i]
------------------------------
func RS(A,n):
 Max<-Get_Max(A,n)
 for i(from 1 to Max/i i*=10)
    do CounSort(A,n,i)
------------------------------
func BS(A,n):
 Min<-Get_Min(A,n)
 Max<-Get_Max(A,n)
 Length<-Max-Min+1
 bucket<-new vector[length]
 for i(from 1 to Length)
    do bucket[i]<-vector[]
 for i(from 1 to n)
    do bucket[A[i]-Min].push_back(A[i])
 k<-0
 for i(from Length to 0)
    bucketSize<-bucket[i].size()
    if bucketSize>0
        then for j(from bucketSize to 0)
                    A[k]<-bucket[i][j]
                    k++
------------------------------
func Get_Max(A,n):
 max<-A[1]
 for i(from 2 to n)
    do if A[i]>Max
        then Max<-A[i]
 return Max
------------------------------
func Get_Min(A,n)
 Min<-A[1]
 for i(from 2 to n)
    if A[i]<Min
      then Min<-A[i]
 return Min
------------------------------
func duplicate_array(A,B,a,b)
 for i(from a to b)
    do B[i]<-A[i]
------------------------------
func is_A_desc(A,n)
 for i(from 2 to b)
    do if A[i]>A[i-1]
        return 0
 return 1
------------------------------
coded by Chen YU-HSUAN, ID: D44051208, email: yusyuanchen0623@gmail.com
date: 2019/12/22
*/
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <algorithm>
#include <sys/types.h>
#include <sys/times.h>
using namespace std;

void IS(int[], int);
void MS(int[], int, int);
void Merge(int[], int, int, int);
void HS(int[], int);
void Min_Heapify(int[], int, int);
void QS(int[], int, int);
int Partiton(int[], int, int);
void CS(int[], int);
void RS(int[], int);
void CountSort(int[], int, int);
void BS(int[], int);
void duplicate_array(int[], int[], int, int);
int is_A_desc(int[], int);
int Get_Max(int[], int);
int Get_Min(int[], int);
float mytimer();
void printout_array(int[], int);

int main() {
	int is_p, n, a_min, a_max, rs;//n is a natural number
	clock_t t1, t2;//for record the time before and after function
	cout << "Please input is_p n a_min a_max rs" << endl;
	cin >> is_p >> n >> a_min >> a_max >> rs;
	srand(rs);//random seed
	int *A = new int[n];//allocate memory for array A
	for (int i = 0; i < n; i++) {
		A[i] = (rand() % (a_max - a_min + 1)) + a_min;
	}//insert value to array A
	int *B = new int[n];//allocate memory for array B
	if (is_p == 1) {
		printout_array(A, n);
		exit(0);//stop
	}
	duplicate_array(A, B, 0, n);
	t1 = mytimer();
	IS(A, n);
	t2 = mytimer();
	double t_is = (t2 - t1);
	if (is_A_desc(A, n) == 0) {
		cout << "!!INSERTION SORT WRONG!!";
		exit(0);
	}
	duplicate_array(B, A, 0, n);//copy B back to A
	t1 = mytimer();
	MS(A, 0, n - 1);
	t2 = mytimer();
	double t_ms = (t2 - t1);
	if (is_A_desc(A, n) == 0) {
		cout << "!!MERGE SORT WRONG!!";
		exit(0);
	}
	duplicate_array(B, A, 0, n);//copy B back to A
	t1 = mytimer();
	HS(A, n);
	t2 = mytimer();
	double t_hs = (t2 - t1);
	if (is_A_desc(A, n) == 0) {
		cout << "!!HEAP SORT WRONG!!";
		exit(0);
	}
	duplicate_array(B, A, 0, n);//copy B back to A
	t1 = mytimer();
	QS(A, 0, n - 1);
	t2 = mytimer();
	double t_qs = (t2 - t1);
	if (is_A_desc(A, n) == 0) {
		cout << "!!QUICK SORT WRONG!!";
		exit(0);
	}
	duplicate_array(B, A, 0, n);//copy B back to A
	t1 = mytimer();
	CS(A, n);//CS(A,n)
	t2 = mytimer();
	double t_cs = (t2 - t1);
	if (is_A_desc(A, n) == 0) {
		cout << "!!COUNTING SORT WRONG!!";
		exit(0);
	}
	duplicate_array(B, A, 0, n);//copy B back to A
	t1 = mytimer();
	RS(A, n);
	t2 = mytimer();
	double t_rs = (t2 - t1);
	if (is_A_desc(A, n) == 0) {
		cout << "!!RADIX SORT WRONG!!";
		exit(0);
	}
	duplicate_array(B, A, 0, n);//copy B back to A
	t1 = mytimer();
	BS(A, n);
	t2 = mytimer();
	double t_bs = (t2 - t1);
	if (is_A_desc(A, n) == 0) {
		cout << "!!BUCKET SORT WRONG!!";
		exit(0);
	}
	cout << n << " " << a_min << " " << a_max << " " << rs << " "<<fixed << setprecision(2) << t_is <<" " << t_ms <<" " << t_hs<<" " << t_qs<<" " << t_cs <<" " << t_rs <<" " << t_bs << endl;
	delete[] A;
	delete[] B;
	return 0;
}


void IS(int Arr[], int b) {
	int key, k;
	for (int i = 1; i < b; i++) {
		key = Arr[i];
		k = i - 1;
		while (k >= 0 && Arr[k] < key) {
			Arr[k + 1] = Arr[k];
			k--;//continue comparison
		}
		Arr[k + 1] = key;
	}
}

void Merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int *L = new int[n1];
	int *R = new int[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] >= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void MS(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = (int)floor(l + (r - l) / 2);
		MS(arr, l, m);
		MS(arr, m + 1, r);
		Merge(arr, l, m, r);
	}
}


void Min_Heapify(int arr[], int n, int i)
{
	int smallest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && arr[l] < arr[smallest])
		smallest = l;
	if (r < n && arr[r] < arr[smallest])
		smallest = r;
	if (smallest != i) {
		swap(arr[i], arr[smallest]);
		Min_Heapify(arr, n, smallest);
	}
}

void HS(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		Min_Heapify(arr, n, i);
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		Min_Heapify(arr, i, 0);
	}
}

int Partiton(int Arr[], int beg, int end) {
	int pivot = Arr[end];
	int i = beg - 1;
	for (int j = beg; j < end; j++) {
		if (Arr[j] > pivot) {
			i++;
			swap(Arr[i], Arr[j]);
		}
	}
	swap(Arr[i + 1], Arr[end]);
	return i + 1;
}

void QS(int Arr[], int beg, int end) {
	if (end > beg) {
		int pivot = Partiton(Arr, beg, end);
		QS(Arr, beg, pivot - 1);
		QS(Arr, pivot + 1, end);
	}
}
void CS(int Arr[], int size) {
	int Max = Get_Max(Arr, size);
	int Min = Get_Min(Arr, size);
	int range = Max - Min + 1;
	int *A = new int[size];//array sorted
	int *Count = new int[range];//count
	for (int i = 0; i < range; i++) {
		Count[i] = 0;
	}//create a Count-array to count
	for (int j = 0; j < size; j++) {
		Count[Arr[j] - Min]++;
	}
	for (int i = range - 2; i >= 0; i--) {
		Count[i] = Count[i] + Count[i + 1];
	}//accumulation
	for (int j = size - 1; j >= 0; j--) {
		A[Count[Arr[j] - Min] - 1] = Arr[j];//memory problem
		Count[Arr[j] - Min]--;
	}//sorting
	for (int i = 0; i < size; i++) {
		Arr[i] = A[i];
	}
	delete[]A;
	delete[]Count;
}

void CountSort(int Arr[], int n, int exp)
{
	int *output = new int[n];
	int max = 10;
	int *count = new int[max];
	for (int i = 0; i < max; i++) {
		count[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		count[(Arr[i] / exp) % 10]++;
	}
	for (int i = max - 2; i >= 0; i--) {
		count[i] += count[i + 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		output[count[(Arr[i] / exp) % 10] - 1] = Arr[i];
		count[(Arr[i] / exp) % 10]--;
	}
	for (int i = 0; i < n; i++) {
		Arr[i] = output[i];
	}
	delete[]output;
	delete[]count;
}
void RS(int arr[], int n)
{
	int Max = Get_Max(arr, n);
	for (int exp = 1; Max / exp > 0; exp *= 10)
		CountSort(arr, n, exp);
}


void BS(int Arr[], int n)
{
	int Min = Get_Min(Arr, n);
	int Max = Get_Max(Arr, n);
	int bucketLength = Max - Min + 1;
	vector<int>* bucket = new vector<int>[bucketLength];
	for (int i = 0; i < bucketLength; i++) {
		bucket[i] = vector<int>();
	}
	for (int i = 0; i < n; i++) {
		bucket[Arr[i] - Min].push_back(Arr[i]);
	}
	int k = 0;
	for (int i = bucketLength - 1; i >= 0; i--) {
		int bucketSize = bucket[i].size();
		if (bucketSize > 0) {
			for (int j = bucketSize - 1; j >= 0; j--) {
				Arr[k] = bucket[i][j];
				k++;
			}
		}
	}
	bucket->clear();
}

int Get_Max(int Arr[], int a) {
	int Max = Arr[0];
	for (int i = 1; i < a; i++) {
		if (Arr[i] > Max) {
			Max = Arr[i];
		}
	}
	return Max;
}

int Get_Min(int Arr[], int a) {
	int Min = Arr[0];
	for (int i = 1; i < a; i++) {
		if (Arr[i] < Min) {
			Min = Arr[i];
		}
	}
	return Min;
}

void duplicate_array(int Arr_1[], int Arr_2[], int a, int b) {
	for (int i = a; i < b; i++) {
		Arr_2[i] = Arr_1[i];
	}
}
int is_A_desc(int Arr[], int b) {
	for (int i = 1; i < b; i++) {
		if (Arr[i] > Arr[i - 1]) {
			return 0;
		}
		else continue;
	}
	return 1;
}
void printout_array(int Arr[], int b) {
	for (int i = 0; i < b; i++) {
		cout << Arr[i] << " ";
	}
	cout << endl;
}
float mytimer()
{
	struct tms hold;

	times(&hold);
	/*return  (float)(hold.tms_utime) / 60.0;*/
	return  (float)(hold.tms_utime);
}
