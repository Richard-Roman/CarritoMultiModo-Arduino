int lookRight() {         // Giramos el sensor ultrasonico a la derecha 
    myservo.write(50);    
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(115);        
    return distance;
}

int lookLeft()             // Giramos el sensor ultrasonico a la Izquierda
{
    myservo.write(170); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(115); 
    return distance;
    delay(100);
}

int readPing() {            // Leemos si hay obstaculos
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}