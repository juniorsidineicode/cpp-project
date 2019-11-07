CXX = g++
CXXFLAGS = -Wall
SRCS = Machine.cpp PC_machine.cpp Calendar.cpp Clock.cpp ClockCalendar.cpp Node.cpp log.cpp main.cpp
OBJS = ${SRCS:.cpp=.o}

all: linux

linux: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o main
	chmod +x main

Machine: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c
	
PC_machine: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

clock: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

calendar: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

clockCalendar: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

Node: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

log: $@.cpp $@.h
	$(CXX) $(CXXFLAGS) $@.cpp -c

clean:
	rm -rf *.o main