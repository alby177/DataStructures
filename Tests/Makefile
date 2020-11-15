CC = clang++
CFLAGS = --std=c++11
IDIR = ../
ODIR = obj

TARGETS = GenericContainerTest TestDoubleLinkedList TestStack

_DEPS = DoubleLinkedList.h LinkedList.h GenericContainer.h Stack.h CustomIterator.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

all: $(TARGETS)

$(TARGETS):	%: $(ODIR)/%.o
	$(CC) -o $@ $< $(CFLAGS) $(LIBS)

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: all

clean:
	rm -f $(ODIR)/*.o *~ core $(TARGETS)