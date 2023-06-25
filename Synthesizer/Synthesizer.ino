int Freq_Bass = 189;
int Bass_const = 31;
int Freq_Middle = 3779;
int Middle_const = 221;
int Freq_Treble = 5999;
int Treble_const = 4001;
int Switch1 = 7;
int Switch2 = 8;
int Switch3 = 9;
int time = 0;
int PWM_pin = 3;

float Vibrato(float R1, int freq_const, float R2) {
  float a = R1 * freq_const * sin(R2*time/3.14157);
  return a;
};

void Mode() {
  int a1 = digitalRead(Switch1);
  int a2 = digitalRead(Switch2);
  int a3 = digitalRead(Switch3);
  if ((a1 == 0) and (a2 == 0)) {
    noTone(PWM_pin);
  }
  else if ((a1 == 0) and (a2 == 1)) {
    float R1 = analogRead(A1)/1023.0;
    float R2 = analogRead(A2)/1023.0;
    float R = analogRead(A0)/1023.0;
    Serial.println(round(Freq_Bass * R)+Bass_const);
    if (a3 == 1) {
      tone(PWM_pin, round(Freq_Bass * R + Bass_const + Vibrato(R1, Bass_const, R2)));
      delay(1000/round(Freq_Bass * R + Bass_const + Vibrato(R1, Bass_const, R2)));
    }
    else {
      tone(PWM_pin, round(Freq_Bass * R + Bass_const));
      delay(1000/round(Freq_Bass * R + Bass_const));
    }
    
  }
  else if ((a1 == 1) and (a2 == 0)) {
    float R1 = analogRead(A1)/1023.0;
    float R2 = analogRead(A2)/1023.0;
    float R = analogRead(A0)/1023.0;
    Serial.println(round(Freq_Middle * R)+Middle_const);
    if (a3 == 1) {
      tone(PWM_pin, round(Freq_Middle * R + Middle_const + Vibrato(R1, Middle_const, R2)));
      delay(1000/round(Freq_Middle * R + Middle_const + Vibrato(R1, Middle_const, R2)));
    }
    else {
      tone(PWM_pin, round(Freq_Middle * R + Middle_const));
      delay(1000/round(Freq_Middle * R + Middle_const));
    }
  }
  else if ((a1 == 1) and (a2 == 1)) {
    float R1 = analogRead(A1)/1023.0;
    float R2 = (analogRead(A2)/1023.0);
    float R = analogRead(A0)/1023.0;
    Serial.println(round(Freq_Treble * R)+Treble_const);
    if (a3 == 1) {
      tone(PWM_pin, round(Freq_Treble * R + Treble_const + Vibrato(R1, Treble_const, R2)));
      delay(1/round(Freq_Treble * R + Treble_const + Vibrato(R1, Treble_const, R2)));
    }
    else {
      tone(PWM_pin, round(Freq_Treble * R + Treble_const));
      delay(1000/round(Freq_Treble * R + Treble_const));
    }
  };
}

void setup() {
  Serial.begin(9600); 


}

void loop() {
  Mode();
  time++;
}
