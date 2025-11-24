CXX = g++
CXXFLAGS = -std=c++20 -Wall -g
SRC = main.cpp Game/game.cpp Game/player.cpp GameAI/brain.cpp Game/enemy.cpp
OUT = a.out

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)

run:
	clear
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)
	./$(OUT)

visual:
	clear
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)
	./$(OUT) -visual

human:
	clear
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)
	./$(OUT) -human

testhuman:
	clear
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)
	./$(OUT) -testhuman

testvisual:
	clear
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)
	./$(OUT) -testvisual