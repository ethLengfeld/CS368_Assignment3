# Ethan Lengfeld
# 9074020836
CXX=g++
CXXFLAGS = -Wall
EXE = DemoSummarizeGrades

all: demo.o SummarizeGrades.o
	$(CXX) $(CXXFLAGS) -o $(EXE) demo.o SummarizeGrades.o

SummarizeGrades.o: SummarizeGrades.cpp SummarizeGrades.h
	$(CXX) $(CXXFLAGS) -c SummarizeGrades.cpp

demo.o: demo.cpp SummarizeGrades.h
	$(CXX) $(CXXFLAGS) -c demo.cpp

clean:
	-rm demo.o
	-rm SummarizeGrades.o
	-rm DemoSummarizeGrades