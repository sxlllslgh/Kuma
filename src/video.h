//
// Created by Hui on 2020/5/15.
//

#ifndef KUMA_IO_H
#define KUMA_IO_H

extern "C" {
    #include <libavutil/imgutils.h>
    #include <libavutil/samplefmt.h>
    #include <libavutil/timestamp.h>
    #include <libavformat/avformat.h>
}

#include <boost/gil.hpp>
#include <iostream>
#include <string>

namespace Kuma {
    class Video {
    private:
        std::string videoName = nullptr;
        AVFormatContext *formatContext = nullptr;
        AVCodecContext *videoDecoderContext = nullptr, *audioDecoderContext = nullptr;
        enum AVPixelFormat pix_fmt;
        AVStream *videoStream = nullptr, *audioStream = nullptr;
        int videoStreamIndex = -1, audioStreamIndex = -1;
        int open_codec_context(int *streamIndex, AVCodecContext **decoderContext, AVFormatContext *formatContext, enum AVMediaType type);

    public:
        Video(std::string videoName);
        boost::gil::rgb8_image_t *getFrame(long long frameIndex);
    };
}

#endif //KUMA_IO_H
