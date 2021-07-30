CC := g++
CFLAGS :=

PROG := main
SRCDIR := src
OUTDIR := build
TARGET := $(OUTDIR)/$(PROG)
SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(addprefix $(OUTDIR)/,$(patsubst %.cpp,%.o,$(SRCS)))

.PHONY: all clean
all: $(TARGET)

# executable file
$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# object files
$(OUTDIR)/%.o: %.cpp
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(CC) $(CFLAGS) -o $@ $^ -c

clean:
	rm -rf $(OUTDIR)
