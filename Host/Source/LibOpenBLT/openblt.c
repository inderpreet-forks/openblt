/************************************************************************************//**
* \file         openblt.c
* \brief        OpenBLT host library source file.
* \ingroup      Library
* \internal
*----------------------------------------------------------------------------------------
*                          C O P Y R I G H T
*----------------------------------------------------------------------------------------
*   Copyright (c) 2017  by Feaser    http://www.feaser.com    All rights reserved
*
*----------------------------------------------------------------------------------------
*                            L I C E N S E
*----------------------------------------------------------------------------------------
* This file is part of OpenBLT. OpenBLT is free software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published by the Free
* Software Foundation, either version 3 of the License, or (at your option) any later
* version.
*
* OpenBLT is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
* without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
* PURPOSE. See the GNU General Public License for more details.
*
* You have received a copy of the GNU General Public License along with OpenBLT. It 
* should be located in ".\Doc\license.html". If not, contact Feaser to obtain a copy.
* 
* \endinternal
****************************************************************************************/

/****************************************************************************************
* Include files
****************************************************************************************/
#include <assert.h>                         /* for assertions                          */
#include <stddef.h>                         /* for NULL declaration                    */
#include "openblt.h"                        /* OpenBLT host library                    */
#include "util.h"                           /* Utility module                          */


/****************************************************************************************
* Macro definitions
****************************************************************************************/
/** \brief The version number of the library as an integer. The number has two digits
 *         for major-, minor-, and build-version. Version 1.05.12 would for example be
 *         10512.
 */
#define BLT_VERSION_NUMBER   (10000u)

/** \brief The version number of the library as a null-terminated string. */
#define BLT_VERSION_STRING   "1.00.00"


/****************************************************************************************
* Local constant declarations
****************************************************************************************/
/** \brief Constant null-terminated string with the version number of the library. */
char const bltVersionString[] = BLT_VERSION_STRING;


/****************************************************************************************
*             V E R S I O N   I N F O R M A T I O N
****************************************************************************************/
/************************************************************************************//**
** \brief     Obtains the version number of the library as an integer. The number has two
**            digits for major-, minor-, and build-version. Version 1.05.12 would for
**            example return 10512.
** \return    Library version number as an integer.
**
****************************************************************************************/
LIBOPENBLT_EXPORT uint32_t BltVersionGetNumber(void)
{
  return BLT_VERSION_NUMBER;
} /*** end of BltVersionGetNumber ***/


/************************************************************************************//**
** \brief     Obtains the version number of the library as a null-terminated string. 
**            Version 1.05.12 would for example return "1.05.12".
** \return    Library version number as a null-terminated string.
**
****************************************************************************************/
LIBOPENBLT_EXPORT char const * BltVersionGetString(void)
{
  return BLT_VERSION_STRING;
} /*** end of BltVersionGetString ***/


/****************************************************************************************
*             S E S S I O N   /   T R A N S P O R T   L A Y E R S
****************************************************************************************/
/************************************************************************************//**
** \brief     Initializes the firmware update session for a specific communication
**            protocol and transport layer. This function is typically called once at
**            the start of the firmware update.
** \param     sessionType The communication protocol to use for this session. It should
**            be a BLT_SESSION_xxx value.
** \param     sessionSettings Pointer to a structure with communication protocol specific
**            settings.
** \param     transportType The transport layer to use for the specified communication
**            protocol. It should be a BLT_TRANSPORT_xxx value.
** \param     transportSettings Pointer to a structure with transport layer specific
**            settings.
**
****************************************************************************************/
LIBOPENBLT_EXPORT void BltSessionInit(uint32_t sessionType, 
                                      void const * sessionSettings,
                                      uint32_t transportType, 
                                      void const * transportSettings)
{
  /* Check parameters. Note that the settings-pointers are allowed to be NULL in case
   * no additional settings are needed for the specified session or transport type.
   */
  assert(sessionType == BLT_SESSION_XCP_V10);
  assert( (transportType == BLT_TRANSPORT_XCP_V10_RS232) || \
          (transportType == BLT_TRANSPORT_XCP_V10_CAN) );
  
  (void)sessionSettings;
  (void)transportSettings;
  
  /* TODO Implement. */
} /*** end of BltSessionInit ***/


