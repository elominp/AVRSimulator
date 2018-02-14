CXX		    = g++

SRCS 		= main.cpp \
	  	      AVRSimulator.cpp

CXX_OBJS 	= $(SRCS:.cpp=.o)

CXXFLAGS	+= -std=gnu++14

LDFLAGS 	= -lsimavrparts -lsimavr -lpthread -lelf -lGL -lGLU -lglut -lutil

RM		    = rm -r

BIN 		= simulator

all:	    $(BIN)

$(BIN):	    $(CXX_OBJS)
	        $(CXX) $(CXX_OBJS) $(LDFLAGS) -o $(BIN)

clean:
	        $(RM) $(CXX_OBJS)

fclean:	    clean
	        $(RM) $(BIN)

re:	        fclean all

.PHONY:	    all clean fclean re

