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
#ifndef I2C_PWM__PCA9685_HPP_
#define I2C_PWM__PCA9685_HPP_

#include <memory>
#include <stdint.h>
#include <string>

namespace i2c_pwm
{

  class Pca9685
  {
  public:
    static const uint8_t NUM_CHANNELS = 16;
    static const uint16_t MIN_VALUE = 0;
    static const uint16_t MAX_VALUE = 4096; // 2**12

    static std::shared_ptr<Pca9685> create(const std::string &deviceFile,
                                           const int address,
                                           bool autoInitialize);

    static void setMockMode(bool value);

    virtual ~Pca9685()
    {
    }

    /**
     * (Re-)Initializes the PCA9685 with default settings.
     */
    virtual void initialize() = 0;

    /**
     * Stops all servos.
     */
    virtual void allStop() = 0;

    /**
     * Enables or disables low power (sleep) mode.
     *
     * Low power mode turns off the oscillator.  PWM control is disabled
     * in low-power mode.
     *
     * @param value determines whether sleep mode is enacted
     */
    virtual void sleepMode(bool value) = 0;

    /**
     * Adjust the output modulation frequency from 24Hz to 1526Hz.
     *
     * @param value the frequency (in Hz) [24, 1526]
     */
    virtual void setFrequencyHz(uint16_t value) = 0;

    /**
     * Reads and returns the 8-bit value contained in the given register.
     *
     * @param reg
     * @return
     */
    virtual uint8_t read(uint8_t reg) const = 0;

    /**
     * Writes the given 8-bit value to the specified register.
     *
     * @param reg
     * @param data
     */
    virtual void write(uint8_t reg, uint8_t data) = 0;

    /**
     * Writes (an assumed) onValue of 0 and the given offValue to the registers
     * associated with the specified channel.
     *
     * @param channel the PWM channel (0-based) to write the given data
     * @param offValue the off value for the given channel [0 - 4096]
     */
    virtual void writeChannel(uint8_t channel, uint16_t offValue) = 0;

    /**
     * Writes the given onValue and offValue to the registers
     * associated with the specified channel.
     *
     * @param channel the PWM channel (0-based) to write the given data
     * @param onValue the on value for the given channel [0 - 4096]
     * @param offValue the off value for the given channel [0 - 4096]
     */
    virtual void writeChannel(uint8_t channel,
                              uint16_t onValue,
                              uint16_t offValue) = 0;
  };

} // namespace i2c_pwm

#endif // I2C_PWM__PCA9685_HPP_
