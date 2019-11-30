/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_DLLOADER_HPP
#define CPP_RTYPE_2019_DLLOADER_HPP

#include <iostream>
#include <dlfcn.h>
#include <memory>

namespace rtype::engine::loader {

    /**
     * @brief DLLoader to load shared library
     *
     * @tparam T The type of the class in the shared library
     */
    template<typename T>
    class DLLoader {

        public:
        /**
         * @brief Construct a DLLoader object
         */
        DLLoader() = default;

        /**
         * @brief Destroy a DLLoader object
         */
        ~DLLoader() = default;

        /**
         * @brief Open the shared library
         *
         * @param path The path to the shared library
         * @return true on success
         * @return false on failure
         */
        bool loadLibrary(const std::string &path) {
            _handle = dlopen(path.data(), (RTLD_NOW | RTLD_LAZY));
            if (!_handle)
                return false;
            return true;
        }

        /**
         * @brief Close the handle to stop using the shared library
         *
         * @return true on success
         * @return false on failure
         */
        bool closeLibrary() {
            return dlclose(_handle) != 0;
        }

        /**
         * @brief Load the class in the shared library
         *
         * @return a pointer to the class stored in the shared library
         */
        std::shared_ptr<T> getInstance() {
            using allocClass = std::shared_ptr<T>(*)();

            auto allocator = reinterpret_cast<allocClass>(dlsym(_handle,"allocator"));

            if (!allocator) {
                closeLibrary();
                return nullptr;
            }
            return allocator();
        }

        private:
        /**
         * @brief The handle to access shared library data
         */
        void *_handle;
    };
}

#endif //CPP_RTYPE_2019_DLLOADER_HPP
