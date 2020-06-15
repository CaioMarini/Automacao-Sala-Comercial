#include <Arduino.h>

//Manual e led de fora automatico funcionando

//Sites Usados
//
//LDR: https://blogmasterwalkershop.com.br/arduino/como-usar-com-arduino-fotoresistor-sensor-ldr-5mm/
//
//
// número do pins dos botoes das salas
const int buttonPinManuGeral = 32;
const int buttonPinManuFora = 30;
const int buttonPinManuRecep = 28;
const int buttonPinManuCorre = 26;
const int buttonPinManuSala = 24;

//pinos dos botoes de mudança de variavel
const int buttonPinAutomatic = 34;
const int buttonpinAuSegSex = 36;
const int buttonPinAuSabDom = 38;
const int buttonPinAu19a7 = 40;
const int buttonPinAu7a19 = 42;

//Pins dos sensores
const int sensorPinFora = 44;
const int sensorPinRecep1 = 46;
const int sensorPinRecep2 = 48;
const int sensorPinCorre1 = 50;
const int sensorPinCorre2 = 52;
const int sensorPinSala = 51;

// número do pino LED
const int ledPinFora = 39;
const int ledPinRecpUm = 37;
const int ledPinRecpDois = 35;
const int ledPinRecpTres = 33;
const int ledPinCorrUm = 31;
const int ledPinCorrDois = 29;
const int ledPinSalaUm = 27;
const int ledPinSalaDois = 25;

//pinos dos  leds indicatiovos de acionamento dos botoes
const int ledPinAuto = 41;
const int ledPinSegSex = 43;
const int ledPinSabDom = 45;
const int ledPin19a7 = 47;
const int ledPin7a19 = 49;

const int ldrPin = A0;

//variaveis que irao contorlar o dia e hora
int segSex = 0;
int sabDom = 0;
int a19a7 = 0;
int a7a19 = 0;

//variaveis de controle de pessoas
int pesRecep = 0;
int pesCorre = 0;
int pesSala = 0;

// set variables
int estadoButManuGeral = 0; // variável para leitura do pushbutton
int guardaEstadoButManuGeral;  // variável para armazenar valores do pushbutton
int estadoButManuFora = 0;
int guardaEstadoButManuFora;
int estadoButManuRecep = 0;
int guardaEstadoButManuRecep;
int estadoButManuCorre = 0;
int guardaEstadoButManuCorre;
int estadoButManuSala = 0;
int guardaEstadoButManuSala;

int estadoButAuto = 0;
int guardaEstadoButAuto;

int estadoButButAuSegSex = 0;
int guardaEstadoButSegSex;
int estadoButAuSabDom = 0;
int guardaEstadoButSabDom;
int estadoButAu19a7 = 0;
int guardaEstadoBut19a7;
int estadoButAu7a19 = 0;
int guardaEstadoBut7a19;

//Voids que controlarão a contagem de pessoas
void senFora() {
  pesRecep++;

  if(pesRecep<0){
    pesRecep = 0;
  }
  delay(1000);
}

void senRecep1() {
  pesRecep--;

  if(pesRecep<0){
    pesRecep = 0;
  }
  delay(1000);
}

void senRecep2(){
  pesRecep--;
  pesCorre++;

  if(pesRecep < 0){
    pesRecep = 0;
  }
  delay(1000);
}

void senCorre1(){
  pesCorre--;
  pesRecep++;

  if(pesCorre <0){
    pesCorre = 0;
  }
  delay(1000);
}

void senCorre2(){
  pesCorre--;
  pesSala++;

  if(pesCorre < 0 ){
    pesCorre = 0;
  }
  delay(1000);
}

void senSala(){
  pesCorre++;
  pesSala--;

  if(pesSala < 0 ){
    pesSala = 0;
  }
  delay(1000);
}

