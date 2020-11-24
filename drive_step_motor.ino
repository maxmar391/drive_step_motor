int x;
int i = 0;
int cycles = 200; // define number of test cycles



void setup() 
{
  Serial.begin(9600); // start transmission on serial monitor

  pinMode(6, OUTPUT); // Enable
  pinMode(5, OUTPUT); // Step
  pinMode(4, OUTPUT); // Direction

  digitalWrite(6, LOW); // Set Enable low = switch on the motor driver
}



void loop() 
{
  if (i < cycles) // run for defined number of cycles
  { 
    // move 180° in one direction
    digitalWrite(4, HIGH); // Set Direction high

    for (x = 0; x < 100; x++) // Loop 100 steps = 180°
    {
      digitalWrite(5, HIGH); // Output high
      delay(10); // Wait
      digitalWrite(5, LOW); // Output low
      delay(20); // Wait
    }

    i++; // increase counter by one for each test cycle

    Serial.print("Testzyklus: "); // print the current test cycle in the serial monitor
    Serial.print(i);
    Serial.println(); // new line in serial monitor

    // pause before switching direction
    delay(500); // pause half a second



    // move 180° in the other direction
    digitalWrite(4, LOW); // Set Direction low

    for (x = 0; x < 100; x++) // Loop 100 steps = 180°
    {
      digitalWrite(5, HIGH); // Output high
      delay(10); // Wait
      digitalWrite(5, LOW); // Output low
      delay(20); // Wait
    }

    i++; // increase counter by one for each test cycle

    Serial.print("Testzyklus: "); // print the current test cycle in the serial monitor
    Serial.print(i);
    Serial.println(); // new line in serial monitor

    // pause before switching direction
    delay(500); // pause half a second
  }
  else 
  {
    Serial.print("Test abgeschlossen");
    Serial.print(i);
    Serial.print(" Zyklen durchlaufen");
    Serial.println();
  }
}
