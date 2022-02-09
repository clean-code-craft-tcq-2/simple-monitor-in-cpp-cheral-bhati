#include <assert.h>
#include <iostream>
using namespace std;

const float MAX_TEMPERATURE = 45.0;
const float MIN_TEMPERATURE = 0.0;
const float MAX_SOC = 80.0;
const float MIN_SOC = 20.0;
const float MAX_CHARGERATE = 0.8;
const float MIN_CHARGERATE = 0.0;

 bool checkValueinRange(const float maxValue, const float minValue, const float ValuetoCheck)
{
  if (ValuetoCheck < minValue || ValuetoCheck > maxValue )
  {
    return 0 ;
  }
  return 1;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
  bool checkTemperature = false;
  bool checkSOC = false;
  bool checkChargeRate = false;
  
  checkTemperature = checkValueinRange(MAX_TEMPERATURE, MIN_TEMPERATURE, temperature);
  checkSOC = checkValueinRange(MAX_SOC, MIN_SOC, soc);
  checkChargeRate = checkValueinRange(MAX_CHARGERATE, MIN_CHARGERATE, chargeRate);
  
  return checkTemperature && checkSOC && checkChargeRate;
}

  int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
