void setupWifi()
{
  connectingTo(ssid);

  delay(1000);
  lcd.clear();

  WiFi.begin(ssid, password);

  lcd.setCursor(0, 0);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(400);
    dot();
  }

  connected(WiFi.localIP(), WiFi.RSSI());
}
