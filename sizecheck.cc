#include "FPG.hh"
#include <stdio.h>


#define WRITESIZE(STU) printf( "%d bytes are used for " #STU "\n", sizeof(STU) )

using namespace FPG;

int main(int argc, char **argv)
{
  WRITESIZE(StreamHead);
  WRITESIZE(FrameInfo);
  WRITESIZE(Frame);
  WRITESIZE(Head);
  WRITESIZE(Tile);
  WRITESIZE(UserData);
}
