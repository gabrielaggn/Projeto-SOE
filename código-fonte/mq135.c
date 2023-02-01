#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
	int alarme = 2;	//representa o IO27
	int som = 3; //representa o IO22
	wiringPiSetup();
	pinMode(alarme, INPUT);
	pinMode(som, OUTPUT);
	
	while(1){
		if(digitalRead(alarme) == LOW){
			//printf("ALERTA!!!");
			system("/home/gabriela/envioAlertaPerigo.sh");
			system("/home/gabriela/Desktop/buzzer");
			
		}
		else{
			//printf("Tudo okay!");
			/*printf("%d", digitalRead(alarme));*/
			digitalWrite(som, LOW);
			usleep(500);	
		}
	
	}
return 0;

}
