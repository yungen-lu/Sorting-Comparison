QuickSortMain: QuickSort/main.c QuickSort.o util.o
	gcc QuickSort/main.c QuickSort.o util.o -o QuickSortMain
MergeSortMain: MergeSort/main.c MergeSort.o util.o
	gcc MergeSort/main.c MergeSort.o util.o -o MergeSortMain
RadixSortMain: RadixSort/main.c RadixSort.o util.o
	gcc RadixSort/main.c RadixSort.o util.o -g -o RadixSortMain
HeapSortMain: HeapSort/main.c HeapSort.o util.o
	gcc HeapSort/main.c HeapSort.o util.o -g -o HeapSortMain
GenRandMain: GenRand/main.c util.o
	gcc GenRand/main.c util.o -o GenRandMain
QuickSort.o: QuickSort/QuickSort.c QuickSort/QuickSort-H.h
	gcc -c QuickSort/QuickSort.c -o QuickSort.o

MergeSort.o: MergeSort/MergeSort.c MergeSort/MergeSort-H.h
	gcc -c MergeSort/MergeSort.c -o MergeSort.o 

RadixSort.o: RadixSort/RadixSort.c RadixSort/RadixSort-H.h
	gcc -c RadixSort/RadixSort.c -g -o RadixSort.o

HeapSort.o: HeapSort/HeapSort.c HeapSort/HeapSort-H.h
	gcc -c HeapSort/HeapSort.c -g -o HeapSort.o

util.o: util/util.c util/util.h
	gcc -c util/util.c -g -o util.o

cleanU:
	rm -f util.o
cleanQ: 
	rm -f QuickSort.o QuickSortMain

cleanM:
	rm -f MergeSort.o MergeSortMain

cleanR:
	rm -f RadixSort.o RadixSortMain

cleanH:
	rm -f HeapSort.o HeapSortMain
cleanRand:
	rm -f GenRandMain
cleanALL: cleanU cleanQ cleanM cleanR cleanH cleanRand
	find . -name "*.txt" -type f -delete
	find . -name "*.dSYM" -type f -delete
