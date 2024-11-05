#include <Arduino.h>

// Definim pinii pentru LED-uri și butoane
const int led25 = 10;   // LED pentru 25% încărcare
const int led50 = 9;    // LED pentru 50% încărcare
const int led75 = 8;    // LED pentru 75% încărcare
const int led100 = 7;   // LED pentru 100% încărcare
const int redRGB = 6;   // LED RGB - roșu
const int blueRGB = 4;  // LED RGB - albastru
const int greenRGB = 5; // LED RGB - verde
const int startPin = 3; // Buton pentru pornirea încărcării
const int stopPin = 2;  // Buton pentru oprirea forțată

// Variabile pentru stările butoanelor și debounce
int stateStartBtn = HIGH;            // Starea inițială a butonului de start (neapasat)
int stateStopBtn = HIGH;             // Starea inițială a butonului de stop (neapasat)
unsigned long debounceStart = 0;     // Temporizator pentru debounce la butonul de start
unsigned long debounceStop = 0;      // Temporizator pentru debounce la butonul de stop
const unsigned long debounceTime = 50; 

// Indicator pentru încărcare activă
bool chargingActive = false;         

unsigned long pressDurationStop = 0; // Temporizator pentru cât timp este apăsat butonul de stop

// Funcția de inițializare a pinilor și setarea stării inițiale a LED-urilor
void initializeSystem() {
  pinMode(led25, OUTPUT);          
  pinMode(led50, OUTPUT);          
  pinMode(led75, OUTPUT);          
  pinMode(led100, OUTPUT);         
  pinMode(redRGB, OUTPUT);         
  pinMode(blueRGB, OUTPUT);        
  pinMode(greenRGB, OUTPUT);       

  pinMode(startPin, INPUT_PULLUP); 
  pinMode(stopPin, INPUT_PULLUP);  

  // Setăm RGB-ul la verde, semnalând că sistemul este gata de funcționare
  digitalWrite(redRGB, LOW);       // LED-ul RGB roșu este stins
  digitalWrite(greenRGB, HIGH);    // LED-ul RGB verde este aprins
  digitalWrite(blueRGB, LOW);      // LED-ul RGB albastru este stins
}

// Funcție pentru a controla culoarea RGB-ului în funcție de starea de încărcare
void rgbIndicator(bool loading) {
  if (loading) {
    // Dacă încărcarea este activă, aprindem LED-ul roșu
    digitalWrite(redRGB, HIGH);
    digitalWrite(greenRGB, LOW);
    digitalWrite(blueRGB, LOW);
  } else {
    // Dacă încărcarea este oprită, aprindem LED-ul verde
    digitalWrite(redRGB, LOW);
    digitalWrite(greenRGB, HIGH);
    digitalWrite(blueRGB, LOW);
  }
}

// Funcție care controlează animația finală de oprire a încărcării
void stopChargingAnimation() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(led25, HIGH);
    digitalWrite(led50, HIGH);
    digitalWrite(led75, HIGH);
    digitalWrite(led100, HIGH);
    delay(500);
    digitalWrite(led25, LOW);
    digitalWrite(led50, LOW);
    digitalWrite(led75, LOW);
    digitalWrite(led100, LOW);
    delay(500);
  }
  rgbIndicator(false);   // Setăm RGB-ul la verde pentru a indica finalul
  chargingActive = false; 
}

// Funcție care gestionează apăsarea butonului de stop
void handleStopButton() {
  stateStopBtn = digitalRead(stopPin); 
  if (stateStopBtn == LOW && pressDurationStop == 0) {
    pressDurationStop = millis(); // Începem să contorizăm timpul
  }
  // Dacă butonul este ținut apăsat timp de 1 secundă, oprim încărcarea
  if (stateStopBtn == LOW && (millis() - pressDurationStop >= 1000)) {
    stopChargingAnimation();  
  }
  // Dacă butonul este eliberat, resetăm contorizarea
  if (stateStopBtn == HIGH) {
    pressDurationStop = 0;
  }
}
// Funcție pentru a gestiona procesul de încărcare
void chargeProcess() {
  chargingActive = true;  
  rgbIndicator(true);     
  for (int i = 0; i < 2; i++) {
    digitalWrite(led25, HIGH); delay(500); digitalWrite(led25, LOW); delay(500);
    handleStopButton(); 
    if (!chargingActive) return;  
  }

  digitalWrite(led25, HIGH); 
  for (int i = 0; i < 2; i++) {
    digitalWrite(led50, HIGH); delay(500); digitalWrite(led50, LOW); delay(500);
    handleStopButton();
    if (!chargingActive) return;
  }
  
  digitalWrite(led50, HIGH); 
  for (int i = 0; i < 2; i++) {
    digitalWrite(led75, HIGH); delay(500); digitalWrite(led75, LOW); delay(500);
    handleStopButton();
    if (!chargingActive) return;
  }

  digitalWrite(led75, HIGH); 
  for (int i = 0; i < 2; i++) {
    digitalWrite(led100, HIGH); delay(500); digitalWrite(led100, LOW); delay(500);
    handleStopButton();
    if (!chargingActive) return;
  }

  stopChargingAnimation();  
}


void loop() {
  int startReading = digitalRead(startPin); 

  // Debounce pentru butonul de start
  if (startReading != stateStartBtn) {
    debounceStart = millis();  
  }

  if ((millis() - debounceStart) > debounceTime) {
    if (startReading == LOW && !chargingActive) {
      chargeProcess(); 
    }
  }

  stateStartBtn = startReading;  // Actualizăm starea butonului de start
}


void setup() {
  initializeSystem(); 
}
