#include "picture.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
using std::ofstream;
using std::ifstream;
using std::string;
using std::vector;

/*//////constructor//////*/
picture::picture()
{

}

void picture::readAll(string& filePath)
{
	ifstream inFile(filePath, ios_base::binary);

	inFile.read(&headerObject.idLength, sizeof(headerObject.idLength));
	inFile.read(&headerObject.colorMapType, sizeof(headerObject.colorMapType));
	inFile.read(&headerObject.dataTypeCode, sizeof(headerObject.dataTypeCode));
	inFile.read((char*)&headerObject.colorMapOrigin, sizeof(headerObject.colorMapOrigin));
	inFile.read((char*)&headerObject.colorMapLength, sizeof(headerObject.colorMapLength));
	inFile.read(&headerObject.colorMapDepth, sizeof(headerObject.colorMapDepth));
	inFile.read((char*)&headerObject.xOrigin, sizeof(headerObject.xOrigin));
	inFile.read((char*)&headerObject.yOrigin, sizeof(headerObject.yOrigin));
	inFile.read((char*)&headerObject.width, sizeof(headerObject.width));
	inFile.read((char*)&headerObject.height, sizeof(headerObject.height));
	inFile.read(&headerObject.bitsPerPixel, sizeof(headerObject.bitsPerPixel));
	inFile.read(&headerObject.imageDescriptor, sizeof(headerObject.imageDescriptor));


	for (unsigned int i = 0; i < (headerObject.width * headerObject.height); i++)
	{
		inFile.read((char*)&pixel.blue, sizeof(pixel.blue));
		inFile.read((char*)&pixel.green, sizeof(pixel.green));
		inFile.read((char*)&pixel.red, sizeof(pixel.red));
		

		photo.push_back(pixel);
	}
	//cout << "test: " << (int)photo[88].red << endl;
	

	return;
}

void picture::writeFile(string& filePath)
{

	ofstream inFile(filePath, ios_base::binary);

	inFile.write(&headerObject.idLength, sizeof(headerObject.idLength));
	inFile.write(&headerObject.colorMapType, sizeof(headerObject.colorMapType));
	inFile.write(&headerObject.dataTypeCode, sizeof(headerObject.dataTypeCode));
	inFile.write((char*)&headerObject.colorMapOrigin, sizeof(headerObject.colorMapOrigin));
	inFile.write((char*)&headerObject.colorMapLength, sizeof(headerObject.colorMapLength));
	inFile.write(&headerObject.colorMapDepth, sizeof(headerObject.colorMapDepth));
	inFile.write((char*)&headerObject.xOrigin, sizeof(headerObject.xOrigin));
	inFile.write((char*)&headerObject.yOrigin, sizeof(headerObject.yOrigin));
	inFile.write((char*)&headerObject.width, sizeof(headerObject.width));
	inFile.write((char*)&headerObject.height, sizeof(headerObject.height));
	inFile.write(&headerObject.bitsPerPixel, sizeof(headerObject.bitsPerPixel));
	inFile.write(&headerObject.imageDescriptor, sizeof(headerObject.imageDescriptor));

	for (unsigned int i = 0; i < photo.size(); i++)
	{
		inFile.write((char*)&photo[i].blue, sizeof(photo[i].blue));
		inFile.write((char*)&photo[i].green, sizeof(photo[i].green));
		inFile.write((char*)&photo[i].red, sizeof(photo[i].red));
	}

	return;
}

