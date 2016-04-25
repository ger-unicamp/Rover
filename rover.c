#define MOTOR_F_E 0
#define MOTOR_F_D 1
#define MOTOR_T_E 2
#define MOTOR_T_D 3

#define MOTOR_E 0
#define MOTOR_D 1

#define PONTE_H_1 0
#define PONTE_H_2 1

#define TEMPO_GIRO 2000

#define TEMPO_PARADA

//gira o dado motor pra frente
void frente(int motor){

}

//gira o dado motor pra tras
void tras(int motor) {



}

void desliga_motor(int motor) {

}

void desliga_motores() {
	desliga_motor(MOTOR_D);
	desliga_motor(MOTOR_E);
}

//Gira os dois motores pra frente
void reto_frente() {

	frente(MOTOR_D);
	frente(MOTOR_E);

}

//segue reto para tras
void reto_tras() {

	tras(MOTOR_D);
	tras(MOTOR_E);
}

//Para um dos motores
void para_um(int motor) {

}

//Para os dois motores
void para() {

	para_um(MOTOR_D);
	para_um(MOTOR_E);

	delay(TEMPO_PARADA);
}

//gira um motor enquanto gira reverso o outro 
void gira_total(int tempo) {

	//se for horario, inverte motores da direita
	if(tempo > 0) {
		tras(MOTOR_D);
		frente(MOTOR_E);		
	}
	else if(tempo < 0) {
		frente(MOTOR_D);
		tras(MOTOR_E);
	}
	else {
		para();
	}

	delay(tempo);

}

void gira_parcial(int tempo) {

	//Se for horario, para os motores da direita
	if(tempo > 0) {
		desliga_motor(MOTOR_D);
		frente(MOTOR_E);
	}
	else if(tempo < 0) {
		frente(MOTOR_D);
		desliga_motor(MOTOR_E);
	}  
	else {
		para();
	}

	delay(tempo);

}

void setup() {

}

void loop() {

	//Primeiro ele vai seguir reto por um tempo determinado
	reto();
	delay(5000);

	//Para para depois fazer o giro
	para();	

	//Gira horario com os motores direitos parados 
	gira_parcial(TEMPO_GIRO);
	para();	

	//Gira anti-horario com os motores esquerdos parados
	gira_parcial((-1) * TEMPO_GIRO);
	para();

	//Gira horario com motores no reverso
	gira_total(TEMPO_GIRO);
	para();

	//Gira anti-horario com motores no reverso
	gira_total((-1) * TEMPO_GIRO);
	para();




}