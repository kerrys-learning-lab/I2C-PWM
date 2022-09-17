// Copyright 2022 Kerry Johnson
//
// This file is part of I2C-PWM.
//
// I2C-PWM is free software: you can redistribute it and/or modify it under the
// terms of the GNU General Public License v3 as published by the Free Software
// Foundation.
//
// I2C-PWM is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
// A PARTICULAR PURPOSE. See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with
// I2C-PWM.  If not, see https://www.gnu.org/licenses/.
#include "Pca9685Mock.hpp"

namespace i2c_pwm
{

  Pca9685Mock::Pca9685Mock(const std::string & /* deviceFile */,
                           const int /* address */,
                           bool /* autoInitialize */)
      : logger_(rclcpp::get_logger("i2c_pwm.Pca9685Mock"))
  {
  }

  Pca9685Mock::~Pca9685Mock()
  {
  }

  void Pca9685Mock::initialize()
  {
    RCLCPP_INFO(logger_, "Pca9685Mock::initialize()");
  }

  void Pca9685Mock::allStop()
  {
    RCLCPP_INFO(logger_, "Pca9685Mock::allStop()");
  }

  void Pca9685Mock::sleepMode(bool value)
  {
    RCLCPP_INFO(logger_,
                "Pca9685Mock::sleepMode(value=%s)",
                value ? "true" : "false");
  }

  void Pca9685Mock::setFrequencyHz(uint16_t value)
  {
    RCLCPP_INFO(logger_, "Pca9685Mock::setFrequencyHz(value=%d)", value);
  }

  uint8_t Pca9685Mock::read(uint8_t reg) const
  {
    RCLCPP_INFO(logger_, "Pca9685Mock::read(reg=%d)", reg);
    return reg;
  }

  void Pca9685Mock::write(uint8_t reg, uint8_t data)
  {
    RCLCPP_INFO(logger_, "Pca9685Mock::write(reg=%d, data=%d)", reg, data);
  }

  void Pca9685Mock::writeChannel(uint8_t channel, uint16_t offValue)
  {
    RCLCPP_INFO(logger_,
                "Pca9685Mock::writeChannel(channel=%d, offValue=%d)",
                channel,
                offValue);
  }

  void Pca9685Mock::writeChannel(uint8_t channel,
                                 uint16_t onValue,
                                 uint16_t offValue)
  {
    RCLCPP_INFO(logger_,
                "Pca9685Mock::writeChannel(channel=%d, onValue=%d, offValue=%d)",
                channel,
                onValue,
                offValue);
  }

} // namespace i2c_pwm
