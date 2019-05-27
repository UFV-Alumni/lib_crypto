#include <SPI.h>
#include "libcrypto.c"

//void sprint(unsigned char out[][4]){
//    for (int i = 0; i < 4; i++) {
//        for (int j = 0; j < 4; j++)
//            Serial.print(out[i][j]);
//        Serial.println();
//    }
//}

unsigned long timer1;
//unsigned long acc;
//skipjack_key skey;
//rc2_key skey;
//unsigned char Skey[10] = {0x94,0x74,0xB8,0xE8,0xC7,0x3B,0xCA,0x7D,0xCA,0x7D};
//unsigned char Bkey[8]  = {0x94,0x74,0xB8,0xE8,0xC7,0x3B,0xCA,0x7D};
//unsigned char key[16]  = {0x94,0x74,0xB8,0xE8,0xC7,0x3B,0xCA,0x7D,0x53,0x23,0x91,0x42,0xf3,0xc3,0x12,0x1a};
//uint32_t key[16]  = {0x94,0x74,0xB8,0xE8,0xC7,0x3B,0xCA,0x7D,0x53,0x23,0x91,0x42,0xf3,0xc3,0x12,0x1a};


//int i = 1;
//int led = 13;

////AES
static unsigned char key[4][4] = {
        {0xE8, 0xE9, 0xEA, 0xEB},
        {0xED, 0xEE, 0xEF, 0xF0},
        {0xF2, 0xF3, 0xF4, 0xF5},
        {0xF7, 0xF8, 0xF9, 0xFA}};

unsigned char input[4][4] = {
        {0x8C, 0xA1, 0x89, 0x0D},
        {0xBF, 0xE6, 0x42, 0x68},
        {0x41, 0x99, 0x2D, 0x0F},
        {0xB0, 0x54, 0xBB, 0x16}};

unsigned char w[40][4];

unsigned char out[4][4];

void setup() {
  // put your setup code here, to run once:
   Serial.begin(115200);
//   subkey(key,w);
//   rc2_setup (key, 16, 0, &skey);
//   skipjack_setup(Skey, 10, 0, &skey);
//   pinMode(PIND2, OUTPUT);
//   pinMode(led, OUTPUT);   
//   delay(600); 
}

void loop() {
  //digitalWrite(PIND2, HIGH);
  //digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  //sprint(input);
  //unsigned char pt[8]= {0x28, 0x85, 0x84, 0x2e, 0xa3, 0xe6, 0x99, 0x9b};
  //unsigned char ct[8];
  timer1 = micros();
  //skipjack_encrypt(pt, ct, &skey);
  //rc2_encrypt(pt,ct,&skey);
  //xtea_encrypt(pt,ct,key);
  //rc4_encrypt(pt,8);
  //xxtea_encrypt(pt,8);
  aes_encrypt(input, out, w);
  
  timer1 = micros()-timer1;
  Serial.print("TEMPO: ");
  Serial.println(timer1);
  //sprint(out);
  //digitalWrite(PIND2, LOW);

//  for(i=0;i<8;i++){
//    Serial.print(ct[i],HEX );
//    Serial.print(" ");  
//  }
//  Serial.println();
//
//  skipjack_encrypt(pt, ct, &skey);
//  //rc2_decrypt(ct,pt,&skey);
//  //xtea_decrypt(pt,ct,key);
//  //rc4_decrypt(pt,8);
//  //xxtea_decrypt(pt,8);
//  
//  for(i=0;i<8;i++){
//    Serial.print(pt[i],HEX );
//    Serial.print(" ");  
//  }
//  Serial.println();
//  
//  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
//  
//  delay(500);   
}
