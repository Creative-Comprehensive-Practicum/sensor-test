namespace constants {
enum class PIN {
  PWM1 = 5,
  PWM2 = 6,
  PWM3 = 9,
  PWM4 = 10,

  LED1 = 11,
  LED2 = 12,
  LED3 = 13,

  analog0 = A0,
  analog1 = A1,
  analog2 = A2,
  analog3 = A3,
  analog4 = A4,
  analog5 = A5,
};

namespace globals {
  
}

constexpr uint8_t analog_thresholds[4] = {2, 2, 2, 2};
constexpr uint8_t weights[4] = {2, 1, -1, -2};

constexpr uint8_t analog_pins[4] = {
  static_cast<uint8_t>(constants::PIN::analog0), 
  static_cast<uint8_t>(constants::PIN::analog1),
  static_cast<uint8_t>(constants::PIN::analog2),
  static_cast<uint8_t>(constants::PIN::analog3),
};

}

void setup() {
  

}

void loop() {
  for(int i = 0; i < 4; i++){
    auto ainput = analogRead(constants::analog_pins[i]);
    Serial.print((ainput > constants::analog_thresholds[i]) ? "white": "green");
    Serial.print(", ");
  }

  Serial.print('\n');

}
