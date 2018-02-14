#include <mcheck.h>

__attribute__((constructor))
static void mtrace_init(void) {
	mtrace();
}

__attribute__((destructor))
static void mtrace_exit(void) {
	muntrace();
}

