CFLAGS += -g
LDFLAGS +=

all: libmtrace.so

libmtrace.so: libmtrace.c
	$(CC) $(CFLAGS) $(LDFLAGS) -shared $< -o $@

test: test.c
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

test-run: test
	MALLOC_TRACE=test.log LD_PRELOAD=./libmtrace.so ./test
	cat test.log

clean:
	rm -f libmtrace.so test test.log
