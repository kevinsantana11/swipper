#include "config.h"

#define TRIGGER_PIN CONF_TRIGGER_PIN
#define ECHO_PIN CONF_ECHO_PIN
#define GREEN_PIN CONF_GREEN_PIN
#define YELLOW_PIN CONF_YELLOW_PIN
#define RED_PIN CONF_RED_PIN
#define SPEAKER_PIN CONF_SPEAKER_PIN

void sensors_configure(void);

void sensors_run(void);