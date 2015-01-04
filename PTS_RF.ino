
/*
 Copyright (c) 2014 OpenSourceRF.com.  All right reserved.

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 See the GNU Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <RFduinoBLE.h>

int lampPin = 2;

void setup()
{
  RFduinoBLE.deviceName = "Lamp";
  RFduinoBLE.advertisementData = "Office";
  RFduinoBLE.advertisementInterval = MILLISECONDS(300);
  RFduinoBLE.txPowerLevel = -20;  // (-20dbM to +4 dBm)

  pinMode(lampPin, OUTPUT);
  // start the BLE stack
  RFduinoBLE.begin();

  Serial.begin(9600);
  Serial.println("Hello!");
}

void loop()
{
  // switch to lower power mode
  RFduino_ULPDelay(INFINITE);  

}

void RFduinoBLE_onAdvertisement(bool start)
{
  if (start)
    Serial.println("On advertise Start");
  else
    Serial.println("On advertise end");
}

void RFduinoBLE_onConnect()
{
  Serial.println("On Connect");
}

void RFduinoBLE_onDisconnect()
{
  Serial.println("On Disconnect");
}

// returns the dBm signal strength indicated by the receiver after connection (-0dBm to -127dBm)
void RFduinoBLE_onRSSI(int rssi)
{
}

void RFduinoBLE_onReceive(char *data, int len)
{
  digitalWrite(lampPin, data[0]); 
  Serial.print("Writing Pin Data"); Serial.println(data[0]);
}
