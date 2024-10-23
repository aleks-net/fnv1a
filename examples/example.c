#include <stdio.h>

#include "../fnv1a32.h"
#include "../fnv1a64.h"

int main(int argc, char* argv[]) {
	printf("C Example\n");

	printf("fnv1a32_str( \"aleks-net\" ) returns %08x\n", fnv1a32_str("aleks-net"));
	printf("fnv1a64_str( \"aleks-net\" ) returns %016llx\n", fnv1a64_str("aleks-net"));

	return 0;
}