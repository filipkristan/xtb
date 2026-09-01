#include "getFocusedWindowID.h"
#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/Xatom.h>

// NOTES: Add error handling!
char *getFocusedWindowID() {
    Display *display = XOpenDisplay((char *) NULL);
    if (!display) {
        fprintf(stderr, "Cannot open display\n");
    }
    const Window root = DefaultRootWindow(display);
    Atom property = XInternAtom(display, "_NET_ACTIVE_WINDOW", False);
    Atom typeReturn;
    int formatReturn;
    unsigned long nItemsReturn;
    unsigned long bytesLeft;
    unsigned char *data;

    XGetWindowProperty(
        display,
        root,
        property,
        0,
        1,
        False,
        XA_WINDOW,
        &typeReturn,
        &formatReturn,
        &nItemsReturn,
        &bytesLeft,
        &data
    );

    const Window win = ((Window *) data)[0];
    XFree(data);
    XFlush(display);

    static char wid[32];
    // formating using %x returns the hex value instead of the raw id
    snprintf(wid, sizeof(wid), "%x", win); // (IGNORE COMPILER WARNINGS!)
    XCloseDisplay(display);
    return wid;
}
