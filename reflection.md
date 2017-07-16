# Reflection on PID Control project
## Implementation
Here I implemented a basic PID controller which has the form like below:
```
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
```
In `main.cpp`, I updated the error and clipped the steering value to [-1, 1].
```
pid.UpdateError(cte);

steer_value = pid.TotalError();
steer_value = std::max(-1.0, std::min(steer_value, 1.0));
```
## Tuning Process
At first, I used only P gain to control my car. The car was swinging through the road and could not finish the track.
* [Swinging Car](./video/swinging_car.mov)

As I decreased the P gain, the swinging became less, but the car was still not capable of finishing the track. After I had introduced the D gain, the car became stable on the road and could nearly complete the track.
* [Good Car](./video/good_car.mov)

After several experiments, I came up with control gain that is good enough to drive along the road.
```
// Kp Ki Kd
pid.Init(0.18, 0.0, 2.0);
```
For this project, it was enough to use only PD controller to complete the track. I supposed that there was no external force affecting the car.
