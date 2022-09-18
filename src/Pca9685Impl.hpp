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
#ifndef PCA9685IMPL_HPP_
#define PCA9685IMPL_HPP_

#include <rclcpp/rclcpp.hpp>
#include <memory>
#include <string>
#include "i2c_pwm/Pca9685.hpp"

namespace i2c_pwm
{

  class Pca9685Impl : public Pca9685
  {
  public:
    Pca9685Impl(const std::string &deviceFile,
                const int address,
                bool autoInitialize = true);
    virtual ~Pca9685Impl();

    void initialize() override;
    void allStop() override;

    void sleepMode(bool value) override;
    void setFrequencyHz(uint16_t value) override;

    uint8_t read(uint8_t reg) const override;
    void write(uint8_t reg, uint8_t data) override;
    void writeChannel(uint8_t channel, uint16_t offValue) override;
    void writeChannel(uint8_t channel, uint16_t onValue, uint16_t offValue)
        override;

  private:
    float pulseWidthToMillis(uint16_t pulseCounts) const;

    const std::string deviceFilePath_;
    const int address_;
    int fd_;
    uint8_t frequencyHz_;
    float frequencyScale_;
    rclcpp::Logger logger_;
  };

} // namespace i2c_pwm

#endif // PCA9685IMPL_HPP_
