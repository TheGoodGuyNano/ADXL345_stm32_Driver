#ifndef ADXL345_H
#define ADXL345_H

/*
Date: 08/07/2025
Author: Gonzalez Alejandro (Nano)
ADXL345.h 
*/

#include "stm32f1xx_hal.h"

#define ADXL345_Address         (0x1DU<<1)  /*Main address*/
#define ADXL345_Address_alt     (0x53U<<1)  /*Alternative address 2do device*/

#define DEVID                   0x00U       /*Device ID, holds a fixed  device of 0xE5*/
#define DEVID_RESULT            0xE5U       /*Response of device ID*/
#define THRESH_TAP              0xD1U       /*Tap threshold*/
#define OFSX                    0x1EU       /*X-axis offset*/
#define OFSY                    0x1FU       /*Y-axis offset*/
#define OFSZ                    0x20U       /*Z-axis offset*/
#define DUR                     0x21U       /*Tap duration*/
#define LATENT                  0x22U       /*Tap latency*/
#define WINDOW                  0x23U       /*Tap window*/
#define THRESH_ACT              0x24U       /*Activity threshold*/
#define THRESH_INACT            0x25U       /*Inactivity threshold*/
#define TIME_INACT              0x26U       /*Inactivity time*/
#define ACT_INACT_CTL           0x27U       /*Axis enable control for activity and inactivity detection*/
#define THRESH_FF               0x28U       /*Free-fall threshold*/
#define TIME_FF                 0x29U       /*Free-fall time*/
#define TAP_AXES                0x2AU       /*Axis control for single tap/double tap*/
#define ACT_TAP_STATUS          0x2BU       /*Source of single tap/double tap*/
#define BW_RATE                 0x2CU       /*Data rate and power mode control*/
#define POWER_CTL               0x2DU       /*Power-saving features control*/
#define INT_ENABLE              0x2EU       /*Interrupt enable control*/
#define INT_MAP                 0x2FU       /*Interrupt mapping control*/
#define INT_SOURCE              0x30U       /*Source of interrupts*/
#define DATA_FORMAT             0x31U       /*Data format control*/
#define DATAX0                  0x32U       /*X-Axis Data 0*/
#define DATAX1                  0x33U       /*X-Axis Data 1*/
#define DATAY0                  0x34U       /*Y-Axis Data 0*/
#define DATAY1                  0x35U       /*Y-Axis Data 1*/
#define DATAZ0                  0x36U       /*Z-Axis Data 0*/
#define DATAZ1                  0x37U       /*Z-Axis Data 1*/
#define FIFO_CTL                0x38U       /*FIFO control*/
#define FIFO_STATUS             0x39U       /*FIFO status*/

typedef struct
{
    /*I2C handle*/
    I2C_HandleTypeDef *i2cADXL_handler;
    /*Accelerometer data (x,y,z) m/s^2*/
    float acc_mps2[3];
}st_ADXL345;


/**
  * @brief  Initialize ADXL345 Device with i2c
  * @param  dev: Initialize struct for ADXL345
  * @param  i2cHandler: i2c channel handler configured
  * @retval 1:True or 0:False
  */
uint8_t ADXL345_Init (st_ADXL345 *dev, I2C_HandleTypeDef *i2cHandler);


/**
  * @brief  Initialize ADXL345 Device with i2c
  * @param  dev: Reads the Acceletations from the device, stored in 'dev'
  * @retval HAL_StatusTypeDef
  */
HAL_StatusTypeDef ADXL345_ReadAccelerations(st_ADXL345 *dev);


#endif /*ADXL345_H*/