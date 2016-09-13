def InsertionSort(A):
	for j in range(1, len(A)):
		key = A[j]
		#insert A[j] into sorted sequence A[1...j - 1]
		i = j - 1
		while i >= 0 and A[i] > key:
			A[i + 1] = A[i]
			i = i - 1
		A[i + 1] = key

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
for n in range(0, 999):
	#Best Case
	A = np.arange(n + 1)
	E = timeit.Timer(lambda: InsertionSort(A))
	InsertionSort(A)
	T[n] = (scipy.mean(E.repeat(repeat = 10,number = 1)))
	plt.plot(A[n], T[n], 'ro')

	#Worst Case
	A1 = A[::-1]			#reverse
	F = timeit.Timer(lambda: InsertionSort(A1))
	InsertionSort(A1)
	T1[n] = (scipy.mean(F.repeat(repeat = 10,number = 1)))
	plt.plot(A1[n], T1[n], 'bo')

	#Random Case
	C = np.array(np.random.random_integers(0, n + 1 , n + 1))
	G = timeit.Timer(lambda: InsertionSort(C))
	InsertionSort(C)
	T2[n] = (scipy.mean(G.repeat(repeat = 10,number = 1)))
	plt.plot(C[n], T2[n], 'go')

plt.savefig("insertion.pdf")
