#include <stdio.h>

static void SetGFX()  { _asm { mov ax, 0x13; int 0x10 } }
static void SetText() { _asm { mov ax, 0x03; int 0x10 } }
static unsigned char _far* VRAM = (unsigned char _far*) 0xA0000000UL;
static void PutPixel (unsigned x, unsigned y, int c) { VRAM[y*320u+x] = c; }

static const unsigned Width=320, Height=200;

int main() {

	SetGFX();
	for (unsigned y=0; y < Height; ++y)
		for (unsigned x=0; x < Width; ++x)
			PutPixel(x,y x);
	return 0;
}
