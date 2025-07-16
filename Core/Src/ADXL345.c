#include "ADXL345.h"


uint8_t ADXL345_Init (st_ADXL345 *dev, I2C_HandleTypeDef *i2cHandler)
{
    /*Store numbers of transaction errors (to be returned at end of function)*/
    uint8_t errNum = 0;
    HAL_StatusTypeDef status;

    uint8_t regData;

    /*Set struct paramenters*/
    dev->i2cADXL_handler = i2cHandler;

    for(uint8_t index = 0; index < INDEX_ACC; index++)
    {
        dev->acc_mps2[index] = 0.0f;
    }

    status = ADXL345_ReadRegister (dev, DEVID, &regData);
    /*If the status is not HAL_OK add 1 to errNum*/
    errNum += (status != HAL_OK);

    if(regData != DEVID_RESULT)
    {
        return DEVID_NOT_MATCH;
    }

    
    

}


HAL_StatusTypeDef ADXL345_ReadRegister (st_ADXL345 *dev, uint8_t reg, uint8_t *data)
{
    return HAL_I2C_Mem_Read(dev->i2cADXL_handler, ADXL345_Address, reg, I2C_MEMADD_SIZE_8BIT, data, SIZE_REGISTER_READ, HAL_MAX_DELAY);
}


HAL_StatusTypeDef ADXL345_ReadRegisters (st_ADXL345 *dev, uint8_t reg, uint8_t *data, uint8_t length)
{
    return HAL_I2C_Mem_Read(dev->i2cADXL_handler, ADXL345_Address, reg, I2C_MEMADD_SIZE_8BIT, data, length, HAL_MAX_DELAY);
}


HAL_StatusTypeDef ADXL345_WriteRegister (st_ADXL345 *dev, uint8_t reg, uint8_t *data)
{
    return HAL_I2C_Mem_Write(dev->i2cADXL_handler, ADXL345_Address, reg, I2C_MEMADD_SIZE_8BIT, data, HAL_MAX_DELAY);
}

