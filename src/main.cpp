#include <stdio.h>
#include <unistd.h>
#include "audio/jack.h"

TAAudioJACK audio;
TAAudioDesc want, got;

void process(float** in, float** out, int inChans, int outChans, unsigned int size) {
  for (int i=0; i<outChans; i++) {
    for (int j=0; j<size; j++) {
      out[i][j]=1.0f;
    }
  }
}

int main(int argc, char** argv) {
  want.bufsize=1024;
  want.fragments=2;
  want.inChans=0;
  want.outChans=2;
  want.outFormat=TA_AUDIO_FORMAT_F32;
  want.name="romance";

  audio.setCallback(process);

  printf("initializing audio.\n");
  if (!audio.init(want,got)) {
    printf("error while initializing audio!\n");
    return 1;
  }

  if (!audio.setRun(true)) {
    printf("error while activating!\n");
    return false;
  }
  printf("running!\n");

  while (true) {
    usleep(50000);
  }
  return 0;
}
