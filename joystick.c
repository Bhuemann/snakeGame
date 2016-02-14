#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "joystick.h"

static int joystick_fd = -1;

int open_joystick(string deviceName)
{
	string location = JOYSTICK_DEVPATH + deviceName;
	
	joystick_fd = open(location, O_RDONLY | O_NONBLOCK); /* read write for force feedback? */
	if (joystick_fd < 0)
		return joystick_fd;

	/* maybe ioctls to interrogate features here? */

	return joystick_fd;
}

int read_joystick_event(struct js_event *jse)
{
	int bytes;

	bytes = read(joystick_fd, jse, sizeof(*jse));

	if (bytes == -1)
		return 0;

	if (bytes == sizeof(*jse))
		return 1;

	printf("Unexpected bytes from joystick:%d\n", bytes);

	return -1;
}

void close_joystick()
{
	close(joystick_fd);
}

int get_joystick_status(struct wwvi_js_event *wjse)
{
	int rc;
	struct js_event jse;
	if (joystick_fd < 0)
		return -1;

	// memset(wjse, 0, sizeof(*wjse));
	while ((rc = read_joystick_event(&jse) == 1)) {
		jse.type &= ~JS_EVENT_INIT; /* ignore synthetic events */
		if (jse.type == JS_EVENT_AXIS) {
			switch (jse.number) {
			case 0: wjse->stick_x = jse.value;
				break;
			case 1: wjse->stick_y = jse.value;
				break;
			/* case 2: wjse->stick2_x = jse.value; */
			/* 	break; */
			/* case 3: wjse->stick2_y = jse.value; */
			/* 	break; */
			default:
				break;
			}
		} else if (jse.type == JS_EVENT_BUTTON) {
			if (jse.number < 10) {
				switch (jse.value) {
				case 0:
				case 1: wjse->button[jse.number] = jse.value;
					break;
				default:
					break;
				}
			}
		}
	}
	// printf("%d\n", wjse->stick1_y);
	return 0;
}

void setJoystickFd(int fd){
	joystick_fd = fd;
}

#if 0
/* a little test program */
int main(int argc, char *argv[])
{
	int fd, rc;
	int done = 0;

	struct js_event jse;

	fd = open_joystick();
	if (fd < 0) {
		printf("open failed.\n");
		exit(1);
	}

	while (!done) {

		//Controller unplugged
		if(errno == ENODEV){

			printf("Controller disconnected!\n");

			while((fd = open_joystick()) < 0){
				usleep(1000);
			}
			
			errno = 0;
			
		}

		
		rc = read_joystick_event(&jse);
		usleep(1000);
		
		/* if (rc == 1) { */
		/* 	printf("Event: time %8u, value %8hd, type: %3u, axis/button: %u\n", */
		/* 		   jse.time, jse.value, jse.type, jse.number); */

		if(rc == 1){
			if(jse.type == BUTTON_TYPE && jse.value == BUTTON_DOWN_PRESS){

				switch(jse.number){
				
				case BUTTON_A:
					printf("You pressed the A button\n");
					break;
				case BUTTON_B:
					printf("You pressed the B button\n");
					break;
				case BUTTON_X:
					printf("You pressed the X button\n");
					break;
				case BUTTON_Y:
					printf("You pressed the Y button\n");
					break;
				case BUTTON_LB:
					printf("You pressed the LB button\n");
					break;
				case BUTTON_RB:
					printf("You pressed the RB button\n");
					break;
				case BUTTON_SELECT:
					printf("You pressed the SELECT button\n");
					break;
				case BUTTON_START:
					printf("You pressed the START button\n");
					break;

				}

			
			}
			else if(jse.type == DPAD_TYPE && jse.value != DPAD_UP_PRESS){

				if(jse.number == DPAD_Y_AXIS){

					if(jse.value == -32767)
						printf("You pressed the DPAD UP\n");
					else
						printf("You pressed the DPAD DOWN\n");
				
				}
				else if(jse.number == DPAD_X_AXIS){

					if(jse.value == -32767)
						printf("You pressed the DPAD LEFT\n");
					else
						printf("You pressed the DPAD RIGHT\n");

				
				}

			
			}
		}
	}
}
#endif
