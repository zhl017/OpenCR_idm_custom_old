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

#include "../../include/mecanum/turtlebot3_mecanum_controller.h"

Turtlebot3MecanumController::Turtlebot3MecanumController()
{
  // const_cmd_vel_ = CONST_VEL;
}

Turtlebot3MecanumController::~Turtlebot3MecanumController()
{
  DEBUG_SERIAL.end();
}

bool Turtlebot3MecanumController::init(float max_lin_vel, float max_ang_vel, uint8_t scale_lin_vel, uint8_t scale_ang_vel)
{
  DEBUG_SERIAL.begin(57600);
  // 57600bps baudrate for RC100 control
  rc100_.begin(1);  

  max_lin_vel_ = max_lin_vel;
  min_lin_vel_ = (-1)*max_lin_vel;
  max_ang_vel_ = max_ang_vel;
  min_ang_vel_ = (-1)*max_ang_vel;
  scale_lin_vel_ = scale_lin_vel;
  scale_ang_vel_ = scale_ang_vel;

  DEBUG_SERIAL.println("Success to init Controller");
  return true;
}

bool Turtlebot3MecanumController::getRCdata(float *get_cmd_vel, uint16_t &raw_data)
{
  uint16_t received_data = 0;
  bool clicked_state = false;

  static float lin_x = 0.0, lin_y = 0.0, ang_z = 0.0;
  
  if (rc100_.available())
  {
    received_data = rc100_.readData();
    if (&raw_data != &Internal::dummy_raw_data_)
      raw_data = received_data;

    if (received_data == RC100_BTN_U)
    {
      lin_x = max_lin_vel_ / 2;
      lin_y = 0.0;
      ang_z = 0.0;
      clicked_state = true;
    }
    else if (received_data == RC100_BTN_D)
    {
      lin_x = min_lin_vel_ / 2;
      lin_y = 0.0;
      ang_z = 0.0;
      clicked_state = true;
    }
    else if (received_data == RC100_BTN_L)
    {
      lin_x = 0.0;
      lin_y = max_lin_vel_ / 2;
      ang_z = 0.0;
      clicked_state = true;
    }
    else if (received_data == RC100_BTN_R)
    {
      lin_x = 0.0;
      lin_y = min_lin_vel_ / 2;
      ang_z = 0.0;
      clicked_state = true;
    }
    else if (received_data == RC100_BTN_2)
    {
      lin_x = 0.0;
      lin_y = 0.0;
      ang_z = max_ang_vel_;
      clicked_state = true;
    }
    else if (received_data == RC100_BTN_4)
    {
      lin_x = 0.0;
      lin_y = 0.0;
      ang_z = min_ang_vel_;
      clicked_state = true;
    }
    else if (received_data == (RC100_BTN_U + RC100_BTN_L))
    {
      lin_x = max_lin_vel_ / 2;
      lin_y = max_lin_vel_ / 2;
      clicked_state = true;
    }
    else if (received_data == (RC100_BTN_U + RC100_BTN_R))
    {
      lin_x = max_lin_vel_ / 2;
      lin_y = min_lin_vel_ / 2;
      clicked_state = true;
    }
    else if (received_data == (RC100_BTN_D + RC100_BTN_L))
    {
      lin_x = min_lin_vel_ / 2;
      lin_y = max_lin_vel_ / 2;
      clicked_state = true;
    }
    else if (received_data == (RC100_BTN_D + RC100_BTN_R))
    {
      lin_x = min_lin_vel_ / 2;
      lin_y = min_lin_vel_ / 2;
      clicked_state = true;
    }
    else if (received_data == RC100_BTN_6)
    {
      lin_x = max_lin_vel_;
      lin_y = 0.0;
      ang_z = 0.0;
      clicked_state = true;
    }
    else if (received_data == RC100_BTN_5)
    {
      lin_x = 0.0;
      lin_y = 0.0;
      ang_z = 0.0;
      clicked_state = true;
    }
    else
    {
      lin_x = lin_x;
      lin_y = lin_y;
      ang_z = ang_z;
    }

    // lin_x = constrain(lin_x, min_lin_vel_, max_lin_vel_);
    // lin_y = constrain(lin_y, min_lin_vel_, max_lin_vel_);
    // ang_z = constrain(ang_z, min_ang_vel_, max_ang_vel_);

    get_cmd_vel[0] = lin_x;
    get_cmd_vel[1] = lin_y;
    get_cmd_vel[2] = ang_z;

  }

  return clicked_state;
}
