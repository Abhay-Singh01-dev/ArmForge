#ifndef ARMFORGE_CONFIG_H_
#define ARMFORGE_CONFIG_H_

#define ARMFORGE_VERSION_MAJOR 0
#define ARMFORGE_VERSION_MINOR 1
#define ARMFORGE_VERSION_PATCH 0

#if defined(_WIN32) && defined(ARMFORGE_BUILDING_LIBRARY)
#define ARMFORGE_API __declspec(dllexport)
#elif defined(_WIN32)
#define ARMFORGE_API __declspec(dllimport)
#else
#define ARMFORGE_API
#endif

#define ARMFORGE_VERSION_STRING "0.1.0"

#endif  // ARMFORGE_CONFIG_H_

