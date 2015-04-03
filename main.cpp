/*
 * Copyright (c) 2011 Reinhard Tartler
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/**
 * @file
 * Shows how the metadata API can be used in application programs.
 * @example metadata.c
 */

#include <stdio.h>
#include <iostream>
#include <string>

extern "C" {
//#include <libavformat/avformat.h>
//#include <libavutil/dict.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
}

using namespace std;
void first_test(const string & filename);

int main (int argc, char **argv)
{





//    AVFormatContext *fmt_ctx = NULL;
//    AVDictionaryEntry *tag = NULL;
//    int ret;
//
//    if (argc != 2) {
//        printf("usage: %s <input_file>\n"
//               "example program to demonstrate the use of the libavformat metadata API.\n"
//               "\n", argv[0]);
//        return 1;
//    }
//
//    av_register_all();
//    if ((ret = avformat_open_input(&fmt_ctx, "/Applications/iMovie.app/Contents/Resources/Trailers/PreviewMovies/Travel/Movie-28.mov", NULL, NULL)))
//        return ret;
//    ret = avformat_open_input(&fmt_ctx, "/Applications/iMovie.app/Contents/Resources/Trailers/PreviewMovies/Travel/Movie-28.mov", NULL, NULL);
//
//    while ((tag = av_dict_get(fmt_ctx->metadata, "", tag, AV_DICT_IGNORE_SUFFIX)))
//        printf("%s=%s\n", tag->key, tag->value);
//
//
//    printf("%d", avformat_version());
//
//    avformat_close_input(&fmt_ctx);

    string file = "/Users/lpsdesk/ClionProjects/testa/test.avi";
    first_test(file);
//    first_test(file);
    return 0;
}
void first_test(const string & filename){

//    char test[];
//    strcpy()= filename;
//    printf("%s", test;
//    cout << filename << endl;
//    int k = filename.size();
//    char *testname = (char*)malloc(filename.size() * sizeof(char));
    const char *testFile = filename.c_str();
    printf("%s", testFile);
//    char                testFile[]     = "/Users/lpsdesk/ClionProjects/testa/test.avi";
    AVFrame             *pFrame         = NULL;
    AVCodecContext      *pCodecCtxOrig  = NULL;
    AVCodecContext      *pCodecCtx      = NULL;

    printf("%s\n", testFile);
    av_register_all();



    AVFormatContext *pFormatCtx = nullptr;
    if (avformat_open_input(&pFormatCtx, testFile, NULL, 0) !=0) {
        fprintf(stderr, "ERROR: Didn't find the file!\n");
        exit(0);
    } else {
        puts("Found the file! Moving on...");
    }

    if(avformat_find_stream_info(pFormatCtx, NULL) <0){
        fprintf(stderr, "Couldn't find the stream information\n");
        exit(-1);
    } else {
        puts("Found the stream info. Moving on...");
    }

//    av_dump_format(pFormatCtx, 0, testFile, 0);

    int i;



    int videoStream = -1;

    for (i=0; i < pFormatCtx->nb_streams; i++){
//            printf("%d\n", i);
        if(pFormatCtx->streams[i]->codec->codec_type==AVMEDIA_TYPE_VIDEO)
        {
            videoStream =i;
        }
    }

    if(videoStream == -1){
        fprintf(stderr, "No video stream found\n");
        exit(1);
    } else {
        puts("Found video Stream. Moving on...");
    }

    pCodecCtxOrig=pFormatCtx->streams[videoStream]->codec;

    AVCodec *pCodec = NULL;

    pCodec=avcodec_find_decoder(pCodecCtxOrig->codec_id);
    if (pCodec== NULL){
        fprintf(stderr, "ERROR: Unsupported Codec!\n");
        exit(-1);
    } else {
        puts("Found the codec type. Moving on...");
    }

    pCodecCtx = avcodec_alloc_context3(pCodec);

    if(avcodec_copy_context(pCodecCtx, pCodecCtxOrig) != 0) {
        fprintf(stderr, "Couldn't copy codec context!\n");
        exit(-1);
    } else {
        puts("Copied codec context.");
    }

    if(avcodec_open2(pCodecCtx, pCodec, NULL)<0){
        fprintf(stderr, "ERROR: Couldn't open the codec!\n");
        exit(-1);

    } else {
        puts("Opened codec. Moving on...");
    }
    pFrame=av_frame_alloc();
}