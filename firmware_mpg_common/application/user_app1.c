/**********************************************************************************************************************
File: user_app1.c                                                                

----------------------------------------------------------------------------------------------------------------------
To start a new task using this user_app1 as a template:
 1. Copy both user_app1.c and user_app1.h to the Application directory
 2. Rename the files yournewtaskname.c and yournewtaskname.h
 3. Add yournewtaskname.c and yournewtaskname.h to the Application Include and Source groups in the IAR project
 4. Use ctrl-h (make sure "Match Case" is checked) to find and replace all instances of "user_app1" with "yournewtaskname"
 5. Use ctrl-h to find and replace all instances of "UserApp1" with "YourNewTaskName"
 6. Use ctrl-h to find and replace all instances of "USER_APP1" with "YOUR_NEW_TASK_NAME"
 7. Add a call to YourNewTaskNameInitialize() in the init section of main
 8. Add a call to YourNewTaskNameRunActiveState() in the Super Loop section of main
 9. Update yournewtaskname.h per the instructions at the top of yournewtaskname.h
10. Delete this text (between the dashed lines) and update the Description below to describe your task
----------------------------------------------------------------------------------------------------------------------

Description:
This is a user_app1.c file template 

------------------------------------------------------------------------------------------------------------------------
API:

Public functions:


Protected System functions:
void UserApp1Initialize(void)
Runs required initialzation for the task.  Should only be called once in main init section.

void UserApp1RunActiveState(void)
Runs current task state.  Should only be called once in main loop.


**********************************************************************************************************************/

#include "configuration.h"

/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_UserApp1"
***********************************************************************************************************************/
/* New variables */
volatile u32 G_u32UserApp1Flags;                       /* Global state flags */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Existing variables (defined in other files -- should all contain the "extern" keyword) */
extern volatile u32 G_u32SystemFlags;                  /* From main.c */
extern volatile u32 G_u32ApplicationFlags;             /* From main.c */

extern volatile u32 G_u32SystemTime1ms;                /* From board-specific source file */
extern volatile u32 G_u32SystemTime1s;                 /* From board-specific source file */


/***********************************************************************************************************************
Global variable definitions with scope limited to this local application.
Variable names shall start with "UserApp1_" and be declared as static.
***********************************************************************************************************************/
static fnCode_type UserApp1_StateMachine;            /* The state machine function pointer */
//static u32 UserApp1_u32Timeout;                      /* Timeout counter used across states */


/**********************************************************************************************************************
Function Definitions
**********************************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Public functions                                                                                                   */
/*--------------------------------------------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------------------------------------------*/
/* Protected functions                                                                                                */
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Function: UserApp1Initialize

Description:
Initializes the State Machine and its variables.

Requires:
  -

Promises:
  - 
*/
void UserApp1Initialize(void)
{

//  LedToggle(PURPLE);
    /*
viod button_pressed(void)
    {
     static bool B_impressed[3]=FALSE;
    if( IsButtonPressed(BUTTON) ==TRUE)   
   {
     if( IsButtonPressed(BUTTON0) ==FALES)   
     
     { LedOn(RED);
     B_impressed[0]=TRUE;
     }
     else
          { LedOff(RED);
     B_impressed[0]=TRUE;
    }
    if(WasButtonPressed(BUTTON))
    {if(B_impressed[1]==FALSE)}
    }
*/
  /* If good initialization, set state to Idle */
  if( 1 )
  {
    UserApp1_StateMachine = UserApp1SM_Idle;
  }
  else
  {
    /* The task isn't properly initialized, so shut it down and don't run */
    UserApp1_StateMachine = UserApp1SM_FailedInit;
  }

} /* end UserApp1Initialize() */

  
/*----------------------------------------------------------------------------------------------------------------------
Function UserApp1RunActiveState()

Description:
Selects and runs one iteration of the current state in the state machine.
All state machines have a TOTAL of 1ms to execute, so on average n state machines
may take 1ms / n to execute.

Requires:
  - State machine function pointer points at current state

Promises:
  - Calls the function to pointed by the state machine function pointer
*/
void UserApp1RunActiveState(void)
{
  UserApp1_StateMachine();

} /* end UserApp1RunActiveState */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Private functions                                                                                                  */
/*--------------------------------------------------------------------------------------------------------------------*/


/**********************************************************************************************************************
State Machine Function Definitions
**********************************************************************************************************************/

/*-------------------------------------------------------------------------------------------------------------------*/
/* Wait for ??? */

