#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);


#include <RH_ASK.h>    // incluye libreria RadioHead.h
#include <SPI.h>    // incluye libreria SPI necesaria por RadioHead.h

RH_ASK rf_driver;   // crea objeto para modulacion por ASK  
  
int botonIncrementoSegmentos = 9;             //SEGMENTO
int PinPulsador = 53;                        //ARRANCA Y PARA TIMER
int PinPulsadorReset = 52;                   // RESETEA
int PinPulsadorDecremento = 48;              // RESTA LOCAL
int botonIncremento = 49;                      // SUMA LOCAL
int botonIncrementoVis =  31;                 // SUMA VISI
int PinPulsadorDecrementoVis = 33;           // RESTA VISI

int pinPulsadorResetSeg = 51;                // RESETEA SOLO LOS 24 SEGUNDOS

int estadoBotonIncrementoLocal;                 // ESTADO DEL BOTON DE PUNTOS LOCAL
int estadoBotonAnteriorIncrementoLocal;         // ESTADO DEL BOTON DE PUNTOS LOCAL

int cuentaLocal = 0;                             // CUENTA LOCAL

int estadoBotonDecrementoLocal;                  // ESTADO BOTON DECREMENTO LOCAL
int estadoBotonAnteriorDecrementoLocal;          // ESTADO BOTON ANTERIOR DECREMENTO LOCAL

                          
int estadoBotonIncrementoVis;                 // ESTADO DEL BOTON DE PUNTOS VISI
int estadoBotonAnteriorIncrementoVis;           // ESTADO DEL BOTON DE PUNTOS VISI

int cuentaVis = 0;                             // CUENTA VISI


int estadoBotonDecrementoVis;                       // ESTADO BOTON DECREMENTO VISI
int estadoBotonAnteriorDecrementoVis;                 // ESTADO BOTON ANTERIOR DECREMENTO VISI


int inicio = 0;
int eActual = 0;                                      // ESTADO PARA TIMER
int eAnterior = 0;                                    // ESTADO ANTERIOR PARA TIMER


int milisegundos = 0;
int decimas = 0;
int minutos = 0;
int segundos = 0;


int milisegundosSeg = 0;                          //24 segundos
int decimasSeg = 0;                               //24 segundso
int segundosSeg = 0;                              //24 segundos










void activarContador() {

  if (inicio == 1) {
    milisegundos = millis();


    decimas++;

    if (decimas == 10) {
      decimas = 0;
      segundos++;
    }
    if (segundos == 60) {
      segundos = 0;
      minutos++;

    }

    if (minutos == 10) {
      minutos = 0;
      segundos = 0;
      decimas = 0;
      lcd.clear();

    }



    lcd.setCursor(6, 0);
    if (minutos < 10)      {
      lcd.print("0");
    }
    lcd.print(minutos);
    lcd.print(":");
    lcd.setCursor(9, 0);
    if (segundos < 10)     {
      lcd.print("0");
    }
    lcd.print(segundos);
  }

}



void activarContadorSeg() {




  milisegundosSeg = millis();


  decimasSeg++;

  if (decimasSeg == 10) {
    decimasSeg = 0;
    segundosSeg++;
  }

  if (segundosSeg == 25) {

    segundosSeg = 0;
    decimasSeg = 0;

  }


  lcd.setCursor(6, 1);
  lcd.setCursor(8, 1);
  if (segundosSeg < 10)     {
    lcd.print("0");
  }
  lcd.print(segundosSeg);
}







void resetearTiempo() {
  minutos = 0;
  segundos = 0;
  decimas = 0;
  segundosSeg = 0;
  decimasSeg = 0;
  cuentaLocal = 0;
  cuentaVis = 0;
  lcd.clear();


}
void puntoss () {
  cuentaLocal++;
  //Serial.println(cuenta);


  lcd.setCursor(0, 0);
  lcd.print("L");

  lcd.setCursor(0 , 1);
  lcd.print(cuentaLocal);


}

void puntosResta() {
  cuentaLocal--;
  lcd.setCursor(0, 0);
  lcd.print("L");
  lcd.setCursor(0, 1);
  lcd.print(cuentaLocal);
}


