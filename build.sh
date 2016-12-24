rm *.o
g++ -c BitWriter.cpp -std=c++11
g++ -c CharCount.cpp -std=c++11
g++ -c Heap.cpp -std=c++11
g++ -c HuffTree.cpp -std=c++11
g++ -c Node.cpp -std=c++11
g++ -c PriorityQueue.cpp -std=c++11
g++ -c stdafx.cpp -std=c++11
g++ -c Compress.cpp -std=c++11
g++ -c BitReader.cpp -std=c++11
g++ -c Uncompress.cpp -std=c++11
g++ BitWriter.o CharCount.o Heap.o HuffTree.o Node.o PriorityQueue.o stdafx.o Compress.o -o compress
g++ BitReader.o CharCount.o Heap.o HuffTree.o Node.o PriorityQueue.o stdafx.o Uncompress.o -o expand
