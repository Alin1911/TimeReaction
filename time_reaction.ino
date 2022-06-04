#include <SD.h>
#include <TFT.h>
#include <SPI.h>

#define cs   10
#define dc   9
#define rst  8

#define buzz 3

#define TEXT_SIZE_1 10
#define START_QUESTION_1 10
#define START_ANSWER_1 90
TFT TFTscreen = TFT(cs, dc, rst);

#define BUTTON1        2
#define BUTTON2        4
#define BUTTON3        7
#define LED            5
#define LED1            6
#define TEXT_SIZE      1
#define START_QUESTION 0

int led_last_state     = LOW;
int button1_last_state = 0;
int button2_last_state = 0;
int button3_last_state = 0;

long startTime         = 0;
long endTime           = 0;
long final_time        = 0;
int start_index        = 0;

int corect_answer      = -1;

int question           = -1;

long timp[5];
char cstr[25];

void setup() {
  pinMode(buzz, OUTPUT);

  //LED
  pinMode(LED, OUTPUT);
  pinMode(LED1, OUTPUT);

  //BUTOANE
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);

  //INIALIZARE LCD
  TFTscreen.begin();
  TFTscreen.background(0, 0, 0);
  TFTscreen.stroke(0, 255, 0);
  //TEXT SIZE
  TFTscreen.setTextSize(1);

}
void printLogo() {
  int redRandom = random(0, 255);
  int greenRandom = random (0, 255);
  int blueRandom = random (0, 255);
  TFTscreen.stroke(redRandom, greenRandom, blueRandom);
  TFTscreen.text("Reaction Time", 6, 7);
  TFTscreen.stroke(255, 255, 255);
}

void detectButton() {
  if (digitalRead(BUTTON1) == 1) {
    button1_last_state = 1;
  } else if (digitalRead(BUTTON2) == 1) {
    button2_last_state = 1;
  } else if (digitalRead(BUTTON3) == 1) {
    button3_last_state = 1;
  }
}

void questionCall() {
  if(question == -1){
    printStart();
  } else if (question == 0) {
    question0();
  } else if (question == 1) {
    question1();
  } else if (question == 2) {
    question2();
  } else if (question == 3) {
    question3();
  } else if (question == 4) {
    question4();
  } else if (question == 5) {
    question5();
  } else if (question == 6) {
    question6();
  } else if (question == 7) {
    question7();
  } else if (question == 8) {
    question8();
  } else if (question == 9) {
    question9();
  } else if (question == 10) {
    question10();
  } else if (question == 11) {
    question11();
  } else {
    question = random(0, 1);
    TFTscreen.background(0, 0, 0);
  }
}

void timeCalcul() {
  for (int i = 0; i < 5; ++i)
  {
    final_time += timp[i];
  }
  final_time /= 5;
}

void correctAnswer() {
  endTime = millis();
  timp[start_index] = endTime - startTime;
  question = random(2 * start_index, 2 * (start_index + 1) + 2);
  TFTscreen.background(0, 0, 0);

  tone(buzz, 7500);
  digitalWrite(LED1, HIGH);
  delay(50);
  noTone(buzz);
  digitalWrite(LED1, LOW);
  delay(100);

  startTime = 0;
  endTime = 0;
  button2_last_state = 0;
  button1_last_state = 0;
  start_index++;
  startTime = millis();
}

void wrongAnswer() {
  timp[start_index] = 6000;
  question = random(2 * start_index, 2 * (start_index + 1) + 2);
  TFTscreen.background(0, 0, 0);

  tone(buzz, 5000);
  digitalWrite(LED, HIGH);
  delay(50);
  noTone(buzz);
  digitalWrite(LED, LOW);
  delay(100);

  startTime = 0;
  endTime = 0;
  button2_last_state = 0;
  button1_last_state = 0;
  start_index++;
  startTime = millis();
}

void restart() {
  for (int i = 0; i < 5; ++i)
  {
    timp[i] = 0;
  }
  final_time = 0;
  start_index = 0;

  tone(buzz, 5000, 100);
  digitalWrite(LED, HIGH);
  digitalWrite(LED1, HIGH);
  delay(50);
  noTone(buzz);
  digitalWrite(LED1, LOW);
  digitalWrite(LED, LOW);
  delay(100);

  endTime = 0;
  question = random(0, 2);

  TFTscreen.background(0, 0, 0);
  button3_last_state = 0;
  startTime = millis();
}

