#pragma once
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <X11/X.h>
#include <X11/Xatom.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/Xrender.h>
#include <math.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <iostream>
#include <vector>

#define USE_CHOOSE_FBCONFIG

class app_base {
public:
    app_base();
    Window main_window() const;
    float aspect_ratio() const;
    int run();
    virtual bool init();

private:
    int init_context();
    int init_main_window();
    int update_message_queue();

    virtual void mouse_down(XButtonEvent btn, int x, int y) = 0;
    virtual void mouse_up(XButtonEvent btn, int x, int y) = 0;
    virtual void mouse_move(int x, int y) = 0;
    void tick() = 0;

    bool appPaused;
    bool minimized;
    bool maximized;
    bool resizing;

    GameTimer timer;

    int m_Xscreen;
    Atom m_del_atom;
    Colormap m_cmap;
    Display *m_Xdisplay;
    XVisualInfo *m_visual;
    XRenderPictFormat *m_pict_format;
    GLXFBConfig *m_fbconfigs, m_fbconfig;
    int m_numfbconfigs;
    GLXContext m_render_context;
    Window m_Xroot, m_window_handle;
    GLXWindow m_glX_window_handle;
    int m_width, m_height;
};

