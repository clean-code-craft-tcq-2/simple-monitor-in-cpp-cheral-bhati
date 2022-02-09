#include <assert.h>
#include <iostream>
using namespace std;

const float MAX_TEMPERATURE = 45.0;
const float MIN_TEMPERATURE = 0.0;
const float MAX_SOC = 80.0;
const float MIN_SOC = 20.0;
const float MAX_CHARGERATE = 0.8;
const float MIN_CHARGERATE = 0.0;

int checkValueinRange(const float maxValue, const float minValue, const float ValuetoCheck)
{
  if (ValuetoCheck < minValue)
  {
    return -1 ;
  }
  else if (ValuetoCheck > maxValue)
  {
    return 0;
  }
  return 1;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
  if(temperature < 0 || temperature > 45) {
    cout << "Temperature out of range!\n";
    return false;
  } else if(soc < 20 || soc > 80) {
    cout << "State of Charge out of range!\n";
    return false;
  } else if(chargeRate > 0.8) {
    cout << "Charge Rate out of range!\n";
    return false;
  }
  return true;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
