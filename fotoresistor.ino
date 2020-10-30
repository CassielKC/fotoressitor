void setup() {
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  float rl=0, il=0, vana=0;
  delay(1000);
  vana=analogRead(A0);
  Serial.print("La lectura analogica es de: ");
  Serial.print(vana );
  Serial.println(" bits");
  Serial.print("");
  vana=vana*(5.0/1023.0);
  rl=613*((5/vana)-1);
  il=pow((rl/126951),-1.1655);
  
  Serial.print("el voltaje es de: ");
  Serial.print(vana );
  Serial.println(" V");
  Serial.print("");
  Serial.print("El valor de la resistencia es de: ");
  Serial.print(rl );
  Serial.println(" Ohms");
  Serial.print("");
  Serial.print("La intensidad luminos a es de: ");
  Serial.print(il );
  Serial.println(" LUX");
  Serial.print("-------------------------------------------");
  Serial.println("");
  
  if(il<=2000)
  {
    digitalWrite(13,HIGH);
  }
  else
  {
    digitalWrite(13, LOW);
  }
}
