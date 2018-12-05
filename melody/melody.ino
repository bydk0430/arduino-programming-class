// 하울의 움직이는 성 OST
// 음계
//  도0 262 레1 294 미2 330
//  파3 349 솔4 392 라5 440
//  시6 494 
//  도7 523 레8 587 #레9 622
//  미10 659 파11 698 #파12 740
//  솔13 784 #솔14 831
//  라15 880 시16 988
//  도17 1047 레18 1175

int melody[] = {262,294,330,349,392,440,494,523,587,622,659,698,740,
              784,831,880,988,1047,1175};

  int mel[] = {2,5,7,10,10,10,    8,7,6,7,7,7,
               5,7,9,15,15,15,    15,13,11,13,13,13,
               6,10,13,16,16,15,  13,12,13,15,15,13,
               12,10,8,7,8,10,8,5,6,6,6,

               16,15,13,15,12,12,12,12,14,13,
               14,15,16,17,17,17,17,17,17,12,12,11,
               12,13,15,16,16,16,16,16,16,12,10,12,
               15,13,12,10,9,10,12,12,16,18,18,17
    };           

void setup() {
  for(int i=0;i<93;i++) {
    tone(8,melody[mel[i]], 250);
    delay(400);
    noTone(8);
  }
}

void loop() {

}