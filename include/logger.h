/*
** EPITECH PROJECT, 2022
** strace
** File description:
** logger
*/

#pragma once

#ifndef ENV
#define ENV prod
#endif


#if ENV == dev
    #include <stdio.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <unistd.h>

    #ifndef LOGPATH
    #define LOGPATH debug.log
    #endif

    #define STR_VALUE(arg)      #arg
    #define EXPAND(name) STR_VALUE(name)

    #define EXPANDED_LOG_PATH EXPAND(LOGPATH)

    int *s_log_file();
    #define log_file s_log_file()
    void close_logger()
    {
        close(*log_file);
    }

    int *s_log_file()
    {
        static bool registered = false;
        static int inst = 0;
        if (!registered) {
            inst = open(EXPANDED_LOG_PATH, O_WRONLY | O_APPEND | O_CREAT, S_IRWXU| S_IRWXG);
            atexit(close_logger);
            registered = true;
        }
        return &inst;
    }


    #define LOG(msg, ...) \
        dprintf(* log_file, "%s:%d at function %s(): ", __FILE__, __LINE__, __FUNCTION__); \
        dprintf(* log_file, msg __VA_OPT__(,) __VA_ARGS__);\
        dprintf(*log_file, "\n");
        // printf("%s:%d at function %s(): ", __FILE__, __LINE__, __FUNCTION__);
        // printf(msg __VA_OPT__(,)__VA_ARGS__);
        // printf("\n");

#else
    #define LOG(msg, ...)
#endif