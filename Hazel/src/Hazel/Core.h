#pragma once

// #ifdef HZ_PLATFORM_LINUX
// #ifdef HZ_BUILD_SO
#define HAZEL_API __attribute__((visibility("default")))
// #endif
// #else
// #error :Hazel only support linux!"
// #endif
