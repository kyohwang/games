#include <stdlib.h>
#include <memory>

// rgb转换成hsb
void rgb2hsb(unsigned char &rgbR, unsigned char &rgbG, unsigned char &rgbB, float &hsbH, float &hsbS, float &hsbB){
	// 计算rgb中最小的 min
	unsigned char min = (rgbR < rgbG) ? rgbR : rgbG;
	min = (min < rgbB) ? min : rgbB;

	// 计算rgb中最大的max
	unsigned char max = (rgbR > rgbG) ? rgbR : rgbG;
	max = (max > rgbB) ? max : rgbB;

	hsbH = 0; //Hue色相
	hsbS = 0; //Saturation饱和度
	hsbB = 0; //brightness明度

	//计算饱和度
	hsbS = max == 0 ? 0 : (max - min) / (float) max;
	
	// 计算明度
	hsbB = (float) max / 255.0f;

	//计算色相
	unsigned char temp = max - min;
	hsbH = 0;
	if (max == rgbR) {
		if (rgbG >= rgbB) {
			hsbH = (float)(rgbG - rgbB) * 60.0 / (float)temp + 0;
		}else {
			hsbH = ((float)(rgbG - rgbB) * 60.0 / (float)temp) + 360;
		}
	}else if (max == rgbG) {
		hsbH = ((float)(rgbB - rgbR) * 60.0 / (float)temp) + 120;
	}else if (max == rgbB) {
		hsbH = ((float)(rgbR - rgbG) * 60.0 / (float)temp) + 240;
	}
}

void hsb2rgb(float &hsbH, float &hsbS, float &hsbB, unsigned char &rgbR, unsigned char &rgbG, unsigned char &rgbB)
{
	int i = ((int)(hsbH / 60)) % 6;
	float f = hsbH / 60 - i;
	float p = (hsbB * (1 - hsbS));
	float q = (hsbB * (1 - f * hsbS));
	float t = (hsbB * (1 - (1 - f) * hsbS));
	float v = hsbB;
	const unsigned char RGBMax = 255; 

	switch (i) {
	case 0:
		rgbR = v*RGBMax;
		rgbG = t*RGBMax;
		rgbB = p*RGBMax;
		break;
	case 1:
		rgbR = q*RGBMax;
		rgbG = v*RGBMax;
		rgbB = p*RGBMax;
		break;
	case 2:
		rgbR = p*RGBMax;
		rgbG = v*RGBMax;
		rgbB = t*RGBMax;
		break;
	case 3:
		rgbR = p*RGBMax;
		rgbG = q*RGBMax;
		rgbB = v*RGBMax;
		break;
	case 4:
		rgbR = t*RGBMax;
		rgbG = p*RGBMax;
		rgbB = v*RGBMax;
		break;
	case 5:
		rgbR = v*RGBMax;
		rgbG = p*RGBMax;
		rgbB = q*RGBMax;
		break;
	default:
		break;
	}
}

int main(const char* args[], int argc)
{
	unsigned char r = 38;
	unsigned char g = 88;
	unsigned char b = 166;

	float hsbH = 0.0;
	float hsbS = 0.0;
	float hsbB = 0.0;

	rgb2hsb(r,g,b,hsbH,hsbS,hsbB);

	printf("h=%f s=%f b=%f  \n",hsbH,hsbS,hsbB);

	unsigned char r1 = 0;
	unsigned char g1 = 0;
	unsigned char b1 = 0;

	float hhhh = 10;

	hsb2rgb(hhhh,hsbS,hsbB,r1,g1,b1);

	printf("r=%d g=%d b=%d  \n",r1,g1,b1);

	while (true)
	{

	}
	return 0;
}