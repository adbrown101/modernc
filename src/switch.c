#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc + 1]) {
		char bird = argv[1][0];
		switch(bird) {
			case 'm' : puts("this is a magpie");
				break;
			case 'r' : puts("this is a raven");
				break;
			case 'j' : puts("this is a jay");
				break;
			case 'c' : puts("this is a chough");
				break;
			default : puts("this is an unknown corvid");
		}
	return EXIT_SUCCESS;
}