/************************************************************************************//**
** \brief     Terminates the firmware update session. This function is typically called
**            once at the end of the firmware update.
**
****************************************************************************************/
LIBOPENBLT_EXPORT void BltSessionTerminate(void)
{
  /* TODO Implement. */
} /*** end of BltSessionTerminate ***/


/************************************************************************************//**
** \brief     Starts the firmware update session. This is were the library attempts to
**            activate and connect with the bootloader running on the target, through
**            the transport layer that was specified during the session's initialization.
** \return    BLT_RESULT_OK if successful, BLT_RESULT_ERROR_xxx otherwise.
**
****************************************************************************************/
LIBOPENBLT_EXPORT uint32_t BltSessionStart(void)
{
  /* TODO Implement. */
  
  return BLT_RESULT_OK;
} /*** end of BltSessionStart ***/


/************************************************************************************//**
** \brief     Stops the firmware update session. This is there the library disconnects
**            the transport layer as well.
**
****************************************************************************************/
LIBOPENBLT_EXPORT void BltSessionStop(void)
{
  /* TODO Implement. */
} /*** end of BltSessionStop ***/


/************************************************************************************//**
** \brief     Requests the target to erase the specified range of memory on the target.
**            Note that the target automatically aligns this to the erasable memory
**            block sizes. This typically results in more memory being erased that the
**            range that was specified here. Refer to the target implementation for
**            details.
** \param     address The starting memory address for the erase operation.
** \param     len The total number of bytes to erase from memory.
** \return    BLT_RESULT_OK if successful, BLT_RESULT_ERROR_xxx otherwise.
**
****************************************************************************************/
LIBOPENBLT_EXPORT uint32_t BltSessionClearMemory(uint32_t address, uint32_t len)
{
  uint32_t result = BLT_RESULT_ERROR_GENERIC;
  
  /* Check parameters. */
  assert(len > 0);
  
  (void)address;

  /* Only continue if the parameters are valid. */
  if (len > 0) 
  {
  /* TODO Implement. */
    result = BLT_RESULT_OK;
  }
  
  return result;
} /*** end of BltSessionClearMemory ***/


/************************************************************************************//**
** \brief     Requests the target to program the specified data to memory. Note that it
**            is the responsibility of the application to make sure the memory range was
**            erased beforehand.
** \param     address The starting memory address for the write operation.
** \param     len The number of bytes in the data buffer that should be written.
** \param     data Pointer to the byte array with data to write.
** \return    BLT_RESULT_OK if successful, BLT_RESULT_ERROR_xxx otherwise.
**
****************************************************************************************/
LIBOPENBLT_EXPORT uint32_t BltSessionWriteData(uint32_t address, uint32_t len, 
                                               uint8_t const * data)
{
  uint32_t result = BLT_RESULT_ERROR_GENERIC;

  /* Check parameters. */
  assert(data != NULL);
  assert(len > 0);
  
  (void)address;
  
  /* Only continue if the parameters are valid. */ 
  if ( (data != NULL) && (len > 0) ) /*lint !e774 */
  {
  /* TODO Implement. */
    result = BLT_RESULT_OK;
  }

  return result;
} /*** end of BltSessionWriteData ***/


/************************************************************************************//**
** \brief     Requests the target to upload the specified range from memory and store its
**            contents in the specified data buffer.
** \param     address The starting memory address for the read operation.
** \param     len The number of bytes to upload from the target and store in the data 
**            buffer.
** \param     data Pointer to the byte array where the uploaded data should be stored.
** \return    BLT_RESULT_OK if successful, BLT_RESULT_ERROR_xxx otherwise.
**
****************************************************************************************/
LIBOPENBLT_EXPORT uint32_t BltSessionReadData(uint32_t address, uint32_t len, 
                                              uint8_t * data)
{
  uint32_t result = BLT_RESULT_ERROR_GENERIC;

  /* Check parameters. */
  assert(data != NULL);
  assert(len > 0);

  (void)address;

  /* Only continue if the parameters are valid. */
  if ( (data != NULL) && (len > 0) ) /*lint !e774 */
  {
    /* TODO Implement. */
    data[0] = 0;
    result = BLT_RESULT_OK;
  }
      
  return result;
} /*** end of BltSessionReadData ***/


