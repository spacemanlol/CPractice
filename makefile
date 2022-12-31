all:
	g++ arraytest.cpp memoryalign.cpp -o test.exe 
	
arraytest.o: arraytest.cpp
	g++ arraytest.cpp -o
# LESSON - PRE PROCESSOR - it removes header files and pastes in the contents, replace any macros with its value, and creates a .i intermediate file.

arraytest.i: arraytest.cpp
	g++ -E arraytest.cpp -o arraytest.i 
# LESSON - COMPILER - takes the preprocessed file and replaces symbols and creates a .s assembly file
arraytest.s: arraytest.i
	g++ -S arraytest.i -o arraytest.s
# LESSON - ASSEMBLER - takes the assembler file .s files and creates a .o object file 
arraytest.o: arraytest.s
	g++ -c arraytest.s -o arraytest.o
#LESSON - LINKER - takes all the object files and library files and creates a final executable file or library files
memoryalign.i: memoryalign.cpp
	g++ -E memoryalign.cpp -o memoryalign.i
memoryalign.s: memoryalign.i
	g++ -S memoryalign.i -o memoryalign.s
memoryalign.o: memoryalign.s
	g++ -c memoryalign.s -o memoryalign.o
arraytest.exe: arraytest.o memoryalign.o
	g++ arraytest.o memoryalign.o -o arraytest.exe
clean:
	rm *.o *.i *.s
