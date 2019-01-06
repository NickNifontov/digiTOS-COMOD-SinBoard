/*
 * digiTOS-ADC.c
 *
 *  Created on: 31 дек. 2018 г.
 *      Author: Nick Nifontov
 */

#include "digiTOS-ADC.h"

#ifdef Detect_ZeroV_Point
uint32_t TempVal=0;
#endif

// ************** ADC SECTION ************** //
//uint32_t adc_cnt1=0;

void StartADC(){
	//HAL_ADC_Start_IT(&hadc);
	//ADC->CCR |= ADC_CCR_TSEN | ADC_CCR_VREFEN;
	HAL_ADC_Start_DMA(&hadc,(uint32_t*) &ADC_Data,ADC_ChannelCnt);
}

//void CollectADC_Data() {
	/*if (ADC_Cnt[3]>=Temp_MeasureDensity) {
		ADC_Data[3]=(uint32_t)(ADC_Data[3]/ADC_Cnt[3]);
		//sprintf(temp_buffer, "CPU Temp=%02d C \r\n",
		//		GetCPU_Temp());

		ADC_Cnt[3]=0;
		ADC_Data[3]=0;
	}*/
	/*ADC_Data[0]=0;
	ADC_Cnt[0]=0;
	ADC_Data[1]=0;
	ADC_Cnt[1]=0;
	ADC_Data[2]=0;
	ADC_Cnt[2]=0;*/
//}

//void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc1)
//{
	/*if (__HAL_ADC_GET_FLAG(&hadc, ADC_FLAG_EOC))
	{
		if (adc_cnt1>=ADC_ChannelCnt) {
			adc_cnt1=0;
		}
		ADC_Data[adc_cnt1] = ADC_Data[adc_cnt1]+HAL_ADC_GetValue(&hadc);
		ADC_Cnt[adc_cnt1]=ADC_Cnt[adc_cnt1]+1;
		adc_cnt1++;
	}

	if (__HAL_ADC_GET_FLAG(&hadc, ADC_FLAG_EOS)) {
		CollectADC_Data();
	}*/
//}

//******* ADC **********//

//******* AMPLITUDE **********//
void ResetV_data() {
	 V_1=0;
	 V_2=0;
	 V_3=0;
	 V_4=0;

	 V_Cnt[0]=1;
	 V_Cnt[1]=1;
	 V_Cnt[2]=1;
	 V_Cnt[3]=1;

	 V_Out_Cnt=1;
	 V_Out_RawData=0;

	#ifdef USE_VREF
	 V_Cnt[4]=1;
	 V_5=1500;
	#endif

	#ifdef DC_PROTECTION
	 	 DC_Data=0;
	 	 DC_DataCnt=0;
	#endif
}

float CheckAmp(float Value) {
	if (Value>Amp_max) {
		return Amp_max;
	}
	if (Value<Amp_min) {
		return Amp_min;
	}
	return Value;
	//
}

float CalcNewAmp(uint32_t V_curr, uint32_t V_etalon) {
	float fRes=1;
	if (V_curr>V_etalon) {
		fRes=fRes+(float)((V_curr-V_etalon)*Amp_CoefPlus);
	}
	if (V_curr<V_etalon) {
		fRes=fRes-(float)((V_etalon-V_curr)*Amp_CoefMinus);
	}

	if (fRes>Amp_max) {
		fRes=Amp_max;
	}
	if (fRes<Amp_min) {
		fRes=Amp_min;
	}

	return fRes;
}

#ifdef AMP_CORRECTION_TYPE_STEP
float CalcNewAmpByStep(float CurrAmp, float TargetAmp) {
	float fRes=CurrAmp;
	if (TargetAmp>CurrAmp) {
		fRes=fRes+amp_correction_step;
		if (fRes>=TargetAmp) {
			fRes=TargetAmp;
		}
		return fRes;
	}
	if (TargetAmp<CurrAmp) {
		fRes=fRes-amp_correction_step;
		if (fRes<=TargetAmp) {
			fRes=TargetAmp;
		}
		return fRes;
	}
	return fRes;
}
#endif

uint16_t asqrt(uint32_t x) {
  /*      From http://medialab.freaknet.org/martin/src/sqrt/sqrt.c
   *	Logically, these are unsigned. We need the sign bit to test
   *	whether (op - res - one) underflowed.
   */
  int32_t op, res, one;

  op = x;
  res = 0;

  /* "one" starts at the highest power of four <= than the argument. */

  one = 1 << 30;	/* second-to-top bit set */
  while (one > op) one >>= 2;

  while (one != 0) {
    if (op >= res + one) {
      op = op - (res + one);
      res = res +  2 * one;
    }
    res /= 2;
    one /= 4;
  }
  return (uint16_t) (res);
}


void CalcAc_V_ByWave() {
	// calc AC data for one wave form'
	#ifdef Detect_ZeroV_Point
		ZeroV_point=ADC_Data[0]; // Store last value of V_out via zero point
	#endif
	V_Out = (uint32_t) (V_Out_RawData / V_Out_Cnt);
	V_Out = asqrt(V_Out);
	V_Out = (uint32_t) (V_RATIO * V_Out);
}