void picture::Rotate(string& filePath)
{

	ofstream inFile(filePath, ios_base::binary);

	inFile.write(&headerObject.idLength, sizeof(headerObject.idLength));
	inFile.write(&headerObject.colorMapType, sizeof(headerObject.colorMapType));
	inFile.write(&headerObject.dataTypeCode, sizeof(headerObject.dataTypeCode));
	inFile.write((char*)&headerObject.colorMapOrigin, sizeof(headerObject.colorMapOrigin));
	inFile.write((char*)&headerObject.colorMapLength, sizeof(headerObject.colorMapLength));
	inFile.write(&headerObject.colorMapDepth, sizeof(headerObject.colorMapDepth));
	inFile.write((char*)&headerObject.xOrigin, sizeof(headerObject.xOrigin));
	inFile.write((char*)&headerObject.yOrigin, sizeof(headerObject.yOrigin));
	inFile.write((char*)&headerObject.width, sizeof(headerObject.width));
	inFile.write((char*)&headerObject.height, sizeof(headerObject.height));
	inFile.write(&headerObject.bitsPerPixel, sizeof(headerObject.bitsPerPixel));
	inFile.write(&headerObject.imageDescriptor, sizeof(headerObject.imageDescriptor));

	unsigned int i = photo.size();
	
	//for (unsigned int i = 0; i < photo.size(); i++)
	while (i--)
	{
		inFile.write((char*)&photo[i].blue, sizeof(photo[i].blue));
		inFile.write((char*)&photo[i].green, sizeof(photo[i].green));
		inFile.write((char*)&photo[i].red, sizeof(photo[i].red));
	}

	return;
}


void picture::printHead()
{
	cout << "idLength: " << (int)headerObject.idLength << endl;
	cout << "Color Map type: " << (int)headerObject.colorMapType << endl;
	cout << "data type code: " << (int)headerObject.dataTypeCode <<endl;
	cout << "Color Map orgin: " << (short)headerObject.colorMapOrigin << endl;
	cout << "color map length: " << (short)headerObject.colorMapLength << endl;
	cout << "Color map depth: " << headerObject.colorMapDepth << endl;
	cout << "x Orgin: " << (short)headerObject.xOrigin <<endl;
	cout << "y orhin: " << (short)headerObject.yOrigin << endl;
	cout << "width: " << (short)headerObject.width << endl;
	cout << "height: " << (short)headerObject.height << endl;
	cout << "bits per pixel: " << (int)headerObject.bitsPerPixel << endl;
	cout << "Image Descriptor: " << (int)headerObject.imageDescriptor << endl;

	return;
}

picture picture::Multiply(picture& other)
{
	picture multiply;

	multiply.headerObject.idLength = headerObject.idLength;
	multiply.headerObject.colorMapType = headerObject.colorMapType;
	multiply.headerObject.dataTypeCode = headerObject.dataTypeCode;
	multiply.headerObject.colorMapOrigin = headerObject.colorMapOrigin;
	multiply.headerObject.colorMapLength = headerObject.colorMapLength;
	multiply.headerObject.colorMapDepth = headerObject.colorMapDepth;
	multiply.headerObject.xOrigin = headerObject.xOrigin;
	multiply.headerObject.yOrigin = headerObject.yOrigin;
	multiply.headerObject.width = headerObject.width;
	multiply.headerObject.height = headerObject.height;
	multiply.headerObject.bitsPerPixel = headerObject.bitsPerPixel;
	multiply.headerObject.imageDescriptor = headerObject.imageDescriptor;


	for (unsigned int i = 0; i < photo.size(); i++)
	{
		//------ blue pixel ------//
		multiply.pixel.blue = PixMult(photo[i].blue, other.photo[i].blue);
		
		//------ green pixel ------//
		multiply.pixel.green = PixMult(photo[i].green, other.photo[i].green);

		//------ red pixel ------//
		multiply.pixel.red = PixMult(photo[i].red, other.photo[i].red);
	

		multiply.photo.push_back(multiply.pixel);
	}

	return multiply;
}

unsigned char picture::PixMult(unsigned char A, unsigned char B)
{
	unsigned char val;
	float tempFloat;
	tempFloat = (((float)A) / 255.0f) * (((float)B) / 255.0f);

	if (tempFloat > 1.0)
	{
		tempFloat = 1;
	}

	val = (unsigned char)(tempFloat * 255 + 0.5f);

	return val;
}

