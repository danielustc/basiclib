ALL:
	g++ -Wall -g sort.cc random.cc quicksort.cc util.cc linklist.cc linklist.h -o sort
test:
	g++ -g test.cc -o test.out
class:
	g++ -g class.cc -o class
