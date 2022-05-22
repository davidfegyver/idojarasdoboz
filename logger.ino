void connectingTo(String ssid)
{
  Serial.print("Connecting to: ");
  Serial.println(ssid);

  lcd.clear();

  lcd.print("Connecting to:");
  lcd.setCursor(0, 1);
  lcd.print(ssid);
}

void weatherbox()
{
  Serial.println("WeatherBox by davidfegyver");
  Serial.println("Starting up...");

  lcd.clear();

  lcd.print("     Weatherbox");
  lcd.setCursor(0, 1);
  lcd.print("  by davidfegyver");
}

void dot()
{
  Serial.print(".");
  lcd.print(".");
}

void connected(IPAddress ip, long rssi)
{
  Serial.println("\nWiFi connected");
  Serial.print("IP Address: ");
  Serial.println(ip);
  Serial.print("Wifi signal strength: ");
  Serial.print(rssi);
  Serial.println(" dBm");

  lcd.clear();
  lcd.print("Wifi connected!");
  lcd.setCursor(0, 1);
  lcd.print("IP: ");
  lcd.print(IpAddress2String(ip));
  lcd.setCursor(0, 2);
  lcd.print("Signal strength: ");
  lcd.setCursor(0, 3);
  lcd.print(rssi);
}

void connToOpenW()
{
  Serial.println("Connecting to OpenWeatherMap..");

  lcd.clear();
  lcd.print("Connecting to");
  lcd.setCursor(0, 1);
  lcd.print("OpenWeatherMap...");
}

void unexpectedResponse(String error)
{
  Serial.print("Unexpected response: ");
  Serial.println(error);

  lcd.clear();

  lcd.print("Unexpected response");
  lcd.setCursor(0, 1);
  lcd.print("from OpenWeatherMap: ");
  lcd.setCursor(0, 2);
  lcd.print(error);
}
void invalidResponse()
{
  Serial.println("Invalid response");

  lcd.clear();

  lcd.print("Invalid response");
  lcd.setCursor(0, 1);
  lcd.print("from OpenWeatherMap");
}

void deserializationFailed(String error)
{
  Serial.print("JSON deserialization failed");
  Serial.println(error);

  lcd.clear();

  lcd.print("JSON deserialization");
  lcd.setCursor(0, 1);
  lcd.print("failed:");
  lcd.setCursor(0, 2);
  lcd.print(error);
}

void logWeather(String weather, float temp, int pressure, int humidity)
{
  Serial.print("Weather: ");
  Serial.println(weather);
  Serial.print("Temperature: ");
  Serial.println(temp);
  Serial.print("Pressure: ");
  Serial.println(pressure);
  Serial.print("Humidity: ");
  Serial.println(pressure);

  lcd.clear();
  lcd.print(weather + ".");
  lcd.setCursor(0, 1);
  lcd.print("Temperature: ");
  lcd.print(temp);
  lcd.print("C");
  lcd.setCursor(0, 2);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");
  lcd.setCursor(0, 3);
  lcd.print("Pressure: ");
  lcd.print(pressure);
  lcd.print("hPa");
}

void requestSuccessful()
{
  Serial.println("Request successful!");
  lcd.clear();
  lcd.print("Request successful!");
}

String IpAddress2String(IPAddress ipAddress)
{
  return String(ipAddress[0]) + String(".") +
         String(ipAddress[1]) + String(".") +
         String(ipAddress[2]) + String(".") +
         String(ipAddress[3]);
}