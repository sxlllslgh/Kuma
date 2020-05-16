cmake_minimum_required(VERSION 3.14)

# Set project name.
project(kuma)

# Set C++ version and CFlags.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-D__STDC_CONSTANT_MACROS")

# Set source directory.
aux_source_directory(src SRC_DIR)

# Create executable file.
add_executable(kuma ${SRC_DIR})

# Link libraries.
# Set link order.
if (NOT LINK_SHARED_FIRST)
    set(CMAKE_FIND_LIBRARY_SUFFIXES .a${CMAKE_FIND_LIBRARY_SUFFIXES})
endif()

# Find and link boost.
find_package(Boost REQUIRED system)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
else()
    message(FATAL_ERROR "Could not find boost.")
    exit()
endif()

# Set include and library directories.
include_directories(${PROJECT_SOURCE_DIR}/include)
set(LIB_PATH ${PROJECT_SOURCE_DIR}/lib)
if (WIN32)
    set(LIB_PATH ${LIB_PATH}/windows)
elseif(APPLE)
    set(LIB_PATH ${LIB_PATH}/macos)
endif ()

# Find and link tensorflow.
if (WIN32)
    if (GPU)
        find_library(LIB_TENSORFLOW tensorflow ${LIB_PATH}/gpu)
    else()
        find_library(LIB_TENSORFLOW tensorflow ${LIB_PATH}/cpu)
    endif ()
elseif(APPLE)
    find_library(LIB_TENSORFLOW tensorflow ${LIB_PATH})
endif ()
target_link_libraries(${PROJECT_NAME} ${LIB_TENSORFLOW})

# Find and link FFmpeg.
set(FFMPEG_LIBS)
if (FFMPEG_SHARED)
    # Find dynamic FFmpeg libraries.
    find_library(LIB_AV_UTIL avutil ${LIB_PATH})
    find_library(LIB_AV_FORMAT avformat ${LIB_PATH})
    find_library(LIB_AV_CODEC avcodec ${LIB_PATH})
    find_library(LIB_SWRESAMPLE swresample ${LIB_PATH})
else()
    # Find static FFmpeg libraries.
    find_library(LIB_AV_UTIL avutil ${LIB_PATH} NO_DEFAULT_PATH)
    find_library(LIB_AV_FORMAT avformat ${LIB_PATH} NO_DEFAULT_PATH)
    find_library(LIB_AV_CODEC avcodec ${LIB_PATH} NO_DEFAULT_PATH)
    find_library(LIB_SWRESAMPLE swresample ${LIB_PATH} NO_DEFAULT_PATH)
