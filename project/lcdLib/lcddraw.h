/** \file lcddraw.h
 *  \brief Adapted from RobG's EduKit
 */

#ifndef lcddraw_included
#define lcddraw_included

void drawPixel(u_char col, u_char row, u_int colorBGR);
void fillRectangle(u_char colMin, u_char rowMin, u_char width, u_char height, 
		   u_int colorBGR);

void fillCircle(u_char center_row,  u_char_ center_col, u_int rad, 
		   u_int colorBGR);

void circleOutline(u_char center_row,  u_char_ center_col, u_int rad, 
		   u_int colorBGR);

void clearScreen(u_int colorBGR);

void drawChar5x7(u_char rcol, u_char rrow, char c, 
     u_int fgColorBGR, u_int bgColorBGR);

void drawString5x7(u_char col, u_char row, char *string,
		u_int fgColorBGR, u_int bgColorBGR);

void drawHappySolarSystem(u_int up);\
void drawSadSolarSystem(u_int up);
void sunDeadlyLazer(u_int up);

void welcome();

#endif // included


