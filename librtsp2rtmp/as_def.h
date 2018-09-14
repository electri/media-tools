#ifndef __AS_MEDIA_DEFINE_H__
#define __AS_MEDIA_DEFINE_H__
#if (defined(__WIN32__) || defined(_WIN32)) && !defined(__MINGW32__)
#include "stdafx.h"
#include <winsock2.h>

extern "C" int initializeWinsockIfNecessary();
#else
#include <stdarg.h>
#include <time.h>
#include <sys/time.h>
#include <fcntl.h>
#define initializeWinsockIfNecessary() 1
#endif
#if defined(__WIN32__) || defined(_WIN32) || defined(_QNX4)
#else
#include <signal.h>
#define USE_SIGNALS 1
#endif
#include <stdint.h>
#include <stdio.h>
#include <signal.h>


typedef void*    AS_HANDLE;


enum AS_RTSP_STATUS {
    AS_RTSP_STATUS_INIT       = 0x00,
    AS_RTSP_STATUS_SETUP      = 0x01,
    AS_RTSP_STATUS_PLAY       = 0x02,
    AS_RTSP_STATUS_PAUSE      = 0x03,
    AS_RTSP_STATUS_TEARDOWN   = 0x04,
    AS_RTSP_STATUS_INVALID    = 0xFF,
};

enum AS_RTSP_DATA_TYPE {
    AS_RTSP_DATA_TYPE_VIDEO   = 0x00,
    AS_RTSP_DATA_TYPE_AUDIO   = 0x01,
    AS_RTSP_DATA_TYPE_OTHER   = 0x02,
};


typedef void (*rtsp_status_callback)(AS_HANDLE handle,int status,void* ctx);

typedef struct  {
    rtsp_status_callback f_status_cb;   /*status callback function*/
    void                *ctx;           /*user data*/
}as_rtsp_callback_t;

#endif /*__AS_MEDIA_DEFINE_H__*/