void setup() {
// define o pino do Led como saída do Arduino
  pinMode(ledPinFora, OUTPUT);
  pinMode(ledPinRecpUm, OUTPUT);
  pinMode(ledPinRecpDois, OUTPUT);
  pinMode(ledPinRecpTres, OUTPUT);
  pinMode(ledPinCorrUm, OUTPUT);
  pinMode(ledPinCorrDois, OUTPUT);
  pinMode(ledPinSalaUm, OUTPUT);
  pinMode(ledPinSalaDois, OUTPUT);

  //definiçãodos pins dos leds do botoes de contorle como saida
  pinMode(ledPinAuto, OUTPUT);
  pinMode(ledPinSegSex, OUTPUT);
  pinMode(ledPinSabDom, OUTPUT);
  pinMode(ledPin19a7, OUTPUT);
  pinMode(ledPin7a19, OUTPUT);

  pinMode(ldrPin, INPUT);

// define pino do pushbutton como entrada do Arduino:
  pinMode(buttonPinManuGeral, INPUT);
  pinMode(buttonPinManuFora, INPUT);
  pinMode(buttonPinManuRecep, INPUT);
  pinMode(buttonPinManuCorre, INPUT);
  pinMode(buttonPinManuSala, INPUT);

//define o pinnos do  botoes de variavel com saida
  pinMode(buttonPinAutomatic, INPUT);
  pinMode(buttonpinAuSegSex, INPUT);
  pinMode(buttonPinAuSabDom, INPUT);
  pinMode(buttonPinAu19a7, INPUT);
  pinMode(buttonPinAu7a19, INPUT);

  Serial.begin(9600);

}

