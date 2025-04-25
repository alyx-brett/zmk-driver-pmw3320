#pragma once

#include <zephyr/drivers/sensor.h>
#include "pixart.h"

#ifdef __cplusplus
extern "C" {
#endif


#define PMW3320_REG_PRODUCT_ID 0x00
#define PMW3320_PRODUCT_ID 0x3B
#define PMW3320_REG_REVISION_ID 0x01
#define PMW3320_REVISION_ID 0x00

/* #define PMW3320_REG_MOTION 0x02 */
/* #define PMW3320_REG_DELTA_X_L 0x03 */
/* #define PMW3320_REG_DELTA_Y_L 0x04 */
/* #define PMW3320_REG_SQUAL 0x05 */
/* #define PMW3320_REG_SHUTTER_HIGHER 0x06 */
/* #define PMW3320_REG_SHUTTER_LOWER 0x07 */
/* #define PMW3320_REG_PIX_MAX 0x08 */
/* #define PMW3320_REG_PIX_AVG 0x09 */
/* #define PMW3320_REG_PIX_MIN 0x0A */
/* #define PMW3320_REG_PIXEL_GRAB 0x0B */
/* #define PMW3320_REG_DELTA_XY_H 0x0C */

#define PMW3320_REG_RESOLUTION 0x0D

#define PMW3320_REG_RUN_DOWNSHIFT 0x0E
#define PMW3320_REG_REST1_PERIOD 0x0F
#define PMW3320_REG_REST1_DOWNSHIFT 0x10
#define PMW3320_REG_REST2_PERIOD 0x11
#define PMW3320_REG_REST2_DOWNSHIFT 0x12
#define PMW3320_REG_REST3_PERIOD 0x13

#define PMW3320_REG_PERFORMANCE 0x22
#define PMW3320_PERFORMANCE_NORMAL 0x01
#define PMW3320_PERF_FORCE_AWAKE_MASK 0xF0
#define PMW3320_PERF_FORCE_AWAKE_DISABLE_MASK 0x0F

/* #define PMW3320_REG_FRAME_RATE 0x39 */

#define PMW3320_REG_POWER_UP_RESET 0x3A
#define PMW3320_POWERUP_CMD_RESET 0x5A
#define PMW3320_POWERUP_CMD_WAKEUP 0x96

/* #define PMW3320_REG_SHUTDOWN 0x3B */

#define PMW3320_REG_NOT_REV_ID 0x3F
#define PMW3320_NOT_REV_ID 0xFF

/* #define PMW3320_REG_BURST_READ_FIRST 0x42 */

#define PMW3320_REG_NOT_PROD_ID 0x4F
#define PMW3320_NOT_PROD_ID 0xC4

#define PMW3320_REG_MOTION_BURST 0x63
#define PMW3320_BURST_SIZE 3
#define PMW3320_X_L_POS 0
#define PMW3320_Y_L_POS 1
#define PMW3320_XY_H_POS 2

/* write command bit position */
#define SPI_WRITE_BIT BIT(7)

/* Helper macros used to convert sensor values. */
#define PMW3320_SVALUE_TO_CPI(svalue) ((uint32_t)(svalue).val1)
#define PMW3320_SVALUE_TO_TIME(svalue) ((uint32_t)(svalue).val1)

/** @brief Sensor specific attributes of PMW3320. */
enum pmw3320_attribute {

	/** Sensor CPI for both X and Y axes. */
	PMW3320_ATTR_CPI,

	/** Entering time from Run mode to REST1 mode [ms]. */
	PMW3320_ATTR_RUN_DOWNSHIFT_TIME,

	/** Entering time from REST1 mode to REST2 mode [ms]. */
	PMW3320_ATTR_REST1_DOWNSHIFT_TIME,

	/** Entering time from REST2 mode to REST3 mode [ms]. */
	PMW3320_ATTR_REST2_DOWNSHIFT_TIME,

	/** Sampling frequency time during REST1 mode [ms]. */
	PMW3320_ATTR_REST1_SAMPLE_TIME,

	/** Sampling frequency time during REST2 mode [ms]. */
	PMW3320_ATTR_REST2_SAMPLE_TIME,

	/** Sampling frequency time during REST3 mode [ms]. */
	PMW3320_ATTR_REST3_SAMPLE_TIME,

};

#ifdef __cplusplus
}
#endif
