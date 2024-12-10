#include <stdlib.h>
#include "deathclock_face.h"
#include "watch.h"
#include "watch_utility.h"
#include "watch_private_display.h"


void deathclock_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
  (void) settings;

  if (*context_ptr == NULL) {
    *context_ptr = malloc(sizeof(deathclock_state_t));
  }
}

void deathclock_face_activate(movement_settings_t *settings, void *context) {
  (void) settings;

  memset(context, 0, sizeof(deathclock_state_t));
}

bool deathclock_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
  (void) settings;

  deathclock_state_t *state = (deathclock_state_t *) context;
  // char buf[14];

  // Respond to events
  switch (event.event_type) {
    // Switch to the next watch face
    // case EVENT_MODE_BUTTON_UP:
    //   movement_mode_to_next_face();
    //   break;
    case EVENT_TICK:
      watch_display_string("  KeyMan ", 0);
      break;

    default:
      return movement_default_loop_handler(event, settings);
  }
}

void deathclock_face_resign(movement_settings_t *settings, void *context) {
  (void) settings;
  (void) context;
}