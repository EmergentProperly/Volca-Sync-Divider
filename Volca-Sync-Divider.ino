  //o  O O  VOLCA SYNC DIVIDER  (O) 000 o|
///|   (O)  x   o   o   o     o o o o    |
///|        o   o   x   x     = = = =    |
///|   (O)  o   o   x   o                |
///|o___________________________________o|
///||   [][][]  [][]  [][][]  [][]  []  ||                           
///||  [][][][][][][][][][][][][][][][] ||     
///||-----------------------------------||
///|/   *  *   *   *     *  *  *   *    \|
/////////////////////////////////////////
////////////////////////////////////////

/*
  An Arduino driven Korg Volca sync divider. The arduino recieves a sync pulse from a volca, and outputs 2 or more 
  pulses at a lower BPM while remaining in time. 
  
  Put together and tested with an Arduino Nano, Arduino Pro Micro, Volca Beats, Volca Keys and Volca Bass. The Volca Beats was the master sync. 
  
  DISCLAIMER: Due to the quirkiness of Volcas, your mileage may vary.
*/



// Sync in/out pins for the Volcas. Add additional outputs if you have more than 3 volcas in your project.
const int  input1 = 3;    
const int output1 = 8;      
const int output2 = 9;
const int LED1 = 5;
const int LED2 = 6;


// Step counting
int inputCounter = 0;   // counter for the number of sync pulses
int inputState = 0;         // current state of the sync input
int lastinputState = 0;     // previous state of the sync input

unsigned long start_time = millis (); // for closing the pulses at the correct time

void setup() {
  // initialize pin 3 as input:
  pinMode(input1, INPUT);
  // initialize the outputs:
  pinMode(output1, OUTPUT);
  pinMode(output2, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {

 inputState = digitalRead(input1);

  // compare the syncState to its previous state
  if (inputState != lastinputState) {
    // if the state has changed, increment the counter
    if (inputState == HIGH) {
      inputCounter++;
    }

  
  lastinputState = inputState; // save the current state as the last state, for next time through the loop

  // Volca Sync sends 5V pulses with a duration of 15 milliseconds. This block ensures the pulses are closed at the right time.
  if (millis () - start_time >= 15) {
    digitalWrite(output1, LOW);
    digitalWrite(output2, LOW);
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
  }


  /*  
    The following sends SYNC OUT signals every X-amount of SYNC IN signals. Adjust numbers and add blocks to suit your project's requirements. 
    The default is both outputs are 1/16th speed of the original time (not to be confused with 16th steps). 
    See troubleshooting section in the README if your Volcas are syncing unpredictably.
  */

  if (inputCounter % 2 == 0) {
    //digitalWrite(LED_BUILTIN, HIGH);  // <--- If you'd prefer to use the onboard LED for the main pulse.
    digitalWrite(LED2, HIGH);
  }
    
 
  // Comment Block 1 and uncomment Block 2-3 together for a different variation. Experiment with "(inputCounter % x == 0)" to your hearts content. 

  // Block 1
  // Divided SYNC OUT pulses are sent. LEDs light up on divided pulses
  if (inputCounter % 16 == 0) {
    digitalWrite(output1, HIGH);
    digitalWrite(output2, HIGH);
    digitalWrite(LED1, HIGH);
  }
  
  /*
    // Block 2
    if (inputCounter % 8 == 0) {
      digitalWrite(output1, HIGH);
      digitalWrite(output2, HIGH);
      digitalWrite(LED2, HIGH);
    }

    // Block 3
    if (inputCounter % 16 == 0) {
      digitalWrite(output1, HIGH);
      digitalWrite(output2, HIGH);
      digitalWrite(LED2, HIGH);
    }
  */

  }

}
