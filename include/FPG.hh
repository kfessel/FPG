#include <stdint.h>

namespace FPG{      //Flexible Progressiv Graphics
  /*
   *FPG-Stream
   *  StreamHead|{Data}
   *Data
   *  {Frame}|{Data}
   *  {nothing}
   *Frame
   *  Head
   *  Tile
   *  UserData
   *
   *every Block has a size of a multible of 4 bytes
   *
   *
   *
   */
  struct StreamHead{
    uint8_t magic[3];   //FPG
    uint8_t version[1];
  };
  struct FrameInfo{
    uint8_t  type;      // values over 127 are reseverd for longer types
    uint32_t size:24;   // size in byte >> 4 (32Bit aligned pad using 0)
  };
  struct Frame{
    FrameInfo frameinfo;
    uint32_t data[];   // frameinfo.size-1;
  };

  struct Head{
    struct Channel{
      uint32_t width;
      uint32_t height;
      uint8_t  usedbits;
    };
    FrameInfo frameinfo;
    uint32_t height;
    uint32_t width;
    uint8_t colormode;  // upto 127 are reseverd vor predefined modes >127 color mode to be define may use UserData to define
    uint8_t nchannels;  // number of channels
                        //(min the number of channels required by colormodel  extra channels are to will be
                        // en- and decoded but have to be interpreted separatly (useable for depthmaps))
    Channel channels[];
  };
  struct Tile{
    FrameInfo frameinfo;
    uint8_t  channel;
    uint8_t  level;
    uint16_t tilenumber;
    uint16_t bitstream[]; //runlength encoded Bitplanes
  };
  struct UserData
  {
    FrameInfo frameinfo;
    uint32_t data[];   // frameinfo.size-1;
  };
  
  
  
  
};
