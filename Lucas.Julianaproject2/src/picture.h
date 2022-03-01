#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
using std::string;
using std::vector;

class picture
{
	struct Header
	{
		char idLength;
		char colorMapType;
		char dataTypeCode;
		short colorMapOrigin;
		short colorMapLength;
		char colorMapDepth;
		short xOrigin;
		short yOrigin;
		short width;
		short height;
		char bitsPerPixel;
		char imageDescriptor;
	};

	struct pixels
	{
		unsigned char blue;
		unsigned char green;
		unsigned char red;
	};

	string filepath;

	pixels pixel;
	Header headerObject;
	vector<pixels> photo;

public:

	//constructor//
	picture();

	//mutators
	void readAll(string& filePath);
	picture Multiply(picture& other);
	picture Subtract(const picture& other);
	picture Screen(const picture& other);
	picture Overlay(const picture& other);
	picture ScaleRed(float r);
	picture ScaleGreen(float g);
	picture ScaleBlue(float b);
	picture Sum(float r, float g, float b);
	void WriteRed(string& filePath);
	void WriteGreen(string& filePath);
	void WriteBlue(string& filePath);
	picture Combine(const picture& green, const picture& blue);

	//pix edits
	unsigned char PixMult(unsigned char A, unsigned char B);
	unsigned char PixScreen(unsigned char A, unsigned char B);
	unsigned char PixOverlay(unsigned char A, unsigned char B);

	//print
	void printHead();
	void writeFile(string& filePath);
	void Rotate(string& filePath);

	//test
	bool testTru(const picture& other);

};
