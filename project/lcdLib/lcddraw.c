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

void fillCircle(u_char center_row,  u_char center_col, u_int rad, 
		   u_int colorBGR)
{
  for(int r = center_row - rad; r <= center_row + rad; r++){
		double pow1 = pow(rad, 2);
		double pow2 = pow(fabs(center_row - r), 2);
	  	double diff = fabs(pow1-pow2);
		double mag = sqrt(diff);
		int length = round(mag);
		for(int c = center_col - rad; c <= center_col + rad; c++){
			if((c > (center_col - length)) && (c < (center_col + length))){
				drawPixel(c, r, colorBGR);
			}
		}
  }
}

void circleOutline(u_char center_row,  u_char center_col, u_int rad, 
		   u_int colorBGR)
{
  for(int r = center_row - rad; r <= center_row + rad; r++){
		double pow1 = pow(rad, 2);
		double pow2 = pow(fabs(center_row - r), 2);
	  	double diff = fabs(pow1-pow2);
		double mag = sqrt(diff);
		int length = round(mag);
		drawPixel(center_col - length, r, colorBGR);
		drawPixel(center_col + length, r, colorBGR);
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

void drawHappySolarSystem(u_int up){
	clearScreen(COLOR_BLACK);
	
	circleOutline(80, 64, 50, COLOR_WHITE);
	circleOutline(80, 64, 40, COLOR_WHITE);
	circleOutline(80, 64, 30, COLOR_WHITE);
	
	
	fillCircle(80, 64, 15, COLOR_YELLOW);

	fillCircle(80, 14, 4, COLOR_CYAN);
	circleOutline(80, 14, 6, COLOR_WHITE);

	fillCircle(52, 92, 5, COLOR_AQUAMARINE);
	fillCircle(110, 64, 4, COLOR_TURQUOISE);

	

	fillCircle(80, 64, 15, COLOR_YELLOW);
	fillCircle(110, 64, 4, COLOR_BLACK);
	circleOutline(80, 64, 30, COLOR_WHITE);
	fillCircle(105, 61, 4, COLOR_TURQUOISE);
	
	fillCircle(80, 64, 15, COLOR_YELLOW);
	fillCircle(105, 61, 4, COLOR_BLACK);
	circleOutline(80, 64, 30, COLOR_WHITE);
	fillCircle(100, 58, 4, COLOR_TURQUOISE);
	
	fillCircle(80, 64, 15, COLOR_YELLOW);
	fillCircle(100, 58, 4, COLOR_BLACK);
	circleOutline(80, 64, 30, COLOR_WHITE);
	fillCircle(95, 55, 4, COLOR_TURQUOISE);
	
	fillCircle(80, 64, 15, COLOR_YELLOW);
	fillCircle(95, 55, 4, COLOR_BLACK);
	circleOutline(80, 64, 30, COLOR_WHITE);
	fillCircle(89, 53, 4, COLOR_TURQUOISE);
	fillCircle(80, 64, 15, COLOR_GOLD);
	
	drawString5x7(10,30,"ThE sUN iS a deAdlY", COLOR_WHITE, COLOR_BLACK);
	drawString5x7(10,40,"LasEr :(", COLOR_WHITE, COLOR_BLACK);
	drawString5x7(10,50,"ThE sUN iS a deAdlY", COLOR_WHITE, COLOR_BLACK);
	drawString5x7(10,60,"LasEr :(", COLOR_WHITE, COLOR_BLACK);
	drawString5x7(10,70,"ThE sUN iS a deAdlY", COLOR_WHITE, COLOR_BLACK);
	drawString5x7(10,80,"LasEr :(", COLOR_WHITE, COLOR_BLACK);
	drawString5x7(10,90,"ThE sUN iS a deAdlY", COLOR_WHITE, COLOR_BLACK);
	drawString5x7(10,100,"LasEr :(", COLOR_WHITE, COLOR_BLACK);
	drawString5x7(10,110,"ThE sUN iS a deAdlY", COLOR_WHITE, COLOR_BLACK);
	drawString5x7(10,120,"LasEr :(", COLOR_WHITE, COLOR_BLACK);
	drawString5x7(10,130,"ThE sUN iS a deAdlY", COLOR_WHITE, COLOR_BLACK);
	drawString5x7(10,140,"LasEr :(", COLOR_WHITE, COLOR_BLACK);
	
	fillCircle(80, 64, 20, COLOR_GOLD);
	fillCircle(80, 64, 25, COLOR_ORANGE_RED);
	fillCircle(80, 64, 30, COLOR_GOLD);
	fillCircle(80, 64, 35, COLOR_ORANGE_RED);
	fillCircle(80, 64, 40, COLOR_GOLD);
	fillCircle(80, 64, 45, COLOR_ORANGE_RED);
	fillCircle(80, 64, 50, COLOR_GOLD);
	fillCircle(80, 64, 55, COLOR_ORANGE_RED);
	fillCircle(80, 64, 60, COLOR_GOLD);
	fillCircle(80, 64, 65, COLOR_ORANGE_RED);
	fillCircle(80, 64, 70, COLOR_GOLD);
	fillCircle(80, 64, 75, COLOR_ORANGE_RED);
	fillCircle(80, 64, 80, COLOR_GOLD);
	fillCircle(80, 64, 85, COLOR_ORANGE_RED);
	
} 

void drawSadSolarSystem(u_int up){
	circleOutline(80, 64, 50, COLOR_WHITE);
	circleOutline(80, 64, 40, COLOR_WHITE);
	circleOutline(80, 64, 30, COLOR_WHITE);
	
	fillCircle(80, 64, 20, COLOR_RED);

	fillCircle(80, 14, 4, COLOR_BROWN);
	circleOutline(80, 14, 6, COLOR_WHITE);

	fillCircle(52, 92, 5, COLOR_PINK);
	fillCircle(110, 64, 4, COLOR_FIREBRICK);


	fillCircle(80, 64, 25, COLOR_ORANGE_RED);

	fillCircle(40, 34, 4, COLOR_BROWN);
	circleOutline(40, 34, 6, COLOR_WHITE);

	fillCircle(80, 104, 5, COLOR_PINK);
	fillCircle(89, 53, 4, COLOR_FIREBRICK);
	
	drawString5x7(10,60,"ThE sUN iS a deAdlY LasEr :(", COLOR_WHITE, COLOR_BLACK);
	
} 

void sunDeadlyLazer(u_int up){
	drawString5x7(10,60,"ThE sUN iS a deAdlY LasEr :(", COLOR_WHITE, COLOR_BLACK);
	
	if(up == 1){
		fillCircle(80, 64, 20, COLOR_RED);
		
	} else {
		fillCircle(80, 64, 25, COLOR_ORANGE_RED);
		
	}
} 

void welcome(){
  clearScreen(COLOR_BLACK);
	drawString5x7(10,60,"Welcome! >:)", COLOR_WHITE, COLOR_BLACK);
} 



  
