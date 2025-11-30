#ifndef DVN_IMAGES
#define DVN_IMAGES
#include "stdint.h"

typedef struct{
	uint8_t *mImage;
}dvn_Image;


extern dvn_Image imageDVN;


void DVN_chooseImage( uint8_t mImage);

#endif