picture picture::Screen(const picture& other)
{
	picture Screen;

	Screen.headerObject.idLength = headerObject.idLength;
	Screen.headerObject.colorMapType = headerObject.colorMapType;
	Screen.headerObject.dataTypeCode = headerObject.dataTypeCode;
	Screen.headerObject.colorMapOrigin = headerObject.colorMapOrigin;
	Screen.headerObject.colorMapLength = headerObject.colorMapLength;
	Screen.headerObject.colorMapDepth = headerObject.colorMapDepth;
	Screen.headerObject.xOrigin = headerObject.xOrigin;
	Screen.headerObject.yOrigin = headerObject.yOrigin;
	Screen.headerObject.width = headerObject.width;
	Screen.headerObject.height = headerObject.height;
	Screen.headerObject.bitsPerPixel = headerObject.bitsPerPixel;
	Screen.headerObject.imageDescriptor = headerObject.imageDescriptor;

	for (unsigned int i = 0; i < photo.size(); i++)
	{
		//------ blue pixel ------//
		Screen.pixel.blue = PixScreen(photo[i].blue, other.photo[i].blue);

		//------ green pixel ------//
		Screen.pixel.green = PixScreen(photo[i].green, other.photo[i].green);

		//------ red pixel ------//
		Screen.pixel.red = PixScreen(photo[i].red, other.photo[i].red);


		Screen.photo.push_back(Screen.pixel);
	}

	return Screen;

}

unsigned char picture::PixScreen(unsigned char A, unsigned char B)
{
	unsigned char val;
	float tempFloat;
	tempFloat = (1.0f - (1.0f - (float)(A / 255.0f)) * (1.0f - (float)(B / 255.0f)));

	if (tempFloat > 1.0f)
	{
		tempFloat = 1;
	}
	else if(tempFloat < 0)
	{
		tempFloat = 0.0f;
	}

	val = (unsigned char)(tempFloat * 255 + 0.5f);

	return val;
}

picture picture::Overlay(const picture& other)
{
	picture overlay;

	overlay.headerObject.idLength = headerObject.idLength;
	overlay.headerObject.colorMapType = headerObject.colorMapType;
	overlay.headerObject.dataTypeCode = headerObject.dataTypeCode;
	overlay.headerObject.colorMapOrigin = headerObject.colorMapOrigin;
	overlay.headerObject.colorMapLength = headerObject.colorMapLength;
	overlay.headerObject.colorMapDepth = headerObject.colorMapDepth;
	overlay.headerObject.xOrigin = headerObject.xOrigin;
	overlay.headerObject.yOrigin = headerObject.yOrigin;
	overlay.headerObject.width = headerObject.width;
	overlay.headerObject.height = headerObject.height;
	overlay.headerObject.bitsPerPixel = headerObject.bitsPerPixel;
	overlay.headerObject.imageDescriptor = headerObject.imageDescriptor;

	for (unsigned int i = 0; i < photo.size(); i++)
	{
		//------ blue pixel ------//
		overlay.pixel.blue = PixOverlay(photo[i].blue, other.photo[i].blue);

		//------ green pixel ------//
		overlay.pixel.green = PixOverlay(photo[i].green, other.photo[i].green);

		//------ red pixel ------//
		overlay.pixel.red = PixOverlay(photo[i].red, other.photo[i].red);


		overlay.photo.push_back(overlay.pixel);
	}

	return overlay;
}

unsigned char picture::PixOverlay(unsigned char A, unsigned char B)
{
	unsigned char val;
	float tempFloat;

	if (((float)(B / 255.0f)) <= 0.5f)
	{
		tempFloat = ((2.0f) * ((float)(A / 255.0f)) * ((float)(B / 255.0f)));
	}
	else
	{
		tempFloat = (1.0f - (2.0f) * (1.0f - (float)(A / 255.0f)) * (1.0f - (float)(B / 255.0f)));
	}

	if (tempFloat > 1.0f)
	{
		tempFloat = 1;
	}
	else if (tempFloat < 0)
	{
		tempFloat = 0.0f;
	}

	val = (unsigned char)(tempFloat * 255 + 0.5f);

	return val;
}

