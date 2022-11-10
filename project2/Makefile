all: openhttest orderedhttest

openhttest: openhttest.cpp doublehashentry.cpp doublehashbuild.cpp doublehashentry.hpp doublehashbuild.hpp
	g++ openhttest.cpp doublehashentry.cpp doublehashbuild.cpp -o openhttest

orderedhttest: orderedhttest chainhashentry.hpp chainhashentry.cpp chainhashbuild.hpp chainhashbuild.cpp
	g++ orderedhttest.cpp chainhashentry.cpp chainhashbuild.cpp -o orderedhttest
	
clearn: rm openhttest orderedhttest