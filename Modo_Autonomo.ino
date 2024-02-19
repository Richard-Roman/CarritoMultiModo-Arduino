void Autonomo(){

  Serial.println("Modo Autonomo");
  delay(3000);
  comando = (char)bluetooth.read();
  Serial.println(comando);

  if (comando == 'A'){ // Orden para iniciar el modo Autonomo
    
    do{

      int distanceR = 0;
      int distanceL =  0;
      delay(40); 
      
      if(distance <= 40){               //Evaluamos si existe obtaculo dentro del rango del sensor ultrasonico
        Serial.println("obtaculo");
        moveStop();                     // Nos detenemos              
        delay(200);                   
        moveBackward();                 // Retrocedemos
        delay(800);                      
        moveStop();                     // Nos detenemos 
        delay(200);
        distanceR = lookRight();        // Miramos a la derecha con el sensor ultrasonico
        delay(200);
        distanceL = lookLeft();         // Miramos a la Izquierda con el sensor ultrasonico
        delay(200);
        
        if(distanceR>=distanceL){       // Evaluamos el camino a tomar
          Serial.println("derecha");
          turnRight();                  // Giramos a la derecha    
          moveStop();                   // Nos detenemos
          }
        else{
          Serial.println("izquierda");
          turnLeft();                   // Giramos a la Izquierda
          moveStop();                   // Nos detenemos
        }

      }
      else{
        Serial.println("sin obtaculo");
        moveForward();                  // Nos movemos hacia Adelante       
      }

      distance = readPing();
      comando = (char)bluetooth.read();

    }while(comando != 'P');   // Orden para detener el modo Autonomo
    
    Serial.println("bucle terminado");
 }
 else{  // Si no se dio la orden para inicializar el modo 
  Serial.println("No se Inicializo");
 }
      
}