void puntosVisResta() {
  cuentaVis--;
  lcd.setCursor(13, 0);
  lcd.print("V");
  lcd.setCursor(13, 1);
  lcd.print(cuentaVis);
}




void puntosVis() {
  cuentaVis++;
  Serial.println(cuentaVis);
  lcd.setCursor(13, 0);
  lcd.print("V");
  lcd.setCursor(13 , 1);
  lcd.print(cuentaVis);


}


void perromalvado () {
  decimasSeg = 0;
  segundosSeg = 0;
}






// SEGMENTO //
const int a = 2;
const int b = 3;
const int c = 4;
const int d = 5;
const int e = 6;
const int f = 7;
const int g = 8;

const int tiempoAntirebote = 10;
int cuenta = 0;
int estadoBotonIncremento;
int estadoBotonAnteriorIncremento;
int estadoBotonDecremento;
int estadoBotonAnteriorDecremento;



boolean antirebote (int pin) {


  int contador = 0;
  boolean estado;
  boolean estadoAnterior;


  do{
    estado = digitalRead (pin);
    if (estado != estadoAnterior) {
      contador = 0;
      estadoAnterior = estado;
      }
      else {
        contador = contador + 1;
      }
       delay(1);
       } while(contador < tiempoAntirebote);

       return estado;
       }


       void actualizarNumero (){
        switch (cuenta) {

     

          case 1:
        digitalWrite (a, LOW);
        digitalWrite (b, HIGH);
        digitalWrite (c, HIGH);
        digitalWrite (d, LOW);        //numero 1
        digitalWrite (e, LOW);
        digitalWrite (f, LOW);
        digitalWrite (g, LOW); 
        break;

        case 2:
        digitalWrite (a, HIGH);
        digitalWrite (b, HIGH);
        digitalWrite (c, LOW);
        digitalWrite (d, HIGH);        //numero 2
        digitalWrite (e, HIGH);
        digitalWrite (f, LOW);
        digitalWrite (g, HIGH);
        break;

        case 3:
        digitalWrite (a, HIGH);
        digitalWrite (b, HIGH);
        digitalWrite (c, HIGH);
        digitalWrite (d, HIGH);        //numero 3
        digitalWrite (e, LOW);
        digitalWrite (f, LOW);
        digitalWrite (g, HIGH); 
        break;

        case 4:
        digitalWrite (a, LOW);
        digitalWrite (b, HIGH);
        digitalWrite (c, HIGH);
        digitalWrite (d, LOW);        //numero 4
        digitalWrite (e, LOW);
        digitalWrite (f, HIGH);
        digitalWrite (g, HIGH);
        break;
         
      }
    }

       

void setup () {


  pinMode(botonIncrementoSegmentos, INPUT);
  pinMode(PinPulsador, INPUT);
  pinMode(PinPulsadorReset, INPUT);
  pinMode(botonIncremento, INPUT);
  pinMode(PinPulsadorDecremento, INPUT);
  pinMode(botonIncrementoVis, INPUT);
  pinMode(PinPulsadorDecrementoVis, INPUT);
  pinMode (pinPulsadorResetSeg, INPUT);
   pinMode(a, OUTPUT);
  pinMode(b, OUTPUT); 
  pinMode(c, OUTPUT); 
  pinMode(d, OUTPUT); 
  pinMode(e, OUTPUT); 
  pinMode(f, OUTPUT); 
  pinMode(g, OUTPUT);

  
  
  lcd.begin(16, 2);                       //DISPLAY 16,2

  lcd.init();                             // Inicializar el LCD


  lcd.backlight();                      //Encender la luz de fondo.        //ENCIENDE LA LUZ DE FONDO

  rf_driver.init();      // inicializa objeto con valores por defecto

}

