#include "PID.h"

PID::PID() {
}

PID::~PID() {
}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * Initialize PID coefficients 
   */

  // start

  // Get the input from main.cpp
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;

  p_error  = 0.0;
  i_error  = 0.0;
  d_error  = 0.0;
  prev_cte = 0.0;

  // end

}

void PID::UpdateError(double cte) {
  /**
   * Update PID errors based on cte.
   */

  // start

  // Update the P.I.D controller
  p_error  = cte;
  i_error  = i_error + cte;
  d_error  = cte - prev_cte;

  prev_cte = cte;

  // end
}

double PID::TotalError() {
  /**
   * Calculate and return the total error
   */

  // start

  return -Kp * p_error - Ki * i_error - Kd * d_error;

  // end

}
