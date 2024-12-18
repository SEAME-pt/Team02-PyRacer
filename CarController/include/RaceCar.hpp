#pragma once

#include "Motor.hpp"
#include "Servo.hpp"
#include "PCA9685.hpp"
#include "SharedMemory.hpp"
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <iostream>
#include <chrono>
#include <thread>

extern int signalTo;

class RaceCar
{
  private:
    I2C* m_I2c;
    PCA9685* m_ServoPCA;
    PCA9685* m_motorPCA;
    Motor motorRight;
    Motor motorLeft;
    Servo servo;
    SharedMemory* sharedData;

  private:
    void setDirection(uint8_t angle);
    void setSpeed(int speed);

  public:
    RaceCar();
    ~RaceCar();

    void init(const std::string& i2cDevice, uint8_t motorAddress,
              uint8_t servoAddress);
    void run(void);
    void stop(void);
};