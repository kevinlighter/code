# files = graphImp.cpp graphBase.cpp graphBase.h undirect_graph.h\
# undirect_graph.cpp direct_graph.h direct_graph.cpp

files = *.cpp

#files := $(wildcard *.cpp) $(wildcard *.h)

main: $(files)
	g++ -std=c++17 -o main $(files) -I.

.PHONY:clean
	clean:
	-rm edit $(files)