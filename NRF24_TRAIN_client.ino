#include <SPI.h>
#include <RH_NRF24.h>

int trainID = 1234; // train ID


//8 bit variable 2 variable array because we can only send bytes through the nrf 
uint8_t id[2];
//vsc pins 
RH_NRF24 nrf24(7, 8);  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  if (!nrf24.init()) {
    Serial.println("init failed");
  }

  if (!nrf24.setChannel(1)) {
    Serial.println("setChannel failed");
  }

  if (!nrf24.setRF(RH_NRF24::DataRate2Mbps, RH_NRF24::TransmitPower0dBm)) {
  }

    id[1] = trainID & 255; // in arduino int byte size =2
  id[0] = trainID >> 8; //bitwise 


}

void loop() {
  // put your main code here, to run repeatedly:
  nrf24.send(id, sizeof(id)); // send command requires array and array size 
  nrf24.waitPacketSent();  
  delay(100);

}
