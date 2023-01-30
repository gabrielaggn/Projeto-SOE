/*Desenvolvido para o projeto de SOE, UnB - GAMA. ALUNAS : GABRIELA GOES e PAMELA CAMPAGNUCCI*/

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


	while(1){
		if(digitalRead(alarme) == LOW){
			//printf("ALERTA!!!");
			system("sudo telegram  \"599113865 \"   \"ALERTA, SEU PET CORRE PERIGO\" ");
			system("./buzzer");	
			
		}
		else{
			//printf("Tudo okay!");
			/*printf("%d", digitalRead(alarme));*/
			digitalWrite(som, LOW);
			usleep(500);	
		}
	
	}

}