endif()
list(APPEND FFMPEG_LIBS ${LIB_AV_UTIL} ${LIB_AV_FORMAT} ${LIB_AV_CODEC} ${LIB_SWRESAMPLE})
# Find system libraries when static link.
if (NOT FFMPEG_SHARED)
    if (WIN32)

    elseif(APPLE)
        # Find Apple system frameworks.
        find_library(APPLE_CORE_FOUNDATION CoreFoundation)
        find_library(APPLE_CORE_MEDIA CoreMedia)
        find_library(APPLE_CORE_VIDEO CoreVideo)
        find_library(APPLE_CORE_SERVICES CoreServices)
        find_library(APPLE_AUDIO_TOOLBOX AudioToolBox)
        find_library(APPLE_VIDEO_TOOLBOX VideoToolBox)
        find_library(APPLE_SECURITY Security)
        list(APPEND FFMPEG_LIBS ${APPLE_CORE_FOUNDATION} ${APPLE_CORE_MEDIA} ${APPLE_CORE_VIDEO} ${APPLE_CORE_SERVICES} ${APPLE_AUDIO_TOOLBOX} ${APPLE_VIDEO_TOOLBOX} ${APPLE_SECURITY})
    endif ()
    # Find other libs.
    find_library(LIB_BZ2 bz2)
    list(APPEND FFMPEG_LIBS ${LIB_BZ2})

    find_library(LIB_OPENCORE_AMR_NB opencore-amrnb)
    find_library(LIB_OPENCORE_AMR_WB opencore-amrwb)
    find_library(LIB_VO_AMR_WB_ENC vo-amrwbenc)
    list(APPEND FFMPEG_LIBS ${LIB_OPENCORE_AMR_NB} ${LIB_OPENCORE_AMR_WB} ${LIB_VO_AMR_WB_ENC})

    find_library(LIB_MOD_PLUG modplug)
    list(APPEND FFMPEG_LIBS ${LIB_MOD_PLUG})

    find_library(LIB_WAV_PACK wavpack)
    list(APPEND FFMPEG_LIBS ${LIB_WAV_PACK})

    find_library(LIB_WEBP webp)
    find_library(LIB_WEBP_MUX webpmux)
    list(APPEND FFMPEG_LIBS ${LIB_WEBP} ${LIB_WEBP_MUX})

    find_library(LIB_OPEN_H264 openh264)
    list(APPEND FFMPEG_LIBS ${LIB_OPEN_H264})

    find_library(LIB_ZVBI zvbi)
    list(APPEND FFMPEG_LIBS ${LIB_ZVBI})

    find_library(LIB_AOM aom)
    list(APPEND FFMPEG_LIBS ${LIB_AOM})

    find_library(LIB_BLURAY bluray)
    list(APPEND FFMPEG_LIBS ${LIB_BLURAY})

    find_library(LIB_Z z)
    list(APPEND FFMPEG_LIBS ${LIB_Z})

    find_library(LIB_DAV1D dav1d)
    list(APPEND FFMPEG_LIBS ${LIB_DAV1D})

    find_library(LIB_GSM gsm)
    list(APPEND FFMPEG_LIBS ${LIB_GSM})

    find_library(LIB_ICONV iconv)
    list(APPEND FFMPEG_LIBS ${LIB_ICONV})

    find_library(LIB_MP3_LAME mp3lame)
    list(APPEND FFMPEG_LIBS ${LIB_MP3_LAME})

    find_library(LIB_INTL intl)
    list(APPEND FFMPEG_LIBS ${LIB_INTL})

    find_library(LIB_LZMA lzma)
    list(APPEND FFMPEG_LIBS ${LIB_LZMA})

    find_library(LIB_OPEN_JPEG openjp2)
    list(APPEND FFMPEG_LIBS ${LIB_OPEN_JPEG})

    find_library(LIB_OPUS opus)
    list(APPEND FFMPEG_LIBS ${LIB_OPUS})

    find_library(LIB_PNG png)
    list(APPEND FFMPEG_LIBS ${LIB_PNG})

    find_library(LIB_SHINE shine)
    list(APPEND FFMPEG_LIBS ${LIB_SHINE})

    find_library(LIB_SNAPPY snappy)
    list(APPEND FFMPEG_LIBS ${LIB_SNAPPY})

    find_library(LIB_SPEEX speex)
    list(APPEND FFMPEG_LIBS ${LIB_SPEEX})

    find_library(LIB_SOXR soxr)
    list(APPEND FFMPEG_LIBS ${LIB_SOXR})

    find_library(LIB_THEORAENC theoraenc)
    list(APPEND FFMPEG_LIBS ${LIB_THEORAENC})

    find_library(LIB_THEORADEC theoradec)
    list(APPEND FFMPEG_LIBS ${LIB_THEORADEC})

    find_library(LIB_TWO_LAME twolame)
    list(APPEND FFMPEG_LIBS ${LIB_TWO_LAME})

    find_library(LIB_VORBIS vorbis)
    list(APPEND FFMPEG_LIBS ${LIB_VORBIS})

    find_library(LIB_VORBIS_ENC vorbisenc)
    list(APPEND FFMPEG_LIBS ${LIB_VORBIS_ENC})

    find_library(LIB_VPX vpx)
    list(APPEND FFMPEG_LIBS ${LIB_VPX})

    find_library(LIB_X264 x264)
    list(APPEND FFMPEG_LIBS ${LIB_X264})

    find_library(LIB_X265 x265)
    list(APPEND FFMPEG_LIBS ${LIB_X265})

    find_library(LIB_XAVS xavs)
    list(APPEND FFMPEG_LIBS ${LIB_XAVS})

    find_library(LIB_XVID_CORE xvidcore)
    list(APPEND FFMPEG_LIBS ${LIB_XVID_CORE})
endif()
target_link_libraries(${PROJECT_NAME} ${FFMPEG_LIBS})
message(${FFMPEG_LIBS})