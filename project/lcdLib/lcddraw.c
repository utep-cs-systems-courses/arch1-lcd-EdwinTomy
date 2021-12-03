/** \file lcddraw.c
 *  \brief Adapted from RobG's EduKit
 */
#include "lcdutils.h"
#include "lcddraw.h"
#include <math.h>
#include <stdio.h>

/** Draw single pixel at x,row 
 */
void drawPixel(u_char col, u_char row, u_int colorBGR) 
{
  lcd_setArea(col, row, col, row);
  lcd_writeColor(colorBGR);
}

/** Fill rectangle
 *
 *  \param colMin Column start
 *  \param rowMin Row start
 *  \param width Width of rectangle
 *  \param height height of rectangle
 *  \param colorBGR Color of rectangle in BGR
 */
void fillRectangle(u_char colMin, u_char rowMin, u_char width, u_char height, 
		   u_int colorBGR)
{
  u_char colLimit = colMin + width, rowLimit = rowMin + height;
  lcd_setArea(colMin, rowMin, colLimit - 1, rowLimit - 1);
  u_int total = width * height;
  u_int c = 0;
  while ((c++) < total) {
    lcd_writeColor(colorBGR);
  }
}

void fillCircle(u_char center_row,  u_char_ center_col, u_int rad, 
		   u_int colorBGR)
{
  for(int r = center_row - rad; r <= center_row + rad; r++){
     for(int c = center_col - rad; c <= center_col + rad; c++){
		int length = sqrt(pow(rad, 2) - pow((rad-center_row), 2))
		if((c > (center_col - length)) && (c > (center_col + length))){
			}
		 }
  }
}

/** Fill screen with color
 */
void clearScreen(u_int colorBGR) 
{
  u_char w = screenWidth;
  u_char h = screenHeight;
  fillRectangle(0, 0, screenWidth, screenHeight, colorBGR);
}

/** 5x7 font - this function draws background pixels
 *  Adapted from RobG's EduKit
 */
void drawChar5x7(u_char rcol, u_char rrow, char c, 
     u_int fgColorBGR, u_int bgColorBGR) 
{
  u_char col = 0;
  u_char row = 0;
  u_char bit = 0x01;
  u_char oc = c - 0x20;

  lcd_setArea(rcol, rrow, rcol + 4, rrow + 7); /* relative to requested col/row */
  while (row < 8) {
    while (col < 5) {
      u_int colorBGR = (font_5x7[oc][col] & bit) ? fgColorBGR : bgColorBGR;
      lcd_writeColor(colorBGR);
      col++;
    }
    col = 0;
    bit <<= 1;
    row++;
  }
}

/** Draw string with font 5x7
 */
void drawString5x7(u_char col, u_char row, char *string,
		u_int fgColorBGR, u_int bgColorBGR)
{
  u_char cols = col;
  while (*string) {
    drawChar5x7(cols, row, *string++, fgColorBGR, bgColorBGR);
    cols += 6;
  }
}


/** Draw rectangle outline
 *  
 *  \param colMin Column start
 *  \param rowMin Row start 
 *  \param width Width of rectangle
 *  \param height Height of rectangle
 *  \param colorBGR Color of rectangle in BGR
 */
void drawRectOutline(u_char colMin, u_char rowMin, u_char width, u_char height,
		     u_int colorBGR)
{
  /**< top & bot */
  fillRectangle(colMin, rowMin, width, 1, colorBGR);
  fillRectangle(colMin, rowMin + height, width, 1, colorBGR);

  /**< left & right */
  fillRectangle(colMin, rowMin, 1, height, colorBGR);
  fillRectangle(colMin + width, rowMin, 1, height, colorBGR);
}

void drawFistBump(u_char cc, u_char cr){
  clearScreen(COLOR_RED);
  for(int r = 0; r <= 30; r++){
    int col_range = (45-r > 30)? 45: 45-r;
    for(int c = 0; c < col_range; c++){
      drawPixel(cc-c,cr-r, COLOR_BLACK);
      drawPixel(cc+c,cr-r, COLOR_WHITE);
      drawPixel(cc-c,cr+r, COLOR_BLACK);
      drawPixel(cc+c,cr+r, COLOR_WHITE);
    }
  }
}

void drawTriforce(u_char cc, u_char cr){
  clearScreen(COLOR_DARK_GREEN);
  for(int row = 0; row <= 30; row++){
    int col1= row;
    int col2 = -row;
  
    for(int col = col2; col <= col1; col++){
      drawPixel(col + cc, row + cr, COLOR_GOLD);
      drawPixel(col + cc + 30, row + cr + 30, COLOR_GOLD);
      drawPixel(col + cc - 30, row + cr + 30, COLOR_GOLD);
    }
  }
}

void drawPiano(){
  clearScreen(COLOR_PURPLE);
  int swap = 0;
  for(int row = 30; row < 120; row++){
    if (swap){
      row += 2;
      fillRectangle(30, row, 80, 20, COLOR_BLACK);
      swap ^= 1;
    }else{
      row += 2;
      fillRectangle(30, row, 80, 20, COLOR_WHITE);
      swap ^= 1;
    }
  }
}
  
