#if defined (SPARK)
#include "Adafruit_MCP23017.h"
#else
#include <Wire.h>
#ifdef __AVR__
#include <avr/pgmspace.h>
#endif
#include "Adafruit_MCP23017.h"

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#endif //Spark

// minihelper to keep Arduino backward compatibility
static inline void wiresend(uint8_t x) {
#if (ARDUINO >= 100) || defined (SPARK)
	Wire.write((uint8_t) x);
#else
	Wire.send(x);
#endif
}

static inline uint8_t wirerecv(void) {
#if (ARDUINO >= 100) || defined (SPARK)
	return Wire.read();
#else
	return Wire.receive();
#endif
}

