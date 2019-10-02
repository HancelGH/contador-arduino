
const int buttonPin = 12;    
const int ledPin =  13;      

int Estadobutton = 0;         


int unidad=0;        
int decena=0;       
int conmutador=0;    
int cont=0;           
      
int var=0;     
void setup() {               
  pinMode(2, OUTPUT);  //seg a
  pinMode(3, OUTPUT);  //seg b
  pinMode(4, OUTPUT);  //seg c
  pinMode(5, OUTPUT);  //seg d
  pinMode(6, OUTPUT);  //seg e
  pinMode(7, OUTPUT);  //seg f
  pinMode(8, OUTPUT);  //seg g
  
  pinMode(10, OUTPUT); 
  pinMode(11, OUTPUT); 
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
 delay(50);
 Estadobutton = digitalRead(buttonPin);
  if (Estadobutton == HIGH) {
    digitalWrite(ledPin, HIGH);
    encender();
  } else {
    digitalWrite(ledPin, LOW);
    cont++;  
    encender();
    
  }

 }
void encender(){
  if (cont==9){ //secuencia en la que valida la pulsacion del boton esta relacionada con el delay al principio del loop            
      cont=0;                  
      unidad=unidad+1;          // incrementa la unidad, primer 7seg
    if (unidad >= 10){        
        decena=decena+1;      // incrementa la decena,  segundo 7seg
      unidad=0;               
      if (decena>=10){        
       decena=0; 
      }      
    }
 }
 
    
    if (conmutador == 0) {    // hace la multiplexacion conmutando entre los dos 7seg  izq y der
      digitalWrite(10, 1);    // enciende el derecho
      digitalWrite(11, 0);    // apaga el izquierdo
      var=unidad;             // iguala la variable que escribe el numero en el 7seg al valor de la unidad
      conmutador=1;           // cambia el conmutador para que en el siguiente ciclo cumpla la otra condicion
      
    }
    else{
     digitalWrite(10, 0);       // apaga el derecho
      digitalWrite(11, 1);      // enciende el izquierdo
      var=decena;               // iguala la variable que escribe el numero en el 7seg al valor de la decena
      conmutador=0;             // cambia el conmutador para que en el siguiente ciclo cumpla la otra condicion
      
    }
  switch (var) {
    case 1:                 //escribe en el 7seg el numero 1
      digitalWrite(2, 0);
      digitalWrite(3, 1);
      digitalWrite(4, 1);
      digitalWrite(5, 0);
      digitalWrite(6, 0);
      digitalWrite(7, 0);
      digitalWrite(8, 0);
     break;
    case 2:                //escribe en el 7seg el numero 2
      digitalWrite(2, 1);
      digitalWrite(3, 1);
      digitalWrite(4, 0);
      digitalWrite(5, 1);
      digitalWrite(6, 1);
      digitalWrite(7, 0);
      digitalWrite(8, 1);
     break;      
    case 3:               //escribe en el 7seg el numero 3
       digitalWrite(2, 1);
       digitalWrite(3, 1);
       digitalWrite(4, 1);
       digitalWrite(5, 1);
       digitalWrite(6, 0);
       digitalWrite(7, 0);
       digitalWrite(8, 1);
      break;
    case 4:               //escribe en el 7seg el numero 4
      digitalWrite(2, 0);
      digitalWrite(3, 1);
      digitalWrite(4, 1);
      digitalWrite(5, 0);
      digitalWrite(6, 0);
      digitalWrite(7, 1);
      digitalWrite(8, 1);
     break;
    case 5:               //escribe en el 7seg el numero 5
      digitalWrite(2, 1);
      digitalWrite(3, 0);
      digitalWrite(4, 1);
      digitalWrite(5, 1);
      digitalWrite(6, 0);
      digitalWrite(7, 1);
      digitalWrite(8, 1);
     break;
    case 6:               //escribe en el 7seg el numero 6
      digitalWrite(2, 1);
      digitalWrite(3, 0);
      digitalWrite(4, 1);
      digitalWrite(5, 1);
      digitalWrite(6, 1);
      digitalWrite(7, 1);
      digitalWrite(8, 1);
     break;
    case 7:              //escribe en el 7seg el numero 7
      digitalWrite(2, 1);
      digitalWrite(3, 1);
      digitalWrite(4, 1);
      digitalWrite(5, 0);
      digitalWrite(6, 0);
      digitalWrite(7, 0);
      digitalWrite(8, 0);
     break;
    case 8:              //escribe en el 7seg el numero 8
      digitalWrite(2, 1);
      digitalWrite(3, 1);
      digitalWrite(4, 1);
      digitalWrite(5, 1);
      digitalWrite(6, 1);
      digitalWrite(7, 1);
      digitalWrite(8, 1);
      break;
    case 9:               //escribe en el 7seg el numero 9
      digitalWrite(2, 1);
      digitalWrite(3, 1);
      digitalWrite(4, 1);
      digitalWrite(5, 0);
      digitalWrite(6, 0);
      digitalWrite(7, 1);
      digitalWrite(8, 1);
     break;
    case 0:                //escribe en el 7seg el numero 0
       digitalWrite(2, 1);
       digitalWrite(3, 1);
       digitalWrite(4, 1);
       digitalWrite(5, 1);
       digitalWrite(6, 1);
       digitalWrite(7, 1);
       digitalWrite(8, 0);
      break;
           
    default: 
    pausa();
 }
    
}
 void pausa(){

 }
