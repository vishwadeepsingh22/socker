CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		src/socker.o

LIBS =

TARGET =	bin/socker

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
