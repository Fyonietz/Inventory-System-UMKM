#include "../core/starter.hpp"
#include "pyro.hpp"
#ifdef _WIN32
    #define EXPORT __declspec(dllexport)
#else   
    #define EXPORT
#endif
EXPORT std::string get_local_system_time();
EXPORT int times(struct mg_connection *connection,void *callback);
EXPORT int stock(struct mg_connection *connection,void *callback);
EXPORT int item(struct mg_connection *connection,void *callback);