picture picture::Subtract(const picture& other)
{
	picture subtract;

	subtract.headerObject.idLength = headerObject.idLength;
	subtract.headerObject.colorMapType = headerObject.colorMapType;
	subtract.headerObject.dataTypeCode = headerObject.dataTypeCode;
	subtract.headerObject.colorMapOrigin = headerObject.colorMapOrigin;
	subtract.headerObject.colorMapLength = headerObject.colorMapLength;
	subtract.headerObject.colorMapDepth = headerObject.colorMapDepth;
	subtract.headerObject.xOrigin = headerObject.xOrigin;
	subtract.headerObject.yOrigin = headerObject.yOrigin;
	subtract.headerObject.width = headerObject.width;
	subtract.headerObject.height = headerObject.height;
	subtract.headerObject.bitsPerPixel = headerObject.bitsPerPixel;
	subtract.headerObject.imageDescriptor = headerObject.imageDescriptor;


	for (unsigned int i = 0; i < photo.size(); i++)
	{
		//------ blue pixel ------//
		if ((int)photo[i].blue - (int)other.photo[i].blue < 0)
		{
			subtract.pixel.blue = 0;
		}
		else if ((int)photo[i].blue - (int)other.photo[i].blue > 255)
		{
			subtract.pixel.blue = 255;
		}
		else
		{
			subtract.pixel.blue = (int)photo[i].blue - (int)other.photo[i].blue;
		}

		//------ green pixel ------//
		if ((int)photo[i].green - (int)other.photo[i].green < 0)
		{
			subtract.pixel.green = 0;
		}
		else if ((int)photo[i].green - (int)other.photo[i].green > 255)
		{
			subtract.pixel.green = 255;
		}
		else
		{
			subtract.pixel.green = (int)photo[i].green - (int)other.photo[i].green;
		}


		//------ red pixel ------//
		if ((int)photo[i].red - (int)other.photo[i].red < 0)
		{
			subtract.pixel.red = 0;
		}
		else if ((int)photo[i].red - (int)other.photo[i].red > 255)
		{
			subtract.pixel.red = 255;
		}
		else
		{
			subtract.pixel.red = (int)photo[i].red - (int)other.photo[i].red;
		}

		subtract.photo.push_back(subtract.pixel);
	}

	return subtract;
}

picture picture::Sum(float r, float g, float b)
{
	picture Sum;

	Sum.headerObject.idLength = headerObject.idLength;
	Sum.headerObject.colorMapType = headerObject.colorMapType;
	Sum.headerObject.dataTypeCode = headerObject.dataTypeCode;
	Sum.headerObject.colorMapOrigin = headerObject.colorMapOrigin;
	Sum.headerObject.colorMapLength = headerObject.colorMapLength;
	Sum.headerObject.colorMapDepth = headerObject.colorMapDepth;
	Sum.headerObject.xOrigin = headerObject.xOrigin;
	Sum.headerObject.yOrigin = headerObject.yOrigin;
	Sum.headerObject.width = headerObject.width;
	Sum.headerObject.height = headerObject.height;
	Sum.headerObject.bitsPerPixel = headerObject.bitsPerPixel;
	Sum.headerObject.imageDescriptor = headerObject.imageDescriptor;

	for (unsigned int i = 0; i < photo.size(); i++)
	{
		//------ blue pixel ------//
		if ((float)photo[i].blue + b < 0)
		{
			Sum.pixel.blue = 0;
		}
		else if ((float)photo[i].blue + b > 255)
		{
			Sum.pixel.blue = 255;
		}
		else
		{
			Sum.pixel.blue = (unsigned char)((float)photo[i].blue + b);
		}

		//------ green pixel ------//
		if ((float)photo[i].green + g < 0)
		{
			Sum.pixel.green = 0;
		}
		else if ((float)photo[i].green + g > 255)
		{
			Sum.pixel.green = 255;
		}
		else
		{
			Sum.pixel.green = (unsigned char)((float)photo[i].green + g);
		}

		//------ red pixel ------//
		if ((float)photo[i].red + r < 0)
		{
			Sum.pixel.red = 0;
		}
		else if ((float)photo[i].red + r > 255)
		{
			Sum.pixel.red = 255;
		}
		else
		{
			Sum.pixel.red = (unsigned char)((float)photo[i].red + r + 0.5f);
		}

		Sum.photo.push_back(Sum.pixel);
	}


	return Sum;
}

