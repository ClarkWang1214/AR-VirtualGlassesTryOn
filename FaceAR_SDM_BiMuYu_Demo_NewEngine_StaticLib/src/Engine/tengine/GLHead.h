#pragma once

#ifdef WIN32
#include "glew.h"
#elif Linux
#include "glew.h"
#elif IOS
#import <>
#elif Android
#include <GLES3/gl3.h>
#include <GLES3/gl3ext.h>
#endif

