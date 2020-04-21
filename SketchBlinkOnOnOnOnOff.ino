// https://habr.com/ru/post/352806/
int Led = 13; // объявляем переменную Led на 13 пин (выход)
void setup(){
    pinMode(Led, OUTPUT); // определяем переменную
}

int TimeSlot=1000;

void loop()
{  int DurationOn=TimeSlot*0.5;
   int DurationOff=TimeSlot-DurationOn;
    digitalWrite(Led, HIGH); // подаём напряжение на 13 пин
    delay(DurationOn); // ожидаем 0.5 секунд
     digitalWrite(Led, HIGH); // подаём напряжение на 13 пин
    delay(DurationOn); // ожидаем 0.5 секунд
     digitalWrite(Led, HIGH); // подаём напряжение на 13 пин
    delay(DurationOn); // ожидаем 0.5 секунд
     digitalWrite(Led, HIGH); // подаём напряжение на 13 пин
    delay(DurationOn); // ожидаем 0.5 секунд
     digitalWrite(Led, HIGH); // подаём напряжение на 13 пин
    delay(DurationOn); // ожидаем 0.5 секунд
    digitalWrite(Led, LOW); // не подаём напряжение на 13 пин
    delay(DurationOff); // ожидаем 0.5 секунд
  }
