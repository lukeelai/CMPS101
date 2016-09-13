def mergeSort(A, low, high):
	#intialize first
    i = 0
    j = 0
    #if array hasn't been touched yet sort starting at index 0
    if i < low and j < low:
        mergeSort( A, 0, len(A) - 1)
    #if first index is lower, keep on sorting
    if low < high:
    	#first block
        for i in range(low, high):
            curr = i
            #second block to compare
            for j in range( i + 1, high + 1):
                if A[j] < A[curr]:
                    curr = j
            if curr != i:
                A[i], A[curr] = A[curr], A[i]      #swap
    #splitting array           
    elif low < high:
        mid = (low + high)//2
        mergeSort(A, low, mid)
        mergeSort(A, mid+1, high)
        merge(A, low, mid, high)
        
def merge(A, low, mid, high):
    #intialize arrays and split them
    left = A[low:mid]
    right = A[mid:high + 1]
    #set the last index of the arrays to be infinity-ish
    left.append(999999999)
    right.append(999999999)
    #magic of merging
    for k in range (low, high + 1):
        if left[i] <= right[j]:
            A[k] = left[i]
            i += 1
        else:
            A[k] = right[j]
            j += 1
#test
import scipy
import timeit
import matplotlib
matplotlib.use("PDF")
import matplotlib.pyplot as plt
import numpy as np

T = np.zeros(1000)
T1 = np.zeros(1000)
T2 = np.zeros(1000)

for n in range(0,999):
    #Best Case
    A = np.arange(n + 1)
    print(A)
    E = timeit.Timer(lambda: mergeSort(A, 0, n ))
    mergeSort(A, 0, n )
    T[n] = (scipy.mean(E.repeat(repeat = 1,number = 1)))
    plt.plot(A[n], T[n], 'ro')

    #Worst Case
    B = np.arange(n + 1)
    B1 = B[::2]
    B2 = B[1::2]
    B3 = np.concatenate((B1, B2), axis = 1)
    F = timeit.Timer(lambda: mergeSort(B3, 0, n ))
    mergeSort(B3, 0, n )
    T1[n] = (scipy.mean(F.repeat(repeat = 1,number = 1)))
    plt.plot(B3[n], T1[n], 'bo')

    #Random Case
    C = np.array(np.random.random_integers(0, n + 1, n + 1))
    G = timeit.Timer(lambda: mergeSort(C, 0, n ))
    mergeSort(C, 0, n )
    T2[n] = (scipy.mean(G.repeat(repeat = 1,number = 1)))
    plt.plot(C[n], T2[n], 'go')

plt.savefig("merge.pdf")
