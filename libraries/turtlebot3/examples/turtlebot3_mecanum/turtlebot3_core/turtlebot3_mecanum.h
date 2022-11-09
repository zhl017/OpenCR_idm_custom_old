/*******************************************************************************
* Copyright 2016 ROBOTIS CO., LTD.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/* Authors: Yoonseok Pyo, Leon Jung, Darby Lim, HanCheol Cho */

#ifndef TURTLEBOT3_MECANUM_H_
#define TURTLEBOT3_MECANUM_H_

#define NAME                             "Mecanum"

#define WHEEL_RADIUS                     0.05            // meter (BURGER / WAFFLE : 0.033, MECANUM : 0.05)
#define WHEEL_SEPARATION_X               0.096           // meter (BURGER : 0.160, WAFFLE : 0.287, MECANUM : 0.192 / 2)
#define WHEEL_SEPARATION_Y               0.171           // meter (BURGER : 0.160, WAFFLE : 0.287, MECANUM : 0.342 / 2)
#define TURNING_RADIUS                   0.1961           // meter (BURGER : 0.080, WAFFLE : 0.1435, MECANUM : 0.1961)
#define ROBOT_RPM                        77              // rpm   (BURGER : 61, WAFFLE : 77, MECANUM(XM430-W350) : 46, MECANUM(XM430-W210) : 77)

#define ENCODER_MIN                      -2147483648     // raw
#define ENCODER_MAX                      2147483648      // raw

#define MAX_LINEAR_VELOCITY              (WHEEL_RADIUS * 2 * 3.14159265359 * ROBOT_RPM / 60) // m/s
#define MAX_ANGULAR_VELOCITY             (MAX_LINEAR_VELOCITY / TURNING_RADIUS)       // rad/s

#define MIN_LINEAR_VELOCITY              -MAX_LINEAR_VELOCITY  
#define MIN_ANGULAR_VELOCITY             -MAX_ANGULAR_VELOCITY 

#endif  //TURTLEBOT3_MECANUM_H_
