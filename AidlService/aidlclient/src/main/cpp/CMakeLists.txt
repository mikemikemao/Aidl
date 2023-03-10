# Sets the minimum version of CMake required to build the native library.
cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17")

set(jnilibs ${CMAKE_SOURCE_DIR}/../jniLibs)
set(libname hiacs)

include_directories(
        ${CMAKE_SOURCE_DIR}/
        ${common_inc_dir}/
        ${CMAKE_SOURCE_DIR}/utils
        ${CMAKE_SOURCE_DIR}/ipc
)

link_directories(
        ${jnilibs}/${ANDROID_ABI}
)

file(GLOB src-files
        ${CMAKE_SOURCE_DIR}/*.cpp
        ${CMAKE_SOURCE_DIR}/utils/*.cpp
        ${CMAKE_SOURCE_DIR}/ipc/*.cpp
        ${aidl_src_dir}/com/hikvision/aidlservice/*.cpp
        )

add_library( # Sets the name of the library.
        ${libname}
        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        ${src-files}
        )

set(native-libs
        android
        log
        mediandk
        binder_ndk
        m
        z
        )

find_library (
        binder_ndk-lib
        binder_ndk
)

target_link_libraries( # Specifies the target library.
        ${libname}
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib}
        ${native-libs}
        )