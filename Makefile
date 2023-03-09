CXX = g++
CXXFLAGS = -g -Wall
TARGET = add-nbo

.PHONY:
	$(TARGET) clean

$(TARGET): main.cpp
	$(CXX) -o $@ $(CXXFLAGS) main.cpp

clean:
	rm -rf $(TARGET)
