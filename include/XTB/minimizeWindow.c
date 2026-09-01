#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <unistd.h>

// NOTES: Needs checks for when a window doesn't exist
void minimizeWindow(const char *wid) {
    Display *display = XOpenDisplay((char *) NULL);
    if (!display) {
        fprintf(stderr, "Cannot open display\n");
    }
    int screen = DefaultScreen(display);
    Status status = XIconifyWindow(display, (Window) strtoul(wid,NULL, 0), screen);

    if (status == 0) {
        fprintf(stderr, "Failed to minimize window.\n");
        fprintf(stderr, "(Failed to send iconify request. Window manager may not support it)\n");
    }

    XFlush(display);
    XCloseDisplay(display);
}
