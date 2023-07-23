#include "../sharedDefs.h"
#include <vector>

enum RomCommandType {
  romCEnd=0,
  romCFrame,
  romCJump
};

struct RomCommand {
  RomCommandType type;
  union {
    unsigned char u8;
    int i32;
    float f32;
  } val;
};

enum RomModType {
  // no modulation.
  romMNone=0,
  // invert the phase of every sample.
  romMInvert,
  // move every sample up/down, and cross over boundaries.
  romMOverflow,
  // move every sample up/down, and change direction upon hitting boundary.
  romMPong,
  // average every sample with the previous ones.
  romMAverage
};

struct RomPart {
  float wave[1024];
  size_t waveLen;

  RomModType mod;
  bool modLeft, modDown;
  double modSpeed, modPower;
};

struct RomState {
  RomPart parts[4];
  RomCommand program[256];
};

struct RomVoice {

};

class Romance {
  std::vector<RomVoice> voices;
};