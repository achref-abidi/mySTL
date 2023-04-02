//
// Created by achrefabidi on 01/04/23.
//

#ifndef MYSTL_UTIL_H
#define MYSTL_UTIL_H

#define LOG(func_name, arg) (std::cout << "Called " << func_name << " with " << arg << "." << std::endl)

#ifdef DEBUG
    #ifdef __GNUG__
        #define LOG_TRACE(...) \
            (std::cout << "[TRACE] " << __FILE_NAME__ << "(" << __LINE__ << ") : " \
            << "Called " << __PRETTY_FUNCTION__ << \
            " with argument(s) " << __VA_ARGS__ << "." \
            << std::endl)

    #endif // __GNUG__
#else
    #define LOG_TRACE(args)
#endif // DEBUG

#endif //MYSTL_UTIL_H