/****************************************************************************************
*             F I R M W A R E   D A T A
****************************************************************************************/
/************************************************************************************//**
** \brief     Initializes the firmware data module for a specified firmware file parser.
** \param     parserType The firmware file parser to use in this module. It should be a
**            BLT_FIRMWARE_PARSER_xxx value.
** \param     parserSettings Pointer to a structure with file parser specific settings if
**            applicable, otherwise specify a NULL value.
**
****************************************************************************************/
LIBOPENBLT_EXPORT void BltFirmwareInit(uint32_t parserType, void const * parserSettings)
{
  /* Verify parameters. Note that it is okay for the parserSettings to be a NULL value.
   * Not all parsers require additional settings.
   */
  assert(parserType == BLT_FIRMWARE_PARSER_SRECORD);
  
  (void)parserSettings;
  
  /* TODO Implement. */
} /*** end of BltFirmwareInit ***/


/************************************************************************************//**
** \brief     Terminates the firmware data module. Typically called at the end of the 
**            program when the firmware data module is no longer needed.
**
****************************************************************************************/
LIBOPENBLT_EXPORT void BltFirmwareTerminate(void)
{
} /*** end of BltFirmwareTerminate ***/


/************************************************************************************//**
** \brief     Loads firmware data from the specified file using the firmware file parser
**            that was specified during the initialization of this module.
** \param     firmwareFile Filename of the firmware file to load.
** \return    BLT_RESULT_OK if successful, BLT_RESULT_ERROR_xxx otherwise.
**
****************************************************************************************/
LIBOPENBLT_EXPORT uint32_t BltFirmwareLoadFromFile(char const * firmwareFile)
{
  uint32_t result = BLT_RESULT_ERROR_GENERIC;
  
  /* Verify parameters. */
  assert(firmwareFile != NULL);
  
  /* Only continue if parameters are valid. */
  if (firmwareFile != NULL) /*lint !e774 */
  {
    /* TODO Implement. */
    result = BLT_RESULT_OK;
  }

  return result;
} /*** end of BltFirmwareLoadFromFile ***/


/************************************************************************************//**
** \brief     Writes firmware data to the specified file using the firmware file parser
**            that was specified during the initialization of this module.
** \param     firmwareFile Filename of the firmware file to write to.
** \return    BLT_RESULT_OK if successful, BLT_RESULT_ERROR_xxx otherwise.
**
****************************************************************************************/
LIBOPENBLT_EXPORT uint32_t BltFirmwareSaveToFile(char const * firmwareFile)
{
  uint32_t result = BLT_RESULT_ERROR_GENERIC;
  
  /* Verify parameters. */
  assert(firmwareFile != NULL);
  
  /* Only continue if parameters are valid. */
  if (firmwareFile != NULL) /*lint !e774 */
  {
    /* TODO Implement. */
    result = BLT_RESULT_OK;
  }

  return result;
} /*** end of BltFirmwareSaveToFile ***/


/************************************************************************************//**
** \brief     Obtains the number of firmware data segments that are currently present
**            in the firmware data module.
** \return    The total number of segments.
**
****************************************************************************************/
LIBOPENBLT_EXPORT uint32_t BltFirmwareGetSegmentCount(void)
{
  /* TODO Implement. */
  
  return 0;
} /*** end of BltFirmwareGetSegmentCount ***/


/************************************************************************************//**
** \brief     Obtains the contents of the firmware data segments that was specified by
**            index parameter. Note that it is allowed to specify a NULL pointer for the
**            data parameter. In which case only the address and length information of
**            the segment are retrieved.
** \param     idx The segment index. It should be a value greater or equal to zero and
**            smaller than the value returned by \ref BltFirmwareGetSegmentCount.
** \param     address Pointer to where the segment's base address will be written to.
** \param     len Pointer to where the segment's length will be written to.
** \param     data Pointer to the the segment's data pointer will be written to. Note
**            that no data is copied to this pointer, so it does not have a be a data
**            array. This function gives direct access to the segment's data.
** \return    BLT_RESULT_OK if successful, BLT_RESULT_ERROR_xxx otherwise.
**
****************************************************************************************/
LIBOPENBLT_EXPORT uint32_t BltFirmwareGetSegment(uint32_t idx, uint32_t * address, 
                                                 uint32_t * len, uint8_t * data)
{
  uint32_t result = BLT_RESULT_ERROR_GENERIC;

  /* Verify parameters. Note that it is okay for the data parameter to be NULL. */
  assert(idx < BltFirmwareGetSegmentCount());
  assert(address != NULL);
  assert(len != NULL);
  
  (void)data;

  /* Only continue if parameters are valid. */ 
  if ((address != NULL) && (len != NULL) &&
      (idx < BltFirmwareGetSegmentCount()) ) /*lint !e774 */
  {
    /* TODO Implement. */
    *len = 0;
    *address = 0;
    result = BLT_RESULT_OK;
  }
  
  return result;
} /*** end of BltFirmwareGetSegment ***/


