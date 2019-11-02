CXX = g++
CXXFLAGS = -Wall
SRCS = PC_machine.cpp Calendar.cpp Clock.cpp ClockCalendar.cpp main.cpp
OBJS = ${SRCS:.cpp=.o}

all: linux

linux: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o main
	chmod +x main
	
PC_machine: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

clock: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

calendar: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

clockCalendar: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

clean:
	rm -rf *.o main