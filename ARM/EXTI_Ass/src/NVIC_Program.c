/*
 * NVIC_Program.c
 *
 *  Created on: May 19, 2023
 *      Author: knawy
 */
#include "BIT_MATH_H_.h"
#include "STD_Types.h"
#include "stm32f401xx.h"

#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Config.h"
#include "NVIC_Config.h"
#include "NVIC_Interface.h"
#include "NVIC_Private.h"

void NVIC_voidEnablePerInt(u8 copyInt_Id)
{
	NVIC->ISER[copyInt_Id/32]=(1<<(copyInt_Id % 32));
}
void NVIC_voidDisablePerInt(u8 copyInt_Id)
{
	NVIC->ICER[copyInt_Id/32]=(1<<(copyInt_Id % 32));
}
void NVIC_voidSetPendingFlag(u8 copyInt_Id)
{
	NVIC->ISPR[copyInt_Id/32]=(1<<(copyInt_Id % 32));
}
void NVIC_voidClrPendingFlag(u8 copyInt_Id)
{
	NVIC->ICPR[copyInt_Id/32]=(1<<(copyInt_Id % 32));
}

/*OPtion of copy_u8PriorityOption: GROUP4BITS_SUBGROUP0BITS ,
 *                                 GROUP3BITS_SUBGROUP1BITS ,
 *                                 GROUP2BITS_SUBGROUP2BITS ,
 *                                 GROUP1BITS_SUBGROUP4BITS ,
 *                                 GROUP0BITS_SUBGROUP4BITS  */
void NVIC_voidSetPriorityConfig(u8 copy_u8PriorityOption)
{
	SCB->AIRCR=VECT_KEY|(copy_u8PriorityOption<<8);

}
void NVIC_voidSetIntPriority(u8 copyInt_Id,u8 copy_u8GrpPri,u8 copy_u8Subpri)
{
	NVIC->IPR[copyInt_Id]=(copy_u8GrpPri<< 6)|(copy_u8Subpri<< 4);//for 2G,2S
}
