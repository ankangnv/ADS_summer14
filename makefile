project:	clean compileNode compileDisplayhelp compileMLtree compileBinNode compileList compileMBheap compileInsertData compileheap
		g++ Node.o Displayhelp.o MLtree.o BinNode.o List.o MBheap.o InsertData.o heap.o -o heap

clean:		
		-rm -f Node.o Displayhelp.o MLtree.o BinNode.o List.o MBheap.o InsertData.o heap.o heap

compileNode: 	Node.cpp Node.h
		g++ -c Node.cpp

compileDisplayhelp:	Displayhelp.cpp Displayhelp.h
		g++ -c Displayhelp.cpp

compileMLtree:	MLtree.cpp MLtree.h
			g++ -c MLtree.cpp

compileBinNode:	BinNode.cpp BinNode.h
			g++ -c BinNode.cpp

compileList:	List.cpp List.h
		g++ -c List.cpp

compileMBheap:	MBheap.cpp MBheap.h
			g++ -c MBheap.cpp

compileInsertData:	InsertData.cpp InsertData.h
			g++ -c InsertData.cpp

compileheap:	heap.cpp 
		g++ -c heap.cpp

