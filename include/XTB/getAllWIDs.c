#include "getAllWIDs.h"
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <stdio.h>
#include <string.h>

// NOTES: Add error handling!
void getAllWIDs(char storage[][COLS]) {
    Display *display = XOpenDisplay((char *) NULL);
    if (!display) {
        fprintf(stderr, "Cannot open display\n");
    }
    Window root = DefaultRootWindow(display);
    char *atom_name = "_NET_CLIENT_LIST";
    Atom atom_net_client_list;
    Atom type;
    int format;
    unsigned long nItems, remainder;
    unsigned char *list = NULL;
    char data[ROWS][COLS];


    atom_net_client_list = XInternAtom(display, atom_name,True);

    // Checks if your WM/DE supports EWMH
    if (atom_net_client_list == None) {
        fprintf(stderr, "Window manager does not support EWMH (_NET_CLIENT_LIST)\n");
        XCloseDisplay(display);
    }

    // XA_WINDOW is used for x11 to know
    if (XGetWindowProperty(display, root, atom_net_client_list, 0, (~0L),False,XA_WINDOW, &type, &format,
                           &nItems, &remainder, &list) != Success) {
        fprintf(stderr, "Failed to get _NET_CLIENT_LIST property\n");
        XCloseDisplay(display);
    }

    if (list == NULL || nItems == 0) {
        XCloseDisplay(display);
    }

    // NOTE: Unsigned long int must be used instead of int because "Window" is a unsigned long int
    Window *windows = (Window *) list;
    for (unsigned long int i = 0; i < nItems; ++i) {
        // Formats it in a way to turn id to a hex and if its too short it pads 0's to the front
        // printf("0x%08lx\n",  (Window) windows[i]);
        sprintf(storage[i], "0x%08lx", (Window) windows[i]);
        // printf("Window id: %s\n", WindowList[i]);
    }

    // for (int i = 0; i < 7; ++i) {
    //     strcpy(data[i], storage[i]);
    //     printf("Window id: %s\n", storage[i]);
    // }


    XFree(list);
    XCloseDisplay(display);
}
