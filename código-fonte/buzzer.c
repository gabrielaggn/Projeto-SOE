#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
	
		int som = 3; //representa o IO22
		int alarme = 2;	//representa o IO27
		wiringPiSetup();
		pinMode(som, OUTPUT);
		pinMode(alarme, INPUT);
		
	
	
		while(1){
			

					digitalWrite(som, HIGH);
					usleep(500);
					digitalWrite(som, LOW);
					usleep(500);
					if(digitalRead(alarme) == HIGH){
						digitalWrite(som, LOW);
						break;
					}
		}	
	
}
