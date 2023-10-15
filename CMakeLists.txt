# The Flutter tooling requires that developers have a version of Visual Studio
# installed that includes CMake 3.14 or later. You should not increase this
# version, as doing so will cause the plugin to fail to compile for some
# customers of the plugin.
cmake_minimum_required(VERSION 3.14)
project(audiodecoder LANGUAGES CXX)

set(audiodecoder_srcs src/audiodecoderbase.cpp src/audiodecoder_c.cpp)
set(audiodecoder_hdrs include/audiodecoderbase.h include/audiodecoder_c.h)

if(WIN32)
    list(APPEND audiodecoder_srcs  src/audiodecodermediafoundation.cpp)
    list(APPEND audiodecoder_hdrs  include/audiodecodermediafoundation.h)
elseif(APPLE)
    list(APPEND audiodecoder_srcs  src/audiodecodercoreaudio.cpp)
    list(APPEND audiodecoder_hdrs  include/audiodecodercoreaudio.h)
else()
    error("This platform is not supported!")
endif()

    
add_library(audiodecoder
    SHARED
    ${audiodecoder_srcs}
)
message(${audiodecoder_srcs})
target_include_directories(audiodecoder PUBLIC include)

if(WIN32)
    set(wmf_libs dxva2.lib evr.lib mf.lib mfplat.lib mfplay.lib mfreadwrite.lib mfuuid.lib)
    target_link_libraries(audiodecoder PRIVATE ${wmf_libs})
elseif(APPLE)
    find_library(AudioToolbox REQUIRED)

else()
    error("This platform is not supported!")
endif()