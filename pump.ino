void setupPump()
{
  pinMode(pump_pin, OUTPUT);
  switchPumpOff();
}
void switchPumpOn()
{
  digitalWrite(pump_pin, HIGH);
}
void switchPumpOff()
{
  digitalWrite(pump_pin, LOW);
}
