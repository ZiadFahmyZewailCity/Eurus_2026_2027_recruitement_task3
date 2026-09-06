#include <Arduino.h>
#include "mppt.h"
#include "mppt_config.h"

static float V_old = 0.0;
static float I_old = 0.0;
static float D_old = MPPT_INITIAL_DUTY;

float MPPT(float V, float I)
{
  float dV = V - V_old;
  float dI = I - I_old;

  float D;

  if (abs(dV) < MPPT_VOLTAGE_TOLERANCE)
  {
    if (dI > 0) 
        { D = D_old - MPPT_STEP_SIZE; }
    else if (dI < 0) 
        { D = D_old + MPPT_STEP_SIZE; }
    else 
        { D = D_old; }
  }
  else
  {
    float slope = dI / dV;
    float cond = -I / V;

    if (abs(slope - cond) < MPPT_CONDUCTANCE_TOLERANCE)
      { D = D_old; }
    else if (slope > cond)
      { D = D_old - MPPT_STEP_SIZE; }
    else
      { D = D_old + MPPT_STEP_SIZE; }
  }

  // limits
  if (D > MPPT_MAX_DUTY) {
    D = MPPT_MAX_DUTY; }
    
  if (D < MPPT_MIN_DUTY) {
    D = MPPT_MIN_DUTY; }

  // update memory
  V_old = V;
  I_old = I;
  D_old = D;

  return D;
}