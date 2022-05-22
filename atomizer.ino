void setupAtomizer()
{
  pinMode(atomizer_pin, OUTPUT);
  digitalWrite(atomizer_pin, HIGH);
}
void switchAtomizer()
{
  digitalWrite(atomizer_pin, LOW);
  delay(100);
  digitalWrite(atomizer_pin, HIGH);
}
