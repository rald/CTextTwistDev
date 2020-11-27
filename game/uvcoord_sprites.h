#ifndef SPRITES_H
#define SPRITES_H

#define SPRITES_BITMAP_WIDTH  512
#define SPRITES_BITMAP_HEIGHT 512
#define SPRITES_NUM_IMAGES     73

const unsigned int sprites_texcoords[] = {

	//	*** BIG LETTERS ***

	   0,   0,  64,  64,	//   0
	  64,   0,  64,  64,	//   1
	 128,   0,  64,  64,	//   2
	 192,   0,  64,  64,	//   3
	 256,   0,  64,  64,	//   4
	 320,   0,  64,  64,	//   5
	 384,   0,  64,  64,	//   6
	 448,   0,  64,  64,	//   7
	   0,  64,  64,  64,	//   8
	  64,  64,  64,  64,	//   9
	 128,  64,  64,  64,	//  10
	 192,  64,  64,  64,	//  11
	 256,  64,  64,  64,	//  12
	 320,  64,  64,  64,	//  13
	 384,  64,  64,  64,	//  14
	 448,  64,  64,  64,	//  15
	   0, 128,  64,  64,	//  16
	  64, 128,  64,  64,	//  17
	 128, 128,  64,  64,	//  18
	 192, 128,  64,  64,	//  19
	 256, 128,  64,  64,	//  20
	 320, 128,  64,  64,	//  21
	 384, 128,  64,  64,	//  22
	 448, 128,  64,  64,	//  23
	   0, 192,  64,  64,	//  24
	  64, 192,  64,  64,	//  25
	  
	//	*** SMALL LETTERS ***
	
	   0, 256,  32,  32,	//  26
	  32, 256,  32,  32,	//  27
	  64, 256,  32,  32,	//  28
	  96, 256,  32,  32,	//  29
	 128, 256,  32,  32,	//  30
	 160, 256,  32,  32,	//  31
	 192, 256,  32,  32,	//  32
	 224, 256,  32,  32,	//  33
	 256, 256,  32,  32,	//  34
	 288, 256,  32,  32,	//  35
	 320, 256,  32,  32,	//  36
	 352, 256,  32,  32,	//  37
	 384, 256,  32,  32,	//  38
	   0, 288,  32,  32,	//  39
	  32, 288,  32,  32,	//  40
	  64, 288,  32,  32,	//  41
	  96, 288,  32,  32,	//  42
	 128, 288,  32,  32,	//  43
	 160, 288,  32,  32,	//  44
	 192, 288,  32,  32,	//  45
	 224, 288,  32,  32,	//  46
	 256, 288,  32,  32,	//  47
	 288, 288,  32,  32,	//  48
	 320, 288,  32,  32,	//  49
	 352, 288,  32,  32,	//  50
	 384, 288,  32,  32,	//  51

	//	*** SHAPES ***
	
	 128, 192,  64,  64,	//  52	BALL
	 192, 192,  64,  64,	//  53	BOX
	 256, 192,  32,  32,	//  54	SMALL BOX
	 
	//	*** BUTTONS ***
	
	   0, 320, 128,  64,	//  55	TWIST UP
	 128, 320, 128,  64,	//  56	TWIST DOWN
	 
	 256, 320, 128,  64,	//  57	ENTER UP
	 384, 320, 128,  64,	//  58	ENTER DOWN
	
	   0, 384, 128,  64,	//  59	LAST UP
	 128, 384, 128,  64,	//  60	LAST DOWN

	 256, 384, 128,  64,	//  61	CLEAR UP
	 384, 384, 128,  64,	//  62	CLEAR DOWN
	 

	  
};

#endif
