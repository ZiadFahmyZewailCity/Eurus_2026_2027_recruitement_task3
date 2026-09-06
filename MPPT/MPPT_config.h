#ifndef MPPT_CONFIG_H
#define MPPT_CONFIG_H

/* Algorithm Parameters */
#define MPPT_STEP_SIZE               0.001
#define MPPT_INITIAL_DUTY            0.5

/* Hardware Limits */
#define MPPT_MAX_DUTY                0.9
#define MPPT_MIN_DUTY                0.05

/* Noise Tolerance Thresholds */
#define MPPT_VOLTAGE_TOLERANCE       0.0001
#define MPPT_CONDUCTANCE_TOLERANCE   0.001

#endif // MPPT_CONFIG_H