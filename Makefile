#!make -f

CXX=clang++-9
CXXVERSION=c++2a
CXXFLAGS=-std=$(CXXVERSION) -Werror -Wsign-conversion
TIDY_FLAGS=-extra-arg=-std=$(CXXVERSION) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-*
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

SOURCES=Game.cpp Team.cpp Leauge.cpp Schedule.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))


run: demo
	./demo

demo: Demo.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo


test: TestCounter.o Test.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o demo test


