#include "getWindowTitle.h"
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/Xatom.h>

// NOTES: Add error handling!
char *getWindowTitle(const char *wid) {
    Display *dpy;
    Window root;
    Atom netactivewindow;
    Atom netwmname;
    Atom utf8string;
    Atom real;

    int format;
    unsigned long extra;
    unsigned long n;
    unsigned char *data;

    if (!(dpy = XOpenDisplay(0))) {
        exit(1);
    }

    root = XDefaultRootWindow(dpy);
    netactivewindow = XInternAtom(dpy, "_NET_ACTIVE_WINDOW", False);
    netwmname = XInternAtom(dpy, "_NET_WM_NAME", False);
    utf8string = XInternAtom(dpy, "UTF8_STRING", False);

    if (XGetWindowProperty(dpy, root, netactivewindow, 0, ~0, False, AnyPropertyType, &real, &format, &n, &extra, &data) != Success && data != 0) {
        exit(2);
    }

    unsigned long window = strtoul(wid, NULL, 16);
    XFree(data);

    if (window == 0) {
        exit(0);
    }

    if (XGetWindowProperty(dpy, window, netwmname, 0, ~0, False, utf8string, &real, &format, &n, &extra, &data) != Success || data == 0) {
        XFree(data);
        // fallback
        if (XGetWindowProperty(dpy, window, XA_WM_NAME, 0, ~0, False, AnyPropertyType, &real, &format, &n, &extra, &data) != Success || data == 0) {
            exit(3);
        }
    }

    // printf("WINDOW TITLE: %s\n", data);
    char *out;
    out = strdup((char *) data);
    // snprintf(out,sizeof(out),"%s\n", data );
    XFree(data);
    // printf("WINDOW TITLE: %s\n", out);
    XSync(dpy, False);
    XCloseDisplay(dpy);

    return out;
}
