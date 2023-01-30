#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
	
		int som = 3; //representa o IO22
		wiringPiSetup();
		pinMode(som, OUTPUT);
		
	
	
		while(1){
			

					digitalWrite(som, HIGH);
					usleep(500);
					digitalWrite(som, LOW);
					usleep(500);
		}	
	
}
