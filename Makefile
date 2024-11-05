FindXthNodeFromEnd: FindXthNodeFromEnd.o
	g++ -g -o FindXthNodeFromEnd.exe FindXthNodeFromEnd.o -pthread    

FindXthNodeFromEnd.o: FindXthNodeFromEnd/FindXthNodeFromEnd.cpp
	g++ -g  -c -pthread FindXthNodeFromEnd/FindXthNodeFromEnd.cpp
