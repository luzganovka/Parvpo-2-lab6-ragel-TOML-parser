#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define INI_FILENAME "out/random.ini"
#define PY_GEN_CMD_TEMPLATE "python3 src/ini_generator.py --size %d --output " INI_FILENAME
#define PARSER_CMD "bin/ini_parser " INI_FILENAME


double get_time_diff(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <MIN_size_kb>, <MAX_size_kb>\n", argv[0]);
        return 1;
    }

    int min_size_kb = atoi(argv[1]);
    if (min_size_kb <= 0) {
        fprintf(stderr, "Error: Invalid size.\n");
        return 1;
    }
    int max_size_kb = atoi(argv[2]);
    if (max_size_kb <= 0) {
        fprintf(stderr, "Error: Invalid size.\n");
        return 1;
    }

    char cmd[256];

    for (int size_kb = min_size_kb; size_kb <= max_size_kb; size_kb+=min_size_kb) {
        snprintf(cmd, sizeof(cmd), PY_GEN_CMD_TEMPLATE, size_kb);

        printf("Generating %d KB ini file...\n", size_kb);
        if (system(cmd) != 0) {
            fprintf(stderr, "Failed to generate ini file.\n");
            return 1;
        }

        printf("Running parser...\n");
        struct timespec start, end;
        clock_gettime(CLOCK_MONOTONIC, &start);

        int ret = system(PARSER_CMD);

        clock_gettime(CLOCK_MONOTONIC, &end);

        if (ret != 0) {
            fprintf(stderr, "Parser failed.\n");
            return 1;
        }

        double elapsed = get_time_diff(start, end);
        printf("Done! Parsed %d KB in %.2f ms.\n", size_kb, elapsed * 1e3);
    }

    return 0;
}