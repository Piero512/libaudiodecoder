#include "audiodecoder_c.h"
#ifdef WIN32
#include "audiodecodermediafoundation.h"
#elif
#include "audiodecodercoreaudio.h"
#endif


    AD_API AudioDecoderBase* newDecoder(const char* fileName){
        std::string str(fileName);
#ifdef WIN32
        return new AudioDecoderMediaFoundation(fileName);
#elif
        return new AudioDecoderCoreAudio(fileName);
#endif
    }

    AD_API int openDecoder(AudioDecoderBase* decoder){
        return decoder->open();
    }

    AD_API void closeDecoder(AudioDecoderBase* decoder) {
        delete decoder;
    }

    AD_API  int seekDecoder(AudioDecoderBase* decoder, int sampleIdx){
        return decoder->seek(sampleIdx);
    }

    AD_API  int readDecoder(AudioDecoderBase* decoder, int size, float* buffer ){
        return decoder->read(size, buffer);
    }

    AD_API  int decoderGetNumSamples(AudioDecoderBase* decoder ){
        return decoder->numSamples();
    }

    AD_API  int decoderGetChannels(AudioDecoderBase* decoder){
        return decoder->channels();
    }

    AD_API  int decoderSampleRate(AudioDecoderBase* decoder){
        return decoder->sampleRate();
    }

    AD_API  int decoderPositionInSamples(AudioDecoderBase* decoder){
        return decoder->positionInSamples();
    }

    AD_API  void EnumerateSupportedFileExtensionsDecoder(AudioDecoderBase* dec, SupportedExtensionCallback cb){
        auto l = dec->supportedFileExtensions();
        for(auto it = l.begin(); it != l.end(); it++){
            cb(it->c_str());
        }
    }