void UpdateAmplitudeByV() {
	CalcAc_V_ByWave();

	#ifdef USE_VREF
		V_5=(uint32_t) (V_5/V_Cnt[4]);
		VDDA_Actual=(3300*(*VREFINT_CAL_ADDR))/V_5;
    #endif

	#ifndef USE_VREF_FOR_ADC_CORRECTION
		V_1=(uint32_t) (V_1/V_Cnt[0]);
		V_2=(uint32_t) (V_2/V_Cnt[1]);
		V_3=(uint32_t) (V_3/V_Cnt[2]);
		V_4=(uint32_t) (V_4/V_Cnt[3]);
	#endif

	#ifdef USE_VREF_FOR_ADC_CORRECTION
			V_1=(uint32_t) (V_1*(*VREFINT_CAL_ADDR)/V_Cnt[0]);
			V_2=(uint32_t) (V_2*(*VREFINT_CAL_ADDR)/V_Cnt[1]);
			V_3=(uint32_t) (V_3*(*VREFINT_CAL_ADDR)/V_Cnt[2]);
			V_4=(uint32_t) (V_4*(*VREFINT_CAL_ADDR)/V_Cnt[3]);
	#endif

	#ifdef AMP_CORRECTION_TYPE_IMMIDIATLY
		Sine_Amplitude_1=CalcNewAmp(V_1,V1_etalon);
		Sine_Amplitude_2=CalcNewAmp(V_2,V2_etalon);
		Sine_Amplitude_3=CalcNewAmp(V_3,V3_etalon);
		Sine_Amplitude_4=CalcNewAmp(V_4,V4_etalon);
	#endif

	#ifdef AMP_CORRECTION_TYPE_STEP
		amp1_target=CalcNewAmp(V_1,V1_etalon);
		Sine_Amplitude_1=CalcNewAmpByStep(Sine_Amplitude_1,amp1_target);

		amp2_target=CalcNewAmp(V_2,V2_etalon);
		Sine_Amplitude_2=CalcNewAmpByStep(Sine_Amplitude_2,amp2_target);

		amp3_target=CalcNewAmp(V_3,V3_etalon);
		Sine_Amplitude_3=CalcNewAmpByStep(Sine_Amplitude_3,amp3_target);

		amp4_target=CalcNewAmp(V_4,V4_etalon);
		Sine_Amplitude_4=CalcNewAmpByStep(Sine_Amplitude_4,amp4_target);
	#endif

	#ifdef AMP_PROTECTION
		uint16_t AverageAmplitude=(uint16_t) (100*(float)(Sine_Amplitude_4+Sine_Amplitude_3+Sine_Amplitude_2+Sine_Amplitude_1));
		if ((AMP_BLOCKED==0) && ((AverageAmplitude>=AMP_PROTECTION_MAX) || (AverageAmplitude<=AMP_PROTECTION_MIN))) {
			AMP_PROTECTION_CNT++;
			if (AMP_PROTECTION_CNT>AMP_PROTECTION_MINMAX_CNT) {
				AMP_BLOCKED=1;
			}

		}
	#endif

	#ifdef DC_PROTECTION
			 DC_DataAverage=(DC_Data/DC_DataCnt);
			 if ((DC_BLOCKED==0) && (DC_DataAverage>=DC_PROTECTION_MAX) ) {
				 DC_PROTECTION_CNT++;
				 if (DC_PROTECTION_CNT>DC_PROTECTION_WAVE_CNT) {
				 	DC_BLOCKED=1;
				 }
			 }
	#endif

	ResetV_data();
}

void CheckV_Feedback() {
		#ifdef USE_VREF
			V_5=V_5+ADC_Data[3];
			V_Cnt[4]= V_Cnt[4]+1;
		#endif

		#ifdef DC_PROTECTION
			 DC_Data=DC_Data+ADC_Data[2];
			 DC_DataCnt=DC_DataCnt+1;
		#endif


	    //Calc V_out data AC coltage
		V_Out_Cnt++;
		#ifdef Detect_ZeroV_Point
			if (ZeroV_point==StartVZeroPointFlag) {
				ZeroV_point=ADC_Data[0];
			} else {
				TempVal=ADC_Data[0]-ZeroV_point;
				V_Out_RawData=V_Out_RawData+TempVal*TempVal;
			}
		#endif

		#ifndef Detect_ZeroV_Point
			V_Out_RawData=V_Out_RawData+ADC_Data[0]*ADC_Data[0];
		#endif

		if (sin_step>Sin_Amp_ind[2]) {
			V_4=V_4+ADC_Data[0];
			V_Cnt[3]= V_Cnt[3]+1;
			return;
		}
		if (sin_step>Sin_Amp_ind[1]) {
			V_3=V_3+ADC_Data[0];
			V_Cnt[2]= V_Cnt[2]+1;
			return;
		}
		if (sin_step>Sin_Amp_ind[0]) {
			V_2=V_2+ADC_Data[0];
			V_Cnt[1]= V_Cnt[1]+1;
			return;
		} else {
			V_1=V_1+ADC_Data[0];
			V_Cnt[0]= V_Cnt[0]+1;
			return;
		}
}
//******* AMPLITUDE **********//


//******* TEMP **********//
/*char temp_buffer[50] = {'\0'};

int32_t int_temp=0;

int32_t GetCPU_Temp(){
	int_temp = ADC_Data[3];

	if (int_temp>0) {
		int_temp = int_temp  - (int32_t) *TEMP30_CAL_ADDR;
	   // int_temp *= (int32_t)(110000 - 30000);
		int_temp *= (int32_t)(110 - 30);
		int_temp = int_temp / (int32_t)(*TEMP110_CAL_ADDR - *TEMP30_CAL_ADDR);
	   // int_temp += 30000;
		int_temp += 30;
		return int_temp;
	} else {
		return 0;
	}
}*/
//******* TEMP **********//
