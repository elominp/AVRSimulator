CXX		= g++

SRCS 		= main.cpp \
	  	  AVRSimulator.cpp

CXX_OBJS 	= $(SRCS:.cpp=.o)

CXXFLAGS	= -std=gnu++14 -I../simavr/simavr/sim -I../simavr/simavr/sim/avr -I../simavr/examples/parts -I../simavr/examples/shared

LDFLAGS 	= -lsimavr -lsimavrparts -lpthread -lelf -lGL -lGLU -lglut -lutil

RM		= rm -r

BIN 		= simulator

all:	$(BIN)

$(BIN):	$(CXX_OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $(BIN)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(BIN)

re:	fclean all

.PHONY:	all clean fclean re

