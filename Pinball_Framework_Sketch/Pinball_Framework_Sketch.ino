/*This simple sketch is my take on the overall control of the game. 
One button starts the game. The other launches the balls. 
You will need to define the digital pins according to how you wire 
your buttons to your board of choice. I'm using the T-Display E-Paper 
with builtin buttons on pins 0 and 35.
 */
int startButton = 0;
int playButton = 35;

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println();
  Serial.println("Press start!");
  pinMode(startButton, INPUT);
  pinMode(playButton, INPUT);
}

void loop() {
  int startbuttonState = digitalRead(startButton);
  if(startbuttonState == 0){    
  Serial.println("Game on!");
  int plays = 1;
  while(plays <= 3){
  int playbuttonState = digitalRead(playButton);
  if(playbuttonState == 0){ 
    Serial.println(plays);
    delay(5000); //pretend pinball stuff is happening here
    Serial.println("Play over");
    plays++;
  delay(1);        // delay in between reads for stability
  } //if play == 0
  } //while plays <= 3
    Serial.println("Game over");  
  } //if start == 0
}
