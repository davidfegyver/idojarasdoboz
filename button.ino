void setupButton()
{
  pinMode(button_pin, INPUT);
}
boolean readButtonState()
{
  return digitalRead(button_pin);
}
