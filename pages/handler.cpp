#include "handler.hpp"
#include "../act/backend.h"
Pnix Server;
EXPORT std::string get_local_system_time() {
    SYSTEMTIME system_time;
    GetLocalTime(&system_time);

    const char* days[] = {
        "Minggu", "Senin", "Selasa", "Rabu",
        "Kamis", "Jumat", "Sabtu"
    };

    std::ostringstream output_string_stream;
    output_string_stream 
        << days[system_time.wDayOfWeek] << ", "
        << system_time.wDay << "/" << system_time.wMonth << "/" << system_time.wYear << " "
        << (system_time.wHour < 10 ? "0" : "") << system_time.wHour << ":"
        << (system_time.wMinute < 10 ? "0" : "") << system_time.wMinute << ":"
        << (system_time.wSecond < 10 ? "0" : "") << system_time.wSecond;

    return output_string_stream.str();
}

EXPORT int times(struct mg_connection *connection,void *callback){
      std::string time_string = get_local_system_time();

     mg_printf(connection,
              "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\n%s",
              time_string.c_str());
    return 200;
}


EXPORT int stock(struct mg_connection *connection,void *callback){
    Server.SSR("public/views/stock.htpp",connection);
    return 200;
}

EXPORT int item(struct mg_connection *connection,void *callback){
    Server.SSR("public/views/item.htpp",connection);
    return 200;
}