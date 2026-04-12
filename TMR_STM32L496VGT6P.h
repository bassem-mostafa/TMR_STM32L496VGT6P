// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2024 BaSSeM
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// #############################################################################
// #### Description ############################################################
// #############################################################################

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#ifndef TMR_STM32L496VGT6P_H_
    #define TMR_STM32L496VGT6P_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    typedef enum TMR_STM32L496VGT6P_Status
    {
        TMR_STM32L496VGT6P_Status_Success = 0,
        TMR_STM32L496VGT6P_Status_ArgumentInvalid,
        TMR_STM32L496VGT6P_Status_NotSupported,
        TMR_STM32L496VGT6P_Status_Error,
        TMR_STM32L496VGT6P_Status_Busy,
        TMR_STM32L496VGT6P_Status_Timeout,
    } TMR_STM32L496VGT6P_Status_t;

    typedef enum TMR_STM32L496VGT6P_ID
    {
        TMR_STM32L496VGT6P_ID_Null = 0,
        TMR_STM32L496VGT6P_ID_1,
    } TMR_STM32L496VGT6P_ID_t;

    typedef struct TMR_STM32L496VGT6P_InstanceContext TMR_STM32L496VGT6P_InstanceContext_t;

    typedef struct TMR_STM32L496VGT6P_Instance
    {
        TMR_STM32L496VGT6P_ID_t ID;
        TMR_STM32L496VGT6P_InstanceContext_t * Context;
    } TMR_STM32L496VGT6P_Instance_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Initialize( TMR_STM32L496VGT6P_Instance_t * TMR_STM32L496VGT6P_Instance );
    TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Cycle( TMR_STM32L496VGT6P_Instance_t * TMR_STM32L496VGT6P_Instance );
    TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_DeInitialize( TMR_STM32L496VGT6P_Instance_t * TMR_STM32L496VGT6P_Instance );

    // TODO Add More APIs

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* TMR_STM32L496VGT6P_H_ */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
