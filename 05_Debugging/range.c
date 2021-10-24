#include <stdio.h>

int main(int argc, char* argv[]) {
    int start = 0;
	int end = 1;
	int step = 1;
	if (argc == 1) {
    	printf("%s",
            "usage: range [start] [end] [step]\n"
            "start: range start\n"
            "end: range end\n"
            "step: range step\n"
            "output depends on the number of arguments:\n"
            "\t1: [0, 1, ..., end-1]\n"
            "\t2: [start, start+1, ..., end-1]\n"
            "\t3: [start, start+step, ..., end-1]\n"
    	);
    	return 0;
    }
    else if (argc == 2) {
     	sscanf(argv[1], "%d", &end);
    }
    else {
		sscanf(argv[1], "%d", &start);
		sscanf(argv[2], "%d", &end);
     	if (argc == 4) {
     		sscanf(argv[3], "%d", &step);
     	}
     	if (!step || start < end && step < 0)
     		return 0;
    }
    for (int i = start; i < end; i += step)
    	printf("%d\n", i);
}
