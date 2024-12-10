/*
 * MIT License
 *
 * Copyright (c) 2024 Logan Small
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef DEATHCLOCK_FACE_H_
#define DEATHCLOCK_FACE_H_

/*
 * DEATH CLOCK FACE
 *
 * Displays the amount of time you have left to live, based on your current age and life expectancy.
 */

#include "movement.h"

typedef struct {
  uint32_t age;
  uint32_t life_expectancy;
} deathclock_state_t;

void deathclock_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void deathclock_face_activate(movement_settings_t *settings, void *context);
bool deathclock_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void deathclock_face_resign(movement_settings_t *settings, void *context);

#define deathclock_face ((const watch_face_t){ \
    deathclock_face_setup, \
    deathclock_face_activate, \
    deathclock_face_loop, \
    deathclock_face_resign, \
    NULL, \
})

#endif // DEATHCLOCK_FACE_H_