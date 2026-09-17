#include <stdio.h>
#include <string.h>
#include <XTB/xtb.h>

char storage[32][32];

int main() {
    Display *display = XOpenDisplay(NULL);
    if (!display) {
        fprintf(stderr, "Cannot open display\n");
    }
    // Make a list of all running window IDs
    getAllWIDs(storage);
    for (int i = 0; i < sizeof(storage) / sizeof(storage[0]); ++i) {
        if (strcmp(storage[i], "\0") != 0) {
            if (isWindow(storage[i])) {
                // printf("Found window for: %s\n", storage[i]);
                printf("Title: %s\n", getWindowTitle(storage[i]));
            } else {
                printf("Couldn't find window: %s\n", storage[i]);
                printf("%hhd", isWindow(storage[i]));
            }
            // printf("%s\n", getWindowTitle(storage[i]));
            //printf("%s\n", getWindowTitle("0x02200097"));
        }
    }
}
