/*
	RackAFX(TM)
	Applications Programming Interface
	Derived Class Object Definition
	Copyright(c) Tritone Systems Inc. 2006-2012

	Your plug-in must implement the constructor,
	destructor and virtual Plug-In API Functions below.
*/

#pragma once

// base class
#include "plugin.h"
#include "CombFilter.h"
#include "Delay.h"
#include "DelayAPF.h"
#include "LPFCombFilter.h"
#include "OnePoleLPF.h"

// abstract base class for RackAFX filters
class CAOSReverb : public CPlugIn
{
public:
	// RackAFX Plug-In API Member Methods:
	// The followung 5 methods must be impelemented for a meaningful Plug-In
	//
	// 1. One Time Initialization
	CAOSReverb();

	// 2. One Time Destruction
	virtual ~CAOSReverb(void);

	// 3. The Prepare For Play Function is called just before audio streams
	virtual bool __stdcall prepareForPlay();

	// 4. processAudioFrame() processes an audio input to create an audio output
	virtual bool __stdcall processAudioFrame(float* pInputBuffer, float* pOutputBuffer, UINT uNumInputChannels, UINT uNumOutputChannels);

	// 5. userInterfaceChange() occurs when the user moves a control.
	virtual bool __stdcall userInterfaceChange(int nControlIndex);


	// OPTIONAL ADVANCED METHODS ------------------------------------------------------------------------------------------------
	// These are more advanced; see the website for more details
	//
	// 6. initialize() is called once just after creation; if you need to use Plug-In -> Host methods
	//				   such as sendUpdateGUI(), you must do them here and NOT in the constructor
	virtual bool __stdcall initialize();

	// 7. joystickControlChange() occurs when the user moves a control.
	virtual bool __stdcall joystickControlChange(float fControlA, float fControlB, float fControlC, float fControlD, float fACMix, float fBDMix);

	// 8. process buffers instead of Frames:
	// NOTE: set m_bWantBuffers = true to use this function
	virtual bool __stdcall processRackAFXAudioBuffer(float* pInputBuffer, float* pOutputBuffer, UINT uNumInputChannels, UINT uNumOutputChannels, UINT uBufferSize);

	// 9. rocess buffers instead of Frames:
	// NOTE: set m_bWantVSTBuffers = true to use this function
	virtual bool __stdcall processVSTAudioBuffer(float** ppInputs, float** ppOutputs, UINT uNumChannels, int uNumFrames);

	// 10. MIDI Note On Event
	virtual bool __stdcall midiNoteOn(UINT uChannel, UINT uMIDINote, UINT uVelocity);

	// 11. MIDI Note Off Event
	virtual bool __stdcall midiNoteOff(UINT uChannel, UINT uMIDINote, UINT uVelocity, bool bAllNotesOff);


	// 12. MIDI Modulation Wheel uModValue = 0 -> 127
	virtual bool __stdcall midiModWheel(UINT uChannel, UINT uModValue);

	// 13. MIDI Pitch Bend
	//					nActualPitchBendValue = -8192 -> 8191, 0 is center, corresponding to the 14-bit MIDI value
	//					fNormalizedPitchBendValue = -1.0 -> +1.0, 0 is at center by using only -8191 -> +8191
	virtual bool __stdcall midiPitchBend(UINT uChannel, int nActualPitchBendValue, float fNormalizedPitchBendValue);

	// 14. MIDI Timing Clock (Sunk to BPM) function called once per clock
	virtual bool __stdcall midiClock();


	// 15. all MIDI messages -
	// NOTE: set m_bWantAllMIDIMessages true to get everything else (other than note on/off)
	virtual bool __stdcall midiMessage(unsigned char cChannel, unsigned char cStatus, unsigned char cData1, unsigned char cData2);

	// 16. initUI() is called only once from the constructor; you do not need to write or call it. Do NOT modify this function
	virtual bool __stdcall initUI();



	// Add your code here: ----------------------------------------------------------- //

	//pre delay
	CDelay m_PreDelay;

	//input diffusion
	COnePoleLPF m_InputLPF;
	CDelayAPF m_InputAPF_1;
	CDelayAPF m_InputAPF_2;
	CDelayAPF m_InputAPF_3;
	CDelayAPF m_InputAPF_4;

	//parallel comb bank 1
	CCombFilter m_ParallelCF_1;
	CCombFilter m_ParallelCF_2;
	CLPFCombFilter m_ParallelCF_3;
	CLPFCombFilter m_ParallelCF_4;

	//parallel comb bank 2
		CCombFilter m_ParallelCF_5;
	CCombFilter m_ParallelCF_6;
	CLPFCombFilter m_ParallelCF_7;
	CLPFCombFilter m_ParallelCF_8;

	//parallel comb bank 3
		CCombFilter m_ParallelCF_9;
	CCombFilter m_ParallelCF_10;
	CLPFCombFilter m_ParallelCF_11;
	CLPFCombFilter m_ParallelCF_12;

	//parallel comb bank 4
		CCombFilter m_ParallelCF_13;
	CCombFilter m_ParallelCF_14;
	CLPFCombFilter m_ParallelCF_15;
	CLPFCombFilter m_ParallelCF_16;

	//damping
	COnePoleLPF m_DampingLPF1;
	COnePoleLPF m_DampingLPF2;

	//output diffusion
	CDelayAPF m_OutputAPF_5;
	CDelayAPF m_OutputAPF_6;
	CDelayAPF m_OutputAPF_7;
	CDelayAPF m_OutputAPF_8;

	//cook all member objects variables
	void cookVariables();

	// END OF USER CODE -------------------------------------------------------------- //


	// ADDED BY RACKAFX -- DO NOT EDIT THIS CODE!!! ----------------------------------- //
	//  **--0x07FD--**

	float m_fPreDelay_mSec;
	float m_fPreDelayAtten_dB;
	float m_fInputLPF_g;
	float m_fLPF2_g2;
	float m_fRT60;
	float m_fWet_pct;
	float m_fAPF_1_Delay_mSec;
	float m_fAPF_2_Delay_mSec;
	float m_fAPF_3_Delay_mSec;
	float m_fAPF_4_Delay_mSec;
	float m_fAPF_5_Delay_mSec;
	float m_fAPF_6_Delay_mSec;
	float m_fAPF_7_Delay_mSec;
	float m_fAPF_8_Delay_mSec;
	float m_fAPF_1_g;
	float m_fAPF_2_g;
	float m_fAPF_3_g;
	float m_fAPF_4_g;
	float m_fAPF_5_g;
	float m_fAPF_6_g;
	float m_fAPF_7_g;
	float m_fAPF_8_g;
	float m_fPComb_1_Delay_mSec;
	float m_fPComb_2_Delay_mSec;
	float m_fPComb_3_Delay_mSec;
	float m_fPComb_4_Delay_mSec;
	float m_fPComb_5_Delay_mSec;
	float m_fPComb_6_Delay_mSec;
	float m_fPComb_7_Delay_mSec;
	float m_fPComb_8_Delay_mSec;
	float m_fPComb_9_Delay_mSec;
	float m_fPComb_10_Delay_mSec;
	float m_fPComb_11_Delay_mSec;
	float m_fPComb_12_Delay_mSec;
	float m_fPComb_13_Delay_mSec;
	float m_fPComb_14_Delay_mSec;
	float m_fPComb_15_Delay_mSec;
	float m_fPComb_16_Delay_mSec;

	// **--0x1A7F--**
	// ------------------------------------------------------------------------------- //

};




















































