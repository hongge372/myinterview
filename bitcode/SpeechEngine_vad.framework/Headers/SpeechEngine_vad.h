//
//  SpeechEngine_vad.h
//  SpeechEngine_vad
//
//  Created by liudongqing on 2019/4/29.
//  Copyright © 2019 liudongqing. All rights reserved.
//

#ifndef speechEngine_vad_h
#define speechEngine_vad_h

#ifdef __cplusplus
extern "C" {
#endif
    
    int speechEngine_vad_start(int sampFrequency,int sampChannel);
    int speechEngine_vad_process(uint8_t* speech_in,int len);
    void  speechEngine_vad_stop();
    
#ifdef __cplusplus
}
#endif
#endif


