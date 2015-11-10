#pragma config(Motor,  port1,           driveLeftBack, tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           driveLeftFront, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           conveyor,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           handFlywheelLeft, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           intakeFlywheelLeft, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           waterwheel,    tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port7,           intakeFlywheelRight, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           handFlywheelRight, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           driveRightFront, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          driveRightBack, tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
  // .....................................................................................
  // Insert user code here.
  // .....................................................................................

	AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{
		motor[driveLeftBack] = vexRT[Ch3] + vexRT[Ch1];
		motor[driveLeftFront] = vexRT[Ch3] + vexRT[Ch1];
		motor[driveRightBack] = vexRT[Ch3] + vexRT[Ch1];
		motor[driveRightFront] = vexRT[Ch3] + vexRT[Ch1];

		if(vexRT[Btn8D] == 1)
		{
			motor[conveyor] = 127;
		}
		else if(vexRT[Btn8U] == 1)
		{
			motor[conveyor] = 0;
		}
		if(vexRT[Btn7D] == 1)
		{
			motor[waterwheel] = 127;
		}
		else if(vexRT[Btn7U] == 1)
		{
			motor[waterwheel] = 0;
		}
		else if(vexRT[Btn7R] == 1)
		{
			motor[waterwheel] = -127;
		}
		if(vexRT[Btn6U] == 1)
		{
			motor[handFlywheelLeft] = 79;
			motor[handFlywheelRight] = 79;
		}
		else if(vexRT[Btn6D] == 1)
		{
			motor[handFlywheelLeft] = 0;
			motor[handFlywheelRight] = 0;
		}

		if(vexRT[Btn5U] == 1)
		{
			motor[intakeFlywheelLeft] = 79;
			motor[intakeFlywheelRight] = 79;
		}
		else if(vexRT[Btn5D] == 1)
		{
			motor[intakeFlywheelLeft] = 0;
			motor[intakeFlywheelRight] = 0;
		}

	}
}
