/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** DLLoader
*/

#pragma once

#ifdef _WIN32
    #include <windows.h>
#else
    #include <dlfcn.h>
#endif
    
#include <functional>
#include <iostream>
#include <memory>
#include <string>


/**
 * @brief Loader class of '.so' files.
 *
 */
template <class T>
class DLLoader {

    /**
     * @brief Return type of the Symbol function.
     *
     */
    typedef T* (*CreateComponentFunc)();

    public:

        /**
         * @brief Load a .so file and get a symbol function.
         *
         * @param libSo Path of the file to load.
         * @param symbol Symbol of the function to call.
         * @return std::shared_ptr<T> Return value of the function symbol.
         */
        static std::shared_ptr<T> load(const std::string& libSo, const std::string& symbol) {

            void* handle = dlopen(libSo.c_str(), RTLD_LAZY);

            if (!handle) {
                std::cerr << "Cannot load library: " << dlerror() << std::endl;
                return nullptr;
            }

            CreateComponentFunc createComponent = (CreateComponentFunc) dlsym(handle, symbol.c_str());

            const char* dlsym_error = dlerror();
            if (dlsym_error) {
                std::cerr << "Cannot load symbol " << symbol << ": " << dlsym_error << std::endl;
                dlclose(handle);
                return nullptr;
            }
            return std::shared_ptr<T>(createComponent());
        }
};
