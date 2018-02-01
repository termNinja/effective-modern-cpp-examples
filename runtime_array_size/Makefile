#
# Makefile
# Nemanja Micovic, 2018-01-24 15:43
#

GOAL = dragon
CXXFLAGS = -Wall -Wextra --std=c++14
CXX = clang++
SRC = $(shell ls | grep cpp)

#dragon: runtime.array.size.cpp
dragon: $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $<

.PHONY: clean

clean:
	@echo 'Cleared project.'
	@rm $(GOAL)

