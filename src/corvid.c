#include <stdio.h>
#include <stdlib.h>

enum corvid { magpie, raven, jay, chough, corvid_num, };
#define FLOCK_MAGPIE ( 1U << magpie )
#define FLOCK_RAVEN ( 1U << raven )
#define FLOCK_JAY ( 1U << jay )
#define FLOCK_CHOUGH ( 1U << chough )
#define FLOCK_EMPTY 0U
#define FLOCK_FULL ( (1U << corvid_num) - 1 )

int main(void) {
	unsigned flock = FLOCK_EMPTY;
	flock |= FLOCK_CHOUGH;
	// flock |= FLOCK_RAVEN;
	// flock |= FLOCK_JAY;
	// flock |= FLOCK_MAGPIE;
	if (flock&FLOCK_RAVEN) {
		printf("flock = %u\nand has raven\n", flock);
	} else {
		printf("flock = %u\nand has no raven\n", flock);
	}
	return EXIT_SUCCESS;
}
