#include <windows.h>
#include <string>
#include <ostream>
#include <sstream>
#ifdef _WIN32
    #define EXPORT __declspec(dllexport)
#else   
    #define EXPORT
#endif
