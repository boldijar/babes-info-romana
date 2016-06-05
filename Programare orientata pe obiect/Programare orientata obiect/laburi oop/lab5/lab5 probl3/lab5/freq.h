#ifndef FREQ_H
#define FREQ_H
#include "Set.h"
struct _Freq;
typedef _Freq * Freq;
void initFreq(Freq&);
void addFreq(Freq&,Telem);
void printFreq(Freq);
int belongsFreq(Freq,Telem);
void destroyFreq(Freq&);
#endif