picture picture::ScaleRed(float r)
{
	picture Scale;

	Scale.headerObject.idLength = headerObject.idLength;
	Scale.headerObject.colorMapType = headerObject.colorMapType;
	Scale.headerObject.dataTypeCode = headerObject.dataTypeCode;
	Scale.headerObject.colorMapOrigin = headerObject.colorMapOrigin;
	Scale.headerObject.colorMapLength = headerObject.colorMapLength;
	Scale.headerObject.colorMapDepth = headerObject.colorMapDepth;
	Scale.headerObject.xOrigin = headerObject.xOrigin;
	Scale.headerObject.yOrigin = headerObject.yOrigin;
	Scale.headerObject.width = headerObject.width;
	Scale.headerObject.height = headerObject.height;
	Scale.headerObject.bitsPerPixel = headerObject.bitsPerPixel;
	Scale.headerObject.imageDescriptor = headerObject.imageDescriptor;

	for (unsigned int i = 0; i < photo.size(); i++)
	{
		//------ red pixel ------//
		if ((float)photo[i].red * r < 0)
		{
			Scale.pixel.red = 0;
		}
		else if ((float)photo[i].red * r > 255)
		{
			Scale.pixel.red = 255;
		}
		else
		{
			Scale.pixel.red = (unsigned char)((float)photo[i].red * r + 0.5f);
		}
	}

	return Scale;
}
picture picture::ScaleGreen(float g)
{
	picture Scale;

	Scale.headerObject.idLength = headerObject.idLength;
	Scale.headerObject.colorMapType = headerObject.colorMapType;
	Scale.headerObject.dataTypeCode = headerObject.dataTypeCode;
	Scale.headerObject.colorMapOrigin = headerObject.colorMapOrigin;
	Scale.headerObject.colorMapLength = headerObject.colorMapLength;
	Scale.headerObject.colorMapDepth = headerObject.colorMapDepth;
	Scale.headerObject.xOrigin = headerObject.xOrigin;
	Scale.headerObject.yOrigin = headerObject.yOrigin;
	Scale.headerObject.width = headerObject.width;
	Scale.headerObject.height = headerObject.height;
	Scale.headerObject.bitsPerPixel = headerObject.bitsPerPixel;
	Scale.headerObject.imageDescriptor = headerObject.imageDescriptor;

	for (unsigned int i = 0; i < photo.size(); i++)
	{
		//------ green pixel ------//
		if ((float)photo[i].green * g < 0)
		{
			Scale.pixel.green = 0;
		}
		else if ((float)photo[i].green * g > 255)
		{
			Scale.pixel.green = 255;
		}
		else
		{
			Scale.pixel.green = (unsigned char)((float)photo[i].green * g + 0.5f);
		}
	}

	return Scale;
}
picture picture::ScaleBlue(float b)
{
	picture Scale;

	Scale.headerObject.idLength = headerObject.idLength;
	Scale.headerObject.colorMapType = headerObject.colorMapType;
	Scale.headerObject.dataTypeCode = headerObject.dataTypeCode;
	Scale.headerObject.colorMapOrigin = headerObject.colorMapOrigin;
	Scale.headerObject.colorMapLength = headerObject.colorMapLength;
	Scale.headerObject.colorMapDepth = headerObject.colorMapDepth;
	Scale.headerObject.xOrigin = headerObject.xOrigin;
	Scale.headerObject.yOrigin = headerObject.yOrigin;
	Scale.headerObject.width = headerObject.width;
	Scale.headerObject.height = headerObject.height;
	Scale.headerObject.bitsPerPixel = headerObject.bitsPerPixel;
	Scale.headerObject.imageDescriptor = headerObject.imageDescriptor;

	for (unsigned int i = 0; i < photo.size(); i++)
	{
		//------ blue pixel ------//
		if ((float)photo[i].blue * b < 0)
		{
			Scale.pixel.blue = 0;
		}
		else if ((float)photo[i].blue * b > 255)
		{
			Scale.pixel.blue = 255;
		}
		else
		{
			Scale.pixel.blue = (unsigned char)((float)photo[i].blue * b + 0.5f);
		}
	}

	return Scale;
}

