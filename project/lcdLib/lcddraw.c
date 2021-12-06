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
	u_char colLimit = colMin + width;
  u_char rowLimit = rowMin + height;
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
		int length = sqrt(pow(rad, 2) - pow((rad-center_row), 2));
		for(int c = center_col - rad; c <= center_col + rad; c++){
			if((c > (center_col - length)) && (c > (center_col + length))){
				drawPixel(c, r, colorBGR);
			}
		}
  }
}

void circleOutline(u_char center_row,  u_char_ center_col, u_int rad, 
		   u_int colorBGR)
{
  for(int r = center_row - rad; r <= center_row + rad; r++){
		int length = sqrt(pow(rad, 2) - pow((rad-center_row), 2));
		drawPixel(c - length, r, colorBGR);
		drawPixel(c + length, r, colorBGR);
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

void drawHappySolarSystem(u_int if_up){
  clearScreen(COLOR_BLACK);
	
  
  
} 


  