//
// Created by Hui on 2020/5/15.
//

#include "video.h"

/*
Kuma::Video::Video(std::string videoName) : videoName(videoName) {
    try {
        if (avformat_open_input(&formatContext, videoName.c_str(), nullptr, nullptr) < 0) {
            throw "Could not open file \"" + videoName + "\".";
        }
        if (avformat_find_stream_info(formatContext, nullptr) < 0) {
            throw "Could not find stream information.";
        }
        if (open_codec_context(&videoStreamIndex, &videoDecoderContext, formatContext, AVMEDIA_TYPE_VIDEO) >= 0) {
            videoStream = formatContext->streams[videoStreamIndex];

            video_dst_file = fopen(video_dst_filename, "wb");
            if (!video_dst_file) {
                fprintf(stderr, "Could not open destination file %s\n", video_dst_filename);
                ret = 1;
                goto end;
            }

            */
/* allocate image where the decoded image will be put *//*

            width = video_dec_ctx->width;
            height = video_dec_ctx->height;
            pix_fmt = video_dec_ctx->pix_fmt;
            ret = av_image_alloc(video_dst_data, video_dst_linesize,
                                 width, height, pix_fmt, 1);
            if (ret < 0) {
                fprintf(stderr, "Could not allocate raw video buffer\n");
                goto end;
            }
            video_dst_bufsize = ret;
        }
    } catch (std::string& e) {
        std::cerr << e << std::endl;
    }
}

int Kuma::Video::open_codec_context(int *streamIndex, AVCodecContext **decoderContext, enum AVMediaType type) {
    int ret, stream_index;
    AVStream *st;
    AVCodec *dec = NULL;
    AVDictionary *opts = NULL;

    ret = av_find_best_stream(fmt_ctx, type, -1, -1, NULL, 0);
    if (ret < 0) {
        fprintf(stderr, "Could not find %s stream in input file '%s'\n",
                av_get_media_type_string(type), src_filename);
        return ret;
    } else {
        stream_index = ret;
        st = fmt_ctx->streams[stream_index];

        */
/* find decoder for the stream *//*

        dec = avcodec_find_decoder(st->codecpar->codec_id);
        if (!dec) {
            fprintf(stderr, "Failed to find %s codec\n",
                    av_get_media_type_string(type));
            return AVERROR(EINVAL);
        }

        */
/* Allocate a codec context for the decoder *//*

        *dec_ctx = avcodec_alloc_context3(dec);
        if (!*dec_ctx) {
            fprintf(stderr, "Failed to allocate the %s codec context\n",
                    av_get_media_type_string(type));
            return AVERROR(ENOMEM);
        }

        */
/* Copy codec parameters from input stream to output codec context *//*

        if ((ret = avcodec_parameters_to_context(*dec_ctx, st->codecpar)) < 0) {
            fprintf(stderr, "Failed to copy %s codec parameters to decoder context\n",
                    av_get_media_type_string(type));
            return ret;
        }

        */
/* Init the decoders, with or without reference counting *//*

        av_dict_set(&opts, "refcounted_frames", refcount ? "1" : "0", 0);
        if ((ret = avcodec_open2(*dec_ctx, dec, &opts)) < 0) {
            fprintf(stderr, "Failed to open %s codec\n",
                    av_get_media_type_string(type));
            return ret;
        }
        *stream_idx = stream_index;
    }
    return 0;
}
*/