void picture::WriteRed(string& filePath)
{
	ofstream inFile(filePath, ios_base::binary);

	inFile.write(&headerObject.idLength, sizeof(headerObject.idLength));
	inFile.write(&headerObject.colorMapType, sizeof(headerObject.colorMapType));
	inFile.write(&headerObject.dataTypeCode, sizeof(headerObject.dataTypeCode));
	inFile.write((char*)&headerObject.colorMapOrigin, sizeof(headerObject.colorMapOrigin));
	inFile.write((char*)&headerObject.colorMapLength, sizeof(headerObject.colorMapLength));
	inFile.write(&headerObject.colorMapDepth, sizeof(headerObject.colorMapDepth));
	inFile.write((char*)&headerObject.xOrigin, sizeof(headerObject.xOrigin));
	inFile.write((char*)&headerObject.yOrigin, sizeof(headerObject.yOrigin));
	inFile.write((char*)&headerObject.width, sizeof(headerObject.width));
	inFile.write((char*)&headerObject.height, sizeof(headerObject.height));
	inFile.write(&headerObject.bitsPerPixel, sizeof(headerObject.bitsPerPixel));
	inFile.write(&headerObject.imageDescriptor, sizeof(headerObject.imageDescriptor));

	unsigned char val = 0;

	for (unsigned int i = 0; i < photo.size(); i++)
	{
		inFile.write((char*)&photo[i].red, sizeof(photo[i].red));
		inFile.write((char*)&photo[i].red, sizeof(photo[i].red));
		inFile.write((char*)&photo[i].red, sizeof(photo[i].red));
	}

	return;
}

void picture::WriteGreen(string& filePath)
{
	ofstream inFile(filePath, ios_base::binary);

	inFile.write(&headerObject.idLength, sizeof(headerObject.idLength));
	inFile.write(&headerObject.colorMapType, sizeof(headerObject.colorMapType));
	inFile.write(&headerObject.dataTypeCode, sizeof(headerObject.dataTypeCode));
	inFile.write((char*)&headerObject.colorMapOrigin, sizeof(headerObject.colorMapOrigin));
	inFile.write((char*)&headerObject.colorMapLength, sizeof(headerObject.colorMapLength));
	inFile.write(&headerObject.colorMapDepth, sizeof(headerObject.colorMapDepth));
	inFile.write((char*)&headerObject.xOrigin, sizeof(headerObject.xOrigin));
	inFile.write((char*)&headerObject.yOrigin, sizeof(headerObject.yOrigin));
	inFile.write((char*)&headerObject.width, sizeof(headerObject.width));
	inFile.write((char*)&headerObject.height, sizeof(headerObject.height));
	inFile.write(&headerObject.bitsPerPixel, sizeof(headerObject.bitsPerPixel));
	inFile.write(&headerObject.imageDescriptor, sizeof(headerObject.imageDescriptor));

	unsigned char val = 0;

	for (unsigned int i = 0; i < photo.size(); i++)
	{
		inFile.write((char*)&photo[i].green, sizeof(photo[i].green));
		inFile.write((char*)&photo[i].green, sizeof(photo[i].green));
		inFile.write((char*)&photo[i].green, sizeof(photo[i].green));
	}

	return;
}

