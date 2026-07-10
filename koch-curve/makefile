SRC_DIR := ./src

CXX := g++
CXXFLAGS := -g -std=c++20  
LDFLAGS := $(shell pkg-config --cflags --libs raylib) -lm -lX11 -lXrandr -lXi -lXcursor -lXinerama -ldl -lpthread
COMMON_OBJS := main.o line.o generator.o


curve: $(COMMON_OBJS)
	$(CXX) $^ -g -o $@ $(LDFLAGS)

# =====================================================
# COMPILATION RULES
# =====================================================
main.o: main.cpp
	$(CXX) -c $< $(CXXFLAGS)

line.o: ./src/line.cpp ./src/line.hpp
	$(CXX) -c $< $(CXXFLAGS)

generator.o: ./src/generator.cpp ./src/generator.hpp
	$(CXX) -c $< $(CXXFLAGS)

# =====================================================
# UTILITIES
# =====================================================

clean:
	rm -f *.o curve

format:
	find . \( -name "*.cpp" -o -name "*.hpp" \) | \
	xargs clang-format -style=llvm -i

lint:
	cpplint $(shell find . \( -name "*.cpp" -o -name "*.hpp" \))

count:
	find . \( -name "*.cpp" -o -name "*.hpp"  \) | xargs wc -l


.PHONY: clean format lint
