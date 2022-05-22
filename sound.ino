// Some code found here is from https://github.com/theFPVgeek/WTV020SD16P

const unsigned int PLAY_PAUSE = 0xFFFE;
const unsigned int STOP = 0xFFFF;

const unsigned int VOLUME_MIN = 0xFFF0;
const unsigned int VOLUME_MAX = 0xFFF7;

unsigned int currentVolume = VOLUME_MAX;
int lastMicros = 0;

void setupSound()
{
  pinMode(sound_clk_pin, OUTPUT);
  pinMode(sound_data_pin, OUTPUT);
  setVolume(5);
}

void playVoice(unsigned int voiceNumber)
{
  sendCommand(voiceNumber);
}

void stopVoice()
{
  sendCommand(STOP);
}

void setVolume(unsigned int volume)
{
  if (volume < 8)
  {
    currentVolume = VOLUME_MIN + volume;
    sendCommand(currentVolume);
  }
}
void sendCommand(unsigned int command)
{
  digitalWrite(sound_clk_pin, LOW);
  delay(2);
  for (unsigned int mask = 0x8000; mask > 0; mask >>= 1)
  {
    digitalWrite(sound_clk_pin, LOW);
    delayMicroseconds(50);
    if (command & mask)
    {
      digitalWrite(sound_data_pin, HIGH);
    }
    else
    {
      digitalWrite(sound_data_pin, LOW);
    }
    delayMicroseconds(50);
    digitalWrite(sound_clk_pin, HIGH);
    delayMicroseconds(100);
    if (mask > 0x0001)
    {
      delay(2);
    }
  }
  delay(20);
}