void picture::WriteBlue(string& filePath)
{
	ofstream inFile(filePath, ios_base::binary);

	inFile.write(&headerObject.idLength, sizeof(headerObject.idLength));
	inFile.write(&headerObject.colorMapType, sizeof(headerObject.colorMapType));
	inFile.write(&headerObject.dataTypeCode, sizeof(headerObject.dataTypeCode));
	inFile.write((char*)&headerObject.colorMapOrigin, sizeof(headerObject.colorMapOrigin));
	inFile.write((char*)&headerObject.colorMapLength, sizeof(headerObject.colorMapLength));
	inFile.write(&headerObject.colorMapDepth, sizeof(headerObject.colorMapDepth));
	inFile.write((char*)&headerObject.xOrigin, sizeof(headerObject.xOrigin));
	inFile.write((char*)&headerObject.yOrigin, sizeof(headerObject.yOrigin));
	inFile.write((char*)&headerObject.width, sizeof(headerObject.width));
	inFile.write((char*)&headerObject.height, sizeof(headerObject.height));
	inFile.write(&headerObject.bitsPerPixel, sizeof(headerObject.bitsPerPixel));
	inFile.write(&headerObject.imageDescriptor, sizeof(headerObject.imageDescriptor));

	unsigned char val = 0;

	for (unsigned int i = 0; i < photo.size(); i++)
	{
		inFile.write((char*)&photo[i].blue, sizeof(photo[i].blue));
		inFile.write((char*)&photo[i].blue, sizeof(photo[i].blue));
		inFile.write((char*)&photo[i].blue, sizeof(photo[i].blue));
	}

	return;
}

picture picture::Combine(const picture& green, const picture& blue)
{
	picture combos;

	combos.headerObject.idLength = headerObject.idLength;
	combos.headerObject.colorMapType = headerObject.colorMapType;
	combos.headerObject.dataTypeCode = headerObject.dataTypeCode;
	combos.headerObject.colorMapOrigin = headerObject.colorMapOrigin;
	combos.headerObject.colorMapLength = headerObject.colorMapLength;
	combos.headerObject.colorMapDepth = headerObject.colorMapDepth;
	combos.headerObject.xOrigin = headerObject.xOrigin;
	combos.headerObject.yOrigin = headerObject.yOrigin;
	combos.headerObject.width = headerObject.width;
	combos.headerObject.height = headerObject.height;
	combos.headerObject.bitsPerPixel = headerObject.bitsPerPixel;
	combos.headerObject.imageDescriptor = headerObject.imageDescriptor;

	for (unsigned int i = 0; i < photo.size(); i++)
	{
		//------ blue pixel ------//
		combos.pixel.blue = blue.photo[i].blue;

		//------ green pixel ------//
		combos.pixel.green = green.photo[i].green;

		//------ red pixel ------//
		combos.pixel.red = photo[i].red;


		combos.photo.push_back(combos.pixel);
	}

	return combos;
}

bool picture::testTru(const picture& other)
{
	for (unsigned int i = 0; i < photo.size(); i++)
	{
		//------ blue pixel ------//
		if (photo[i].blue != other.photo[i].blue)
		{
			return false;
		}

		//------ green pixel ------//
		if (photo[i].green != other.photo[i].green)
		{
			return false;
		}
		
		//------ red pixel ------//
		if (photo[i].red != other.photo[i].red)
		{
			return false;
		}
		
	}

	return true;
}