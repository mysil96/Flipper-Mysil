#pragma once
#include <furi.h>
#include <toolbox/api_lock.h>
#include <flipper_application/flipper_application.h>
#include "loader.h"
#include "loader_menu.h"
#include "loader_extmainapp.h"
#include "loader_applications.h"

typedef struct {
    char* args;
    FuriThread* thread;
    bool insomniac;
    FlipperApplication* fap;
} LoaderAppData;

struct Loader {
    FuriPubSub* pubsub;
    FuriMessageQueue* queue;
    LoaderMenu* loader_menu;
    LoaderApplications* loader_applications;
    LoaderAppData app;
    ExtMainAppList_t ext_main_apps;
};

typedef enum {
    LoaderMessageTypeStartByName,
    LoaderMessageTypeStartByNameDetachedWithGuiError,
    LoaderMessageTypeAppClosed,
    LoaderMessageTypeShowMenu,
    LoaderMessageTypeShowSettings,
    LoaderMessageTypeMenuClosed,
    LoaderMessageTypeApplicationsClosed,
    LoaderMessageTypeLock,
    LoaderMessageTypeUnlock,
    LoaderMessageTypeIsLocked,
} LoaderMessageType;

typedef struct {
    const char* name;
    const char* args;
    FuriString* error_message;
} LoaderMessageStartByName;

typedef struct {
    LoaderStatus value;
} LoaderMessageLoaderStatusResult;

typedef struct {
    bool value;
} LoaderMessageBoolResult;

typedef struct {
    FuriApiLock api_lock;
    LoaderMessageType type;

    union {
        LoaderMessageStartByName start;
    };

    union {
        LoaderMessageLoaderStatusResult* status_value;
        LoaderMessageBoolResult* bool_value;
    };
} LoaderMessage;
