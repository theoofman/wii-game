/*===========================================
        GRRLIB (GX Version)
        - Template Code -

        Minimum Code To Use GRRLIB
============================================*/
#include <grrlib.h>

#include <stdlib.h>
#include <time.h>
#include <wiiuse/wpad.h>
/*
WPAD_BUTTON_2=0x0001
WPAD_BUTTON_1=0x0002
WPAD_BUTTON_B=0x0004
WPAD_BUTTON_A=0x0008
WPAD_BUTTON_MINUS=0x0010
WPAD_BUTTON_HOME=0x0080
WPAD_BUTTON_LEFT=0x0100
WPAD_BUTTON_RIGHT=0x0200
WPAD_BUTTON_DOWN=0x0400
WPAD_BUTTON_UP=0x0800
WPAD_BUTTON_PLUS=0x1000
WPAD_NUNCHUK_BUTTON_Z=(0x0001--16)
WPAD_NUNCHUK_BUTTON_C=(0x0002--16)

*/

int main(int argc, char **argv) {
	srand(time(NULL));
    // Initialise the Graphics & Video subsystem
    GRRLIB_Init();

    // Initialise the Wiimotes
    WPAD_Init();
	u32 wpaddown, wpadheld;
	GRRLIB_SetBackgroundColour(0xFF,0x00,0x00,0xFF);

	int xPos = 0;
	int yPos = 0;
	int SPEED = 5;
	int xVelocity = 5;
	int yVelocity = 5;
	int SCREENWIDTH = 640;
	int SCREENHEIGHT = 480;
	u32 color = 0x000000FF;
    // Loop forever
    while(1) {

        WPAD_ScanPads();  // Scan the Wiimotes
		wpaddown = WPAD_ButtonsDown(0);
        wpadheld = WPAD_ButtonsHeld(0);

        // If [HOME] was pressed on the first Wiimote, break out of the loop
        if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME)  break;
		if(WPAD_ButtonsDown(0) & WPAD_BUTTON_A){
			color = (rand()%16777216)*256+255;
		}

        // ---------------------------------------------------------------------
        // Place your drawing code here
        // ---------------------------------------------------------------------
		//width 640
		//height 480
		GRRLIB_Rectangle(xPos,yPos,200,200, color, true);
		/*
		if(wpadheld & WPAD_BUTTON_RIGHT){
			xPos += SPEED;
		}
		if(wpadheld & WPAD_BUTTON_LEFT){
			xPos -= SPEED;
		}
		if(wpadheld & WPAD_BUTTON_UP){
			yPos -= SPEED;
		}
		if(wpadheld & WPAD_BUTTON_DOWN){
			yPos += SPEED;
		}
		*/
		xPos += xVelocity;
		yPos += yVelocity;
		if(xPos < 0 || xPos > SCREENWIDTH-200){
			xVelocity *= -1;
		}
		if(yPos < 0 || yPos > SCREENHEIGHT-200){
			yVelocity *= -1;
		}
        GRRLIB_Render();  // Render the frame buffer to the TV
		
    }

    GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB

    exit(0);  // Use exit() to exit a program, do not use 'return' from main()
}