void loop() {




  eActual = digitalRead(PinPulsador);                                //estado actual es igual al estado en el que se encuentra el pin
  if (eActual && eAnterior == 0) {                                  //eActual en true y eAnterior en 0
    inicio = 1 - inicio;                                           //resta 1 - el estado en el que se encuentra inicio

  }
  eAnterior = eActual;                                          //guarda el estado en el que estaba

  if (inicio == 1) {                                         //si inicio esta en 1



    const char *msg = "1";                                // carga numero 1 en mensaje a enviar
    rf_driver.send((uint8_t *)msg, strlen(msg));          // envia el mensaje
    rf_driver.waitPacketSent();                          // espera al envio correcto del mensaje


    activarContador();
    activarContadorSeg();

  }

  if (digitalRead(PinPulsadorReset) == 1) {

    const char *msg = "2";                                // carga numero 2 en mensaje a enviar
    rf_driver.send((uint8_t *)msg, strlen(msg));          // envia el mensaje
    rf_driver.waitPacketSent();                          // espera al envio correcto del mensaje

    resetearTiempo();



  }







  estadoBotonIncrementoLocal = digitalRead(botonIncremento);
  if (estadoBotonIncrementoLocal != estadoBotonAnteriorIncrementoLocal) {
    if (digitalRead(botonIncremento) == 1) {
      const char *msg = "3";                                // carga numero 3 en mensaje a enviar
      rf_driver.send((uint8_t *)msg, strlen(msg));          // envia el mensaje
      rf_driver.waitPacketSent();                          // espera al envio correcto del mensaje

      puntoss();

    }
    estadoBotonAnteriorIncrementoLocal = estadoBotonIncrementoLocal;


  }

  estadoBotonIncrementoVis = digitalRead(botonIncrementoVis);
  if (estadoBotonIncrementoVis != estadoBotonAnteriorIncrementoVis) {
    if (digitalRead(botonIncrementoVis) == 1) {




      const char *msg = "4";                                // carga numero 4 en mensaje a enviar
      rf_driver.send((uint8_t *)msg, strlen(msg));          // envia el mensaje
      rf_driver.waitPacketSent();                          // espera al envio correcto del mensaje

      puntosVis();
    }
    estadoBotonAnteriorIncrementoVis = estadoBotonIncrementoVis;
  }





  estadoBotonDecrementoVis = digitalRead(PinPulsadorDecrementoVis);
  if (estadoBotonDecrementoVis != estadoBotonAnteriorDecrementoVis) {
    if (digitalRead(PinPulsadorDecrementoVis) == 1) {
      const char *msg = "5";                                // carga numero 5 en mensaje a enviar
      rf_driver.send((uint8_t *)msg, strlen(msg));          // envia el mensaje
      rf_driver.waitPacketSent();                          // espera al envio correcto del mensaje

      puntosVisResta();

    }
    estadoBotonAnteriorDecrementoVis = estadoBotonDecrementoVis;
  }


  estadoBotonDecrementoLocal = digitalRead(PinPulsadorDecremento);
  if (estadoBotonDecrementoLocal != estadoBotonAnteriorDecrementoLocal) {
    if (digitalRead(PinPulsadorDecremento) == 1) {
      const char *msg = "6";                                // carga numero 6 en mensaje a enviar
      rf_driver.send((uint8_t *)msg, strlen(msg));          // envia el mensaje
      rf_driver.waitPacketSent();                          // espera al envio correcto del mensaje

      puntosResta();

    }
    estadoBotonAnteriorDecrementoLocal = estadoBotonDecrementoLocal;

  }


  if (digitalRead(pinPulsadorResetSeg) == 1) {


    const char *msg = "7";                                // carga numero 7 en mensaje a enviar
    rf_driver.send((uint8_t *)msg, strlen(msg));          // envia el mensaje
    rf_driver.waitPacketSent();                          // espera al envio correcto del mensaje

    perromalvado();

  }



 estadoBotonIncremento = digitalRead(botonIncrementoSegmentos);
 if(estadoBotonIncremento != estadoBotonAnteriorIncremento) {
  if(digitalRead(botonIncrementoSegmentos)== 1){
    const char *msg = "8";                                // carga numero 8 en mensaje a enviar
    rf_driver.send((uint8_t *)msg, strlen(msg));          // envia el mensaje
    rf_driver.waitPacketSent();                          // espera al envio correcto del mensaje

    
    cuenta++;
    if(cuenta > 4){
      cuenta = 1;

    
    }
  }
 }
 estadoBotonAnteriorIncremento = estadoBotonIncremento;
  actualizarNumero();
}
