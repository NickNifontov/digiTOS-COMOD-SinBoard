/*
 * digiTOS-ADC.c
 *
 *  Created on: 31 дек. 2018 г.
 *      Author: Nick Nifontov
 */

#include "digiTOS-ADC.h"
#include "digiTOS-Core.h"
#include "adc.h"
#include <stdlib.h>
#include <stdio.h>

//******* ADC **********//
//uint32_t adc_cnt1=0;

void StartADC(){
	//HAL_ADC_Start_IT(&hadc);
	//ADC->CCR |= ADC_CCR_TSEN | ADC_CCR_VREFEN;
	HAL_ADC_Start_DMA(&hadc,(uint32_t*) &ADC_Data,ADC_ChannelCnt);
}

void CollectADC_Data() {
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
}

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

void UpdateAmplitudeByV() {
	V_1=(uint32_t) (V_1/V_Cnt[0]);
	V_2=(uint32_t) (V_2/V_Cnt[1]);
	V_3=(uint32_t) (V_3/V_Cnt[2]);
	V_4=(uint32_t) (V_4/V_Cnt[3]);

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

	ResetV_data();
}

void CheckV_Feedback() {
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
