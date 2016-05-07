/*
 *   Museo dell'Informatica Funzionante - Museo Interattivo di Archeologia Informatica
 *   Author: Andrea Milazzo aka mancausoft <andreamilazzo@mancausoft.org>
 * 
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *   
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */ 

#define KEY_0 6
#define KEY_1 13
#define KEY_2 12
#define KEY_3 11
#define KEY_4 10
#define KEY_5 9
#define KEY_6 8

#define STROBE 5
#define RESET 4

#define STROBE_ENABLE_TIME 15
#define STROBE_RELEASE_TIME_MS 50
#define RESET_TIME 500

#define RESET_KEY 0x12 // CTRL + R


void inline set_key(unsigned char key);

void setup() {
digitalWrite(STROBE,0);
pinMode(STROBE,OUTPUT);
digitalWrite(STROBE,0);
Serial.begin(250000);
  
digitalWrite(RESET,1);
pinMode(RESET,OUTPUT);
digitalWrite(RESET,1);

pinMode(KEY_0,OUTPUT);
pinMode(KEY_1,OUTPUT);
pinMode(KEY_2,OUTPUT);
pinMode(KEY_3,OUTPUT);
pinMode(KEY_4,OUTPUT);
pinMode(KEY_5,OUTPUT);
pinMode(KEY_6,OUTPUT);
}

unsigned char key;

void loop() {
  while (!Serial.readBytes(&key, 1));
  set_key(key);
  delay(STROBE_RELEASE_TIME_MS);
}


void inline set_key(unsigned char key)
{
  if(key == RESET_KEY) 
  {
    digitalWrite(RESET, 1);
    delayMicroseconds(RESET_TIME);
    digitalWrite(RESET, 0);
    return;
  }
  
  digitalWrite(KEY_0, key & 1);
  key >>=1;
  digitalWrite(KEY_1, key & 1);
  key >>=1;
  digitalWrite(KEY_2, key & 1);
  key >>=1;
  digitalWrite(KEY_3, key & 1);
  key >>=1;
  digitalWrite(KEY_4, key & 1);
  key >>=1;
  digitalWrite(KEY_5, key & 1);
  key >>=1;
  digitalWrite(KEY_6, key & 1);
  digitalWrite(STROBE,1);
  delayMicroseconds(STROBE_ENABLE_TIME);
  digitalWrite(STROBE,0);
}
