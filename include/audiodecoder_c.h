#pragma once
#include "audiodecoderbase.h"
#ifdef WIN32
#define AD_API __declspec(dllexport)
#else
#define AD_API extern
#endif

typedef  void (*SupportedExtensionCallback)(const char*);
#ifdef __cplusplus
extern "C" {
#endif
    AD_API AudioDecoderBase* newDecoder(const char* fileName);

    AD_API int openDecoder(AudioDecoderBase* decoder);

    AD_API void closeDecoder(AudioDecoderBase* decoder);

    AD_API int seekDecoder(AudioDecoderBase* decoder, int sampleIdx);

    AD_API int readDecoder(AudioDecoderBase* decoder, int size, float* buffer );

    AD_API int decoderGetNumSamples(AudioDecoderBase* decoder );

    AD_API int decoderGetChannels(AudioDecoderBase* decoder);

    AD_API int decoderSampleRate(AudioDecoderBase* decoder);

    AD_API int decoderPositionInSamples(AudioDecoderBase* decoder);

    AD_API void EnumerateSupportedFileExtensionsDecoder(AudioDecoderBase* dec, SupportedExtensionCallback cb);

#ifdef __cplusplus
}
#endif