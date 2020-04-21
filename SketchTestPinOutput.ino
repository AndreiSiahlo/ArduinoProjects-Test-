int outputPin = 13,ControlledPin=13;
int NumberOfPins=20;
char val='R';
int iPin=13;
int TimeSlot0 = 4000; //1second
int TimeSlotMin = 125, TimeSlotMax =16000;  //good values 124 and 16000,  bad value was TimeSlot0 * 16 (4000*16) and 32000
int TimeDelayInLoop = TimeSlot0 / 100;  // Both variables: TimeDelayInLoop and TimeDelayInLoopT[] are required

int outputPinT[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int TimeSlotT[20];
int FlashModeT[20];
int MustBeOnOffT[20]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int DurationOnOffT[20];
int TimeDelayInLoopT[20];

void setup()
{ Serial.begin(9600); // Скорость 9600 бит/сек
  // put your setup code here, to run once:
  ControlledPin = 13;
  for(iPin=1;iPin<=NumberOfPins;iPin++)
  {TimeSlotT[iPin] = 1000;
   FlashModeT[iPin]=1;  
   MustBeOnOffT[iPin]=1;
   DurationOnOffT[iPin]=1;
   TimeDelayInLoopT[iPin]=TimeSlotT[iPin]/10;
   pinMode(outputPinT[iPin], OUTPUT);  // режим вывода
  }}

void loop()
{ // put your main code here, to run repeatedly:
  if (Serial.available())
  { // если есть принятый символ
    val = Serial.read(); //сохраняем в val
    Serial.println(val);
    if (val == '7')     // Если принят символ '7'
    { ControlledPin = 7;}
    if (val == '8')     // Если принят символ '8'
    { ControlledPin = 8;}
    if (val == '9')     // Если принят символ '9'
    { ControlledPin = 9;}
    if (val == 'A')     // Если принят символ 'A'
    { ControlledPin = 10;}
    if (val == 'B')     // Если принят символ 'B'
    { ControlledPin = 11;}
    if (val == 'C')     // Если принят символ 'B'
    { ControlledPin = 12;}
    if (val == 'D')     // Если принят символ 'D'
    { ControlledPin = 13;}
    
    if (val == 'R')     // Если принят символ 'R'
    { ControlledPin = 13;}
    pinMode(outputPin, OUTPUT);
    if (val == 'Y')     // Если принят символ 'Y'
    { ControlledPin = 11;}
    pinMode(outputPin, OUTPUT);
    if (val == 'G')     // Если принят символ 'Y'
    { ControlledPin = 9;}
    
    pinMode(ControlledPin, OUTPUT);
    
    if (val == 'H')     // Если принят символ 'H'
    { Serial.println("High");
      Serial.println("ControlledPin");
      Serial.println(ControlledPin);
      FlashModeT[ControlledPin] = 0;
      digitalWrite(ControlledPin, HIGH); // То включаем светодиод
    }
    if (val == 'L')     // Если принят символ 'L'
    { Serial.println("Low");
      Serial.println("ControlledPin");
      Serial.println(ControlledPin);
      FlashModeT[ControlledPin] = 0;
      digitalWrite(ControlledPin, LOW); // То выключаем светодиод
    }
    if (val == 'F')
    { Serial.println("Flash");
      Serial.println("ControlledPin");
      Serial.println(ControlledPin);
      FlashModeT[ControlledPin] = 1;
      MustBeOnOffT[ControlledPin]=1;
      TimeSlotT[ControlledPin] = TimeSlot0; 
      DurationOnOffT[ControlledPin] = 0;
    }
    if (val == '>')
    {DurationOnOffT[ControlledPin] = DurationOnOffT[ControlledPin] + TimeDelayInLoopT[ControlledPin]/8;
    }
    if (val == '+')
    {Serial.println(" ControlledPin");
     Serial.println(ControlledPin);
     TimeSlotT[ControlledPin] = TimeSlotT[ControlledPin]* 2;
     if(TimeSlotT[ControlledPin]>=TimeSlotMax)
        TimeSlotT[ControlledPin]=TimeSlotMax;
     Serial.println(" TimeSlotT[ControlledPin](now)");
     Serial.println(TimeSlotT[ControlledPin]);
     };  //  Note: TimeSlot can be as big as possible, because delay(InLoop) is used instead of delay(TimeSlot) 
     if (val == '-')
     { Serial.println(" TimeSlotT[ControlledPin](before)");
       Serial.println(TimeSlotT[ControlledPin]);
       TimeSlotT[ControlledPin] = TimeSlotT[ControlledPin] / 2;
       if(TimeSlotT[ControlledPin]<TimeSlotMin)
          TimeSlotT[ControlledPin]=TimeSlotMin;
       Serial.println(" TimeSlotT[ControlledPin](now)");
       Serial.println(TimeSlotT[ControlledPin]);
     };
     if (val == 'M')
     { Serial.println("ControlledPin=");
       Serial.println(ControlledPin);
       Serial.println("TimeSlotT[ControlledPin]");
       Serial.println(TimeSlotT[ControlledPin]);
       Serial.println("TimeSlotT[(int)ControlledPin]");
       Serial.println(TimeSlotT[(int)ControlledPin]);
      };
      if (val == '0')
      { for(iPin=1;iPin<=NumberOfPins;iPin++)TimeSlotT[iPin] = TimeSlot0;
        DurationOnOffT[iPin] = 0;
      }
     }
    
    iPin=ControlledPin;//DDDebug

    for(iPin=1;iPin<=NumberOfPins;iPin++)
    { DurationOnOffT[iPin] = DurationOnOffT[iPin] + TimeDelayInLoopT[iPin];
      if(FlashModeT[iPin] == 1)
      if (MustBeOnOffT[iPin] == 1)
      { digitalWrite(iPin, HIGH);
        if(DurationOnOffT[iPin] > TimeSlotT[iPin])
        { MustBeOnOffT[iPin] = 0;
          DurationOnOffT[iPin] = 0;
      }}
      if(FlashModeT[iPin] == 1)
      if (MustBeOnOffT[iPin] == 0)
     { digitalWrite(iPin,LOW);
       if(DurationOnOffT[iPin] > TimeSlotT[iPin])
       { MustBeOnOffT[iPin] = 1;
         DurationOnOffT[iPin] = 0;
    }}}
  
  delay(TimeDelayInLoop); // This command should be at the end of the loop()-function
  }