void printTime() {
  for (int i = 0; i < 5; ++i)
  {
    itoa(timp[i], cstr, 10);
    if (timp[i] != 0) {
      TFTscreen.text(cstr, START_ANSWER_1, ((i + 1) * TEXT_SIZE_1));
    }
  }
  if (final_time != 0) {
    itoa(final_time, cstr, 10);
    TFTscreen.text(cstr, START_ANSWER_1, (9 * TEXT_SIZE_1));
  }
}
void loop() {
  printLogo();
  detectButton();

  if (start_index < 5) {
    questionCall();
  } else if (start_index >= 5 && final_time == 0){
    timeCalcul();
    printStart();
  }

  if (button2_last_state == 1 && corect_answer == 2) {
    correctAnswer();
  } else if (button1_last_state == 1 && corect_answer == 1) {
    correctAnswer();
  } else if (button2_last_state == 1 && corect_answer == 1) {
    wrongAnswer();
  } else if (button1_last_state == 1 && corect_answer == 2) {
    wrongAnswer();
  } else if (button3_last_state == 1) {
    restart();
  } else {
    printTime();
  }
}
void printStart(){
  TFTscreen.text("START", START_QUESTION_1, (7 * TEXT_SIZE_1));
}

void question0() {
  TFTscreen.text("Rosia este", START_QUESTION_1, (3 * TEXT_SIZE_1));
  TFTscreen.text("un fruct.", START_QUESTION_1, (4 * TEXT_SIZE_1));
  corect_answer = 1;
}

void question1() {
  TFTscreen.text("Capitala", START_QUESTION_1, (3 * TEXT_SIZE_1));
  TFTscreen.text("Angliei", START_QUESTION_1, (4 * TEXT_SIZE_1));
  TFTscreen.text("e Rusia", START_QUESTION_1, (5 * TEXT_SIZE_1));
  corect_answer = 2;
}

void question2() {
  TFTscreen.text(" 1 + 2 = 3", START_QUESTION_1, (3 * TEXT_SIZE_1));
  corect_answer = 1;
}

void question3() {
  TFTscreen.text("Patrat verde", START_QUESTION_1, (3 * TEXT_SIZE_1));
  for (int i = 0; i < 20; i++){
    TFTscreen.drawRect(10 + i, 60 + i, 40 - 2 * i, 40 - 2 * i, 0xF800);
  }
  corect_answer = 2;
}

void question4() {
  TFTscreen.text("Marul este", START_QUESTION_1, (3 * TEXT_SIZE_1));
  TFTscreen.text("fruct.", START_QUESTION_1, (4 * TEXT_SIZE_1));
  corect_answer = 1;
}

void question5() {
  TFTscreen.text("Pinguinul", START_QUESTION_1, (3 * TEXT_SIZE_1));
  TFTscreen.text("este mamifer.", START_QUESTION_1, (4 * TEXT_SIZE_1));
  corect_answer = 2;
}

void question6() {
  TFTscreen.text("Varza este", START_QUESTION_1, (3 * TEXT_SIZE_1));
  TFTscreen.text("o leguma.", START_QUESTION_1, (4 * TEXT_SIZE_1));
  corect_answer = 1;
}

void question7() {
  TFTscreen.text("Capitala", START_QUESTION_1, (3 * TEXT_SIZE_1));
  TFTscreen.text("Angliei", START_QUESTION_1, (4 * TEXT_SIZE_1));
  TFTscreen.text("e Londra", START_QUESTION_1, (5 * TEXT_SIZE_1));
  corect_answer = 1;
}

void question8() {
  TFTscreen.text("1 -(-2) =-1", START_QUESTION_1, (3 * TEXT_SIZE_1));
  corect_answer = 2;
}

void question9() {
  TFTscreen.text("Patrat rosu", START_QUESTION_1, (3 * TEXT_SIZE_1));
    for (int i = 0; i < 20; i++){
    TFTscreen.drawRect(10 + i, 60 + i, 40 - 2 * i, 40 - 2 * i, 0xFFE0);
  }
  corect_answer = 2;
}

void question10() {
  TFTscreen.text("Negru este", START_QUESTION_1, (3 * TEXT_SIZE_1));
  TFTscreen.text("o culoare.", START_QUESTION_1, (4 * TEXT_SIZE_1));
  corect_answer = 2;
}

void question11() {
  TFTscreen.text("Ursul nu", START_QUESTION_1, (3 * TEXT_SIZE_1));
  TFTscreen.text("este mamifer.", START_QUESTION_1, (4 * TEXT_SIZE_1));
  corect_answer = 2;
}
