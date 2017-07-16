#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Kd = Kd;
  this->Ki = Ki;

  previous_cte = 0;
  p_error = 0;
  i_error = 0;
  d_error = 0;
}

// Update error for each control part
void PID::UpdateError(double cte) {
  p_error = cte;

  d_error = cte - previous_cte;
  previous_cte = cte;

  i_error += cte;
}

// Return the calculated control value
double PID::TotalError() {
  return -(Kp * p_error + Kd * d_error + Ki * i_error);
}