static void UserApp1SM_Idle(void)
{
   LedOff(WHITE);
  LedOff(PURPLE);
  LedOff(BLUE);
  LedOff(CYAN);
  LedOff(GREEN);
  LedOff(YELLOW);
  LedOff(ORANGE);
  LedOff(RED);
  
  if( WasButtonPressed(BUTTON0)&&WasButtonPressed(BUTTON1)&&WasButtonPressed(BUTTON2)&&WasButtonPressed(BUTTON3) )
{
  /* The button is currently pressed, so make sure the LED is on */
  LedOn(WHITE);
}
else
{
  /* The button is not pressed, so make sure the LED is off */
  LedOff(WHITE);
}
  /*static u8_pwm_red = 0;
  if(G_u32SystemTime1ms%1000 = 0)
  {
    LedToggle(PURPLE);
  u8_pwm_red++;
  if(u8_pwm_red>=20)
    u8_pwm_red=0;
  LedPWM(RED,led);
  */
  }
     /* static u8 u8key=0;
  static u32 u32Counter1 = 0;
  static u32 u32Counter2 = 1;
  static u32 u32Counter3 = 1000;
  static u32 u32Counter4 = 100;
  if(u32Counter2==1001)
  {
    u8key=1;
    u32Counter4 = 100;
  }
  else if(u32Counter2 == 1|| u32Counter4 == 1000)
  {
    u8key=0;
    u32Counter2 = 1;
  }
  switch(u8key)
  {
  case 0:u32Counter1++;
      if(u32Counter1==u32Counter2)
      { 
        LedOn(RED);
      }
       else if(u32Counter1 == 1000)
      {
           LedOff(RED);
           u32Counter1 = 0;
           u32Counter2+=100;
           u32Counter4-=1;
  }break;
  case 1:
    u32Counter3--;
    if(u32Counter3 == 0)
    { 
      LedOff(RED);
      u32Counter3 = 1000;
    }
    else if (u32Counter3 == u32Counter4)
    {   LedOn(RED);
    u32Counter4 += 100;
    u32Counter2 -= 100;
     }break;
  }
}*/

/*  
u8 u8randCounter;
u32 u32Counter1 = 0;
u8randCounter=rand()%8;
switch(u8randCounter)
   {   
      case 0:
             LedOn(RED);
             for(u32Counter1=0;u32Counter1<2000*500;u32Counter1++);
             
             LedOff(RED);break;
      case 1:
             LedOn(BLUE);
             for(u32Counter1=0;u32Counter1<2000*500;u32Counter1++);
            
             LedOff(BLUE);break;
      case 2:
             LedOn(GREEN);
             for(u32Counter1=0;u32Counter1<2000*500;u32Counter1++);
            
             LedOff(GREEN);break;
      case 3:
             LedOn(YELLOW);
             for(u32Counter1=0;u32Counter1<2000*500;u32Counter1++);
            
             LedOff(YELLOW);break;
      case 4:
             LedOn(PURPLE);
             for(u32Counter1=0;u32Counter1<2000*500;u32Counter1++);
           
             LedOff(PURPLE);break;
      case 5:
             LedOn(ORANGE);
             for(u32Counter1=0;u32Counter1<2000*500;u32Counter1++);
           
             LedOff(ORANGE);break;
      case 6:
             LedOn(WHITE);
             for(u32Counter1=0;u32Counter1<2000*500;u32Counter1++);
           
             LedOff(WHITE);break;
      case 7:
             LedOn(CYAN);
             for(u32Counter1=0;u32Counter1<2000*500;u32Counter1++);
           
             LedOff(CYAN);break;
   }  
}
 /* static u8 u8key=0;
  static u32 u32Counter1 = 0;
  static u32 u32Counter2 = 1024;
  if(u32Counter2==2)
  {
    u8key=1;
  }
  else if(u32Counter2==1024)
  { 
    u8key=0;
  }
  switch(u8key)
  {
  case 0:u32Counter1++;
      if(u32Counter1==u32Counter2)
      LedOn(BLUE);//HEARTBEAT_ON();
       else if(u32Counter1==2*u32Counter2)
      {
           LedOff(BLUE);
           //HEARTBEAT_OFF();
           u32Counter1 = 0;
           u32Counter2/=2;
  }break;
  case 1:u32Counter1++;
       if(u32Counter1==u32Counter2)
         LedOn(BLUE);
       //HEARTBEAT_ON();
       else if(u32Counter1==2*u32Counter2)
         {
           LedOff(BLUE);
           //HEARTBEAT_OFF();
           u32Counter1 = 0;
           u32Counter2*=2;
  }break;
 }
}
} /* end UserApp1SM_Idle() */
     
#if 0
/*-------------------------------------------------------------------------------------------------------------------*/
/* Handle an error */
static void UserApp1SM_Error(void)          
{
  
} /* end UserApp1SM_Error() */
#endif


/*-------------------------------------------------------------------------------------------------------------------*/
/* State to sit in if init failed */
static void UserApp1SM_FailedInit(void)          
{
    
} /* end UserApp1SM_FailedInit() */


/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------*/
