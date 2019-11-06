CXX=clang++
CXXFLAGS=-I$(INCLUDE_DIR) -Wall -Wextra -Werror -O2 -std=c++11

SRCS=src/*.cpp
OBJS=$(SRCS:.cpp=.o)

INCLUDE_DIR=./

EXEC=abstractVM

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)
	@echo Program linked

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJS)
	@echo "Objects files deleted"

fclean: clean
	rm -rf $(EXEC)
	@echo "Program deleted"

re: fclean all

.PHONY: clean fclean re all