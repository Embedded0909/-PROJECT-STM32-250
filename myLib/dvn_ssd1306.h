#ifndef DVN_SSD1306
#define DVN_SSD1306 

//---------------------------------------------INCLUDE-----------------------------------------------
#include "stm32f1xx_hal.h"
#include "string.h"

//----------------------------------------------DEFINE-----------------------------------------------
#define DVN_SSD1306_I2C_ADDR                   0x78
#define SSD1306_DEACTIVATE_SCROLL              0x2E 
#define SSD1306_WIDTH													 128
#define SSD1306_HEIGHT												 64
#define DVN_SSD1306_WRITECOMMAND(command)      DVN_ssd1306_I2C_Write(DVN_SSD1306_I2C_ADDR, 0x00, (command))
#define DVN_SSD1306_WRITEDATA(data)            DVN_ssd1306_I2C_Write(DVN_SSD1306_I2C_ADDR, 0x40, (data))

//-----------------------------------------------STRUCT---------------------------------------------
typedef struct {
	uint16_t CurrentX;
	uint16_t CurrentY;
	uint8_t Inverted;
	uint8_t Initialized;
} SSD1306_t;

typedef enum {
	SSD1306_COLOR_BLACK = 0x00, 
	SSD1306_COLOR_WHITE = 0x01  
} SSD1306_COLOR_t;

typedef struct {
	uint8_t FontWidth;    
	uint8_t FontHeight;  
	const uint16_t *data; 
} DVN_FontDef_t;

extern DVN_FontDef_t DVN_Font_11x18;
//------------------------------------------------API---------------------------------------------------
uint8_t DVN_SSD1306_Init();
void DVN_ssd1306_I2C_Write(uint8_t address, uint8_t reg, uint8_t data) ;
void DVN_SSD1306_Fill(SSD1306_COLOR_t color);
void DVN_SSD1306_UpdateScreen(void);
void DVN_ssd1306_I2C_WriteMulti(uint8_t address, uint8_t reg, uint8_t* data, uint16_t count);
void DVN_SSD1306_GotoXY(uint16_t x, uint16_t y);
char DVN_SSD1306_Putc(char ch, DVN_FontDef_t* Font, SSD1306_COLOR_t color);
char DVN_SSD1306_Puts(char* str, DVN_FontDef_t* Font, SSD1306_COLOR_t color);
void DVN_SSD1306_DrawPixel(uint16_t x, uint16_t y, SSD1306_COLOR_t color);
#endif