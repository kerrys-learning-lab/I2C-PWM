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
#include "i2c_pwm/Pca9685.hpp"
#include "Pca9685Impl.hpp"
#include "Pca9685Mock.hpp"

namespace
{
  bool mockMode = false;
} // namespace

namespace i2c_pwm
{

  const uint8_t Pca9685::NUM_CHANNELS;
  const uint16_t Pca9685::MIN_VALUE;
  const uint16_t Pca9685::MAX_VALUE;

  std::shared_ptr<Pca9685> Pca9685::create(const std::string &deviceFile,
                                           const int address,
                                           bool autoInitialize)
  {
    if (mockMode)
    {
      return std::shared_ptr<Pca9685>(new Pca9685Mock(deviceFile,
                                                      address,
                                                      autoInitialize));
    }
    else
    {
      return std::shared_ptr<Pca9685>(new Pca9685Impl(deviceFile,
                                                      address,
                                                      autoInitialize));
    }
  }

  void Pca9685::setMockMode(bool value)
  {
    mockMode = value;
  }

}