/************************************************************************************//**
** \brief     Adds data to the segments that are currently present in the firmware data
**            module. If the data overlaps with already existing data, the existing data
**            gets overwritten. The size of a segment is automatically adjusted or a new
**            segment gets created, if necessary.
** \param     address Base address of the firmware data. 
** \param     len Number of bytes to add.
** \param     data Pointer to array with data bytes that should be added.
** \return    BLT_RESULT_OK if successful, BLT_RESULT_ERROR_xxx otherwise.
**
****************************************************************************************/
LIBOPENBLT_EXPORT uint32_t BltFirmwareAddData(uint32_t address, uint32_t len, 
                                              uint8_t const * data)
{
  uint32_t result = BLT_RESULT_ERROR_GENERIC;
  
  /* Verify parameters. */
  assert(len > 0);
  assert(data != NULL);
  
  (void)address;

  /* Only continue if parameters are valid. */
  if ( (len > 0) && (data != NULL) ) /*lint !e774 */
  {
    /* TODO Implement. */
    result = BLT_RESULT_OK;
  }


  return result;
} /*** end of BltFirmwareAddData ***/


/************************************************************************************//**
** \brief     Removes data from the segments that are currently present in the firmware 
**            data module. The size of a segment is automatically adjusted or removed, if
**            necessary.
** \param     address Base address of the firmware data. 
** \param     len Number of bytes to remove.
** \return    BLT_RESULT_OK if successful, BLT_RESULT_ERROR_xxx otherwise.
**
****************************************************************************************/
LIBOPENBLT_EXPORT uint32_t BltFirmwareRemoveData(uint32_t address, uint32_t len)
{
  uint32_t result = BLT_RESULT_ERROR_GENERIC;

  /* Verify parameters. */
  assert(len > 0);
  
  (void)address;

  /* Only continue if parameters are valid. */
  if (len > 0)
  {
    /* TODO Implement. */
    result = BLT_RESULT_OK;
  }

  return result;
} /*** end of BltFirmwareRemoveData ***/


/****************************************************************************************
*             G E N E R I C   U T I L I T I E S
****************************************************************************************/
/************************************************************************************//**
** \brief     Calculates a 16-bit CRC value over the specified data.
** \param     data Array with bytes over which the CRC16 should be calculated.
** \param     len Number of bytes in the data array.
** \return    The 16-bit CRC value.
**
****************************************************************************************/
LIBOPENBLT_EXPORT uint16_t BltUtilCrc16Calculate(uint8_t const * data, uint32_t len)
{
  uint16_t result = 0;
  
  /* Check parameters. */
  assert(data != NULL);
  assert(len > 0);

  /* Only continue if parameters are valid. */
  if ( (data != NULL) && (len > 0) ) /*lint !e774 */
  {
    /* Perform checksum calculation. */
    result = UtilChecksumCrc16Calculate(data, len);
  }
  
  return result;
} /*** end of BltUtilCrc16Calculate ***/


/************************************************************************************//**
** \brief     Calculates a 32-bit CRC value over the specified data.
** \param     data Array with bytes over which the CRC32 should be calculated.
** \param     len Number of bytes in the data array.
** \return    The 32-bit CRC value.
**
****************************************************************************************/
LIBOPENBLT_EXPORT uint32_t BltUtilCrc32Calculate(uint8_t const * data, uint32_t len)
{
  uint32_t result = 0;
  
  /* Check parameters. */
  assert(data != NULL);
  assert(len > 0);

  /* Only continue if parameters are valid. */
  if ( (data != NULL) && (len > 0) ) /*lint !e774 */
  {
    /* Perform checksum calculation. */
    result = UtilChecksumCrc32Calculate(data, len);
  }
  
  return result;
} /*** end of BltUtilCrc32Calculate ***/


/*********************************** end of openblt.c **********************************/

 