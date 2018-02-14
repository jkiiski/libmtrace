#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

static void foo(void *p)
{
	free(p);
}

static void* bar(void)
{
	return malloc(10);
}

static int running;

static void term(int sig)
{
	running = 0;
}

int main(int argc, char **argv)
{
	signal(SIGTERM, term);
	signal(SIGINT, term);

	running = 1;

	while (running) {
		bar();
		foo(bar());
		sleep(1);
	}

	return 0;
}
