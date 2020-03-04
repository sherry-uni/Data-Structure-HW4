read an integer is_p (meaing whether to print out A or not), natural number n, a lower bound integer a_min, an upper bound integer a_max, and an integer as the random seed rs
allocate memory for an array A of n integers (here we assume to use A[1],...,A[n], if you want to use A[0],...,A[n-1], please do whatever necessary changes by yourself)
using the random seed rs to generate n random integer numbers which are uniformly distributed in the range [a_min, a_max] , and store these n random integer numbers in A[1],...,A[n].
if is_p=1 then print out A[1],...A[n] and STOP; Otherwise do nothing and CONTINUE
write the following 7 sorting functions
IS(A,n) : do the insertion sort
MS(A,1,n) : do the merge sort
HS(A,n) : do the heap sort
QS(A,1,n) : do the quick sort
CS(A,n,k) : do the counting sort
RS(A,n,k) : do the radix sort
BS(A,n) : do the bucket sort
these five functions all sort the same array A in nonincreasing order (i.e.從大排至小；非從小排至大!！)
your code should also contain the following 4 other functions
printout_array(A,1,n) : to printout the integer 1-D array A (from previous HW, make necesary changes by yourself)
duplicate_array(A,B,1,n) : to duplicate 1-D array A to be array B, where both A & B have dimensions 1xn (from previous HW, make necesary changes by yourself)
is_A_desc(A,n) : to check whether A[i]>=A[j] for any i<j
if it passes the checking, then return "1" and printout "order OK!"; otherwise, return "0" and printout "!!WRONGLY SORTED!!". (from HW4, make necesary changes by yourself)
mytimer() : to return a time tag. please use related files in this example file
To be more specific, your code has to

read [is_p, n, a_min, a_max, rs] from screen
allocate memory for 2 arrays of integers A and B, each with size=n
using rs to generate n random integers uniformly distributed in the range [a_min,a_max], store them in A
if is_p=1 then print out A and STOP
copy A to B (i.e. duplicate A's value into B)
DO INSERTION SORT
execute t1=mytimer(), IS(A,n), execute t2=mytimer(), compute t_is=t2-t1
execute is_A_desc(A,n), if it returns "0" then print out "!!INSERTION SORT WRONG!!" and STOP.
copy B back to A so that A has its original values
DO MERGE SORT
execute t1=mytimer(), MS(A,1,n), execute t2=mytimer(), compute t_ms=t2-t1
execute is_A_desc(A,n), if it returns "0" then print out "!!MERGE SORT WRONG!!" and STOP.
copy B back to A so that A has its original values
DO HEAP SORT
execute t1=mytimer(), HS(A,n), execute t2=mytimer(), compute t_hs=t2-t1
execute is_A_desc(A,n), if it returns "0" then print out "!!HEAP SORT WRONG!!" and STOP.
copy B back to A so that A has its original values
DO QUICK SORT
execute t1=mytimer(), QS(A,1,n), execute t2=mytimer(), compute t_qs=t2-t1
execute is_A_desc(A,n), if it returns "0" then print out "!!QUICK SORT WRONG!!" and STOP.
copy B back to A so that A has its original values
DO COUNTING SORT
execute t1=mytimer(), CS(A,n), execute t2=mytimer(), compute t_cs=t2-t1
execute is_A_desc(A,n), if it returns "0" then print out "!!COUNTING SORT WRONG!!" and STOP.
DO RADIX SORT
execute t1=mytimer(), RS(A,n,k), execute t2=mytimer(), compute t_rs=t2-t1
execute is_A_desc(A,n), if it returns "0" then print out "!!RADIX SORT WRONG!!" and STOP.
DO BUCKET SORT
execute t1=mytimer(), BS(A,n,k), execute t2=mytimer(), compute t_bs=t2-t1
execute is_A_desc(A,n), if it returns "0" then print out "!!BUCKET SORT WRONG!!" and STOP.
printout n, a_min, a_max, rs, t_is, t_ms, t_hs, t_qs, t_cs, t_rs, and t_bs
free all the memories and end the program
Thus, if your code stops in the middle somehwere showing a warning message saying that A is not sorted in nonincreasing order, that must mean your sorting algorithm is wrong. A correct code should successfully sort the same n integers without problems.

Small examples: (suppose your code is compiled with a name "allsort")

allsort (開始執行程式)
Input [is_p,n,a_min,a_max,rs]= 1 10 10 1000 1 (輸入1,10, 10,1000, 1)
783 34 872 546 215 89 965 235 77 284 (輸出10個介於10~1000\的隨機亂整數)
allsort (開始執行程式)
Input [is_p,n,a_min,a_max,rs]= 0 10 10 1000 1 (輸入0,10, 10,1000, 1)
10 10 1000 1 20.1 15.2 14.4 8.9 5.3 7.6 9.7 (輸出 n, a_min, a_max, rs, t_is, t_ms, t_hs, t_qs, t_cs, t_rs, t_bs)

You have to input an n that is large enough (e.g. n=10,000,000, a_min=1, a_max=10,000,000) to make the computational time differentiable. In particular, you have to test the following 9 random [n, a_min, a_max] categories:[10000, 1, 10000]; [10000, 10000,30000]; [10000, 1, 30000]; [50000, 1, 50000]; [50000, 20000, 70000]; [50000, 1, 70000]; [100000, 1, 100000]; [100000, 50000, 150000]; [100000, 1, 150000]; For each category, you should generate 20 random cases, each with a different random seed. After the test, make a table to summarize the average running time (with standard deviation) spent for each algorithm and each category as the following table, where the blank cells should be filled in with the mean time (with stdev) spent by algorithms IS, MS, HS, QS, CS, RS and BS, respectively.
