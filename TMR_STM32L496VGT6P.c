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

#include "Platform.h"

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

#ifndef DEBUG
    #define DEBUG
#endif

#ifdef DEBUG
    #undef DEBUG
#endif

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#ifdef STM32L496xx

// #############################################################################
// #### Include(s) #############################################################
// #############################################################################

    #include "../../TMR_Internal.h"
    #include "TMR_STM32L496VGT6P.h"

    #include "stm32l4xx.h"

// #############################################################################
// #### Private Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### Private Type(s) ########################################################
// #############################################################################

typedef struct TMR_STM32L496VGT6P_Instance_Context
{
    //  TIM_HandleTypeDef *TMRx; // FIXME
} TMR_STM32L496VGT6P_Instance_Context_t;

typedef struct TMR_STM32L496VGT6P_Context
{
    // FIXME Nothing to be done
    // FIXME What about first time initialize, affect all pins at once ?
} TMR_STM32L496VGT6P_Context_t;

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

static TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Instance_IsValid( TMR_STM32L496VGT6P_Instance_t * TMR_STM32L496VGT6P_Instance );
static TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Instance_Initialize( TMR_STM32L496VGT6P_Instance_t * TMR_STM32L496VGT6P_Instance );
static TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Instance_Cycle( TMR_STM32L496VGT6P_Instance_t * TMR_STM32L496VGT6P_Instance );
static TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Instance_DeInitialize( TMR_STM32L496VGT6P_Instance_t * TMR_STM32L496VGT6P_Instance );
//
static TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Context_Initialize( void );
static TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Context_Cycle( void );
static TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Context_DeInitialize( void );

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

static TMR_STM32L496VGT6P_Context_t TMR_STM32L496VGT6P_Context;

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

static TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Instance_Apply( TMR_STM32L496VGT6P_Instance_t * TMR_STM32L496VGT6P_Instance )
{
    TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Status_Error;
    do
    {
        TMR_Trace( "%s( Instance=%p )", __FUNCTION__, TMR_STM32L496VGT6P_Instance );
        if ( ( TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Instance_IsValid( TMR_STM32L496VGT6P_Instance ) ) != TMR_STM32L496VGT6P_Status_Success )
        {
            break;
        }
        // TODO TIMer initialize
        //    if ( TMR_STM32L496VGT6P_Instance->Context->TMRx != NULL )
        //    {
        //      HAL_TIM_Init( TMR_STM32L496VGT6P_Instance->Context->TMRx, &TMR_STM32L496VGT6P_Instance->Context->InitType );
        //    }
    }
    while ( 0 );
    return TMR_STM32L496VGT6P_Status;
}

static TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Instance_IsValid( TMR_STM32L496VGT6P_Instance_t * TMR_STM32L496VGT6P_Instance )
{
    TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Status_Error;
    do
    {
        TMR_Trace( "%s( Instance=%p )", __FUNCTION__, TMR_STM32L496VGT6P_Instance );
        if ( TMR_STM32L496VGT6P_Instance == NULL )
        {
            TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Status_ArgumentInvalid;
            break;
        }
        if ( TMR_STM32L496VGT6P_Instance->Context == NULL )
        {
            TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Status_Error;
            break;
        }
        TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Status_Success;
    }
    while ( 0 );
    return TMR_STM32L496VGT6P_Status;
}

static TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Instance_Initialize( TMR_STM32L496VGT6P_Instance_t * TMR_STM32L496VGT6P_Instance )
{
    TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Status_Error;
    do
    {
        TMR_Trace( "%s( Instance=%p )", __FUNCTION__, TMR_STM32L496VGT6P_Instance );
        if ( ( TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Instance_IsValid( TMR_STM32L496VGT6P_Instance ) ) != TMR_STM32L496VGT6P_Status_Success )
        {
            if ( TMR_STM32L496VGT6P_Status == TMR_STM32L496VGT6P_Status_ArgumentInvalid )
            {
                break;
            }
            if ( TMR_STM32L496VGT6P_Instance->Context == NULL )
            {
                RAM_Status_t RAM_Status = RAM_Status_Error;
                if ( ( RAM_Status = RAM_Allocate( RAM_1, ( RAM_Reference_t * ) &TMR_STM32L496VGT6P_Instance->Context, UTIL_SizeOf( TMR_STM32L496VGT6P_Instance_Context_t ) ) ) != RAM_Status_Success )
                {
                    TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Status_Error;
                    break;
                }
                // Double check context validity
                if ( TMR_STM32L496VGT6P_Instance->Context == NULL )
                {
                    TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Status_Error;
                    break;
                }
                TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Status_Success;
                switch ( TMR_STM32L496VGT6P_Instance->ID )
                {
                    case TMR_STM32L496VGT6P_ID_Null:
                        // TODO Add
                        break;
                    case TMR_STM32L496VGT6P_ID_1:
                    default:
                        TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Status_NotSupported;
                        break;
                }
                if ( TMR_STM32L496VGT6P_Status != TMR_STM32L496VGT6P_Status_Success )
                {
                    break;
                }
            }
        }
        TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Instance_Apply( TMR_STM32L496VGT6P_Instance );
    }
    while ( 0 );
    return TMR_STM32L496VGT6P_Status;
}

static TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Instance_Cycle( TMR_STM32L496VGT6P_Instance_t * TMR_STM32L496VGT6P_Instance )
{
    TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Status_Error;
    do
    {
        TMR_Trace( "%s( Instance=%p )", __FUNCTION__, TMR_STM32L496VGT6P_Instance );
        if ( ( TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Instance_IsValid( TMR_STM32L496VGT6P_Instance ) ) != TMR_STM32L496VGT6P_Status_Success )
        {
            break;
        }
        // FIXME Nothing to be done
        TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Status_Success;
    }
    while ( 0 );
    return TMR_STM32L496VGT6P_Status;
}

static TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Instance_DeInitialize( TMR_STM32L496VGT6P_Instance_t * TMR_STM32L496VGT6P_Instance )
{
    TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Status_Error;
    do
    {
        TMR_Trace( "%s( Instance=%p )", __FUNCTION__, TMR_STM32L496VGT6P_Instance );
        if ( ( TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Instance_IsValid( TMR_STM32L496VGT6P_Instance ) ) != TMR_STM32L496VGT6P_Status_Success )
        {
            break;
        }
        // TODO
        TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Instance_Apply( TMR_STM32L496VGT6P_Instance );
    }
    while ( 0 );
    return TMR_STM32L496VGT6P_Status;
}

static TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Context_Initialize( void )
{
    TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Status_Error;
    do
    {
        TMR_Trace( "%s( void )", __FUNCTION__ );
        UTIL_UNUSED( TMR_STM32L496VGT6P_Context ); // FIXME Skip Warning
        // Nothing to be done
        TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Status_Success;
    }
    while ( 0 );
    return TMR_STM32L496VGT6P_Status;
}

static TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Context_Cycle( void )
{
    TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Status_Error;
    do
    {
        TMR_Trace( "%s( void )", __FUNCTION__ );
        UTIL_UNUSED( TMR_STM32L496VGT6P_Context ); // FIXME Skip Warning
        // Nothing to be done
        TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Status_Success;
    }
    while ( 0 );
    return TMR_STM32L496VGT6P_Status;
}

static TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Context_DeInitialize( void )
{
    TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Status_Error;
    do
    {
        TMR_Trace( "%s( void )", __FUNCTION__ );
        UTIL_UNUSED( TMR_STM32L496VGT6P_Context ); // FIXME Skip Warning
        // Nothing to be done
        TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Status_Success;
    }
    while ( 0 );
    return TMR_STM32L496VGT6P_Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Initialize( TMR_STM32L496VGT6P_Instance_t * TMR_STM32L496VGT6P_Instance )
{
    TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Status_Error;
    do
    {
        TMR_Trace( "%s( Instance=%p )", __FUNCTION__, TMR_STM32L496VGT6P_Instance );
        if ( ( TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Context_Initialize( ) ) != TMR_STM32L496VGT6P_Status_Success )
        {
            break;
        }
        TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Instance_Initialize( TMR_STM32L496VGT6P_Instance );
    }
    while ( 0 );
    return TMR_STM32L496VGT6P_Status;
}

TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Cycle( TMR_STM32L496VGT6P_Instance_t * TMR_STM32L496VGT6P_Instance )
{
    TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Status_Error;
    do
    {
        TMR_Trace( "%s( Instance=%p )", __FUNCTION__, TMR_STM32L496VGT6P_Instance );
        if ( ( TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Context_Cycle( ) ) != TMR_STM32L496VGT6P_Status_Success )
        {
            break;
        }
        TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Instance_Cycle( TMR_STM32L496VGT6P_Instance );
    }
    while ( 0 );
    return TMR_STM32L496VGT6P_Status;
}

TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_DeInitialize( TMR_STM32L496VGT6P_Instance_t * TMR_STM32L496VGT6P_Instance )
{
    TMR_STM32L496VGT6P_Status_t TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Status_Error;
    do
    {
        TMR_Trace( "%s( Instance=%p )", __FUNCTION__, TMR_STM32L496VGT6P_Instance );
        if ( ( TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Instance_DeInitialize( TMR_STM32L496VGT6P_Instance ) ) != TMR_STM32L496VGT6P_Status_Success )
        {
            break;
        }
        TMR_STM32L496VGT6P_Status = TMR_STM32L496VGT6P_Context_DeInitialize( );
    }
    while ( 0 );
    return TMR_STM32L496VGT6P_Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#endif /* STM32L496xx */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