void loop() {

  // le o estado pushbutton: ligado (HIGH) ou desligado (LOW)
  estadoButManuGeral = digitalRead(buttonPinManuGeral);
  estadoButManuFora = digitalRead(buttonPinManuFora);
  estadoButManuRecep = digitalRead(buttonPinManuRecep);
  estadoButManuCorre = digitalRead(buttonPinManuCorre);
  estadoButManuSala = digitalRead(buttonPinManuSala);

  estadoButAuto = digitalRead(buttonPinAutomatic);  //Botao Modo Automatico
  estadoButButAuSegSex = digitalRead(buttonpinAuSegSex);
  estadoButAuSabDom = digitalRead(buttonPinAuSabDom);
  estadoButAu19a7 = digitalRead(buttonPinAu19a7);
  estadoButAu7a19 = digitalRead(buttonPinAu7a19);

  if (estadoButAuto == HIGH) {
    guardaEstadoButAuto = !guardaEstadoButAuto;
    while (!digitalRead(buttonPinAutomatic)) {
    }
    delay(500);
  }

  //Botoes de mudança de variavel
  if (estadoButButAuSegSex == HIGH) {
    guardaEstadoButSegSex = !guardaEstadoButSegSex;
    while (!digitalRead(buttonpinAuSegSex)) {
    }
    delay(500);
  }

  if (estadoButAuSabDom == HIGH) {
    guardaEstadoButSabDom = !guardaEstadoButSabDom;
    while (!digitalRead(buttonPinAuSabDom)) {
    }
    delay(500);
  }

  if (estadoButAu19a7 == HIGH) {
    guardaEstadoBut19a7 = !guardaEstadoBut19a7;
    while (!digitalRead(buttonPinAu19a7)) {
    }
    delay(500);
  }
  if (estadoButAu7a19 == HIGH) {
    guardaEstadoBut7a19 = !guardaEstadoBut7a19;
    while (!digitalRead(buttonPinAu7a19)) {
    }
    delay(500);
  }

  /*************************************************************************************************************/
  /*************************************************************************************************************/
  //incio da rotina automatica
  //inicializa o modo automatico e acende um led indicando se esse mod esta ativo
  if (guardaEstadoButAuto == HIGH) {
    digitalWrite(ledPinAuto, HIGH);

    //Led de fora liga automaticamnete quando o sensor detecta que está escuro
    if (analogRead(ldrPin) > 600) {
      digitalWrite(ledPinFora, HIGH);
    } else if (ldrPin < 599) {
      digitalWrite(ledPinFora, LOW);
    }

    //BOTOES DE VARIAVEL
    //Botoa seg a sex
    if (guardaEstadoButSegSex == HIGH) {
      digitalWrite(ledPinSegSex, HIGH);
      segSex = +1;
      //Serial.println(segSex);
    } else if (guardaEstadoButSegSex == LOW) {
      digitalWrite(ledPinSegSex, LOW);
      segSex = 0;
      //Serial.println(segSex);
    }
    //botao sab dom
    if (guardaEstadoButSabDom == HIGH) {
      digitalWrite(ledPinSabDom, HIGH);
      sabDom = +1;
      //Serial.println(sabDom);
    } else if (guardaEstadoButSabDom == LOW) {
      digitalWrite(ledPinSabDom, LOW);
      sabDom = 0;
      //Serial.println(sabDom);
    }
    //botao 19 a 7
    if (guardaEstadoBut19a7 == HIGH) {
      digitalWrite(ledPin19a7, HIGH);
      a19a7 = +1;
      //Serial.println(a19a7);
    } else if (guardaEstadoBut19a7 == LOW) {
      digitalWrite(ledPin19a7, LOW);
      a19a7 = 0;
      //Serial.println(a19a7);
    }
    //Botão 7 a 19
    if (guardaEstadoBut7a19 == HIGH) {
      digitalWrite(ledPin7a19, HIGH);
      a7a19 = +1;
      //Serial.println(a7a19);
    } else if (guardaEstadoBut7a19 == LOW) {
      digitalWrite(ledPin7a19, LOW);
      a7a19 = 0;
      //Serial.println(a7a19);
    }

    if(guardaEstadoButSegSex == LOW && guardaEstadoButSabDom == LOW && guardaEstadoBut19a7== LOW && guardaEstadoBut7a19 == LOW){
      digitalWrite(ledPinRecpUm, LOW);
      digitalWrite(ledPinRecpDois, LOW);
      digitalWrite(ledPinRecpTres, LOW);
      digitalWrite(ledPinCorrUm, LOW);
      digitalWrite(ledPinCorrDois, LOW);
      digitalWrite(ledPinSalaUm, LOW);
      digitalWrite(ledPinSalaDois, LOW);
    }

    //Automação da iluminação da sem pessoa
    //Seg a Sex || 19 a 7 || Sem Pessoa Claro/Escuro
    if (analogRead(ldrPin) > 600 && pesRecep == 0 && a19a7 == 1 && segSex == 1) {
      digitalWrite(ledPinRecpUm, HIGH);
    } else if (analogRead(ldrPin) < 599 && pesRecep == 0 && a19a7 == 1 && segSex == 1) {
      digitalWrite(ledPinRecpUm, LOW);
    }

    //Seg a Sex || 7 a 19 || Sem Pessoa Claro/Escuro
    if(analogRead(ldrPin) > 600 && segSex == 1 && a7a19 ==1 && pesRecep == 0  ){
      digitalWrite(ledPinRecpUm,HIGH);
      digitalWrite(ledPinRecpDois,HIGH);
      digitalWrite(ledPinRecpTres,LOW);
    }else if(analogRead(ldrPin) < 599 && segSex == 1 && a7a19 == 1 && pesRecep ==0){
      digitalWrite(ledPinRecpUm,LOW);
      digitalWrite(ledPinRecpDois,LOW);
      digitalWrite(ledPinRecpTres,HIGH);
    }


     if(digitalRead(sensorPinFora) == LOW){
        senFora();
        Serial.println(pesRecep);

      }

     if(digitalRead(sensorPinRecep1) == LOW){
        senRecep1();
        Serial.println(pesRecep);

      }

     if(digitalRead(sensorPinRecep2)== LOW){
       senRecep2();
       Serial.println(pesRecep);
       Serial.println(pesCorre);
     }

     if(digitalRead(sensorPinCorre1) == LOW){
       senCorre1();
       Serial.println(pesRecep);
       Serial.println(pesCorre);
     }

     if(digitalRead(sensorPinCorre2) == LOW){
       senCorre2();
       Serial.println(pesCorre);
       Serial.println(pesSala);
     }

     if(digitalRead(sensorPinSala) == LOW){
       senSala();
       Serial.println(pesSala);
       Serial.println(pesCorre);
     }


     //Automação da iluminação da com pessoa
        //Seg a Sex || 19 a 7 || Sem Pessoa Claro/Escuro Recpção
        if (analogRead(ldrPin) > 600 && pesRecep >= 1 && a19a7 == 1 && segSex == 1) {
          digitalWrite(ledPinRecpUm, HIGH);//Escuro
          digitalWrite(ledPinRecpDois,HIGH);
        } else if (analogRead(ldrPin) < 599 && pesRecep >= 1 && a19a7 == 1 && segSex == 1) {
          digitalWrite(ledPinRecpUm, LOW);//claro
          digitalWrite(ledPinRecpDois, LOW);
        }

        //Seg a Sex || 7 a 19 || Sem Pessoa Claro/Escuro
        if(analogRead(ldrPin) > 600 && segSex == 1 && a7a19 ==1 && pesRecep >=1  ){
          digitalWrite(ledPinRecpUm,HIGH);//Escuro
          digitalWrite(ledPinRecpDois,HIGH);
          digitalWrite(ledPinRecpTres,HIGH);
        }else if(analogRead(ldrPin) < 599 && segSex == 1 && a7a19 == 1 && pesRecep >= 1){
          digitalWrite(ledPinRecpUm,LOW);//Claro
          digitalWrite(ledPinRecpDois,HIGH);
          digitalWrite(ledPinRecpTres, LOW);
        }
        //Recepção
        //Sab Dom || Claro /Escuro
        if(analogRead(ldrPin) > 600 && sabDom == 1  ){
           digitalWrite(ledPinRecpUm,HIGH);//Escuro
           digitalWrite(ledPinRecpDois,LOW);
           digitalWrite(ledPinRecpTres,LOW);
         }else if(analogRead(ldrPin) < 599 && sabDom == 1){
           digitalWrite(ledPinRecpUm,LOW);//Claro
           digitalWrite(ledPinRecpDois,LOW);
           digitalWrite(ledPinRecpTres, LOW);
         }

        //Corredor
        if (analogRead(ldrPin) > 600 && pesCorre >= 1 ) {
           digitalWrite(ledPinCorrUm, HIGH);//Escuro
           digitalWrite(ledPinCorrDois,HIGH);
           //delay(500);
        } else if (analogRead(ldrPin) < 599 && pesCorre >= 1) {
           digitalWrite(ledPinCorrUm, HIGH);//claro
           digitalWrite(ledPinCorrDois, LOW);
          // delay(500);
        }

        if(pesCorre == 0){
           digitalWrite(ledPinCorrUm, LOW);
           digitalWrite(ledPinCorrDois, LOW);
        }

        if (analogRead(ldrPin) > 600 && pesSala >= 1 ) {
            digitalWrite(ledPinSalaUm, HIGH);//Escuro
                   digitalWrite(ledPinSalaDois,HIGH);
                  
           } else if (analogRead(ldrPin) < 599 && pesSala >= 1) {
                digitalWrite(ledPinSalaUm, HIGH);//claro
                digitalWrite(ledPinSalaDois, LOW);        
            }

        if(pesSala == 0){
              digitalWrite(ledPinSalaUm, LOW);
              digitalWrite(ledPinSalaDois, LOW);
         }


    //*************************************
    //Parte Manual Do projeto
    //*******************************
  } else if (guardaEstadoButAuto == LOW) {
    digitalWrite(ledPinAuto, LOW);

    // verifica se o botão geral está pressionado
    if (estadoButManuGeral == HIGH) {
      // inverte valor da variável guarda_estado
      guardaEstadoButManuGeral = !guardaEstadoButManuGeral;
      //esperera soltar o botão
      while (!digitalRead(buttonPinManuGeral)) {
      }
      delay(500);
    }
    //verifica se o botao fora esta pressionado
    if (estadoButManuFora == HIGH) {
      // inverte valor da variável guarda_estado
      guardaEstadoButManuFora = !guardaEstadoButManuFora;
      //esperera soltar o botão
      while (!digitalRead(buttonPinManuFora)) {
      }
      delay(500);
    }
    //verifica se o botao recepçao esta pressionado
    if (estadoButManuRecep == HIGH) {
      // inverte valor da variável guarda_estado
      guardaEstadoButManuRecep = !guardaEstadoButManuRecep;
      //esperera soltar o botão
      while (!digitalRead(buttonPinManuRecep)) {
      }
      delay(500);
    }
    //verifica se o botao coorredor esta pressionado
    if (estadoButManuCorre == HIGH) {
      // inverte valor da variável guarda_estado
      guardaEstadoButManuCorre = !guardaEstadoButManuCorre;
      //esperera soltar o botão
      while (!digitalRead(buttonPinManuCorre)) {
      }
      delay(500);
    }
    //verifica se o botao sala esta pressionado
    if (estadoButManuSala == HIGH) {
      // inverte valor da variável guarda_estado
      guardaEstadoButManuSala = !guardaEstadoButManuSala;
      //esperera soltar o botão
      while (!digitalRead(buttonPinManuSala)) {
      }
      delay(500);
    }

    if (guardaEstadoButManuGeral == HIGH) {
      // liga o led
      digitalWrite(ledPinFora, HIGH);
      digitalWrite(ledPinRecpUm, HIGH);
      digitalWrite(ledPinRecpDois, HIGH);
      digitalWrite(ledPinRecpTres, HIGH);
      digitalWrite(ledPinCorrUm, HIGH);
      digitalWrite(ledPinCorrDois, HIGH);
      digitalWrite(ledPinSalaUm, HIGH);
      digitalWrite(ledPinSalaDois, HIGH);
      return;

    } else if (guardaEstadoButManuGeral == LOW) {
      // desliga o led
      digitalWrite(ledPinFora, LOW);
      digitalWrite(ledPinRecpUm, LOW);
      digitalWrite(ledPinRecpDois, LOW);
      digitalWrite(ledPinRecpTres, LOW);
      digitalWrite(ledPinCorrUm, LOW);
      digitalWrite(ledPinCorrDois, LOW);
      digitalWrite(ledPinSalaUm, LOW);
      digitalWrite(ledPinSalaDois, LOW);
    }

    if (guardaEstadoButManuFora == HIGH) {
      // liga o led
      digitalWrite(ledPinFora, HIGH);
    } else if (guardaEstadoButManuFora == LOW) {
      // desliga o led
      digitalWrite(ledPinFora, LOW);
    }

    if (guardaEstadoButManuRecep == HIGH) {
      // liga o led
      digitalWrite(ledPinRecpUm, HIGH);
      digitalWrite(ledPinRecpDois, HIGH);
      digitalWrite(ledPinRecpTres, HIGH);
    } else if (guardaEstadoButManuRecep == LOW) {
      // desliga o led
      digitalWrite(ledPinRecpUm, LOW);
      digitalWrite(ledPinRecpDois, LOW);
      digitalWrite(ledPinRecpTres, LOW);
    }

    if (guardaEstadoButManuCorre == HIGH) {
      // liga o led
      digitalWrite(ledPinCorrUm, HIGH);
      digitalWrite(ledPinCorrDois, HIGH);
    } else if (guardaEstadoButManuCorre == LOW) {
      // desliga o led
      digitalWrite(ledPinCorrUm, LOW);
      digitalWrite(ledPinCorrDois, LOW);
    }

    if (guardaEstadoButManuSala == HIGH) {
      // liga o led
      digitalWrite(ledPinSalaUm, HIGH);
      digitalWrite(ledPinSalaDois, HIGH);
    } else if (guardaEstadoButManuSala == LOW) {
      // desliga o led
      digitalWrite(ledPinSalaUm, LOW);
      digitalWrite(ledPinSalaDois, LOW);
    }

  }

  //Fim Do void Loop
}
